---
title: write cmakelist file
categories: linux
tags: linux
date: 2018-05-17
---

## 循环遍历

```python
file(GLOB_RECURSE CPP_FILES *.cpp)
foreach(f ${CPP_FILES})
    string(REGEX MATCH "examples/.*" relative_path ${f})
    string(REGEX REPLACE "examples/" "" target_name ${relative_path})
    string(REGEX REPLACE "\\.cpp" "" target_name ${target_name})
    add_executable(${target_name} ${f})
    target_link_libraries(${target_name} parse_demo)
endforeach()
```

## 条件编译

```c++
/* cpp 中的条件编译 */

//1. 通过定义了或者没有定义某个宏来开启或者关闭对应代码的编译。
#ifdefine {MACRO}或者#ifndef {MACRO}

//2. 通过某个宏的值为true(非0)或者false(0)来开启或者关闭对应代码的编译
#if {MACRO}
// 3. 逻辑组合
#if defined({MACRO1}) && defined({MACRO2}
#if defined({MACRO1}) || defined({MACRO2})

/* 预编译指令
#define            定义一个预处理宏
#undef            取消宏的定义

#if                   编译预处理中的条件命令，相当于C语法中的if语句
#ifdef              判断某个宏是否被定义，若已定义，执行随后的语句
#ifndef            与#ifdef相反，判断某个宏是否未被定义
#elif                若#if, #ifdef, #ifndef或前面的#elif条件不满足，则执行#elif之后的语句，相当于C语法中的else-if
#else              与#if, #ifdef, #ifndef对应, 若这些条件不满足，则执行#else之后的语句，相当于C语法中的else
#endif             #if, #ifdef, #ifndef这些条件命令的结束标志.
*/


/* cmake 中的条件编译 */

// 增加编译宏 需要-D， 为了与cmake自己的宏变量作为区分
ADD_DEFINITIONS(-DLOG_MACRO1 -DLOG_MACRO2)
ADD_DEFINITIONS(-DLOG_MACRO1=0 -DLOG_MACRO2=1)

// option 是cmake自己的编译参数
// 可以根据这个参数指定默认值
/*
option(DLOG "print log" ON)
option(DLOG "print log" ON)

if(DLOG)
    message("defined dlog in cmake")    
    add_definitions(-DDLOG)
else()
    message("not defined dlog in cmake")
endif()
*/
#ifdef DLOG
std::cout<<"defined DLOG"<<std::endl;
#else
std::cout<<"not defined DLOG"<<std::endl;
#endif

```

## 指定C/C++的标准

```py
# CMake的最小版本要求
cmake_minimum_required(VERSION 3.0.0)
# 项目名称以及版本号
project(demo VERSION 0.1.0)

#启动对C++14标准的支持
set(CMAKE_CXX_STANDARD 14)

# 显式要求指明支持C++标准
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 启动对C11标准的支持
# set(CMAKE_C_STANDARD 11)
# 显式要求指明支持C标准
# set(CMAKE_C_STANDARD_REQUIRED True)

# 归档静态库到指定目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
# 归档动态库到指定目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
# 归档可执行文件到指定目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

#设置可执行程序
add_executable(demo main.cpp)
```


## ros include header from another package

will include "b_include.h" file in :  

```python
catkin_package(
  CATKIN_DEPENDS
    roscpp
    ...
  DEPENDS
    EIGEN3
    ...
  INCLUDE_DIRS  #which is neede to indicate the include path
    include
)

// Install project namespaced headers
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE)
```

only one *demo.cpp* file.

```
cmake_minimum_required(VERSION 2.8) #minimum supported version
project(demo_name)  #project name
add_executable(demo_name demo.cpp)  
```

multiple source files

```
#content
./Demo2
    |
    +--- main.cpp
    |
    +--- mathFunc.cpp
add_executable(demo_name demo.cpp mathFunc.cpp)

#if you have many files
aux_source_directory(. DIR_SRCS)  #find all the source files and name them DIR_SRCS
add_executable(demo_name ${DIR_SRCS})    #add all of them 

```

include file and subdirectory

```
#content
  main.cpp
  mod1.hpp
  mod1/
    func1.cpp
    func2.cpp
  mod2.hpp
  mod2/
    func1.cpp
    func2.cpp
```
```
#CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_subdirectory(mod1) 
add_subdirectory(mod2) 
add_executable(Main main.cpp)
target_link_libraries(Main Mod1 Mod2)    #将库文件链接到指定的可执行文件

#mod1/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Mod1 STATIC
  func1.cpp
  func2.cpp
)

#mod2/CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_library(Mod2 STATIC     #生成静态库
  func1.cpp
  func2.cpp
)
```
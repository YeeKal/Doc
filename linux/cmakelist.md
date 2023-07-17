---
title: cmakelist
categories: linux
tags: linux
date: 2019-05-30
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

## 添加多个文件

```cmake
file(GLOB_RECURSE CPP_SRCS  cpp_path/*.cpp)
```

## thread

```cmake
find_package (Threads)

target_link_libraries(producer_consumer  ${CMAKE_THREAD_LIBS_INIT})
```

```py
#  生成链接库文件.o,比如类文件，可以被执行文件调用
add_library()

#  库文件链接到指定的可执行文件
target_link_libraries()

# 添加库文件搜索路径
link_directories()
```



```cmake
#设置库文件存放路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

#设置执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

#设置cmkae模块路径
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
```

target_include_directories()：指定目标包含的头文件路径, 自己所依赖的头文件放在那

target_link_libraries()：指定目标链接的库， 所依赖的库文件

target_compile_options()：指定目标的编译选项

include_directories(): 全局包含，向下传递

目标 由 add_library() 或 add_executable() 生成。

关键字说明：

1. private: 不包含链接库所依赖的模块，只能使用链接库所提供的功能
2. public: 链接库所依赖的模块都会被包含进来
3. interface: 链接库没有使用但是链接目标需要使用链接库所依赖的头文件


- [cmake 之 PUBLIC|PRIVATE|INTERFACE 关键字](https://ravenxrz.ink/archives/e40194d1.html)


## 常用包写法

## 单目录源文件

```cmake
# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project (Demo1)

# 指定生成目标
add_exectuable(main main.cpp func1.cpp)
```

若源文件很多，更省事的方法是使用 aux_source_directory命令，该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名。 
```cmake
# 语法： aux_source_directory(<dir> <variable>)

cmake_minimum_required (VERSION 2.8)
project (Demo2)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(Demo ${DIR_SRCS})
```
## 多目录

```
项目名/
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
两种写法：根目录编写单个CMakeLists.txt/每个目录分别编写
```cmake
#method 1
cmake_minimum_required(VERSION 2.8)
add_executable(Main
  main.cpp
  mod1/func1.cpp
  mod1/func2.cpp
  mod2/func1.cpp
  mod2/func2.cpp
)
```
```cmake
#method 2
#CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
add_subdirectory(mod1) 
add_subdirectory(mod2) 
add_executable(Main main.cpp)
target_link_libraries(Main Mod1 Mod2) 

#mod1/CMakeLists.txt
add_library(Mod1 STATIC  # STATIC 生成静态库
  func1.cpp
  func2.cpp
)
#aux_source_directory(. DIR_LIB_SRCS)
#add_library (Mod1 ${DIR_LIB_SRCS})

#mod2/CMakeLists.txt
add_library(Mod2 STATIC
  func1.cpp
  func2.cpp
)
#aux_source_directory(. DIR_LIB_SRCS)
#add_library (Mod2 ${DIR_LIB_SRCS})

```

## find_package

调用预定义在 CMAKE_MODULE_PATH 下的 FindNAME.cmake 模块.

也可以自己定义 FindNAME模块，将其放入工程的某个目录中，通过 SET(CMAKE_MODULE_PATH dir)设置查找路径

```cmake

```

## cmake变量

- set(VAR value): 设置变量
- \${VAR}： 引用变量，在 IF 等语句中,是直接使用变量名而不通过\${}取值
- 隐式定义变量
    - CMAKE_SOURCE_DIR | PROJECT_SOURCE_DIR | [project_name]_SOURCE_DIR: 工程顶级目录
    - CMAKE_CURRENT_SOURCE_DIR: CMakeList.txt所在当前目录
    - PROJECT_NAME: 项目名称

## building libraries
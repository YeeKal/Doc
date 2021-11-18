---
title: write cmakelist file
categories: linux
tags: linux
date: 2018-05-17
---

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
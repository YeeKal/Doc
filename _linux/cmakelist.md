---
title: cmakelist
categories: linux
tags: linux
date: 2019-05-30
---
- add_library: 生成链接库文件.o,比如类文件，可以被执行文件调用
- target_link_libraries： 库文件链接到指定的可执行文件
- link_directories: 添加库文件搜索路径

```cmake
#设置库文件存放路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

#设置执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

#设置cmkae模块路径
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
```

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
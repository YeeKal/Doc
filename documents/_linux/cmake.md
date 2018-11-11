---
title: write cmakelist file
categories: linux
tags: linux
date: 2018-05-17
---

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
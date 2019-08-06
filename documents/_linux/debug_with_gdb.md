---
title: debug with gdb
categories: linux
tags: linux
date: 2019-01-02
---
**dubug with ros**

```c++
//edit cmakelist.txt
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  -g ")
set (CMAKE_VERBOSE_MAKEFILE ON)
//catkin_make
catkin_make  -DCMAKE_BUILD_TYPE=Debug 
//launch
launch-prefix="xterm-egdb--args"
//rosrun
rosrun --prefix 'gdb -ex run --args' [package_name] [node_name] 

```

**gdb commands**

In gdb the initial character of the command has the same function as th command word.

- run: execute program
- finish: quit the program
- next/n: step over
- step: step into
- <line number>:
- break <line number>:set break point at line number
- continue: run until next breakpoint
- print:
- bt: 查看函数堆栈
- list <line number>: list source code near line number
- list func: list source code of the function
- info <>: info locals,info f
- frame i:
- up: 向上移动n层
- down: 向下移动n层
- disassemble func: 查看汇编代码
- set print object on/set print pretty on: default is off; its better to open.
- set args 10 20 30 40 50:设置参数
- gdb  *array@length:查看数组值


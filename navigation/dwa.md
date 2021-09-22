---
title: DWA算法
categories: navigation
tags: planning
date: 2021_09_22
---
## dwa

速度采样$(v,w)$ -> 根据动力学状态方程作轨迹推演 -> 轨迹评价

## base local planner

ros 中的实现

```c++
dwaComputeVelocityCommands():
    dp_->findBestPath()
        速度采样
```

##  ref

- [Difference between DWA and TEB local planners](http://files.davidqiu.com/research/tutorials/2018_rosmann_Difference%20between%20DWA%20and%20TEB%20local%20planners.pdf)
- [DWA局部路径规划算法论文阅读](https://www.cnblogs.com/dlutjwh/p/11158233.html)
- paper
    - [1997-The dynamic window approach to collision avoidance]()

---
title: st图
categories: autopilot
tags: planning
date: 2021-08-11
---

## st graph

在既有路径的情况下进行速度规划，即确定当前的（路经点上的）最优速度。

以时间t为横轴， 路径长度为纵轴。图中的点表示在t时刻路径s的位置会与障碍物发生碰撞，因此可以根据该图进行最优速度的优化.

![st_apollo.jpg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/st_apollo.jpg)

ref: Apollo代码中的ST Graph在modules/planning/lattice/behavior/path_time_graph.h文件

原文網址：https://kknews.cc/car/ryr2x5n.html

```py
静态障碍物：
    1. 根据路径序列计算碰撞的上下界
    2. 在上下界加入时间上下界（时间起点和终点）形成四个点
    3. 在st中的表现应该是横穿的矩形
动态障碍物:
    1. 动态障碍物以离散轨迹点表示
    2. 遍历轨迹点，对每个点在s路径序列上计算上下界，并加上当前时间
    3. 把轨迹点的上界连起来，下界连接来，则在图中形成一个上下的包围体
```
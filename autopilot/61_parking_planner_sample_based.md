---
title: sample based parking planner
categories: 
tags: 
date: 2023-12-28
---

## RRT path planner for automated parking

- [2017 A two-stage RRT path planner for automated parking](https://www.merl.com/publications/docs/TR2017-121.pdf)

**<font color='Tomato'>Improving RRT</font>**

- [Improving RRT for Automated Parking in Real-world Scenarios](https://arxiv.org/pdf/2310.20518.pdf)
- [source code](https://rtime.ciirc.cvut.cz/gitweb/hubacji1/iamcar2.git)

![Improving RRT](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/12/20231228104017.png)

method:

- in slot gcp planner
- out-slot rrt pplanner

## 2022 Continuous-Curvature Target Tree Algorithm for Path Planning in Complex Parking Environments

1. 根据直线长度,采样多条出库路径,然后计算cost最小的出库长度以及target-tree
2. 采用rrt* 进行连接(?怎么连接的)

泊车路径
rrt*

连续曲率轨迹 


## 2017 TTS-RTR

<font color='Tomato'>Ref</font>

- [2017 Autonomous Path Planning for Road Vehicles in Narrow Environments: An Efficient Continuous Curvature Approach]()


基于运动学的采样方法
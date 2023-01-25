---
title: 自动泊车规划器
categories: autopilot
tags: autopilot
date: 2023-01-12
---

## methods

- 分形搜索 Fractal Search
- NMPC 碰撞检测
- CBF: Control Barrier Functions

- within-STC constraints
- [Collision Detection Accelerated:An Optimization Perspective](https://arxiv.org/pdf/2205.09663.pdf)

## practice

- [courses/ko/parking](https://cw.fel.cvut.cz/b202/_media/courses/ko/parking.pdf)

## geometry path pattern
A new geometry-based secondary path planning for automatic parking

## minkowski sum
碰撞检测
GJK，全称Gilbert–Johnson–Keerthi distance algorithm  

- [box2d: b2_distance.h](https://github.com/erincatto/Box2D)
- [Separating Axis Theorem](http://www.metanetsoftware.com/technique/tutorialA.html)

## An Optimization-Based Motion Planner for Car-like Logistics Robots on Narrow Roads

结合TED进行窄通道的freespace规划

Narrow-Roads-Timed-Elastic-Band

## 2021_Autonomous_Parking_Trajectory_Planning_With_Tiny_Passages_A_Combination_of_Multistage_Hybrid_A-Star_Algorithm_and_Numerical_Optimal_Control

freespace规划

1. A* 发现窄通道
2. 混合A* 连接窄通道
3. 基于优化方案进行后处理

后处理的碰撞检测使用within-STC constraints

## 2022 Continuous-Curvature Target Tree Algorithm for Path Planning in Complex Parking Environments
泊车路径
rrt*

连续曲率轨迹 

## ref

- paper
    - [Optimisation based path planning for car parking in narrow environments]()
    - [A fast motion planning algorithm for car parking based on static optimization]()
    - [Practical motion planning for car-parking control in narrow environment]()
    - [A new geometry-based secondary path planning for automatic parking](https://journals.sagepub.com/doi/full/10.1177/1729881420930575)
    - [Continuous-Curvature Target Tree Algorithm for Path Planning in Complex Parking Environments](https://arxiv.org/pdf/2201.03163.pdf)
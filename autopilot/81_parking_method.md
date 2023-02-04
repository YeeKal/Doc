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

1. 根据直线长度,采样多条出库路径,然后计算cost最小的出库长度以及target-tree
2. 采用rrt* 进行连接(?怎么连接的)

泊车路径
rrt*

连续曲率轨迹 

## 2016 Optimisation based path planning for car parking in narrow environments

1. phase A and phase B 的规划
2. 对于狭窄空间,guide-tree 进行换挡采样

- [courses/ko/parking:对以上算法的实践](https://cw.fel.cvut.cz/b202/_media/courses/ko/parking.pdf)


## 2017 Autonomous Path Planning for Road Vehicles in Narrow Environments: An Efficient Continuous Curvature Approach

TTS-RTR planner : 基于运动学的采样方法


## 0130

- [2016 Spatio-temporal decomposition: a knowledge-based initialization strategy for parallel parking motion optimization]()
- [2017 Hybrid curvature steer: A novel extend function for sampling-based nonholonomic motion planning in tight environments]()
- [2022 Parallel Parking: Optimal Entry and Minimum Slot Dimensions](https://arxiv.org/abs/2205.02523)
- [2016 Time-Optimal Maneuver Planning in Automatic Parallel Parking Using a Simultaneous Dynamic Optimization Approach]()

## 0203

- [Trajectory optimization for Car-Like Vehicles in Structured and Semi-Structured Environments](https://ieeexplore.ieee.org/document/8500373)
- [Efficient_Collision_Detection_between_2D_Polygons](https://www.researchgate.net/publication/221546279_Efficient_Collision_Detection_between_2D_Polygons)

## ref

- paper
    - [2016 Optimisation based path planning for car parking in narrow environments]()
    - [2013 A fast motion planning algorithm for car parking based on static optimization]()
    - [Practical motion planning for car-parking control in narrow environment]()
    - [A new geometry-based secondary path planning for automatic parking](https://journals.sagepub.com/doi/full/10.1177/1729881420930575)
    - [2022 Continuous-Curvature Target Tree Algorithm for Path Planning in Complex Parking Environments](https://arxiv.org/pdf/2201.03163.pdf)
    - [ALTRO: A Fast Solver for Constrained Trajectory Optimization](https://www.ri.cmu.edu/publications/altro-a-fast-solver-for-constrained-trajectory-optimization/)
    - [Solving Constrained Trajectory Planning Problems Using Biased Particle Swarm Optimization](https://dspace.lib.cranfield.ac.uk/bitstream/handle/1826/16453/Solving_Constrained_Trajectory_Planning_problems-2021.pdf?sequence=4)
    - [2020-An Optimization-Based Receding Horizon Trajectory Planning Algorithm](https://www.sciencedirect.com/science/article/pii/S2405896320330810)
- paper(NN)
    - [Time-Optimized Online Planning For Parallel Parking With Nonlinear Optimization and Improved Monte Carlo Tree Search](https://www.semanticscholar.org/paper/Time-Optimized-Online-Planning-For-Parallel-Parking-Song-Chen/9ace2c192aea884f16ceac206ec278007139651d)
- course
    - [EECS C106B](https://pages.github.berkeley.edu/EECS-106/sp22-site/resources/)
    - [Path-Planning-for-a-Simple-Car](https://jckantor.github.io/CBE30338/07.06-Path-Planning-for-a-Simple-Car.html)
- tool / library
    - [2017_PYROBOCOP: Python-based Robotic Control & Optimization Package for Manipulation and Collision Avoidance]()
    - [nmpc by casadi](https://github.com/devsonni/MPC-Implementation/tree/main/Python%20Implementation)
---
title: optimal motion planning
categories: motion planning
tags: optimal control 
date: 2021-10-29
---

## 2018 - Optimization-Based Collision Avoidance

#### introduction

提出轨迹优化中的难点：障碍物碰撞的表达。当前存在的方法不足：

- 降级为线性约束： [2014 - Motion planning with sequential convex optimization and convex collision checking]()
- 质点模型不切合实际
- 多面体(polyhedral)通常使用整数变量进行表达： [2002 - Review of Nonlinear Mixed-Integer and Disjunctive Programming Techniques]()。`Mixed-integer convex optimization`在非线性实时控制器上并不是一个可接受的选择

本文方法特点：

1. 构建凸集（polytope, ellipsoids and so on）
2. 对`signed distance`重新整理， 使得`least-intrusive trajectorie`成为可能
3. 整合了动力学，轨迹可直接在控制器上执行， kinodynamically feasible

相关进展(针对基于优化的避障方法)

- potential field
- point-mass models
    - polyhedral obstacles： disjunctive programming， mixed-integer optimization problem
    - ellipsoidal obstacles： smooth non-convex constraint
- full-dimensional controlled objects
    - keeping all vertices of the controlled object outside the obstacle: [2015-A unified motion planning method for parking an autonomous vehicle in the presence of irregularly placed obstacles]()
    - signed distance: [2014 - Motion planning with sequential convex optimization and convex collision checking]()
    - a smooth reformulation of the collision avoidance constraint for point-mass controlled objects and polyhedral obstacles: [2011 Trajectory generation for aircraft avoidance maneuvers using online optimization]()


## Simultaneous path planning and trajectory optimization for robotic manipulators using discrete
mechanics and optimal control

- three stage
    - path planning
    - trajectory planning: velocity, smooth
    - control: torque
- swarm-intelligence based algorithm:
    - PSO(Particle Swarm Optimization)
    - ACO(Ant Colony OPtimization)
    - ABC(Artificial Bee Colony Optimization)
    - FA(Firefly Algorithms)
    - BA(Bat Algorithm) 
- dp



- trajectory planning
- trajectory optimization
- optimal trajectory planning


Time-optimal Control of Manipulators: 李群上机械臂的最有控制，路径规划和轨迹优化同时进行


## ref

- paper
    - [2006 - Optimal manipulator path planning with obstacles using disjunctive programming]()
    - [2016 - Mixed-Integer Quadratic Program - Optimal Trajectory Planning for Autonomous Driving Integrating Logical Constraints: An MIQP Perspective]()

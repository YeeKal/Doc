---
title: CFS 凸可行集算法
categories: autopilot
tags: autopilot
date: 2023-02-03
---

## CFS: Convex Feasible Set

根据优化问题的结构在当前迭代点上构造凸可行域. 与convex corridor的区别: convex corridor根据障碍物的特点构造实际空间上可行域, 而Convex Feasible Set是根据优化问题的结构通过解析式构造优化变量空间上的可行域.

## SCCFS: Soft Constrained Convex Feasible Set

带约束版本的CFS

## FOAD：Fast Optimization Based Autonomous Driving Motion Planner

cfs 在自动驾驶领域的应用

## ref

- project
    - [Convex Feasible Set python code](https://github.com/valkyrjaL/Convex_Feasible_Set)
    - [CFS on arm with matlab](https://github.com/changliuliu/CFS)
- blog
    - [论文阅读：Convex Feasible Set Algorithm 01](https://zhuanlan.zhihu.com/p/553262342)
    - [FOAD基于数值优化的自动驾驶实时运动规划](https://www.jiqizhixin.com/articles/2018-10-31-7)
    - [论文阅读：Convex Feasible Set Algorithm 02](https://zhuanlan.zhihu.com/p/561101217)
- paper
    - [2016 The convex feasible set algorithm for real time optimization in motion planning](https://arxiv.org/abs/1709.00627)
    - [2017 Convex feasible set algorithm for constrained trajectory smoothing](https://www.cs.cmu.edu/~cliu6/files/acc17.pdf)
    - [FOAD: Fast optimization-based autonomous driving motion planner]() 
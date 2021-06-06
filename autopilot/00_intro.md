---
title: 自动驾驶决策规划
categories: autopilot
tags: autopilot
date: 2021-04-27
---
## requirement

- 熟悉路径规划相关算法(A*,RRT,Lattice planner等),了解机器人决策系统,如决策状态机、决策树、专家系统,强化学习,POMDP
- 深度学习,强化学习,数值优化,模型预测控制,车辆动力学模型
- 运动规划和控制（包括但不限于图搜索、轨迹规划/优化、不确定性下的规划、最优控制/MPC/LQR）、自动规划（PDDL/POMDP）、强化学习
- 自动驾驶决策控制与运动规划 Decision Making And Motion Planning, DMAP
- 模型预测控制: model predictive control
- POMDP: Partially Observable Markov Decision Processes

## 路径规划

- 基于搜索： a-star/dijkstra
- 基于采样: rrt/rrt*
- 动力学约束下的运动学规划(kinodynamic path planning)
    - 两点边界值最优控制问题State-state Boundary Value Optimal Control Problem
    - 状态栅格搜索算法 State Lattice Search
    - 动力学约束RRT*算法 Kinodynamic RRT*
    - 混合A*算法 Hybrid A*

## 轨迹规划

- 多项式插值
- Dubins曲线[33]和Reeds and Sheep

## 最优控制

- mpc: model predictive control

## 自动规划/端到端

- PDDL/POMDP

## ref

- 招聘
    - [阿里巴巴打磨元](https://cn.indeed.com/viewjob?jk=2c5947f7b0b845af&tk=1f44mj6bapqcu801&from=serp&vjs=3)
- 知识点参考
    - [移动机器人运动规划课程](https://zhuanlan.zhihu.com/p/82784940)
- blog
    - [自动驾驶汽车：综述（七）---决策系统之运动规划Motion Plan](https://zhuanlan.zhihu.com/p/59794261)
    - [一起自学吧](https://www.17zixueba.com/thread-9088-1-1.html)
    - [无人驾驶SOTA代码](https://zhuanlan.zhihu.com/p/59769293)
    - [mit 无人驾驶](https://deeplearning.mit.edu/)
    - [自动驾驶决策控制及运动规划史上最详细最接地气总览现状](https://zhuanlan.zhihu.com/p/260707853)
- paper
    - [2019-self driving cars a survey](https://arxiv.org/abs/1901.04407)
---
title: 自动驾驶决策规划
categories: autopilot
tags: autopilot
date: 2021-04-27
---

## 车体

- 传感器
    - 相机
    - 激光雷达
    - 毫米波雷达
    - 超声波雷达

## 感知

- 传感器融合
    - 雷达感知
    - 视觉感知
    - 激光雷达感知

- 地图
- 定位

- 决策
- 规划
- 控制


- [工程实践中，目标检测为何要加目标追踪？](https://zhuanlan.zhihu.com/p/70268783)

## 视觉感知

- 视觉：
    - 传统视觉：特征，统计
    - 深度学习：
- 视觉感知：
    - 传统视觉：车道线B-Spline拟合/DPM物体检测
    - 深度学习：yolo/ssd/xpilot



SFM:

dtam: 从时序图估计出深度
MVDepthNet:单目深度估计
atlas: [atlas](https://github.com/magicleap/Atlas)



## requirement

- 熟悉路径规划相关算法(A*,RRT,Lattice planner等),了解机器人决策系统,如决策状态机、决策树、专家系统,强化学习,POMDP
- 深度学习,强化学习,数值优化,模型预测控制,车辆动力学模型
- 运动规划和控制（包括但不限于图搜索、轨迹规划/优化、不确定性下的规划、最优控制/MPC/LQR）、自动规划（PDDL/POMDP）、强化学习
- 自动驾驶决策控制与运动规划 Decision Making And Motion Planning, DMAP
- 模型预测控制: model predictive control
- POMDP: Partially Observable Markov Decision Processes

## 规控

- 全局规划
- 决策：换道/超车/减速
- 运动规划
- 控制：根据当前状态跟踪轨迹

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
- project
    - [Steering Functions for Car-Like Robots](https://github.com/hbanzhaf/steering_functions)
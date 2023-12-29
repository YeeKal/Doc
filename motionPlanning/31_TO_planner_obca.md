---
title: obca
categories: 
tags: 
date: 2023-02-02
---

## Collision Avoidance for Point-Mass Models

<font color='Tomato'>Collision-Free Trajectory Generation</font>

$$\begin{aligned}
\operatorname{dist}(\mathbb{E}(x), \mathbb{O}) & >\mathrm{d}_{\min } \\
& \Longleftrightarrow \exists \lambda \succeq_{\mathcal{K}^*} 0:(A p-b)^{\top} \lambda>\mathrm{d}_{\min },\left\|A^{\top} \lambda\right\|_* \leq 1
\end{aligned}$$

1. K either the standard cone or the second-order cone, which allows us to model polyhedral and ellipsoidal obstacles. 
2. not able to distinguish between "severe" and "less severe" colliding trajectories

<font color='Tomato'>Minimum-Penetration Trajectory Generation</font>

$$\begin{aligned}
\operatorname{pen}(\mathbb{E}(x), \mathbb{O}) & <\mathrm{p}_{\max } \\
& \Longleftrightarrow \exists \lambda \succeq_{\mathcal{K}^*} 0:(b-A p)^{\top} \lambda<\mathrm{p}_{\max },\left\|A^{\top} \lambda\right\|_*=1 .
\end{aligned}     $$

<font color='Tomato'>combine:</font>

$$\begin{aligned}
& \operatorname{sd}(\mathbb{E}(x), \mathbb{O})>\mathrm{d} \\
& \Longleftrightarrow \exists \lambda \succeq \mathcal{K}^* 0:(A p-b)^{\top} \lambda>\mathrm{d},\left\|A^{\top} \lambda\right\|_*=1 . \\
&
\end{aligned}$$

## ref

- blog
    - [matlab 开放空间下（OPEN SAPCE）基于OBCA(distance approach)的泊车轨迹优化-代码实现](https://zhuanlan.zhihu.com/p/599002491)
    - [ DualVariableWarmStartOSQPInterface障碍物防撞数](https://zhuanlan.zhihu.com/p/157743632)
- projects
    - [OBCA: Optimization-Based Collision Avoidance](https://github.com/XiaojingGeorgeZhang/OBCA)
    - [TDR-OBCA: A Reliable Planner for Autonomous Driving in Free-Space Environment](https://arxiv.org/pdf/2009.11345.pdf)
    - [2018_zhang_Autonomous Parking using Optimization-Based Collision Avoidance [Optimization][Obstacles]](http://files.davidqiu.com/research/papers/2018_zhang_Autonomous%20Parking%20using%20Optimization-Based%20Collision%20Avoidance%20[Optimization][Obstacles].pdf)
    
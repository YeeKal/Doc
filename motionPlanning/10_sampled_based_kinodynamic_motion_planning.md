---
title: sampled_based_kinodynamic_motion_planning
categories: motion planning
tags: kinodynamic
date: 2019_06_17
---

- 固定线型
    - RS
    - spiral
- OBVP
- 采样控制量  discretized double integrator dynamics 

## RRT based

- [2010 Optimal Kinodynamic Motion Planning using Incremental Sampling-based Methods](https://dspace.mit.edu/bitstream/handle/1721.1/65847/Frazzoli-2010-Optimal%20kinodynamic%20motion%20planning.pdf?sequence=1&isAllowed=y)

RRT* + differential constraints(local steering method)


- [Asymptotically Optimal Sampling-based Kinodynamic Planning](https://arxiv.org/pdf/1407.2896.pdf)
- [Robot Motion Planning Algorithms](https://github.com/iamprem/rmp)

## kinodynamic motion planning

- kinodynamic solution: mapping from time to generalized forces or accelerations
- time optimal kinodynamic solution: require minimal time
- NP-hard  寻找近似解
- 质点在2D/3D情景下的近似解

kinematic constraints: joint limits, obstacle avoidance

dynamic constraints: time-derivatives of configuration, which include dynamics laws and bounds on velocity, acceleration, and applied force

BVP: boundary value problem

规划位置的同时还要规划速度

- Generalized waiter-motion with no-sliding constraints/generalized waiter-motion problem

- time-optimal motion planning/jerky motion

- differential constraints, dynamic constraints

- differential models: $\dot{x}=f(x,u)$
- discrete-time approximation:$x_{k+1}=f(x_k,u_k)$

## numerical integration process:
- Euler method: $x(\Delta t)\approx x(0)+\Delta tf(x(0),u(0))$
- Runge-Kutta method: refer to numerical method notes
    - the fourth-order Runge-Kutta integration method:

$$x(\Delta t)\approx x(o)+\frac{\Delta t}{6}(w_1,w_2,w_3,w_4)   \\
\begin{align}\text{in which: } w_1&=f(x{0},u(0)) \\
               w_2&=f(x{0}+\frac{1}{2}\Delta t w_1,u(\frac{1}{2}\Delta t))  \\
               w_3&=f(x{0}+\frac{1}{2}\Delta t w_2,u(\frac{1}{2}\Delta t))  \\
               w_2&=f(x{0}+\Delta t w_3,u(\Delta t))
\end{align}$$

- Multistep methods 
- Black-box simulators
- Reverse-time system simulation

## OBVP

- BVP: boundary value problem
- OBVP: optimal boundary value problem

解法： 

- Hamilton-Jacobi-Bellman方程或Pontryagin's Minimum Principle
- fixed-final-state-free-final-time controller
- double integrator

## OBVP

Pontryagin's Minimum Principle (PMP) 是一种解决最优控制问题的方法，它依赖于变分法和哈密顿系统。这个原理提供了必要条件来确定一个过程是否为最优。对于一个具有标准形式的最优控制问题：

$$\min_u \int_{t_0}^{t_f} L(x(t), u(t), t) , dt$$


受到动力学约束：

$$\frac{dx}{dt} = f(x(t), u(t), t)$$

以及初始条件 ( x(t_0) = x_0 ) 和终止条件 ( x(t_f) = x_f )。

PMP 引入了协态 ( \lambda(t) )，并定义哈密顿函数 ( H )：

$$H(x, \lambda, u, t) = L(x, u, t) + \lambda^T f(x, u, t)$$

根据 PMP，最优控制 ( u^*(t) ) 必须最小化哈密顿量对每一个 ( t )，同时需要满足动力学方程和以下的协态方程：

$$\frac{d\lambda}{dt} = -\frac{\partial H}{\partial x}$$


## Randomized Kinodynamic Planning

- [paper](https://skat.ihmc.us/rid=1K7WQT337-XQJP8C-1YHM/Randomized%20Kinodynamic%20Planning.pdf)

**distance metric**



## Kinodynamic RRT*

- paper: Kinodynamic RRT*: Optimal Motion Planning for Systems with Linear Differential Constraints

- fixed-final-state-free-final-time controller
that exactly and optimally connects any pair of states
- applied to linear Differential Constraints, applied to non-linear dynamics as well by using their first-order Taylor approximations


## temp

- steering method
- driftless, 无向的

## steering method

- [toppra](https://notebook.community/hungpham2511/toppra/docs/source/tutorials/tut3_non_zero_velocities)

Non-zero starting and ending velocities

## Asymptotically Optimal Planning by Feasible Kinodynamic Planning in State-Cost Space

- [paper](https://arxiv.org/pdf/1505.04098)

code:

    - [kinodynamic_frontend](https://github.com/ZamesNg/kinodynamic_frontend/tree/master)


## ref

- blog
- code
- project
    - [avp-rrt](https://github.com/stephane-caron/avp-rrt)
    - [lqrrt](https://github.com/jnez71/lqRRT)
    - [Kinodynamic Planning](https://github.com/palliprasanth/Kinodynamic-Planning)
- paper
    - [1993 - Kinodynamic Motion Planning](http://www.cs.duke.edu/~reif/paper/canny/kinodynamic.pdf)
    - [2012-Kinodynamic RRT*: Optimal Motion Planning for Systems with Linear Differential Constraints](https://arxiv.org/abs/1205.5088)
    - [A New Approach to Time-Optimal Path Parameterization Based on Reachability Analysis](https://arxiv.org/abs/1707.07239)
    - [2013-rss-Kinodynamic Planning in the Configuration Space via Admissible Velocity Propagation](http://www.roboticsproceedings.org/rss09/p52.html)
        - [suplementary materials](http://www.programmingvision.com/rosendiankovthesis.pdf)
        - [source code: avp-rrt](https://github.com/stephane-caron/avp-rrt)
    - [2014-sst-Asymptotically Optimal Sampling-based Kinodynamic Planning](https://arxiv.org/abs/1407.2896)
    - [2018-Sampling-based optimal kinodynamic planning with motion primitives](https://arxiv.org/abs/1809.02399)
    - [Asymptotically Optimal Planning by Feasible Kinodynamic Planning in State-Cost Space](https://arxiv.org/abs/1505.04098)
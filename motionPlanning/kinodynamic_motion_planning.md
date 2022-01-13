---
title: kinodynamic_motion_planning
categories: motion planning
tags: kinodynamic
date: 2019_06_17
---



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

## temp

- steering method
- driftless, 无向的

## steering method

- [toppra](https://toppra.readthedocs.io/en/latest/tutorials/tut3_non_zero_velocities.html)

Non-zero starting and ending velocities

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
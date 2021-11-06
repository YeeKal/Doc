---
title: 基于最优化的轨迹规划/运动规划 
categories: motion planning
tags: planning
date: 2021-10-21
---

PDE: 偏微分方程(Partial Differential Equation)

最优控制的方法在轨迹优化中主要使用直接法中的配点法。配点法中由于积分和为分的处理又会有梯形积分，simpson等各种积分法的区别。从广义上讲，伪谱法也属于配点法，与上述积分类似，也是通过吧为分和积分通过另一种方式离散化，转化为更容易构造优化方程的形式。

最优控制 VS 轨迹优化：

最优控制 VS 非线性优化

- collocation methods
- pseudo

- scaling


## optimal control based planning

$$\begin{aligned}
u^*(t):&=arg\min_{u(.)}\int^{t_f}_{t_0}C(x(t), u(t))dt  \\
s.t.\quad x(t_0)&=x_0   \\
\dot{x}(t) &=f(x(t), u(t))   \quad \forall t  \quad \text{(states function)} \\
x(t) &\in \mathcal{X}_{feas},  \quad \forall t \quad \text{(collision-free)} \\
u(t) &\in \mathcal{U}_{feas},  \quad \forall t \quad \text{(control-limits)} 
\end{aligned}$$

- In the view of control: generate feasible control inputs under dynamics constraints

- In the view of planning: generate dynamically-feasible waypoints (which will be tracked with appropriate control methods)

#### methods

- explicit methods: convex problem,  LQR
- numerical methods: shooting, collocation
    - convex
        - software: CVX, OSQP
        - internal: Gurobi, Sedumi, Mosek
    - non-convex
        - interior point: IPOPT, SNOPT
        - active  set methods: SAS


lqr, mpc

## challenge

在考虑动力学的情况下会遇到的挑战：

1. obstacle avoidance: 不可导，非凸。
2. hybrid mode switch (contact force)
3. energy efficiency and smoothness(min jerk, snap)

#### obstacle avoidance

simple geometric constraints: e.g. $(x-x_{obs})^2+(y-y_{obs})^2\geq r^2$. such constraints are general non-convex.

to make it convex:

- mixed-integer formulation

```
8Richards and How, “Aircraft trajectory planning with collision avoidance using mixed integer linear programming”.
9Deits and Tedrake, “Footstep planning on uneven terrain with mixed-integer convex optimization”.
10Deits and Tedrake, “Efficient mixed-integer planning for UAVs in cluttered environments”.
```

- dual variables

```
1Zhang, Liniger, and Borrelli, “Optimization-based collision avoidance
github: https://github.com/XiaojingGeorgeZhang/OBCA
```

- chomp/stomp/ Sequential Convex Optimization

```
2Schulman et al., “Motion planning with sequential convex optimization and convex collision checking”
```

## contact force

Optimization through contact(contact invariant optimization): contact force is zero or distance between contact points should be zero.

application case: manipulation with finger contact, legged robotics

```
lab: https://homes.cs.washington.edu/~todorov/projects.html
github: https://github.com/robbierolin/Contact-Invariant-Optimization-Project
Contact-Invariant Optimization for Hand Manipulation: https://homes.cs.washington.edu/~zoran/MordatchSCA12.pdf
Discovery of Complex Behaviors through Contact-Invariant Optimization
```




## ref

- lab
    - [Momvement Control Laboratory](https://homes.cs.washington.edu/~todorov/index.php?video=TassaICRA14&paper=Tassa,%20ICRA%202014)

- blog
    - [References on Optimal Control, Reinforcement Learning and Motion Planning](https://github.com/eleurent/phd-bibliography)

- course
    - [Robotic Systems](https://motion.cs.illinois.edu/RoboticSystems/)
    - [Model Predictive Control](http://cse.lab.imtlucca.it/~bemporad/mpc_course.html)
    - [cs 285 RL](http://rail.eecs.berkeley.edu/deeprlcourse-fa19/)
    - [UofT Robotics Institute](https://www.cs.toronto.edu/~florian/)
    - [Autonomous Systems, Control and Optimization (ASCO) Lab](https://asco.lcsr.jhu.edu/courses/)
    - [Numerical Optimal Control](https://www.syscop.de/teaching/ss2020/numerical-optimal-control-online)
    - [Optimal Control for Robotics - Spring 2018](https://github.com/MatthewPeterKelly/ME149_Spring2018)
- projects
    
    - [Optimal Control Framework - python](https://github.com/jhu-asco/optimal_control_framework)
    - [Geometric Control Optimization and Planning Library](https://github.com/jhu-asco/gcop)
    - [optimTraj - matlab](https://github.com/MatthewPeterKelly/OptimTraj)
    - [OBCA: Optimization-Based Collision Avoidance](https://github.com/XiaojingGeorgeZhang/OBCA)
    - [ALTRO: TrajectoryOptimizatio](https://github.com/RoboticExplorationLab/TrajectoryOptimization.jl)
    - [Pontryagin-Differentiable-Programming](https://github.com/wanxinjin/Pontryagin-Differentiable-Programming)
- paper
    - [Obstacle avoidance using optimal control theory](https://www.semanticscholar.org/paper/Obstacle-avoidance-using-optimal-control-theory-Hagenaars/7fc04bb7953ad69efdfe00721f589dce60e69f5f)
    - [On Motion Planning Using Numerical Optimal Control](http://liu.diva-portal.org/smash/get/diva2:1318297/FULLTEXT01.pdf)
    - [Synthesis and Stabilization of Complex Behaviors through Online Trajectory Optimization](https://homes.cs.washington.edu/~todorov/papers/TassaIROS12.pdf)
    - [2010- Practical Methods for Optimal Control and Estimation Using Nonlinear Programming]()
    - [1998- A Survey of Numerical Methods for Trajectory Optimization]()
    - [2009 - A survey of numerical methods for optimal control]()
    - [ALTRO: A Fast Solver for Constrained Trajectory Optimization](https://roboticexplorationlab.org/papers/altro-iros.pdf)
    - [2021-Creating Better Collision-Free Trajectory for Robot Motion Planning by Linearly Constrained Quadratic Programming](https://www.frontiersin.org/articles/10.3389/fnbot.2021.724116/full)
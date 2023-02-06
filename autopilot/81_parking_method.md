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

实质则是构型空间？如何转化为优化问题

- [2020-Closed-Form Minkowski Sum Approximations for Efficient Optimization-Based Collision Avoidance](https://arxiv.org/abs/2203.15977)
- [2015-Efficient Configuration Space Construction and Optimization for Motion Planning](https://cdr.lib.unc.edu/downloads/6682xd766)
- [A Simple Method for Computing Minkowski Sum Boundary in 3D Using Collision Detection](https://cs.gmu.edu/~jmlien/lib/exe/fetch.php?media=lien_wafr08.pdf)
- [Exact and Efficient Construction of Planar Minkowski Sums using the Convolution Method](http://www.cs.jhu.edu/~misha/Spring20/Wein06.pdf)
- [2019 Efficient Exact Collision Detection between Ellipsoids and Superquadrics via Closed-form Minkowski Sums]()
- [Real-time Reciprocal Collision Avoidance with Elliptical Agents]()
- [2011 Fast and robust 2D Minkowski sum using reduced convolution](http://masc.cs.gmu.edu/wiki/uploads/ReducedConvolution/iros11-mksum2d.pdf)
- [Polygonal Minkowski Sums via Convolution:Theory and Practice]()

Reciprocal Velocity Obstacles (RVO)

- [Optimal Reciprocal Collision Avoidance](https://gamma.cs.unc.edu/ORCA/)
- projects
    - [RVO2 Library: Reciprocal Collision Avoidance for Real-Time Multi-Agent Simulation](https://gamma.cs.unc.edu/RVO2/)

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

#### abstract

-  a static optimization problem is formated while considering
    1. distance to obstacles
    2. longer driving distances
- in narrow scenarios, a tree-based guidance for the local planner is introduced

#### 1. introduction

- build roadmap
- rrt with kinematic constraints, Integrating the differential equations of the robot for a specified distance 
    1. randomised inputs[^1]
    2. inputs based on the analytic solution[^2]
- geometry
    - Dubins
    - Reeds and Shepp
    - β-spline [14, 15], Bezi´er [16] or polynomial [17] curves.
- hybrid a-star
- non-holonomic characteristics
    - small-time-controllable
    - chained-form systemand sinusoidal inputs
    - Dubins curves
    - clothoid curves
- optimal control problem

以上方法可能对某些场景或者单一泊车场景有效果，但是对于更加泛化和多元化的，以及狭窄空间下的停车场景也许无法计算出有效轨迹。因此本文提出了一种基于优化方法的泊车规划器，能够以较低的计算代价实现狭窄场景下的实时规划。

#### 2. problem statement
本文首先讨论了普通场景下的三种车位的规划方法，即

- parallel slot: 水平车位， 侧方位停车
- garage slot： 垂直车位，倒车入库
- angle slot：斜列车位

后面又更深入扩展了规划器再狭窄场景下和比较杂乱的停车场(parking deck)下的规划方法

![parking_opti_slot](imgs/parking_opti_slot.png)

根据自行车模型，把状态量对时间求导，可列出小车的动力学方程：

$$\left\{\begin{align}
 \dot{x} &=v\cdot cos(\theta)  \\
 \dot{y} &=v\cdot sin(\theta)  \\
 \dot{\theta} &=\frac{v \cdot tan(\phi)}{L}  \\
 \dot{v} &= a \\
 \dot{\phi} &= \zeta\
\end{align}\right.$$

而在本文中，只考虑轨迹，不考虑时间上的速度和加速度。把状态量对时间求导改为对轨迹长度求导。

对于任一变量 a:
$$\frac{da}{ds} = \frac{da}{dt} \frac{dt}{ds} = \frac{1}{v}\frac{da}{dt}$$

则状态方程转化为：

$$\left\{ \begin{align}
 \dot{x} &= cos(\theta)  \\
 \dot{y} &=sin(\theta)  \\
 \dot{\theta} &=\frac{tan(\phi)}{L} 
\end{align}
\right.$$

其中注意到$\frac{tan(\phi)}{L}$实际就是由于方向盘转弯而导致的曲率,对于自行车模型.曲率和方向盘转角是一一对应的,因此运动学模型也可以写为:

$$\left\{\begin{align}
 \dot{x} &= cos(\theta)  \\
 \dot{y} &=sin(\theta)  \\
 \dot{\theta} &=u_l
\end{align}\right.$$

这样就得到文中的方程式：

$$\mathbf{q}^{\prime}=\left(\begin{array}{c}
x^{\prime} \\
y^{\prime} \\
\theta^{\prime}
\end{array}\right)=\left(\begin{array}{c}
D \cos (\theta) \\
D \sin (\theta) \\
D u_l
\end{array}\right)=\mathbf{f}_s\left(\mathbf{q}, u_l, D\right)$$

其中$D\in\{-1, 1\}$指示车行驶的方向，1代表向前，-1代表向后。

#### 3. Path Planning for Car Parking

对于上述非线性方程，根据路径s进行二阶离散。注意这里步长$\eta_i\in[\eta_{min}, \eta_{max}]$也是一个变量。得到如下表达式：

$$\begin{aligned}
\mathbf{q}_{i+1} & =\left(\begin{array}{l}
x_{i+1} \\
y_{i+1} \\
\theta_{i+1}
\end{array}\right)=\left(\begin{array}{c}
x_i+D \eta_i \cos \left(\theta_i+D \frac{\eta_i u_{l_i}}{2}\right) \\
y_i+D \eta_i \sin \left(\theta_i+D \frac{\eta_i u_{l_i}}{2}\right) \\
\theta_i+D \eta_i u_{l_i}
\end{array}\right) \\
& =\mathbf{f}\left(\mathbf{q}_i, \mathbf{u}_i, D\right) .
\end{aligned}$$

上式中，$D$作为指示方向的变量可以忽略。除去状态变量$[x, y, \theta]$之外，还有两个变量，即$u=[u_l, \eta]$, 表示方向盘转角(实际为曲率)和步长，作为优化变量。

文中的优化问题**并不是一次优化完整条轨迹，而是每次走一步，循环迭代直到判断需要换挡的位置**。该优化问题定义为：

$$
\begin{array}{ll}
\min _{\mathbf{u}_i} & l_{O_i}\left(\mathbf{q}_{i+1}\right) \\
\text { s.t. } & \mathbf{q}_{i+1}=\mathbf{f}\left(\mathbf{q}_i, \mathbf{u}_i, D\right) \\
& \mathbf{h}_P\left(\mathbf{q}_{i+1}\right) \leq \mathbf{0} \\
& \mathbf{u}_{\min } \leq \mathbf{u}_i \leq \mathbf{u}_{\max },
\end{array}
$$

其中损失函数：
$$\begin{aligned}
l_{O_i}\left(\mathbf{q}_{i+1}\right)&=r_\theta e_{\theta_{i+1}}^2+\mathbf{e}_{P_{i+1}}^{\mathrm{T}} \mathbf{R e}_{P_{i+1}}+r_u \Delta u_i^2  \\
e_{p_i}&=[x_i-x_E, y_i-y_E]^T  &\text{目标点的位置偏差} \\
e_{\theta_i}&=\theta_i-\theta_O & \text{预定义目标的航向偏差} \\
\Delta u_i &=u_i-u_{i-1} & \text{方向盘转角变化}    \\
r_\theta,& R, r_u & 权重系数
\end{aligned} 
$$

约束函数中，第一项为状态方程，第二项为碰撞检测，第三项为控制参数变化范围。

文中没有对碰撞检测做更加详细的说明，只提到使用了Minkowski sum[^3].

在规划的具体实施上，文中提出了分两步走的策略，其中定义了一个方便脱困的中间转换点(Phase switching point)$q_P$.整个规划是倒着从库内到库外规划，因此两步规划分别为：
1. phase B: $q_E\rightarrow q_P$,从终点到转换点
2. phase A: $q_P\rightarrow q_S$,从转换点到起点

![parking_opti_two_phase](imgs/parking_opti_two_phase.png)



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

## cites

[^1]:[2000-Randomized kinodynamic motion planning with moving obstacles](http://ai.stanford.edu/~latombe/papers/IJRR-kino/final.pdf)
[^2]:1991-A fast path planner for a car-like indoor mobile robot
[^3]: [Spatial planning: A configuration space approach,” IEEE Trans. Comput., vol. C-32, no. 2, pp. 108–120, 1983.](https://dspace.mit.edu/handle/1721.1/5684)
---
title: multistage based parking planner
categories: autopilot
tags: parking|planning|optimization
date: 2023-05-12
---

## 2022 Dftpav: Flatness-Based Trajectory

1. analytic trajectory representation with <font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>differential flatness</font> property
2.  efficient obstacle avoidance with a <font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>safe driving corridor</font> for unmodelled obstacles
3. <font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>signed distance approximations</font> for
dynamic moving objects

**<font color='Tomato'>Ref</font>**

- [An Efficient Spatial-Temporal Trajectory Planner for Autonomous Vehicles in Unstructured Environments](https://arxiv.org/pdf/2208.13160.pdf)
- [Differential Flatness-Based Trajectory Planning for Autonomous Vehicles]()
- [code](https://github.com/ZJU-FAST-Lab/Dftpav/tree/main)

**<font color='Tomato'>Related Work</font>**

- trajectory optimization:
    1. convex elastic band smoothing (CES): eliminates the non-convexity of the curvature constraint with fixed path lengths, transform the original problem into a quadratically constrained quadratic program (QCQP)
    2. dualloop iterative anchoring path smoothing (DL-IAPS): sequential convex optimization (SCP) is used to relax the curvature constraint
- obstacle avoidance
    1. two circle to cover ego car
    2. OBCA: 增加优化问题维数; 对偶元和障碍物数量成正比
    3. H-OBCA, with MPC

**<font color='Tomato'>SPATIAL-TEMPORAL TRAJECTORY PLANNING</font>**

adopt the lightweight hybridA* algorithm to find a collision-free path that is further optimized by the proposed planner. 


<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>differential flatness</font>

[1995: Differential flatness of mechanical control systems: A catalog of prototype systems]()

对非线性系统通过有限的微分近似进行降维. 对于机器人的运动规划,可以将所有的轨迹约束映射到平坦输出空间,降低优化维数.得到最优解之后再上升回到初始的状态空间中.

比如对于二维车辆,其独立变量理论上只需要两个量.假设取平坦输出为$x, y$, 输入取速度和前轮转角.则可以得到关系式:

$$\begin{aligned}
& v = \sqrt{\dot{x}^2 + \dot{y}^2}    \\
& \delta = \arctan [\frac{l(\dot{y}\ddot{x}-\dot{x}\ddot{y})}{v^3}]
\end{aligned}$$

此时规划轨迹可以只需要得到$x(t), y(t)$. 一般可以选择基函数$\beta(t)$组合成平坦输出:

$$x(t) = \sum_j \alpha_j\beta_j(t) \\
y(t) = \sum_j \alpha_j\beta_j(t)$$

比如常见的把$x,y$表示为多项式进行表示.

<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>Differentially Flat Vehicle Model</font>:

$$\begin{aligned}
\text{let}~ \boldsymbol\sigma& = (\sigma_x, \sigma_y)^T\\
v & =\eta \sqrt{{\dot{\sigma_x}}^2+{\dot{\sigma_y}}^2} \\
\theta & =\arctan 2\left(\eta \dot{\sigma}_y, \eta \dot{\sigma}_x\right) \\
a_t & =\eta\left(\dot{\sigma_x} \ddot{\sigma}_x+\dot{\sigma}_y \ddot{\sigma}_y\right) / \sqrt{{\dot{\sigma_x}}^2+\dot{\sigma}_y^2} \\
a_n & =\eta\left(\dot{\sigma_x} \ddot{\sigma}_y-\dot{\sigma}_y \ddot{\sigma}_x\right) / \sqrt{{\dot{\sigma_x}}^2+\dot{\sigma}_y^2} \\
\phi & =\arctan \left(\eta\left(\dot{\sigma}_x \ddot{\sigma}_y-\dot{\sigma}_y \ddot{\sigma}_x\right) L /\left(\dot{\sigma}_x{ }^2+\dot{\sigma}_y{ }^2\right)^{\frac{3}{2}}\right) \\
\kappa & =\eta\left(\dot{\sigma}_x \ddot{\sigma}_y-{\dot{\sigma_y}}^{\sigma_x}\right) /\left({\dot{\sigma_x}}^2+{\dot{\sigma_y}}^2\right)^{\frac{3}{2}} \\
\eta & \in \{-1, 1 \} \quad \text{motion direction}
\end{aligned}$$

"with the natural **differential flatness property**,we can use the **flat outputs and their finite derivatives to characterize arbitrary state quantities** of the vehicle, which **simplifies the trajectory planning** and facilitates optimization".

avoid singularities by fixing the velocity magnitude to a small, non-zero constant when the gear shifts. Both the gear shifting position and directional angle can be optimized(<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>优化换挡点</font>).

**<font color='Tomato'>INSTANTANEOUS STATE CONSTRAINTS</font>**

**<font color='Tomato'>Dynamic Feasibility</font>**

**<font color='Tomato'>Static Obstacle Avoidance</font>**

generate free convex polygon based on the sampling point([2020 Generating large convex polytopes directly on point clouds](https://arxiv.org/abs/2010.08744), [code](https://github.com/StarryN/Galaxy)).

H-representation:  On canonical representations of convex polyhedra
## 2022 FTHA && Iterative NLP

1. 通过hybrid A* 寻找相对较优的轨迹, 避免搜索失败
2. 圆形代替车身; 基于圆形的二维C空间; 构建方形corridor
3. 罚函数代替边界约束条件; 多次求解, 根据当前最优轨迹重新构建corridor

<font color='Tomato'>ref</font>

- [Optimization-based trajectory planning for autonomous parking with irregularly placed obstacles: A lightweight iterative framework]()
- [github](https://github.com/libai1943/ParkingMotionPlanningTITS21)
- [bilibili](https://www.bilibili.com/video/BV1n7411q7iv/)

<font color='Tomato'>Abstract</font>

- focused on optimization base parking
- within-corridor collision constraints: scale is small and independent from environment complexity
- reconstructs the corridor in an iterative framework

<font color='Tomato'>Intro</font>

- samping / seach based
- optimization based

contributions:

1. a fault-tolerant variant of the hybrid A∗ algorithm is proposed
2. an iterative framework that incorporates a corridor construction procedure and a lightweight NLP solution procedure


<font color='Tomato'>Problem formulation</font>

bicycle kinematic model:


$$\mathbf{Z}(t)~=~[x(t),y(t),\theta(t),v(t),\phi(t)] \\
{\mathbf{u}}(t)\equiv[a(t)_{\ast}\omega(t)]{\mathbf{i}} $$


为了避免$\theta \in [0, \pi]$的不连续,边界条件以三角函数约束代替值约束:

$$\theta(t) = \theta_t \rightarrow \left\{ \begin{aligned}\sin \theta(t) = \sin \theta_t \\ \cos \theta(t) = \cos \theta_t\end{aligned}\right.$$

<font color='Tomato'>Collision avoidance</font>

根据三角形面积构造不等式

<font color='Tomato'>Corridor Construction</font>

对于给定的初始路径,可以只考虑该初始值的"附近空间结构",而不需要考虑环境中所有的障碍物,这样就避免过多的障碍物导致的复杂计算.

Generation of a Guiding Route

fault-tolerant hybrid A∗ (FTHA): 

1. 如果算法失败,就选择当前为止最优的结点,通过A*与终点连接
2. 添加简单的速度信息生成初解

construction of corridors

沿着四个方向按固定步长逐渐增长,若失败或者达到最大长度则停止扩大

![corridor_construction.png](imgs/corridor_construction.png)

Within-Corridor Constraint Formulation


障碍物约束改写为圆在`corridor` 里面:

$P_{\mathrm{f}}(t)$ stays inkth local box for $P_{\mathrm{f}}.$ 

$P_{\mathrm{r}}(t)$ stays inkth local box for $P_{\mathrm{r}},$, $t = T/N_{FE}·k,k =1,\cdots,N_{FE}$

$$
\begin{array}{l l}{{x_{\mathrm{r}}(t)}}{{\in\left[x\mathrm{r}_{\mathrm{min}}^{k},\,{\bf x}\mathrm{nax}\right],}} ~ {{y_{\mathrm{r}}(t)\in\left[y\mathrm{r}_{\mathrm{min}}^{k},\,{\bf y}\mathrm{r}_{\mathrm{max}}^{k}\right],}}\\ {{t=T/{\bf N}_{\mathrm{FE}}\cdot k,}} ~ {{k=1,\cdot\cdot\cdot.....\,,{\bf N}_{\mathrm{FE}}.}}\end{array} 
$$

<font color='Tomato'>LIGHTWEIGHT ITERATIVE OPTIMIZATION
FRAMEWORK</font>

penalty function to merge boundary constraints

iteratively solve the ocp problem and generate corridors based on the optimal trajectory util the infeasibility is reduced to tiny


##  2021 tiny passage

<font color='Tomato'>Ref</font>

- [Autonomous Parking Trajectory Planning With Tiny Passages A Combination of Multistage Hybrid A-Star Algorithm and Numerical Optimal Control]()

freespace规划

1. A* 发现窄通道
2. 混合A* 连接窄通道
3. 基于优化方案进行后处理

后处理的碰撞检测使用within-STC constraints


## TDR-OBCA

## H-OBCA

## Ref

- [An Efficient Spatial-Temporal Trajectory Planner for Autonomous Vehicles in Unstructured Environments](https://arxiv.org/pdf/2208.13160.pdf)
- [Differential Flatness-Based Trajectory Planning for Autonomous Vehicles]()
- [2015 CES: A convex optimization approach to smooth trajectories for motion planning with car-like robots]()
- [2021 Autonomous driving trajectory optimization with dual-loop iterative anchoring path smoothing and piecewise-jerk speed optimization]()
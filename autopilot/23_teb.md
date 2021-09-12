---
title: time elastic band 
categories: autopilot
tags: planning
date: 2021-09-06
---

## Elastic Band

EB is a local planner which needs an origin path to optimize.

two force:

- internal contraction force: 收缩力，消除松弛，张紧路线
- external repulsive force: 障碍物的排斥力

performance:

- handle dynamic obstacles
- may fail when changes are large(resort to global planner)

#### Bubbles

在b位置与障碍物的最小距离，这实际上定义了一个无障碍的圆空间：

$$\rho(b)$$

则b处的bubble：

$$B(b)=\{\mathbf{q}:\|\mathbf{b}-\mathbf{q}\|<\rho(\mathbf{b})\}$$

而elastic band可以看作是由有限个bubble组成。落在这些bubbles中的点保证是无碰撞的。为了保证路径无碰撞，假设各个相邻bubble重叠，则连接邻近bubble的圆心的线段可以保证无碰撞。

![](imgs/teb_bubbles.jpg)

距离障碍物越近，bubble越小，数量也会越多。bubble的形状不限于圆形，也可以为椭圆，但是计算量会增大。

#### deform strategy

$$\begin{align}
\mathbf{f}_{c} & =k_{c}\left(\frac{\mathbf{b}_{i-1}-\mathbf{b}_{i}}{\left\|\mathbf{b}_{i-1}-\mathbf{b}_{i}\right\|}+\frac{\mathbf{b}_{i+1}-\mathbf{b}_{i}}{\left\|\mathbf{b}_{i+1}-\mathbf{b}_{i}\right\|}\right)  \\
\mathbf{f}_{r} & = \begin{cases}k_{r}\left(\rho_{0}-\rho\right) \frac{\partial \rho}{\partial \mathbf{b}} & \rho<\rho_{0} \\ 0 & \rho \geq \rho_{0}\end{cases}
\end{align}$$



## Time Elastic Band

global planner -> local planner

TEB is a local planner



## ref

- blog
- projects
    - [teb_local_planner](https://github.com/rst-tu-dortmund/teb_local_planner)
    - [eband_local_planner](https://github.com/utexas-bwi/eband_local_planner)
    - [eband planner](https://github.com/bhaskara/eband_planner)
    - [pp-ElasticBand- standlone](https://github.com/youmnam/pp-ElasticBand)
- paper
    - elastic band
        - [1993-elastic Bands: Connecting Path Planning and Control]()
    - common
        - [2012-Trajectory modification considering dynamic constraints of autonomous robots]()
        - [2013-  Efficient trajectory optimization using a sparse model]()
    - extensive
        - [2015 Planning of Multiple Robot Trajectories in Distinctive Topologie]()
        -[2017 Integrated online trajectory planning and optimization in distinctive topologies]()
        - [2017- Kinodynamic Trajectory Optimization and Control for Car-Like Robots]()
        - [2014 TEB + NMPC: Timed-Elastic-Bands for Predictive Control]()
        - [2015 TEB + NMPC: Timed-elastic-bands for time-optimal point-to-point nonlinear model predictive control]()
        - [2014-Planning of optimal collision avoidance trajectories with timed elastic bands]()
        - [2015- A Convex Optimization Approach to Smooth  trajectoriesfor Motion Planning with Car-Like Robots ]()
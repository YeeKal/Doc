---
title: 轨迹优化(trajectory optimization) 
categories: motion planning
tags: planning
date: 2021-08-17
---

## 2003-Reactive Nonholonomic Trajectory Generation via Parametric Optimal Control

**Abstract**

1. parametric trajectory reduce computation time, at the cost os potentially introducing suboptimality

## 轨迹规划/轨迹拟合

通过连续曲线连接路经点

维度：拟合的曲线参数组数跟数据点的维度一致

**cubic polynomials**

三次多项式曲线： $\theta(t)=a_0+a_1t+a_2t^2+a_3t^3$

边界条件:

$$\begin{bmatrix}\theta_i \\ \theta_{i+1} \\ \dot\theta_i \\ \dot\theta_{i+1}  \end{bmatrix} =
\begin{bmatrix} 1 & 0& 0&0 \\
     1 & \Delta t& \Delta t^2&\Delta t^3 \\
      0 & 1& 0&0 \\
     0 & 1& 2\Delta t& 3\Delta t^2 
 \end{bmatrix}  \begin{bmatrix} a_0 \\a_1\\a_2\\a_3\end{bmatrix}$$

保证速度连续，有唯一解

多个数据点 -> 曲线拟合：

- n个数据点， m维度
- (n-1)*m条曲线， 4*(n-1)*m个
- 首尾边界条件 + 中间边界条件 + 中间连续条件 = 4*m+2*(n-2)*m+2*(n-2)*m=4*(n-1)*m

**quintic polynominal**

五次多项式： 加速度连续



## optimization

- [polytraj](https://github.com/jsford/PolyTraj)
- [Trajectory Optimization motion planning](https://github.com/bestvibes/motion-planner)
- [Convex Optimization for motion plannin](https://github.com/Theochiro/motion-planning)
- [trajopt](https://rll.berkeley.edu/trajopt/doc/sphinx_build/html/)

路径: 可以称为一条曲线，但是这条曲线本身并不依赖时间因子。同样的一条曲线可以以不同的速度运动。因此这条曲线上面的导数并不代表速度，如果在二维(X-Y), 这个导数代表了不同纬度速度的比值,而不是速度本身。

曲线：曲线需要有规律。这个规律是指可以用有限个参数的函数来表示，这样才能约束点与点之间的关系。另一方面，为了满足运动学特性，需要曲线n阶连续(速度，加速度...),所以一般会选择多项式来进行曲线拟合。曲线需要满足一些条件，比如路经点的位置，速度，加速度等作为约束。这样的曲线可能有无数条，因此再定义一个目标函数(比如，路径最短，能量最小等)转化为一个优化问题，求出在该目标函数下最优的一条曲线。

参数方程(以二维平面举例)：若只关注曲线，没有速度，加速度，则位置以s为参数进行表示。

曲率: 描述了几何体的弯曲程度。在二维平面上，曲率表示了曲线上某个点的切线方向角对弧长的转动率。曲率代表了曲线本身的特性。

$$\kappa=\kappa(s)  \\
\theta=\int \kappa(s)ds$$

尺度: 不同尺度相同位置的点会得到相同的曲线， 这样会造成原本只需首尾是曲线中间大部分是直线的解没办法得到。即曲线只适合较短路径的拟合？(受制于参数方程的本身特性)

避障：如何避障？这也决定了参数方程拟合的方式适合短距离无障碍物的假设空间。

规划 or 轨迹优化: 这种方法更适合在有了路径点之后，对路径进行轨迹化。

- 为路径添加时间序列
- 基于优化的规划
- 轨迹优化(会改变路径点)


轨迹:


## ref

- blog 
    - [参数化最优控制 约束-控制-图形参数](https://blog.csdn.net/Neo11111/article/details/105960645)
    - [基于多项式螺旋曲线的轨迹优化](https://blog.csdn.net/github_39582118/article/details/117754864?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-1.control&spm=1001.2101.3001.4242)
    - [trajectory optimization](http://www.matthewpeterkelly.com/tutorials/trajectoryOptimization/cartPoleCollocation.svg#frame1129)
    - [Transcription Methods for Trajectory Optimization](https://arxiv.org/pdf/1707.00284.pdf)
    - [轨迹优化04. 轨迹拟合 & 轨迹插值](https://zhuanlan.zhihu.com/p/342012866)
- project
    - [OptimTraj-maTLAB](https://github.com/MatthewPeterKelly/OptimTraj/tree/master/demo/cartPole)
- course
    - [台大机器人学之运动学——林沛群-b站](https://www.bilibili.com/video/BV1v4411H7ez)
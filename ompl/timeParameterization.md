---
title: time parameterization
categories: ompl
tags: planning
date: 2018-10-30
---

Interpolation:

- segment interpolation: straight-line segment and transition segment
- polynomial curves
- cubic curves: Hermite cubic splines, Bezier curve, B-spline, nonuniform rational B-spline
- cubic spline: 三次样条曲线
- quintic spline: 五次样条曲线
- Reeds-Shepp 曲线
- Dubins 曲线

## trajectory processing in moveit:
- [class documentation](http://docs.ros.org/melodic/api/moveit_core/html/classtrajectory__processing_1_1IterativeParabolicTimeParameterization.html)
- [github](https://github.com/ros-planning/moveit/tree/master/moveit_core/trajectory_processing/src)

which contains three executable trajectory processing methods:

- IterativeParabolicTimeParameterization:
    - [ref github issue](https://github.com/ros-planning/moveit/issues/160)
- IterativeSplineParameterization
    - [ref github issue](https://github.com/ros-planning/moveit/pull/382)
- TimeOptimalTrajectoryGeneration
    - [website](http://www.golems.org/projects/traj.html)
    - TOPP

## 轨迹规划-离散时间序列

- 三次多项式插值

[点到点轨迹规划——三次曲线，五次曲线，梯形曲线，S曲线](https://blog.csdn.net/fengyu19930920/article/details/81043776)
[ur末端画圆](https://blog.csdn.net/ckkboy/article/details/82959359)
[三次样条插值介绍](https://www.cnblogs.com/ondaytobewhoyouwant/p/8989497.html)

## 插值

- SE3
- SO3

[slerp for quaterion](https://en.wikipedia.org/wiki/Slerp)

$$Slerp(p_0 ,p_1,;t)=\frac{sin[(1-t)\theta]}{sin\theta}p_0+\frac{sin[t\cdot\theta]}{sin\theta}p_1$$
$$Linear(p_0 ,p_1,;t)=(1-t)p_0+t\cdot q_1$$

## TOPP

- [TOPP](https://github.com/quangounet/TOPP)
- [TOPPRA](https://github.com/hungpham2511/toppra)

[轨迹规划-样条插补-古月](http://www.guyuehome.com/752)

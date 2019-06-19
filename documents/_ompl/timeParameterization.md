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
- IterativeParabolicTimeParameterization
- IterativeSplineParameterization
- TimeOptimalTrajectoryGeneration

## TOPP

- [TOPP](https://github.com/quangounet/TOPP)
- [TOPPRA](https://github.com/hungpham2511/toppra)

[轨迹规划-样条插补-古月](http://www.guyuehome.com/752)

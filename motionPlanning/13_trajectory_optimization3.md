---
title: 轨迹优化之
categories: motion planning
tags: planning
date: 2021-08-17
---

- elastic band
- chomp
- stomp
- trajopt
- itomp

## trajopt


## chomp

functional gradient: 泛函梯度

$$\bar{\nabla} u[\xi]=\frac{\partial v}{\partial \xi}-\frac{d}{d t} \frac{\partial v}{\partial \xi^{\prime}}$$

梯度下降：

$$\xi_{i+1}=\xi_{i}-\eta_{i} \bar{\nabla} U[\xi]$$

## stomp

## moveit 三种轨迹优化方法对比

- Time-optimal Trajectory Parameterization
- Iterative Spline Parameterization
- Iterative Parabolic Time Parameterization

## time optimal path

## 2014-TOPP

A General, Fast, and Robust Implementation of the Time-Optimal Path Parameterization Algorithm

#### introduction

three families of methods：

- dynamic programming: divide the$(s, \dot{s})$ plane into a grid and find the optimal trajectory in the $(s,\dot{s})$ plane
- convex optimization: discretize the s-axis into N segments and subsequently convert into a convex optimization problem
- numerical integration: Pontryagin Maximum Principle(庞特里雅金极大原理 ), the optimal trajectory in the $(s, \dot{s})$ plane is known to be “bang-bang” and can thus be found by integrating successively the maximum and minimum accelerations $\ddot{s}$. But the programming is difficult with the so-called dynamic singularities


This paper develops a numerical integration method considering the dynamic singularities.

bang-bang control: 起停式控制，有迟滞区间。在最优控制中，若最优控制信号为其上限或下限，则该最优控制问题可以以起停式控制为最优解。起停式控制常出现在最短时间的最佳控制问题中[2]。例如要车辆行驶一定距离，且从出发到最后停止的时间要最短，其解法是在经过某一“切换点”前用最大油门加速，过切换点后以最大刹车方式刹车，让车停在想要的位置。---- [wiki](https://zh.wikipedia.org/wiki/%E8%B5%B7%E5%81%9C%E5%BC%8F%E6%8E%A7%E5%88%B6)

#### improve the robustness of the numerical integration approach

General formulation of the TOPP problem:








## ref

- blog 
- paper
    - [trajectory planning for automatic machines and robots]()
    - time optimal path
        - Numerical Integration
            - [2016-Essential Properties of Numerical Integration for Time-optimal Trajectory Planning Along a Specified Path]()
            - [2013-A general, fast, and robust implementation of the time-optimal path parameterization algorithm]()
            - [2018_TOPP_A New Approach to Time-Optimal Path Parameterization Based on Reachability Analysis](https://arxiv.org/abs/1707.07239)
                - [code-github](https://github.com/quangounet/TOPP)
                - [Improved IPTP by fitting a cubic spline](https://github.com/ros-planning/moveit/pull/382)
                - [github-Improved IPTP](https://github.com/ros-planning/moveit/tree/master/moveit_core/trajectory_processing/src)
            - [2019-Time-optimal path tracking for robots a numerical integration-like approach combined with an iterative learning algorithm]()
        - convex optimization
            - [Time-Optimal Path Tracking for Robots: A Convex Optimization Approach]()
            - [2012_IJRR_Collisionfree and smooth trajectory computation in cluttered environments]()
            - [2012-rss-TOTG-Time-optimal trajectory generation for path following with bounded acceleration and velocity](http://www.roboticsproceedings.org/rss08/p27.pdf)
                - [projects](http://www.golems.org/projects/traj.html)
                - [code](https://github.com/tobiaskunz/trajectories)
            - [2013-Fast Interpolation and Time-Optimization on Implicit Contact Submanifolds]()
                - [project](https://motion.cs.illinois.edu/mintos/)
            
    - motion planning
        - [2013_rss_Finding locally optimal, collision-free trajectories with sequential convex optimization]()
            - [blog](https://rll.berkeley.edu/trajopt/rss/)
        - [2009-CHOMP:Gradient optimization techniques for efficient motion planning]()
        - [2011_icra_STOMP: Stochastic trajectory optimization for motion planning]()
        - [2012_ICAPS_ITOMP: Incremental trajectory optimization for real-time replanning in dynamic environments]()
        - [2017_ISRR_Fast any time motion planning in point clouds by interleaving sampling and interior point optimization]()
        - [trajopt](https://rll.berkeley.edu/trajopt/doc/sphinx_build/html/) 
            - [code](https://github.com/joschu/trajopt)
        - [2011-Parallel Algorithms for Real-time Motion Planning](https://www.ri.cmu.edu/pub_files/2011/7/mcnaughton-thesis.pdf)
        - [itomp]()
            - [blog](https://gamma.cs.unc.edu/ITOMP/ITOMP_ROS/)
            - [github - code](https://github.com/Chpark/itomp)
    - grasp motion planning
        - [2020_ICRA_GOMP: Grasp-Optimized Motion Planning for Bin Picking]()
- projects
    - [Efficient Trajectory Optimization for Robot Motion Planning -- Examples](https://github.com/yzhao334/Efficient-Trajectory-Optimization-for-Robot-Motion-Planning--Examples)
    - [towr](https://github.com/ethz-adrl/towr)
    - [gpmp2](https://github.com/gtrll/gpmp2)

---
title: 轨迹优化之
categories: motion planning
tags: planning
date: 2021-08-17
---

## trajopt


## chomp

functional gradient: 泛函梯度

$$\bar{\nabla} u[\xi]=\frac{\partial v}{\partial \xi}-\frac{d}{d t} \frac{\partial v}{\partial \xi^{\prime}}$$

梯度下降：

$$\xi_{i+1}=\xi_{i}-\eta_{i} \bar{\nabla} U[\xi]$$

## moveit 三种轨迹优化方法对比

- Time-optimal Trajectory Parameterization
- Iterative Spline Parameterization
- Iterative Parabolic Time Parameterization




## ref

- blog 
- paper
    - trajectory
        - [2012_IJRR_Collisionfree and smooth trajectory computation in cluttered environments]()
        - [2014-A general, fast, and robust implementation of the time-optimal path parameterization algorithm]()
        - [2012-rss-TOTG-Time-optimal trajectory generation for path following with bounded acceleration and velocity](http://www.roboticsproceedings.org/rss08/p27.pdf)
            - [projects](http://www.golems.org/projects/traj.html)
            - [code](https://github.com/tobiaskunz/trajectories)
        - [2018_TOPP_A New Approach to Time-Optimal Path Parameterization Based on Reachability Analysis](https://arxiv.org/abs/1707.07239)
            - [code-github](https://github.com/quangounet/TOPP)
            - [Improved IPTP by fitting a cubic spline](https://github.com/ros-planning/moveit/pull/382)
            - [github-Improved IPTP](https://github.com/ros-planning/moveit/tree/master/moveit_core/trajectory_processing/src)

    - motion planning
        - [2013_rss_Finding locally optimal, collision-free trajectories with sequential convex optimization]()
        - [2009-CHOMP:Gradient optimization techniques for efficient motion planning]()
        - [2011_icra_STOMP: Stochastic trajectory optimization for motion planning]()
        - [2012_ICAPS_ITOMP: Incremental trajectory optimization for real-time replanning in dynamic environments]()
        - [2017_ISRR_Fast any time motion planning in point clouds by interleaving sampling and interior point optimization]()
        - [trajopt](https://rll.berkeley.edu/trajopt/doc/sphinx_build/html/) 
        - [2011-Parallel Algorithms for Real-time Motion Planning](https://www.ri.cmu.edu/pub_files/2011/7/mcnaughton-thesis.pdf)
    - grasp motion planning
        - [2020_ICRA_GOMP: Grasp-Optimized Motion Planning for Bin Picking]()

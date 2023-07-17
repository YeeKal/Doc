---
title: 低维下的运动规划
categories: autopilot
tags: autopilot
date: 2021-04-27
---

## planning methods

1. 碰撞检测
2. 状态方程
3. 换档点的优化


- [bench-mr](https://github.com/robot-motion/bench-mr)


## ref

- blog
    - [MOTION PLANNING](http://motion.cs.illinois.edu/RoboticSystems/PlanningWithDynamicsAndUncertainty.html)
- paper
    - [2022 db-A*: Discontinuity-bounded Search for Kinodynamic Mobile Robot Motion Planning](https://arxiv.org/abs/2203.11108)
    - [2017-A tutorial on newton methods for constrained trajectory optimization and relations to slam, gaussian process smoothing, optimal control, and probabilistic inference](https://argmin.lis.tu-berlin.de/papers/17-toussaint-Newton.pdf)
    - [2008-kpiece:Kinodynamic Motion Planning by Interior-Exterior Cell Exploration](https://ioan.sucan.ro/files/pubs/wafr2008.pdf)

    
- book
    - [Robotic Systems](https://motion.cs.illinois.edu/RoboticSystems/)
- library
    - * Search-based: ARA* (using SBPL http://www.sbpl.net/)
    - * Sampling-based: SST* (using OMPL https://ompl.kavrakilab.org/)
    - * [Hybrid: db-A*](https://github.com/IMRCLab/kinodynamic-motion-planning-benchmark)

## ref

- blog
- paper
    - [Implementation of Autonomous Parking with Two Path Planning Algorithms](https://web.archive.org/web/20200608071214/http://kth.diva-portal.org/smash/get/diva2:1329148/FULLTEXT01.pdf)
- project
    - [rrt_reeds_shepp](https://github.com/sjs5904/Reeds-Shepp/blob/master/rrt_reeds_shepp.py)
---
title: optimization based parking planner
categories: autopilot
tags: autopilot
date: 2023-01-12
---

## Intro

1. MIQP
2. Bilevel Optimization
3. Mathematical Program with Complementarity Constraints (MPCC)
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

## A Linear and Exact Algorithm for Whole-Body Collision Evaluation via Scale Optimization


## Mixed Integer Conic Optimization using Julia and JuMP

- [lecture: Mixed Integer Conic Optimization using Julia and JuMP](https://github.com/juan-pablo-vielma/grid-science-2019)
- [paper: Extended Formulations in Mixed Integer Conic Quadratic Programming]()

## Narrow-Roads-Timed-Elastic-Band

<font color='Tomato'>Ref</font>

- [An Optimization-Based Motion Planner for Car-like Logistics Robots on Narrow Roads]()

结合TEB进行窄通道的freespace规划

Narrow-Roads-Timed-Elastic-Band



## 2016 single step optimization

- [Optimisation based path planning for car parking in narrow environments]()
- tags: `运动规划(motion planning)` `基于优化的方法(optimization based)` `自动驾驶(autopilot)`
- algorithm guidance:
    1. phase A and phase B 的规划
    2. 对于狭窄空间,guide-tree 进行换挡采样
- [courses/ko/parking:对以上算法的实践](https://cw.fel.cvut.cz/b202/_media/courses/ko/parking.pdf)
- [paper notes](../blog/paper_read_parking_planner.md)


## 0130

- [2016 Spatio-temporal decomposition: a knowledge-based initialization strategy for parallel parking motion optimization]()
- [2017 Hybrid curvature steer: A novel extend function for sampling-based nonholonomic motion planning in tight environments]()
- [2022 Parallel Parking: Optimal Entry and Minimum Slot Dimensions](https://arxiv.org/abs/2205.02523)
- [2016 Time-Optimal Maneuver Planning in Automatic Parallel Parking Using a Simultaneous Dynamic Optimization Approach]()

## 0203

- [Trajectory optimization for Car-Like Vehicles in Structured and Semi-Structured Environments](https://ieeexplore.ieee.org/document/8500373)
- [Efficient_Collision_Detection_between_2D_Polygons](https://www.researchgate.net/publication/221546279_Efficient_Collision_Detection_between_2D_Polygons)

## ref


- project
    - [Collision Avoidance in Tightly-Constrained Environments without Coordination: a Hierarchical Control Approach](https://sites.google.com/berkeley.edu/sg-control)
- paper
    - [2016 Optimisation based path planning for car parking in narrow environments]()
    - [2013 A fast motion planning algorithm for car parking based on static optimization]()
    - [Practical motion planning for car-parking control in narrow environment]()
    - [A new geometry-based secondary path planning for automatic parking](https://journals.sagepub.com/doi/full/10.1177/1729881420930575)
    - [2022 Continuous-Curvature Target Tree Algorithm for Path Planning in Complex Parking Environments](https://arxiv.org/pdf/2201.03163.pdf)
    - [ALTRO: A Fast Solver for Constrained Trajectory Optimization](https://www.ri.cmu.edu/publications/altro-a-fast-solver-for-constrained-trajectory-optimization/)
    - [Solving Constrained Trajectory Planning Problems Using Biased Particle Swarm Optimization](https://dspace.lib.cranfield.ac.uk/bitstream/handle/1826/16453/Solving_Constrained_Trajectory_Planning_problems-2021.pdf?sequence=4)
    - [2020-An Optimization-Based Receding Horizon Trajectory Planning Algorithm](https://www.sciencedirect.com/science/article/pii/S2405896320330810)
    - [kinodynamic-motion-planning-benchmark](https://github.com/IMRCLab/kinodynamic-motion-planning-benchmark)
    - [2008 - On-line Path Planning For an Autonomous Vehicle in an Obstacle Filled Environment](https://folk.ntnu.no/skoge/prost/proceedings/cdc-2008/data/papers/1745.pdf)
    - [2021 - Fast UAV Trajectory Optimization using Bilevel Optimization with Analytical Gradients](https://arxiv.org/pdf/1811.10753.pdf)
    - [2019-A bilevel optimal motion planning (BOMP) model with application to autonomous parking]()
- paper(NN)
    - [Time-Optimized Online Planning For Parallel Parking With Nonlinear Optimization and Improved Monte Carlo Tree Search](https://www.semanticscholar.org/paper/Time-Optimized-Online-Planning-For-Parallel-Parking-Song-Chen/9ace2c192aea884f16ceac206ec278007139651d)
- course
    - [EECS C106B](https://pages.github.berkeley.edu/EECS-106/sp22-site/resources/)
    - [Path-Planning-for-a-Simple-Car](https://jckantor.github.io/CBE30338/07.06-Path-Planning-for-a-Simple-Car.html)
- tool / library
    - [2017_PYROBOCOP: Python-based Robotic Control & Optimization Package for Manipulation and Collision Avoidance]()
    - [nmpc by casadi](https://github.com/devsonni/MPC-Implementation/tree/main/Python%20Implementation)

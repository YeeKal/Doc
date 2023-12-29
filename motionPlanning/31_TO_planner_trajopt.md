---
title: trajopt: Trajectory Optimization for Motion Planning
categories: 
tags: 
date: 2023-11-28
---

- [Mainpage](https://rll.berkeley.edu/trajopt/doc/sphinx_build/html/)
- [2013_rss_Finding locally optimal, collision-free trajectories with sequential convex optimization](http://joschu.net/docs/trajopt-paper.pdf)
- [blog](https://rll.berkeley.edu/trajopt/rss/)

> trajopt is a software framework for generating robot trajectories by local optimization.
> 
> The following core capabilities are included:
>
>1. a solver for non-convex optimization problems, using sequential convex optimization.
>2. cost and constraint functions for kinematics and collision avoidance
>3. constructing problems from JSON-based specification format


## Implementation in moveit

**<font color='Tomato'>collision</font>**

tesseract_collision

## Implementation in tesseract


## Implementation

**<font color='Tomato'>Collision detection</font>**

通过多个球近似机器人实体

Approximate each link as a union of spheres:[Medial Spheres for Shape Approximation](http://www.cs.mcgill.ca/~kry/pubs/cim10/cim10.pdf)

First get distance field for mesh
Find medial axis points



**<font color='Tomato'>Trilinear interpolation</font>**



## Ref
- implementations
    - [trajopt single ](https://github.com/joschu/trajopt/tree/master)
    - [tesseract trajopt](https://github.com/tesseract-robotics/trajopt/tree/master)
    - [tesseract motion planner](https://github.com/tesseract-robotics/tesseract_planning/blob/master/tesseract_motion_planners/trajopt/src/trajopt_collision_config.cpp)
    - [trajopt in moveit](https://github.com/ros-planning/moveit/blob/master/moveit_planners/trajopt/src/trajopt_interface.cpp#L72)
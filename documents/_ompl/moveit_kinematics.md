---
title: moveit kinematics
categories: ompl
tags: planning
date: 2019-01-04
---

- [kinematics_base-github ](https://github.com/ros-planning/moveit/tree/melodic-devel/moveit_core/kinematics_base)
- [kinematics plugin-github](https://github.com/ros-planning/moveit/tree/melodic-devel/moveit_kinematics)
- [kdl plugin-github](https://github.com/ros-planning/moveit/tree/melodic-devel/moveit_kinematics/kdl_kinematics_plugin)

**KinematicsBase**

Basic kinematics interface in moveit.

In KDL plugin:  
- chainiksolver_pos_nr_jl_mimic: 逆运动学，加入关节限位和mimic关节
- chainiksolver_vel_pinv_mimic.hpp： jacobian求解，加入mimic关节
- kdl_kinematics_plugin：KinematicsBase子类，执行kdl求解
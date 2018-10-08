---
title: ompl
categories: ompl
tags: planning
date: 2018-07-18
---

## source installation with moveit

- install ros
- [moveit source installation](http://moveit.ros.org/install/source/)
    - prerequisites
- [building from source](http://moveit.ros.org/install/source/dependencies/)

**errors**

1. [Removed EuclideanProjection, changed to Eigen vector.](https://github.com/ros-planning/moveit/pull/903/files)
2. libompl.so: copied from "/usr/local/lib" to destination.

**add a new planner**

**Modify MoveIt! Source**

In your MoveIt! directory, modify src/moveit_planners/ompl/ompl_interface/src/planning_context_manager.cpp. Include the header file that defines your planner at the top and register your planner in the registerDefaultPlanners() function as the existing ones are

**Install MoveIt! from Source**

Finish the last 2 steps of the MoveIt! installation (catkin_make and source the install)

If you **did not overwrite the existing OMPL**  in your ros directory, you will have to set environment variables to tell MoveIt! which version of OMPL to use

You can set: OMPL_PREFIX = [local install directory]

append OMPL_PREFIX to CMAKE_PREFIX_PATH

**Modify ompl_planning.yaml**

If you've already generated MoveIt! config files for your robot, modify /config/ompl_planning.yaml in YOURROBOT_moveit_config to include the option for the new planner.

**re-build**

for the older package which uses moveit, clean the build files(delete build||devel) and re-build this package.

[official](http://moveit.ros.org/install/source/)
[qiu-zhihu](https://www.zhihu.com/question/55861914)

## reference

1. [rrt.cpp in github](https://github.com/ompl/ompl/blob/master/src/ompl/geometric/planners/rrt/src/RRT.cpp)
2. [rrt.h in github](https://github.com/ompl/ompl/blob/master/src/ompl/geometric/planners/rrt/RRT.h)
3. [new motion planner](http://ompl.kavrakilab.org/newPlanner.html)
4. [planning_interface ](http://docs.ros.org/kinetic/api/moveit_ros_planning_interface/html/index.html)
5. [ompl_interface in moveit](https://github.com/ros-planning/moveit/tree/kinetic-devel/moveit_planners/ompl/ompl_interface/src)

**samples**

[ Quadcopter path planning using ompl in ros](https://github.com/ayushgaud/path_planning)

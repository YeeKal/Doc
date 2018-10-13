---
title: what happened when selecting sampler
categories: ompl
tags: planning
date: 2018-10-09
---

much work has been done in `constraint_sampler_manager_->selectSampler()`;

## constraint samper

```c++
//generate ik_solver in configure()
kinematics::KinematicsBaseConstPtr kb_; 
IKConstraintSampler::configure(){
    ....
    kb_ = jmg_->getSolverInstance();
    loadIKSolver();
    ....
}
```

## setStateValidityChecker

- [state_validity_checker.cpp](https://github.com/ros-planning/moveit_planners/blob/kinetic-devel/ompl/ompl_interface/src/detail/state_validity_checker.cpp)
- [state_validity_checker.h](https://github.com/ros-planning/moveit_planners/blob/kinetic-devel/ompl/ompl_interface/include/moveit/ompl_interface/detail/state_validity_checker.h)

```c++
void ompl_interface::ModelBasedPlanningContext::configure(){
    ompl_simple_setup_->setStateValidityChecker(ob::StateValidityCheckerPtr(new StateValidityChecker(this)));
}
```

## add collision to the world

- [planning_scene_monitor.cpp](https://github.com/ros-planning/moveit/blob/b02ef29bee78f31744f7507d9db70d1677116cef/moveit_ros/planning/planning_scene_monitor/src/planning_scene_monitor.cpp)
- [planning_scene_monitor.h](https://github.com/ros-planning/moveit/blob/b02ef29bee78f31744f7507d9db70d1677116cef/moveit_ros/planning/planning_scene_monitor/include/moveit/planning_scene_monitor/planning_scene_monitor.h)

```c++
ros::Subscriber planning_scene_subscriber_;
ros::Subscriber planning_scene_world_subscriber_;
ros::Subscriber attached_collision_object_subscriber_;

planning_scene_subscriber_ =
        root_nh_.subscribe(scene_topic, 100, &PlanningSceneMonitor::newPlanningSceneCallback, this);

void planning_scene_monitor::PlanningSceneMonitor::newPlanningSceneCallback(
    const moveit_msgs::PlanningSceneConstPtr& scene)
{
  newPlanningSceneMessage(*scene);
}
```

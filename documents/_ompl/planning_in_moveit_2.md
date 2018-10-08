---
title: analyze planning in moveit 2 
categories: ompl
tags: planning
date: 2018-10-08
---

load robot model

```c++
//in motion_planning_api_tutorial.launch
<include file="$(find pr2_moveit_config)/launch/planning_context.launch">
    <arg name="load_robot_description" value="true"/>
  </include>

//in planning_context.launch
//the robot_description was launched
<!-- Load universal robot description format (URDF) -->
  <param if="$(arg load_robot_description)" name="$(arg robot_description)" command="$(find xacro)/xacro --inorder '$(find pr2_description)/robots/pr2_no_kinect.urdf.xacro'"/>

//then in your code
robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
robot_model::RobotModelPtr robot_model = robot_model_loader.getModel();
planning_scene::PlanningScenePtr planning_scene(new planning_scene::PlanningScene(robot_model));
robot_state::RobotState& robot_state = planning_scene->getCurrentStateNonConst();
//or
robot_state::RobotStatePtr robot_state(new robot_state::RobotState(robot_model));
```

moveit_msgs::DisplayTrajectory

```
DisplayTrajectory->
    RobotTrajectory[] ->trajectory_msgs/JointTrajectory
    ->trajectory_msgs::JointTrajectoryPoint
    ->double[] positions

```

**PlanningScene**

- [PlanningScene.h](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/planning_scene/include/moveit/planning_scene/planning_scene.h)
- [PlanningScene.cpp](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/planning_scene/src/planning_scene.cpp)

self collision checking and obstacle collision checking.

In `move_group`, `planning_scene_interface` is used.

- [PlanningSceneInterface](https://github.com/ros-planning/moveit/blob/54d516a4e6fdc5db9dfcba4da9e916d807ea312a/moveit_ros/planning_interface/planning_scene_interface/src/planning_scene_interface.cpp)
- [PlanningSceneInterface.cpp](https://github.com/ros-planning/moveit/blob/54d516a4e6fdc5db9dfcba4da9e916d807ea312a/moveit_ros/planning_interface/planning_scene_interface/src/planning_scene_interface.cpp)

```c++
private:
    ros::ServiceClient planning_scene_service_;
    ros::ServiceClient apply_planning_scene_service_;
    ros::Publisher planning_scene_diff_publisher_;
void addCollisionObjects(){
    ......//构造完planning_scene,然后发布出去
    moveit_msgs::PlanningScene planning_scene;
    planning_scene_diff_publisher_.publish(planning_scene);
}
```

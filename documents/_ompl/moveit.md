---
title: moveit
categories: ompl
tags: planning
date: 2018-07-15
---

**moveit configuration package**

roslaunch moveit_setup_assistant setup_assistant.launch

[analyse the file](https://www.ncnynl.com/archives/201612/1138.html)

- moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
- moveit::planning_interface::MoveGroupInterface::Plan my_plan;
- moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

```c++
  robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
  robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
  robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));

  kinematic_state->setToDefaultValues();
  const robot_state::JointModelGroup *joint_model_group = kinematic_model->getJointModelGroup("right_arm");
  const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();
```

- [moveit core](http://docs.ros.org/kinetic/api/moveit_core/html/namespacemoveit_1_1core.html)
    - [RobotState](http://docs.ros.org/kinetic/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html)
    - [RobotModel](http://docs.ros.org/kinetic/api/moveit_core/html/classmoveit_1_1core_1_1RobotModel.html)
    - [JointModelGroup](http://docs.ros.org/kinetic/api/moveit_core/html/joint__model__group_8h_source.html)
- [eigen_msg](http://docs.ros.org/jade/api/eigen_conversions/html/eigen__msg_8h.html)
- [PlanningPipeline](http://docs.ros.org/jade/api/moveit_ros_planning/html/classplanning__pipeline_1_1PlanningPipeline.html)

## RobotState

[getJacobian()](http://docs.ros.org/jade/api/moveit_core/html/robot__state_8cpp_source.html#l01098)


     
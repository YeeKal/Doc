---
title: api examples
categories: ompl
tags: moveit
date: 2018-11-15
---

```c++
//moveit
robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
robot_model::RobotModelPtr robot_model = robot_model_loader.getModel();
robot_state::RobotStatePtr robot_state(new robot_state::RobotState(kinematic_model));

const robot_state::JointModelGroup *joint_model_group = kinematic_model->getJointModelGroup("right_arm");
const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();
```
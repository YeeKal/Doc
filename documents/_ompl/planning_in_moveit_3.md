---
title: planning in moveit - collision checking
categories: ompl
tags: planning
date: 2018-10-12
---

主页设计：色块+首字母，时间顺序展示
category：同一类别放在左侧索引里/
archive：集中展示，没有色块，按时间顺序
post：右侧目录

## planningSceneMonitor

[move_group.cpp](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_ros/move_group/src/move_group.cpp)

- planning_scene_interface: publish planning_scene,可以自己写发布者。若是自己写了planning_scene_monitor，可以不用发布/接收消息这一层。
- planning_scene_monitor: 通过`robot_description`,构建robot_model_loder_, robot_model_,planning_scene. 之后通过MoveGroupExe类后见moveGroupCapabilities以及相关move_group节点。 这里面涉及构建collision_objects和planning_scene更新的具体细节，还是需要这个类来处理构建障碍物。
```c++
//in move_group.cpp
int main(int argc, char** argv)
{
  ros::init(argc, argv, move_group::NODE_NAME);

  ros::AsyncSpinner spinner(1);
  spinner.start();

  boost::shared_ptr<tf::TransformListener> tf(new tf::TransformListener(ros::Duration(10.0)));

  planning_scene_monitor::PlanningSceneMonitorPtr planning_scene_monitor(
      new planning_scene_monitor::PlanningSceneMonitor(ROBOT_DESCRIPTION, tf));

  if (planning_scene_monitor->getPlanningScene())
  {
    bool debug = false;
    for (int i = 1; i < argc; ++i)
      if (strncmp(argv[i], "--debug", 7) == 0)
      {
        debug = true;
        break;
      }
    if (debug)
      ROS_INFO("MoveGroup debug mode is ON");
    else
      ROS_INFO("MoveGroup debug mode is OFF");

    printf(MOVEIT_CONSOLE_COLOR_CYAN "Starting context monitors...\n" MOVEIT_CONSOLE_COLOR_RESET);
    planning_scene_monitor->startSceneMonitor();
    planning_scene_monitor->startWorldGeometryMonitor();
    planning_scene_monitor->startStateMonitor();
    printf(MOVEIT_CONSOLE_COLOR_CYAN "Context monitors started.\n" MOVEIT_CONSOLE_COLOR_RESET);

    move_group::MoveGroupExe mge(planning_scene_monitor, debug);

    planning_scene_monitor->publishDebugInformation(debug);

    mge.status();

    ros::waitForShutdown();
  }
  else
    ROS_ERROR("Planning scene not configured");

  return 0;
}
```

## 理念

- moveit: 用户是傻瓜。用户只需要定义目标约束，如何把目标约束转化为采样约束则交给moveit规划接口来做。
- me: 用户是超人。用户需要什么样的目标约束由用户自己定义采样约束，自己构造问题进行求解。

so:

- moveit ask: What can I do for you? And I\`ll drive you there.
- me: What can I do for you? And this is the car which you can drive yourself anywhere.

**state monitor**

```c++
//in planning scene monitor
 CurrentStateMonitorPtr current_state_monitor_;
 startStateMonitor(const std::string& joint_states_topic);//joint_states

//in planning scene
/*
Apply changes to this planning scene
*/
 planning_scene->usePlanningSceneMsg(planning_scene_k);
```

- [rviz_visual_tools::rvt](http://docs.ros.org/jade/api/rviz_visual_tools/html/classrviz__visual__tools_1_1RvizVisualTools.html)
- [moveit_visual_tools::rvt](http://docs.ros.org/jade/api/moveit_visual_tools/html/classmoveit__visual__tools_1_1MoveItVisualTools.html)
- [visualization_msgs/Marker](http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html)


## state validity checker

- [state_validity_checker.cpp](https://github.com/ros-planning/moveit_planners/blob/kinetic-devel/ompl/ompl_interface/src/detail/state_validity_checker.cpp)

```c++
//
class StateValidityChecker : public ompl::base::StateValidityChecker{
public:
	StateValidityChecker(const ModelBasedPlanningContext *planning_context);
	isValid(state);
	isValidWithCache(state);//最终的合法性判断函数
};
bool isValidWithCache(const ompl::base::State *state, bool verbose){
	// check path constraints
	const kinematic_constraints::KinematicConstraintSetPtr &kset = planning_context_->getPathConstraints();
	if (kset && !kset->decide(*kstate, verbose).satisfied)
	{
	const_cast<ob::State*>(state)->as<ModelBasedStateSpace::StateType>()->markInvalid();
	return false;
	}

	// check feasibility
	if (!planning_context_->getPlanningScene()->isStateFeasible(*kstate, verbose))
	{
	const_cast<ob::State*>(state)->as<ModelBasedStateSpace::StateType>()->markInvalid();
	return false;
	}

	// check collision avoidance
	collision_detection::CollisionResult res;
	planning_context_->getPlanningScene()->checkCollision(verbose ? collision_request_simple_verbose_ : collision_request_simple_, res, *kstate);
	if (res.collision == false)
	{
	const_cast<ob::State*>(state)->as<ModelBasedStateSpace::StateType>()->markValid();
	return true;
	}
	else
	{
	const_cast<ob::State*>(state)->as<ModelBasedStateSpace::StateType>()->markInvalid();
	return false;
	}
}
```



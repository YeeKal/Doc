---
title: planning scene monitor
categories: ompl
tags: planning
date: 2018-10-25
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
  
  
图论->鱼骨架
鱼骨架->规划先验路径
  
  
```
我:邱博，sda ros驱动有没有开放读写i/o的接口
q:没有
我:是不是需要修改下层驱动
q:是
我:邱博，你之前做规划，比如之前演示的双臂夹一个板子一起运动的规划是用了moveit的环境么，那是不是用了moveit里面更加底层的函数，比如planningcontext来操作ompl的接口
q:直接用的ompl
我:那你建立机器人模型，求逆解，碰撞检测都是自己重写了接口么
q:不用，ros的
q:只是不用moveit 封装后的
我:那是怎么做的
q:你看ompl教程
q:把state validation 改成fcl
我:ompl官方教程么
q:目标点用逆解算好
q:是
我:之前花了很大功夫看moveit源码，想着怎么能实现既能保留moveit丰富的功能，又能开放ompl的接口，
q:只要看ompl就行了
q:moveit 没什么功能呀
q:只是封装
我:但是，我就是不知道怎么把这些功能集成起来
我:ompl教程看了也没看出什么
q:你先看moveit 怎么调用ompl
q:你自己调用也是一样
我:我看了，moveit自己建了一个modelbasedstate space，planningcontext来进行状态空间，采样器的建立，planning scene进行碰撞检测,
q:具体看调用ompl那一段
我:我可不可以看下你的环境配置啊
q:不用配置，你现在的就都可以直接调用
q:建议只看ompl，不要被moveit 限制了
我:fcl进行validstatechecker，那怎么建立机器人运动学模型呢
我:还是，直接手写进入
q:用ROS的
q:这部分也可以用moveit
q:都无所谓的，你只是规划器换掉
我:还是urdfmodelloader读取urdf的方式来建立是么
q:你先直接用moveit 写好的就行
我:那是自己写statespace,还是用moveit的
我:用moveit的modelbased state space
q:ompl里自己写
q:只用碰撞检测和逆解
q:还有显示
我:逆解是怎么做的
q:其他ompl都可以做了
q:逆解只要计算一次呀，就是规划的目标点
我:用什么来算呢，还是配置什么库
q:kdl或者moveit 不都有吗
我:好的
```
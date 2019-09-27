---
title: introduction
categories: navigation
tags: navigation
date: 2019-09-24
---

## [ros navigation](http://wiki.ros.org/navigation/)

![overview](pics/overview.png)
三个常用规划包：

1. move_base：根据参照的消息进行路径规划，使移动机器人到达指定的位置；
2. gmapping：根据激光数据（或者深度数据模拟的激光数据）建立地图；
3. amcl：根据已经有的地图进行定位。

消息：

- /cmd_vel: move_base发布的移动命令/移动车接受的命令
- /move_base/goal
- /odom: 里程计信息
- /scan:


**move_base**

1. navigation goal: 通过 MoveBaseAction , MoveBaseGoal等实现，MoveBaseGoal封装了目标pose数据，客服端程序将MoveBaseGoal类型数据发送给MoveBaseAction服务端启动导航过程。
2. global planner: 全局规划器 利用地图与规划算法规划一条从当前位置到目标位置的最优路径。
3. local planner: 可以利用传感器数据识别不在地图中障碍物信息，如果本地规划行不通，会请求重新进行全局规划。

查看tf关系：

- 使用rqt_tf_tree: rosrun rqt_tf_tree rqt_tf_tree
- 使用tf_echo: rosrun tf tf_echo [parent_frame_id] [child_frame_id]

**map**

- 地图种类
    - Occupancy Grid Map: 占据栅格地图
- 建图算法
    - Gmapping
    - HectorSlAM
    - Karto
    - Cartographer

## ref

- [ros navigation](http://wiki.ros.org/navigation/)
- [cmd_vel to wheel speed](https://blog.csdn.net/heyijia0327/article/details/41823809)
- [用ROS开发自己的机器人](https://blog.csdn.net/heyijia0327/article/category/2768679)


## paper

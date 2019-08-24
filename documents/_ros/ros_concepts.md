---
title: ros begining
categories: ros
tags: ros
date: 2017-11-01
---

**create a workspace**

``` 
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
$ source devel/setup.bash
```
**a catkin package**

```
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
# This is an example, do not try to run this
# catkin_create_pkg <package_name> [depend1] [depend2] [depend3]

$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash
$ catkin_make --pkg <pk-a> <pk-b>
```

command line


node/topic/msg
no space in "<node-name>"
**topics**

```
$ rosrun rqt_graph rqt_graph
```

[moveit concepts pipline](http://moveit.ros.org/documentation/concepts/)


- moveit
1. edit CMakeLists.txt and package.xml to add support include files
2. rvizvisualtoolsgui to give the command
3. markeyarray : rviz_visual_tools ; or the connection can't be established.
```
- Class: rviz/MarkerArray
    Enabled: true
    Marker Topic: /rviz_visual_tools
    Name: MarkerArray

or:
  add `MarkerArray` then settings
```

同一个窗口 source一次可能不能使用其他的包，还需要在source其它包之后再重新编译。 






## tf 


> rosrun tf tf_echo /graber_4t_link /graber_end
> rosrun tf view_frames   //监听当前时刻所有通过ros广播的tf坐标
---
title: simulate with turtlebot
categories: navigation
tags: navigation
date: 2019-09-24
---

open in terminal:

> roslaunch rbx1_bringup fake_turtlebot.launch 
> roslaunch rbx1_nav fake_amcl.launch map:=test_map.yaml  
> rosrun rviz rviz -d `rospack find rbx1_nav`/nav.rviz

1. 构建虚拟turtlebot，创建BaseController，接受'cmd_vel'命令
2. 创建amcl导航，启动move_base,发布地图
3. 启动rviz显示


## 示例

**机器人启动文件**

```xml
<!-- open sensor -->
<launch>
  <node pkg="sensor_node_pkg" type="sensor_node_type" name="sensor_node_name" output="screen">
    <param name="sensor_param" value="param_value" />
  </node>
 
 <!-- open odometry -->
  <node pkg="odom_node_pkg" type="odom_node_type" name="odom_node" output="screen">
    <param name="odom_param" value="param_value" />
  </node>
 
 <!-- tf transform -->
  <node pkg="transform_configuration_pkg" type="transform_configuration_type" name="transform_configuration_name" output="screen">
    <param name="transform_configuration_param" value="param_value" />
  </node>
</launch>
```

**tf transform**

[official tutorial](http://wiki.ros.org/navigation/Tutorials/RobotSetup/TF)

```c++
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "robot_tf_publisher");
    ros::NodeHandle n;

    ros::Rate r(100);

    tf::TransformBroadcaster broadcaster;

    while(n.ok()){
        broadcaster.sendTransform(
        tf::StampedTransform(
            tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.1, 0.0, 0.2)),
            ros::Time::now(),"base_link", "base_laser"));
        r.sleep();
    }
}
```
---
title: simulate with agv
categories: navigation
tags: navigation
date: 2019-10-10
---

open in terminal:

> roslaunch rrbot_gazebo rrbot_world.launch  
> roslaunch agv_nav gmapping_demo.launch
> rosrun rviz rviz -d `rospack find rbx1_nav`/nav.rviz
> rosrun teleop_twist_keyboard teleop_twist_keyboard.py 

- taleop_twist_keyboard:键盘控制




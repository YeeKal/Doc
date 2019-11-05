---
title: command for detection and grasping
categories: cv
tags: pcl
date: 2019-10-31
---

## dependencies
- 0rk
	- [object-recognition-core](http://wg-perception.github.io/ork_tutorials/tutorial03/tutorial.html)
	- [installation](http://wg-perception.github.io/object_recognition_core/install.html#install)
- Super4PCS
	- [Super4PCS Library compilation](http://nmellado.github.io/Super4PCS/a05034.html)


 ## commands
```c++
//open realsense
roslaunch realsense2_camera rs_camera.launch
// open realsense with rgbd
roslaunch realsense2_camera rs_camera.launch filters:=pointcloud
// depth align
roslaunch realsense2_camera rs_camera.launch align_depth:=true


// open openni
```
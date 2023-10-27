---
title: convex corridor 
categories: 
tags: 
date: 2023-06-04
---

JPS jump point search

运动规划 motion planning 方法motion planning


### SFC: Safe Flight Corridor

<font color='Tomato'>Ref</font>

- [2017 Planning Dynamically Feasible Trajectories for Quadrotors using Safe Flight Corridors in 3-D Complex Environments]()
- [code](https://github.com/sikang/DecompUtil/blob/master/test/test_seed_decomp.cpp)

| seed decomp                   | line segment                  | iterative decomp                   | ellipsoid decomp                   |
| ----------------------------- | ----------------------------- | ---------------------------------- | ---------------------------------- |
| ![output_seed.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/output_seed.svg) | ![output_line.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/output_line.svg) | ![output_iterative.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/output_iterative.svg) | ![output_ellipsoid.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/output_ellipsoid.svg) |


**<font color='Tomato'>SFC construction</font>**

1. find ellipsoid
    - 根据最近点缩小椭圆
2. find polyhedron
    - 一步步扩大寻找半平面
3. bounding box: 裁剪
4. shrink： 寻找更合适的半平面以包括起点和终点

**<font color='Tomato'>Trajectory optimization</font>**

**<font color='Tomato'>RHP: Receding Horizon Planning</font>**

- execution planning $T_e$
- re-planning for the next epoch when the robot is executing the trajectory at the current epoch

**<font color='Tomato'>ref paper</font>**

- [Efficient mixed-integer planning for uavs in cluttered environments (ICRA), 2015]()
- [2015 Computing large convex regions of obstacle-free space through semidefinite programming]()



## GALAXY

<font color='Tomato'>Ref</font>

- [2020 Generating large convex polytopes directly on point clouds](https://arxiv.org/abs/2010.08744)
- [code](https://github.com/StarryN/Galaxy)
- [code 2](https://github.com/ZJU-FAST-Lab/Dftpav/blob/1808107b7fb6fe459f38154e355010a854e4575f/src/Plan/traj_planner/include/plan_utils/CorridorBuilder2d.hpp#L12)

| narrow space                              | hollow space               |
| ----------------------------------------- | -------------------------- |
| 狭窄环境的多边形边角突出,难以覆盖整个车形 | 空旷环境下效果较好         |
| ![galaxy_tiny.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/galaxy_tiny.png)             | ![galaxy_large.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/galaxy_large.png) |

依赖障碍物信息， 因此若障碍物分布不好，则找到的空旷区域会比较尖锐。
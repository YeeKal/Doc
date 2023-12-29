---
title: Signed Distance Field(SDF)
categories: motion planning
tags: 
date: 2023-11-30
---

- general method
    - fast marching method
    - fast sweeping method
    - level set method, 水平集方法
- geometry shape calculation
- object
    - 2d / 3d
    - geometry shape
    - image
    - 3d model, such as stl
- application
    - Surface Normals
    - Collision Detection
    - Geometry Processing: The gradient can be used for smoothing and sharpening features of a model, morphological operations, and other geometry processing tasks in 3D modeling and CAD software.


## computational sweeping

1. find the filled seed
2. BFS  expand

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/20231130202912.png)


## gradient

梯度为0的地方

鱼骨图 skeletal graphs

## 8-points Signed Sequential Euclidean Distance Transform

## Distance Transform

Distance Transform

Distance Transform源于图像处理，表示每个像素点距离前景图像之间的距离，可以用于图像分割，形态学，骨架提取等。事实上这其实就是产生了无符号的距离场。在机器人领域，可以用于生成障碍物的距离场，用于规划算法中。

- project
    - [Distance Transforms of Sampled Functions](https://cs.brown.edu/people/pfelzens/dt/)
    - [Fast Distance Transform](https://observablehq.com/@mourner/fast-distance-transform)
    - [Graph Based Image Segmentation](https://cs.brown.edu/people/pfelzens/segment/index.html)
    - [C++ Distance Transform: support 3d](https://github.com/giorgiomarcias/distance_transform/tree/master)
- sdf blog
    - [old gridmap](https://github.com/aybakana/grid_map/blob/master/grid_map_sdf/src/SignedDistanceField.cpp)
    - [new gridmap](https://github.com/ANYbotics/grid_map/blob/master/grid_map_sdf/include/grid_map_sdf/DistanceDerivatives.hpp)


## field sweeping

field sweeping isn’t perfect. the distance and the gradient may be slightly wrong.

![field sweeping](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/20231130151054.png)

use <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>Eikonal Sweep</font>. The comparison:

![Eikonal Sweep](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/20231130151233.png)

## Fast marching method

FMM: Fast Marching Method / FMS: fast marching square

- paper/notes:
    - [1999 - Fast marching method:Fast methods for the eikonal and related Hamilton-Jacobi equations on unstructured meshes.]()
    - Eran Treister and Eldad Haber. A fast marching algorithm for the factored eikonal equation. Journal of Computational Physics, 324:210-225, 2016.
    - [Implementing and Analysing the Fast Marching Method](https://essay.utwente.nl/75601/1/Alblas_BA_EWI.pdf)
- project
    - [eikonalfm c++](https://github.com/kevinganster/eikonalfm)

fast marching method 是求解程函方程的一种数值方法

Eikonal方程解u(x)的物理含义是从源点x0以速度f(x)到达计算域Ω内x点所需要消耗的最短时间。当f(x) = 1的特殊情况下，方程解就代表计算域Ω内的距离场。

Dijkstra算法和Fast marching算法思想相似，不同之处在于Dijkstra算法利用节点之间的欧式距离进行更新. 而Fast marching算法利用由Eikonal方程化简得到的近似偏微分方程进行更新，更加接近真实的距离，边缘处更加光滑。

## Collision Detection


## Ref

- paper
    - [2023 A_Differentiable_Signed_Distance_Representation_for_Continuous_Collision_Avoidance_in_Optimization-Based_Motion_Planning](https://www.researchgate.net/publication/368664467_A_Differentiable_Signed_Distance_Representation_for_Continuous_Collision_Avoidance_in_Optimization-Based_Motion_Planning)
- blog
    - [geometry shape](https://iquilezles.org/articles/distfunctions/)
    - [plot 3d donut in terminal](https://vgel.me/posts/donut/)
    - [Closest Point Coordinate Fields](https://prideout.net/coordinate-fields)
- project
    - [Signed Distance Fields c++](https://github.com/chriscummings100/signeddistancefields/tree/master)
    - [sdf python](https://github.com/fogleman/sdf/tree/main)
    - [Graph Based Image Segmentation](https://cs.brown.edu/people/pfelzens/segment/index.html)
    - [Distance Transforms of Sampled Functions](https://cs.brown.edu/people/pfelzens/dt/)
    - [Local Optimization for Robust Signed Distance Field Collision](https://www.shadertoy.com/view/wdcGDB)
    - [scd](https://github.com/guthriejd1/scd)
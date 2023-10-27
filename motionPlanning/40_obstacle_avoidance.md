---
title: obstacle avoidance
categories: motion planning
tags: optimal control 
date: 2021-10-29
---

- 按照维度区分
    - 2D 平面
    - 3D 
- 按照优化方案
    - 直接计算
    - 优化中的梯度计算

## 两个box 碰撞检测

分两种情况: 有一个点在另一个内部/重叠但是没有点在内部

![box_collision.jpg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/motionPlanning/imgs/box_collision.jpg)

第一种情况 三角形面积大于原始正方形;第二种情况在连续动态的环境里不会发生，如果发生必定已经发生了第一种情况。

$$S_{\Delta P A B}+S_{\Delta P B C}+S_{\Delta P C D}+S_{\Delta P D A}>S_{\square A B C D}$$

# 两条线的碰撞检测

转化为符号表达式, 参考

# polygon point collision

- [POLYGON/POINT](http://www.jeffreythompson.org/collision-detection/poly-point.php)
- [How can I determine whether a 2D Point is within a Polygon?](https://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon/2922778#2922778)
- [PNPOLY - Point Inclusion in Polygon Test](https://wrfranklin.org/Research/Short_Notes/pnpoly.html)

## polygon

- polygon circle
    - circle with line
    - center point in polygon
- polygon rectangle
    - rectangle with line
    - center point inside polygon

## PIVOT2D


## 优化问题中的平面凸多边形碰撞检测的处理

- [Apollo规划算法基于多边形分离的平滑分析](https://zhuanlan.zhihu.com/p/74528875)
- [自动泊车规划算法基于多边形分离的平滑分析](https://zhuanlan.zhihu.com/p/162973842)
- [apollo obca中的实现](https://zhuanlan.zhihu.com/p/157743632)

$$\begin{aligned}
& -b_1 \lambda-b_2 \mu>0 \\
& A_1^T \lambda+z=0 \\
& A_2^T \mu-z=0 \\
& \|z\|_* \leq 1 \\
& \lambda \succeq 0 \\
& \mu \succeq 0
\end{aligned}$$


- [polyhedra-and-polytopes](https://scaron.info/blog/polyhedra-and-polytopes.html)


## PYROBOCOP: Python-based Robotic Control & Optimization Package for Manipulation and Collision Avoidance
---

Orthogonal Collocation Method 正交配置法, 是加权余项法(Method of Weighted Residuals)的一种, 与传统差分法相比，具有计算精度高和稳定性好等优点.

mathematical programs with complementarity constraints (MPCCs)


**<font color='Tomato'>Collision avoidance</font>**

$$\begin{array}{cc}
\min _{\alpha_i, \alpha_j} & \left\|V_i(x, y) \alpha_i-V_j(x, y) \alpha_j\right\| \\
\text { s.t. } & 1^T \alpha_i=1,1^T \alpha_j=1 \\
& \alpha_i, \alpha_j \geq 0
\end{array}$$

where $1^T \alpha_i=1$ means the convex linear combination of the polytopes.

Reformulate using First-order stationary conditions.


## DCA

2022 Differentiable Collision Avoidance Using Collision Primitives

> Zimmermann S, Busenhart M, Huber S, et al. **Differentiable collision avoidance using collision primitives**[C]//2022 IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS). IEEE, 2022: 8086-8093.
> - [video](https://youtu.be/et0bu--wuy4)
> - [🐯 code:DCA-Differentiable collision avoidance](https://github.com/SimiPro/DCA)
> - 2022 iros; Collision Primitives
> - ref:[Optimal control via second order sensitivity analysis]()

Algorithms:

usion basic collision primitives to represent obstacle:

$$\mathbf{P}(\mathbf{x}, \mathbf{t})=\mathbf{p}(\mathbf{x})+\sum_{l=1}^L t_l \mathbf{v}_l(\mathbf{x}), \quad 0 \leq t_l \leq 1, \forall l$$

![collision_primitive.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/motionPlanning/imgs/collision_primitive.png)



1. barrier function
2. make collision constraints soft


## 2022 Motion Planning around Obstacles with Convex Optimization

- [:tiger:code: GCS-Graphs of Convex Sets](https://github.com/mpetersen94/gcs)

- Mixed-Integer Convex Programming (MICP) 
- Second-Order-Cone Programs (SOCPs)
- ref
    - [2015ICRA:Efficient mixed-integer planning for UAVs in cluttered environments]()

## 2022 finding and optimizing certified, collision-free regions in configuration space for robot manipulators

- `C-Iris`: C-space Iterative Regional Inflation by Semidefinite programming
- [code:C_Iris based drake](https://github.com/AlexandreAmice/drake/tree/C_Iris)

computing collision-free C-space regions:
- maximal-volume ellipse
- maximal expansion of the polytope

![ciris_maximal_expansion.jpg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/motionPlanning/imgs/ciris_maximal_expansion.jpg)

## 2022 
## Ref

- paper 
    - [Efficient Formulation of Collision Avoidance Constraints in Optimization Based Trajectory Planning and Control](https://arxiv.org/abs/2104.12641)
    - [PYROBOCOP: Python-based Robotic Control & Optimization Package for Manipulation and Collision Avoidance](https://arxiv.org/pdf/2106.03220.pdf)
        - [Research Software — PyRoboCOP](https://www.merl.com/research/license/PyRoboCOP)
        - [PyRoboCOP](https://github.com/merlresearch/PyRoboCOP)
    - [2004 Efficient collision detection between 2D polygons](https://www.academia.edu/7251297/Efficient_Collision_Detection_between_2D_Polygons)
    - [2022-Differentiable Collision Detection for a Set of Convex Primitives](https://arxiv.org/pdf/2207.00669.pdf)
    - [2022_Motion Planning using Reactive Circular Fields:A 2D Analysis of Collision Avoidance and Goal Convergence](https://arxiv.org/pdf/2210.16106v1.pdf)
    - [2022 Motion Planning around Obstacles with Convex Optimization](https://arxiv.org/pdf/2205.04422v1.pdf)
    - [finding and optimizing certified, collision-free regions in configuration space for robot manipulators](https://arxiv.org/abs/2205.03690)
- blog
    - [论文阅读：Efficient Formulation of Collision Avoidance Constraints in Optimization Based Trajectory](https://zhuanlan.zhihu.com/p/592762287)
    - [collision-detection tutorial](http://www.jeffreythompson.org/collision-detection/table_of_contents.php)

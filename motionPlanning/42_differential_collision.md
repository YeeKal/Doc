---
title: Differentiable Collision
categories: motion planning
tags: optimal control 
date: 2021-10-29
--- 

## DCOL

**<font color='Tomato'>Ref</font>**

- [2022-Differentiable Collision Detection for a Set of Convex Primitives](https://arxiv.org/pdf/2207.00669.pdf)
- [code](https://github.com/kevin-tracy/DifferentiableCollisions.jl)
- [author: kevin-tracy](https://github.com/kevin-tracy/kevin-tracy.github.io)

DCOL: a fast and fully differentiable collision-detection framework that reasons about colliisons between a set of composable and highly expressive convex primirive shapes.

利用凸优化的方式，处理凸可表达的形状的可微分的碰撞检测

**<font color='Tomato'>Introduction</font>**

-  non-differentiable collision methods
    - GJK
    - enhanced-GJK


**<font color='Tomato'>BACKGROUND</font>**

- Conic Optimization
- Differentiating Through a Cone Program

**<font color='Tomato'>DCOL A LGORITHM</font>**


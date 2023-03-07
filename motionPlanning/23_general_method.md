---
title: optimal motion planning
categories: motion planning
tags: optimal control 
date: 2021-10-29
---

## 2018 - Optimization-Based Collision Avoidance

#### introduction

提出轨迹优化中的难点：障碍物碰撞的表达。当前存在的方法不足：

- 降级为线性约束： [2014 - Motion planning with sequential convex optimization and convex collision checking]()
- 质点模型不切合实际
- 多面体(polyhedral)通常使用整数变量进行表达： [2002 - Review of Nonlinear Mixed-Integer and Disjunctive Programming Techniques]()。`Mixed-integer convex optimization`在非线性实时控制器上并不是一个可接受的选择

本文方法特点：

1. 构建凸集（polytope, ellipsoids and so on）
2. 对`signed distance`重新整理， 使得`least-intrusive trajectorie`成为可能
3. 整合了动力学，轨迹可直接在控制器上执行， kinodynamically feasible

相关进展(针对基于优化的避障方法)

- potential field
- point-mass models
    - polyhedral obstacles： disjunctive programming， mixed-integer optimization problem
    - ellipsoidal obstacles： smooth non-convex constraint
- full-dimensional controlled objects
    - keeping all vertices of the controlled object outside the obstacle: [2015-A unified motion planning method for parking an autonomous vehicle in the presence of irregularly placed obstacles]()
    - signed distance: [2014 - Motion planning with sequential convex optimization and convex collision checking]()
    - a smooth reformulation of the collision avoidance constraint for point-mass controlled objects and polyhedral obstacles: [2011 Trajectory generation for aircraft avoidance maneuvers using online optimization]()


#### problem definition


**collision modeling:**

- Robot: $\mathbb{E}(x_k) \subset \mathbb{R}^n$, space occupied by the controlled object at time $k$
- Obstacle: 

$$\mathbb{O}^{(m)}=\{y\in \mathbb{R}^n:A^{(m)} y \preceq _{\mathcal{K}}b^{(m)}\}, \quad A^{(m)} \in \mathbb{R}^{l \times n}, b^{(m)} \in \mathbb{R}^{l}, \text { and } \mathcal{K} \subset \mathbb{R}^{l}$$

$\mathcal{K}$ is a closed convex pointed cone with non-empty interior, this is entirely generic since any compact convex set admits a conic representation of the form,[ref: Convex Analysis, 1970]().(虽然这里符号复杂，但其实就是说障碍物可以用一个非齐次线性不等式表示.对于多面体，这时取$\mathcal{K}=\mathbb{R}^l_{+}$,非负象限也是正常锥的一种， 此时$\preceq _{\mathcal{K}}b^{(m)} = \leq$. 对于椭圆，可以取$\mathcal{K}=\mathbb{R}^l_{+}$为二阶锥。)

for point-mass robot: $\mathbb{E}(x_k)$ degenerate to a point $p_k$

for *full-dimensional* objects: model as the rotation and translation of the initial convex set $\mathbb{B}\subset \mathbb{R}^n$

$$\mathbb{E}\left(x_{k}\right)=R\left(x_{k}\right) \mathbb{B}+t\left(x_{k}\right), \quad \mathbb{B}:=\left\{y: G y \preceq_{\overline{\mathcal{K}}} g\right\}$$

#### collision avoidance for point-mass models

dual problem:

$$\begin{aligned}
\operatorname{dist}(\mathbb{E}(x), \mathbb{O}) &>\mathrm{d}_{\min } \\
& \Longleftrightarrow \exists \lambda \succeq_{\mathcal{K}^{*}} 0:(A p-b)^{\top} \lambda>\mathrm{d}_{\min },\left\|A^{\top} \lambda\right\|_{*} \leq 1
\end{aligned}$$

the problem as:

$$\begin{aligned}
\min _{\mathbf{x}, \mathbf{u}, \boldsymbol{\lambda}} & \sum_{k=0}^{N} \ell\left(x_{k}, u_{k}\right) \\
\text { s.t. } & x_{0}=x_{S}, x_{N+1}=x_{F} \\
& x_{k+1}=f\left(x_{k}, u_{k}\right), h\left(x_{k}, u_{k}\right) \leq 0 \\
&\left(A^{(m)} p_{k}-b^{(m)}\right)^{\top} \lambda_{k}^{(m)}>0 \\
&\left\|A^{(m)^{\top}} \lambda_{k}^{(m)}\right\|_{*} \leq 1, \lambda_{k}^{(m)} \succeq_{\mathcal{K}^{*}} 0 \\
& \text { for } k=0, \ldots, N, m=1, \ldots, M
\end{aligned}$$


**collision free trajectory generation**

signed distance: 把碰撞这个bool变量编码成带有碰撞程度的连续函数表达式中，让机器人明白这个障碍物的碰撞能到多大程度，以及走多远之后其碰撞的程度是怎么样的。这样碰撞就变得可微

$$\begin{aligned}
\operatorname{sd}(\mathbb{E}(x), \mathbb{O}) &>\mathrm{d} \\
& \Longleftrightarrow \exists \lambda \succeq_{\mathcal{K}^{*}} 0:(A p-b)^{\top} \lambda>\mathrm{d},\left\|A^{\top} \lambda\right\|_{*}=1
\end{aligned}$$

```python
                      signed distance              
        +----------------------------------------+ 
      2 |:                   :                  :| 
        | :                  :                 .'| 
        |  :                 :                .' | 
        |   :                :               .'  | 
        |    :               :              .'   | 
        |     :              :             .'    | 
        |      :             :            .'     | 
   y    |       :            :           .'      | 
        |        :           :          .'       | 
        |         :          :         .'        | 
        |''''''''''':'''''''':'''''''':''''''''''| 
        |            '.      :      .'           | 
        |              '.    :    .'             | 
        |                '.  :  .'               | 
     -1 |                  '.:.'                 | 
        +----------------------------------------+ 
         -2                                     2  
                             x                     

```





## Simultaneous path planning and trajectory optimization for robotic manipulators using discrete
mechanics and optimal control

- three stage
    - path planning
    - trajectory planning: velocity, smooth
    - control: torque
- swarm-intelligence based algorithm:
    - PSO(Particle Swarm Optimization)
    - ACO(Ant Colony OPtimization)
    - ABC(Artificial Bee Colony Optimization)
    - FA(Firefly Algorithms)
    - BA(Bat Algorithm) 
- dp



- trajectory planning
- trajectory optimization
- optimal trajectory planning


Time-optimal Control of Manipulators: 李群上机械臂的最优控制，路径规划和轨迹优化同时进行


## ref

- paper
    - [2006 - Optimal manipulator path planning with obstacles using disjunctive programming]()
    - [2016 - Mixed-Integer Quadratic Program - Optimal Trajectory Planning for Autonomous Driving Integrating Logical Constraints: An MIQP Perspective]()

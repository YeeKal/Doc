---
title: kinodynamic planning on manipulator
categories: motion planning
tags: kinodynamic
date:2019-07-04
---

## papers

**Probabilistically Complete Kinodynamic Planning for Robot Manipulators with Acceleration Limits**

- 2014
- use a 7-DOF manipulator to hit the nail at the desired velocity
- considers the joint acceleration limits and non-zero start and goal velocities


I. Introduction

1. rrt is successful in the geometric path planning problems
2. rrts do not have efficient steering methods to handle arbitrary differential constraints
3. provide a fast, non-iterative steering method for the boundary value problem

II. Problem Definition

- the state vector: $[p,v]$
- the double integrator system:     $\dot p=v,\quad \dot v =a$
- constraints on position,velocity and acceleration:

$$\begin{align}p_{min}\leq & p \leq p_{max} \\
v_{min}\leq & v \leq v_{max}  \\
a_{min}\leq & a \leq a_{max}    \\
p &\in C_{free}\end{align}$$

- the new method is called  DIMT: Double-Integrator Minimum Time
- this method ignores the position constraint and obstacles, which are handled by rrt.

III. Related Work

- decoupled: first to generate a path and than add time-parameterized parameters
- kinodynamic rrt: use the incremental simulator to forward simulate the system for a given time step and control input
- lqr-rrt: optimize the metric function. Lniearize the system dynamics with a quadratic cost function which leads to an lqr problem 
- trajectory optimization: CHOMP and STOMP.
- Double-Integrator Minimum Time

IV. Steering Method

DIMT is divided into two steps:
    1. calculate the minimum time to reach the next goal 
    2. calculate the trajectory 


**Fast Smoothing of Manipulator Trajectories using Optimal Bounded-Acceleration Shortcuts**

```
      V ^
        |
   v_max|____________________________________
        |
        |             /\
        |            /  \
        |           /    \
        |          /      \
        |         |   L    | 
        |         |        |
        |------------------------------------>
        |              t                      T
        |
   v_max|
        |____________________________________
        |            /  \
        |           /    \
        |          /      \
        |         |   L    | 
        |         |        |
        |------------------------------------>
        |              t                      T



```
To connect two nodes $[x_1,v_1]\rightarrow[x_2,v_2]$, define four motion primitives: the parabolas $P^+$ and $P^-$ accelerating at $a_{max}$ and $-a_{max}$, respectively, and the lines $L^+$ and $L^-$ traveling at $v_{max}$ and $-v_{max}$,respectively.There are four possible classes of motion primitive combinations that may be optimal: $P^+P-, P-P^+,P^+L^+P^-,P^-L^-P+$

1. $P^+P^-$: set $t_p$ the turning time
$$v_1+t_p a_{max}=v_2+a_{max} (t-t_p)   \\
\text{duration t and the turning time: }t_p=\frac{t}{2}+\frac{v_2-v_1}{2a_{max}}   $$

the solution is the quadratic equation:

$$a_{max}t_p^2+2v_1t_p+\frac{v_1^2-v_2^2}{2a_{max}}-(x_2-x_1)=0 \\
t=2t_p+\frac{v_1-v_2}{a_{max}}$$

2. $P^+L^+P^-$: the turning time $t_{p1},t_{p2}$
---
title: kinodynamic_motion_planning
categories: motion planning
tags: kinodynamic
date: 2019_06_17
---

## kinodynamic motion planning

The term kinodynamic planning was introduced by Canny, Donald, Reif, and Xavier [290] to refer to **motion planning problems for which velocity and acceleration bounds must be satisfied**.

BVP: boundary value problem

规划位置的同时还要规划速度

- Generalized waiter-motion with no-sliding constraints/generalized waiter-motion problem

- time-optimal motion planning/jerky motion

- differential constraints / dynamic constraints

- differential models: $\dot{x}=f(x,u)$
- discrete-time approximation:$x_{k+1}=f(x_k,u_k)$

## numerical integration process:
- Euler method: $x(\Delta t)\approx x(0)+\Delta tf(x(0),u(0))$
- Runge-Kutta method: refer to numerical method notes
    - the fourth-order Runge-Kutta integration method:

$$x(\Delta t)\approx x(o)+\frac{\Delta t}{6}(w_1,w_2,w_3,w_4)   \\
\begin{align}\text{in which: } w_1&=f(x{0},u(0)) \\
               w_2&=f(x{0}+\frac{1}{2}\Delta t w_1,u(\frac{1}{2}\Delta t))  \\
               w_3&=f(x{0}+\frac{1}{2}\Delta t w_2,u(\frac{1}{2}\Delta t))  \\
               w_2&=f(x{0}+\Delta t w_3,u(\Delta t))
\end{align}$$

- Multistep methods 
- Black-box simulators
- Reverse-time system simulation

## temp

- steering method
- driftless, 无向的
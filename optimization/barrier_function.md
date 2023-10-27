---
title: barrier function
categories: optimization
tags: optimization
date: 2023-02-17
---

把约束条件转化为目标函数的一部分，而约束条件转化为参数的范围约束。这些参数使得修改过的最优化问题的最优解在原始问题最优解的附近。对于一个特定的参数，可以很容易求出最优解。然后通过调整参数，使得最优解逼近原始问题的最优解。这种求解一系列无约束最优化的方法也被称为序列无约束极小化方法(SUMT: Sequential Unconstrained Minimization Technique)

## Log Barrier Function

对于凸优化问题

$$\begin{array}{ll}
\min _x & f(x) \\
\text { subject to } & h_i(x) \leq 0, \quad i=1, \ldots m \\
& A x=b
\end{array}$$

可以增加log barrier函数，把优化目标改为:
$$\min _x  f(x) - (1/t)\cdot\sum^m_{i=1}log(-h_i(x))    $$

其中约束条件$h_i(x) \leq 0$就是log函数的定义域，同时当$h_i(x)\rightarrow 0$时，log barrier会趋近于无穷大。因此若优化目标有最小值，则约束条件必能满足。其中$t>0$是一个很大的参数，用来调整log barrier函数对原优化目标的影响。

在每次求解的时候，固定参数t，求出当前的最优解。然后逐渐增大t，逼近原始问题的最优解。


其中barrier function 被定义为：
$$\phi(x) = -\sum^m_{i=1}log(-h_i(x))$$

相关梯度和Hessian函数：
$$\begin{gathered}
\nabla \phi(x)=-\sum_{i=1}^m \frac{1}{h_i(x)} \nabla h_i(x) \\
\nabla^2 \phi(x)=\sum_{i=1}^m \frac{1}{h_i(x)^2} \nabla h_i(x) \nabla h_i(x)^{\top}-\sum_{i=1}^m \frac{1}{h_i(x)} \nabla^2 h_i(x)
\end{gathered}$$


## Central Path

根据log barrier函数重写优化目标:

$$\begin{array}{ll}
\min _x & tf(x) + \phi(x) \\
\text { subject to } 
& A x=b
\end{array}$$

`central path`被定义为最优解关于参数t的函数$x^*(t)$. 根据KKT条件:

$$\begin{aligned}
A x^*(t)=b, h_i\left(x^*(t)\right)<0, i=1 \ldots m & \quad \text { Primal feasibility } \\
t \nabla f\left(x^*(t)\right)-\sum_{i=1}^m \frac{1}{h_i(x)} \nabla h_i(x)+A^{\boldsymbol{\top}} w & \quad \text { Stationarity }
\end{aligned}$$

对于线性优化，$f(x)=c^Tx$, 其central path $x^*(t)$如下图所示:

![central_path.jpg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/optimization/imgs/central_path.jpg)

## Ref

- course/slides
    - [Barrier Method](https://www.stat.cmu.edu/~ryantibs/convexopt-F15/lectures/15-barr-method.pdf)
- blog
    - [zhihu-数学Barrier Method](https://zhuanlan.zhihu.com/p/136592584)

---
title: shooting method for trajectory optimization
categories: motion planning
tags: trajectory optimization
date: 2023-04-01
---

## overview
- single shooting
- multiple shooting

离散控制量,根据状态方程通过积分求得状态量

$$\begin{aligned}\min_{u^0 \cdots u^t}&\quad \sum(J(x^t)) \\
s.t. & \quad x^{t+1} = f(x^t, u^t)\end{aligned}$$

<font color='Tomato'>Note:</font>
- multiple shooting求解会更容易一点，对初始误差不会特别敏感
---
title: 回旋螺线
categories: blog
tags: 
date: 2022-07-22
---

螺旋线有很多种，这里讨论的是“曲率随长度线性变化的螺旋线”, 即回旋螺线，又被称为**欧拉螺线(Euler Spiral)**，或者**羊角螺线(clothoid)**。在现实环境中经常需要曲线的曲率是连续变化的，因此欧拉螺线被广泛用于曲线拟合以及路径规划中。

回旋螺线的参数方程可以写为:

$$\begin{aligned}\kappa &= \alpha s + \kappa_0 \\
\kappa_0 & \rightarrow \text{curvature at init point}\\
\kappa & \rightarrow \text{curvature}\\
\kappa & \rightarrow \text{sharpness, curvature ratio}\\
s & \rightarrow \text{curve length} \end{aligned}
$$

为了计算方便，一般把$\kappa_0$ 设为0,则本文主要讨论的曲线参数方程为:
$$\kappa = \alpha s$$




![](imgs/clothoid.png)
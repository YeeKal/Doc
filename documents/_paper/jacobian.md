---
title: jacobian and tangent space
categories: paper
tags: closed
date: 2016-06-15
---

## tangent space
**切平面**

- 曲面方程：$F(x,y,z)$
- 法向量：$\vec{n}=(F_x,F_y,F_z)$
- 切平面： $F_x(x-a)+F_y(y-b)+F_z(z-c)=0$
- 方向导数：曲面方程$z=f(x,y)$在$p$点沿方向$\vec{l}=(cos\phi,sin\phi)$的方向导数：
$$\begin{align}
\frac{\partial f}{\partial l}&=\frac{\partial f}{\partial x}cos\phi+\frac{\partial f}{\partial y}sin\phi    \\
                            &=(\frac{\partial f}{\partial x},\frac{\partial f}P{\partial y})(cos\phi,sin\phi) \\
                            &=Gradient \cdot Direction
\end{align}$$
梯度在单位方向向量上的投影。

**切空间**

若有m个方程定义在n个变量上：
$$F_1(x_1,x_2,\dots,x_n)\\
F_2(x_1,x_2,\dots,x_n) \\
\dots                   \\
F_m(x_1,x_2,\dots,x_n)$$
则方程个数表示被限制的维度，也是法空间的维度。空间维度减去法空间维度是切空间维度。把方程在点P的偏导组合成矩阵形式A,则A的零空间是点P的切空间，表示的是与法空间相垂直的切向量$\vec{b}$的线性组合。
$$\begin{bmatrix}
\frac{\partial F_1}{\partial x_1} & \frac{\partial F_1}{\partial x_2} &\dots &\frac{\partial F_1}{\partial x_n} \\
\frac{\partial F_2}{\partial x_1} & \frac{\partial F_2}{\partial x_2} &\dots& \frac{\partial F_2}{\partial x_n} \\
\dots &\dots &\dots &\dots                      \\
\frac{\partial F_m}{\partial x_1} & \frac{\partial F_m}{\partial x_2} &\dots & \frac{\partial F_m}{\partial x_n} \\
\end{bmatrix}
\begin{bmatrix}
b_1 \\b_2\\ \dots \\b_n
\end{bmatrix}=0$$

## jacobian

雅克比矩阵表示线性近似:
$$y(x)\approx y(p)+J\cdot(x-p) $$
实质是切空间之间基底的线性变换.机器人末端速度与关节速度的关系:
$$\dot{X}=J\cdot \dot{q}$$

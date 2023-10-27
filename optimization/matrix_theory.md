---
title: 矩阵理论
categories: optimization
tags: optimization
date: 2023-06-28
---

## 矩阵空间

$$A = \left[\begin{array}{ccccccc}
a_{11} & a_{12} & a_{13} & \ldots & a_{1 j} & \ldots & a_{1 n} \\
a_{21} & a_{22} & a_{23} & \ldots & a_{2 j} & \ldots & a_{2 n} \\
a_{31} & a_{32} & a_{33} & \ldots & a_{3 j} & \ldots & a_{3 n} \\
\vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
a_{i 1} & a_{i 2} & a_{i 3} & \ldots & a_{i j} & \ldots & a_{i n} \\
\vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
a_{m 1} & a_{m 2} & a_{m 3} & \ldots & a_{m j} & \ldots & a_{m n}
\end{array}\right] \in \mathcal{R} ^{m\times n}$$

- $C(A)$: 列空间
- $C(A^T)$: 行空间
- NULL(A): 零空间
- NULL(A^T): 左零空间
- 行空间和零空间的维度只和为n
- 列空间和左零空间的维度只和为m
- 行空间和零空间正交（Orthogonality）

把矩阵写成行空间的向量组合, 则由零空间可推出行空间和零空间正交：

$$A = \begin{bmatrix}a_1^T \\ \cdots \\ a_2^T \\a_m^T \end{bmatrix}: Az=0 \rightarrow a_i^T z = 0$$

<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>线性空间投影： $Ax = b$</font>

b是A的列空间的线性组合， 若b中包含了左零空间中的维度($b= p+ e$)，则方程无解。但可以通过投影找到最近的解，即方程退化为$Ax = p$

![project_b.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/optimization/imgs/project_b.png)

x的基础解系是A的行空间的线性组合， 而x可以由零空间拓展成无数个解。

![project_four.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/optimization/imgs/project_four.png)

## 最小二乘法（Least Squares， LS）

$Ax = b$， 若无解， 则找到b在列空间的投影p。 使得Ax = p， 则p是距离b最近的解。

- br: 列空间
- bn: 左零空间

$$b - Ax = bn  \rightarrow A^T(b-Ax) = bn   \\
A^TAx = A^Tb \\
x = (A^TA)^{-1} A^T b$$


- 垂直
- 水平
- 广义最小二乘： Generalized Least Squares, GLS 
- 非线性扩展

## ref

- [the-four-fundamental-subspaces](https://www.itshared.org/2015/06/the-four-fundamental-subspaces.html)
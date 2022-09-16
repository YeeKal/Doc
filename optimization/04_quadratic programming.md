---
title: 二次规划
categories: optimization
tags: optimization
date: 2022-09-15
---

二次规划的基本形式：

$$\begin{aligned}
&\min f(x)=q^T x+\frac{1}{2} x^T Q x \\
&\text { s.t.Ax }=a \\
&B x \leq b \\
&x \geq 0
\end{aligned}$$


$Q$ 可被认为是目标函数的Hessian matrix.

## 全局解

如果$Q$是正定矩阵，则目标函数是凸函数，则局部最小值就是全局最小值。一般我们说QP问题默认其是凸函数。

## 无约束条件

求极值

$$\begin{aligned}
\nabla f &= Qx+q = 0 \\ 
x&=Q^{-1}\cdot -q
\end{aligned}$$

## 等式约束

- 消元法
- 拉格朗日乘子法

## KKT conditions

拉格朗日函数：
$$\begin{aligned}
F(X, \lambda, \mu) = f(x) + \lambda^T (Ax-a)+\mu^T (Bx-b)
\end{aligned}$$
KKT 条件：
$$\begin{aligned}
\nabla_x F(X, \lambda, \mu) &= q + \frac{1}{2}Qx + A^T\lambda+B^T\mu  \\
Ax -a & = 0    \\
Bx - b & \leq 0 \\
\lambda^T \neq 0,& \quad \mu^T \geq 0, \quad x \geq 0
\end{aligned}$$


## solution strategy

- only equality constraints: **conjugate gradient method**:
-  inequality constraints: interior point and active set methods
- box constraint $x^L\leq x \leq x^U$: trust-region methods
- all general constraint: NLP solver

## ref

- blog
    - [Quadratic_programming](https://optimization.mccormick.northwestern.edu/index.php/Quadratic_programming)
- pdf / book / notes
    - [Chapter3](https://www.math.uh.edu/~rohop/fall_06/Chapter3.pdf)
---
title: 非线性优化
categories: optimization
tags: optimization
date: 2022-09-16
---

$$\begin{aligned}
\min & f(x) \\
s.t. & h(x) = 0 \\
& g(x)\leq 0
\end{aligned}$$

- SQP

## SQP: Sequential quadratic programming

求解带约束非线性优化问题的迭代方法，要求目标函数二阶微分连续。

**kkt 条件**：

$$\nabla L=\left[\begin{array}{l}
\frac{d L}{d x} \\
\frac{d L}{d \lambda} \\
\frac{d L}{d \mu}
\end{array}\right]=\left[\begin{array}{c}
\nabla f+\lambda \nabla h+\mu \nabla g^* \\
h \\
g^*
\end{array}\right]=0$$

**牛顿法**： $x_{k+1} = x_k - \frac{\nabla f}{\nabla^2f}$

**SQP algorithm**
A feasible point x ∈ F that satisfies the first order necessary optimality conditions (A1) is called a critical point of the NLP (4.1a)-(4.1c).
Note that a critical point need not to be a local minimum

在ktt点，目标函数的极值点也是拉格朗日函数的极值点；所有的约束要么是等于0，否则就退化为无约束条件。SQP算法通过牛顿法寻找拉格朗日函数的极值点：

$$\begin{aligned}
&{\left[\begin{array}{l}
x_{k+1} \\
\lambda_{k+1} \\
\mu_{k+1}
\end{array}\right]=\left[\begin{array}{l}
x_k \\
\lambda_k \\
\mu_k
\end{array}\right]-\left(\nabla^2 L_k\right)^{-1} \nabla L_k} \\
&\text { Recall: } \nabla L=\left[\begin{array}{c}
\frac{d L}{d x} \\
\frac{d L}{d \lambda} \\
\frac{d L}{d \mu}
\end{array}\right]=\left[\begin{array}{cc}
\nabla f+\lambda \nabla h+\mu \nabla g^* \\
h \\ g^*
\end{array}\right] \\
&\text { Then } \nabla^2 L=\left[\begin{array}{ccc}
\nabla_{x x}^2 L & \nabla h & \nabla g \\
\nabla h & 0 & 0 \\
\nabla g & 0 & 0
\end{array}\right]
\end{aligned}$$

如果微分变量能完整得通过解析的方式求出来，则这一迭代过程会很顺利。


## ref

- paper
    - [Sequential Quadratic Programmin](http://web.cse.ohio-state.edu/~parent.1/classes/788/Au10/OptimizationPapers/SQP/actaSqp.pdf)
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

求解带约束非线性优化问题的迭代方法，要求目标函数二阶微分连续。每次迭代相当于求一个二次优化问题。

**kkt 条件**：

$$\nabla L=\left[\begin{array}{l}
\frac{d L}{d x} \\
\frac{d L}{d \lambda} \\
\frac{d L}{d \mu}
\end{array}\right]=\left[\begin{array}{c}
\nabla f+\sum \lambda_m \nabla h_m+\sum\mu_k \nabla g_k \\
\sum h_m \\
\sum g_k
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
\nabla f+\sum \lambda_m \nabla h_m+\sum\mu_k \nabla g_k \\
h \\
g
\end{array}\right]=\left[\begin{array}{cc}
\nabla f+J_{h}^T \lambda+J_{g}^T \mu \\
h \\
g
\end{array}\right] \\
&\text { Then } \nabla^2 L=\left[\begin{array}{ccc}
H_f(x) + \sum \lambda_m H_{hm}(x) + \sum \mu_k H_{gk}(x) & J^T_h & J^T_g \\
J_h & 0 & 0 \\
J_g & 0 & 0
\end{array}\right]
\end{aligned}$$

如果微分变量能完整得通过解析的方式求出来，则这一迭代过程会很顺利。

## 等式约束
令每次迭代步长为$\delta  =\begin{bmatrix} \delta_x \\ \delta_\lambda\end{bmatrix}$, 则：
$$\nabla ^2 L_k \begin{bmatrix} \delta_x \\ \delta_\lambda\end{bmatrix} = -\nabla L_k   \\
\downdownarrows \\
\text{let: } B(x, \lambda) =  H_f(x)+\sum \lambda_m H_{hm}(x), \\
\text{then: } 
\begin{bmatrix} B(x,\lambda) & J_h^T \\ J_h & 0\end{bmatrix} \begin{bmatrix} \delta_x \\ \delta_\lambda\end{bmatrix} = -\begin{bmatrix} \nabla f +J_h^T \lambda \\ h  \end{bmatrix}$$

上式等价于一个等式约束的二次规划问题:

$$\min_{\delta_x} \frac{1}{2}\delta_xB(x, \lambda)\delta_x+\delta_x(f +J_h^T \lambda)   \\
\text{subject to: } J_h \delta_x+h = 0$$


对以上二次规划问题通过使拉格朗日方程的梯度为0即可得到迭代步长的表达式。

## 不等式约束
令每次迭代步长为$\delta  =\begin{bmatrix} \delta_x \\ \delta_\lambda \\ \delta_{\mu} \end{bmatrix}$, 则：
$$\nabla ^2 L_k \begin{bmatrix} \delta_x \\ \delta_\lambda \\ \delta_{\mu} \end{bmatrix} = -\nabla L_k   \\
\downdownarrows \\
\text{let: } B(x, \lambda) =  H_f(x)+\sum \lambda_m H_{hm}(x) +\sum \mu_k H_{gk}(x), \\
\text{then: } 
\begin{bmatrix} B(x,\lambda) & J_h^T & J_g^T \\ J_h & 0 & 0 \\
J_g & 0 & 0\end{bmatrix} \begin{bmatrix} \delta_x \\ \delta_\lambda \\ \delta_{\mu}\end{bmatrix} = -\begin{bmatrix} \nabla f +J_h^T \lambda \\ h  \\g \end{bmatrix}$$


等价的带不等式约束的二次规划问题
$$\begin{align} \min_{\delta_x}& \quad \frac{1}{2}\delta_xB(x, \lambda)\delta_x+\delta_x(f +J_h^T \lambda)   \\
\text{subject to:}& \quad J_h \delta_x+h = 0  \\
&\quad J_g\delta_x+g \leq 0 \end{align}$$

求解方式：

- directly solve matrix block
- Quasi-Newton approximations to the Hessian
- trust region, line search to improve robustness
- treatment of constraints during the iterative process



## ref

- paper
    - [Sequential Quadratic Programmin](http://web.cse.ohio-state.edu/~parent.1/classes/788/Au10/OptimizationPapers/SQP/actaSqp.pdf)
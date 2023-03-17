---
title: optimization1 intro
categories: optimization
tags: optimization
date: 2019-07-12
---

## intro

- 凸优化
    - 最小二乘
    - 线性规划
    - 一般的凸优化问题
- 非线性优化

## 数学符号

$\nabla$: nabla算子，向量微分算子，表示对各个方向求梯度

三维情况下， $\nabla=\frac{\partial}{\partial x} \mathbf{i}+\frac{\partial}{\partial y} \mathbf{j}+\frac{\partial}{\partial z} \mathbf{k}$ 或 $\nabla=\left(\frac{\partial}{\partial x}, \frac{\partial}{\partial y}, \frac{\partial}{\partial z}\right)$
二维情况下， $\nabla=\frac{\partial}{\partial x} \mathbf{i}+\frac{\partial}{\partial y} \mathbf{j}$ 或 $\nabla=\left(\frac{\partial}{\partial x}, \frac{\partial}{\partial y}\right)$

$\nabla$与函数之间通过不同的符号连接表示不同的含义：

1. $\nabla F$: 求梯度，标量函数梯度为向量，向量函数为二阶张量
$$\nabla F=(\frac{\partial F_{x}}{\partial x}, \frac{\partial F_{y}}{\partial y},\frac{\partial F_{z}}{\partial z})$$

2. $\nabla \cdot F$: 求散度

$$\operatorname{div} \mathbf{F}=\nabla \cdot \mathbf{F}=\frac{\partial F_{x}}{\partial x}+\frac{\partial F_{y}}{\partial y}+\frac{\partial F_{z}}{\partial z} $$

3. $\nabla \times F$: 求旋度

4. 雅可比矩阵，是指针对多元变量的向量函数求梯度

$$\begin{align}f&=\begin{bmatrix} f_1\\f_2\\\dots\\f_m\end{bmatrix}=\begin{bmatrix} f_1(q)\\f_2(q)\\ \dots \\f_m(q) \end{bmatrix}    \\
J_f(q)&  =\begin{bmatrix}\nabla f_1 \\\nabla f_2 \\ \cdots \\ \nabla f_m \end{bmatrix}\end{align} $$

5. Hesse-Matrix: 多变量实函数的二阶偏导

$$\mathbf{H}=\left[\begin{array}{cccc}
\frac{\partial^2 f}{\partial x_1^2} & \frac{\partial^2 f}{\partial x_1 \partial x_2} & \cdots & \frac{\partial^2 f}{\partial x_1 \partial x_n} \\
\frac{\partial^2 f}{\partial x_2 \partial x_1} & \frac{\partial^2 f}{\partial x_2^2} & \cdots & \frac{\partial^2 f}{\partial x_2 \partial x_n} \\
\vdots & \vdots & \ddots & \vdots \\
\frac{\partial^2 f}{\partial x_n \partial x_1} & \frac{\partial^2 f}{\partial x_n \partial x_2} & \cdots & \frac{\partial^2 f}{\partial x_n^2}
\end{array}\right]$$

$$H_{ij} = \frac{\partial^2 f}{\partial x_i \partial x_j}\\
H(f)=J(\nabla f)$$

6. 函数向量： $f(x) = Ax$

$$\nabla f = J_f = A$$
$$\text{let } h(x) = \lambda^T f(x) = \lambda^T A x \quad \text{退化为多变量实函数}\\
\nabla h = J_f^T \lambda =  A^T \lambda$$

$\Delta$ 拉普拉斯算子：二阶偏导的加和，一般也写作 $\nabla^2$

## linear optimization

- 单纯形法
- 椭球法
- 内点算法

## nonlinear optimization

- 梯度下降(gradient descent), 负梯度，一阶收敛
- 牛顿法(newton's method)，二阶收敛
- 拟牛顿法(quasi-newton method,BFGS), 用正定矩阵来近似Hessian矩阵的逆，简化运算的复杂度
- 共轭梯度(Conjugate Gradient)
- 启发式优化算法: 遗传算法，蚁群算法，粒子群算法,差分进化算法
- SQP(Sequential Quadratic Programming, 序列二次规划/约束变尺度)
- RSQP(Revised Sequential Quadratic Programming)
- 拉格朗日乘子法

## kkt 条件

Karush–Kuhn–Tucker conditions

对于具有等式和不等式约束的优化问题：
$$min f(x) \\
s.t. g_j(x)\leq 0(j=1,2,\dots,m)\\
h_k(x)=0(k=1,2,\dots,l)$$
kkt条件给出了判断$x$是否为最优解的必要条件：
$$\begin{array}{lr}
\frac{\partial f}{\partial x_i}+\sum_{j=1}^m \mu_j\frac{\partial g_j}{\partial x_i}+\sum_{k=1}^l \lambda_j\frac{\partial h_k}{\partial x_i}=0,(i=1,2,\dots,n) \\ h_k(x)=0,(k=1,2,\dots,l)\\\mu_jg_j(x)=1,(j=1,2,\dots,m) \\ \mu_j\geq0
\end{array} $$

kkt条件将多个约束方程转化成求零点的一个方程。

## SQP

序列二次规划的算法思路是把约束问题的目标函数在迭代点$x^\ast$处通过泰勒展开简化成二次函数：

$$min\ f(x)=\frac{1}{2}(x-x^*)^T\Delta^2f(x^\ast)(x-x^\ast)+\Delta f(x^\ast)(x-x^\ast) \\
s.t.\ \Delta g_j(x^\ast)^T(x-x^*)+g_j(x^\ast)\leq 0\ (j=1,2,\dots,m) \\
\Delta h_k(x^\ast)^T(x-x^*)+h_k(x^\ast)= 0\ (k=1,2,\dots,l)
$$

此问题是原约束问题的近似问题，其解不一定是原问题的可行点(**??**)，为此，令：

$$\begin{aligned}
S&=x-x^\ast \\
H&=\Delta^2f(x^\ast) \\
C&=\Delta f(x^\ast)  \\
A_{eq}&=[\Delta h_1(x^\ast),\Delta h_2(x^\ast),\dots,\Delta h_l(x^\ast)]^T \\
A&=[\Delta g_1(x^\ast),\Delta g_2(x^\ast),\dots,\Delta g_m(x^\ast)]^T \\
B_{eq}&=[h_1(x^\ast),h_2(x^\ast),\dots,h_l(x^\ast)]^T \\
B&=[g_1(x^\ast),g_2(x^\ast),\dots,g_l(x^\ast)]^T 
\end{aligned}$$

则原约束问题转变为二次规划问题的一般形式：

$$min \ F(S)=\frac{1}{2}S^THS \\
s.t.\ AS\leq B \\
A_{eq}S=B_{eq}$$

- L-SQP

## 优化库

- python
    - cvxpy: 符号计算凸优化库
- c++
    - [OSQP](https://osqp.org/)
    - [IPOPT]()


## 凸优化基础

01. 判定凸集，以及凸函数
02. 线性规划与二次规划
03. 拉格朗日与对偶函数
04. Strong Duality与KKT条件
05. Non-convex优化问题
06. NP-Hard问题与松他化处理
07. Discrete Optimization
08. GD, SGD, Adam, Adagrad
09. L-BFGS, ADMM

## 学习

1. 线性代数： MIT公开课《线性代数》
2. 最优化： Optimization Model + 方述诚 （线性规划 + 非线性规划）
3. 进阶：应用 + 进阶



## ref

- book  
    - [numerical optimization]()
        - [csdn - 数值优化（Numerical Optimization）学习系列-目录](https://blog.csdn.net/fangqingan_java/article/details/48951191)
    - [Convex Optimization in signal and communication]()
    - [Optimization Model]()
- blog
    - [SQP 算法实现](https://zhuanlan.zhihu.com/p/348666680)
    - [optim docs](https://optimlib.readthedocs.io/en/latest/api/sumt.html)
    - [优化器列表](https://www.twblogs.net/a/5b7f9a6f2b717767c6b073d6)
- project
    - [CppNumericalSolvers](https://github.com/PatWie/CppNumericalSolvers)
    - [optim](https://github.com/kthohr/optim)
- course
    - [stanford Convex Optimization 1](https://web.stanford.edu/class/ee364a/lectures.html)
    - [stanford Convex Optimization 2](https://web.stanford.edu/class/ee364b/lectures.html)
    - [cmu Convex Optimization: Spring 2015](https://www.stat.cmu.edu/~ryantibs/convexopt-S15/)
    - [Optimization Theory](https://www.math.uh.edu/~rohop/fall_06/)
    - [nonlinear programming](http://ocw.nctu.edu.tw/course_detail.php?bgid=3&gid=0&nid=358)
    - [ECE236C - Optimization Methods for Large-Scale Systems]()
    - [Convex and Conic Optimization-Princeton University](https://aaa.princeton.edu/orf523s16)
    - [Convex Analysis And Optimization](https://ocw.mit.edu/courses/6-253-convex-analysis-and-optimization-spring-2012/pages/lecture-notes/)
- [bilibili-线性规划 方述诚](https://www.bilibili.com/video/av455050227/)





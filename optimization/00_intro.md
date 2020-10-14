---
title: optimization1 intro
categories: ompl
tags: optimization
date: 2019-07-12
---

## ref

- [nonlinear programming](http://ocw.nctu.edu.tw/course_detail.php?bgid=3&gid=0&nid=358)
- [bilibili-线性规划 方述诚](https://www.bilibili.com/video/av455050227/)


## intro

- 凸优化
    - 最小二乘
    - 线性规划
    - 一般的凸优化问题
- 非线性优化

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

- [Optimization Methods](ECE236C - Optimization Methods for Large-Scale Systems)


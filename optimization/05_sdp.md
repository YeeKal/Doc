---
title: semidefinite programming
categories: 
tags: 
date: 2023-05-25
---

## Background

LP(线性规划)的高效求解大大促进了LP的广泛使用。研究者们向再非线性问题上也找到类似LP这种快速求解的特性，因此把注意力投到了LP中的非负约束， 即非负凸锥，(sets that are invariant by positive scaling of their elements).

## Basis

positive semidefinite(psd):

$$v^TXv\geq 0,  v \in \mathcal{R}^n$$

- $S^n$: the set of symmetric $n\times n$ matrices
- $S_+^n$: the set of  positive semidefinite(psd) symmetric $n\times n$ matrices, a closed convex cone
- $S_{++}^n$: the set of  positive definite(psd) symmetric $n\times n$ matrices
- $X\succeq 0$: x is symmetric and positive semidefinite
- $X\succ 0$: x is symmetric and positive definite
- $X\succeq Y$: $X-Y \succeq 0$
- $X\succeq Y$: $X-Y \succeq 0$

**<font color='Tomato'>Remark</font>**: $S_+^n=\{X\in S^n | X\succ 0 \}$ is a closed convex cone in $\mathcal{R}^{n^2}$ of dimension $x\times (n+1) /2$

**<font color='Tomato'>Properties of symmetric matrices</font>**

- if $X\in S^n, X = QDQ^T$ for some orthonormal matrix $Q$ and some diagonal matrix $D$.($Q^{-1} = Q^T$).
- Q的列向量就是$X$的特征向量,对应特征值为相应的对角元
- $M\succ 0 $ if and only if $d-v^TP^{-1}v > 0$ for $M$ is defined as:

$$M=\begin{bmatrix}P & v \\ V^t & d\end{bmatrix}$$

## Semidefinite Programming(SDP)

对于矩阵的三种视角:

1. matrix
2. an array of $n^2$ components 
3. a vector in the space $S^n$

在最优化里面每一个元素都是变量,至于怎么排列元素并不改变这一事实.

**<font color='Tomato'>define linear function of $X$</font>** 

let $C(X)$ is a linear function of $X$, then $C(X)$ can be written as $C\bullet X$, where:

$$C\bullet X := \sum ^n_{i=1}\sum^n_{j=1}C_{ij}X_{ij}$$

<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>其本质乃是一个线性方程</font>

**<font color='Tomato'>define semidefinite program(SDP)</font>** in standard conic form

$$\begin{aligned}\min \quad & C\bullet X \\
s.t. \quad & A_i X = b_i, i = 1,\cdots,m \\
&X \succeq 0 \end{aligned}$$

$C, A_1, \cdots, A_m$ are symmetric matrix, and $b\in \mathcal{R}^n$

与标准LP问题类似,在LP中$x$位于非负象限的凸锥中,而这里$X$位于半正定矩阵所形成的凸锥集合中.

通过构造对角元可以很容易把LP问题转化为SDP问题

**<font color='Tomato'>Standard Inequality Form</font>**

$$\begin{aligned}\min  \quad & c^Tx \\
s.t. \quad & F_0+x_1F_1+\cdots + x_mF_m \succeq 0 \end{aligned}$$

$c\in \mathcal{R}^n,x\in \mathcal{R}^n, F_0, \cdots, F_m$ are symmetric matrix




**<font color='Tomato'>Semidefinite Programming Duality</font>**

$$\begin{aligned}
\mathrm{max}\ \quad & \sum_{i=1}^{m}y_{i}b_{i} \\
{\textrm{s. t.}}\quad &  \sum_{i=1}^{m}y_{i}A_{i}+S=C \\
& S\succeq 0.\end{aligned}$$

## SDP in Combinatorial Optimization

MAXCUT problem

## SDP in Convex Optimization

<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:15px;'>types of constraints that can be modeled in the SDP framework</font> : `linear inequalities`, `convex quadratic inequalities`, `lower bounds on matrix norms`, `lower bounds on determinants of symmetric positive semidefinite matrices`, `lower bounds on the geometric mean of a nonnegative vector`, plus many others.

<font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>problems which can be cast in the form of a semidefinite program</font>:`linear programming`, `optimizing a convex quadratic form subject to convex quadratic inequality constraints`, `minimizing the volume of an ellipsoid that covers a given set of points and ellipsoids`, `maximizing the volume of an ellipsoid that is contained in a given polytope`, plus a variety of maximum eigenvalue and minimum eigenvalue problems.

SDP 中常见的构造方式是通过移项转化为 $u^TAu \geq 0$ 的形式， 然后把约束条件转变为半正定矩阵约束: $$A\succeq 0$$

比如约束条件： 

$$(Au)^T < u^TPu \quad \Rightarrow \quad u^TA^TPAu - u^TPu < 0 \\
\Downarrow  \\
P-A^TPA \succ 0
$$

**<font color='Tomato'>QCQP: quadratically constrained quadratic program</font>**

$$\begin{aligned}
\min_{x} \quad &  x^{T}Q_{0}x+q_{0}^{T}x+c_{0}  \\
s.t. \quad & x^{T}Q_{i}x+q_{i}^{T}x+c_{i} \leq 0, i = 1,\cdots, m
\end{aligned}$$

where $Q_0\succeq 0, Q_i\succeq 0$

## Applications

https://inst.eecs.berkeley.edu/~ee127/sp21/livebook/l_sdp_apps.html

## Ref

- [Introduction to Semidefinite Programming](https://ocw.mit.edu/courses/6-251j-introduction-to-mathematical-programming-fall-2009/resources/mit6_251jf09_sdp/)
- [F. Alizadeh · D. Goldfarb  Second-order cone programming]()
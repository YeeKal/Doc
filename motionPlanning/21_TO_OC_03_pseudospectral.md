---
title: pseudospectral
categories: motion planning
tags: planning
date: 2021-10-24
---

## Overview

a global form of orthogonal collocation： 全局曲线，点是选择的曲线上的点，

spectrally: approximation will converge spectrally (i.e., at an exponential rate) as a function of the number of collocation points

当前一般使用拉格朗日多项式

## 2018 - Efficient Trajectory Optimization for Robot Motion Planning

an optimal control based approach to address the path planning and trajectory planning
subproblems simultaneously

- Pseudospectral Method: Legendre拟谱方法
- Chebyshev-Lobatto points：$T_i=\frac{t_f}{2}(cos(\frac{i\pi}{N})+1) i=0,\cdots,N$
- barycentric interpolation


## Pseudospectral

ref: 最优控制问题的Legendre_伪谱法求解及其应用

- Gauss  伪谱法
    - LG积分(Legendre-Gauss)
- radau  伪谱法
    - LGR积分(Legendre-Gauss-Radau)
- Legendre  伪谱法
    - LGL积分(Legendre-Gauss-Lobatto)
- Chebyshev  伪谱法
    - CGL积分(Chebyshev-Gauss-Lobatto)

#### 高斯数值积分

Gaussian quadrature

$$\int^1_{-1} f(x)dx \approx \sum^n_{i=1}w_i f(x_i)$$

#### LG积分(Legendre-Gauss)

- 积分区间: [-1, 1]
- Gauss 点：Legendre多项式零点, 这些零点是固定的，可查表得到

两点求积:

$$\int^1_{-1}f(x)dx\approx f(-\frac{\sqrt{3}}{3}) + f(\frac{\sqrt{3}}{3})$$


三点求积:

$$\int^1_{-1}f(x)dx\approx \frac{5}{9}f(-\frac{\sqrt{15}}{5})+ \frac{8}{9}f(0) + \frac{5}{9}f(\frac{\sqrt{15}}{5})$$

一般区间上进行变量替换: $x=\frac{b-a}{2}t+\frac{b+a}2$

#### LGR积分(Legendre-Gauss-Radau)

$P_{n-1}(x)+P_n(x)$的零点

#### LGL积分(Legendre-Gauss-Lobatto)

$\dot P_{n-1}(x)$的零点和-1，1， 即$(1-x^2)\dot P_{n-1}(x)$零点， 有n+1个

#### Legendre  伪谱法

把时域$[t_0. t_f]$转换到[-1,1]区间，$\tau=\frac{2t-t_f-t_0}{t_f-t_0}$.再根据LGL点进行离散化。对状态变量和控制量进行响应离散化，形成N+1个离散状态变量$[X_0, X_1, \cdots, X_N]$和离散控制变量$[U_0, U_1, \cdots, U_N]$, 利用拉格朗日插值多项式逼近$x(\tau), u(\tau)$：

$$
\begin{aligned}
&x(\tau) \approx X(\tau)=\sum_{i=0}^{N} L_{i}(\tau) X_{i} \\
&u(\tau) \approx U(\tau)=\sum_{i=0}^{N} L_{i}(\tau) U_{i}
\end{aligned}
$$

$$
L_{i}(\tau)=\prod_{j=0, j \neq i}^{N} \frac{\tau-\tau_{j}}{\tau_{i}-\tau_{j}}
$$

对状态方程进行转化，将状态变量通过插值多项 式参数化后, 对状态的微分运算可以近似为对插值基
函数的微分运算：

$$\dot{x}\left(\tau_{k}\right) \approx \dot{X}_{k}=\sum_{i=0}^{N} \dot{L}_{i}\left(\tau_{k}\right) X_{i}=\sum_{i=0}^{N} D_{k i} X_{i}$$

其中$D^{(N+1)\times(N+1)}$(Gauss Pseudospectral differentiation matrix.)表示拉格朗日基函数在各个配点处对$\tau$的微分值：

$$D_{k i}=\left\{\begin{array}{l}
\frac{P_{N}\left(\tau_{k}\right)}{P_{N}\left(\tau_{i}\right)\left(\tau_{k}-\tau_{i}\right)}, i \neq k \\
-N(N+1) / 4, i=k=0 \\
N(N+1 / 4), i=k=N \\
0, \text { otherwise }
\end{array}\right.$$

状态方程转化为N+1个等式约束（去掉了对状态的微分项）：

$$\sum_{i=0}^{N} D_{k i} X_{i}-\frac{t_{f}-t_{0}}{2} f\left(X_{k}, U_{k}, \tau_{k}\right)=0$$


对代价函数中的积分项进行转化：

$$J=\phi\left(x\left(t_{f}\right), t_{f}\right)+\int_{t_{0}}^{t_{f}} G(x(t), u(t), t) \mathrm{d} t$$

$$
J=\phi+\frac{t_{f}-t_{0}}{2} \sum_{i=0}^{N} w_{i} G\left(X_{i}, U_{i}, \tau_{i}\right)
$$
其中 $w$ 为积分权重, 定义为
$$
w_{i}=\int_{-1}^{1} l_{i}(\tau) \mathrm{d} \tau=\frac{2}{N(N+1) P_{N}^{2}\left(\tau_{i}\right)} .
$$

这样就把最优控制问题转化为非线性优化问题。

ref:
- [最优控制问题的Legendre伪谱法求解及其应用]()
- [2008 - Advances in pseudospectral methods for optimal control]()
- [1995 - The pseudospectral Legendre method for discretizing optimal control problems]()



## orthogonal polynominals on [-1, 1]

```
- 切比雪夫点
- 切比雪夫插值
- 切比雪夫多项式
```
#### 拉格朗日多项式

拉格朗日插值



$$l_i(x)=\frac{\prod^n_{j=0}(x-x_j)}{\prod^n_{j=0}(x_i-x_j)} \qquad (i=0,1,\cdots, n \quad i\neq j)$$




#### Chebyshev polynomials (切比雪夫多项式)

- 递推式： $T_0(x)=1,T_1(x)=x, T_{n+1}(x)=2xT_n(x)-T_{n-1}(x)$
- 三角形式：$T_n(x)cos(n \arccos x), -1\leq x\leq 1$
- 零点：$T_n(x)$在[-1,1]中有n个不同的实根：$x_k=cos(\frac{2k-1}{2n}\pi)$
- 极值点： $x_k=cos(\frac{k}{n}\pi)$


#### Legendre polynomials (勒让德多项式)

$$P_{n}(x)=\frac{1}{2^{n}} \sum_{s=0}^{[n / 2]} \frac{(-1)^{s}(2 n-2 s) !}{s !(n-s) !(n-2 s) !} x^{n-2 s} $$

- 递推式： $(n+1)P_{n+1}=(2n+1)xP_n-nP_{n-1}$

正交性

$$\int_{-1}^{1} P_{m}(x) P_{n}(x) d x=\frac{2}{2 n+1} \delta_{m n}$$

n个积分点就是（n-1）阶勒让德多项式的极值点（共n-2个）加上积分区间的两个端点

Clenshaw–Curtis quadrature




## A Pseudospectral Method for Real-Time Motion Planning and Obstacle Avoidance 

1. use p-norm to represent box, circle
2. triangle: 三条线的交集，求最小值


## ref

- blog
    - [blog - chebfun](http://www.chebfun.org/)
- project
    - [PSOPT](https://swmath.org/software/20700)
    - [Pseudospectral-optimal-control-python](https://github.com/NaderTG/Pseudospectral-optimal-control-python)
    - [mpopt: A pseudo-spectral collocation based multi-phase Optimal control problem solver](https://github.com/mpopt/mpopt)
    - [Efficient Trajectory Optimization for Robot Motion Planning -- Examples](https://github.com/yzhao334/Efficient-Trajectory-Optimization-for-Robot-Motion-Planning--Examples)
    - [github - chebfun](https://github.com/asgeirbirkis/chebfun)
- paper
    - [2010-A Pseudospectral Optimal Motion Planner for Autonomous Unmanned Vehicles](https://core.ac.uk/download/pdf/36737091.pdf)
    - [2007-A Pseudospectral Method for Real-Time Motion Planning and Obstacle Avoidance ](https://apps.dtic.mil/sti/pdfs/ADA478686.pdf)
    - [A review of pseudospectral optimal control: From theory to flight]()
    - [2020 Optimal Motion Planning for Differential Drive Mobile Robots based on Multiple-Interval Chebyshev Pseudospectral Methods]()

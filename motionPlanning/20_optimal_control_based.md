---
title: 基于最优化的轨迹规划/运动规划 
categories: motion planning
tags: planning
date: 2021-10-21
---

PDE: 偏微分方程(Partial Differential Equation)

## Pseudospectral

ref: 最优控制问题的Legendre_伪谱法求解及其应用

- Gauss  伪谱法
- radau  伪谱法
- Legendre  伪谱法
- Chebyshev  伪谱法

#### orthogonal polynominals on [-1, 1]

Legendre polynomials:

$$\int^1_{-1}P_m(x)P_n(x)dx=\frac{2}{2n+1}\delta_{mn}   \\
P_0(x)=1    \\ 
P_1(x)=x \\ 
P_2(x)=\frac{3}{2}x^2-\frac{1}{2}   \\ \cdots$$

Chebyshev polynomials:



拉格朗日插值

拉格朗日多项式

$$l_i(x)=\frac{\prod^n_{j=0}(x-x_j)}{\prod^n_{j=0}(x_i-x_j)} \qquad (i=0,1,\cdots, n \quad i\neq j)$$

切比雪夫节多项式

多项式零点, 切比雪夫节点  $x_k=cos(\frac{2k-1}{2n}\pi)$

极值点： $x_k=cos(\frac{k}{n}\pi)$

高斯数值积分

Gaussian quadrature

$$\int^1_{-1} f(x)dx \approx \sum^n_{i=1}w_i f(x_i)$$

legendre 多项式

n个积分点就是（n-1）阶勒让德多项式的极值点（共n-2个）加上积分区间的两个端点

Clenshaw–Curtis quadrature




## A Pseudospectral Method for Real-Time Motion Planning and Obstacle Avoidance 

1. use p-norm to represent box, circle
2. triangle: 三条线的交集，求最小值


## ref

---
title: 凸集和凸函数
categories: optimization
tags: optimization
date: 2020-09-09
---

## 直线和线段

记$x_1,x_2\in C$，则直线形式：

$$y=\theta x_1 + (1-\theta)x_2, \theta \in R$$

若$\theta \in [0,1]$则y构成了$x_1$和$x_2$之间的线段。上述直线形式表示了y是基于两个基点所构成的，当$\theta \in [0,1]$y在两点之间变动;当$\theta <0$或$\theta > 1$,y则超出线段，在线段的延伸处。

## 集合的表示

线性组合：

$$y=\sum \lambda_i x_i$$ 

- 仿射集合(Affine set): $\sum \lambda_i=1$
- 凸锥(conic set): $\lambda_i \geq 0$
- 凸集(convex set): $\sum \lambda_i=1, \lambda_i \geq 0 $

线性方程组的解集$C=\{ x| Ax=b \}$是一个仿射集合。反之，任意仿射集合可以表示为一个线性方程组的解集。上式中$A$是一个矩阵，$x,b$都是向量。

$\{ x| a^Tx=b \}$这个集合被称为超平面，a，x是向量b是一个常数。任取$x_0$,使得$a^Tx_0=b$, 则解集上任意点$x$,有$a^T(x-x_0)=0$. 即解集以$x_0$为中心，垂直a的所有的线段形成的平面。

从集合的角度理解一下优化问题：

$$P=\left\{\mathbf{x} \in \mathbf{R}^{n} \mid \mathbf{A} \mathbf{x}=\mathbf{b}, \mathbf{x} \geq \mathbf{0}\right\}$$

- P是A的列向量组成的超平面相交之后再与凸锥($x\geq 0$)相交的集合
- $\mathbf{A} \mathbf{x}=\mathbf{b}, \mathbf{x} \geq \mathbf{0}$意味着，向量b落入由A的列向量形成的凸锥中。

## 凸函数

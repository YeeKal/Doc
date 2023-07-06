---
title: 拉格朗日乘子法
categories: optimization
tags: optimization
date: 2022-09-15
---

Lagrange multiplier

把一个有n个变量与k个约束条件的最优化问题转换为一个解有n+k个变量的方程组的解的问题。这里引入的k个新的变量，被称为拉格朗日乘子，这些变量代表了被转换的约束方程的线性组合在各个向量上的梯度系数。

## 等式条件的拉格朗日乘子法

考虑一个三位空间的优化问题

$$\min f(x, y)  \\
s.t. \quad g(x,y) = c$$

假设极值存在，则当沿着$g(x,y) = c$移动$f(x,y)$的等高线时，极值$d_n$存在的点必定与$g(x,y)=c$相切，即此时$f$和$g$的切线平行，则：

$$\nabla f(x, y)=-\lambda \nabla(g(x, y)-c)$$

移项得：

$$\nabla[f(x, y)+\lambda(g(x, y)-c)]=\mathbf{0}$$
同时满足条件:

$$g(x, y)-c = 0$$

则意味着新方程在此时有极值点：

$$L(x, y, \lambda) = f(x, y)+\lambda (g(x, y)-c)$$

原问题转化为求$L(x, y, \lambda)$的极值，即：
$$\nabla L = 0    \rightarrow \quad \begin{aligned} 
\frac{\partial L}{\partial x} = 0 \\
\frac{\partial L}{\partial y} = 0 \\
\frac{\partial L}{\partial \lambda} = 0   
\end{aligned}
 $$

## 不等式情况下的KKT条件

KKT条件（卡鲁什-库恩-塔克条件 ，Karush-Kuhn-Tucker Condition)

对于不等式约束问题：
$$\min f(X)  \\
\text{subject to}: \quad g_i(X) \leq 0, \quad h_j(X) = 0$$

定义拉格朗日函数：

$$L(X, \lambda, \mu) = f(X)+\sum_{j=1} \lambda_j h_j(X)+\sum_{i=1} \mu_i g_i(X)$$

KKT条件定义下的最优值条件：

$$
\nabla L(x, \lambda, \mu) = 0   \\
\quad g_i(X) \leq 0, \quad h_j(X) = 0 \\
\mu_i \geq 0, \quad, \lambda_i \neq 0    \\
\mu_i g_i(X) = 0
$$

对第3个表达式: 构造的拉格朗日函数，$L \leq f$, 而$g_i(X) \leq 0$, 因此在最优值处，必然导致$\mu_i \geq 0$

对第四个表达式所限制的约束条件的直观理解：1. 如果最优值在$g_i(X)<0$范围内，则$\mu_i=0$，$g_i(x)\leq 0 $条件退化为不约束极值区域的条件；2. 如果最优值在$g_i(X)=0$范围内，则问题变成了只有等式约束条件的问题，自然也满足$\mu_i g_i(X) = 0$.

$$\nabla L=\left[\begin{array}{l}
\frac{d L}{d x} \\
\frac{d L}{d \lambda} \\
\frac{d L}{d \mu}
\end{array}\right]=\left[\begin{array}{c}
\nabla f+\lambda \nabla h+\mu \nabla g^* \\
h \\
g^*
\end{array}\right]=0$$

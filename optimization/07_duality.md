---
title: duality
categories: optimization
tags: optimization
date: 2023-05-05
---

## intro

three main formulations and implementations: <font color='Tomato'>Fenchel, Wolfe, and Lagrangean</font> 

- primal problem
- dual problem

拉格朗日乘子,惩罚项把约束函数包含在目标函数中, 原始问题被转化为另一个问题

- inf: infimum, the greatest lower bound, 下确界/最大下界
- sup: suprema, the least upper bound

Complementary slackness 

1. 构建拉格朗日乘子
2. 根据梯度为0替换掉x
3. 构建以拉格朗日乘子构建对偶问题

## hyperplane

$$\inf _y\left\{\|y\|-\mu^T y\right\}=0 \text { if }\|\mu\|_* \leq 1$$

## Fenchel conjugate

## Lagrangian

The Lagrangian of this problem is:

$$L(x, \lambda, \nu) = f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x).$$

The Lagrangian dual is:

$$g(\lambda,\nu) = \inf_{x \in \mathcal{D}} \left( f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x) \right),$$

g是最小值,而由于$L \leq f$, 所以希望L与f之间的gap越小越好,因此希望找到最优的$\lambda, \nu$使得g越大越好.

The Lagrangian dual problem, in turn is:

$$\begin{align}
\max \;\;\;\; &g(\lambda,\nu)\\
\text{s.t.} \;\;\;\; &\lambda \succcurlyeq 0.
\end{align}$$

Note that:

$$\begin{align}
\sup_{\lambda \succcurlyeq 0, \; \nu} L(x,\lambda,\nu) 
&= \sup_{\lambda \succcurlyeq 0, \; \nu} \left( f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x) \right) \\
&= 
\begin{cases}
f_0(x) & \text{if } f_i(x) \leq 0, \; i = 1,\ldots,m, \text{ and } h_i(x) = 0, \; i=1,\ldots,p \\
\infty & \text{otherwise}.
\end{cases} 
\end{align}$$

This means that

$$p^\star := \inf_x \sup_{\lambda \succcurlyeq 0, \; \nu} L(x, \lambda, \nu)$$

is the optimal value of the primal problem. Moreover, by definition,  

$$d^\star := \sup_{\lambda \succcurlyeq, \; \nu} \inf_x L(x,\lambda,\nu)$$

is the optimal value of the dual problem.

If it is strong duality, then $d^* = p^*$.

$$x^\star = \arg\min_x L(x,\lambda^\star,\nu^\star).$$


## Ref

- blog
    - [dual problem question](https://math.stackexchange.com/questions/223235/please-explain-the-intuition-behind-the-dual-problem-in-optimization)
- project
- course
    - [duality slides](https://web.archive.org/web/20141227023221/http://www.ifor.math.ethz.ch/teaching/Courses/Spring_2013/Convex_Optimization/Slides)


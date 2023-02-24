---
title: 凸优化问题
categories: optimization
tags: optimization
date: 2023-02-22
---

## Optimization Terminology

A <font color='Tomato'>convex optimization program</font> can be written as a convex minimization:

$$\begin{array}{cl}
\underset{x \in D}{\operatorname{minimize}} & f(x) \\
\text { subject to } & g_i(x) \leq 0, i=1, \ldots, m \\
& A x=b
\end{array}$$

where $f$ and $g_i, i=1,\cdots m$ are all convex.

<font color='Tomato'> Convex minimization </font> can be reposed as concave maximization, and both are called convex optimization problems:

$$\begin{aligned} \begin{aligned}
\min & \quad f(x) \quad  \\
\text { s.t. }& \quad g_i(x) \leq 0, \quad i=1, \ldots m\\
& \quad A x=b \end{aligned} \quad \Longleftrightarrow \quad  \begin{aligned}  \max & \quad -f(x) \quad  \\
\text { s.t. }& \quad g_i(x) \leq 0, \quad i=1, \ldots m\\
& \quad A x=b \end{aligned} \end{aligned}$$



| notation/terminology  | coment |  
|---|---|---|
|$f(x)$: **Objective function, criterion**| the convex function we are minimizing over.|
|$D$: **Optimization domain(定义域)**|implicit domain,  $D=\operatorname{dom}(f) \cap \bigcap_i \operatorname{dom}\left(g_i\right)$|
|$g_i(x)$: **Inequality constraints**| convex functions; the solution must satisfy these.|
|$f^*$: **Optimal value(最优值)**| the minimum of $f(x)$ over all feasible points $x$|
|$X_{\text {opt }}$: **Set of solutions(解集)**| All $x$ 's that solve to a convex problem. Property: it's a convex set.|
|**Solution, optimal point**| the $\mathrm{x}$ at which the function achieves the optimal value; i.e. - $x$ such that $f(x)=f^*$; also called the minimizer.| 
|**Feasible points(可行集)**| $x, x\in D, g_i(x)\leq 0, Ax=b$ | 
|**$\epsilon$-suboptimal**|a feasible $x$ for which the function is within $\epsilon$ of the optimal value, i.e.  $f(x) ≤ f + \epsilon$|
|**$g_i$ is active**|a feasible $x$ and $g_i(x)=0$|
|**Locally optimal(局部最优)**||
|**Globally optimal(全局最优)**||


## Properties and first-order optimality

## Equivalent transformations



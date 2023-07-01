---
title: 锥规划
categories: optimization
tags: optimization
date: 2023-06-26
---
## Conic Programming

$$\begin{aligned}
\mathrm{max}\ \quad & c^Tx \\
{\textrm{s. t.}}\quad &  d-Dx \in K \\ \quad & Ax = b\end{aligned}$$

Here:
- $c, x \in \mathbb{R}^n$
- $D:\mathbb{R}^n \rightarrow Y $ linear, $d\in Y$ for some Euclidean space $Y$
- $K\subseteq Y$ is a closed convex cone
- write $x\preceq_K y$ for $y-x \in K$

## Second-order cone programming(SOCP)

Second-order cone:

$$\mathcal{Q}_n:=\left\{x=\left[\begin{array}{c}
x_0 \\
\bar{x}
\end{array}\right] \in \mathbb{R}^n: x_0 \geq\|\bar{x}\|\right\}$$

SOCP:

$$\begin{aligned}
\mathrm{max}\ \quad & c^Tx \\
{\textrm{s. t.}}\quad &  d-Dx \in \mathcal{Q} \\ \quad & Ax = b\end{aligned}$$

where: $\mathcal{Q} = \mathcal{Q}_{n1}\times \cdots \times \mathcal{Q}_{nr}$


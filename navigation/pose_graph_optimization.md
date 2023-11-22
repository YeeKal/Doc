---
title: PGO(pose graph optimization)
categories: 
tags: 
date: 2023-11-06
---

## Introduction

- [datasets](https://lucacarlone.mit.edu/datasets/)
- [paper: A Tutorial on Graph-Based SLAM](http://www2.informatik.uni-freiburg.de/~stachnis/pdf/grisetti10titsmag.pdf)

以图结构来表示机器人的位姿和相对关系。其中节点代表位姿，边代表相对关系，这种相对关系也是一种测量的约束关系。这种约束来源于里程计(Odometry)或者是回环检测(loop closure).里程计一般提供了前后连续两个点之间的运动关系，回环检测提供了相对于之前已经出现的位置点的相对观测关系，这种关系约束了位置的测量结果。由于误差的存在。测量的直接结果和观测关系不一定完全对应，这就为回环检测的相对观测位置的优化留下了空间。其中相对观测关系一般被成为软约束，这是相比于相对运动的的硬约束而言。如下图，软约束以虚线表示。

![graph node](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/1*cHszMviLE8Ce7CAdUIYP6A%402x.png)
![more nodes](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/1*-rCu94XxJOkRbT8quYo8yA%402x.png)

目标函数中，起始点一般置0，作为绝对原点。把相对关系写成相减的形式，平方和作为总误差。优化变量为合个位置节点：

$$\begin{aligned}
& J_{\text {GraphSLAM }}=x_0^T \Omega x_0+\sum_t\left(x_t-g\left(u_t, x_{t-1}\right)\right)^T R_t^{-1}\left(x_t-g\left(u_t, x_{t-1}\right)\right) \\
& \quad+\sum_t\left(z_t-h\left(x_t, m_j\right)\right)^T Q_t^{-1}\left(z_t-h\left(x_t, m_j\right)\right) \\
& x_0^T \Omega x_0: \text{fix init pose as origin}\\
& z_t-h\left(x_t, m_j\right): \text{measurement error} \\
& x_t-g\left(u_t, x_{t-1}\right): \text{motion constraint error} \\
& R_t, Q_t: \text{covariance, 代表了不同测量维度的精度区别}
\end{aligned}$$

上式中$g,h$是位置转化关系，通常这两个函数并不是线性的，比如加入了旋转。

**<font color='Tomato'>Linearizing Constraints</font>**

对于非线性约束需要把约束函数线性化


**<font color='Tomato'>Pose Graph Optimization</font>**

- [2018 A Comparison of Graph Optimization Approaches for Pose Estimation in SLAM](https://lamor.fer.hr/images/50036607/2021-ajuric-comparison-mipro.pdf)

![pose graph optimization](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/pose_graph_optimization_com.png)

## 2D 

$$\begin{split}r_{ab} =
\left[
\begin{array}{c}
  R_a^T\left(p_b - p_a\right) - \hat{p}_{ab} \\
  \mathrm{Normalize}\left(\psi_b - \psi_a - \hat{\psi}_{ab}\right)
\end{array}
\right]\end{split}$$

$$\begin{split}R_a =
\left[
\begin{array}{cc}
  \cos \psi_a & -\sin \psi_a \\
  \sin \psi_a & \cos \psi_a \\
\end{array}
\right]\end{split}$$

## Library

**<font color='Tomato'>SE-Sync</font>**

- [paper](https://arxiv.org/abs/1612.07386)
- [SE-Sync implementation](https://github.com/david-m-rosen/SE-Sync)


## Ref

- Course
    - [CMPUT631: Autonomous Robot Navigation  ](https://webdocs.cs.ualberta.ca/~zhang/c631/)
- Paper
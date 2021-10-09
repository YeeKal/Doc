---
title: 自动驾驶中控制优化方法
categories: autopilot
tags: planning
date: 2021-08-11
---

optimal control

differential dynamic programming
## mpc

## lqr

lqr 只看下一时刻， 而mpc关注接下来多个时刻

#### 最优控制角度：


全状态反馈控制系统图:

![lqr1](imgs/lqr1.png)

对于系统$\dot{x}=A x+B u$, 要设计一个状态反馈控制器$u=-Kx$, 则$\dot{x}=(A-BK)x$. 因此需要设计K使得能满足要求。

LQR定义了一个能量函数：

$$J=\frac{1}{2} \int_{0}^{\infty} x^{T} Q x+u^{T} R u d t$$

$Q, R$都是半正定矩阵，表示权重参数。这里的x可以看作目标差值，因此最优的时候这个差值是为0的。所以能量函数的两项一个代表了最后的系统稳定，误差为零，第二项代表使用较少的动作。

把$u=-Kx$带入能量函数:

$$J=\frac{1}{2} \int_{0}^{\infty} x^{T}\left(Q+K^{T} R K\right) x d t$$

假设存在一个常量矩阵P使得：$\frac{d}{d t}\left(x^{T} P x\right)=-x^{T}\left(Q+K^{T} R K\right) x$, 则可得(这里假设闭环系统稳定，即$x(t)_{t\rightarrow \inf}\rightarrow$0)：

$$J=-\frac{1}{2} \int_{0}^{x} \frac{d}{d t}\left(x^{T} P x\right) d t=\frac{1}{2} x^{T}(0) P x(0)   \\
\begin{aligned}
&\dot{x}^{T} P x+x^{T} P \dot{x}+x^{T} Q x+x^{T} K^{T} R K x=0 \\
&x^{T} A_{c}^{T} P x+x^{T} P A_{c} x+x^{T} Q x+x^{T} K^{T} R K x=0 \\
&x^{T}\left(A_{c}^{T} P+P A_{c}+Q+K^{T} R K\right) x=0
\end{aligned}$$

若等于0恒成立，则括号内应为0:

$$\begin{aligned}
&(A-B K)^{T} P+P(A-B K)+Q+K^{T} R K=0 \\
&A^{T} P+P A+Q+K^{T} R K-K^{T} B^{T} P-P B K=0
\end{aligned}$$

若选取$K=R^{-1} B^{T} P$得Riccati方程：

$$A^TP+PA+Q-PBR^{-1}B^TP=0$$

则根据Riccati方程求出P，在求出K，从而可以得出下一步的控制量。


[LQR from wikipedia](https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic_regulator)

- 无穷时域连续时间 Finite-horizon， continuous-time
- 有穷时域连续时间 Finite-horizon, continuous-time
- 无穷时域离散时间 Finite-horizon， continuous-time
- 有穷时域离散时间 Finite-horizon, continuous-time

$$u[k]=-K[k]X[k]    \\
$$

离散时间序列上通过动态规划的方式，从后向前递推控制量。

## iLQR / DDP

LQR中的A和B是常量，适用于现行系统，但是对于非线性系统，A和B是一个变化的量。iLQR就是针对非线性系统在局部进行线性化。先采取初始的控制量走一遍得到初始轨迹。在初始轨迹上作为参考点进行线性化，在采用LQR的方法求出最优控制量。


给定一条轨迹， DDP在此基础上的出更优的策略和轨迹


## ref

- blog
    - [Differential Dynamic Programing (DDP)](https://inst.eecs.berkeley.edu/~cs294-40/fa08/scribes/lecture7.pdf)
- course
    - [Learning for robotics and control](https://inst.eecs.berkeley.edu/~cs294-40/fa08/#lectures)
    - [CS 287: Advanced Robotics, Fall 2019](https://people.eecs.berkeley.edu/~pabbeel/cs287-fa19/)
    - [Topics in AI: Dynamic Programming](https://www.cs.ubc.ca/~mitchell/Class/CS532M.2007W2/)







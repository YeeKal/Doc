---
title: LQR and iLQR
categories: motion planning
tags: planning
date: 2021-10-23
---

## LQR

二次代价函数

是线性还是局部线性

局部线性，时变

$$J= \sum _ {t=0}^ {H-1}  (  x_ {t}^ {r}  Q_ {t}  x_ {t}  +  u_ {t}^ {r}  R_ {t}  u_ {t}  )+  x_ {H}^ {r}  P_ {H}  x_ {H} 
$$

或者也可以写成更加紧凑的矩阵形式：

$$g(x,u)=\begin{bmatrix}x \\u \end{bmatrix}\begin{bmatrix}Q & S^T \\ S & R \end{bmatrix} \begin{bmatrix}x \\u \end{bmatrix}^T$$

这里的S描述了x和u耦合之间的系数，一般设置为0.

哈密顿-雅可比-贝尔曼方程， 最优路径的子路径也是最优的：

$$J^*(x_k)=\min_u g(x_k,u) + J^*(x_{k+1})$$

在上述最优控制求解思路中，假设代价函数的最优解是关于x的一个二次多项式。


在动态规划角度，倒序的本质是根据当前state和下一个state计算当前需要采取的动作，以使得局部最优。

最后一步，Q函数实际就是代价函数，在下一个迭代中Q函数将变化为下一步的V函数
而在之前的几步迭代中Q函数是当前代价加上上一步计算的V(也就是上一步的Q，实际上加和起来也就是总的代价函数)


## iLqr

LQR要求模型局部线性，iLQR扩展到了非线性模型。首先初始化一条路径，根据该路径进行线性化然后采用LQR的方式进行更新。由于模型非线性而采用线性方式更新没法做到像LQR一样一次能达到最优解，因此iLQR采用迭代的方式进行梯度下降，一步步找到最优解。

牛顿法迭代： $\Delta x-f'(x_n)/f''(x_n)$

$$\begin{aligned}&\text{until convergence:}   \\
&\qquad g =\nabla_xg(\hat{x})  \\
&\qquad H =\nabla^2_xg(\hat{x})  \\
&\qquad \hat{x} \leftarrow \arg \min_x \frac{1}{2}(x-\hat{x})^TH(x-\hat{x})  + g^T(x-\hat{x})
\end{aligned}$$


对动力学模型和代价函数进行线性化：

$$\begin{aligned}
&f\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right) \approx f\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)+\nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} f\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{l}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right] \\
&c\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right) \approx c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)+\nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]+\frac{1}{2}\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]^{T} \nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}}^{2} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]
\end{aligned}$$

移项：

$$
\begin{aligned}
&f\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right)-f\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right) \approx \nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} f\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{l}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right] \\
&c\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right)-c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right) \approx \nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]+\frac{1}{2}\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]^{T} \nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}}^{2} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)\left[\begin{array}{c}
\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}\right]
\end{aligned}
$$

重新整理，标记符号：

$\bar{f}\left(\delta \mathbf{x}_{t}, \delta \mathbf{u}_{t}\right)=\mathbf{F}_{t}\left[\begin{array}{l}\delta \mathbf{x}_{t} \\ \delta \mathbf{u}_{t}\end{array}\right], \quad
\mathbf{F}_{t}=\nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} f\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)$

$$\begin{gathered}
\bar{c}\left(\delta \mathbf{x}_{t}, \delta \mathbf{u}_{t}\right)=\frac{1}{2}\left[\begin{array}{l}
\delta \mathbf{x}_{t} \\
\delta \mathbf{u}_{t}
\end{array}\right]_{\mathbf{x}}^{T} \mathbf{C}_{t}\left[\begin{array}{l}
\delta \mathbf{x}_{t} \\
\delta \mathbf{u}_{t}
\end{array}\right]+\left[\begin{array}{l}
\delta \mathbf{x}_{t} \\
\delta \mathbf{u}_{t}
\end{array}\right]^{T} \mathbf{c}_{t}\\
\begin{array}{l}
\delta \mathbf{x}_{t}=\mathbf{x}_{t}-\hat{\mathbf{x}}_{t} \\
\delta \mathbf{u}_{t}=\mathbf{u}_{t}-\hat{\mathbf{u}}_{t}
\end{array}     \\
\mathbf{C}_{t}=\nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}}^{2} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)    \\
\mathbf{c}_{t}=\nabla_{\mathbf{x}_{t}, \mathbf{u}_{t}} c\left(\hat{\mathbf{x}}_{t}, \hat{\mathbf{u}}_{t}\right)
\end{gathered}$$

在整理之后就有着跟LQR一样的问题形式:
$$
\begin{gathered}
f\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right)=\mathbf{F}_{t}\left[\begin{array}{c}
\mathbf{x}_{t} \\
\mathbf{u}_{t}
\end{array}\right]+\mathbf{f}_{t} \\
c\left(\mathbf{x}_{t}, \mathbf{u}_{t}\right)=\frac{1}{2}\left[\begin{array}{c}
\mathbf{x}_{t} \\
\mathbf{u}_{t}
\end{array}\right]^{T} \mathbf{C}_{t}\left[\begin{array}{c}
\mathbf{x}_{t} \\
\mathbf{u}_{t}
\end{array}\right]+\left[\begin{array}{c}
\mathbf{x}_{t} \\
\mathbf{u}_{t}
\end{array}\right]^{T} \mathbf{c}_{t}
\end{gathered}
$$

在iLQR中，状态方程只展开到一阶，如果把状态方程也展开到二阶就被称为DDP：


使用line search


## ref

- blog
    - [Continuous_Time_LQR](https://coursys.sfu.ca/2019fa-cmpt-419-x1/pages/Continuous_Time_LQR/view)
- projects
    - [Constrained iLQR with c++/eigen](https://hub.fastgit.org/pparmesh/Constrained_ILQR)
    - [iLQR with python/casadi](https://hub.fastgit.org/ADVRHumanoids/ilqr)
    - [Constrained Iterative LQR controller for an Autonomous Vehicle](https://github.com/pparmesh/Constrained_ILQR)

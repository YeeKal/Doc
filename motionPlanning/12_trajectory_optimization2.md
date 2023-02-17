---
title: 轨迹优化之轨迹规划
categories: motion planning
tags: planning
date: 2021-08-17
---
## 轨迹优化

- 约束： 系统动力学。边界条件
- 可行解: 满足约束的解
- 目标函数: 包含边界项和积分项
- 最优解: 最小化目标函数的解

![trajectory_optimization1](imgs/trajectory_optimization1.png)

## 变分法

设优化目标是使加速度的积分最小:

$$J=\int_{0}^{1} u^{2}(\tau) d \tau=\int_{0}^{1} \ddot{x}^{2}(\tau) d \tau$$

其对应泛函：

$$\mathcal{L}(x, \dot{x}, \ddot{x}|t)=\mathcal{L}(\ddot{x}|t)=\ddot{x}^{2}$$

根据E-L(欧拉拉格朗日)方程:
    $$\frac{\partial \mathcal{L}}{\partial x}-\frac{d}{dt}(\frac{\partial \mathcal{L}}{\partial x'})-\frac{d^2}{dt^2}(\frac{\partial \mathcal{L}}{\partial x''}) =0$$
可推导出x具有三次多项式的形式：
$$x^{(4)}=0$$

同理可以求得:

- 3次多项式：最小加速度
- 5次多项式：最小jerk
- 7次多项式： 最小snapw

## 轨迹拟合

通过连续曲线连接路经点

维度：拟合的曲线参数组数跟数据点的维度一致

**polynomials**

三次多项式曲线： $\theta(t)=a_0+a_1t+a_2t^2+a_3t^3$

边界条件:

$$\begin{bmatrix}\theta_i \\ \theta_{i+1} \\ \dot\theta_i \\ \dot\theta_{i+1}  \end{bmatrix} =
\begin{bmatrix} 1 & 0& 0&0 \\
     1 & \Delta t& \Delta t^2&\Delta t^3 \\
      0 & 1& 0&0 \\
     0 & 1& 2\Delta t& 3\Delta t^2 
 \end{bmatrix}  \begin{bmatrix} a_0 \\a_1\\a_2\\a_3\end{bmatrix}$$

保证速度连续，有唯一解

多个数据点 -> 曲线拟合：

- n个数据点， m维度
- (n-1)*m条曲线， 4*(n-1)*m个
- 首尾边界条件 + 中间边界条件 + 中间连续条件 = 4*m+2*(n-2)*m+2*(n-2)*m=4*(n-1)*m

**正交多项式**

根据变分法中求得的微分方程，需要根据具体条件解出该方程的参数。这里可以使用正交多项式来求解。

两类常用正交多项式：
    
$$\begin{aligned}
\text{基于Taylor展开的指数多项式}\quad &1, t, t^{2}, t^{3}, \ldots\\
\text{基于Fourier展开的三角多项式}\quad&1, \sin t, \cos t, \sin 2 t, \cos 2 t, \ldots
\end{aligned}$$

- 多项式轨迹拟合:
    - 最小加速度： $x(t)=a_{0}+a_{1} t+a_{2} t^{2}+a_{3} t^{3}$
    - 最小jerk: $\quad x(t)=a_{0}+a_{1} t+a_{2} t^{2}+a_{3} t^{3}+a_{4} t^{4}+a_{5} t^{5}$
    - 最小snap: $\quad x(t)=a_{0}+a_{1} t+a_{2} t^{2}+a_{3} t^{3}+a_{4} t^{4}+a_{5} t^{5}+a_{6} t^{6}+a_{7} t^{7}$
- 三角函数轨迹拟合:
    - 正弦轨迹: $ x(t)=a_{0}+a_{1} \cos a_{2} t+a_{3} \sin a_{2} t $
    - 摆线轨迹: $ x(t)=a_{0}+a_{1} t-a_{2} \sin a_{3} t $
    - Fourier轨迹: $x(t)=\frac{A_{0}}{2}+\sum_{n=1}^{\infty}\left[A_{n} \cos n t+B_{n} \sin n t\right]$

    $$\begin{gathered}
A_{0}=\frac{1}{\pi} \int_{-\pi}^{\pi} x(t) d t \\
A_{n}=\frac{1}{\pi} \int_{-\pi}^{\pi} x(t) \cos n t d t \\
B_{n}=\frac{1}{\pi} \int_{-\pi}^{\pi} x(t) \sin n t d t
\end{gathered}$$

## 数值积分

插值型数值积分方法：

1. 梯形公式： $I_{1}(f)=\frac{b-a}{2}(f(a)+f(b))$
2. Simspon公式: $I_{2}(f)=\frac{b-a}{6}\left(f(a)+4 f\left(\frac{a+b}{2}\right)+f(b)\right)$
3. cote
4. gauss
5. 复化Simspon
6. ....

## 离散空间

![trajectory_optimization2](imgs/trajectory_optimization2.png)


轨迹优化是一个求解泛函优化的问题。可以将该问题离散化。转化为一个函数优化的问题，降低求解难度。（泛函优化和函数优化）即直接求解轨迹点而不关注该函数的表达式。把一个微分方程转化为有m*n（维度*控制点）个优化参数的优化问题。

微分方程和离散法对比：基于微分方程的变分法是更加精确的解法，但是求解通常比较困难，特别在复杂问题以及有约束的情况下。而离散优化的方法则更加通用，降低求解复杂度，虽然牺牲了一些精确性（由于插值的存在，曲线可能不是最优）。
![trajectory_optimization3](imgs/trajectory_optimization3.png)




两种常用的微分/积分近似方法。

**Trapezoidal Collocation**：
    $$\min _{u(t)} \int_{t_{0}}^{t_{N}} u^{2}(\tau) d \tau \approx \min _{u_{0} . . u_{N}} \sum_{k=0}^{N-1} \frac{1}{2}\left(h_{k}\right)\left(u_{k}^{2}+u_{k+1}^{2}\right) \\
    \int_{t_{0}}^{t_{F}} w(\tau, \boldsymbol{x}(\tau), \boldsymbol{u}(\tau)) d \tau \quad \approx \sum_{k=0}^{N-1} \frac{1}{2} h_{k} \cdot\left(w_{k}+w_{k+1}\right)$$

system dynamics:

$$\begin{aligned}
\dot{\boldsymbol{x}} &=\boldsymbol{f}, \\
\int_{t_{k}}^{t_{k+1}} \dot{\boldsymbol{x}} d t &=\int_{t_{k}}^{t_{k+1}} \boldsymbol{f} d t, \\
\boldsymbol{x}_{k+1}-\boldsymbol{x}_{k} & \approx \frac{1}{2} h_{k} \cdot\left(\boldsymbol{f}_{k+1}+\boldsymbol{f}_{k}\right)
\end{aligned}$$

**Simpspon**

$$\int_{t_{0}}^{t_{F}} w(\tau) d \tau \approx \sum_{k=0}^{N-1} \frac{h_{k}}{6}\left(w_{k}+4 w_{k+\frac{1}{2}}+w_{k+1}\right)$$

system dynamics
$$\begin{aligned}
&x_{k+1}-x_{k}=\frac{1}{6} h_{k}\left(\boldsymbol{f}_{k}+4 \boldsymbol{f}_{k+\frac{1}{2}}+\boldsymbol{f}_{k+1}\right) \\
&x_{k+\frac{1}{2}}=\frac{1}{2}\left(x_{k}+x_{k+1}\right)+\frac{h_{k}}{8}\left(\boldsymbol{f}_{k}-\boldsymbol{f}_{k+1}\right)
\end{aligned}$$

**曲线插值**

为了从控制点恢复连续轨迹，需要进行曲线插值。

梯形配置法(Trapezoidal Collocation)求解：

$$\begin{gathered}
\boldsymbol{f}(t)=\dot{\boldsymbol{x}}(t) \approx \boldsymbol{f}_{k}+\frac{\tau}{h_{k}}\left(\boldsymbol{f}_{k+1}-\boldsymbol{f}_{k}\right) \\
\boldsymbol{x}(t)=\int \dot{\boldsymbol{x}}(t) d \tau \approx \boldsymbol{c}+\boldsymbol{f}_{k} \tau+\frac{\tau^{2}}{2 h_{k}}\left(\boldsymbol{f}_{k+1}-\boldsymbol{f}_{k}\right) \\
\qquad \boldsymbol{x}(t) \approx \boldsymbol{x}_{k}+\boldsymbol{f}_{k} \tau+\frac{\tau^{2}}{2 h_{k}}\left(\boldsymbol{f}_{k+1}-\boldsymbol{f}_{k}\right)
\end{gathered}$$

Simpson配置法(Hermite–Simpson Collocation)求解:

$$\tau=t-t_{k}  \\
h_{k}=t_{k+1}-t_{k} \\
\boldsymbol{u}(t)=\frac{2}{h_{k}^{2}}\left(\tau-\frac{h_{k}}{2}\right)\left(\tau-h_{k}\right) \boldsymbol{u}_{k}-\frac{4}{h_{k}^{2}}(\tau)\left(\tau-h_{k}\right) \boldsymbol{u}_{k+\frac{1}{2}}+\frac{2}{h_{k}^{2}}(\tau)\left(\tau-\frac{h_{k}}{2}\right) \boldsymbol{u}_{k+1}    \\
\begin{aligned}
&\boldsymbol{x}(t)=\int \dot{\boldsymbol{x}} d t \\
&=\int\left[\boldsymbol{f}_{k}+\left(-3 \boldsymbol{f}_{k}+4 \boldsymbol{f}_{k+\frac{1}{2}}-\boldsymbol{f}_{k+1}\right)\left(\frac{\tau}{h_{k}}\right)+\left(2 \boldsymbol{f}_{k}-4 \boldsymbol{f}_{k+\frac{1}{2}}+2 \boldsymbol{f}_{k+1}\right)\left(\frac{\tau}{h_{k}}\right)^{2}\right] d t
\end{aligned}   \\
\begin{aligned}
\boldsymbol{x}(t)=& \boldsymbol{x}_{k}+\boldsymbol{f}_{k}\left(\frac{\tau}{h_{k}}\right)+\frac{1}{2}\left(-3 \boldsymbol{f}_{k}+4 \boldsymbol{f}_{k+\frac{1}{2}}-\boldsymbol{f}_{k+1}\right)\left(\frac{\tau}{h_{k}}\right)^{2} \\
&+\frac{1}{3}\left(2 \boldsymbol{f}_{k}-4 \boldsymbol{f}_{k+\frac{1}{2}}+2 \boldsymbol{f}_{k+1}\right)\left(\frac{\tau}{h_{k}}\right)^{3}
\end{aligned}$$

## 

- mesh refinement: 
    - h-method: increase number of segments
    - p-method: increase polynomial order


## 最优控制

- [Numerical Optimal Control-course](https://www.syscop.de/teaching/ss2020/numerical-optimal-control-online)
- [NUMERICAL METHODS FOR OPTIMAL CONTROL](https://mariozanon.wordpress.com/numerical-methods-for-optimal-control/)
- [zhihu - optimal control](https://www.zhihu.com/column/c_1378929738640089088)




## ref

- blog 
    - [trajectory optimization slides](http://www.matthewpeterkelly.com/tutorials/trajectoryOptimization/cartPoleCollocation.svg#frame1129)
        - [OptimTraj-maTLAB](https://github.com/MatthewPeterKelly/OptimTraj/tree/master/demo/cartPole)
        - [2017-An Introduction to Trajectory Optimization: How to Do Your Own Direct Collocation]()
    - [Transcription Methods for Trajectory Optimization](https://arxiv.org/pdf/1707.00284.pdf)
    - [轨迹优化04. 轨迹拟合 & 轨迹插值](https://zhuanlan.zhihu.com/p/342012866)
- project
    
- course
    - [台大机器人学之运动学——林沛群-b站](https://www.bilibili.com/video/BV1v4411H7ez)
- paper
    
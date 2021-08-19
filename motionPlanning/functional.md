---
title: 泛函分析
categories: manifold
tags: manifold
date: 2021-08-18
---

$$I(y)=\int Fdx$$


- 泛函F：函数的函数, 可以使y和y各阶导数的函数
- 泛函数$I$: 是一个数，一般表示为泛函的积分。

则从优化的角度可以把泛函F看成优化目标， 泛函数$I$是最优值。不过通过泛函求出来的不是某一类函数的参数，而是那种形式的函数能达到最优解。

暂且设$F$是y和y的一阶导的函数: $F(y,y')$. 则路径最短问题可以表示为：

$$I=\int Fdx=\int \sqrt{1+y'^2} dx $$

**一阶欧拉拉格朗日方程**

- 微分$dy=y'$： 由x方向微小扰动产生
- 变分$\delta y$： 确定向不同的y之间的差值

令任意函数表示为最优函数和扰动函数的和：$\tilde{y}=y(x)+\epsilon\eta(x)$.若$I$取得极值， 则当$\epsilon ->0$, $I$的变化量也是0。这里由$\epsilon$引起的扰动变化标记为$\delta I, \delta y, \delta y'$.

$$\begin{align}\delta I &=\int (\frac{\partial F}{\partial y}\delta y+\frac{\partial F}{\partial y'}\delta y')dx \\
&=\int(\frac{\partial F}{\partial y}-\frac{d}{dx}(\frac{\partial F}{\partial y'}))\delta ydx+\frac{\partial F}{\partial y}'\delta y |^{x_2}_{x_1} \\
&=0\\
\text{边界条件:}&\quad\delta y(x_1)=0, \delta y(x_2)=0 \\
\text{欧拉拉格朗日方程(E-L):}& \quad \frac{\partial F}{\partial y}-\frac{d}{dx}(\frac{\partial F}{\partial y'}) =0 \end{align}$$

使得泛函数变分为0的有两部分，第二部分可以根据边界条件保证为0。因为各个函数的路径起始点都一样，所以该处的变分为0。第二部分是两个函数的乘积。由于$\delta y=\epsilon \eta$是任意函数，为了保证该积分为0，只能让第一个因子恒为0。

考虑二维平面最短路径问题，$F=\sqrt{1+y'^2}$, 根据欧拉拉格朗日方程:

$$\frac{\partial F}{\partial y}=0\\
\frac{\partial F}{\partial y'}=\frac{y'}{\sqrt(1+(y')^2)} \\
\frac{d(\frac{y'}{\sqrt(1+(y')^2)})}{dx}=0 \\
\frac{y'}{\sqrt(1+(y')^2)}=constant=C \\
y'=constant$$

所以y是一条直线。

**高阶**

假如泛函: 

$$I=\int_{x_{1}}^{x_{2}} F\left(y, y^{\prime}, y^{\prime \prime} ; x\right) d x$$

则其一阶变分：

$$\begin{align}\delta I &=\int_{x_{1}}^{x_{2}}\left(\frac{\partial F}{\partial y} \delta y+\frac{\partial F}{\partial y^{\prime}} \delta y^{\prime}+\frac{\partial F}{\partial y^{\prime \prime}} \delta y^{\prime \prime}\right) d x\\
&=\int_{x_{1}}^{x_{2}}\left(\frac{\partial F}{\partial y}-\frac{d}{d x}\left(\frac{\partial F}{\partial y^{\prime}}\right)+\frac{d^{2}}{d x^{2}} \frac{\partial F}{\partial y^{\prime \prime}}\right) \delta y d x+ \\
& \quad \quad \left.\frac{\partial F}{\partial y^{\prime \prime}} \delta y^{\prime}\right|_{x_{1}} ^{x_{2}}+\left.\left[\frac{\partial F}{\partial y^{\prime}}-\frac{d}{d x}\left(\frac{\partial F}{\partial y^{\prime \prime}}\right)\right] \delta y\right|_{x_{1}} ^{x_{2}}   \\
&=0 \end{align} \\
\quad \\
\mathrm{E}-\mathrm{L}:\quad \Longrightarrow  \frac{\partial F}{\partial y}-\frac{d}{d x}\left(\frac{\partial F}{\partial y^{\prime}}\right)+\frac{d^{2}}{d x^{2}} \frac{\partial F}{\partial y^{\prime \prime}}=0 \\
\begin{align}\text {边界条件}:& \\
&\frac{\partial F}{\partial y^{\prime \prime}}=0 \text { (Natural) or } \\
& \delta y^{\prime}=0 \text { (Essential) } ;\\
&\frac{\partial F}{\partial y^{\prime}}-\frac{d}{d x}\left(\frac{\partial F}{\partial y^{\prime \prime}}\right)=0 \text { (Natural) or }\\
&y=0 \text { (Essential) }
\end{align}
$$




## 带约束



## ref

- [变分法简介Part 1](https://zhuanlan.zhihu.com/p/20718489)
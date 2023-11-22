---
title: st图
categories: autopilot
tags: planning
date: 2021-08-11
---



## S-T graph

在既有路径的情况下进行速度规划，即确定当前的（路经点上的）最优速度。

以时间t为横轴， 路径长度为纵轴。图中的点表示在t时刻路径s的位置会与障碍物发生碰撞，因此可以根据该图进行最优速度的优化.

```py
静态障碍物：
    1. 根据路径序列计算碰撞的上下界
    2. 在上下界加入时间上下界（时间起点和终点）形成四个点
    3. 在st中的表现应该是横穿的矩形
动态障碍物:
    1. 动态障碍物以离散轨迹点表示
    2. 遍历轨迹点，对每个点在s路径序列上计算上下界，并加上当前时间
    3. 把轨迹点的上界连起来，下界连接来，则在图中形成一个上下的包围体
```

在实际应用中有两大类不同的处理方案：

- time window(TW): 离散s轴，沿t轴方向画条带， 优化变量 $t_i$
- pass window(PW)： 离散t轴，在s轴方向画条带， 优化变量为$s,\dot{s}, \ddot{s}$

PW 型

![st_path](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/st_path.png)

TW 型

![overtake_st2](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/11/overtake_st2.png)

对于变量的处理上也有两大类：

- 直接离散变量
- 曲线拟合：多项式/贝塞尔曲线

## PW 型

- [ref blog](https://liuxiaofei.com.cn/blog/apollo%E4%BA%8C%E6%AC%A1%E8%A7%84%E5%88%92%E7%AE%97%E6%B3%95piecewise-jerk-speed-optimizer%E8%A7%A3%E6%9E%90/)

离散t轴，在s轴方向画条带， 优化变量为$s,v = \dot{s}, a = \ddot{s}, jerk$. 该问题可以转化为标准的QP问题，可以用OSQP进行快速求解。

问题定义只能在s方向上定义，不能对笛卡尔坐标系进行定义。因此关于曲率，横向加速度等没有办法加入到约束条件。

**<font color='Tomato'>Cost function</font>**

$$\begin{align} J=\sum^N_{i=0}( &w^i_s\cdot||s^i-s^i_r||^2\\
+&w^i_v\cdot||v^i-v^i_r||^2 \\
+&w^i_a\cdot||a^i||^2   \\
+&w^i_{jerk}\cdot||jerk^i||^2)   \end{align}  $$

**<font color='Tomato'>Constraint</font>**

**boundary constraint - safety**

N = 4*t

s的约束规定了障碍物的时序

$$s_{min}{\leq}s_t{\leq}s_{max} \\
v_{min}{\leq}v_t{\leq}v_{max} \\
a_{min}{\leq}a_t{\leq}a_{max}\\
jerk_{min}{\leq}jerk_t{\leq}jerk_{max}
$$

**单调约束**

N = t-1

$$\begin{equation}s_t - s_{t+1} \leq0\end{equation}$$

**状态方程约束/运动学约束 - kinematic**

N = 3*(t-1)

$$s_{t+1}=s_t+v_t{\cdot}dt+\frac{1}{2}a_t{\cdot}dt^2+\frac{1}{6}jerk_t{\cdot}dt^3 \\
v_{t+1}=v_t+a_t{\cdot}dt+\frac{1}{2}jerk_t{\cdot}dt^2\\
a_{t+1}=a_t+jerk_t{\cdot}dt$$

**scenario**


$$\begin{align}
s^i &\leq s^i_{lead}-(v^i-v^i_{lead})\cdot t_r^i-d^i_{l_{safe}} & \quad \text{纵向避让} \\
s^i &\geq s^i_{rear}+(v^i_{rear}-v^i)\cdot t_r^i+d^i_{r_{safe}} & \quad \text{纵向超车}\end{align}$$

纵向避让: 自车以当前速度行驶反应时间的距离后与前车应该保持安全距离

纵向超车: 自车以当前速度行驶反应时间内，被超车辆与自车能保持一定安全距离

## PW 型 spline 参数曲线

- [QP-Spline-Path Optimizer](https://github.com/ApolloAuto/apollo/blob/r5.5.0/docs/specs/qp_spline_path_optimizer.md)
- [qp_spline_path_optimizer](https://github.com/ApolloAuto/apollo/blob/r5.5.0/docs/specs/qp_spline_st_speed_optimizer_cn.md)
- [代码参考](https://github.com/jchengai/gpir/blob/main/common/smoothing/osqp_spline1d_solver.h)

s不再是离散变量，而是把s表示为t的曲线函数。早期Apollo的做法即是如此。在Apollo中，ST速度参数被分为 n 段，每段路径用用5阶多项式表示

$$
s = f_i(t) 
  = a_{0i} + a_{1i} \cdot t + a_{2i} \cdot t^2 + a_{3i} \cdot t^3 + a_{4i} \cdot t^4 + a_{5i} \cdot t^5
$$

如此优化变量从$\{s,v = \dot{s}, a = \ddot{s}, jerk\}$转化为曲线的参数 $\{a_{ij}\}$,最后同样转化为QP问题

**<font color='Tomato'>定义样条段优化函数</font>** 

Apollo首先定义$cost_1$以使路径更加平滑：

$$
cost_1 = \sum_{i=1}^{n} \Big( w_1 \cdot \int\limits_{0}^{d_i} (f_i')^2(s) ds + w_2 \cdot \int\limits_{0}^{d_i} (f_i'')^2(s) ds + w_3 \cdot \int\limits_{0}^{d_i} (f_i^{\prime\prime\prime})^2(s) ds \Big)
$$

然后，Apollo定义$cost_2$表示最后的S-T路径和S-T巡航路径（有速度限制且m个点）的差值：

$$
cost_2 = \sum_{i=1}^{n}\sum_{j=1}^{m}\Big(f_i(t_j)- s_j\Big)^2
$$

同样地，Apollo定义了$cost_3$表示第一个S-T路径和随后的S-T路径（o个点）的差值：

$$
cost_3 = \sum_{i=1}^{n}\sum_{j=1}^{o}\Big(f_i(t_j)- s_j\Big)^2
$$

最后得出的目标函数为：

$$
cost = cost_1 + cost_2 + cost_3
$$

**<font color='Tomato'>约束条件</font>**
    
**初始点约束**

假设第一个点是($t0$, $s0$)，且$s0$在路径$f_i(t)$, $f'i(t)$, 和$f_i(t)''$上（位置、速率、加速度）。Apollo将这些约束转换为QP约束的等式为：

$$
A_{eq}x = b_{eq}
$$

**单调约束**

路线必须是单调的，比如车辆只能往前开。

在路径上采样 **m** 个点，对每一个 $j$和$j-1$ 的点对，且($j\in[1,...,m]$)，如果两个点都处在同一个样条$k$上，则：

$$\begin{vmatrix}  1 & t_j & t_j^2 & t_j^3 & t_j^4&t_j^5 \\ \end{vmatrix} 
\cdot \begin{vmatrix}  a_k \\ b_k \\ c_k \\ d_k \\ e_k \\ f_k  \end{vmatrix} >
\begin{vmatrix}  1 & t_{j-1} & t_{j-1}^2 & t_{j-1}^3 & t_{j-1}^4&t_{j-1}^5 \\ \end{vmatrix}  
\cdot 
\begin{vmatrix}  a_{k} \\ b_{k} \\ c_{k} \\ d_{k} \\ e_{k} \\ f_{k}  \end{vmatrix}$$

如两个点分别处在不同的样条$k$和$l$上，则：

$$
\begin{vmatrix}  1 & t_j & t_j^2 & t_j^3 & t_j^4&t_j^5 \\ \end{vmatrix} 
\cdot 
\begin{vmatrix}  a_k \\ b_k \\ c_k \\ d_k \\ e_k \\ f_k  \end{vmatrix} >
\begin{vmatrix}  1 & t_{j-1} & t_{j-1}^2 & t_{j-1}^3 & t_{j-1}^4&t_{j-1}^5 \\ \end{vmatrix}  
\cdot 
\begin{vmatrix}  a_{l} \\ b_{l} \\ c_{l} \\ d_{l} \\ e_{l} \\ f_{l}  \end{vmatrix}
$$

**平滑节点约束**

该约束的目的是使样条的节点更加平滑。假设两个段$seg_k$ 和$seg_{k+1}$互相连接，且$seg_k$的累计值 **s** 为$s_k$。计算约束的等式为：

$$
f_k(t_k) = f_{k+1} (t_0)
$$

即：

$$\begin{vmatrix} 1 & t_k & t_k^2 & t_k^3 & t_k^4&t_k^5 \\ \end{vmatrix} 
\cdot \begin{vmatrix} 
a_{k0} \\ a_{k1} \\ a_{k2} \\ a_{k3} \\ a_{k4} \\ a_{k5} 
\end{vmatrix} = \begin{vmatrix} 
1 & t_{0} & t_{0}^2 & t_{0}^3 & t_{0}^4&t_{0}^5 \\\end{vmatrix} 
\cdot \begin{vmatrix} 
a_{k+1,0} \\ a_{k+1,1} \\ a_{k+1,2} \\ a_{k+1,3} \\ a_{k+1,4} \\ a_{k+1,5} 
\end{vmatrix}$$

然后，
$$
\begin{vmatrix} 
 1 & t_k & t_k^2 & t_k^3 & t_k^4&t_k^5 &  -1 & -t_{0} & -t_{0}^2 & -t_{0}^3 & -t_{0}^4&-t_{0}^5\\
 \end{vmatrix} 
 \cdot 
 \begin{vmatrix} 
 a_{k0} \\ a_{k1} \\ a_{k2} \\ a_{k3} \\ a_{k4} \\ a_{k5} \\ a_{k+1,0} \\ a_{k+1,1} \\ a_{k+1,2} \\ a_{k+1,3} \\ a_{k+1,4} \\ a_{k+1,5}   
 \end{vmatrix} 
 = 0
$$

等式中得出的结果为$t_0$ = 0。

同样地，为下述等式计算约束等式：

$$
f'_k(t_k) = f'_{k+1} (t_0)
\\
f''_k(t_k) = f''_{k+1} (t_0)
\\
f'''_k(t_k) = f'''_{k+1} (t_0)
$$

**点采样边界约束**

在路径上均匀的取样 **m** 个点，检查这些点上的障碍物边界。将这些约束转换为QP约束不等式，使用不等式：

$$
Ax \leq b
$$

首先基于道路宽度和周围的障碍物找到点 $(s_j, l_j)$的下边界$l_{lb,j}$，且$j\in[0, m]$。计算约束的不等式为：

$$
\begin{vmatrix} 
 1 & t_0 & t_0^2 & t_0^3 & t_0^4&t_0^5 \\
  1 & t_1 & t_1^2 & t_1^3 & t_1^4&t_1^5 \\
 ...&...&...&...&...&... \\
 1 & t_m & t_m^2 & t_m^3 & t_m^4&t_m^5 \\
 \end{vmatrix} \cdot \begin{vmatrix} a_i \\ b_i \\ c_i \\ d_i \\ e_i \\ f_i \end{vmatrix} 
 \leq 
 \begin{vmatrix}
 l_{lb,0}\\
 l_{lb,1}\\
 ...\\
 l_{lb,m}\\
 \end{vmatrix}
$$

同样地，对上边界$l_{ub,j}$，计算约束的不等式为：

$$
\begin{vmatrix} 
 1 & t_0 & t_0^2 & t_0^3 & t_0^4&t_0^5 \\
  1 & t_1 & t_1^2 & t_1^3 & t_1^4&t_1^5 \\
 ...&...&...&...&...&... \\
 1 & t_m & t_m^2 & t_m^3 & t_m^4&t_m^5 \\
 \end{vmatrix} \cdot \begin{vmatrix} a_i \\ b_i \\ c_i \\ d_i \\ e_i \\ f_i \end{vmatrix} 
 \leq
 -1 \cdot
 \begin{vmatrix}
 l_{ub,0}\\
 l_{ub,1}\\
 ...\\
 l_{ub,m}\\
 \end{vmatrix}
$$

**速度边界优化**

Apollo同样需要建立速度限制边界。

在st曲线上取样 **m** 个点，为每个点$j$获取速度限制的上边界和下边界，例如$v{ub,j}$ 和 $v{lb,j}$，约束定义为：

$$
f'(t_j) \geq v_{lb,j}
$$
即：
$$
\begin{vmatrix}  
0& 1 & t_0 & t_0^2 & t_0^3 & t_0^4 \\  
0 & 1 & t_1 & t_1^2 & t_1^3 & t_1^4 \\ 
...&...&...&...&...&... \\ 
0& 1 & t_m & t_m^2 & t_m^3 & t_m^4 \\ 
\end{vmatrix} 
\cdot 
\begin{vmatrix} 
a_i \\ b_i \\ c_i \\ d_i \\ e_i \\ f_i 
\end{vmatrix}  
\geq  
\begin{vmatrix} v_{lb,0}\\ v_{lb,1}\\ ...\\ v_{lb,m}\\ \end{vmatrix}
$$

且，
$$
f'(t_j) \leq v_{ub,j}
$$
即：
$$
\begin{vmatrix} 
 0& 1 & t_0 & t_0^2 & t_0^3 & t_0^4 \\
 0 & 1 & t_1 & t_1^2 & t_1^3 & t_1^4 \\
 ...&...&...&...&...&... \\
 0 &1 & t_m & t_m^2 & t_m^3 & t_m^4 \\
 \end{vmatrix} \cdot \begin{vmatrix} a_i \\ b_i \\ c_i \\ d_i \\ e_i \\ f_i \end{vmatrix} 
 \leq
 \begin{vmatrix}
 v_{ub,0}\\
 v_{ub,1}\\
 ...\\
 v_{ub,m}\\
 \end{vmatrix}
$$

## TW型

优势：

- 沿路径限速：曲率限速，横向margin限速
- 横向加速度：

两大类优化方程结构：

1. 以$t_i$为优化变量， 路径上的限速信息以及横向加速度转化为t的线性不等式 [ref](https://www.cs.cmu.edu/~cliu6/files/iv17-2.pdf)
2. 以$v_i,a_i$为优化变量，路径上的限速信息直接使用$v_i$代替

**<font color='Tomato'>优化变量$v(s), a(s)$</font>**

数据输入：

- $P=\{x_i,y_i,\theta_i\}$
- $TW = \{s_i,t_{min,i}, t_{max,i}\}$

优化目标：


$$\begin{aligned} J_{v_i(s), a_i(s),j_i(s)} &= w_1 J_T + w_2 J_S & \\
J_t & = \sum v_i / \Delta s_i & \text{total elapse time} \\
J_S &= \sum j_i^2 & \text{sumsquare of jerk, comfort} \end{aligned}$$

（优化目标暂时缺少横向运动学惩罚项，缺少加速度惩罚项）

约束方程：

$$\begin{aligned} \dot v = a; \dot a = j &\quad \text{运动学方程}\\ & \quad \text{端点和边界条件} \\
T_i =\sum_{n=0}^{n=i} v_n / \Delta s_n \in (t_{min,i}, t_{max,i}) &\quad \text{障碍物约束} \\
vi \in (v_{min,i}, v_{max,i}) & \quad \text{沿路径的速度约束，其实隐含在边界条件之中} \end{aligned}$$



## Ref


ref: Apollo代码中的ST Graph在modules/planning/lattice/behavior/path_time_graph.h文件



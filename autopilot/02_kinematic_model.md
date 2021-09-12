---
title: 自动驾驶-运动学模型
categories: autopilot
tags: autopilot
date: 2021-08-10
---

## 自行车模型

![bicycle_model](imgs/bicycle_model.jpg)

自行车模型中心点位于后车轮中心。$L$为前后轮距。

- state:
    - x:
    - y
    - $\theta$: heading angle
    - v: velocity
- control:
    - $\phi$: steer angle
    - a: acceleration

推倒关系式:

$$\begin{align}
 \dot{x} &=v\cdot cos(\theta)  \\
 \dot{y} &=v\cdot sin(\theta)  \\
 \dot{\theta} &=\frac{v \cdot tan(\phi)}{L}  \\
 \dot{v} &= a
\end{align}$$


**linealize**

You can get a discrete-time mode with Forward Euler Discretization with sampling time dt.

$$z_{k+1}=z_k+f(z_k,u_k)dt$$

Using first degree Tayer expantion around zbar and ubar
$$z_{k+1}=z_k+(f(\bar{z},\bar{u})+A'z_k+B'u_k-A'\bar{z}-B'\bar{u})dt$$

$$z_{k+1}=(I + dtA')z_k+(dtB')u_k + (f(\bar{z},\bar{u})-A'\bar{z}-B'\bar{u})dt$$

$$z_{k+1}=Az_k+Bu_k +C$$

where:

$$\begin{align}A &= (I + dtA')\\
&=\begin{bmatrix} 
1 & 0 & cos(\bar{\phi})dt & -\bar{v}sin(\bar{\phi})dt\\
0 & 1 & sin(\bar{\phi})dt & \bar{v}cos(\bar{\phi})dt \\
0 & 0 & 1 & 0 \\
0 & 0 &\frac{tan(\bar{\delta})}{L}dt & 1 \\
\end{bmatrix}   \\
    \\
B &= dtB'\\
&=
\begin{bmatrix} 
0 & 0 \\
0 & 0 \\
dt & 0 \\
0 & \frac{\bar{v}}{Lcos^2(\bar{\delta})}dt \\
\end{bmatrix} \end{align}   $$

$$\begin{align}
C &= (f(\bar{z},\bar{u})-A'\bar{z}-B'\bar{u})dt\\
&= dt(
\begin{bmatrix} 
\bar{v}cos(\bar{\phi})\\
\bar{v}sin(\bar{\phi}) \\
\bar{a}\\
\frac{\bar{v}tan(\bar{\delta})}{L}\\
\end{bmatrix}   
\begin{bmatrix} 
\bar{v}cos(\bar{\phi})-\bar{v}sin(\bar{\phi})\bar{\phi}\\
\bar{v}sin(\bar{\phi})+\bar{v}cos(\bar{\phi})\bar{\phi}\\
0\\
\frac{\bar{v}tan(\bar{\delta})}{L}\\
\end{bmatrix}   
\begin{bmatrix} 
0\\
0 \\
\bar{a}\\
\frac{\bar{v}\bar{\delta}}{Lcos^2(\bar{\delta})}\\
\end{bmatrix}
)\\
& =\begin{bmatrix} 
\bar{v}sin(\bar{\phi})\bar{\phi}dt\\
-\bar{v}cos(\bar{\phi})\bar{\phi}dt\\
0\\
-\frac{\bar{v}\bar{\delta}}{Lcos^2(\bar{\delta})}dt\\
\end{bmatrix}
\end{align}$$


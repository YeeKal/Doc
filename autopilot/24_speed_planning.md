---
title: longitudinal speed planning
categories: autopilot
tags: planning
date: 2021-09-08
---

## 2018 Toward a More Complete, Flexible, and Safer Speed Planning for Autonomous Driving via Convex Optimization

- [blog- Convex-optimization-based Speed Planning](https://yuzhangbit.github.io/speed_project/)


#### motivation

constraints for speed planning

- safety
- smooth
- time-efficient

$$\begin{array}{llll}
\hline \text { Category } & \text { Constraint Name } & \text { Description } & \text { Property } \\
\hline \text { Soft Constraints } & \begin{array}{l}
\text { Smoothness (S) } \\
\text { Time Efficiency (TE) }
\end{array} & \begin{array}{l}
\text { continuity of speed, acceleration and jerk over the path } \\
\text { time used by travelling along the path }
\end{array} & \begin{array}{l}
\text { performance } \\
\text { performance }
\end{array} \\
\hline \text { Hard Constraints } & \text { Friction Circle (FC) } & \text { total force should be within the friction circle } & \text { safety } \\
& \text { Time Window (TW) } & \text { time window to reach a certain point on path } & \text { safety } \\
& \text { Boundary Condition (BC) } & \text { speed at the end of the path } & \text { safety\&performance } \\
\hline
\end{array}$$

#### dynamics

$$\begin{aligned}
\theta & \text { heading of the car } \\
u^{\tau} & \text { lateral force in ego frame } \\
u^{\eta} & \text { longitudinal force in ego frame }    \\
\text{prime } &'\text{: derivative eith respact to arc-length s} \\ \text{dot } &\dot{}\text{ :derivative eith respact to time t } 
\end{aligned}$$

path representation

$$\begin{aligned}
r(s)&=(x(s), y(s)), s \in\left[0, s_{f}\right]   \\
r'(s)&=(cos(\theta), sin(\theta(s)))=(x'(s), y'(s))\\
s & =f(t)  \\
\alpha(s) & =\ddot{f}  \quad \text{longitudinal acceleration}  \\
\beta(s) & =\dot{f}^2  \quad \text{square of the longitudinal speed}\end{aligned}$$

dynamics:

$$\begin{aligned}\dot{x}(s)&=\frac{\partial x}{\partial s} \dot{f}  \\
\ddot{x}(s)&=\frac{\partial^2 x}{\partial s^2} \dot{f}^2+\frac{\partial x}{\partial s} \ddot{f} \\
&=x''(s)\beta(s)+x'(s)\alpha(s)
\end{aligned}$$

$$\text { Dynamics }\left\{\begin{array}{l}
R \boldsymbol{u}=m \ddot{r}(s), \text { dynamics equation } \\
\ddot{r}(s)=r^{\prime \prime}(s) \beta(s)+r^{\prime}(s) \alpha(s) \\
R=\left[\begin{array}{cc}
\cos (\theta(s)) & -\sin (\theta(s)) \\
\sin (\theta(s)) & \cos (\theta(s))
\end{array}\right], \text { rotation matrix } \\
\boldsymbol{u}=\left(u^{\tau}, u^{\eta}\right), \text { control vector }
\end{array}\right.$$

#### object function

object function is viewed as soft constraints, and constrains function is viewed as hard constraints

- time efficiency: 
$$J_{T}=T_{s_{f}}=\int_0^{T} 1dt\\
=\int_{f(0)}^{f(t_f)} \frac{1}{\dot{f}}ds=\int_{0}^{s_{f}} \beta(s)^{-\frac{1}{2}} d s$$

- IoD(Integrate of difference) objective: velocity track.(这里是速度跟踪，也许能把它换成速度范围，在下面path constraints有所体现)
    $$J_v=\int^{s_f}_0||\beta(s)-v_r(s)^2||ds$$
- smooth objective:
    - jerk is common used but is non-convex

    $$\begin{aligned}
    \mathcal{J}(s) &=\frac{\partial^3 f}{\partial t^3}=\dot{\alpha}(s)=\alpha^{\prime}(s) \dot{f} \\
    &=\alpha^{\prime}(s) \sqrt{\beta(s)}=\frac{1}{2} \beta^{\prime \prime}(s) \sqrt{\beta(s)}
    \end{aligned}$$

    - pseudo jerk, is convex (used in this paper)

    $$J_{S}=\int_{0}^{s_{f}}\left\|\alpha^{\prime}(s)\right\|^{2} d s$$
- path constraints: $\psi(s,x,u)\leq0, s\in[0,s_f]$
    - speed limits(与前述IoD约束不同)
- boundary condition constraints
- time window constraints: avoid collision with the predicted trajectory of obstacles. 在$\dot{s}-s$图上，通过某段路程的时间被限制在某一个范围内。
    $$T_{i}=\int_{0}^{s_{i}} \beta(s)^{-\frac{1}{2}} d s \in\left(0, T_{U}\right]$$


在该图的横穿场景中，两辆车把同行时间分成了三段。其中A段只有一个上限，B段有上下限，C段有一个下限，三段联合组成了这一位置的时间窗口约束。这里只有A段是凸的而B，C是非凸的条件。一般是通过决策过程选择一端把该问题变成凸问题。
![speed_planning_1.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/speed_planning_1.png)

- comfort box constraints: use semi-hard constraint 

## implementation with discretization


## ref

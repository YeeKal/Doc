---
title: TW 型S-T图速度规划
categories: 
tags: 
date: 2023-11-20
---


## 离散 $\dot f,\ddot f$


$$\begin{array}{cl}
\underset{\substack{\alpha(s), \beta(s), u(s), \sigma^\tau(s), \sigma^\eta(s)}}{\operatorname{minimize}} & J=\omega_1 J_T+\omega_2 J_S+\omega_3 J_V \\
& +\lambda_1\left\|\sigma^\tau(s)\right\|+\lambda_2\left\|\sigma^\eta(s)\right\| \\
\text { s.t. } & (6),(8),(11),(17),(19),(20), \\
& \|\alpha(s)\| \leq a_c^\tau+\sigma^\tau(s), \\
& \left\|\frac{u^\eta(s)}{m}\right\| \leq a_c^\eta+\sigma^\eta(s), \\
& 0 \leq \sigma^\tau(s), \\
& 0 \leq \sigma^\eta(s),
\end{array}$$

where $\dot{r}^2(s)=\left(r^{\prime}(s)\right)^2 \beta(s) \text { and } \ddot{r}(s)=r^{\prime} \alpha(s)+r^{\prime \prime} \beta(s)$

**<font color='Tomato'>Implementation with Discretization</font>** 

$$\begin{aligned}\beta(s)&=\beta_i+\left(s-s_i\right)\left(\frac{\beta_{i+1}-\beta_i}{s_{i+1}-s_i}\right), s \in\left[s_i, s_{i+1}\right] \\
r'(s) &= \frac{r(s_{i+1})-r(s_i)}{s_{i+1}-s_i} \\
r''(s) &= \frac{r(s_{i-2})-r(s_{i-1})-r(s_i)+r(s_{i+1})}{2\Delta s^2} \end{aligned}$$

**Cost function**

$$\begin{aligned}
J_{T_i} & =\int_{s_i}^{s_{i+1}} \beta(s)^{-\frac{1}{2}} d s \\
& =\int_{s_i}^{s_{i+1}}\left(\beta_i+\left(s-s_i\right)\left(\frac{\beta_{i+1}-\beta_i}{s_{i+1}-s_i}\right)\right)^{-\frac{1}{2}} d s \\
& =\frac{2 \cdot \Delta s}{\sqrt{\beta_i}+\sqrt{\beta_{i+1}}}, \\
J_T& =2 \sum_{i=0}^{N-1} \frac{\Delta s}{\sqrt{\beta_i}+\sqrt{\beta_{i+1}}} \\
J_S &= \int^{s_f}_0 ||\alpha'(s)||^2 ds \\
    &= \sum^{N-1}_0||\frac{\alpha(s_{i+1})-\alpha(s_i)}{\Delta s}||^2\Delta s \\
J_V &=\sum^{N-1}_0||\beta(s_i)-v_r^2||\Delta s 
\end{aligned}$$

**Constraint**

dynamics:

$$Ru = m \ddot{r} \\
\beta'(s) = 2\alpha(s)$$

acc and vec limit:

$$||u(s)|| \leq \mu mg \\
\mu^\tau(s) \leq m\cdot a^{\tau}_{max} \\
\beta(s)\leq v^2_{max}$$

path constraints:

$$\beta(s_i)\leq \overline{\beta}(s_i)$$

endpoint condition:

$$\underline{\alpha}_{sf} \leq \alpha_{sf} \leq \overline{\alpha}_{sf} \\ 
\underline{\beta}_{sf} \leq \beta_{sf} \leq \overline{\beta}_{sf}$$


time window:

$$t_i = T(s_i) \in (t_{imin}, t_{imax})$$

**<font color='Tomato'>Force constraint</font>**


$$\begin{aligned}R\boldsymbol{u} &=m \ddot{r}(s)\\
\boldsymbol{u} &= \begin{bmatrix} u^\tau \\ u^\eta  \end{bmatrix} \\ 
&=mR^{-1}\ddot r \\
&=m\begin{bmatrix} cos \theta & sin \theta \\
-sin\theta & cos\theta \end{bmatrix} (\begin{bmatrix} cos\theta \cdot \ddot f \\ sin\theta\cdot \ddot f  \end{bmatrix} + \begin{bmatrix} -sin\theta \cdot \kappa \cdot \dot f^2 \\ cos \theta \cdot \kappa \cdot \dot f^2 \end{bmatrix}) \\ 
& = m \begin{bmatrix} \ddot f \\ \kappa \dot f^2 \end{bmatrix} \quad \begin{matrix} \text{ 其实就是纵向加速度} \\ \text{其实就是向心力} \frac{v^2}{r} \end{matrix} \end{aligned} $$


## $P = \{x_i,y_i, \theta_i, \kappa_i\}$

$$\begin{array}{cl}
\underset{\substack{\alpha(s), \beta(s), u(s), \sigma^\tau(s), \sigma^\eta(s)}}{\operatorname{minimize}} & J=\omega_1 J_T+\omega_2 J_S+\omega_3 J_V  +\lambda_1\left\|\sigma^\tau(s)\right\|+\lambda_2\left\|\sigma^\eta(s)\right\| \\
&= \sum_{i=0}^{N-1}(2w_1 \frac{\Delta s}{\sqrt{\beta_i}+\sqrt{\beta_{i+1}}} + w_2  ||\frac{\alpha(s_{i+1})-\alpha(s_i)}{\Delta s}||^2\Delta s+||\beta(s_i)-v_r^2||\Delta s)\\
& +\lambda_1\left\|\sigma^\tau(s)\right\|+\lambda_2\left\|\sigma^\eta(s)\right\| \\
s.t.\quad& \\
&\beta'(s) = 2\alpha(s), \alpha(s)^2+(\kappa(s) \beta(s))^2 \leq (\mu g)^2\\
&\beta(s)\leq v^2_{max}, \alpha(s) \leq a^{\tau}_{max}\\
& T(s_i) \in (t_{imin}, t_{imax}) \quad \text{time window}\\
& \beta(s_i)\leq \overline{\beta}(s_i) \quad \text{path constraints} \\
& \underline{\alpha}_{sf} \leq \alpha_{sf} \leq \overline{\alpha}_{sf},
\underline{\beta}_{sf} \leq \beta_{sf} \leq \overline{\beta}_{sf}\\
 &\|\alpha(s)\| \leq a_c^\tau+\sigma^\tau(s), \\
& \left\|\frac{u^\eta(s)}{m}\right\| \leq a_c^\eta+\sigma^\eta(s), \\
& 0 \leq \sigma^\tau(s), \\
& 0 \leq \sigma^\eta(s),
\end{array}$$

## 简化版

$$\begin{array}{cl}
\underset{\substack{\alpha(s), \beta(s), u(s)}}{\operatorname{minimize}} & J=\omega_1 J_T+\omega_2 J_S+\omega_3 J_V   \\
&= \sum_{i=0}^{N-1}(2w_1 \frac{\Delta s}{\sqrt{\beta_i}+\sqrt{\beta_{i+1}}} + w_2  ||\frac{\alpha(s_{i+1})-\alpha(s_i)}{\Delta s}||^2\Delta s+||\beta(s_i)-v_r^2||\Delta s)\\
s.t.\quad& \\
&\beta'(s) = 2\alpha(s) \\
&\sout{ \alpha(s)^2+(\kappa(s) \beta(s))^2 \leq (\mu g)^2 }\\
& \kappa_i \beta(s) \leq a^\eta_{max} \quad \text{lat slip acc, 最后可以转化为对速度的约束} \\
&\beta(s)\leq v^2_{max}, \alpha(s) \leq a^{\tau}_{max}\\
& T(s_i) \in (t_{imin}, t_{imax}) \quad \text{time window}\\
& \beta(s_i)\leq \overline{\beta}(s_i) \quad \text{path constraints} \\
& \underline{\alpha}_{sf} \leq \alpha_{sf} \leq \overline{\alpha}_{sf},
\underline{\beta}_{sf} \leq \beta_{sf} \leq \overline{\beta}_{sf}
\end{array}$$

## 零速处理

对分母为0时进行处理

$$\Delta T_i = =\frac{2 \cdot \Delta s}{\sqrt{\beta_i}+\sqrt{\beta_{i+1}}}$$

1. pruning: 在零点处剪枝
2. use a small speedvalue, such as 0.02m/s

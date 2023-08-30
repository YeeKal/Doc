<!-- MarkdownTOC -->

- [differential motion](#differential-motion)
- [velocity](#velocity)
- [which frame](#which-frame)
- [kinematic singularity](#kinematic-singularity)
- [velocity/force duality](#velocityforce-duality)

<!-- /MarkdownTOC -->

## differential motion

末端执行器的位姿变化(cartesian velocity)$X=\{x_1,x_2,x_3,x_4,x_5,x_6\}$由各个关节的变化(joint rates)$\{q_1,q_2\dots\}$产生，记为：

$$\begin{align}X=\begin{bmatrix} x_1\\x_2\\\dots\\x_m\end{bmatrix}=\begin{bmatrix} f_1(q)\\f_2(q)\\ \dots \\f_m(q) \end{bmatrix}\end{align} $$

对每一个状态量进行全微分：

$$\begin{matrix}\Delta x_1=\frac{\partial f_1}{\partial q_1}\cdot\Delta q_1+\frac{\partial f_1}{\partial q_2}\cdot\Delta q_2+\dots+\frac{\partial f_1}{\partial q_n}\cdot\Delta q_n      \\\Delta x_2=\frac{\partial f_2}{\partial q_1}\cdot\Delta q_1+\frac{\partial f_2}{\partial q_2}\cdot\Delta q_2+\dots+\frac{\partial f_2}{\partial q_n}\cdot\Delta q_n       \\ \vdots      \\\Delta x_m=\frac{\partial f_m}{\partial q_1}\cdot\Delta q_1+\frac{\partial f_m}{\partial q_2}\cdot\Delta q_2+\dots+\frac{\partial f_m}{\partial q_n}\cdot\Delta q_n \end{matrix}  \longrightarrow    \Delta X=\begin{bmatrix}\frac{\partial f_1}{\partial q_1}&\frac{\partial f_1}{\partial q_2}&\dots&\frac{\partial f_1}{\partial q_n}      \\\frac{\partial f_2}{\partial q_1}&\frac{\partial f_2}{\partial q_2}&\dots&\frac{\partial f_2}{\partial q_n}      \\ \vdots&\vdots&\vdots&\vdots      \\\frac{\partial f_m}{\partial q_1}&\frac{\partial f_m}{\partial q_2}&\dots&\frac{\partial f_m}{\partial q_n} \end{bmatrix}\Delta Q$$

此微分矩阵被称为雅可比矩阵(jacobian matrix), 记为$J$. 则上述微分式简写为：

$$\Delta X_{m\times1}=J_{m\times n}(q)\cdot\Delta Q_{n\times1}$$

## jacobian

雅可比矩阵是状态量(position/orientation)对关节变化量的微分矩阵，因此事实上也表示了速度(linear/angular)对关节变化的关系. 另一方面根据正运动学也可以求得末端执行器的速度：

linear: $V_i=\varepsilon_i Z_i\dot{q}+\bar{\varepsilon_i}\cdot(\Omega_i\times P_{end})$($P_{i}$：坐标系$i$的原点指向末端坐标系原点在基坐标系中的向量表示)  
angular: $\Omega_i=\bar{\varepsilon_i}\cdot\Omega_i$ **(prismatic joint: $\varepsilon$=1;revolute joint: $\bar{\varepsilon}$=1)**  
- $Z_i=^0Z_i=R^0_ie_z$: 坐标系z轴方向基坐标系下的向量表示   
- $P_i$:坐标系$i$的原点指向末端坐标系原点在基坐标系中的向量表示(故若坐标系原点重合，则叉积为0，即旋转运动不影响线性速度)
- $Z_i\cdot \dot{q_i}$: Z是向量，与线性速度值相乘表示速度在三个轴上的投影分量  
- $Z_i\times P_i\cdot \dot{q}$: 与旋转关节的旋转轴与末端向量叉乘表示旋转对线速度的影响

$$\begin{align}v&=\sum^m_{i=1}V_i=\sum^m_{i=1}(\varepsilon_i\cdot Z_i+\bar{\varepsilon_i}\cdot(Z_i\times P_i))\cdot\dot{q_i}\\&=\begin{bmatrix}(\varepsilon_1\cdot Z_1+\bar{\varepsilon_1}\cdot(Z_1\times P_1)&\dots (\varepsilon_n\cdot Z_n+\bar{\varepsilon_n}\cdot(Z_n\times P_n) \end{bmatrix}\begin{bmatrix} q_1\\ \vdots \\q_n\end{bmatrix}\\&=J_vQ \end{align}$$

$$\begin{align}\omega&=\sum^m_{i=1}\Omega_i=\sum^m_{i=1}(\bar{\varepsilon_i}\cdot Z_i)\cdot\dot{q_i}\\&=\begin{bmatrix}\bar{\varepsilon_1}\cdot Z_1&\dots&\bar{\varepsilon_n}\cdot Z_n \end{bmatrix}\begin{bmatrix} q_1\\ \vdots \\q_n\end{bmatrix}\\&=J_{\omega}Q \end{align}$$

$$J=\begin{bmatrix} J_v\\J_{\omega}\end{bmatrix}$$

速度在坐标系间(旋转+平移)的转换：

$$v_{p/A}=^A_BRv_{p/B}+v_{B/A}+w_{B/A}\times P_B$$

$P_B$ 是点在相对坐标系(B)中的坐标

**denote**: $\hat{a}, $skew symetric matrix

$$\vec{a}\times\vec{b}=\begin{bmatrix} 0&-a_3&a_2\\a_3&0&-a_1\\-a_2&a_1&0\end{bmatrix}\begin{bmatrix}b_1\\b_2\\b_3 \end{bmatrix}=\hat{a}b$$

**transformation in different frames**

在同一个坐标系中计算$J$.

不同坐标系间的变换：

$$^AJ=\begin{bmatrix} ^A_BR&0\\0& ^A_BR \end{bmatrix} {}^BJ$$



##velocity propagation

$$\begin{align} v_i&\equiv{}^0[^0V_i]= [^0V_i] \\  \omega_i&\equiv{}^0[^0\Omega_i]= [^0\Omega_i] \end{align}$$

The velocity **computed** relative to the base frame {0} and often **represented** reltive to other frames{$\mathcal{k}$}. The following notation is used for this conditions:

$$\begin{align} {}^kv_i&\equiv{}^k[^0V_i]={}^k_0R [^0V_i]={}^k_0R\cdot v_i \\  \omega_i&\equiv{}^k[^0\Omega_i]= {}^k_0R[^0\Omega_i]={}^k_0R\cdot\omega_i \end{align}$$

Velocity of link *i+1* computed and represented relative to the base {0}:

$${}^0\Omega_{i+1}={}^0\Omega_{i}+{}^0_iR{}^i\Omega_{i+1}$$

then converted to frame {*i+1*}:

$${}^{i+1}\omega_{i+1}={}^{i+1}\omega_{i}+{}^{i+1}_iR{}^i\Omega_{i+1}={}^{i+1}_iR{}^i\Omega_{i}+\dot{\theta}_{i+1}{}^{i+1}\hat{Z}_{i+1}$$

- ${}^{i+1}\omega_{i+1}$ , Angular velocity of frame {*i+1*} **measured** relative to therobot base, and **expressed** in frame {*i+1*}
- ${}^{i+1}\omega_{i}$, Angular velocity of frame {*i*} **measured** relative to the robot base, and **expressed** in frame {*i+1*}
- ${}^{i+1}_iR{}^i\Omega_{i+1}$, Angular velocity of frame {*i+1*} **measured** relative to frame{*i*} and **expressed** in frame {*i+1*}

**conclusion**

$0\longrightarrow i+1$

$$\begin{align} v_{i+1}&=v_i+[\varepsilon_{i+1} Z_{i+1}\dot{q}_{i+1}+\bar{\varepsilon_{i+1}}\cdot(\Omega_i\times {}^iP_{i+1})] \\ \omega_{i+1}&=\omega_i+\bar{\varepsilon_i}\cdot\Omega_{i+1}, \quad where \quad \Omega_{i+1}=\dot{q}_{i+1} Z_{i+1}\end{align}$$

$i+1 \longrightarrow i+1$

$$\begin{align}{}^{i+1}v_{i+1}&={}^{i+1}_iR({}^iv_i+{}^i\omega_i\times {}^iP_{i+1})+\varepsilon_{i+1} {}^{i+1}Z_{i+1}\dot{q}_{i+1} \\ {}^{i+1}\omega_{i+1}&={}^{i+1}_iR{}^i\Omega_{i}+\bar{\varepsilon}_{i+1}\dot{q}_{i+1}{}^{i+1}Z_{i+1}  \end{align}$$

## kinematic singularity

**singularity**: the effector locality loses the ability to move in a direction or to rotate about a direction.

If jacobian is nonsingular, then we can invert it to calculate joint rates from given cartesian velocities: $$\dot{\Theta}=J^{-1}\upsilon$$

奇异点会降低$J$的秩。

singular configuration: det(J)=0

**cross product operator in diff. frames**

$$^0P\times^0\omega=^0_nR\cdot(^nP\times^n\omega)$$

$$^0\hat{P}^0\omega=^0_nR\cdot(^n\hat{P}^n\omega)=^0_nR\cdot^n\hat{P}(^0_n{R^T} ^0\omega)$$

$$^0\hat{P}=^0_nR\hat{^nP}^0_n{R^T}$$



##velocity/force duality

$$\dot{x}=J\dot{\theta}\\ \tau=J^TF$$

**静力传递**

$$^if_i=^i_{i+1}R^{i+1}f_{i+1}\\^in_i=^i_{i+1}Rn_{i+1}+^iP_{i+1}\times ^if_i$$

- $^if_i$表示第i-1个连杆对连杆i的作用力，可以认为是对joint i的作用力
- 低阶连杆对本连杆的作用力等于高阶连杆对本连杆的作用力，低阶连杆对本连杆的力矩等于高阶连杆对本连杆的力矩和高阶坐标系原点在本坐标系的向量与力的叉积。

**All components of the force and moment vectors are resisted by the structure of the mechanism itself, except for the torque about the joint axis.** To find the joint torque requied to maintain the static equilibrium, the dot product of the joint-axis vector with the moment vector acting on the link is computed:

$$\tau_i=^in_i^T\cdot{}^iZ_i$$

In the case that joint i is prismatic, the joint actuator force is:

$$\tau_i=^if^T_i\cdot^iZ_i$$

 **cartesian transformation**

$$\begin{bmatrix}^A\nu _A\\^A\omega _A \end{bmatrix}=\begin{bmatrix}^A_BR&^AP_{BORG}\times ^A_BR\\0&^A_BR \end{bmatrix}\begin{bmatrix}^B\nu _B\\^B\omega _B \end{bmatrix}$$

$$\begin{bmatrix}^AF_A\\^AN _A \end{bmatrix}=\begin{bmatrix}^A_BR&0\\^AP_{BORG}\times ^A_BR&^A_BR \end{bmatrix}\begin{bmatrix}^BF _B\\^BN _B \end{bmatrix}$$










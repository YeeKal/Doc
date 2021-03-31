##acceleration

**线加速度**

动点在相对坐标系B中的运动，变换到坐标系A中的表达式：

$$^AV_Q=^AR_B{}^BV_Q+{}^AV_{BORG}+{}^A\Omega _B\times {}^AR_B{}^BQ$$
$$\begin{align}\frac{d({}^AV_{BORG})}{dt}&={}^A\dot{V}_{BORG} \\ \frac{d({}^AR_B{}^BV_Q)}{dt}&=^AR_B{}^B\dot{V}_Q+{}^A\Omega _B\times ^AR_B{}^BV_Q \\ \frac{d({}^A\Omega _B\times {}^AR_B{}^BQ)}{dt}&= {}^A\dot{\Omega} _B\times {}^AR_B{}^BQ+{}^A\Omega _B\times ({}^A\Omega _B\times {}^AR_B{}^BQ+{}^AR_B{}^BV_Q+{}^AV_{BORG}) \end{align}$$

其中叉积的性质：

$$\frac{d(a\times b)}{dt}=\frac{da}{dt}\times b+a\times \frac{db}{dt}$$

in revolute joint:

$$^A\dot{V}_Q={}^A\dot{\Omega} _B\times {}^AR_B{}^BQ+{}^A\Omega _B\times {}^A\Omega _B\times {}^AR_B{}^BQ$$

in prismatic joint:

$$^A\dot{V}_Q={}^A\dot{V}_{BORG}+{}^A\dot{\Omega} _B\times {}^AV_{BORG}$$

**角加速度**

$${}^A\Omega_C={}^A\Omega_B+{}^A_BR{}^B\Omega_C  \\ {}^A\dot{\Omega}_C={}^A\dot{\Omega}_B+{}^A_BR{}^B\dot{\Omega}_C+ {}^A\Omega_B\times {}^A_BR{}^B\Omega_C$$

## rigid body dynamics

**linear momentum**

$$\psi=mv \\ \frac{d\psi}{dt}=F$$

**angular momentum**(角动量/动量矩)

$$p\times m\dot{v}=p\times F=N$$(moments, 力矩)

$$\phi=p\times mv$$

刚体定轴转动：

$$\phi=\int_Vp\times(\omega\times p)\rho d\nu$$

$$p\times(\omega\times p)=p\times(-p)\times \omega=\hat{p}(-\hat{p})\omega$$

so: 

$$\phi=\int\hat{p}(-\hat{p})\rho d\nu\cdot\omega=I\omega$$ ($I$, **inertia tensor**)

**Newton equation and Euler equation**

$$\begin{align}\dot{\psi}&=F \\ F&=ma \\ \dot{\phi}&=N \\ N&=I\dot{\omega}+\omega\times I\omega \end{align}$$（此处请注意对角动量的求导，对惯性张量**I**的求导）

**inertia tensor**

$$\begin{align}I&=\int_V\hat{p}(-\hat{p})\rho d\nu \\&=\int_V((p^Tp)E_3-pp^T)\rho d\nu \end{align}$$

*parallel axis theorem*

$p_C$为坐标系C原点在坐标系A中的坐标。

$$I_A=I_C+M[(p_C^Tp_C)E_3-p_Cp_C^T]$$

##Newton-Euler algorithm

$$F_i=m\dot{v}_{c_1} \\ N_i={}^{C_i}I\dot{\omega}_i+\omega_i\times {}^{C_i}I\omega_i $$

where the origin of frame{$C_i$} is at the center of the body, with the same orientation as frame{i}.

![newton-euler algorithm](imgs/newton_euler.png)

由关节位置，速度和加速度计算所需的关节力矩。

## 动力学方程的结构

**state space equation**

$$\tau=M(q)\ddot{q}+V(q, \dot{q})+G(q)$$

**configuration space equation**

$$\tau=M(q)\ddot{q}+B(q)[\dot{q}\dot{q}]+C(q)[\dot{q}^2]+G(q)$$

##Lagrange equation

$$L=K-U$$(kinetic energy-potential energy)

$$\frac{d}{dt}\frac{\partial L}{\partial \dot{q}}-\frac{\partial L}{\partial q}=\tau$$

$$\frac{d}{dt}\frac{\partial K}{\partial \dot{q}}-\frac{\partial K}{\partial q}+\frac{\partial U}{\partial q}=\tau$$

kinetic energy: $K=\sum_iK_i=\sum_i(\frac{1}{2}m_i\upsilon^T_{C_i}\upsilon_{C_i}+\frac{1}{2}{}^i\omega^T_i {}^{C_i}I_i\omega_i )=\frac{1}{2}\dot{q}^TM(q)\dot{q}$

$$\frac{\partial K}{\partial \dot{q}}=M(q)\dot{q} \\ \frac{d}{dt}\frac{\partial K}{\partial \dot{q}}=\frac{d}{dt}(M\dot{q})=M\ddot{q}+\dot{M}\dot{q}$$

$$\begin{align}\frac{d}{dt}\frac{\partial K}{\partial \dot{q}}-\frac{\partial K}{\partial q}&=M\ddot{q}+\dot{M}\dot{q}-\frac{1}{2}\begin{bmatrix}\dot{q}^T\frac{\partial M}{\partial q_1}\dot{q}\\ \vdots \\ \dot{q}^T\frac{\partial M}{\partial q_n}\dot{q}\end{bmatrix}\\ &=M\ddot{q}+V(q, \dot{q}) \end{align}$$



kinetic energy: work done by external forces to bring the system from rest to its current state.










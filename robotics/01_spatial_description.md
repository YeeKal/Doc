## 运动状态的描述

**world frame**: 世界坐标系，A

**body frame:** 固定于刚体本身的坐标系，B，随刚体的运动而运动

因此坐标系B在坐标系A中的状态表征了刚体的位姿（位置和姿态，平移和旋转）。若A，B原点相同即没有平移，则B中单位基向量相对于A中基向量：$[x_B\quad y_B \quad z_B]=R[x_A\quad y_A \quad z_A]$ ，P被称为**rotation matrix**，denoted as  $_{\mathcal{B}}^{\mathcal{A}}R$ 。则同一个点在A中坐标$^{\mathcal{A}}P$与在B中坐标$^{\mathcal{B}}P$关系：

$$^{\mathcal{A}}P=_{\mathcal{B}}^{\mathcal{A}}R^{\mathcal{B}}P \\$$ 

R若考虑平移，设B中原点在A中坐标$^{\mathcal{A}}P_{B_0}$, 则状态变换：

$$^{\mathcal{A}}P=_{\mathcal{B}}^{\mathcal{A}}R^{\mathcal{B}}P +^{\mathcal{A}}P_{B_0} \\$$ 

**rotation matrix**

![rotation_matrix.PNG](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/robotics/imgs/rotation_matrix.PNG)

旋转矩阵充要条件：

- $R^TR=I$
- $det(R)=1$

旋转矩阵实质就是基变换矩阵，并且

- $_{\mathcal{B}}^{\mathcal{A}}R=_{\mathcal{A}}^{\mathcal{B}}R^T$
- 是正交矩阵

由列向量单位长度且正交（6个条件），故矩阵只有3个自由度。

正交矩阵不一定是旋转矩阵？

## rotation matrix与转角

旋转矩阵定义了刚体姿态的变化，但如何将旋转矩阵与转角相关联则是更加直观理解位姿变化的过程。

**fixed angles**

X-Y-Z 固定角描述

由angles推算R：先绕X轴转$\gamma$, 再绕Y轴转$\beta$, 再绕Z轴转$\alpha$ ，则综合后的旋转矩阵: 

$$R=R_Z(\alpha)R_Y(\beta)R_X(\gamma) \\$$

由R推算angles：

$$\begin{align} \beta=&Atan2(-r_{31},\sqrt{r_{11}^2+r_{21}^2}) \\\alpha=&Atan2(r_{21}/c \beta ,r_{11}/c\beta) \\\gamma=&Atan2(r_{32}/c\beta,r_{33}/c\beta) \end{align} \\$$

上式成立为$\beta \ne \pm90^0$.其中$atan2(y,x)=atan(y/x)$.

**euler angles**

Z-Y-X

再绕Z'轴转$\alpha$,再绕Y'轴转$\beta$,先绕X'轴转$\gamma$,  ，则综合后的旋转矩阵:

$$B=R_X^{-1}R_Y^{-1}R_Z^{-1}=A, A=R_Z(\alpha)R_Y(\beta)R_X(\gamma)B \\$$

$$R=R_Z(\alpha)R_Y(\beta)R_X(\gamma) \\$$

这与fixed angles表达式相同，只是操作步骤不同。

Z-Y-Z

$$\begin{align} \beta=&Atan2(\sqrt{r_{31}^2+r_{32}},r_{33}) \\\alpha=&Atan2(r_{23}/s \beta ,r_{13}/s\beta) \\\gamma=&Atan2(r_{32}/s\beta,-r_{31}/s\beta) \end{align} \\$$

$\beta \ne 0$



同一个rotation matrix有不同的拆解方式。一共有12种euler angles和12种fixed angles，这些都被称为角坐标系表示法。

**angle axis**（轴角坐标）

绕一个轴（方向，2dof）旋转一个角度（1dof）。

[rodrigues formula](http://electroncastle.com/wp/?p=39)

$$R=I+[n]_\times\sin\psi+[n]_\times^2(1-\cos\psi)\\=\left[ \begin{matrix} \cos \psi + w_1^2(1-\cos\psi) & w_1w_2(1-\cos \psi) & w_2 \sin \psi \\ w_1w_2(1-\cos \psi) & \cos \psi + w_2^2(1-\cos \psi) & -w_1 \sin \psi \\ -w_2 \sin \psi & w_1 \sin \psi & \cos \psi \end{matrix} \right] \\ n=(w_1,w_2,w_3)\quad |n|=1$$

where:

$$[n]_\times=\begin{bmatrix}0 & -n_3 & n_2\\n_3 & 0 &-n_1\\-n_2 & n_1 & 0\end{bmatrix}, \quad [n]_\times^2=\begin{bmatrix}-{n_3}^2-{n_2}^2 & n_1n_2 & n_1n_3\\n_1n_2 & -{n_3}^2-{n_1}^2&n_2n_3\\n_1n_3 & n_2n_3 &-{n_2}^2-{n_1}^2\end{bmatrix}$$

$[n]_{\times}$: the skew-symmetric matrix.

A more concize form:

$$R=e^{[n]\times\psi}$$

angles: $\psi=cos^{-1}(\frac{tr(R)-1}{2})$

rotation angle: $[n]_\times=\frac{R-R^T}{2sin(\psi)}$,   $n=[-[n]_\times(2,3),[n]_\times(1,3),-[n]_\times(1,2)]$

向量是可以移动的，而轴的描述除了方向矢量还应有一个过定点的位移约束。轴不一定经过原点，设点$P=[x_p, y_p, z_p]$ .为了保证旋转是依照原点旋转，可先将坐标系移动$-P$，denoted as $^{-P}T$, 形成相对于原点的$P$, 旋转($^{\theta}T$), 再移动$P(^PT)$, 故：

$$^A_BT=^PT^{\theta}T^{-P}T \\$$

**quaternion表达法**

[kwə'tɝnɪən], 四元数， 复数在三维的推广，是一种新定义的数学表达形式。形式为：

$$q=w+xi+yj+zk$$

其中$i,i,k$是-1在三维中的平方根。四元数与旋转的关系：

$$q=(x,y,z,w)=(\vec v, w )=(\vec n \cdot sin\frac{\theta}{2}, cos\frac{\theta}{2})$$

即若以这样的对应关系，则旋转矩阵的存储与计算会有极大的方便。因此四元数对旋转矩阵的表示可以认为是定义了一种对应关系：

$$R(q)=\begin{bmatrix}1-2(y^2+z^2)&2(xy-zw)&29xz+yw)\\2(xy+zw)&1-2(x^2+z^2)&29yz-xw)\\2(xz-yw)&2(yz+xw)&1-2(x^2+y^2) \end{bmatrix} \\$$

*conversion matrix to quaternion*

the basic form($1+tr>0$):

$$\begin{align} q_0 &= \frac {\sqrt{1+r_{11}+r_{22}+r_{33}}}{2}\\q_1&= \frac {r_{32}-r_{23}}{4q_0}  \\q_2 &= \frac {r_{13}-r_{31}}{4q_0}\\ q_3 &= \frac {r_{21}-r_{12}}{4q_0}\end{align} $$

if $1+tr<0$:

1. $r_{11}>r_{22},r_{33}$:

   $$\begin{align} S&= \sqrt{1+r_{11}-r_{22}-r_{33}}\\q_0&=\frac{r_{32}-r_{23}}{S}\\q_1&= \frac {S}{4}  \\q_2 &= \frac {r_{12}+r_{21}}{S}\\ q_3 &= \frac {r_{13}+r_{31}}{S}\end{align} $$

2. $r_{22}>r_{11},r_{33}$

   $$\begin{align} S&= \sqrt{1-r_{11}+r_{22}-r_{33}}\\q_0&=\frac{r_{13}-r_{31}}{S}\\q_1 &= \frac {r_{12}+r_{21}}{S}\\q_2&= \frac {S}{4}  \\ q_3 &= \frac {r_{23}+r_{32}}{S}\end{align} $$

3. $r_{33}>r_{11},r_{22}$

   $$\begin{align} S&= \sqrt{1-r_{11}-r_{22}+r_{33}}\\q_0&=\frac{r_{21}-r_{12}}{S}\\q_1 &= \frac {r_{13}+r_{31}}{S} \\ q_2 &= \frac {r_{23}-r_{32}}{S}\\q_3&= \frac{S}{4}\end{align} $$

## 齐次坐标

$$_{\mathcal{B}}^{\mathcal{A}}T=\begin{bmatrix}_{\mathcal{B}}^{\mathcal{A}}R & ^{\mathcal{A}}P_{B_0} \\0&1 \end{bmatrix} \\$$

$$^{\mathcal{A}}P=_{\mathcal{B}}^{\mathcal{A}}T \cdot ^{\mathcal{B}}P \\$$

(先转动后移动)

不同坐标系中点的变换/同一坐标系中点的变换

## 连续运算

$$^{\mathcal{A}}P=_{\mathcal{B}}^{\mathcal{A}}T \cdot _{\mathcal{C}}^{\mathcal{B}}T \cdot^{\mathcal{C}}P \\$$


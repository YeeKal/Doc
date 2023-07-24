## Quaternion

[kwə'tɝnɪən], 四元数， 复数在三维的推广，是一种新定义的数学表达形式。形式为：

$$q=w+xi+yj+zk$$

其中$i,i,k$是-1在三维中的平方根。

**四元数表示空间中的点**

笛卡尔坐标：$[x,y,z]$.则对应四元数$q=xi+yj+zk$,又称为纯四元数，即实部为0的四元数。

**四元数表示三维旋转**

$$q=(x,y,z,w)=(\vec v, w )=(\vec n \cdot sin\frac{\theta}{2}, cos\frac{\theta}{2})$$

q为单位四元数。即若以这样的对应关系，则旋转矩阵的存储与计算会有极大的方便。因此四元数对旋转矩阵的表示可以认为是定义了一种对应关系：

$$R(q)=\begin{bmatrix}1-2(y^2+z^2)&2(xy-zw)&29xz+yw)\\2(xy+zw)&1-2(x^2+z^2)&29yz-xw)\\2(xz-yw)&2(yz+xw)&1-2(x^2+y^2) \end{bmatrix} \\$$

**四元数运算**

若将四元数视为纯量-向量的形式，则定义四元数加法(adding)：
$$q_1+q_2=(a1+v_1)+(a_2+v_2)=a1+a_2+v_1+v_2$$
四元数乘法(multiplication)：
$$q_1q_2=(a1+v_1)(a_2+v_2)=a_1a_2-v_1\cdot v_2+(a_1v_2+a_2v_1+v_1\times v_2)$$
四元数乘法公式可以根据虚数单位的基本共式推导出来，所以上式仅有形式上的意义而不具备几何意义。四元数乘法表示两个旋转矩阵相乘。
$$q^*=a-v \\
|q|=\sqrt{a^2+||v||^2} \\
q^{-1}=a-v$$
仿照单位复数与欧拉公式：
$$e^{\frac{\theta}{2}(xi+yj+zk)}=cos\frac{\theta}{2}+(xi+yj+zk)sin\frac{\theta}{2}, \text{for x,y,z}\in \mathbb{R} \ s.t. x^2+y^2+z^2=1$$
$$log(q)=\frac{\theta}{2}(xi+yj+zk)$$
**四元数的旋转变换**

设 q 为一个单位四元数，而 p 是一个纯四元数，则：
$$R_q(p)=qpq^{-1}$$
也是一个纯四元数，代表空间的点p经过旋转变换q之后的四元数表示。故：
$$R_{q_1q_2}(p)=q_1q_2pq_2^{-1}q_1^{-1}=R_{q_1}(R_{q_2}(p))$$

## dual quaternion

$$q=q_r+\epsilon q_d,\ where\ \epsilon^2=0$$
或者通过上三角冒表示对偶四元数：
$$\hat{q}=q+\epsilon q_{\epsilon}$$

Like the quaternion,the unit dual-quaternin is our key concern as it can represent any rigid rotational and translational transformations.
$$q_r=r \\
q_d=\frac{1}{2}tr$$
where r is a unit quaternion representing the rotation and t is the quaternion describing the translation.

**<font color='Tomato'>Operation</font>**

- scalar: $aq=aq_r+a\epsilon q_d$
- multiplication: $q_1+q_2=q_{r1}+q_{r2}+\epsilon (q_{d1}+q_{d2})$
- conjugate: $q^*={q_r}^*+\epsilon {q_d}^*$
- unit condition:$||q||=1,\quad {q_r}^*q_d+{q_d}^*q_r=0$

**<font color='Tomato'>空间变换</font>**

$$Trans(p)=qpq^*$$

**the logarithmic **

[Kinematic Control of Free Rigid Bodies Using Dual Quaternions]()

Assume $q_r=\frac{cos\phi}{2}+\frac{sin\phi}{2}n$,$q_t=ps$, where **n** and **s** is vector, **p** is the scalar of $q_t$.
$$q=q_r+\epsilon q_t \\
log(q)=\frac{1}{2}\phi n+\epsilon \frac{1}{2}p s \\
||log(q)||=\sqrt{<log(q),log(q)>} \\
<log(q),log(q)>=log(q)\dot log(1)^T=\frac{|\phi|^2+2\epsilon\phi cos\alpha}{4} ,\ \alpha\ is\ the\ angle\ between\ n\ and \ s  \\$$

define: $$ \mathcal{R}(q)=2||log(q)||=|\phi|+\epsilon|pcos\alpha| $$
the difference of two dual quaternion:
$$e_{12}=q_1q_2^*$$
the distance of two dual quaternion:
$$\mathcal{D}(q_1,q_2)=\mathcal{R}(e_{12})$$

## Ref

- [PyXYZ with quaternion](https://github.com/VideojogosLusofona/PyXYZ/tree/main)
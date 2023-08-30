欧式空间是具有了内积的线性空间

流形：几何曲面的统称

拓扑结构：数学结构

我们可以用一组向量来完全描述机器人的空间状态，所有这组向量的集合便是 C-Space 

流形实际是一种数学结构。（？）学习这种结构可以找到不同空间中的统一规律。是局部具有欧几里得空间性质的空间,要求局部“看起来像”简单的空间.

数据实际上是由一个低维流形由于内部特征的限制映射到高维空间上的，这样就产生了维度的冗余。一次需要通过一定的手段找到内部特征从而降低维度。

**嵌入到高维空间的低维流形**。比如三维空间的球面，由于球的特征限制导致这些三维中的点只需要两个维度就可以表示，比如地球的经纬度。所以可以说球面是一个嵌在三维空间的二维流形，同理圆是嵌在二维空间的一维流形。

对于一个六轴机械臂，机器人的可达空间是在三维空间里，但是自由度却有6个，所以C空间是一个嵌在六维空间的三维流形。

数据降维基于一个假设： 数据分布在一个低维的流形上。降维是在保持测地距离的同时展开一个流形。

**测地线距离**就是用两点之间图上的最短距离来近似的，这方面的算法是一般计算机系中用的图论中的经典算法

- isomap：全局
- mds
- 离散模型：图
- lle: 局部

**Cartesian product**

a [Cartesian product](https://en.wikipedia.org/wiki/Cartesian_product) is a mathematical operation that returns a set (or product set or simply product) from multiple sets:
$$A\times B=\{(a,b)|a\in A,b\in B\}$$
**微分流形**

- $E^3$: Euclidean space
- $T^n$: the n-dimensional torus,defined to be the **Cartesian product** of p copies of $S^1$: $$T^p=S^1\times S^1\times \cdots \times S^1$$
- $S^n$: the n-dimesional sphere in $E^{n+1}$
- mobile robot translating int the n-dimension space: $R^n$

- 3-joint revolute in the plane
    - a torus of outer radius: l1+l2+l3
    - c space: $T$^3
- 2-joint revolute with a prismatic joint in the plane
    - disc of radius: l1+l2+l3
    - c space: $T^2\times \mathcal{E}$
- 3-joint revolute arm mouted on a mobile robot(holonomic)
    - sandwitch of radious:l1+l2+l3
    - c space: $\mathcal{E}^2\times T^3$
- 3-joint revolute arm floating in space
    - workspace: $\mathcal{E}^3$
    - c space: $T^3$
- SO(2), 1-dimension (equal s1?)

**representing rotations**

- $S^1$: rotation in the plane
    - $R_{2\times 2}$
- $SE(2)=SO(2)\times \mathcal{R}(2)$:

**李群**

- 群： 一种集合加上一种运算
    - 封闭性(closure)： 运算结果属于群
    - 结合性(associativity)： $(a1\cdot a2)\cdot a3=a1\cdot (a2\cdot a3)$
    - 单位(identity): $a\cdot e=e\cdot a=a$
    - 逆(inverse)：$a\cdot a^{-1}=e$
    - 一般线性群GL(n): nXn可逆矩阵，对矩阵乘法成群
    - 特殊正交群SO(3): 即旋转矩阵，SO(2)/SO(3)
    - 特殊欧式群SE(3)： n维欧式变换，SE(2)/SE(3)
- 李群： 具有连续性质的群
    - 既是群也是流形
    - SO(3)和SE(3)在乘法下代表着物体在空间中的连续运动，都是李群
- 李代数：

##概念区分

- SO(3): 特殊正交矩阵群(special orthogonal group)，旋转矩阵
    - $SO(3)=\{R\in \mathcal{R}^{3\times3}:RR^T=I,detR=1\}$
- so(3): 反对称矩阵$\hat{w}$,是SO(3)的李代数
$$\hat{w}=\begin{bmatrix}0 &-w_3 & w_2 \\w_3 & 0 & -w_1 \\-w_2 & w_1 & 0 \end{bmatrix}$$
- SE(3): 特殊欧式群(special euclidean group)，位形转换
    - $SE(3)=\{(p,R):p\in \mathcal{R}^3,R\in SO(3) \}=\mathcal{R}^3\times SO(3)$
- se(3): SE(3)的李代数，元素叫做旋量(twist)
    - $se(3)=\{(\hat{w},\upsilon)|\hat{w} \in so(3),\upsilon\in \mathcal{R}^3 \}$
- w: 关节转动中心轴的向量表示形式
- $\hat{w}$: 关节转动中心轴的反对称矩阵表示形式
- $\hat{\xi}$: se(3)的矩阵形式：
$$\hat{\xi}=\begin{bmatrix} \hat{w} & \upsilon \\ 0& 0 \end{bmatrix}$$
- $\xi$: $\xi=(\upsilon,w)\in E^6$为$\hat{\xi}$的运动旋量坐标(twist coordination)
- $e^{\hat{xi}\theta}$: 从se(3)到SE(3)的指数变换，对于$\xi\in se(3),\theta\in \mathcal{R}$,
$$e^{\hat{\xi}\theta}=\begin{bmatrix} e^{\hat{w}\theta}& (I-e^{\hat{w}\theta})(w\times \theta)+ww^T\upsilon\theta\\0 &1 \end{bmatrix}$$

**kinematics and inverse kinematics**

**jacobians and velocity relationships**

**sim-to-real**

[基于旋量理论的机器人建模](https://wenku.baidu.com/view/c1b1c4030a4e767f5acfa1c7aa00b52acec79c43.html)


**运动学旋量坐标**

指数积公式

$$\begin{bmatrix}a_0 \\b_0 \end{bmatrix}=\begin{bmatrix}a_1 \\b_1 \end{bmatrix}+\begin{bmatrix}a_2 \\b_2 \end{bmatrix}$$

$$\begin{bmatrix}a_0 \\b_0 \end{bmatrix}=\begin{bmatrix}a_{11} & a_{12}\\b_{21} & b_{22} \end{bmatrix}+\begin{bmatrix}a_2 \\b_2 \end{bmatrix}$$

$$\begin{bmatrix}a_0 \\b_0 \\c_0 \end{bmatrix}=\begin{bmatrix}a_1 \\b_1 \\c_1 \end{bmatrix}+\begin{bmatrix}a_2 \\b_2 \\c_2\end{bmatrix}$$

$$RR^T=I\\
\dot{R}R^T+R\dot{R}^T=0  \\
\dot{R}R^T=-(\dot{R}R^T) \\
\dot{R}R^T=\hat{w}   \\
\dot{R}=\hat{w}R  \\
$$

$$w=\begin{bmatrix}w_1\\w_2 \\w_3\end{bmatrix}\in \mathcal{R}^3  \\
w\times a=\hat{w}a  \\
\hat{w}: 斜对称矩阵\text{(skew-symmetric matrix)}
$$

$$R=\begin{bmatrix}r_{11} &r_{12} &r_{13} \\
r_{21} &r_{22} &r_{23} \\r_{31} &r_{32} &r_{33} \\ \end{bmatrix}$$





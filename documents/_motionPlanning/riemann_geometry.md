---
title: Riemann geometry
categories: manifold
tags: manifold
date: 2019-08-26
---

- $M$：维度为m的光滑流形
- $p\in M$: 存在一个邻域$U$微分同胚(diffeomorphic)于$R^m$
- 流形M嵌入在n维空间中$\{x_1,x_2,\dots,x_n\}$，其参数方程为$X(u_1,u_2,\cdots,u_m)$
$$X(u_1,u_2,\cdots,u_m)=\begin{bmatrix} x_1=f_1(u_1,u_2,\cdots,u_m) \\ x_2=f_2(u_1,u_2,\cdots,u_m) \\ \cdots \\x_n=f_n(u_1,u_2,\cdots,u_m) \end{bmatrix} ^T$$
- $T_pM$: 切空间, spanned by the vector:
$$\{X_{u_1},X_{u_2},\cdots,X_{u_m}\}=\begin{bmatrix} \frac{\partial x_1 }{\partial u_1} & \frac{\partial x_1 }{\partial u_2} & \cdots &\frac{\partial x_1 }{\partial u_m} \\  \frac{\partial x_2 }{\partial u_1} & \frac{\partial x_2 }{\partial u_2} & \cdots &\frac{\partial x_2 }{\partial u_m} \\  \cdots & \cdots & \cdots &\cdots \\ \frac{\partial x_n }{\partial u_1} & \frac{\partial x_n }{\partial u_2} & \cdots &\frac{\partial x_n }{\partial u_m} \end{bmatrix}$$
- 几个坐标系，原本的坐标系$R^n$, 参数化坐标系$R_m$, 局部坐标系$R^m=X_{u_1} \otimes X_{u_2}\otimes \cdots \otimes X_{u_m}$

**实例**
 $R^3$中单位球面可如下参数化：
 $$X(u,v)=\begin{bmatrix} \cos u \sin v \\ \sin u \sin v \\\cos v \end{bmatrix},(u,v)\in [0,2\pi)\times [0,\pi)$$

 $X(u,v)$分别对$u$和$v$微分得到：
 $$X_u=\begin{bmatrix} -\sin u sin v \\ \cos u \sin v \\0 \end{bmatrix},X_v=\begin{bmatrix} \cos u cos v \\ \sin u \cos v \\-\sin v \end{bmatrix}$$

## First Fundamental Form(第一基本形式)

第一基本形式表示曲面切空间的内积，用罗马字母$I$来表示。
$$I<p,q>=<p,q>$$

设$X(u,v)$是一个参数曲面，则两个切向量的内积为：
$$\begin{align} &I<p,q> \\
                &=I(aX_u+bX_V,cX_u,dX_v)     \\
                &=ac<X_u,X_u>+(ad+bc)<X_u,X_v>+(bd)<X_v,X_v>  \\
                &=Eac+F(ad+bc)+Gbd
\end{align}$$

其中$p,q$可以看作是切空间的基的系数向量，则第一基本形式可以写成矩阵的形式：
$$I<p,q>=p^T \begin{bmatrix}E & F \\F & G \end{bmatrix}q$$

第一基本形式写成现代记法的度量张量系数：
$$g=(g_{ij})=\begin{bmatrix} g_{11} & g_{12}\\ g_{21} &g_{22} \end{bmatrix}, g_{ij}=X_i \cdot X_j(切向量的点积)$$

其一般形式：
$$G=g_{uv}=J^TJ=(\frac{\partial x}{\partial u})^T(\frac{\partial x}{\partial u})$$

即度量张量系数事实上通过切向量的点积定义了切空间各个向量基的内积的矩阵系数，通过这一矩阵系数可以定义基于内积的一些度量形式，比如长度，角度，面积。


## metric tensor(度量张量)

**长度**

度量张量： 黎曼度量实质是二阶张量，是协变分量。

选定一坐标系统$x^u$($x^u$表示为在切空间第$u$个基向量$X_u$的系数)：
$$\begin{align}ds^2&=<ds,ds> \\
                &=<\sum_{u=1}^{u=m}X_udx^u,\sum_{u=1}^{u=m}X_udx^u> \\
                &=\sum_{uv}<X_u,X_v>dx^udx^v    \\
                &=\sum_{uv}g_{uv}dx^udx^v
\end{align}$$



根据优化任务的不同，可以分别以轨迹弧长和系统动能作为黎曼度量，它们决定了不同的黎曼曲面，曲面上的测地线分别对应于路径最短和能量最小。

**角度**

两个切向量$u,v$的夹角：
$$\cos \theta=\frac{<u,v>}{|u||v|}=\frac{\sum_{ij}g_{ij}u^iv^j}{\sqrt{|\sum_{ij}g_{ij}u^iu^j||\sum_{ij}g_{ij}v^iv^j|}}$$


**面积**

以$R^3$中的二位曲面为例：
$$dA=|X_u \times X_v|dudv=\sqrt{<X_u,X_u><X_v,X_v>-<X_u,X_v>^2}dudv$$

拉格朗日恒等式：
$$(a\times b) (a\times b)=(a\cdot a)(b \cdot b)-(a\cdot b)^2$$

## tensor
 
- 多维数组： 数组的阶数为张量的阶数。向量为一阶，矩阵为二阶。
- 张量由向量和余向量(covector)通过张量积(tensor product)组合而成
- 张量是多重线性映射，矢量空间/对偶空间

对于坐标系A，B，坐标基矩阵为$E_A,E_B$, 某一向量在不同坐标系下的表示为$P_A,P_B$.

$$\begin{align} E_B&=C\cdot E_A \\
                D&=C^{-1}       \\
                \vec{P_B}&=D\cdot \vec{P_A}
\end{align}$$

以基变换为基准，变化相同的为协变量(covariant)，相反的为逆变量(contravariant).

$$协变量=\left\{\begin{align}\vec e_{Bj}&=\sum_{i=1}^n c_{ij}\vec e_{Ai} \\
\vec e_{Bj}&= c_{ij}\vec e_{Ai} 
\end{align} \right . $$
$$逆变量=\left\{\begin{align} P_{B}^i&=\sum_{j=1}^n d_{ij}\vec P_{A}^j \\
P_{B}^i&= d_{ij}\vec P_{A}^j
\end{align} \right .$$

[张量”专题之二](https://www.matongxue.com/madocs/692.html)


## geodesic equation

$$\frac{d^2\theta_i}{ds^2}+\sum_{k=1}^{m}\sum_{j=1}^m\Gamma_{kj}^i\frac{d\theta_k}{ds}\frac{d\theta_j}{ds}=0$$

$$\Gamma_{kj}^i=\frac{1}{2}\sum_{n=1}^mg^{ni}(\frac{\partial g_{kn}}{\partial\theta_j}+\frac{\partial g_{jn}}{\partial\theta_k}-\frac{\partial g_{kj}}{\partial\theta_n})$$

- $\Gamma^i_{kj}$: 克里斯托费尔（Christoffel）符号,联络系数
- $g^{ij}$: $g_{ij}$的逆矩阵元素

[测地线](https://spaces.ac.cn/archives/3977)

机器人轨迹规划：给出关节空间初始条件，以任务空间的约束，求出最优化轨迹。

- [first fundamental form](https://howlingpixel.com/i-en)
    - inner product
    - metric
    - area
- [second fundamental form](https://howlingpixel.com/i-en/Second_fundamental_form)
    - curvature

## Second Fundamental Form(第二基本形式)

**平面曲线曲率**
- $k$: 曲率
- $\rho$: 曲率半径
- $\alpha$: 切线角
- $s$: 曲线长度
$$k=\frac{d\alpha}{ds}$$

对一平面曲线方程：$y=f(x)$
$$\tan \alpha=y'    \\
 d \alpha=\frac{y''}{1+y'^2}dx    \\
 d s^2=(1+y'^2)dx       \\
 k=\frac{y''}{(1+y'^2)^{\frac{3}{2}}}
 $$

 曲率还可以有另一种解释。以当前点为P新坐标的原点，沿切线为X轴，则P处导数为0.则曲率为$y''(0)$. 此时$y=f(x)$的taylor展开为：$y=\frac{1}{2}f''(0)x^2+\cdots$

 则曲率：
 $$k=f''(0)=\lim_{x\rightarrow 0}\frac{2y}{x}$$

**空间曲线曲率**

一$R^3$空间曲线由参数方程给出：
$$\vec{r}(t)=\{x(t),y(t),z(t)\}$$

空间曲线曲率的一般参数表达式：
$$k=\frac{||\dot {\vec{r}} \times \ddot{\vec{r}||}}{||\dot{\vec{r}}||^3}$$

**空间曲面曲率**

一$R^3$空间曲面，其中的一点p。p处存在唯一的切平面，以及无数个相互垂直的法平面，但存在一组相互垂直的法平面，使得与曲面交线形成的曲线的曲率有最大值$k_1$和最小值$k_2$，这两个曲率被称为主曲率。反之，当曲率取最大与最小值的两个法平面方向总是垂直的，这是欧拉在1760年的一个结论，称之为主方向。

- 高斯曲率：$K=k_1k_2$
- 平均曲率：$H=\frac{k_1+k_2}{2}$
- 任意方向曲率： $k_\theta=k_1\cos^2 \theta +k_2 \sin^2 \theta$, $\theta$为到主平面夹角
$$H=\frac{1}{2\pi}\int_{-\pi}^{\pi}k_{\theta}d\theta$$

**第二基本形式**

设$r(u,v)$是$R^3$中的参数曲面，$r_u,r_v$为偏导数（切空间的正交向量），则单位法向量：
$$n=\frac{r_u\times r_v}{|r_u\times r_v|}$$

经典形式的视角来看，第二基本形式表示弧长在法向量方向上的投影：
$$<dr^2,n>=<\frac{\partial^2 r}{\partial u^2},n>\dot{u}^2+<\frac{\partial^2 r}{\partial u \partial v},n>\dot{u}\dot{v}+<\frac{\partial^2 r}{\partial v^2},n>\dot{v}^2$$

张量形式的视角的第二基本形式：
$$II=Ldu^2+2Mdudv+Ndv^2\\
L=r_{uu}\cdot n, M=r_{uv}\cdot n, N=r_{vv}\cdot n$$
$$[II]=\begin{bmatrix}L &M \\M &N \end{bmatrix}$$
若$r_u,r_v$为主方向，则$[II]$为对角阵。

$R^3$中的高斯曲率可以表示为第二基本形式和第一基本形式行列式的商：
$$k_1=\frac{L}{E}   \\
k_2=\frac{N}{G}         \\
 k_H=\frac{EN-2FM+GL}{2(EG-F^2)}   \\
K=\frac{det() II)}{det(I)}=\frac{LN-M^2}{EG-F^2}$$

## book

- [黎曼几何引论 陈维桓 8.0](https://book.douban.com/subject/1231151/)
- [黎曼几何初步-伍鸿熙-9.3](https://book.douban.com/subject/1110681/)
- [黎曼几何-彼得森-9.8](https://book.douban.com/subject/2013529/)

## reference

- [黎曼几何-王作勤](https://www.icourse.club/course/12637/)
- [博客](http://blog.sina.com.cn/s/blog_3dc397910102yajh.html)
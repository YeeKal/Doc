---
title: differential geometry
categories: manifold
tags: manifold
date: 2019_06_16
---

- 几何：与变换无关
- 群：变换
- 欧式几何： 刚性变换（平移，旋转，反射，...）
- 仿射几何： 一般的线性变换
- 黎曼几何： 与任意变换无关

## 基本约定

爱因斯坦求和约定：1. 重复两次的指标是求和的哑指标; 2. 出现一次的指标和本次运算没有什么关系; 3. 下标表示协变量，上标表示逆变量

$$a_ib_i=\sum_{i=1}^na_i\cdot b_i       \\
a_{ij}b_j=\sum_{j=1}^na_{ij}\cdot b_i$$


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


## metric

度量张量： 黎曼度量实质是二阶张量

选定一坐标系统x,度量张量为二阶张量：
$$ds^2=\sum_{uv}g_{uv}dx^udx^v$$
$$ds^2=\sum_{i=1}^m\sum_{j=1}^{m}g_{ij}(u)du_idu_j$$
协变分量,度量系数矩阵：
$$G=g_{uv}=J^TJ=(\frac{\partial x}{\partial u})^T(\frac{\partial x}{\partial u})$$

根据优化任务的不同，可以分别以轨迹弧长和系统动能作为黎曼度量，它们决定了不同的黎曼曲面，曲面上的测地线分别对应于路径最短和能量最小。

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

## book

- [黎曼几何引论 陈维桓 8.0](https://book.douban.com/subject/1231151/)
- [黎曼几何初步-伍鸿熙-9.3](https://book.douban.com/subject/1110681/)
- [黎曼几何-彼得森-9.8](https://book.douban.com/subject/2013529/)

## reference

- [黎曼几何-王作勤](https://www.icourse.club/course/12637/)
- [博客](http://blog.sina.com.cn/s/blog_3dc397910102yajh.html)
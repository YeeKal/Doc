---
title: 矩阵分解
categories: engineer
tags: matrix
description: 矩阵分解概要
---
## LU分解

定义 ：$A\in F_{n\times n}$，如果存在**单位下三角**矩阵$L$和上三角矩阵$U$使得$A=LU$，则被称为$A$的$LU$分解（三角分解）。

求解线性方程组进行高斯消元法时，可以通过左乘初等矩阵（第三种初等变换，倍乘加和）把主元以下元素化为0，可以看作上三角矩阵U。左乘的初等矩阵都是单位下三角阵。单位下三角阵乘积为单位下三角阵，单位下三角阵逆矩阵为单位下三角阵。故上述初等矩阵相乘求逆即为单位下三角阵L。对于初等变换的限制（对于下三角矩阵对角元为1的要求）使得并不是所有可逆矩阵都能LU分解。为了保证高斯消元时主元不为0，有如下定理：对于可逆矩阵，存在三角分解与所有顺序主子式不为0等价。这意味着并不是所有的可逆矩阵都可以三角分解，同时并非不可逆矩阵不存在三角分解：n阶矩阵A的前r(A)个顺序主子式非零，则A存在三角分解，反之不然。LU分解方便计算机解线性方程组。

分解算法：[杜尔里特算法(Doolittle algorithm)](http://blog.csdn.net/billbliss/article/details/78559289)

## Cholesky分解

定义：设A是一个n阶对称正定矩阵，则存在唯一的对角元为正的下三角阵G，使得$A=GG^T$（可推广到复数域）

通过LU分解A=LDL,，其中L对角元为1，D为对角阵.。A正定，则D中对角元为正。

$$x^TAx=x^TLDL^T=y^TDy=\sum_{i=1}^{n}d_{ii}y_i^2>0 \quad\quad\quad x\ne 0 \\$$

将D中元素开平方，分别乘到L上，得$A=GG^T$. 求解算法又被称为[平方根算法](http://www.qiujiawei.com/linear-algebra-11/)

## QR分解

定义：可逆矩阵$A\in F_{n\times n}$ ，则存在唯一酉矩阵Q和对角元为正得上上三角阵R使得A=QR.

即使可逆矩阵也不一定存在三角分解，因此可以用更广泛应用的QR分解来代替。Q可以通过Schmidt正交化得到，同你过反解得出R。QR分解又被称为正交分解。QR分解的推广：对于列满秩矩阵A，A=QR，其中Q为A的列向量正交化得到，R是对角元为正的上三角阵，此分解唯一。

## 奇异值分解

The Singular Value Decomposition(SVD)

任意矩阵$A\in F_{m\times n}$，r=rank(A)。为了在n维空间中找到一组正交基，使A变换后依然正交，设正交基：

$$(v_1,v_2,\dots,v_n) \\$$

映射后：

$$(Av_1,Av_2,\dots,Av_n) \\$$

由正交性：

$$(Av_j)^*Av_i=0, \quad v_j^*A^*Av_i=0 \\$$

若取$v_i$ 为$A^*A$特征向量则满足条件。把$v_i$单位化之后，则：

$$(Av_i,Av_i)=\lambda_iv_i\cdot v_i=\lambda_i \\$$

把$Av_i$单位化：

$$u_i=\frac{1}{\sqrt{\lambda_i}}Av_i=\frac{1}{\sigma_i}Av_i \\$$

将$u_i(i=1,\dots,r)$扩展$u_i(i=1,\cdots,m)$，则：

$$A(v_1,\cdots,v_n)=(u_1,\cdots,u_m)\begin{bmatrix} \sigma_1\\&\cdots\\&&\sigma_n\\0&0&0\end{bmatrix} \\$$

即：

$$A=UDV^* \\$$

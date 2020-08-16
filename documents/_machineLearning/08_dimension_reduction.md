---
 title: 08_dimension_reduction
 categories: ml
 tags: ml
 date: 2018-06-03
---

**Motivation**: data compression / reducing complexity. Extracting hidden structure from high dimensional datasets.

## PCA

**variance**: how spread the data set is
$$var(x)=\frac{\sum(x_i-\bar{x})^2}{N}$$
**covariance**: a measure of the extent to which corresponding elements from two sets of ordered data move in the same direction.
$$cov(x,y)=\frac{\sum(x_i-\bar{x})(y_i-\bar{y})}{N}$$

In data analysis, we try to find the patterns among the data sets so we want the data to be spread out across each dimension. Also, we want the dimensions to be independent. Such that if data has high covariance when represented in some n number of dimensions then we replace those dimensions with linear combination of those n dimensions. Now that data will only be dependent on linear combination of those related n dimensions.

PCA finds a new set of dimensions (or a set of **basis** of views) such that all the dimensions are **orthogonal** (and hence linearly independent) and **ranked** according to the variance of data along them. It means more important principle
axis occurs first. (more important = more variance/more spread out data)

用最小的维度来描述数据。 引入噪声来包括数据点在主成分上的扰动。 正交来保证独立性。

- PC(principal component, 主成分): orthogonal directions that capture most of the variance in the data.
- first PC: direction of the maximum variance
- Subsequent PCs: directions orthogonal to 1st PC and describe maximum residual variance.

主成分分析是经典的基于线性分类的分类系统，把分布在多个维度得高维数据投射到几个轴上。 如果样本有两个特征变量，这种拟合就是$a_1x_1+a_2x_2=P$, 其中$a_1,a_2$称为loading，P称为主成分。两个特征变量的主成分分析本质就是一个线性回归。若有n个特征变量，则主成分变成：
$$a_1x_1+a_2x_2+\dots+a_nx_n=PC_1$$
这是第一主成分，于此还可以获得一系列与第一成分正交得其他轴：
$$b_1x_1+b_2x_2+\dots+b_nx_n=PC_2$$
若用向量表示，则：
$$A^TX=PC$$
矩阵A为载荷(loading)，主成分的值为得分(scoring).

Several methods can be used to do PCA.

**eigen decomposition**

0. normalize the data
1. Calculate the covariance matrix X of data sets.
2. Calculate eigen vectors and corresponding eigen values.
3. Sort the eigen vectors according to their eigen values in decreasing order.
4. Choose first k eigen vectors and that will be the new k dimensions.
5. Transform the original n dimensional data points into k dimensions.

the covariance matrix contains:

- variance of dimensions as the main diagonal elements
- covariance of dimensions as the off diagonal elements
- symmetric

As we want the data to be spread out which means it should have high variance along the diagonal, and we want to remove correlated dimensions which means covariance among dimensions should be zero, the covariance matrix should have:

- large numbers as the main diagonal elements
- zero values as the off diagonal elements

This leads the **diagonalization**, the process of transforming a matrix to diagonal matrix.
$$
\text{suppose X has been normalized and set } Y=PX\\
C_x=\frac{1}{n}XX^T \quad \small{\text{(data items in column)}}\\
C_y=\frac{1}{n}YY^T=PC_xP^T  \\
\text{the covariance matrix is symmetric so it must can be diagonalized}  \\
C_x=P^{T}C_yP      \\
\text{in diagonalization,}\quad  C_x=QC_yQ^T \\
P=Q^T  \\
\text{then k eigen vectors in Q corresponding to the first k eigen values  icould be selected }\\
P'=Q_{m*k}^T  \\
Y=P'X   \\
(k*n)=(k*m)(m*n)
$$

**SVD**

the eigenvalue decomposition of $XX^T$ is closely related to SVD of $X$: $(XX^T)\upsilon=\lambda\upsilon$

as $\upsilon$ is the unit eigen vector: $\upsilon^TXX^T\upsilon=\lambda\upsilon^T\upsilon=\lambda$

thus the eigen value $\lambda$ denotes the amount of variability captured along that dimension $\upsilon$

- maximum variance subapace: PCA finds vector $\upsilon$ such that projections on to the vectors capture maximum variance in the data:
$$\frac{1}{n}\sum_{i=1}^{n}(\upsilon^Tx^{i})^2=\upsilon^TXX^T\upsilon$$
- minimum reconstruction error: PCA finds vectors $upsilon$ such that projection on to the vectors yields minimum MSE reconstruction
$$\frac{1}{n}\sum_{i=1}^{n}||x^{i}-(\upsilon^Tx^{i})\upsilon||^2$$


## Kernel PCA

Classic PCA described a linear projection technique which works well when the data is linearly separable. The kelnel method is introduced to cover the nonlinear case.(reference to [SVM](SVM.md))

1. 引入非线性映射函数$\phi(X)$, 将原始数据映射到高维。映射函数是隐形的，不必要知道隐型函数的具体形式。
2. 特征向量用样本集合线性表示：
$$\phi(X)\phi(X)^T\upsilon=\lambda\upsilon \\
\upsilon=\sum_{i=1}^n\alpha_i\phi(X)    \\
\phi(X)\phi(X)^T\phi(X)\alpha=\lambda\phi(X)\alpha
$$
3. 为了凑成内积形式，两边同时左乘$\phi(X)^T$:
$$\phi(X)^T\phi(X)\phi(X)^T\phi(X)\alpha=\lambda\phi(X)^T\phi(X)\alpha
$$
4. 令$K=\phi(X)^T\phi(X)$:
$$K^2\alpha=\lambda K\alpha$$
两边消去K:  
$$K\alpha=\lambda K$$
5. 求解K的特征向量$\alpha$, 并由2中关系得出$\phi(X)$的特征向量$\upsilon$。

## ICA

independent component analysis

- source signals are statistically independent and non-gaussian distributition
- recover source signals without prior knowledge of sources or mixing matrix

ICA mixture model:
$$x=As$$
where $x$ is the mixed signals matrix, $s$ is the original signals matrix, A is unknown mixing matrix.

ICA认为一个信号可以被分解成若干个统计独立的分量的线性组合，而后者携带更多的信息。我们可以证明，只要源信号非高斯，那么这种分解是唯一的。若源信号为高斯的话，那么显然可能有无穷多这样的分解。

## reference

1. [主成分分析（PCA）原理详解](https://blog.csdn.net/zhongkelee/article/details/44064401)

---
 title: fm模型
 categories: recsys
 tags: recsys
 date: 2020-10-11
---

## FM 模型

因子分解机(FM, Factorization Machine).线性模型假设特征之间是相互独立的，而FM模型增加了各特征之间的相互组合：


线性回归(Linear Regression)模型的方程式如下：

$$y=w_{0}+w_{1} x_{1}+w_{2} x_{2}+\cdots+w_{n} x_{n}  \\
y=w_0+\sum_{i=1}^{n}w_i x_i
$$

二阶多项式回归(Polynomial Regression)模型(Poly2 Model)：

$$\mathrm{y}=w_{0}+\sum_{i=1}^{n} w_{i} x_{i}+\sum_{i=1}^{n} \sum_{j \geq i}^{n} w_{i j} x_{i} x_{j}$$

令$W=[w_{ij}]$,则$W$是一个对称矩阵,根据Cholesky分解:

$$W=VV^T    \\
w_{ij}=<V_i,V_j>=\sum_{f=1}^{k}v_{i,f}v_{j,f} $$

可得FM模型方程：

$$\mathrm{y}=w_{0}+\sum_{i=1}^{n} w_{i} x_{i}+\sum_{i=1}^{n} \sum_{j \geq i}^{n} <V_i,V_j> x_{i} x_{j}$$

其中$V_i$是矩阵$V$的第$i$行，可以看做是第$i$个特征的向量化，其中向量长度为$k(k\ll n)$，这样训练参数从$n^2$降到$nk$.

## FM 模型计算

简化过程：

$$\begin{align} \sum_{i=1}^{n} \sum_{j=i+1}^{n}<v_{i}, v_{j}>x_{i} x_{i}&=\frac{1}{2}\left(\sum_{i=1}^{n} \sum_{j=1}^{n}<v_{i}, v_{j}>x_{i} x_{j}-\sum_{i=1}^{n}<v_{i}, v_{i}>x_{i} x_{i}\right) \\
&=\frac{1}{2}\left(\sum_{i=1}^{n} \sum_{j=1}^{n} \sum_{f=1}^{k} v_{l, f} v_{j, f} x_{i} x_{j}-\sum_{i=1}^{n} \sum_{f=1}^{k} v_{i, f} v_{i, f} x_{i} x_{i}\right)\\
 & =\frac{1}{2} \sum_{l=1}^{k}\left[\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)\left(\sum_{j=1}^{n} v_{j, f} x_{j}\right)-\sum_{i=1}^{n} v_{l, f}^{2} x_{i}^{2}\right]   \\
 &(\text{$i$ 和 $j$ 的累加和是相等的，统一用 $i$ 的形式}) \\
 &=\frac{1}{2} \sum_{f=1}^{k}\left[\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)^{2}-\sum_{i=1}^{n} v_{i, f}^{2} x_{i}^{2}\right]\end{align}$$

1. 时间复杂度由$O(kn^2)$降到$O(kn)$，时间复杂度降到线性。
2. 在特征稀疏的场景下，很多特征为0，只需要计算非0特征就行。

梯度计算：

$$\frac{\partial \hat{y}(x)}{\partial \theta}=\left\{\begin{array}{cl}
1 & \text { if } \theta \text { is } w_{0} \\
x_{i} & \text { if } \theta \text { is } w_{i} \\
x_{i} \sum_{j=1}^{n} v_{j, f} x_{j}-v_{i, f} x_{i}^{2} & \text { if } \theta \text { is } v_{l, f}
\end{array}\right.$$

$$\begin{align}\frac{\partial \hat{y}(x)}{\partial v_{i,f}}&=\frac{\partial\left(\frac{1}{2} \sum_{f=1}^{k}\left[\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)^{2}-\sum_{i=1}^{n} v_{i, f}^{2} x_{i}^{2}\right]\right)}{\partial\left(v_{i, f}\right)} \\
&(\text{求和函数中与$i,f$}无关的都去掉了)\\
&=\frac{1}{2}\left[\frac{\partial\left(\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)^{2}\right)}{\partial\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)} \frac{\partial\left(\sum_{i=1}^{n} v_{i, f} x_{i}\right)}{\partial\left(v_{i, f}\right)}-\frac{\partial\left(\sum_{i=1}^{n} v_{i, f}^{2} x_{i}^{2}\right)}{\partial\left(v_{i, f}\right)}\right]  \\
&=(\sum_{j=1}^n v_{j,f}x_j)\cdot x_i-v_{i,f}x_i^2  \\
&=x_{i} \sum_{j=1}^{n} v_{j, f} x_{j}-v_{i, f} x_{i}^{2}\\
\end{align}$$

## FM模型应用

- 回归任务(regression)
- 二分类(binary classification)
- 排序(ranking)


## FFM 模型

## DeepFM 模型


## ref

projects:

- [kaggle-Display Advertising Challenge](https://www.kaggle.com/c/criteo-display-ad-challenge)

blog:

- [zhihu-FM因子分解机模型的原理、推导、代码和应用](https://zhuanlan.zhihu.com/p/145436595)
- [openresource-libFM](http://www.libfm.org/)
- [FM（Factorization Machines）的理论与实践](https://zhuanlan.zhihu.com/p/50426292)
- [推荐系统召回四模型之：全能的FM模型](https://zhuanlan.zhihu.com/p/58160982)

open source:

- LibFM	Earliest library by the author himself for FMs
- LibFFM: Library exclusively FFMs, [code](https://www.csie.ntu.edu.tw/~r01922136/libffm/)
- xLearn: Scalable ML package for both FM & FFMs, [github-code](https://github.com/aksnzhy/xlearn),[doc](https://xlearn-doc-cn.readthedocs.io/en/latest/index.html)
- tffm	Tensorflow implementation of arbitrary order FMs




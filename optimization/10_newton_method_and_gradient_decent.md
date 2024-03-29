---
title: 牛顿法和梯度下降
categories: optimization
tags: optimization
date: 2019-08-06
---

## 牛顿法(Newton Method)

**求零点**

根据一阶泰勒展开公式：

$$f(x)=f(x_k)+f'(x_k)(x-x_k)$$

得到求零点的迭代公式：

$$x=x_k-\frac{f(x_k)}{f'(x_k)}=x_k-\frac{f(x_k)}{\Delta f(x_k)} \\
x=x_k-J(x_k)^{-1}f(x_k), \text{多个实函数的情况}$$

**求极值**

优化算法中求极值的过程可以转化为一阶到函数为0,从而将问题转化为求零点的过程。迭代公式的推导有两种。第一种把优化问题中的导函数看作零点问题中的原函数，则可以根据零点迭代公式直接得到：

$$x=x_k-\frac{f'(x_k)}{f''(x_k)}$$

第二种是根据二阶泰勒展开：

$$f(x)=f(x_k)+f'(x_k)(x-x_k) + \frac{1}{2}f''(x_k)(x-x_k)$$

求导，并令导数为0,得到：

$$f'(x_k)+f''(x_k)(x-x_k)=0 \\
x=x_k-\frac{f'(x_k)}{f''(x_k)}$$

**优化过程中步长的计算**

令$d_k=-\frac{f'(x_k)}{f''(x_k)}$是迭代中每一步更新的步长. 对于有n维变量的函数而言，偏导数$\Delta f(x)=f'(x_k)\in R^n, H(f(x))=f''(x_k)\in R^{(n\times n)}$,所以$d_k$并不是由两个矩阵直接相除，而是通过解方程$H(f(x))d_k=-\Delta f(x)$得到。


## 梯度下降

$$x=x_k-\alpha \Delta f(x)$$

另一种视角：

**<font color='Tomato'>Quadratic approximation</font>**


define the expansion where replacing usual $\nabla^2f(x)$ by $\frac{1}{t}I$:

$$f(y) \approx f(x)+\nabla f(x)^T(y-x)+\frac{1}{2 t}\|y-x\|_2^2$$

which can be refered as the linear approximzation to $f$, the optimal value is:

$$x^+ = \arg \min_y f(x)+\nabla f(x)^T(y-x)+\frac{1}{2 t}\|y-x\|_2^2 \\
\Downarrow  \\
x^+ = x - t \nabla f(x)$$

牛顿法可以看作根据泰勒二次展开的线性近似进行推导，而剃度下降是把泰勒展开中的二次项进一步做近似而得到。两者最后都统一成根据梯度信息进行迭代，只是梯度的系数各不一样。

## 机器学习中的实践用法变种

**Batch Gradient Descent**

针对整个数据集，通过所有样本计算梯度方向. 

- 优点：全局最优解；易于并行实现；
- 缺点：当样本数目很多时，训练过程会很慢


$$\frac{\partial J(\theta)}{\partial \theta_{j}}=\sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right) x_{j}^{(i)}$$

$$\theta_{j}^{\prime}=\theta_{j}-\alpha \frac{\partial J(\theta)}{\partial \theta_{j}}=\theta_{j}-\alpha \sum_{i=1}^{m}\left(h_{\theta}\left(x^{(i)}\right)-y^{(i)}\right) x_{j}^{(i)}$$

**Mini-Batch Gradient Descent**

小批量

$$\theta_{j}:=\theta_{j}-\alpha \frac{1}{10} \sum_{k=i}^{i+9}\left(h_{\theta}\left(x^{(k)}\right)-y^{(k)}\right) x_{j}^{(k)}$$

**Stochastic Gradient Descent**

可以看作是单个样本计算梯度

- 优点：训练速度快；
- 缺点：准确度下降，并不是全局最优；不易于并行实现

$$\theta_{j}:=\theta_{j}+\alpha\left(y^{(i)}-h_{\theta}\left(x^{(i)}\right)\right) x_{j}^{(i)}$$

**总结**

- 牛顿法需要计算二阶导数，这使得牛顿法在以离散数据为基础的机器学习上很难适用












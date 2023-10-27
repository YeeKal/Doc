---
title: 基于矩阵分解的协同过滤
categories: recsys
tags: recsys
date: 2020-12-23
---

- topn 推荐： 准确率 / 召回率
- LFM(latent factor model): 隐因子模型，基于矩阵分解
- als/slope one

## svd 分解

把打分矩阵当作一个大矩阵，并进行SVD分解，但是只保留部分奇异值进行预测：

$$R=U\Sigma V^T\\
A=U_k\Sigma_k V_k^T\approx R $$

![cf_mf.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/recsys/imgs/cf_mf.png)

$$ \text{预测： } r_{i,j}=U_k\Sigma_k^{-1/2}(i) \cdot \Sigma_k^{-1/2} V_k^T(j) \\
\text{用户隐向量矩阵：} P=U_k\Sigma_k^{-1/2}\\
\text{物品隐向量矩阵：} Q=\Sigma_k^{-1/2} V_k^T(j)$$

事实上隐向量矩阵可以看作是对用户和物品向量化的编码，即挖掘用户和物品在多个维度下的隐藏特征。

## ALS (2008)

Alternating Least Squares(ALS): 交替最小二乘

矩阵分解求解的一种优化算法，而FunkSVD看作是基于随机梯度下降的求解

## FunkSVD

既然矩阵分解的目的可以看作是得到隐向量的过程，则可以把矩阵分解转化为一个优化问题，直接初始化该隐向量，并通过迭代优化寻找满足得分矩阵的最优的隐向量。

$$\mathbf{R} \approx \mathbf{P} \times \mathbf{Q}^{T}=\hat{\mathbf{R}}  \\
\hat{r}_{i j}=p_{i}^{T} q_{j}=\sum_{k=1}^{k} p_{i k} q_{k j}$$

根据R矩阵中已知的得分，计算损失：

$$\min e_{i j}^{2}=\sum(r_{i j}-\hat{r}_{i j})^{2}=\sum(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})^{2}$$

正则化：

$$\min L=\sum(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})^{2} +\lambda(||p_{ik}||^2+||q_{kj}||^2)$$

梯度下降：

$$\frac{\partial{L}}{\partial{p_{ik}}} =-2q_{kj}(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})+2\lambda p_{ik}=-2q_{kj}e_{ij}+2\lambda p_{ik} \\
\frac{\partial{L}}{\partial{q_{kj}}} =-2p_{ik}(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})+2\lambda q_{kj}=-2p_{ik}e_{ij}+2\lambda q_{kj}$$

## PMF(2008)

> Salakhutdinov et al. Probabilistic matrix factorization. NIPS(2008): 1257-1264.

FunkSVD的概率解释版本

## BiasSVD(2009)

> Koren et al. Matrix factorization techniques for recommender systems.Computer 42.8 (2009).

$$\min_{p,q,b_u,b_i} L=\sum(r_{i j}-(\sum_{k=1}^{K} p_{i k} q_{k j}+\mu+b_u+b_i)^{2} +\lambda(||p_{ik}||^2+||q_{kj}||^2+||b_u||^2+||b_i||^2)$$

- $\mu$: 整体平均评分,已知常量 
- $b_\mu$: 用户评分偏差, 待训练向量，与用户数目等长
- $b_i$: item被评分偏差，待训练向量，与物品数目等长
- $\hat{r}_{ij}=\sum_{k=1}^{K} p_{i k} q_{k j}+\mu+b_u+b_i$

梯度下降：

$$\frac{\partial{L}}{\partial{p_{ik}}} =-2q_{kj}(r_{i j}-\hat{r}_{ij})+2\lambda p_{ik}=-2q_{kj}e_{ij}+2\lambda p_{ik} \\
\frac{\partial{L}}{\partial{q_{kj}}} =-2p_{ik}(r_{i j}-\hat{r}_{ij})+2\lambda q_{kj}=-2p_{ik}e_{ij}+2\lambda q_{kj} \\
\frac{\partial{L}}{\partial{b_u}}=-2e_{ij}+2\lambda b_u \\
\frac{\partial{L}}{\partial{b_u}}=-2e_{ij}+2\lambda b_i$$

## SVD++

在BiasSVD的基础上引入隐式反馈

$$\hat{r}_{ij}=\mu+b_u+b_i+q_j^T(p_{i}+\frac{1}{\sqrt{||R_u||}}\sum_{j\in R_u}y_j)$$

- $||R_u||$: $R_u$为user 打分的item的id， 因此这个值可以看作是user打分的item的个数
- $y$: (item_size, dim), 每一个item对应的权重系数矩阵

梯度下降：

$$\frac{\partial{L}}{\partial{p_{ik}}} =-2q_{kj}(r_{i j}-\hat{r}_{ij})+2\lambda p_{ik}=-2q_{kj}e_{ij}+2\lambda p_{ik} \\
\frac{\partial{L}}{\partial{q_{kj}}} =-2p_{ik}(r_{i j}-\hat{r}_{ij})+2\lambda q_{kj}=-2e_{ij}(p_{ik}+\frac{1}{\sqrt{||R_u||}}\sum_{j\in R_u}y_{kj})+2\lambda q_{kj} \\
\frac{\partial{L}}{\partial{b_u}}=-2e_{ij}+2\lambda b_u \\
\frac{\partial{L}}{\partial{b_u}}=-2e_{ij}+2\lambda b_i \\
y_{kj}=-2e_{ij}\cdot q_{kj} \cdot \frac{1}{\sqrt{||R_u||}}  +2\lambda y_{kj}$$

## timeSVD

## ConvMF(2016)

- paper: Convolutional Matrix Factorization for Document Context-Aware Recommendation
- [ConvMF-github](https://github.com/cartopy/ConvMF)




## NMF

> Learning the parts of objects by non-negative matrix factorization, 1999

## ref

- blog:
    - [详解矩阵分解算法在推荐系统中的应用(1) | 鹅厂实战](https://zhuanlan.zhihu.com/p/69662980)
    - [推荐系统之矩阵分解(MF)及其python实现](https://blog.csdn.net/qq_43741312/article/details/97548944)
    - [推荐系统之矩阵分解家族](https://zhuanlan.zhihu.com/p/35262187)
    - [基于协同过滤的推荐算法综述](https://zhuanlan.zhihu.com/p/338582478)
    - [github Summary-of-Recommender-System-Papers](https://github.com/fuxuemingzhu/Summary-of-Recommender-System-Papers)
- paper
    - [Matrix Factorization Techniques for Recommender Systems]()
    - [Large-scale Parallel Collaborative Filtering for the Netflix Prize]()
    - [可能是史上最全推荐系统资料了]()
    - [为什么spark中只有als]()
    - [文哥的学习日记-jianshu](https://www.jianshu.com/u/c5df9e229a67)
- personal code



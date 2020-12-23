---
title: 基于矩阵分解的协同过滤
categories: recsys
tags: recsys
date: 2020-12-23
---


## svd 分解

把打分矩阵当作一个大矩阵，并进行SVD分解，但是只保留部分奇异值进行预测：

$$R=U\Sigma V^T\\
A=U_k\Sigma_k V_k^T\approx R $$

![cf_mf](imgs/cf_mf.png)

$$ \text{预测： } r_{i,j}=U_k\Sigma_k^{-1/2}(i) \cdot \Sigma_k^{-1/2} V_k^T(j) \\
\text{用户隐向量矩阵：} P=U_k\Sigma_k^{-1/2}\\
\text{物品隐向量矩阵：} Q=\Sigma_k^{-1/2} V_k^T(j)$$

事实上隐向量矩阵可以看作是对用户和物品向量化的编码，即挖掘用户和物品在多个维度下的隐藏特征。

## FunkSVD

既然矩阵分解的目的可以看作是得到隐向量的过程，则可以把矩阵分解转化为一个优化问题，直接初始化该隐向量，并通过迭代优化寻找满足得分矩阵的最优的隐向量。

$$\mathbf{R} \approx \mathbf{P} \times \mathbf{Q}^{T}=\hat{\mathbf{R}}  \\
\hat{r}_{i j}=p_{i}^{T} q_{j}=\sum_{k=1}^{k} p_{i k} q_{k j}$$

根据R矩阵中已知的得分，计算损失：

$$\min e_{i j}^{2}=\sum(r_{i j}-\hat{r}_{i j})^{2}=\sum(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})^{2}$$

正则化：

$$\min e_{i j}^{2}=\sum(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})^{2} +\lambda(||p_{ik}||^2+||q_{kj}||^2)$$

梯度下降：

$$\frac{\partial{L}}{\partial{p_{ik}}} =-2q_{kj}(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})+2\lambda p_{ik}=-2q_{kj}e_{ij}+2\lambda p_{ik} \\
\frac{\partial{L}}{\partial{p_{kj}}} =-2p_{ik}(r_{i j}-\sum_{k=1}^{K} p_{i k} q_{k j})+2\lambda q_{kj}=-2p_{ik}e_{ij}+2\lambda q_{kj}$$

## PMF(2008)

> Salakhutdinov et al. Probabilistic matrix factorization. NIPS(2008): 1257-1264.

FunkSVD的概率解释版本

## BiasSVD(2009)

> Koren et al. Matrix factorization techniques for recommender systems.Computer 42.8 (2009).

$$\min_{p,q,b_u,b_i} e_{i j}^{2}=\sum(r_{i j}-(\sum_{k=1}^{K} p_{i k} q_{k j}+\mu+b_u+b_i)^{2} +\lambda(||p_{ik}||^2+||q_{kj}||^2+b_u^2+b_i^2)$$

- $\mu$: 整体平均评分 
- $b_\mu$: 用户评分偏差
- $b_i$: item被评分偏差

## SVD++

## timeSVD

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
- personal code



---
title: lightgbm
categories: ml
tags: ml
date: 2021-03-121
---


## 分裂策略

LightGBM和xgboost一样采用分桶方式加速分裂特征选择，不同的是LightGBM通过降采样的方式继续降低特征选择的复杂度。

- GOSS：单边梯度采样，Gradient-based One-Side Sampling。保留大梯度样本的同时，随机保留小梯度样本
- EFB

## 总结

不建议在小数据集上使用LightGBM。LightGBM对过拟合很敏感，对于小数据集非常容易过拟合


## ref

- [What makes LightGBM lightning fast?](https://towardsdatascience.com/what-makes-lightgbm-lightning-fast-a27cf0d9785e)
- [LightGBM算法详解](https://blog.csdn.net/GFDGFHSDS/article/details/104779767)
---
title: 深度学习在推荐系统中的应用-深度兴趣网络
categories: recsys
tags: recsys
date: 2021-01-24
---

## DIN

问题： 多值稀疏特征通过mean/sum转化为统一长度向量会损失信息，不能呢个表达用户的兴趣点。特别指用户与广告的交互信息，点击的广告队列和浏览的商品列表

1. 多值稀疏特征内部的池化： max/mean/sum/lstm
2. 不通过特征间的交互： concat/attention

局部注意力： local activation unit

## ESSM

预估转化率的困难

1. sample selection bias: 训练在点击样本空间，而推理在整个样本空间
2. data sparsity: 数据稀疏

框架： 通过点击率和最终转化率，间接预测点击然后转化的概率


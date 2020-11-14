---
title: triplet loss
categories: recsys
tags: recsys
date: 2020-11-10
---

## triplet less

$$L=\sum_{i=1}^{N} \max \left(0, D\left(q^{(i)}, d_{+}^{(i)}\right)-D\left(q^{(i)}, d_{-}^{(i)}\right)+m\right)$$

- 目标是拉近与正样本的距离，拉远与负样本的距离
- easy triplets: 正样本距离本来就很近，不需要优化，或者说优化的意义不大

    $$L=0, d(q,d_+)+m < d(q,d_-)$$

- hard triplets: $d(q,d_+) > d(q,d_-)$, 正样本的距离比负样本还要远
- semi-hard triplet: 距离适中

    $$d(q,d_+) < d(q,d_-) < d(q,d_+)+m$$

## 训练
---
title: 深度推荐系统中的损失函数
categories: recsys
tags: recsys
date: 2020-11-10
---

## negative Sampling

1. 只有一层Embedding层，即embedding可以通过label取出来，则直接在线选择
2. 把负样本的label作为输入
3. 把batch中其他样本作为负样本

- [tensorflow implementation](tensorflow_recommenders/tasks/retrieval.py)
 
## triplet less

$$L=\sum_{i=1}^{N} \max \left(0, D\left(q^{(i)}, d_{+}^{(i)}\right)-D\left(q^{(i)}, d_{-}^{(i)}\right)+m\right)$$

- 目标是拉近与正样本的距离，拉远与负样本的距离
- easy triplets: 正样本距离本来就很近，不需要优化，或者说优化的意义不大

    $$L=0, d(q,d_+)+m < d(q,d_-)$$

- hard triplets: $d(q,d_+) > d(q,d_-)$, 正样本的距离比负样本还要远
- semi-hard triplet: 距离适中

    $$d(q,d_+) < d(q,d_-) < d(q,d_+)+m$$

#### 训练

## 2020 Mixed Negative Sampling for Learning Two-tower Neural Networks in Recommendations


## ref

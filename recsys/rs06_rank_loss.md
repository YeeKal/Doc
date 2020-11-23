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

![triplets1](imgs/triplets1.png)

实现的多种方式：

- online: 在同一个batch中在线计算选择正负样本
- offline: 手动选择正负样本
    - batch all: select all the valid triplets, and average the loss on the hard and semi-hard triplets. 
        - crucial point here is to not take into account the easy triplets (those with loss 0 ), as averaging on them would make the overall loss very small $\circ$ 
        - this produces a total of $P K(K-1)(P K-K)$ triplets $(P K$ anchors, $K-1$ possible positives per anchor, $P K-K$ possible negatives)
    - batch hard: for each anchor, select the hardest positive (biggest distance $d(a, p))$ and the hardest negative among the batch
        - this produces $P K$ triplets
        - the selected triplets are the hardest among the batch

## 实现

offline:

```python
anchor_output = ...    # shape [None, 128]
positive_output = ...  # shape [None, 128]
negative_output = ...  # shape [None, 128]

d_pos = tf.reduce_sum(tf.square(anchor_output - positive_output), 1)
d_neg = tf.reduce_sum(tf.square(anchor_output - negative_output), 1)

loss = tf.maximum(0.0, margin + d_pos - d_neg)
loss = tf.reduce_mean(loss)
```

online: 

- [Triplet loss in TensorFlow](https://github.com/omoindrot/tensorflow-triplet-loss/blob/master/model/triplet_loss.py)
- [tensorflow semihard]



## 2020 Mixed Negative Sampling for Learning Two-tower Neural Networks in Recommendations


## ref

- blog
    - [Triplet Loss and Online Triplet Mining in TensorFlow](https://omoindrot.github.io/triplet-loss)
    - [Retrieval with Deep Learning: A Ranking loss Survey Part 1](https://medium.com/@ahmdtaha/retrieval-with-deep-learning-a-ranking-loss-survey-part-1-8e88a6f8e091)
- code
    -  [Triplet loss in TensorFlow](https://github.com/omoindrot/tensorflow-triplet-loss)

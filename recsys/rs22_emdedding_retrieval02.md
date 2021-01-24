---
 title: 推荐系统中的向量检索02-单塔模型
 categories: recsys
 tags: recsys
 date: 2020-11-10
---

## 2018 tdm

sampled softmax

商品放到树里，中间节点为分类信息。通过k-means聚类方法

1. 要构建一棵树：这棵树的当前层的最有子节点的父节点必然是上一层父节点的最优子节点，即父节点的值等于最优子节点的值。
2. 怎么学习

- [阿里妈妈新突破：深度树匹配如何扛住千万级推荐系统压力](https://www.6aiq.com/article/1554659383706)

- zhihu-TDM推荐算法 阅读笔记2
- 2019——tdm2_joint optimization of tree-based index and Deep Model for Recommender Systems
- 2020_tdm3 leaning optimal tree models under Beam Search

## ref

- Learning Tree-based Deep Model for Recommender Systems
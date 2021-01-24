---
 title: GBDT+LR
 categories: recsys
 tags: recsys
 date: 2020-10-17
---

把多颗回归树的输出节点以0/1编码，这样就形成了一个高维的0-1向量，这个向量在一定程度上反映了数据的多维特征。之后再对这一多维向量进行LR回归。

## ref

- [回归树的原理及Python实现](https://mp.weixin.qq.com/s?__biz=MzI5NDY1MjQzNA==&mid=2247488358&idx=1&sn=cdf27f1b70577ef159ffd806facc186b&chksm=ec5ecc1bdb29450dfe32651a07caab10b88518de1947c406e212ad0aae688cd43dfc8d83d9a2&scene=21#wechat_redirect)
- [The principle of GBDT regression and Python implementation](https://www.programmersought.com/article/9639530615/)



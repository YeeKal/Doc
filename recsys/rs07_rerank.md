---
title: 搜索推荐中的rerank方法
categories: recsys
tags: recsys
date: 2020-11-18
---

- learning to rank: 指通用的排序方法
- rerank: 指搜索推荐场景中两步过程中召回-排序的第二步，即对召回结果进行二次排序。这一过程更加注重文档与文档间排序权重的对比


## rank loss

- point-wise: [q,doc], 以单个文档的得分。
    - 没有考虑文档间的对比情况
    - Pranking (NIPS 2002), OAP-BPM (EMCL 2003), Ranking with Large Margin Principles (NIPS 2002), Constraint Ordinal Regression (ICML 2005)
- pair-wise: [q,doc_-,doc_+]。考虑文档间的关联强度。有两种建模方式：在建模中考虑两个文档对; 建模中使用单个文档，但是在损失函数里面计算入相对关系。
    - Learning to Retrieve Information (SCC 1995), Learning to Order Things (NIPS 1998), Ranking SVM (ICANN 1999), RankBoost (JMLR 2003), LDM (SIGIR 2005), RankNet (ICML 2005), Frank (SIGIR 2007), MHR(SIGIR 2007), Round Robin Ranking (ECML 2003), GBRank (SIGIR 2007), QBRank (NIPS 2007), MPRank (ICML 2007), IRSVM (SIGIR 2006)
    - SVM Rank
    - RankNet(2007)
    - RankBoost(2003)
    - 只使用了一对文档，没有考虑一系列文档结果之间的相对关系
- list-wise
    - LambdaRank (NIPS 2006), AdaRank (SIGIR 2007), SVM-MAP (SIGIR 2007), SoftRank (LR4IR 2007), GPRank (LR4IR 2007), CCA (SIGIR 2007), RankCosine (IP&M 2007), ListNet (ICML 2007), ListMLE (ICML 2008)
    - softrank: 输出单个文档的排列顺序
    - listnet: 输出整个文档集的排列顺序 
    - LambdaRank
    - AdaRank
    - LambdaMart


## rank model

- 1999, MART(Multiple Additive Regression Tree), -> GBDT. lambda 是MART求解使用的梯度，表示一个待排序文档下一次迭代应该排序的方向
- 2010, RankNet
- LambdaRank
- LambdaMart

## 评价指标

- MAP(Mean Average Precision)

假设有两个主题，主题1有4个相关网页，主题2有5个相关网页。某系统对于主题1检索出4个相关网页，其rank分别为1, 2, 4, 7；对于主题2检索出3个相关网页，其rank分别为1,3,5。对于主题1，平均准确率为(1/1+2/2+3/4+4/7)/4=0.83。对于主题2，平均准确率为(1/1+2/3+3/5+0+0)/5=0.45。则MAP= (0.83+0.45)/2=0.64。

- NDCG(Normalized Discounted Cumulative Gain)

## FTRL

## LambdaMart

相比于MART改变了梯度的计算方式，该计算方式命名为lambda
## LambdaRank

## RankNet


## MART

MART即梯度提升树(GBDT)


## ref 

- blog
    - [推荐系统中re-rank论文有哪些?](https://www.zhihu.com/question/364930489)
    - 
- paper:
    - [RecSys 19][Alibaba] Personalized Re-ranking for Recommendation
    - [SIGIR 18] Learning a Deep Listwise Context Model for Ranking Refinement.pdf
- project
    - [RankLib](https://sourceforge.net/p/lemur/wiki/RankLib/)
    - [Tensorflow-ranking](https://github.com/tensorflow/ranking)
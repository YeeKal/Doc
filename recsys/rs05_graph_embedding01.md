---
title: 图神经网络00 - 入门简介
categories: ml
tags: ml
date: 2020-11-14
---

- [gnn](graph neural network)
- graph embedding
- GCN GraphSAGE GAT GAE

论文解读： [2009] The graph neural network model

## introduction

a function $\tau$ maps a graph $G$ and one of its nodes $n$ to a vector:

$$\tau(\boldsymbol{G}, n) \in \mathbb{R}^{m}$$

- application: 化合物/网页链接
    - graph-focused: 节点独立，对整个图进行分类
    - node-focused: 取决于每个节点
- traditional machine leaning applications cope with graph structured data
    - recursive neural network,
    - Markov chains: random walk theory

## GNN

![gnn_01](imgs/gnn_01.png)


## GCN

2016 Semi-Supervised Classification with Graph Convolutional Networks


## ref 

- blog
    - [图嵌入（Graph embedding）综述](https://zhuanlan.zhihu.com/p/62629465)
    - [gituhb-GNNPapers-清华大学整理图神经网络LIST](https://github.com/thunlp/GNNPapers)
    - [从图(Graph)到图卷积(Graph Convolution)：漫谈图神经网络模型](https://www.cnblogs.com/SivilTaram/p/graph_neural_network_1.html)
        - [github-imgs](https://github.com/SivilTaram/Graph-Neural-Network-Note/tree/master/images)
- personal code
- paper
    - [2009 - The graph neural network model](https://persagen.com/files/misc/scarselli2009graph.pdf) 
    - [Graph Neural Networks: A Review of Methods and Applications](https://arxiv.org/pdf/1812.08434.pdf)
    - [2018-Deep Learning on Graphs: A Survey](https://arxiv.org/pdf/1812.04202.pdf)
    - [2019-A Comprehensive Survey on Graph Neural Networks]()
    - [2016-Semi-Supervised Classification with Graph Convolutional Networks](https://arxiv.org/abs/1609.02907)
    - [2017-Inductive Representation Learning on Large Graphs](https://arxiv.org/abs/1706.02216)
    - [Graph Learning Approaches to Rec Systems: A Review]()
- project
    - [graphsage](http://snap.stanford.edu/graphsage/)

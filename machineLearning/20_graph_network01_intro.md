---
title: 图神经网络1 - 入门简介
categories: ml
tags: gnn
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

**notations:**

- $G$: graph, is a pair $(N,E)$ 
- $N$: set of nodes
- $E$: set of edges
- ne[n]: neighbors of node $n$
- co[n]: set of arcs having $n$ as a vertex
- $l_n, l_{(n_1,n_2)}$: labels attached to node $n$ and edge $(n_1,n_2)$, represented by real vectors
- $x_n$: hidden state of node $n$
- $t_{i,j}$: desired target associated to $n_{i,j}$

**model:**

$$x_n=f_w(l_n, l_{co[n]},l_{ne[n]},x_{ne[n]}) \\
o_n=g_w(x_n,l_n)$$

- $f_w$: local transition function. 状态转移函数。通过迭代得出图节点的隐藏状态。函数参数可以根据实际任务选择是否需要加入迭代过程。
- $o_n$: local output function，局部输出函数。可以认为是下游任务的决策函数，通过图的隐藏状态判断节点的类别。比如对于一个化合物分子，判断该图结构是否为有毒的。
![gnn_01.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gnn_01.png)

通过堆叠所有节点的$f_w$为$F_w$,则模型方程可以写为：

$$\begin{array}{l}
x=F_{\boldsymbol{w}}(\boldsymbol{x}, \boldsymbol{l}) \\
\boldsymbol{o}=G_{\boldsymbol{w}}\left(\boldsymbol{x}, \boldsymbol{l}_{\boldsymbol{N}}\right)
\end{array}$$

对于non-positional图：

$$x_n=\sum_{u\in ne[n]}h_w(l_n, l_{co[n]},l_{ne[n]},x_{ne[n]})$$

这也被称为aggregator函数。对于positional图，函数需要接收金具位置作为额外的输入，具体实现可以把参数排序后输入。

其中$F_w$为全局状态转移函数(global transition function), $G_w$为全局输出函数。这里局部的意思是指单个节点，而全局是指合并全部节点的整个图。在图神经网络中，需要保证$x,o$的存在性和唯一性。 而巴拿赫不动点定理(Banach's Fixed Point Theorem)为这一过程提供了理论基础。该理论指出，如果$F_w$是一个压缩映射(contraction map),则$x,o$存在唯一解。压缩映射的含义是指：

$$||F_w(x_1,l)-F_w(x_2,l)||\leq \mu ||x_1-x_2||$$

即经过映射过的空间比原来的空间要小。经过多次的压缩映射，最后会把原空间压缩到一个点上。根据巴拿赫不动点定理通过迭代的方式可以指数级快速求解， 则隐向量的计算过程表示为：

$$\begin{aligned}
\boldsymbol{x}_{n}(t+1) &=f_{\boldsymbol{w}}\left(\boldsymbol{l}_{n}, \boldsymbol{l}_{\mathrm{co}[n]}, \boldsymbol{x}_{\mathrm{ne}[n]}(t), \boldsymbol{l}_{\mathrm{ne}[n]}\right) \\
\boldsymbol{o}_{n}(t) &=g_{\boldsymbol{w}}\left(\boldsymbol{x}_{n}(t), l_{n}\right), \quad n \in \boldsymbol{N}
\end{aligned}$$

**model implemendation:**

把$f_w$的参数拼接在一起，再经过前馈神经网络，可以对模型做一个简单的实现。

![gnn_02.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gnn_02.png)

**model learning**

- 保证压缩映射：
- 学习过程

$$e_{w}=\sum_{i=1}^{p} \sum_{j=1}^{q_{i}}\left(\mathbf{t}_{i, j}-\varphi_{w}\left(G_{i}, n_{i, j}\right)\right)^{2}$$

**gnn-rnn**

![gnn-rnn.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gnn-rnn.png)






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

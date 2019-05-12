---
 title: 10_graph_model
 categories: ml
 tags: ml
 date: 2018-06-05
 ---

## probabilistic graphical model

- vertex
- edge
- isomorphism [,aɪsə'mɔrfɪzm] 
- directed graph
- undirected graph
- weight: weight/length/cost of edges
- graphical model
    - bayesian network, 贝叶斯网络(directed acyclic graphical model(DAG),有向无环图`)
    - markov random field, 马尔可夫随机场, undirected


## bayesian network

$$E[P(E)] \xrightarrow{\quad \quad} H[P(H/E)]$$
贝叶斯网络中边代表连接关系，点代表在n个与之有连接关系的父节点同时出现的条件下的条件概率。

D-separation：

- head-to-head
    - c未知的条件下，a,b独立

![head2head](https://pic2.zhimg.com/80/v2-eb21d376ce0cd7e026793351bb5a3e4b_hd.jpg)

- tail-to-tail
    - c已知的条件下，a,b独立
    
![tail2tail](https://pic2.zhimg.com/80/v2-6ac53161a26b8ddf1f4e70f10615b8fd_hd.jpg)

- head-to-tail
    - c已知的条件下，a,b独立
    - 在较长的链式网络中，若$x_i$固定，则$x_{i+1}$与$x_i$之前的节点都独立。即$x_{i+1}$的状态只与前一个节点有关。这种顺次演变的随机过程，就叫做马尔科夫链（Markov chain）.

    ![head2tail](https://pic2.zhimg.com/80/v2-62698386270df703bf6237d71d748f28_hd.jpg)

## markov network

MRF：马可夫无向图/马可夫随机场，markov random field





**reference**

1. [从贝叶斯方法谈到贝叶斯网络](https://blog.csdn.net/zdy0_2004/article/details/41096141)

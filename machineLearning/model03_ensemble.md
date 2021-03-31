---
title: 决策树的集成学习
categories: ml
tags: ml
date: 2021-03-21
---

提到决策树一般指一颗单独的树。而集成学习(ensemble)是指可以把学习多颗决策树，根据多颗树的结果进行预测。当然集成学习发展至今，已不仅仅限于多颗决策树，更多得表达了集成学习，集体智慧的一种思路。只不过集成学习运用最广的还是在以决策树为基本的树分类器上面。

决策树的集成学习分两大类：bagging，boosting。bagging是每次从样本中抽取部分训练数据训练一棵树，这样对多棵树的结果求平均得到最终的预测结果。而boosting是每次对上次树的结果进行在词学习，最后累加多颗树的结果。

- bagging: 减少方差
- boosting
- stacking

## Bagging

基本策略:

$$f(x)=1 / M \sum_{m=1}^{M} f_{m}(x)$$

1. 从样本集中重采样（有重复的）选出n个样本；
2. 在所有属性上，对这n个样本建立分类器（ID3、C4.5、CART、SVM、Logistic回归等）；
3. 重复以上两步m次，即获得了m个分类器；
4. 将数据放在这m个分类器上，最后根据这m个分类器的投票结果，决定数据属于哪一类


**随机森林(Random Forest):**

随机森林在bagging基础上更加强调了随机性，属性选择随机：

1. 从样本集中用Bootstrap采样（有放回的采样）选出n个样本（重采样）；
2. 从所有属性中随机选择k个属性，选择最佳分割属性作为节点建立CART决策树；
3. 重复以上两步m次，即建立了m棵CART决策树
4. 这m个CART形成随机森林，通过投票表决结果，决定数据属于哪一类

## Boosting (提升树)

**AdaBoost**

训练过程：

- 步骤1. 首先，初始化训练数据的权值分布。每一个训练样本最开始时都被 赋予相同的权值：1/N
$$
D_{1}=\left(w_{11}, w_{12}, \ldots, w_{1 i}, \ldots, w_{1 N}\right), w_{1 i}=\frac{1}{N}, i=1,2, \ldots, N
$$
- 步骤2 . 进行多轮迭代，用m $=1,2, \ldots,$ M表示迭代的第多少轮
    - 使用具有权值分布D_m的训练数据集学习，得到基本分类器（选取让误差率最低的间值来设计基本分类器)
    $$
    G_{m}(x): \chi \rightarrow\{-1,+1\}
    $$
    - 计算G $_{\mathrm{m}}(\mathrm{x})$ 在训练数据集上的分类误差率
    $$
    e_{m}=P\left(G_{m}\left(x_{i}\right) \neq y_{i}\right)=\sum_{i=1}^{N} w_{m i} I\left(G_{m}\left(x_{i}\right) \neq y_{i}\right)
    $$
    Note: $\mathrm{G}_{\mathrm{m}}(\mathrm{x})$ 在训练数据集上的误差率 $\mathrm{e}_{\mathrm{m}}$ 就是被G $_{\mathrm{m}}(\mathrm{x})$ 误分类样本的权值之和。
    - 计算Gm $(\mathrm{x})$ 的系数 $, \mathrm{a}_{\mathrm{m}}$ 表示 $\mathrm{G}_{\mathrm{m}}(\mathrm{x})$ 在最终分类器中的重要程度（目的：得到基本分类器在最终分类器中所占的权重)
    $$
    a_{m}=\frac{1}{2} \log \frac{1-e_{m}}{e_{m}}
    $$
    Note: $\mathrm{e}_{\mathrm{m}}<=1 / 2$ 时， $\mathrm{a}_{\mathrm{m}}>=0,$ 且 $\mathrm{a}_{\mathrm{m}}$ 随着 $\mathrm{e}_{\mathrm{m}}$ 的减小而增大，意味着分类误差率越小的基本分类器在最终分类器中的作用越大。
    - 更新训练数据集的权值分布（为了得到样本的新的权值分布），用于下一轮迭代
    $$
    \begin{array}{c}
    D_{m+1}=\left(w_{m+1,1}, w_{m+1,2} \ldots w_{m+1, i} \ldots w_{m+1, N}\right) \\
    w_{m+1}, i=\frac{w_{m i}}{Z_{m}} \exp \left(-\alpha_{m} y_{i} G_{m}\left(x_{i}\right) ;\right), i=1,2, \ldots, N
    \end{array}
    $$
- 步骤3.组合各个弱分类器
$$
f(x)=\sum_{m=1}^{M} \alpha_{m} G_{m}(x)
$$
从而得到最终分类器，如下：
$$
G(x)=\operatorname{sign}(f(x))=\operatorname{sign}\left(\sum_{m=1}^{M} \alpha_{m} G_{m}(x)\right)
$$

其中$\mathrm{Z}_{\mathrm{m}}$ 是规范化因子，使得$D_{\mathrm{m}+1}$ 成为一个概率分布：
$$Z_{m}=\sum_{i=1}^{N} \exp \left(-\alpha_{m} y_{i} G_{m}\left(x_{i}\right)\right)$$


AdaBoost 在训练过程中，错分的数据权重系数将会增加; 同时加入了各个树的权重系数来组合各个树的训练结果。

- 优点：
    - 很好的利用了弱分类器进行级联；
    - 可以将不同的分类算法作为弱分类器；
    - AdaBoost具有很高的精度；
    - 相对于bagging算法和Random Forest算法，AdaBoost充分考虑的每个分类器的权重；
- 缺点：
    - AdaBoost迭代次数也就是弱分类器数目不太好设定，可以使用交叉验证来进行确定；
    - 数据不平衡导致分类精度下降；
    - 训练比较耗时，每次重新选择当前分类器最好切分点；

**GBDT**

把当前树的残差作为下一轮的学习目标。

AdaBoost用错分数据点来识别问题，通过调整错分数据点的权重来改进模型。Gradient Boosting通过负梯度来识别问题，通过计算负梯度来改进模型。

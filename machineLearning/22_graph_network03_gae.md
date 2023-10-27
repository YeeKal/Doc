---
title: 图神经网络03 - 图编码器GAE
categories: ml
tags: gnn
date: 2020-12-10
---

## 自编码器

![gae_autoe1.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae_autoe1.png)

自编码器的由一个编码器和一个解码器组成。其基本结构如下：

$$x \rightarrow f_{encoder} \rightarrow z \rightarrow f_{encoder} \hat{x}   \\
\text{$x$:}输入 \\
\text{$z$:}隐向量表达 \\
\text{$\hat{x}$:}输出$$

其优化目标是使得$\hat{x}$与$x$近可能相近，即希望解码器能通过隐向量表达重建出原始的输入$x$。自编码器是生成模型的一种。通过网络结构可以发现，任意在隐向量空间中选择一个点就可以通过解码器生成具有实际意义的$\hat{x}$。自编码器实际上是一个数据特征提取器，其编码器把原始数据转化为低维向量表示，或者说是提取出数据的主要特征;而解码器根据低维向量解码出原始数据。自编码器可以用于数据去噪（例如图像，音频），图像修复，信息检索等过程中。

- 线性自编码器(Linear Autoencoder)：如果编码器使用线性激活函数，则自编码器可以用来实现主成分分析。
- 栈式自编码器(stacked Autoencoders)
- 去噪自编码器: 输入增加噪声，训练之后得到无噪声的输出
- 正则化的自编码器：在损失函数中增加正则项使得编码器学习到更加有用的特征

## 变分自编码器(Variational Autoencoders)

在自编码器中，虽然通过编码器和解码器可以在没有信息损失的情况进行转换，但是隐空间的结构可能只是表达了训练数据的分布情况，而并不能把隐空间的任意一点通过解码都表示成有意义的输出，即在这种过拟合的情况下，隐空间不连续。

变分编码器的编码器输出不是隐空间中的一个点，而是隐空间中的概率分布. 在实践中选择正太分布作为编码器的分布，这一分布实际上由均值$\mu$和方差$\sigma$来表示，而这两个参数是编码器输出的两个向量。则变分编码器的主要训练步骤如下:

![gae_vae1.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae_vae1.png)

- 编码器输出分布向量
- 在该分布中采样一个点
- 对采样点进行解码
- 计算重建误差并进行反向传播

![gae_vae2.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae_vae2.png)

变分编码器使得编码之后的隐向量不再是一个离散的值，而是强制到生成一个由均值和方差控制的分布，这样整个隐空间趋于连续，位于同一分布区域的点具有相同的解码输出，使得编码器具有更大的泛化能力。

![gae_vae3.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae_vae3.png)

**权重共享**

均值网络和方差网络共享部分权重

$$g(x)=g_{2}\left(g_{1}(x)\right), h(x)=h_{2}\left(h_{1}(x)\right), g_{1}(x)=h_{1}(x)$$

**reparametrisation trick**

采样操作本身不可导。通过重参数化，把采样的过程表示为:

$$z=h(x) \zeta+g(x), \zeta \sim \mathcal{N}(0, I)$$即通过采样一个实系数来获得对高维向量的采样，使得该过程可导

**损失函数**

损失函数包括两部分，一个是衡量生成的$\hat{x}$与真实值之间的距离，第二个是让$p(z/x)$分布向标准正太分布看齐。故：

$$L=L_1+L_2    \\
L_1=||x-\hat{x}||^2 \\
\begin{aligned} L_2 &=KL(N(\mu_x,\sigma_x ^2),N(0,1))   \\
&=\frac{1}{2}\sum(-log \sigma_x^2+\mu^2+\sigma^2-1) \end{aligned}$$

正态分布KL散度公式推导：

$$\begin{aligned}
& K L\left(N\left(\mu, \sigma^{2}\right) \| N(0,1)\right) \\
=& \int \frac{1}{\sqrt{2 \pi \sigma^{2}}} e^{-(x-\mu)^{2} / 2 \sigma^{2}}\left(\log \frac{e^{-(x-\mu)^{2} / 2 \sigma^{2}} / \sqrt{2 \pi \sigma^{2}}}{e^{-x^{2} / 2 / \sqrt{2 \pi}}}\right) d x \\
=& \int \frac{1}{\sqrt{2 \pi \sigma^{2}}} e^{-(x-\mu)^{2} / 2 \sigma^{2}} \log \left\{\frac{1}{\sqrt{\sigma^{2}}} \exp \left\{\frac{1}{2}\left[x^{2}-(x-\mu)^{2} / \sigma^{2}\right]\right\}\right\} d x \\
=& \frac{1}{2} \int \frac{1}{\sqrt{2 \pi \sigma^{2}}} e^{-(x-\mu)^{2} / 2 \sigma^{2}}\left[-\log \sigma^{2}+x^{2}-(x-\mu)^{2} / \sigma^{2}\right] d x
\end{aligned}$$

## 图自编码器(GAE)

- 图用 $\mathcal{G}=(\mathcal{V}, \mathcal{E})$ 表示，其中 $\mathcal{V}$ 表示节点集合， $\mathcal{E}$ 表示边集合
- A: 邻接矩阵
- D: 度矩阵
- $N:$ 节点数
- $d$ : 节点的特征（features）维度
- $\mathbf{X} \in \mathbb{R}^{N \times d}$ 表示节点的特征矩阵
- $f$ : embedding 维度
- $\mathbf{Z} \in \mathbb{R}^{N \times f}:$ 节点的 embedding

![gae1.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae1.png)

- encoder: 使用GCN作为编码器

$$Z=GCN(X,A)=$\tilde{\mathbf{A}} \operatorname{ReLU}\left(\tilde{\mathbf{A}} \mathbf{X} \mathbf{W}_{0}\right) \mathbf{W}_{\mathbf{1}}   \\\tilde{\mathbf{A}}=\mathbf{D}^{-\frac{1}{2}} \mathbf{A} \mathbf{D}^{-\frac{1}{2}}, \mathbf{W}_{0} \text { 和 } \mathbf{W}_{\mathbf{1}} \text { 是待学习的参数 }$$

- decoder: 使用内积重构原始的邻接矩阵，以逼近原始的图结构

$$\hat{A}=\sigma(ZZ^T)$$

- loss: 交叉熵作为损失函数

$$\mathcal{L}=-\frac{1}{N} \sum y \log \hat{y}+(1-y) \log (1-\hat{y})   \\
y\in \hat{A}_{ij}$$

## 变分图自编码器(VGAE)

![gae2.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/machineLearning/imgs/gae2.png)

- encoder: 

$$\mu=GCN_{\mu}(X,A)    \\
log\sigma=GCN_{\sigma}(X,A)\\
\text{两个GCN共享$W_0$} $$

- sample: $z=\mu+\epsilon\sigma, \epsilon \sim \mathcal{N}(0, 1)$
- decoder: 使用内积
- train:

$$\mathcal{L}=\mathbb{E}_{q(\mathbf{Z} \mid \mathbf{X}, \mathbf{A})}[\log p(\mathbf{A} \mid \mathbf{Z})]-\operatorname{KL}[q(\mathbf{Z} \mid \mathbf{X}, \mathbf{A}) \| p(\mathbf{Z})]$$




## ref 

- blog
    - [Understanding Variational Autoencoders (VAEs)](https://towardsdatascience.com/understanding-variational-autoencoders-vaes-f70510919f73)
        - [github- code, imgs](https://github.com/WojciechMormul/vae)
    - [图自编码器的起源和应用](https://zhuanlan.zhihu.com/p/112206566)
- personal code
    - [github-vae](https://github.com/bojone/vae)
- paper
    - [2014_Auto-Encoding Variational Bayes]()
    - [2016_Tutorial on Variational Autoencoders]()
    - [Variational Graph Auto-Encoders]()
    - [2018-Graph Convolution Matrix Completion]()
- project
    - [gae-tf](https://github.com/tkipf/gae)
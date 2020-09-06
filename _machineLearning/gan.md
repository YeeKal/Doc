---
 title: gan
 categories: ml
 tags: ml
 date: 2018-06-13
---

##generative adversarial nets



- generative model G
- discriminative model D
    - 生成网络是造样本的，它的目的就是使得自己造样本的能力尽可能强，强到什么程度呢，你判别网络没法判断我是真样本还是假样本。
    - 判别网络目标就是尽量把G生成的图片和真实的图片分别开来
    - 最理想的状态下,G可以生成足以“以假乱真”的图片G(z)。对于D来说，它难以判定G生成的图片究竟是不是真实的，因此D(G(z)) = 0.5.
- 对抗样本
    - 向一副图像中加入随机噪声，确保噪声的强度非常低（L2范数小），以至于在视觉上不可感知，但是却能够实现加入噪声的图像与原始图像在向量空间中相距很远。
    
**Maxmin strategy**

最大最小策略

$$\min_{G}\max_{D}V(D,G)=E_{x~P_{data}(x)}(logD(x))+E_{x~P_z(z)}(log(1-D(G(z))))$$


网络存在着不收敛问题；网络不稳定；网络难训练





## Conditional Generative Adversarial Nets

## DCGAN

设计一种类似反卷积的结构：Deep convolutional NN for GAN. 采用一个随机噪声向量作为输入,
如高斯噪声。输入通过与CNN类似但是相反的结构，将输入放大成二维数据.

**reference**

0. [不要怂，就是GAN](http://www.cnblogs.com/Charles-Wan/p/6266279.html)
1. [paper1](https://arxiv.org/pdf/1406.2661.pdf)
3. [paper3](Unsupervised Representation Learning with Deep Convolutional Generative Adversarial Networks)
4. [AdversarialNetsPapers](https://github.com/zhangqianhui/AdversarialNetsPapers)

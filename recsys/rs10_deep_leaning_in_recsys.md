---
title: 深度学习在推荐系统中的应用
categories: recsys
tags: recsys
date: 2021-01-12
---

Ensemble learning: 混合模型学习, [ref1](http://www.scholarpedia.org/article/Ensemble_learning#Voting_based_methods) 

- Deep&Wide
- DeepFM
- XDeepFM
- AiBox
- DCN: Deep Cross Net, 2019 google

1. CF models:
    - Based on Neural Collaborative Filtering (NCF) framework:
        - NeuMF: Neural Matrix Factorization (He et al, WWW'17) 
        - ConvNCF: Outer Product-based NCF (He et al, IJCAI'18) 
    - Based on Translation framework:
        - TransRec: Translation-based Recommendation (He et al, Recsys'17) 
        - LRML: Latent Relational Metric Learning (Tay et al, WWW'18)
2. Feature-based models:
    - Based on Multi-Layer Perceptron:
        - Wide\&Deep (Cheng et al, DLRS'16), 
        - Deep Crossing (Shan et al, KDD'16) 
    - Based on Factorization Machines (FM):
        - Neural FM (He and Chua, SIGIR'17), 
        - Attentional FM (Xiao et al, IJCAI'17), 
        - DeepFM (Guo et al, IJCAl'17)

## 2016 wide &deep

![2016_deep_wide.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/recsys/imgs/2016_deep_wide.png)

two parts:
- wide component: a linear model, $y=\mathbf{w}^{T} \mathbf{x}+b$ 
- deep component: feed-forward neural network, $a^{(l+1)}=f\left(W^{(l)} a^{(l)}+b^{(l)}\right)$

Area Under Receiver Operator Characteristic Curve (AUC)

## 2016 deepFM

![2016_deepfm.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/recsys/imgs/2016_deepfm.png)

replace linear model with fm model


## ref

1. blog:
    - [CTR预估模型：DeepFM/Deep&Cross/xDeepFM/AutoInt代码实战与讲解](https://zhuanlan.zhihu.com/p/109933924)
    - [CTR预估模型发展过程与关系图谱](https://zhuanlan.zhihu.com/p/104307718)
    - [从FM推演各深度CTR预估模型(附代码)](https://blog.csdn.net/longxinchen_ml/article/details/81031736)
    - [推荐系统CTR实战——Deep & Cross](https://fuhailin.github.io/Deep-and-Cross-Network/)
    - [谷歌、阿里们的杀手锏：三大领域，十大深度学习CTR模型演化图谱](https://cloud.tencent.com/developer/article/1455807)
    - [](https://www.jianshu.com/nb/21403842)
2. personal code:
    - [Deep-Cross-Net](https://github.com/FitzFan/Deep-Cross-Net)
    - [github-CTR模型代码实战](https://github.com/NELSONZHAO/zhihu/tree/master/ctr_models)
    - [CTR Prediction 论文、个人学习笔记分享](https://github.com/duboya/CTR-Prediction)
3. open project



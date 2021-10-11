---
title: POMDP
categories: autopilot
tags: mdp
date: 2021-10-11
---

```
----------------------------------------------------------------
                不考虑动作              考虑动作
-----------------------------------------------------------------
状态可见        马尔科夫链(MC)      马尔可夫决策过程(MDP)
状态不完全可见  隐马尔可夫模型(HMM)   不完全可观察马尔可夫决策过程(POMDP)
-----------------------------------------------------------------
```

## Partially Observable System

MDP中是寻找状态到动作的映射，而POMDP是寻找状态的的概率分布(probability distribution over states)到动作的映射。这一概率分布被成为`belief state`. 首先belief是关于状态的概率分布，如果采取一个动作之后，会转移到下一个belief，这个转移也是一个关于动作和belief的概率分布，转移的结果belief-next又是新一轮的概率分布。

- 值函数 $V(b)$


## 决策规划求解：

- offline
    - 基于点的值迭代
        - PBVI
        - FBVI
        - Perseus
    - 策略迭代
- online
    - POMCP
    - DESPOT

## ref

- project
    - [POMDP算法之PBVI讲解及c++实现](https://zhuanlan.zhihu.com/p/272867881)
- blog
    - [pomdp tutorial](https://www.techfak.uni-bielefeld.de/~skopp/Lehre/STdKI_SS10/POMDP_tutorial.pdf)
    - [Tony's POMDP Page](http://cs.brown.edu/research/ai/pomdp/)
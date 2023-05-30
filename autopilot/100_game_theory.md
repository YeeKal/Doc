---
title: 博弈论
categories: 
tags: 
date: 2023-05-10
---
## normal form

相对于`extensive form`, 另一种博弈的表示形式, 通过收益矩阵(payoff matrix / payoff table)来表示.


- $s_i$ action performed by player $i$
- $s_{-i} = \{s1, \cdots, s_{i-1}, s_{i+1}, s_N\}$ set of actions performed by all the other players

**<font color='Tomato'>Best Response(最优反应)</font>**

$$J_i(s_i^*, s_{-i}) \geq J_i(s_i, s_{-i})$$

**<font color='Tomato'>Nash equilibrium(纳什均衡)</font>**

$$J_i(s_i^*, s^*_{-i}) \geq J_i(s_i, s^*_{-i})$$

对于一个策略组合,每一个玩家的策略想对于其他玩家的策略都是最优的,则该策略组合就达到了一个纳什均衡. 不一定是最优的结果,但是一种稳定的局面. 没有玩家可以在不减少收益的情况下单边改变决策.

## 博弈

策略式博弈:
- 所有玩家同时做策略选择
- 知道对手可选的策略
- 不知道对手具体会选哪一个策略
- 非合作

完全信息博弈


Payoff matrix: 收益矩阵
Domain strategy: 主导策略

zero sum game: 零和博弈, in other words the utilities of both players are opposite

Nash equilibria: 纳什均衡, 对于一个策略组合,每一个玩家的策略想对于其他玩家的策略都是最优的,则该策略组合就达到了一个纳什均衡. 不一定是最优的结果,但是一种稳定的局面.
- Mixed strategy:混合策略, each player chooses the optimal frequency, 根据概率分布
- 纯策略, 比赛规则的完整定义

Pareto Optimality 帕累托最优

Utility, 效用

two players payoff matrix $A, B$, use a vector to represent the strategy $\sigma_a, \sigma_b$, the utility:

$$\sigma_a A\sigma_b^T, \sigma_a B \sigma_b^T$$

## 混合策略
纳什均衡。每个玩家可选的策略也叫纯策略.但有的时候并不能找到一个纯策略的纳什均衡, 以石头剪刀布为例，无论双方采用哪种策略组合，输的一方总可以改变策略使自己反败为胜.

混合策略是给每个纯策略分配一个概率，一个玩家的策略集就是一个“样本空间”.

假设策略集 $A_i = \{a_{i1}, a_{i2}, \cdots, a_{in}\}$, 纯策略可以认为是策略集中的某个策略,而混合策略是给定指策略集一个概率分布,因此纯策略可以看作是其它策略的概率都为0的退化的混合策略.

$$\begin{aligned} \text{纯策略 } & p_k = a_{ik} = (0, \cdots, 1,  \cdots, 0) \begin{bmatrix} a_{i1}\\ a_{i2}\\ \cdots\\ a_{in} \end{bmatrix} \\
\text{混合策略 } & p_k = (p_{i1}, p_{i2}, \cdots, p_{in}) \begin{bmatrix} a_{i1}\\ a_{i2}\\ \cdots\\ a_{in} \end{bmatrix}, p_{i,j}\leq 0, \sum_j p_{ij} = 1
\end{aligned}
$$

收益: 期望收益


混合策略纳什均衡(MNE, mixed strategy Nash equilibrium)

最优反应  其他玩家在混合策略纳什均衡下的混合策略

纳什定理：有限的策略式博弈一定存在混合策略纳什均衡
有限指：有限的玩家，每个玩家都有有限种纯策略。

混合策略计算: 玩家选任意一种纯策略的期望收益是相同的, 如果玩家的纯策略的期望收益不同的话，那么他会一直选期望收益高的那个，也就是选择一个纯策略，而不是混合策略

## fictitious /fɪkˈtɪʃəs/ play

虚拟对抗

## 自动驾驶决策上的应用

完美贝叶斯均衡, 进化博弈论

## Game Theoretic Decision Making

## ref

- [Nashpy](https://nashpy.readthedocs.io/en/stable/index.html)

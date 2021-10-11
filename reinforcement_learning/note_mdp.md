---
title: MDP 马尔可夫过程
categories: rl
tags: rl
date: 2021-10-11
---


1. S: state
2. A: action
3. R: reward，个体在$S_t$采取动作$A_t$对应的奖励为$R_{t+1}$
4. $\pi$: policy,策略，即在某一状态下如何选择动作，常以条件概率表示为$\pi(a/s)=P(A_t=a|S_t=s)$，即在状态s时采取动作a的概率
5. v: value, 在策略$\pi$和状态s下，进入下一个状态后的价值，又被称为值函数，表示为$v_\pi(s)$. 事实上值函数代表当前状态的价值，而是否能达到目的还跟未来的状态有关，故当前值函数也跟未来状态的值函数有关。v函数可以理解为是在状态稳定之后的该状态下的最终的结果，而R函数是当前的即时奖励。
$$v_\pi(s)=\mathbf{E}_\pi(R_{t+1}+\gamma R_{t+2}+\cdots| S_t=s)$$
6. $\gamma$: discount rate(reward decay rate), 如果为0，则是贪婪法，即价值只由当前延时奖励决定，如果是1，则所有的后续状态奖励和当前奖励一视同仁。大多数时候，我们会取一个0到1之间的数字，即当前延时奖励的权重比后续奖励的权重大
7. $P^a_{ss'}$: state transition model，在当前状态s采取动作a后转到下一个状态s‘的概率，虽然大部分问题的的状态转化模型为1. P predicts the next state, R predicts the next reward.
$$P^a_{ss'}=P[S_{t+1}=s'|S_t=s,A_t=a] \\
R^a_s=E[R_{t+1}|S_t=s,A_t=a]$$
8. $\epsilon$: exploration rate

策略的理解是状态到动作的分布概率，表示在某一状态下选择某一个动作的可能性。在控制中表示当前状态下应该采取什么样的控制量。而动作实施的过程类似于动力学方程，根据当前状态以及控制量更新下一个状态。

控制中控制量与状态是没有关系的，而在MDP中为两者搭上了关系。

Policy Iteration（策略迭代）：

- 策略评估(Policy Evaluation): 根据当前策略计算值函数$V(s)$
- 策略提升(Policy Improvement): 更新策略， 计算当前策略分布

Value Iteration(值迭代)
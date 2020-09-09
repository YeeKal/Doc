Simulation Based Search

**forward search**

Build a search tree with the current state $s_t$ and each final node reaches the end. Then select the action which maximum the reward.
1. simulate episodes os experience from now with the model
$$\{s_t^k,A_t^k,R_{t+1}^k,\cdots,S_T^k\}_{k=1}^K\sim M$$ 
2. apply model_free RL to simulated episodes

## MCTS

[MCTS.ai](http://mcts.ai/index.html)

Monte-Carlo Tree Search

**simple Monte-Carlo search**

1. given a model $M_v$ and a simulation policy $\pi$
2. for **each action** $a\in A$
    - simulate k episodes from current real state $s_t$
        $$\{s_t^k,a,R_{t+1}^k,\cdots,S_T^k\}_{k=1}^K\sim M_v,\pi$$
    - evaluate actions by mean return (Monte-Carlo evaluation)
        $$Q(s_t,a)=\frac{1}{K}\sum^K_{k=1}G_t$$
3. select action with maximum value
        $$a_t=arg\max_{a\in A}Q(s_t,a)$$

**Monte-Carlo tree search**

1. given a model $M_v$ 
2. simulate K episodes from current state $s_t$ using current simulation policy $\pi$
    $$\{s_t^k,A_t^k,R_{t+1}^k,\cdots,S_T^k\}_{k=1}^K\sim M_v,\pi$$
3. build a search tree containing visited states and actions
4. evaluate actions $Q(s,a)$ by mean return of episodes from s,a
    $$Q(s_t,a)=\frac{1}{N(s,a)}\sum^K_{k=1}\sum_{u=t}^TG_u$$
5. select action with maximum value in search tree
    $$a_t=\arg \max_{a\in A}Q(s_t,a)$$

Each simulation consists of two phases(in-tree,out-of-tree):
- tree policy(improves): pick actions to maximise $Q(S,A)$
- default policy(fixed): pick actions randomly

Repeat (each simulation):
- evaluate $Q(S,A)$ 
- improve tree policy, e.g by $\epsilon - greedy(Q)$


**Uppder Confidence Bound(UCB)**

$$score=\frac{w_i}{n_i}+c\sqrt{\frac{ln N_i}{n_i}}$$

UCT: Uppder Confidence Bound for Trees, UCT=MCTS+UCB


[alphag0](https://zhuanlan.zhihu.com/p/20893777)
[build own github](https://github.com/AppliedDataSciencePartners/DeepReinforcementLearning)
[五子棋](https://github.com/junxiaosong/AlphaZero_Gomoku)

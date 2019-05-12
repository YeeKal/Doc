---
 title: 07_hmm
 categories: ml
 tags: ml
 date: 2018-06-05
 ---

## Hidden Markov Model

dynamic clustering

**生成模式**

- generating patterns
    - deterministic patterns
    - non-deterministic patterns
        - 状态量
        - pi向量：初始化概率
        - 状态转移矩阵

**隐藏模式**

**Markov process**

未来状态只依赖于当前状态。

- hidden space
- observed space
- start probability
- transition probabilities
- emission probabilities

**three main questions**

- evaluation:
    - given: an hmm M AND a sequence x
    - find: prob(x|M)
    - forward
- decoding
    - given: an HMM M and a sequence x
    - find: the sequence y of states that maximizes the most probable subsequence of states 
    - Viterbi, forward-backward
- learning
    - given: an HMM M with unspecified transition/emission probs, and a sequence x,
    - parameters $\theta=(\pi_i,\alpha_{ij},\eta_{ik})$ that maximize $P(x|\Theta)$
    - Baum-welch 

## solutions

**forward algorithm**

1. 穷举搜索(exhausive search for solution)
2. 递归(recursive solution)
    - 假设上一时间概率已知，则通过哥哥状态的概率相加得出这一时刻的概率



**reference**

1. [我爱自然语言处理](http://www.52nlp.cn/category/hidden-markov-model)

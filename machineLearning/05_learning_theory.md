---
 title: 05_learning_theory
 categories: ml
 tags: ml
 date: 2018-04-30
---

1. 应该选择哪种模型可以使误差最小？
2. 在最优模型下应该选择多大的参数？

**generalization error**: expected error on examples

- bias: few features
- variance: more features
- tradeoff: 权衡，折衷

**preliminaries**

- the union bound

$$P(A_1)\cup\dots\cup A_k\le P(A_1)+\dots+P(A-k)$$

- hoeffding inequality(Chernoff bound): Let $P(Z_i=1)=\varnothing$, and $P(Z_i=0)=1-\varnothing$. Assign $\hat{\phi}=(1/m)\sum_{i=1}^{m}Z_i$ and let any $\lambda> 0$ be fixed. Then:
$$P(|\phi-\hat{\phi}|>\lambda)\le 2exp(-2\lambda^2m)$$

- training error/empirical error: 经验误差，训练误差
$$\hat{\varepsilon}(h)=1/m\sum^m_{i=1}{h(x)\neq y}$$
- the generalization error
$$\varepsilon(h)=P_{x,y}~{h(x)\neq y}$$
- empirical risk minimization(ERM): 训练模型中最小化经验误差以更新参数值的过程
- $\mathcal{H}$, the set of all classifiers

**case of finite $\mathcal(H)$**

The strategy to give guarantees on the generalization error of $\hat{h}$ will be demonstrated in two parts: $\hat{\varepsilon}(h)$ is a reliable estimate of $\varepsilon(h)$ for all $h$; the upper-bound on the generalization error of $\hat{h}$ will be derived then.

$$
P(\exists h\in \mathcal{H}|\varepsilon(h_i)-\hat{\varepsilon}(h_i)|>\lambda)\leq\sum^k_{i=1}2exp(-2\lambda^2m)          \\
P(\forall h\in \mathcal{H}|\varepsilon(h_i)-\hat{\varepsilon}(h_i)|\leq\lambda)\geq 1-\sum^k_{i=1}2exp(-2\lambda^2m)
$$

Let $\sigma>0$, how large must m be before we can guarantee that with probability at least $1-\sigma$, training error will be within $\lambda$ of generalization error?
$$1-\sigma\leq 1-\sum^k_{i=1}2exp(-2\lambda^2m)          \\
m\geq \frac{1}{2\lambda^2}log\frac{2k}{\sigma}
$$

Similarity, if m and $\sigma$ is fixed and solve for $\lambda$ in the previous equation:
$$|\varepsilon(h_i)-\hat{\varepsilon}(h_i)|\leq\sqrt{\frac{1}{2m}log\frac{2k}{\sigma}}$$
Define: $\hat{h}=argmin_{h\in\mathcal{H}}\hat{\varepsilon}(h)$, $h^*=argmin_{h\in\mathcal{H}}\varepsilon(h)$ is the best possible hypothesis.
$$\begin{align}
\varepsilon(\hat{h})&\leq \hat{\varepsilon}(\hat{h})+\lambda  \\
                    &\leq \hat{\varepsilon}(h^*)+\lambda       \\
                    &\leq \varepsilon(h^*)+\lambda
  \end{align}$$

If uniform convergence occurs, then the generalization error of $\hat{h}$ is at most $2\lambda$ worse than the best possible hypothesis in $\mathcal{H}$

**case of infinite $\mathcal(H)$**

- growth function: 假设空间H对m个示例所能赋予标记的最大可能结果数
- dichotomy: 对分, 对于二分类问题的增长函数
- Vapink-Chervonenkis Dimension: 能被H打散的最大的示例集（数据集）的大小

$$m\geq \frac{1}{\varepsilon}(4log_2(\frac{2}{\sigma})+8VC(H)log_2(\frac{13}{\varepsilon}))$$


**PAC**

- version space: A hypothesis h is consistent with a set of training examples D
if and only if $h(x)=y(x)$ for each training example. The version space is the consistent hypothesis in $\mathcal{H}$, denoted as $VS_{H,D}$
- consistent learner: the learner outputs hypothesis that perfectly fits the training data.
-  The version space is said to be $\varepsilon-exhausted$ if every hypothesis h in VS has true error less than $\varepsilon$.

Probability that the version space is not $\varepsilon-exhausted$ is at most $|H|e^{-\varepsilon m}$.

Suppose we want this probability to be at most $\sigma$:
$$H|e^{-\varepsilon m}\leq \sigma \\ 
    m\geq \frac{1}{\varepsilon}(ln|H|+ln(\frac{1}{\sigma})) \\
    \varepsilon\leq \frac{1}{m}(ln|H|+ln(\frac{1}{\sigma}))$$

A learning algorithm is PAC learnable if it:

- requires no more than polynomial computation per trainingexample
- no more than polynomial number of samples

In agnostic learning, $y\notin \mathcal{H}$, then:
$$m\geq \frac{1}{2\varepsilon^2}(ln|H|+ln(\frac{1}{\sigma}))$$


**algorithm diagnosing**

- training set 60%: to train the models
- cross validation set 20%: to choose the model with lower error
- test set 20%: to assess the model

**bias vs. variance**

- high bias: underfit, $J_{train}$ and $J_{cv}$ are both high. Also $J_{train}\approx J_{cv}$
- high variance: $J_{train}$ is low, while $J_{cv}$ is high

**regularization parameter**

As $\lambda$ increases, the fit becomes more rigid. And as $\lambda$ decrease we trend to overfit the data. The solution is to train the model with a list of $\lambda_s$ and compute the $J_{cv}$ **without** $\lambda$.

**set size**


---
 title: 05_bayesian_learning
 categories: ml
 tags: ml
 date: 2018-06-03
 ---

## Bayesian learning

**conditional probability**

事件B发生的条件下事件A发生的概率：

$$P(A|B)=\frac{P(AB)}{P(B)}$$

**Bayesian theory**

We know $P(A|B)$, but we focus more on $P(B|A)$ :

$$P(B|A)=\frac{P(A|B)P(B)}{P(A)}$$

**optimal classifier**

If $P(y_K|x)=max\{P(y_1|x),P(y_2|x)\cdots P(y_k|x)\}$, then $x\in y_k$.

According to Bayesian theory:

$$P(y_i|x)=\frac{P(x|y_i)P(y_i)}{P(x)}$$

For $\forall P(y_i|x)$, $P(x)$ is the same. So only numerators matter(Naive Bayes assumption: features are conditionally independent):

$$P(x|y_i)P(y_i)=P(x_1|y_i)P(x_2|y_i)\cdots P(x_n|y_i)P(y_i)=P(y_i)\prod_{j=1}^{m}P(x_j|y_i)$$

**Beta distribution**

对概率的概率分布，区间(0,1). 概率密度函数：

$$f(\theta;\alpha,\beta)=\frac{\theta^{\alpha-1}(1-\theta)^{\beta-1}}{B(\alpha,\beta)}$$

expectation: $\frac{\alpha}{\alpha+\beta}$

二项分布：$P(data|\theta)\varpropto \theta^z(1-\theta)^{N-z}$

beta 分布: $Beta(a,b)\varpropto \theta^{a-1}(1-\theta)^{b-1}$

在贝叶斯估计中: 
$$P(\theta|data)=\frac{P(data|\theta)P(\theta)}{P(data)}\varpropto P(data|\theta)P(\theta)$$ 
需要在给定数据情况下求出$\theta$的值. 现在我们将Beta分布代进$P(\theta)$, 将二项分布代入$P(data|\theta)$:

$$\begin{align}
P(\theta|data)&\varpropto \theta^z(1-\theta)^{N-z}*\theta^{a-1}(1-\theta)^{b-1}\\
&  \varpropto \theta^{z+a-1}(1-\theta)^{N-z+b-1}\\
&  \varpropto \theta^{'a-1}(1-\theta)^{b'-1}
\end{align}$$

得到的贝叶斯估计服从Beta(a',b')分布，即"Beta distribution is binomial conjugate prior(共轭先验)."用B函数将它标准化就得到后验概率：

$$P(\theta|data)=\frac{\theta^{a'-1}(1-\theta)^{b'-1}}{B(a',b')}$$

- maximum likelihood estimation(MLE): choose value that maximizes the probability of observed data
    $$\hat{\theta}_{MLE}=argmax_{\theta}P(D|\theta)$$
- maximum a posterior estimation(MAP): choose value that is most probable given observed data and prior belief
    $$\hat{\theta}_{MLE}=argmax_{\theta}P(\theta|D)=argmax_{\theta}P(D|\theta)P(\theta)$$

    $$\begin{align} 
     \hat{\theta}_{MLE}&=\frac{\alpha}{\alpha+\beta} \\
     \hat{\theta}_{MAP}&=\frac{\alpha+\alpha_H-1}{\alpha+\alpha_H+\beta+\beta_H-2}
    \end{align}$$

**Naive Bayes**

naive bayes assumption: features are conditionally independent given class.

## GNB

GNB: Gaussian Naive Bayes, which is designed for continuous features.

**Assumptions**

- Y is boolean, goverened by a Bernoulli distribution, with parameter $\pi=P(Y=1)$
- each $x_i$ is a continuous random variable
- for each $x_i,\quad P(x_i|Y=y_k)$ is a Gaussian distribution of the form $N(\mu,\sigma)$
- for each $x_i$, they are conditionally independent


With the conditional assumption:
$$P(Y=1|X)=\frac{P(Y=1)P(X/Y=1)}{P(Y=1)P(X|Y=1)+P(Y=0)P(X|Y=0)}$$

Define: $\theta_{i1}=P(X_i=1|Y=1),\quad \theta_{i0}=P(X_i=1|Y=0)$, and then:
$$P(X_i|Y=1)=\theta^{X_i}_{i1}(1-\theta_{i1})^{(1-X_i)} \\
P(X_i|Y=0)=\theta^{X_i}_{i0}(1-\theta_{i0})^{(1-X_i)}$$

So:

$$\begin{align}
P(Y=1|X)&=\frac{P(Y=1)P(X/Y=1)}{P(Y=1)P(X|Y=1)+P(Y=0)P(X|Y=0)}  \\
    &=\frac{1}{1+\frac{P(Y=0)P(X|Y=0)}{P(Y=1)P(X|Y=1)}} \\
    &=\frac{1}{1+exp(ln\frac{P(Y=0)P(X|Y=0)}{P(Y=1)P(X|Y=1)})}  \\
    &=\frac{1}{1+exp(ln\frac{P(Y=0)}{P(Y=1)}+\sum_{i=1}^n ln\frac{P(X_i|Y=0)}{P(X_i|Y=1)})}  \\
    &=\frac{1}{1+exp(ln\frac{P(Y=0)}{P(Y=1)}+\sum_{i=1}^n (ln(\frac{\theta_{i0}(1-\theta_{i1})}{\theta_{i1}(1-\theta_{i0})})X_i+ln\frac{1-\theta_{i0}}{1-\theta_{i1}})}  \\
    &=\frac{1}{1+exp(\omega_0+\sum_{i=1}^n\omega_i X_i)} \\
P(Y=0|X)&=1-P(Y=1|X)=\frac{exp(\omega_0+\sum_{i=1}^n\omega_i X_i)}{1+exp(\omega_0+\sum_{i=1}^n\omega_i X_i)}
\end{align}$$

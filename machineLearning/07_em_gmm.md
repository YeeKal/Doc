---
 title: 07_em_gmm
 categories: ml
 tags: ml
 date: 2018-05-16
---

## EM算法

Expectation Maximization Algorithm(最大期望算法)：用于含有隐含变量(hidden variable)的概率参数模型的最大似然估计。

- Jensen 不等式
    - 凸函数（向下鼓，二阶导大于等于0），则$E(f(x))\leq f(E(x))$.
    - 凹函数，则$E(f(x))\geq f(E(x))$

训练样本$[x^{(1)},\dots,x^{(m)}]$相互独立，我们想找到每个样例隐含的类别z使得$p(x,z)$最大，最大似然估计：
$$\begin{align}
l(\theta)&=\sum^{m}_{i=1}logp(x:\theta)\\
&=\sum^{m}_{i=1}log\sum_{z}p(x,z:\theta)
\end{align}$$
第二步中对每个样本实例的可能的类别z求联合分布概率之和。$z$是未知的隐含变量，通过不断的建立$l$的下界(E-step),再优化下界(M-step),依次迭代，直至算法收敛到局部最优解。

对于每个实例$i$,$Q_i$表示隐含变量$z$的某种分布，且$\sum Q_i(z)=1,Q_i(z)\geq 0$,对上式作变换：
$$\begin{align}
l(\theta)&=\sum^{m}_{i=1}log\sum_{z}p(x,z:\theta)\\
        &=\sum_{i}log\sum_{z^{(i)}}Q_i(z^{(i)})\frac{p(x^{(i)},z^{(i)}:\theta)}{Q_i(z^{(i)})} \\
        &\geq \sum_{i}\sum_{z^{(i)}} Q_i(z^{(i)})log\frac{p(x^{(i)},z^{(i)}:\theta)}{Q_i(z^{(i)})}=J(z,Q)
\end{align}$$
上式最后一步的转化过程：把最后一个连加看作是求期望的过程，其中$Q_i(z^{(i)})$可以视作概率密度($\sum Q_i(z)=1$),而第一个连加中的$log$看作凹函数，再由Jensen不等式可得到此变换。

EM算法更新：

- 初始化分布参数：$\theta$
- 重复E-step，M-step
    - E: 根据$\theta$估计每一个样例属于$z^{(i)}$的概率
    $$\begin{align}Q_i(z^{(i)})&=\frac{p(x^{(i)},z^{(i)}:\theta)}{\sum_z p(x^{(i)},z^{(i)}:\theta)}\\
    &=\frac{p(x^{(i)},z^{(i)}:\theta)}{ p(x^{(i)}:\theta)}  \\
    &=p(z^{(i)}|x^{(i)}:\theta)
     \end{align}$$
    - M： 根据$Q_i(z^{(i)})$由最大似然估计$\theta$ 
    $$\theta:=arg \max_{\theta}\sum_i\sum_{z^{(i)}}Q_i(z^{(i)})log\frac{p(x^{(i)},z^{(i)}:\theta)}{Q_i(z^{(i)})}$$
    - 若$l(\theta)^{t+1}-l(\theta)^{t}$足够小，则结束

##GMM

Gaussian mixture model(GMM): 高斯混合模型，单一高斯概率密度的延伸，可以平滑地近似任意形状地密度分布。**一般来说，一个混合模型可以使用任何概率分布，这里使用高斯混合模型是因为高斯分布具备很好的数学性质以及良好的计算性能(模型参数容易计算，体现在EM算法中的M step).**

概率密度函数：
$$p(x|\mu,\sigma^2)=\frac{1}{\sqrt{2\sigma^2\pi}}e^{\frac{(x-\mu)^2}{2\sigma^2}}$$

多个高斯模型的线性叠加：
$$p(x)=\sum^K_{k=1}\pi_k\mathcal{N}(x|\mu_k,\Sigma_k)$$
其中$\mathcal{N}(x|\mu_k,\Sigma_k)$是第$k$个分量，$K$表示分量个数,$\pi_k$是分量权重，且满足(保证概率密度归一化)：
$$\sum_{k=1}^K\pi_k=1,0\leq\pi_k\leq 1$$

在男女身高的例子中统计量$\mathcal{X}$是一维的，统计量也可能是多维的。由于需要同时对模型的参数和类别进行估计，故EM算法可以用在高斯混合模型的求解上。此时$\theta=(\pi,\mu,\Sigma)$。

- 初始化高斯分布参数$\theta_k, k=[1,K]$
- E-step: 计算每个数据$j$来自子模型$k$的概率：
$$\gamma_{jk}=\frac{\pi_k\mathcal{N}(x_j|\mu_k,\Sigma_k)}{\sum \pi_k\mathcal{N}(x_j|\mu_k,\Sigma_k)}$$
- M-step: 计算新一轮的模型参数
$$\begin{align}
\pi_k&=\frac{\sum_{j=1}^N \gamma_{jk}}{N} \\
\mu_k&=\frac{\sum_{j=1}^N(\gamma_{jk}x_j)}{\sum_{j=1}^N \gamma_{jk}}  \\
\Sigma_k&=\frac{\sum_{j=1}^N \gamma_{jk}(x_j-\mu_k)(x_j-\mu_k)^T}{\sum_{j=1}^N \gamma_{jk}}
\end{align}$$
- 重复E/M直至收敛。
    
## GDA

Gaussian Discriminant Analysis: 高斯判别分析。

**多变量正态分布**

- mean vector $\mu \in R^n$,
- covariance matrix $\Sigma \in R^{n\times n}$,对称且半正定

多变量高斯分布：$x\sim \mathcal{N}(\mu,\Sigma)$
$$p(x|\mu,\Sigma)=\frac{1}{(2\pi)^{n/2}}exp(-\frac{1}{2}(x-\mu)^T\Sigma^{-1}(x-\mu))$$

**GDA model**

对于一个分类问题，若输入特征是连续变量，便可以通过GDA模型对特征变量进行建模。通过标记的数据点求出高斯分布的参数，从而划分出分类区域。



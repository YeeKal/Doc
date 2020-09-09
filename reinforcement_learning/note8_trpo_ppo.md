## TRPO: trust region policy optimization

[强化学习进阶-知乎](https://zhuanlan.zhihu.com/p/26308073)
[RL — Trust Region Policy Optimization  ](https://medium.com/@jonathan_hui/rl-trust-region-policy-optimization-trpo-explained-a6ee04eeeee9)
[RL — Trust Region Policy Optimization Part 2](https://medium.com/@jonathan_hui/rl-trust-region-policy-optimization-trpo-part-2-f51e3b2e373a)
[推倒-知乎](https://zhuanlan.zhihu.com/p/60257706)

回顾策略梯度更新公式：
$$\theta:=\theta+\alpha\bigtriangledown_\theta J$$
当步长$\alpha$不合适时，更新的参数所对应的策略是一个更不好的策略，当利用这个更不好的策略进行采样学习时，再次更新的参数会更差。因此在更新的时候需要保证选取的是合适的步长。所谓合适的步长是指当策略更新后，价值函数的值不能更差，或者单调递增。TRPO主要用来解决如何使价值函数单调不减。

定义价值回报函数：
$$\eta(\pi')=E_{r|\pi'}(\sum_{t=1}^\infty \gamma^t(r(s_t)))$$
参数更新前后：
$$\eta(\pi')=\eta(\pi)+E_{s_0,a_0,...|\pi '}(\sum_{t=1}^\infty \gamma^t(A_\pi(s_t,a_t))) \\
A_\pi(s,a)=Q_\pi(s,a)-V_\pi(s) \rightarrow \text{advantage function}$$
$A_\pi(s,a)$衡量当前动作想对于平均价值函数的优势，也是新旧策略奖励差。

加入策略项,其中$\sum_a\pi'(a|s)$为对动作a的边际分布，$\sum_{s}P(s_t=s|\pi')$为对状态s的边际分布：
$$\eta(\pi')=\eta(\pi)+\sum_{t=0}^\infty\sum_{s}P(s_t=s|\pi')\sum_a\pi'(a|s)\gamma^tA_{\pi}(s,a) \\
\text{define } \rho_{\pi}=P(s_0=s)+\gamma P(s_1=s)+...\\
\eta(\pi')=\eta(\pi)+\sum_{t=0}^\infty \rho_{\pi'}\sum_a\pi'(a|s)A_{\pi}(s,a)
$$

优化目标：
$$ \max_{\pi'} \eta(\pi')=\max_{\pi'} \eta(\pi')-\eta(\pi)\\
J(\pi')=\sum_{t=0}^\infty \rho_{\pi'}\sum_a\pi'(a|s)A_{\pi}(s,a)$$

这时状态s的分布由新策略产生，对新策略依赖严重。

**Tips**

1. 忽略参数更新对状态分布变化的影响：
$$\eta(\pi')=\eta(\pi)+\sum_{t=0}^\infty \rho_{\pi}\sum_a\pi'(a|s)A_{\pi}(s,a)$$
2. 利用重要性采样对动作分布进行的处理(importance sampling)

In **importance sampling**, we offer the choice of not sampling the value of f(x) from p. Instead, we sample data from q and use the probability ratio between p and q to recalibrate the result.
$$E_{x\sim p}(f(x))=E_{x\sim q}(\frac{f(x)p(x)}{q(x)})$$
$$\begin{align}J(\pi')&=\sum_{t=0}^\infty \rho_{\pi}\sum_a \pi(a|s)\frac{\pi'(a|s)}{\pi(a|s)}A_{\pi}(s,a)  \\ L(\pi') &=\frac{1}{1-\gamma}E_{s\sim\rho_\pi,a\sim\pi}\frac{\pi'(a|s)}{\pi(a|s)}A_{\pi}(s,a) \\
&=E_{s\sim\rho_\pi,a\sim\pi}\frac{\pi'(a|s)}{\pi(a|s)}A_{\pi}(s,a) \rightarrow \text{lower bound function}
\end{align}$$
 $L(\pi)$与$J(\pi)$一阶近似。
 $$\eta(\pi')-\eta(\pi)\geq L(\pi')-CD_{KL}^{max}(\pi'||\pi)$$
 define $M(\pi)=L(\pi')-CD_{KL}^{max}(\pi'||\pi)$, $M(\pi')$是$J(\pi')$的下界，则最大化这个函数（$\max \min f(x)$）可以保证单调不减，又不至于步长过度。$C=\frac{2\epsilon\gamma}{(1-\gamma)^2}$,$D_{KL}$是两个数据分布之间的散度：$D_{KL}(P||Q=\sum_{x=1}^{N}P(x)log\frac{P(x)}{Q(x)}$.

 根据拉格朗日对偶性(Lagrangian Duality)，问题可转化为约束优化问题：
 $$\max_{\pi'} L(\pi') \\s.t. D_{KL}^{max}(\pi'||\pi)\leq \delta$$
3. 在约束条件中，利用平均KL散度代替最大KL散度
$$D_{KL}^{\rho_\pi}(\pi'||\pi)\leq \delta$$
4. $s\sim \rho_\pi\rightarrow s\sim \pi$

最终的TRPO问题转化为：
 $$\max_{\pi'} E_{s\sim\pi,a\sim\pi}\frac{\pi'(a|s)}{\pi(a|s)}A_{\pi}(s,a) \\s.t. E_{s\sim \pi}[D_{KL}(\pi'||\pi)[s]]\leq \delta$$

 ## PPO

 [PPO](https://arxiv.org/pdf/1707.06347.pdf)


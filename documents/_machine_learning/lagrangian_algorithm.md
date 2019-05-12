---
 title: lagrangian_algorithm
 categories: ml
 tags: ml
 date: 2018-03-28
 ---

**lagrange multiplier**

**lagrange duality**

假设$f(x),c_i(x),h_j(x),x\in \mathbb{R}^n$ **连续可微**，原始约束问题：
$$\begin{align}
    \min_{x\in R^n}f(x) \\
    s.t.c_i(x)\leq 0,i=1\cdots k \\
    h_j(x)=0,j=1\cdots l
\end{align}$$
引进拉格朗日函数(generalized lagrange function):
$$\mathcal{L}(x,\alpha,\beta)=f(x)+\sum_{i=1}^{k}\alpha_ic_i(x)+\sum_{j=1}^{l}\beta_ih_j(x)$$
其中$\alpha_i, \beta_j$是拉格朗日乘子。定义：
$$\theta(x)=\max_{\alpha,\beta:\alpha_i\geq 0}\mathcal(L)(x,\alpha,\beta)$$
易证明最大值的约束等价于不等式约束和等式约束的总和。且:
$$\theta(x)=f(x)$$
则加上最小化条件：
$$\min_{x}\theta(x)=\min_{x}\max_{\alpha,\beta:\alpha_i\geq 0}\mathcal(L)(x,\alpha,\beta)=p^*$$
则**原始约束问题被转化为等价的无约束问题**。
其**对偶问题**：
$$\max_{x}\theta(x)=\max_{\alpha,\beta:\alpha_i\geq 0}\min_{x}\mathcal(L)(x,\alpha,\beta)=d^*$$
> 定理：若原始问题与对偶问题都有最优值，则：$d^*\leq p^*$

原始问题的最优值不小于对偶问题的最优值，但是我们要通过对偶问题来求解原始问题，就必须使得原始问题的最优值与对偶问题的最优值相等，固有如下推论：
> 推论: 设$x^*,\alpha^*,\beta^*$是原始问题和对偶问题的可行解，如果$d^*=p^*$, 则$x^*,\alpha^*,\beta^*$是原始问题和对偶问题的最优解。

解存在条件： **KKT条件**，不再细述。其中的对偶互补条件(常用)：
$$\alpha_i^*c_i(x^*)=0,i=0\cdots k$$



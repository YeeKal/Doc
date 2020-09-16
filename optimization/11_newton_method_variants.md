---
 title: 拟牛顿法
 categories: optimization
 tags: optimization
 date: 2019-12-24
---

## 拟牛顿法(Quasi Newton Method)

牛顿法在最优化领域使用时，其更新方式可以认为是由$H^{-1}$矩阵来矫正梯度的搜索方向。而拟牛顿法的含义便是模拟替代Hessian矩阵，同时达到矫正搜索方向的目的。

由泰勒展开式：

$$f(x)=f'(x^k)+H_x(x^k)(x-x^k)$$

取$x=x^{k+1}$得:

$$f'(x^{k+1})-f'(x^k)=H_x(x^{k+1}-x^{k})$$

令：

$$ g_k=\Delta f(x^k)=f'(x^k) \\
y_k=g_{k+1}-g_k \\
\delta_x =x^{k+1}-x^k$$
得拟牛顿条件：

$$ y_k==H_x \delta_k$$

正定保证搜索方向向下：

$$\begin{align}\text{迭代公式：}& x=x^{k}-\lambda H_k^{-1}g_k   \\
\text{$f(x)$在$x_k$泰勒展开：} & f(x)=f(x^k)-\lambda g_k^TH_k^{-1}g_k  \\
\text{如果$H_k$正定：} & g_k^TH_k^{-1}g_k >0  \\
\text{当$\lambda$充分小时：}& f(x) < f(x^k) \end{align}$$

拟牛顿法选择$G_k\approx H_k^{-1}, or \quad B_k\approx H_k$ 进行更新。并在每次迭代中更新矩阵:

$$G_{k+1}=G_k+\Delta G_k$$

## DFP算法

令：

$$G_{k+1}=G_{k}+P_{k}+Q_{k} \\
P_{k} y_{k}=\delta_{k} \\
Q_{k} y_{k}=-G_{k} y_{k}
$$

则可以保证拟牛顿条件。

取:

$$
\begin{aligned}
P_{k} &=\frac{\delta_{k} \delta_{k}^{T}}{\delta_{k}^{T} y_{k}} \\
Q_{k} &=-\frac{G_{k} y_{k} y_{k}^{T} G_{k}}{y_{k}^{T} G_{k} y_{k}}
\end{aligned}$$

可得矩阵 $G_{k+1}$ 的迭代公式

$$G_{k+1}=G_{k}+\frac{\delta_{k} \delta_{k}^{T}}{\delta_{k}^{T} y_{k}}-\frac{G_{k} y_{k} y_{k}^{T} G_{k}}{y_{k}^{T} G_{k} y_{k}}
$$

可以保证若初始矩阵$G_0$是正定的，则迭代过程中每个矩阵$G_k$都是正定的。

**DFP算法步骤**

- 输入：目标函数 $f(x)$ ，梯度 $g(x)=\nabla f(x)$ ，精度要求 $\varepsilon$ 
- 输出： $\quad f(x)$ 的极小点 $x^{*}$

1. 取初始点 $x^{(0)},$ 取 $G_{0}$ 为正定矩阵，置 $k=0$
2. 计算 $g_{k}=g\left(x^{(k)}\right), \quad$ 若 $\left\|g_{k}\right\|<\varepsilon$ 则停止计算， 得近似解 $x^{*}=x^{(k)} ;$ 否则
转3.
3. 置 $p_{k}=-G_{k} g_{k}$
4. 一维搜索，求 $\lambda_{k}$ 使
$$
f\left(x^{(k)}+\lambda_{k} p_{k}\right)=\min _{\lambda \geq 0} f\left(x^{(k)}+\lambda p_{k}\right)
$$
5. 置 $x^{(k+1)}=x^{(k)}+\lambda p_{k}$
6. 计算 $g_{k+1}=g\left(x^{(k+1)}\right),$ 若 $\left\|g_{k+1}\right\|<\varepsilon$ 则停止计算，近似解 $x^{*}=x^{(k+1)} ;$ 否 则，计算
$$
G_{k+1}=G_{k}+\frac{\delta_{k} \delta_{k}^{T}}{\delta_{k}^{T} y_{k}}-\frac{G_{k} y_{k} y_{k}^{T} G_{k}}{y_{k}^{T} G_{k} y_{k}}
$$
7. 置 $k=k+1$ ， 转3.

在第5,6步中，$x^{k+1}$的计算依赖$G_k$,而$G_k$依赖$G_{k-1}$,因此每一步迭代的依赖是往前回溯两次。

[公式待定法](https://blog.csdn.net/itplus/article/details/21896981)


## BFGS算法

BFGS是用$B_k$去拟合$H_k$.其迭代公式:

$$B_{k+1}=B_{k}+\frac{y_{k} y_{k}^{T}}{y_{k}^{T} \delta_{k}}-\frac{B_{k} \delta_{k} \delta_{k}^{T} B_{k}}{\delta_{k}^{T} B_{k} \delta_{k}}$$

通过Sherman-Morrison公式：

$$(A+u v^{T})^{-1}=A^{-1}-\frac{A^{-1} u v^{T} A^{-1}}{1+v^{T} A^{-1} u}$$

得到Hesse矩阵近似逆矩阵：

$$G_{k+1}=\left(I-\frac{\delta_{k} y_{k}^{T}}{\delta_{k}^{T} y_{k}}\right) G_{k}\left(I-\frac{\delta_{k} y_{k}^{T}}{\delta_{k}^{T} y_{k}}\right)^{T}+\frac{\delta_{k} \delta_{k}^{T}}{\delta_{k}^{T} y_{k}}$$

## Broyden 算法

把DFP和BFGS得到的$G_k$进行线性组合：

$$G_{k+1}=\alpha G^{D F P}+(1-\alpha) G^{B F G S}, \alpha \in (0,1)$$

这样的组合也满足牛顿条件并且是正定的。

## L-BFGS(limited-memory BFGS)

当变量个数较多时，$G_k$矩阵的存储会非常耗费内存。L-BFGS的思路是存储部分向量$\delta_k,y_k$,当需要$G_k$时再通过向量的计算得到矩阵，从而降低内存开销。

[l-bfgs](https://blog.csdn.net/itplus/article/details/21897715)

## 一维搜索(line search)

计算拟牛顿法中迭代步长的因子$\lambda$, 以寻求最优的步长因子.

- 精确搜索: 一维搜索(line search)
- 非精确搜索:
    - Wolfe
    - Armijo
    - Goldstein

[用“人话”解释不精确线搜索中的Armijo-Goldstein准则及Wolfe-Powell准则](https://www.codelast.com/%E5%8E%9F%E5%88%9B%E7%94%A8%E4%BA%BA%E8%AF%9D%E8%A7%A3%E9%87%8A%E4%B8%8D%E7%B2%BE%E7%A1%AE%E7%BA%BF%E6%90%9C%E7%B4%A2%E4%B8%AD%E7%9A%84armijo-goldstein%E5%87%86%E5%88%99%E5%8F%8Awo/)

## 总结

- 牛顿法：$O(n^3)$
- 拟牛顿法：$O(n^2)$


## Gauss-Newton

non-linear problem

$$a_{a+1}=a_n-(J(a_n)^TJ(a_n))^{-1}J(a_n)^TF(a_n)$$

## Levenberg-Marquardt

对Gauss-Newton迭代步的修正,防止雅可比奇异位形(damped least squares)：
$$a_{a+1}=a_n-(J(a_n)^TJ(a_n)+\mu(a_n)I)^{-1}J(a_n)^TF(a_n)$$

- quasi-Newton methods
- Sequential Quadratic Programming(SQP)

## ref

- [Quasi Newton Methods in Optimization](http://apmonitor.com/me575/index.php/Main/QuasiNewton)
---
title: duality
categories: optimization
tags: optimization
date: 2023-05-05
---

## intro

three main formulations and implementations: <font color='Tomato'>Fenchel, Wolfe, and Lagrangean</font> 

- primal problem
- dual problem

拉格朗日乘子,惩罚项把约束函数包含在目标函数中, 原始问题被转化为另一个问题

- inf: infimum, the greatest lower bound, 下确界/最大下界
- sup: suprema, the least upper bound

## inf & sup

<font color='Tomato'>$\inf,\sup,\min,\max$</font>

- inf (infimum): The infimum or greatest lower bound of a set is the largest number that is less than or equal to every element in the set. It may not necessarily belong to the set itself. 下确界/最大下界
- sup (supremum): The supremum or least upper bound of a set is the smallest number that is greater than or equal to every element in the set. Like the infimum, it may not necessarily belong to the set.
- min (minimum): The minimum of a set is the smallest element within the set. Unlike the infimum, it must be a member of the set.
- max (maximum): The maximum of a set is the largest element within the set. Similar to the minimum, it must be a member of the set

incomplete: the inf or sup of the set does not belong to this set

<font color='Tomato'>operations on sets</font>

**Sum of sets**
The Minkowski sum of two sets $A$ and $B$ of real numbers is the set
$$
A+B:=\{a+b: a \in A, b \in B\}
$$
consisting of all possible arithmetic sums of pairs of numbers, one from each set. The infimum and supremum of the Minkowski sum satisfies
$$
\inf (A+B)=(\inf A)+(\inf B)
$$
and
$$
\sup (A+B)=(\sup A)+(\sup B)
$$
**Product of sets**
The multiplication of two sets $A$ and $B$ of real numbers is defined similarly to their Minkowski sum:
$$
A \cdot B:=\{a \cdot b: a \in A, b \in B\}
$$
If $A$ and $B$ are nonempty sets of positive real numbers then $\inf (A \cdot B)=(\inf A) \cdot(\inf B)$ and similarly for suprema $\sup (A \cdot B)=(\sup A) \cdot(\sup B) \cdot{ }^{[3]}$


**Scalar product of a set**
The product of a real number $r$ and a set $B$ of real numbers is the set
$$
r B:=\{r \cdot b: b \in B\}
$$
If $r \geq 0$ then
$$
\inf (r \cdot A)=r(\inf A) \quad \text { and } \quad \sup (r \cdot A)=r(\sup A)
$$
while if $r \leq 0$ then
$$
\inf (r \cdot A)=r(\sup A) \quad \text { and } \quad \sup (r \cdot A)=r(\inf A) \text {. }
$$
Using $r=-1$ and the notation $-A:=(-1) A=\{-a: a \in A\}$, it follows that $\inf (-A)=-\sup A \quad$ and $\quad \sup (-A)=-\inf A$.
**Multiplicative inverse of a set**
For any set $S$ that does not contain 0 , let
$$
\frac{1}{S}:=\left\{\frac{1}{s}: s \in S\right\}
$$
If $S \subseteq(0, \infty)$ is non-empty then
$$
\frac{1}{\sup S}=\inf \frac{1}{S}
$$
where this equation also holds when $\sup S=\infty$ if the definition $\frac{1}{\infty}:=0$ is used. ${ }^{[\text {note } 2]}$ This equality may alternatively be written as $\frac{1}{\sup _{s \in S} s}=\inf _{s \in S} \frac{1}{s}$. Moreover, $\inf S=0$ if and only if $\sup \frac{1}{S}=\infty$, where if ${ }^{[n o t e ~ 2]} \inf S>0$, then $\frac{1}{\inf S}=\sup \frac{1}{S}$.

<font color='Tomato'>Duality</font>

For subsets of the real numbers:

$$\inf S = -\sup(-S), \text{where } -S:=\{-s:s \in S \}$$

For any functionals $f$ and $g$:
$$\sup\{f(t)+g(t):t\in A\}\leq \sup\{f(t):t\in A\} +  \sup\{g(t):t\in A\}$$

<font color='Tomato'>Complementary slackness</font>


1. 构建拉格朗日乘子
2. 根据梯度为0替换掉x, 即求 $g(\lambda, \nu) = \inf_{x \in \mathcal{D}} L(x, \lambda, \nu)$ 或者根据最小化
3. 构建以拉格朗日乘子的对偶问题, 即求 $\sup_{\lambda, \nu} g(\lambda, \nu)$ 

## hyperplane

$$\inf _y\left\{\|y\|-\mu^T y\right\}=0 \text { if }\|\mu\|_* \leq 1$$

## $\inf_{x \in \mathcal{D}} L(x, \lambda, v)$

两种方案: 1. 求梯度; 2. fenchel conjugate

关于求梯度:  [通过次微分进行解释](https://math.stackexchange.com/questions/4104855/why-does-any-dual-optimal-point-provide-a-separating-hyperplane-between-a-point)

the optimality condition for minimizing over $y$ can be written as:
$$\mu \in \partial \|y\|$$
where $\partial_g(y)$ is the subdifferential of $g$ at $y$, and is defined by the set of supporting vectors, $e.g.$:
$$\partial g(y) = \{z : g(x)-g(y) - z^T(x-y) \geq 0,\forall x\}.$$

Then this can be proved: $\partial \|y\| =  \{z : z^Ty = \|y\|,\; \|z\|_* \leq 1\}$. [proofs pdf](https://angms.science/doc/CVX/SubdifferentialOfNorm.pdf)

## Fenchel conjugate

- [最强Fenchel对偶解读](https://zhuanlan.zhihu.com/p/32202419)

convex conjudate: 凸共轭

Fenchel conjugate is also known as the Fenchel-Legendre transform 

原函数$f:\mathbb{R}^n \rightarrow \mathbb{R}$的共轭函数:
$$f^*(y)=\sup _{x \in \operatorname{dom} f}\left(y^T x-f(x)\right)$$

the dual norm $||\cdot||_*$ of a norm $||\cdot||$ is difined as:
$$||z||_* = \sup_{||u||\leq 1}<z, u>$$

Fenchel不等式: 
$$f^*(x) \geq y^T x-f(x) \\
f^*(x) + f(x) \geq y^T x$$

3. 绝对值 $f(x) = |x|$, 共軛函数为:
$$f^*(x^*) = \left\{ \begin{aligned} 0, |x^*|\leq 1 \\ \infty, |x^*|> 1 \end{aligned} \right.$$

$$\inf_y\{||y|| - \mu ^Ty\} = 0, \text{for } ||\mu|| \leq 1$$

as: $\inf_y\{||y|| - \mu ^Ty\} = \sup (\mu^T y-||y||) =  f^*(y)$



主问题Prime $\max _{\alpha \geq 0, \beta} L(w, \alpha, \beta)=\left\{\begin{array}{l}J(w) \text { if } w \text { is feasible } \\ \infty \text { otherwise. }\end{array}\right.$
主问题Prime 最优 $\quad J^*=\min _w \max _{\alpha \geq 0, \beta} L(w, \alpha, \beta)$
对偶问题Dual $\quad D(\alpha, \beta)=\min _w L(w, \alpha, \beta)$.
Prime 和 Dual关系 $D(\alpha, \beta) \leq J(w)$
## Lagrangian

The Lagrangian of this problem is:

$$L(x, \lambda, \nu) = f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x).$$

The Lagrangian dual is:

$$g(\lambda,\nu) = \inf_{x \in \mathcal{D}} \left( f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x) \right),$$

g是最小值,而由于$L \leq f$, 所以希望L与f之间的gap越小越好,因此希望找到最优的$\lambda, \nu$使得g越大越好.

The Lagrangian dual problem, in turn is:

$$\begin{align}
\max \;\;\;\; &g(\lambda,\nu)\\
\text{s.t.} \;\;\;\; &\lambda \succcurlyeq 0.
\end{align}$$

Note that:

$$\begin{align}
\sup_{\lambda \succcurlyeq 0, \; \nu} L(x,\lambda,\nu) 
&= \sup_{\lambda \succcurlyeq 0, \; \nu} \left( f_0(x) + \sum_{i=1}^m \lambda_i f_i(x) + \sum_{i=1}^p \nu_i h_i(x) \right) \\
&= 
\begin{cases}
f_0(x) & \text{if } f_i(x) \leq 0, \; i = 1,\ldots,m, \text{ and } h_i(x) = 0, \; i=1,\ldots,p \\
\infty & \text{otherwise}.
\end{cases} 
\end{align}$$

This means that

$$p^\star := \inf_x \sup_{\lambda \succcurlyeq 0, \; \nu} L(x, \lambda, \nu)$$

is the optimal value of the primal problem. Moreover, by definition,  

$$d^\star := \sup_{\lambda \succcurlyeq, \; \nu} \inf_x L(x,\lambda,\nu)$$

is the optimal value of the dual problem.

If it is strong duality, then $d^* = p^*$.

$$x^\star = \arg\min_x L(x,\lambda^\star,\nu^\star).$$


(Next explanation)the dual problem:

$$\max _{\substack{\boldsymbol{x}, \boldsymbol{s} \\ s \geq 0}} \min _{\boldsymbol{y}} L(\boldsymbol{y}, \boldsymbol{x}, \boldsymbol{s})=\max _{\substack{\boldsymbol{x}, \boldsymbol{s} \\ s \geq 0}} L(\boldsymbol{x}, \boldsymbol{s})$$

For each $\boldsymbol{y}$, the Lagrangian $L(\boldsymbol{y}, \boldsymbol{x}, \boldsymbol{s})$ is linear in $(\boldsymbol{x}, \boldsymbol{s})$ and hence also concave in them. Hence $L(\boldsymbol{x}, s)$ is a concave function, because it is the pointwise minimum (over $y$ ), of a collection of concave functions in $(x, s)$.

This also means that the dual problem is really a convex optimization problem in disguise, because we can flip the sign of $-L(\boldsymbol{x}, s)$ to get a convex function and minimizing this is equivalent to maximizing $L(\boldsymbol{x}, \boldsymbol{s})$.
$$
\max _{\substack{x, s \\ s \geq 0}} L(\boldsymbol{x}, \boldsymbol{s})=-\min _{\substack{x, s \\ s \geq 0}}-L(\boldsymbol{x}, \boldsymbol{s})
$$

先求了一簇“最小”，然后从其中挑了一个“最大


Slater条件: 是凸集是强对偶的充分非必要条件


## linear combination of the gradient


## Ref

- blog
    - [dual problem question](https://math.stackexchange.com/questions/223235/please-explain-the-intuition-behind-the-dual-problem-in-optimization)
    - [Geometric interpretation of duality in optimization](https://math.stackexchange.com/questions/2234255/geometric-interpretation-of-duality-in-optimization)
- project
- course
    - [duality slides](https://web.archive.org/web/20141227023221/http://www.ifor.math.ethz.ch/teaching/Courses/Spring_2013/Convex_Optimization/Slides)


---
title: 凸优化问题
categories: optimization
tags: optimization
date: 2023-02-22
---

## Optimization Terminology

A **<font color='Tomato'>convex optimization program</font>** can be written as a convex minimization:

$$\begin{array}{cl}
\underset{x \in D}{\operatorname{minimize}} & f(x) \\
\text { subject to } & g_i(x) \leq 0, i=1, \ldots, m \\
& A x=b
\end{array}$$

where $f$ and $g_i, i=1,\cdots m$ are all convex.

**<font color='Tomato'> Convex minimization </font>** can be reposed as concave maximization, and both are called convex optimization problems:

$$\begin{aligned} \begin{aligned}
\min & \quad f(x) \quad  \\
\text { s.t. }& \quad g_i(x) \leq 0, \quad i=1, \ldots m\\
& \quad A x=b \end{aligned} \quad \Longleftrightarrow \quad  \begin{aligned}  \max & \quad -f(x) \quad  \\
\text { s.t. }& \quad g_i(x) \leq 0, \quad i=1, \ldots m\\
& \quad A x=b \end{aligned} \end{aligned}$$



| notation/terminology  | coment |  
|---|---|---|
|$f(x)$: **Objective function, criterion**| the convex function we are minimizing over.|
|$D$: **Optimization domain(定义域)**|implicit domain,  $D=\operatorname{dom}(f) \cap \bigcap_i \operatorname{dom}\left(g_i\right)$|
|$g_i(x)$: **Inequality constraints**| convex functions; the solution must satisfy these.|
|$f^*$: **Optimal value(最优值)**| the minimum of $f(x)$ over all feasible points $x$|
|$X_{\text {opt }}$: **Set of solutions(解集)**| All $x$ 's that solve to a convex problem. Property: it's a convex set.|
|**$x^*$: Solution, optimal point**| the $\mathrm{x}$ at which the function achieves the optimal value; i.e. - $x$ such that $f(x)=f^*$; also called the minimizer.| 
|**Feasible points(可行集)**| $x, x\in D, g_i(x)\leq 0, Ax=b$ | 
|**$\epsilon$-suboptimal**|a feasible $x$ for which the function is within $\epsilon$ of the optimal value, i.e.  $f(x) ≤ f + \epsilon$|
|**$g_i$ is active**|a feasible $x$ and $g_i(x)=0$|
|**Locally optimal(局部最优)**||
|**Globally optimal(全局最优)**||

**<font color='Tomato'>$X_{\text {opt }}$ is a convex set</font>**

Proof: use definitions. If $x, y$ are solutions, then for $0 \leq \theta \leq 1$,
- $\theta x+(1-\theta) y \in D$
- $g_i(\theta x+(1-\theta) y) \leq \theta g_i(x)+(1-\theta) g_i(y) \leq 0$
- $A(\theta x+(1-\theta) y)=\theta A x+(1-\theta) A y=b$
- $f(\theta x+(1-\theta) y) \leq \theta f(x)+(1-\theta) f(y)=f^{\star}$

Therefore $\theta x+(1-\theta) y$ is also a solution.

Another key property: <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>if criterion $f$ is strictly convex, then the solution is unique</font>.$X_{\mathrm{opt}}$ contains one element

Example:

**<font color='Tomato'>lasso</font>**

Given $y \in \mathbb{R}^n, X \in \mathbb{R}^{n \times p}$, consider the lasso problem:
$$
\begin{array}{ll}
\min _{\beta \in \mathbb{R}^p} & \|y-X \beta\|_2^2 \\
\text { subject to } & \|\beta\|_1 \leq s
\end{array}
$$

**<font color='Tomato'>Huber loss</font>**

$$\sum_{i=1}^n \rho\left(y_i-x_i^T \beta\right), \quad \rho(z)= \begin{cases}\frac{1}{2} z^2 & |z| \leq \delta \\ \delta|z|-\frac{1}{2} \delta^2 & \text { else }\end{cases}$$

**<font color='Tomato'>Locally optimal</font>**

A feasible point $x$ is called locally optimal is thers is some $R > 0$ such that:

$$f(x)\leq f(y), ~ \text{for all feasible}~ y ~ \text{such that}~ ||x-y||_2\leq R$$ 

for convex optimization problems: <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>local optima are global optima</font>

proof: 

1. suppose local optima $f(x)$, and global optima $f(y)$, $f(x)\geq f(y), x \neq y$. By definition, $f(x) \leq f(k), \forall ||x-k||_2\leq R$
2. let $\theta = 1-\frac{R}{2l}, l = ||x-y||_2$
3. let $z = \theta x + (1-\theta) y, ||x-z|| \leq R$, then

$$f(z) = f(\theta x+(1-\theta) y) \leq \theta f(x) + (1-\theta) f(y) < f(x)$$

4. this contradicts $f(x) \leq f(z)$

**<font color='Tomato'>Rewrite Constraints</font>**

The initial problem can be rewritten as:

$$\min f(s) ~~ \text{subject to}~ x\in C$$

where $C=\{x:g_i(x)\leq 0\, i=1,\cdots m, Ax = b \}$ is feasible set. The above formulation is <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>Completely general</font>.

The unconstrained form can also be rewrite as:

$$\min ~ f(x) + I_{C}(x)$$

where $I_C$ is the indicator function of $C$

## Properties and first-order optimality

**<font color='Tomato'>first-order condition for optimality</font>**

For a convex problem:

$$\min f(s) ~~ \text{subject to}~ x\in C$$

and differential $f$, a feasible point $x$ is optimal if and only if:

$$\nabla f(x)^T(y-x)\geq 0 ~~ \text{for all}~~ y\in C$$

In words: <font style='background: #007f16;color: #ffffff;opacity:1.0; border-radius: 5px; padding:5px;'>all feasible directions from $x$ are aligned with increasing gradient
$\nabla f(x)$</font>

$\nabla f(x)$: 在可行集内的梯度方向, 与等高线垂直. 梯度是切线在定义域内的投影

该条件含义:
1. if you move from $x$ towards any feasible $y$, you will increase $f$ locally
2. the vector $-\nabla f(x)$(assuming  nonzero) serves as a hyperplane that "supports" the feasible set $\Omega$ at x.

![first_optimality_for_convex_optimization.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/optimization/imgs/first_optimality_for_convex_optimization.svg)

Note:
- 在$f$ 非凸情况下,该条件是必要条件(necessity). $f$是凸函数$\Rightarrow$ 该条件是充要条件(充分: sufficiency).
- if $C=\mathbb{R}^n$(unconstrained optimization) then optimality condition reduces to familiar $\nabla f(x) = 0$.
- 如果最优点在可行集内部, $\nabla f(x) = 0$.(Take $y=x-\alpha \nabla f(x)$ for $\alpha$ small enough)

**<font color='Tomato'>Proof</font>**

proof-sufficiency:

according to <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>First-order characterization</font> of the convex function:

$$\begin{matrix}f(y)\geq f(x) + \nabla f(x)^T(y-x) \\
\nabla f(x)^T(y-x)\geq 0  \end{matrix} ~ \Rightarrow ~ f(y)\geq f(x)$$

proof-necessity: (若小于0则在x附近存在更小的值) Suppose $x$ is optimal but for some $y \in \Omega$ we had

$$\nabla f^T(x)(y-x)<0$$

Consider $g(\alpha):=f(x+(\alpha(y-x))$. Because $\Omega$ is convex, $\forall \alpha \in[0,1], x+\alpha(y-x) \in \Omega$. Observe that

$$\begin{aligned}
& g^{\prime}(\alpha)=(y-x)^T \nabla f(x+\alpha(y-x)) . \\
& \Rightarrow g^{\prime}(0)=(y-x)^T \nabla f(x)<0 \text {. } \\
&
\end{aligned}
$$

This implies that

$$
\begin{aligned}
& \exists \delta>0, \text { s.t. } g(\alpha)<g(0), \forall \alpha \in(0, \delta) \\
\Rightarrow & f(x+\alpha(y-x))<f(x), \forall \alpha \in(0, \delta) .
\end{aligned}
$$

But this contradicts the optimality of $x$.

**<font color='Tomato'>Example2: equality-constrained minimization</font>**

consider the optimization problem

$$\begin{aligned}
\min& ~ f(x)  \\
s.t. & ~Ax=b, ~ \text{where} ~ f ~ \text{is convex}, A\in \mathbb{R}^{m\times n}
\end{aligned}$$

The point $x$ is optimal point if and only if *it is feasible and $\exist\mu\in \mathbb{R}^m ~ s.t.$*

$\nabla f(x) = A^T \mu ~~\text{or}~~ f(x) = A^T\mu = 0$

proof: according to first-order optimality, solution $x$ satisfies:

$$Ax=b, \nabla f(x)^T(y-x)\geq 0, ~\forall y ~\text{such that}~ Ay=b$$

This is equivalent to:

$$\nabla f(x) ^T v = 0, ~\forall v\in null (A)$$

result follows since $null(A)\perp = row(A)$

上式含义是指$\nabla f(X)$是A的列向量的线性组合, 即在A的列空间里面. 列空间里的向量和零空间的向量相互垂直. 这与拉格朗日乘子法的结果相同.


**<font color='Tomato'>Example2: projection onto a convex set</font>**

$$\min ||a-x||_2^2, ~ x\in C$$

according to first-order optimality condition, the optimal point $x$ satisfies:

$$\nabla f(x)^T(y-x) = (x-a)^T(y-x) \geq 0, \forall y\in C$$

Equivalently, this says that $a-x\in \mathcal{N}_C(x)$, which is the normal cone to $C$ at $x$:

$$\begin{equation}
 N_C(\overline{x}) = \{ y \in \mathbb{R}^d \ <y ,c-\overline{x}> \leq 0 \forall c \in C \}.
 \end{equation}$$

从定义上看,若点在内部,则结果为0.若点在边界上, normal cone实际上定义了在该点处远离整个凸集的方向应该往哪个方向走.若边界在该点处是光滑的,则远离的方向只有一个；若不是光滑的,比如是多边形的一个角,则就会形成一个锥.

![normal_cone_for_convex_set.svg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/optimization/imgs/normal_cone_for_convex_set.svg)

## Equivalent transformations


**<font color='Tomato'>Partial optimization</font>**

Reminder: $g(x)=\min _{y \in C} f(x, y)$ is convex in $x$, provided that $f$ is convex in $(x, y)$ and $C$ is a convex set

Therefore we can always **partially optimize a convex problem and retain convexity**

E.g., if we decompose $x=\left(x_1, x_2\right) \in \mathbb{R}^{n_1+n_2}$, then

$$\begin{aligned}
\min _{x_1, x_2} \quad & f\left(x_1, x_2\right)  \\
\text { s.t. } \quad &g_1\left(x_1\right) \leq 0 \quad \\
\quad & g_2\left(x_2\right) \leq 0 
\end{aligned} \Longleftrightarrow \begin{aligned} \quad \min _{x_1}& \quad \tilde{f}\left(x_1\right) \quad \\ \text { s.t. }& \quad g_1\left(x_1\right) \leq 0 \end{aligned}$$

where $\tilde{f}\left(x_1\right)=\min \left\{f\left(x_1, x_2\right): g_2\left(x_2\right) \leq 0\right\}$. The right problem is convex if the left problem is.

<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>Example: Recall the SVM problem</font>

$$
\begin{array}{ll}
\min _{\beta, \beta_0, \xi} & \frac{1}{2}\|\beta\|_2^2+C \sum_{i=1}^n \xi_i \\
\text { subject to } & \xi_i \geq 0, y_i\left(x_i^T \beta+\beta_0\right) \geq 1-\xi_i, i=1, \ldots n
\end{array}
$$
Rewrite the constraints as $\xi_i \geq \max \left\{0,1-y_i\left(x_i^T \beta+\beta_0\right)\right\}$. Indeed we can argue that we have $=$ at solution(由于是最小化,因此 $\geq\max ~~ \Rightarrow  ~~ =$)

Therefore plugging in for optimal $\xi$ gives the <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>hinge form</font> of SVMs:
$$
\min _{\beta, \beta_0} \frac{1}{2}\|\beta\|_2^2+C \sum_{i=1}^n\left[1-y_i\left(x_i^T \beta+\beta_0\right)\right]_{+}
$$
where $a_{+}=\max \{0, a\}$ is called the <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>hinge function</font>

**<font color='Tomato'>Transformations and change of variables</font>**

If $h:\mathbb{R}\rightarrow \mathbb{R}$ is a monotone increasing transformation, then:

$$\min ~ f(x), ~ x\in C \Longleftrightarrow \min ~ h(f(x)), ~ x\in C$$

If $\phi:\mathbb{R}^n \rightarrow \mathbb{R}^m$:

$$\min_{x} ~ f(x), ~ x\in C \Longleftrightarrow \min_{y} ~ f(\phi(y)), ~ \phi(y)\in C$$

Similarly, inequality or equality constraints can be transformed and yield equivalent optimization problems. Can use this to reveal the
<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>hidden convexity</font> of a problem


**<font color='Tomato'>Eliminating equality constraints</font>**

$$\begin{aligned}
\min _{x} \quad & f(x)  \\
\text { s.t. } \quad &g_i\left(x\right) \leq 0 \quad \\
\quad & Ax = b
\end{aligned}$$

we can express any feasible point as $x = My+x_0$, where $Ax_0=b$ and $col(M) = null (A)$(即表示为一个解和零空间的线性组合). Hence the sbove is equivalent to:

$$\begin{aligned}
\min _{y} \quad & f(My+x_0)  \\
\text { s.t. } \quad &g_i(My+x_0) \leq 0 
\end{aligned}$$

*Note: fully general but not always a good idea*

**<font color='Tomato'>Introducing slack variables</font>**

transform the above inequality constraints via:

$$\begin{aligned}
\min \quad & f(x)  \\
\quad & s_i \geq 0\\
\text { s.t. } \quad &g_i(x) + s_i = 0 \\
& Ax = b
\end{aligned}$$

Note: this is no longer convex unless each $g_i(x) = c_i^T x + d_i$, an affine function

**<font color='Tomato'>Relaxing nonaffine equality constraints</font>**

Given an optimization problem
$$
\min f(x) \text { subject to } x \in C
$$
we can always take <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>an enlarged constraint set</font> $\tilde{C} \supseteq C$ and consider
$$
\min f(x) \text { subject to } x \in \tilde{C}
$$
This is called a relaxation and <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'> its optimal value is always smaller or equal to</font> that of the original problem.(使用更大的可行集，最优点小于等于原问题。比如把等式约束放宽为小于等于)

Important special case: relaxing nonaffine equality constraints, i.e.,

$$
h_j(x)=0, j=1, \ldots r
$$

where $h_j, j=1, \ldots r$ are convex but nonaffine, are replaced with

$$
h_j(x) \leq 0, j=1, \ldots r
$$
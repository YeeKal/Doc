---
 title: 04-GLM
 categories: ml
 tags: ml
 date: 2019-04-18
 ---

The generalized linear model **(GLM, 广义线性模型)** is a flexible  generalization of ordinary linear regression.把自变量的线性预测函数当作因变量的估计值。The target variable y is also called **response variable** in GLM.

## the exponential family

the prototype:

$$\begin{equation}p(y; \eta)=b(y)exp(\eta^TT(y)-a(\eta))\end{equation} \\$$

Here, $\eta$ is called the **natural parameter(or canonical parameter)**; $T(y)$ is the **sufficient statistic**, which is often the case: $T(y)=y$; $a(\eta)$ is **log partial function**. The quantity $e^{-a(\eta)}$ essentially plays the role of a normalization constant, that makes sure the distribution $p(y;\eta)$ sums/integrates over y to 1. A fixed choice of T,a and b defines a *family* of destributions that is parameterized by $\eta$;we then get different distributions within this family. 

We now show that some common distributions belong to the exponential family.

**Gaussian distributions:**

$$\begin{align} p(y)&=\frac{1}{\sqrt{2\pi\sigma}}exp(-\frac{(y-\mu)^2}{2\sigma^2})\\&= \frac{1}{\sqrt{2\pi\sigma}}exp(-\frac{y^2-2y\mu^2+\mu^2}{2\sigma^2})\\&=\frac{1}{\sqrt{2\pi\sigma}}exp(-\frac{y^2}{2\sigma^2})\cdot exp(\frac{\mu}{\sigma^2}\cdot y-\frac{y^2}{2\sigma^2})\end{align}$$

**Bernoulli distribution:**

$$\begin{align}p(y)&=\phi^y(1-\phi)^{1-y}\\&=exp(ylog\phi+(1-y)log(1-\phi))\\&=exp((log(\frac{\phi}{1-\phi}))y+log(1-\phi)) \end{align}$$

Thus, the natural parameter is given by $\eta=log(\phi/(1-\phi))$. If we invert this definition for $\eta$ by solving for $\phi$, we obtain $\phi=\frac{1}{1+e^{-\eta}}$. This is the familiar sigmoid function. Actually, the ordinary least squares(最小二乘法) is based on Gaussian distribution, and logistic regression on Bernoulli distribution.

## constructing GLM

three assumptions:

- $y\vert x;\theta ~ExponentialFamily(\eta)$. I.e., given x and $\theta$, the distribution of y follows some exponential family distribution, with parameter $\eta$.
- $h(x)=E[T(y)|x]$.
- The natural parameter $\eta$ and the inputs $x$ are related linearly: $\eta=\theta^Tx$, which might be better thought of as a "design choice".

## softmax regression

Consider a classification problem in which the response variable $y$ can take any one of k values, so $y\in \{1,2,...,k\}$. We use k parameters $\phi_1, \cdots,\phi_k$ specifying the probability of each of $y$. we will instead pa-
rameterize the multinomial with only $k − 1$ parameters, $\phi_1, \cdots,\phi_{k-1}$, and $p(y=k)=1-\sum_{i=1}^{k-1}\phi_i$. 

To express the multinominl as an exponential family distribution, we introduce one more very useful piece of notation. $[1\{true\}=1,1\{false\}=0 ]$ and define $[(T(y))_i=1\{y=i\}]$. Then we have that $E[(T(y))_i]=p(y=i)=\phi_i$. so:

$$\begin{align} p(y;\phi)&=\phi_1^{(T(y))_1}\cdots\phi_{k}^{\sum_{i=1}^{k-1}(T(y))_{i}}\\&=exp((T(y))_ilog(\phi_i)+\cdots+(1-\sum_{i=1}^{k-1}(T(y))_i)log(\phi_k))\\&=exp((T(y))_ilog(\frac{\phi_i}{\phi_k})+\cdots+log(\phi_k))\\&=b(y)exp(\eta^TT(y)-a(\eta)) \end{align} \\$$

where:

$$\eta=\begin{bmatrix} log(\phi_1/\phi_k)\\\cdots\\log(\phi_1/\phi_k) \end{bmatrix}\\a(\eta)=-log(\phi_k) \\$$

$$T(i)=\begin{bmatrix}0\\0\\\cdots\\1\\\cdots\\0\end{bmatrix} , i-th\quad is 1\\$$

the link function is given (for i=1,...,k) by:

$$ \eta_i=log\frac{\phi_i}{\phi_k} \\$$

And:

$$\phi_k\sum_{i=1}^ke^{\eta_i}=\sum_{i=1}^{k}\phi_i=1\\\phi_i=\frac{e^{\eta_i}}{\sum_{j=1}^k e^{\eta_j}} \\$$



By assumption 3: $\eta=\theta^Tx$:

$$p(y=i|x;\theta)=\phi_i=\frac{e^{\eta_i}}{\sum_{j=1}^k e^{\eta_j}}=\frac{e^{\theta_j^T x}}{\sum_{j=1}^k e^{\theta_j^T x}} \\$$

Our hypothesis will output:

$$\begin{align} h_\theta(x)&=E[T(y)|x]\\&=E\begin{bmatrix} 1\{y=1\}\\\cdots\\1\{y=k-1\}\end{bmatrix}\\&=\begin{bmatrix} \phi_1\\\cdots\\\phi_{k-1}\end{bmatrix} \\&=\begin{bmatrix} \frac{e^{\theta_1^T x}}{\sum_{j=1}^k e^{\theta_j^T x}} \\\cdots\\\frac{e^{\theta_{k-1}^T x}}{\sum_{j=1}^k e^{\theta_j^T x}} \end{bmatrix}\end{align} \\$$

Our hypothesis will output the estimates probability for $p(y=i|x;\theta)$,[$p(y=k)=1-\sum_{i=1}^{k-1}p(y=i)$].The log-likelihood is:

$$l(\theta)=\sum_{i=1}^{m}log\prod_{i=1}^k(\frac{e^{\theta_l^T x^{(i)}}}{\sum_{j=1}^k e^{\theta_j^T x^{(i)}}})^{1\{y^{(i)}=l\}} \\$$

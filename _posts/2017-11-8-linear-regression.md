---
title: linear regression
categories: cs
---

## data model

features: $x^{(i)}$, may be a vector.

target: $y^{i}$

training example: $(x^i,y^i)$, i meanes *$i$th* training example

training set: $\{(x^i,y^i): i=1,...,m\}$

the space of input and output values: $X=Y=R$

hypothesis: $h(x)$ , a function as a good predictor.

&emsp;If the target variable that we are trying to predict is continuous, we call the learning problem a **regression problem(回归问题)**. When y can take on only a small number of discrete values (such as
if, given the living area, we wanted to predict if a dwelling is a house or an
apartment, say), we call it a **classification problem(选择问题)**.

## linear regression

An example. In house price model, $x^i$ are two-dimensional vector in $R^2$ . We decided to approximate y as a linear function of x:

$$h(x)={\theta}_{0}+{\theta}_{1}x_1+{\theta}_{2}x_2 \\$$

Here,$\theta$`s are the **parameters** or (**weights**). Let $x_0=1$ (**intercept term**) , so that the function:

$$h(x)=\sum_{i=0}^n \theta_i x_i=\theta^T x \\$$

Now, problem is how do we pick the parameters $\theta$ to make $h()x$ closer to $y$. To formalize this we define the **cost function**:

$$J(\theta)=\frac{1}{2}\sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2 \\$$

This is the same to **ordinary least squares(最小二乘法)**.

To minimize $J(\theta)$, we start witn an initial value and keep changing $\theta$ to reduce $J$, until hopefully we converge a value of $\theta$ that minimize $J(\theta)$.

**polynomial regression**: Our hypothesis function need not be linear if that does not fit data well.We can change the behavior or curve of our hypothesis function, such as  the quadratic function: $h_\theta(x)=\theta_0+\theta_1x_1+\theta_2x_1^2$. And if let $x_2=x_1^2$, we have created new features: $x_2$.

### gradient descent

Take a small step toward the direction to quickly drop

update rule:

$$\begin{aligned}\theta_j :&=\theta_j - \alpha \frac{\partial}{\partial \theta_j} J(\theta)\\&=\theta_j+\alpha(y^{i}-h_\theta(x^{(i)}))x_j^{(i)}\end{aligned} \\$$

$\alpha$ : **learning rate**. Use smaller $\alpha$, for $J(\theta)$ should decrease on every iteration. But if it is too small, the convergence is slow. To choose $\alpha$, try $\cdots, 0.001,\quad,0.01,(0.03)\quad,0.1,\quad,1, \cdots$ .

where:

$$\begin{aligned} \frac{\partial}{\partial \theta_j} J(\theta)&=(h_{\theta}(x)-y)\frac{\partial}{\partial\theta_j}(h_{\theta}(x)-y)\\&=(y^{i}-h_\theta(x^{(i)}))x_j^{(i)}\end{aligned} \\$$

The rule is called the **LMS**(least mean squares) update rule. And is also known as the **Widrow-Hoff** learning rule. When there are more than one training example, two ways can be applied to modofy this method:

&emsp;&emsp;Repeat until convergence$$\{ \\\quad \quad \theta_j:={\theta}_j+\alpha\sum_{i=0}^m(y^{i}-h_\theta(x^{(i)}))x_j^{(i)} \\ \}$$

This method  looks at every example in the entire training set on every step, and is called **batch gradient descent(遍历)**.

&emsp;&emsp;Loop$$\{ \\\quad \quad for i=1\quad to\quad m,\{\\\theta_j:={\theta}_j+\alpha(y^{i}-h_\theta(x^{(i)}))x_j^{(i)} \\ \quad\quad\}\\\}$$

Each time we encounter a training example, we update the parameters according to the gradient of the error with respect to that single training example only. This algorithm is called **stochastic gradient descent(随机梯度算法)**. This method is often preferred over batch gradient descent.

### feature scaling

To make sure features are on the same scale.

We can speed up gradient descent by having each of our input values in roughly the same range. This is because θ will descend quickly on small ranges and slowly on large ranges, and so will oscillate inefficiently down to the optimum when the variables are very uneven.

Two techniques to help with this are **feature scaling** and **mean normalization**. Feature scaling involves dividing the input values by the range (i.e. the maximum value minus the minimum value) of the input variable, resulting in a new range of just 1. Mean normalization involves subtracting the average value for an input variable from the values for that input variable resulting in a new average value for the input variable of just zero. To implement both of these techniques, adjust your input values as shown in this formula:

$$x_i:=\frac{x_i−μ_i}{s_i} \\$$

where $\mu_i$ is the average of all values, and $s_i$ may be the range (max-min) or the standard deviation. If $\mu_i$ is the standard deviation, the new mean value is 0, and standrad deviation is 1.

### Normal equation

There is no need to do feature scaling with the normal equation.

properties for **matrix derivatives**

$$\bigtriangledown_Af(A)=\begin{bmatrix}\frac{\partial f}{\partial A_{11}}&...&\frac{\partial f}{\partial A_{12}}\\...&&...\\ \frac{\partial f}{\partial A_{11}}&...&\frac{\partial f}{\partial A_{12}}\end{bmatrix} \\$$

$$\begin{align}\bigtriangledown_A trAB&=B^T\\ \bigtriangledown_{A^T} f(A)&=(\bigtriangledown_A f(A))^T\\\bigtriangledown_A trABA^TC&=CAB+C^TAB^T\\\bigtriangledown_A\lvert A\rvert&=\lvert A\rvert(A^{-1})^T \end{align} \\$$

Define the **design matrix**:

$$X_{m\times n}=\begin{bmatrix}(x^{(1)})^T\\(x^{(2)})^T\\...\\(x^{(m)})^T\end{bmatrix} \\$$

$$\overrightarrow{y}=\begin{bmatrix}y^{(1)}\\y^{(2)}\\...\\y^{(m)}\end{bmatrix} \\​$$

Then the cost function can be revised as:

$$\begin{align}J(\theta)&=\frac{1}{2}\sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2\\&=\frac{1}{2}(X\theta-\overrightarrow{y})^T(X\theta-\overrightarrow{y})\end{align} \\$$

Hence,

$$\bigtriangledown_\theta J(\theta)=X^TX\theta-X^T\overrightarrow{y} \\$$

To minimize $J$, we set its derivatives to zero, and  obtain the **normal equation:**

$$X^T X\theta=X^T\overrightarrow{y} \\$$

$$\theta=(X^T X)^{-1}X^T\overrightarrow{y} \\$$

Thus the value of $\theta$ is given in closed form by the equation. ( that's splendid ! ! )

With the normal equation, computing the inversion has complexity $O(n^3)$. In practice, when n exceeds 10000 it might be a good time to go from a normal solution to an iterative process.

### locally weighted linear regression

In LWR, we choose $w^{(i)}$ to minimize $\sum_{i=1}^m w^{(i)}(h_\theta(x^{(i)})-y^{(i)})^2$, where the $w^{(i)}$ are non-negative valued **weights**.  To make a predicton at a query point $x$, a fairly standard choice for the weights is:

$$w^{(i)}=exp(-\frac{(x^{(i)}-x)^2}{2\tau^2}) \\$$

$\tau$ is called the **bandwidth**, and controls how quickly the weight of a training exampple falls off  with distance of its $x^{(i)}$ from the query point $x$.

LWR is **non-parametric** algorithm. The above unweighted linear regression is knownas a **parametric** learing algorithm, as it has a fixed, finite number $\theta^{(i)}​$. To make predictions using locally weighted linear regression, we need to keep the entire training set around.

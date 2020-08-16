---
 title: 03-regularization
 categories: ml
 tags: ml
 date: 2018-03-18
---

---
title: regularization
---

## overfitting

1. Reduce number of features
   - manually select which features to keep
   - model selection algorithm
2. regularization
   - keep all the features, but reduce parameters $\theta$.

The regularization works well when we have a lot of features, each of which contributes a bit to predicting y.

## cost function

$$J(\theta)=\frac{1}{2m}\sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2 \\$$

Suppose we want $\theta_3,\theta_4$ really small, consider this:

$$J(\theta)=\frac{1}{2m}\sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2 +1000\theta_3^2+1000\theta_4^2 \\$$

Then $\theta_3,\theta_4​$ will $\to​$ 0, and less prone to overfitting.

**regularization:**
$$J(\theta)=\frac{1}{2m}\sum_{i=1}^m (h_\theta(x^{(i)})-y^{(i)})^2 +\frac{\lambda}{2m}\sum_{j-1}^n\theta_j^2 \\$$

where the adding term is the regularization term and $\lambda$ is the **regularization parameter**.Using the above cost function with the extra summation, we can smooth the output of our hypothesis function to reduce overfitting. If lambda is chosen to be too large, it may smooth out the function too much and cause underfitting.

## regularized linear regression

We will seperate out $\theta_0$ :

$$\begin{align*} & \text{repeat}\ \lbrace \newline & \ \ \ \ \theta_0 := \theta_0 - \alpha\ \frac{1}{m}\ \sum_{i=1}^m (h_\theta(x^{(i)}) - y^{(i)})x_0^{(i)} \newline & \ \ \ \ \theta_j := \theta_j - \alpha\ \left[ \left( \frac{1}{m}\ \sum_{i=1}^m (h_\theta(x^{(i)}) - y^{(i)})x_j^{(i)} \right) + \frac{\lambda}{m}\theta_j \right] &\ \ \ \ \ \ \ \ \ \ j \in \lbrace 1,2...n\rbrace\newline & \rbrace \end{align*} \\$$

The update rule can be also represented as:

$$\theta_j := \theta_j(1 - \alpha\frac{\lambda}{m}) - \alpha\frac{1}{m}\sum_{i=1}^m(h_\theta(x^{(i)}) - y^{(i)})x_j^{(i)} \\$$

The normal equation；

$$\begin{align*}& \theta = \left( X^TX + \lambda \cdot L \right)^{-1} X^Ty \newline& \text{where}\ \ L = \begin{bmatrix} 0 & & & & \newline & 1 & & & \newline & & 1 & & \newline & & & \ddots & \newline & & & & 1 \newline\end{bmatrix}\end{align*} \\$$

## regularized logistic regression

the similar form which exclude $\theta_0$:

$$J(\theta) = - \frac{1}{m} \sum_{i=1}^m y^{(i)}\ \log (h_\theta (x^{(i)})) + (1 - y^{(i)})\ \log (1 - h_\theta(x^{(i)}))\ + \frac{\lambda}{2m}\sum_{j=1}^n \theta_j^2 \\$$

Note: no $j_0$

## matlab function

**contour()**

```matlab
 x = linspace(-1, 1.5, 50);
 y = linspace(-1, 1.5, 50);
 z=f(x,y);%x and y determines z
 contour(u, v, z,v, 'ShowText','on','LineWidth',2);
 % v can be a number, refer the number of the contour
 % v can be a vector, which specifies at value of z to draw the contour
 % it has some properties
```

**fminuc**

```matlab
options = optimset('GradObj', 'on', 'MaxIter', 400);
%'GradOBBJ'  tells fminunc our function returns both cost and gradient 
[theta, J, exit_flag] =fminunc(@(t)(costFunctionReg(t, X, y, lambda)), initial_theta, options);
%input the initial value and the function should 
```

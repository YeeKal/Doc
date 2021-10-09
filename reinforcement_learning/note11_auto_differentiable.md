
## differential

numerical derivative:

$$f^{\prime}(a)=\lim _{h \rightarrow 0} \frac{f(a+h)-f(a-h)}{2 h}$$

partial derivative:

$$\frac{\partial f}{\partial x_{i}}\left(a_{1}, \ldots, a_{n}\right)=\lim _{h \rightarrow 0} \frac{f\left(a_{1} \ldots, a_{i}+h, \ldots, a_{n}\right)-f\left(a_{1} \ldots, a_{i}, \ldots, a_{n}\right)}{h}$$

The vector of partial derivatives of a scalar-value multivariate function:

$$\nabla f\left(a_{1}, \ldots, a_{n}\right)=\left(\frac{\partial f}{\partial x_{1}}\left(a_{1}, \ldots, a_{n}\right), \ldots, \frac{\partial f}{\partial x_{n}}\left(a_{1}, \ldots, a_{n}\right)\right)$$

**In general:**

Suppose that $\boldsymbol{x} \in \mathbb{R}^{m}, \boldsymbol{y} \in \mathbb{R}^{n}, g$ maps from $\mathbb{R}^{m}$ to $\mathbb{R}^{n}$ and $f$ maps from $\mathbb{R}^{n}$ to $\mathbb{R}$
If $\boldsymbol{y}=g(\boldsymbol{x})$ and $z=f(\boldsymbol{y})$, then
$$
\frac{\partial z}{\partial x_{i}}=\sum_{j} \frac{\partial z}{\partial y_{j}} \frac{\partial y_{j}}{\partial x_{i}}
$$
Equivalently, in vector notation:
$$
\begin{aligned}
\nabla_{\boldsymbol{x}} \boldsymbol{z} &=\left(\frac{\partial \boldsymbol{y}}{\partial \boldsymbol{x}}\right)^{\top} \nabla_{\boldsymbol{y}} z    \\
&=\sum_{j}\left(\nabla_{\mathbf{X}} Y_{j}\right) \frac{\partial \mathbf{z}}{\partial \mathbf{Y}_{j}}
\end{aligned}
$$
where $\frac{\partial \boldsymbol{y}}{\partial \mathbf{x}}$ is the $n \times m$ Jacobian matrix of $g$.

## gradient-descent solution to SVD

$$A=U\Sigma V^T=U\Sigma^{0.5}\cdot\Sigma^{0.5}V^T=\hat{U}\hat{V}$$

SVD decomposition problem reduced ta finding $\min _{\hat{\boldsymbol{U}}, \hat{\boldsymbol{V}}}\left(\left\|\boldsymbol{A}-\hat{\boldsymbol{U}} \hat{\boldsymbol{V}}^{\top}\right\|_{\mathrm{F}}^{2}\right)$:

$$\begin{aligned}
\min _{\hat{u}, \hat{\mathbf{V}}}\left(\left\|\boldsymbol{A}-\hat{\boldsymbol{U}} \hat{\boldsymbol{V}}^{\top}\right\|_{\mathrm{F}}^{2}\right) &=\min _{\hat{\boldsymbol{u}}, \hat{\boldsymbol{v}}}\left(\sum_{r} \sum_{c}\left(A_{r c}-\hat{U}_{r} \hat{V}_{c}\right)^{2}\right) \\
&=\min _{\hat{\boldsymbol{U}}, \hat{\boldsymbol{v}}}\left(\sum_{r} \sum_{c}\left(A_{r c}-\sum_{p=1}^{\rho} \hat{U}_{r p} \hat{V}_{c p}\right)^{2}\right)
\end{aligned}$$

其中， 梯度公式：

$$\begin{aligned}
&\frac{\partial J}{\partial \hat{U}_{r q}}=\sum_{r} \sum_{c} 2 e_{r c} \frac{\partial e}{\partial \hat{U}_{r q}}=-2 \sum_{r} \sum_{c} \hat{V}_{c q} e \\
&\frac{\partial J}{\partial \hat{V}_{c q}}=\sum_{r} \sum_{c} 2 e_{r c} \frac{\partial e}{\partial \hat{V}_{c q}}=-2 \sum_{r} \sum_{c} \hat{U}_{r q} e
\end{aligned}$$

更新公式:

$$\begin{aligned}
&\hat{U}_{r q} \Leftarrow \hat{U}_{r q}+\lambda \sum_{r} \sum_{c} \hat{V}_{c q} e_{r c} \\
&\hat{V}_{c q} \Leftarrow \hat{V}_{c q}+\lambda \sum_{r} \sum_{c} \hat{U}_{r q} e_{r c}
\end{aligned}$$

```python
# gradient based svd
import numpy as np

A = np.random.randn(10,5)

U, S, V = np.linalg.svd(A, full_matrices=False)

K=5
Up = np.random.randn(10,K)
Vp = np.random.randn(5,K)
alpha=0.1

for epoch in range(1000):
    for r in range(A.shape[0]):
        for c in range(A.shape[1]):
            e = A[r][c] - Up[r]@Vp[c]
            for k in range(K):
                urk = Up[r][k] + alpha*e*Vp[c][k]
                vck = Vp[c][k] + alpha*e*Up[r][k]
                Up[r][k] = urk
                Vp[c][k] = vck
    if epoch%100 == 0:
        print('epoch:', epoch, 'error:', ((A - Up@Vp.transpose())**2).sum())

print('Final error:', ((A - Up@Vp.transpose())**2).sum())

print("A:\n", A)
print("A':\n", Up@Vp.transpose())

un = np.sqrt((Up**2).sum(0))
vn = np.sqrt((Vp**2).sum(0))
Up = Up / un
Vp = Vp / vn

print("un, vn:",un, vn)
Sp = un*vn

print("S:\n", S)
print(np.sort(Sp)[::-1])

print("U:\n", U)
print("Up:\n", Up)
```

## reverse AD

back propogation





## ref

-project
    - [200行写一个自动微分工具](https://github.com/tiandiweizun/autodiff)
- blog
    - [自动微分简介：前向模式、反向模式及python代码实现](https://www.cnblogs.com/simplex/p/6777895.html)
    - [数值微分的简单代码实现](https://zhuanlan.zhihu.com/p/78915545)
    - [reverse-mode-automatic-differentiation](https://rufflewind.com/2016-12-30/reverse-mode-automatic-differentiation)
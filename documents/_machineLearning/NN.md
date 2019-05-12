---
 title: NN
 categories: ml
 tags: ml
 date: 2019-04-18
---

neuron networks
neuron networks
neuron networks

non-linear hypothesis

## neuron model

In a neuron, it has **dendrites(树突)**  to input, and **axon(轴突)** as the output. In our model, $s_j$ to denote $jth$ layer. The first layer is the **input** layer x, and the output layer is $h_\theta(x)$. Our $x_0$ is the bias unit and is always 1. Between the input and the output is the **hidden layer** , and $a_i^j$ is called the **activitation units**, represent unit $i$ in layer $j$. 

$$\begin{bmatrix}x_0 \newline x_1 \newline x_2 \newline x_3\end{bmatrix}\rightarrow\begin{bmatrix}a_1^{(2)} \newline a_2^{(2)} \newline a_3^{(2)} \newline \end{bmatrix}\rightarrow h_\theta(x) \\$$

In this model, we use the same logistic function, yet we sometimes call it a sigmoid(logistic) **activation function**, the $\theta$ parameters are called **weights**. The values for each of the "activation" nodes is obtained as follows:

$$\begin{align*} a_1^{(2)} = g(\Theta_{10}^{(1)}x_0 + \Theta_{11}^{(1)}x_1 + \Theta_{12}^{(1)}x_2 + \Theta_{13}^{(1)}x_3) \newline a_2^{(2)} = g(\Theta_{20}^{(1)}x_0 + \Theta_{21}^{(1)}x_1 + \Theta_{22}^{(1)}x_2 + \Theta_{23}^{(1)}x_3) \newline a_3^{(2)} = g(\Theta_{30}^{(1)}x_0 + \Theta_{31}^{(1)}x_1 + \Theta_{32}^{(1)}x_2 + \Theta_{33}^{(1)}x_3) \newline h_\Theta(x) = a_1^{(3)} = g(\Theta_{10}^{(2)}a_0^{(2)} + \Theta_{11}^{(2)}a_1^{(2)} + \Theta_{12}^{(2)}a_2^{(2)} + \Theta_{13}^{(2)}a_3^{(2)}) \newline \end{align*} \\$$

We denote $\Theta^{(j)}$ as the matrix of weights controlling function mapping from layer $j$ to layer $j+1$. In the calculation,  the output nodes will not include the bias nodes while the inputs will. If network has $s_j$ units in layer j and $s_{j+1}$ units in layer j+1, then $Θ^{(j)}$ will be of dimension $s_{j+1}×(s_j+1)$.

In this section we'll do a vectorized implementation of the above functions. We set: 

$$z_1^{(2)}=\Theta_{10}^{(1)}x_0 + \Theta_{11}^{(1)}x_1 + \Theta_{12}^{(1)}x_2 + \Theta_{13}^{(1)}x_3 \\$$

The general form:

$$z^{(j)} = \Theta^{(j-1)}a^{(j-1)} \\$$

$$\begin{align*}x = \begin{bmatrix}x_0 \newline x_1 \newline\cdots \newline x_n\end{bmatrix} &z^{(j)} = \begin{bmatrix}z_1^{(j)} \newline z_2^{(j)} \newline\cdots \newline z_n^{(j)}\end{bmatrix}\end{align*} \\$$

$$a^{(j)}=g(z^{(j)}) \\$$

One example tp comibine some simple function to derive a complicated output.

![xnor example](https://d3c33hcgiwev3.cloudfront.net/imageAssetProxy.v1/rag_zbGqEeaSmhJaoV5QvA_52c04a987dcb692da8979a2198f3d8d7_Screenshot-2016-11-23-10.28.41.png?expiry=1510876800000&hmac=UJ3wo7uFqt1jzOv3MBlcIovABgKgISrUMkJHXudq3vc)

**multiclass classification**

one-vs-all method. Our output will be a vector, and we use $h_\Theta(x)^T=[0,\cdots,1_j,\cdots,0]$ to denote $j th$ output.

## calculation

**cost function**

- L = total number of layers in the network
- sl = number of units (not counting bias unit) in layer l
- K = number of output units/classes

the cost function for regularized logistic regression was:

$$J(\theta) = - \frac{1}{m} \sum_{i=1}^m [ y^{(i)}\ \log (h_\theta (x^{(i)})) + (1 - y^{(i)})\ \log (1 - h_\theta(x^{(i)}))] + \frac{\lambda}{2m}\sum_{j=1}^n \theta_j^2$$

For neural networks:

$$\begin{gather*} J(\Theta) = - \frac{1}{m} \sum_{i=1}^m \sum_{k=1}^K \left[y^{(i)}_k \log ((h_\Theta (x^{(i)}))_k) + (1 - y^{(i)}_k)\log (1 - (h_\Theta(x^{(i)}))_k)\right] + \frac{\lambda}{2m}\sum_{l=1}^{L-1} \sum_{i=1}^{s_l} \sum_{j=1}^{s_{l+1}} ( \Theta_{j,i}^{(l)})^2\end{gather*}$$

**backpropagation algorithm**

In the gradient descend, our goal is to compute $min_{\Theta}J(\Theta)$. Then we need to compute the partial derivative of $J(\Theta)$:  $\frac{\partial J(\Theta)}{\partial\Theta^{(l)}_{j,i}}$

intuition: $\delta^{(l)}_j=$"error" of node j in layer l.

- $\delta^{(L)}=a^{(L)}-y$  to compute error of the last layer, then update by $\delta^{(l)} = ((\Theta^{(l)})^T \delta^{(l+1)})\ .*g'(z^{(l)})$, ($l=2 \dots L-1$, $g'(z^{(l)})= a^{(l)}\ .*\ (1 - a^{(l)})$)

- $\Delta^{(l)}:=\Delta^{(l)}+\delta^{l+1}(a^{(l)})^T$, or in detail $\Delta^{(l)}_{j,i}:=\Delta^{(l)}_{j,i}+\delta^{l+1}_j(a^{(l)})_i^T$

- $D^{(l)}_{i,j} := \dfrac{1}{m}\left(\Delta^{(l)}_{i,j} + \lambda\Theta^{(l)}_{i,j}\right)$, if $j\neq 0$

  $D^{(l)}_{i,j} := \dfrac{1}{m}\Delta^{(l)}_{i,j} $, if $j=0$

- $\frac \partial {\partial \Theta_{ij}^{(l)}} J(\Theta)=D^{(l)}_{i,j}$


##implementation

**unrolling parameters**

```matlab
%put into one long vector
thetaVector = [ Theta1(:); Theta2(:); Theta3(:); ]
deltaVector = [ D1(:); D2(:); D3(:) ]
%get back matrix
Theta1 = reshape(thetaVector(1:110),10,11)
Theta2 = reshape(thetaVector(111:220),10,11)
Theta3 = reshape(thetaVector(221:231),1,11)
```

**gradient checking**

gradient approximation: $gradApprox=\frac{J(\theta+\epsilon)-J(\theta-\epsilon)}{2\epsilon}$

check that: $gradApprox\approx DVec$

Once you have verified **once** that your backpropagation algorithm is correct, you don't need to compute gradApprox again. The code to compute gradApprox can be very slow.

The main reason that we use the backpropagation algorithm rather than the numerical gradient computation method during learning is that the numerical gradient algorithm is very slow.

**random initialization**

*symmetry breaking*

initialize each $\Theta^{(l)}_{ij}$ to a random value in $[-\epsilon, \epsilon]$.

**training**

1. randomly initialize weights
2. forward propagation to get  $h_{\Theta}(x^{(i)})$ for any $x_{(i)}$
3. back propagation to get partial derivatives
4. gradient checking
5. learning to minimize $J$

## 卷积神经网络

- 输入
- 中间层
    - 卷积层：conv
    - 激励层：relu
    - 池化层：pooling layer
- 全连接层：flatten/fully connected layer

**卷积层**

- depth：滤波器个数
- stride：步长，每次移动步数
- zero-padding：外围边缘补0

- 参数共享：每一块区域使用同一个滤波器
- 池化：降低维度，最大值

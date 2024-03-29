---
 title: 06 neural network language model
 categories: nlp
 tags: nlp
 date: 2020-07-02
---

## 反向传播

$$\begin{align}\text{output layer } O&=W^2W^1X   \\
\text{activate function } Y&=f(O)   \\
\text{cost function } J&=L(Y)  \end{align} $$

![nn_bp.jpg](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/nlp/imgs/nn_bp.jpg)

如果$X=[x^1,x^3,x^3]$，则$O=XW^1W^2$，并且$W$的形状与左右神经元个数一致，即行数等于神经元输入个数，列数等于神经元输出个数。如果$X=\begin{bmatrix}x^1 \\ x^2 \\ x^3 \end{bmatrix}$，则$O=W^2W^1X$. 这里我们以第一种形式分析反向传播的矩阵形式。

首先，根据上图中单个元素的推导公式归纳其矩阵形式：
1. 计算输出层误差：
$$\Delta O=\frac{\partial{L}}{\partial{Y}}\frac{\partial{f}}{\partial{O}} \text{ 对应元素相乘}$$
2. 第一次反向传播隐藏层误差，如果有多个隐藏层，也是一样：
$$\Delta H=\Delta O \cdot (W^2)^T$$
3. 对于每格隐藏层的权重参数，取其左边的神经元值作为输入$N_X$，取其右边的误差$\Delta H$，做矩阵乘法：
$$\frac{\partial{L}}{\partial{W}}=\Delta W=N_X^T\cdot\Delta H   \\
 \frac{\partial{L}}{\partial{B}}=\Delta W=\Delta H$$

然后根据矩阵求导([ref1](https://zhuanlan.zhihu.com/p/83859554),[ref2](https://zhuanlan.zhihu.com/p/25496760)):
$$\begin{array}{l}
z=f(Y), Y=A X+B \rightarrow \frac{\partial z}{\partial X}=A^{T} \frac{\partial z}{\partial Y} \\
z=f(Y), Y=X A+B \rightarrow \frac{\partial z}{\partial X}=\frac{\partial z}{\partial Y} A^{T}
\end{array}$$
有：
$$\frac{\partial{L}}{\partial{W^1}}=X^T\cdot \frac{\partial{L}}{\partial{O}}\cdot (W^2)^T \\
\frac{\partial{L}}{\partial{W^2}}=（X\cdot W^1)^T \cdot \frac{\partial{L}}{\partial{O}}\cdot$$
但是如果中间隐藏层过多，假设有三层：
$$\begin{align}\Delta H_1 & =\Delta O\cdot (W^3)^T  \\ 
N_x&=X\cdot W^1   \\
\Delta W^2&=(X\cdot W^1)^T\cdot \Delta O\cdot (W^3)^T \end{align}$$
也许发现了一个规律：
$$\Delta W^i=\overbrace{(X \cdot W^1 \dots W^{i-1})^T}^{第i层的输入} \cdot \underbrace{\Delta O\cdot (W^{i+1}\cdot W^{n})^T}_{第i层的误差}$$

## 中间层非线性元

上述梯度公式是在中间神经元线性计算的情况下求得的，即：
$$ h=w_1\cdot x_1 +w_2\cdot x-2+\cdots +w_n\cdot x_n +b \\
H=XW^1W^2+B$$

实际中发现，简单线性可能造成误差过大，故中间层每层都增加激活函数（比如sigmoid函数），此时正向传播：
$$\begin{align} H_{temp}[i] &= H[i]\cdot W[i]   \\
    H[i] &= F_{activation}(H_{temp}[i]) \\
    Y &= F_{output}(H[-1])  \\
    E &= F_{cost}(Y,Y_{true})
\end{align}$$

反向传播：
$$\begin{align} \Delta_{Y} &=\frac{\partial{F_{cost}}}{\partial{Y}} \\
    \Delta_{H[-1]} &=\Delta_{Y} \cdot \frac{\partial{F_{output}}(H[-1])}{\partial{H[-1]}}  \\
    \Delta_{H_{temp}[-1]} &=\Delta_{H[-1]} \cdot  \frac{\partial{F_{activation}(H_{temp}[-1])}}{\partial{H_{temp}[-1]}}   \\
    \Delta_{H[i]} &=\Delta_{H_{temp}}[i+1] \cdot W[i]^T  \\
                &=\Delta_{H[i+1]} \cdot  \frac{\partial{F_{activation}(H_{temp}[i+1])}}{\partial{H_{temp}[i+1]}} \cdot W[i]^T  \\
    \Delta_{H_{temp}[i]} &=\Delta_{H[i]} \cdot  \frac{\partial{F_{activation}}(H_{temp}[i])}{\partial{H_{temp}[i]}}     \\
    \Delta_{W[i]} &=H[i-1]^T \cdot \Delta_{H_{temp}[i]} \\
                  &=(X \cdot W^1 \dots W^{i-1})^T \cdot \Delta_{H_{temp}[i]}    \\
    \Delta_{B[i]} &=\Delta_{H_{temp}[i]} \end{align}$$




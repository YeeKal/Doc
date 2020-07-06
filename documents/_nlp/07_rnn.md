## ref

Recurrent Neural Networks Tutorial:
- [Part 1 – Introduction to RNNs](http://www.wildml.com/2015/09/recurrent-neural-networks-tutorial-part-1-introduction-to-rnns/)
- [Implementing a RNN with Python, Numpy and Theano](http://www.wildml.com/2015/09/recurrent-neural-networks-tutorial-part-2-implementing-a-language-model-rnn-with-python-numpy-and-theano/)
- [Part3- Backpropagation Through Time and Vanishing Gradients](http://www.wildml.com/2015/10/recurrent-neural-networks-tutorial-part-3-backpropagation-through-time-and-vanishing-gradients/)

Applications:
- score arbitrary sentences based on how likely they are to occur in the real world: machine translation
- generate new text

## RNN

![rnn](imgs/rnn.jpg)

RNN的一级层次是由上图中的t标识的，表示有多少个简单的网络进行时序连接。比如如果一个句子有5个单词，每个单词都需要输入一个简单网络，则需要五个简单网络连接构成一个完整的RNN网络。

- $x_t$: input vector for each word in a sentence 
- $s_t$: $s_{t}=f\left(U x_{t}+W s_{t-1}\right)$, $f$ usually is a nonlinearity such as tanh or ReLU.
- $o_t$: $o_t=softmax(V\cdot s_t)$ ,the output at step $t$.
- in each step, a RNN shares the same parameter ($U,V,W$)

## Backpropagation on RNN

Forward Propagation:
$$\begin{align} s_t &= f_1(U x_{t}+W s_{t-1})=tanh(U x_{t}+W s_{t-1}) \\
                \hat{y_t} &=f_2(Vs_t)=softmax(Vs_t) \\
                E_t(y,\hat{y})&=\sum_{t}E_t(y_t,\hat{y_t})  \longrightarrow \text{  loss function}\\
                            &=-\sum_{t}y_t\log{\hat{y_t}} \end{align}$$
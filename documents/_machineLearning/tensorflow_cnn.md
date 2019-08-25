---
 title: NN
 categories: ml
 tags: ml
 date: 2019-08-20
---

```python
# 10张 15x15的3通道图片 [batch height width channels]
# 3x3卷积核，作用在5通道图片上，得出10通道
# 输出为10张7x7 10通道
input=tf.Variable(tf.random_normal([10,15,15,5]))
w1=tf.Variable(tf.random_normal([3,3,5,10]))
op=tf.nn.conv2d(input,filter,strides=[1,2,2,1],padding='SAME')

b1=tf.get_variable('b1',initializer=tf.constant(0.1,shape=[64]),trainable=FLAGS.trainable)
h1=tf.nn.relu(conv2d(input,w1)+b1)
h1_pool=tf.nn.max_pool(h1,ksize=[1,2,2,1],strides=[1,2,2,1],padding='SAME')
h1_pool=tf.nn.max_pool(h1,ksize=[1,2,2,1],strides=[1,2,2,1],padding='SAME')
'''
ksize=[1,height,width] 不想在batch与channel上做池化
strides=[1,stride,stride,1] 滑动步长
'''

tf.matmul(x,y) #x*y
tf.multiply(x,y) #x，y各元素对应相乘
tf.nn.dropout() #是tensorflow里面为了防止或减轻过拟合而使用的函数，它一般用在全连接层
```
---
 title: numpy
 categories: python
 tags: pandas
 date: 2020-07-05
---
## 乘法

```python
'''
*: 对应位置相乘
a.dot(b)： 矩阵则按照矩阵乘法，向量则对应位置相乘之后加起来，类似内积
          矩阵乘以向量也是按矩阵乘法
np.dot(): 对于秩为1的数组，执行对应位置相乘，然后再相加
        对于秩不为1的二维数组,执行矩阵相乘
        与a.dot一致
np.multiply: 数组和矩阵对应位置相乘，输出与相乘数组/矩阵的大小一致,与*一致
np.matmul(): 矩阵相乘
'''
```

## 维度改变

```python
np.atleast_2d() #
'''
a=np.array([1,2,3,4])  ->  array([1, 2, 3, 4])
np.atleast_2d(a)       ->  array([[1, 2, 3, 4]])

为了使得行向量乘列向量得到一个矩阵，则必须将1维的行列向量转化为二维
'''

>>> a
array([2., 3., 4.])
>>> b
array([2., 3., 4.])
>>> np.atleast_2d(a).T.dot(np.atleast_2d(b))
array([[ 4.,  6.,  8.],
       [ 6.,  9., 12.],
       [ 8., 12., 16.]])
>>> 
```
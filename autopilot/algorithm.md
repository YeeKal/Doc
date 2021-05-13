---
title: coding
categories: CAT
tags: TAG
date: 2021-05-07
---

#### 螺旋数组

1. 遍历过的地方做标记
2. 根据步进做换向：

> di=0, dj=1 | di,dj=dj,-di(右转向，-90旋转矩阵)

```python
def spiralMatrix(nums):
    i=0
    j=0
    di=0
    dj=1
    rows=len(nums)
    cols=len(nums[0])
    for _ in range(rows*cols):
        print("{} ".format(nums[i][j]), end="")
        nums[i][j]=None
        next=nums[(i+di)%rows][(j+dj)%cols]
        if next is None:
            di,dj=dj,-di
        i += di
        j += dj
    
    print()
```

#### 旋转矩阵

顺时针旋转90度：

> m[i][j] -> m[j][row-1-i]

思路1： 非原地旋转，复制一份数据，再赋值给原来的


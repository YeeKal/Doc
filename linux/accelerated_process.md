---
title: 加速运算
categories: linux
tags: linux
date: 2023-01-30
---

## 三角函数

```python
def fastsin(fAngle):
    fASqr = fAngle*fAngle
    fResult = 7.61e-03
    fResult *= fASqr
    fResult -= 1.6605e-01
    fResult *= fASqr
    fResult += 1.0
    fResult *= fAngle
    return fResult
print(np.sin(2*np.pi/1024))
print(fastsin(2*np.pi/1024))
```


## ref

- [常见三角函数优化版本](https://codeantenna.com/a/gpUXb6uc9z)
- [cordic 算法- The Story of Unified Cordic](https://blog.csdn.net/liyuanbhu/article/details/8458769)
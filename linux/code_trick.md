---
title: 更高效的代码
categories: 
tags: 
date: 2022-11-15
---

1. 对内置函数的慎用

```c++
pow(a, 2); -> a*a

a / b;
c /b;
->
d = 1/b;
d * a;
d * c;
```

2. 数据结构

BSP 树
Quad树
R树（rectangle）
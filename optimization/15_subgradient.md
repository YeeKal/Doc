---
title: subgradient
categories: optimization
tags: optimization
date: 2023-07-17
---

## Subgradient(次梯度)

remember <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>First-order characterization</font>** for convex and differential $f$（切线总是在函数的下方）：

$$f(y)\geq f(x) + \nabla f(x)^T(y-x) $$


类比凸函数的一阶条件，给定函数$f$， 对于$\forall y$， 如果满足：

$$f(y)\geq f(x)+g^T(y-x)$$

则称$g$是函数$f$在点$x$处的次梯度。

- 次梯度不唯一，也可能不存在。对于可微的凸函数 $g=\nabla f$ 是唯一的
- 用于解决并不总是处处可导的凸函数

## Subdifferential

把$f$在$x$处所有次梯度构成的集合称为$f$在$x$处的<font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>次微分(Subdifferential)</font>, 记作$\partial f(x)$


## Ref

- [ref code with python](https://github.com/minigonche/subgradient_descent/blob/master/subgradient.py)
---
 title: 牛顿法的改进方法
 categories: optimization
 tags: optimization
 date: 2019-12-24
---

## Gauss-Newton

non-linear problem

$$a_{a+1}=a_n-(J(a_n)^TJ(a_n))^{-1}J(a_n)^TF(a_n)$$

## Levenberg-Marquardt

对Gauss-Newton迭代步的修正,防止雅可比奇异位形(damped least squares)：
$$a_{a+1}=a_n-(J(a_n)^TJ(a_n)+\mu(a_n)I)^{-1}J(a_n)^TF(a_n)$$

- quasi-Newton methods
- Sequential Quadratic Programming(SQP)
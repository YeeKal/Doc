---
title: 轨迹优化之
categories: motion planning
tags: planning
date: 2021-08-17
---

## trajopt


## chomp

functional gradient: 泛函梯度

$$\bar{\nabla} u[\xi]=\frac{\partial v}{\partial \xi}-\frac{d}{d t} \frac{\partial v}{\partial \xi^{\prime}}$$

梯度下降：

$$\xi_{i+1}=\xi_{i}-\eta_{i} \bar{\nabla} U[\xi]$$


## ref

- blog 
- paper
    - [trajopt](https://rll.berkeley.edu/trajopt/doc/sphinx_build/html/)    
    - [2011-Parallel Algorithms for Real-time Motion Planning](https://www.ri.cmu.edu/pub_files/2011/7/mcnaughton-thesis.pdf)

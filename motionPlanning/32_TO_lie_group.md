---
title: trajectory optimization on Lie group
categories: 
tags: 
date: 2023-12-27
---

## 2023-RSS-Convex Geometric Motion Planning on Lie Groups via Moment Relaxation

- [2023-RSS-Convex Geometric Motion Planning on Lie Groups via Moment Relaxation](https://arxiv.org/abs/2305.13565)
- [video-youtube](https://www.youtube.com/watch?v=othZX-T-r5A) 

**<font color='Tomato'>Background</font>**

- local search methods: fast, but depends on good initialization
- sampling-based methods: only probabilistic complete
- global optimization:
    - (discrete)Mixed-integer programming
    - (continuous)Polynomial programming

Global optimization does not scale well:
- robot models
- problem structure

This methods:
- geometric formulation for robot dynamics
- exploit the problem sparsity
- leverage the <font style='background: #007f16;color: #ffffff;opacity:1.0;border-radius: 5px; padding:5px;'>Lasserre's hierarchy</font>  of moment relaxation

for kinodynamic motion planning

**<font color='Tomato'>Method</font>**

- Polynomial optimization problem(POP)
    - Polynomial objective and constraints


[book: An introduction to polynomial and semi-algebraic optimization]()


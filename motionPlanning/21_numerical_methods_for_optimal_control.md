---
title: 最优控制问题的数值解法
categories: motion planning
tags: trajectory optimization
date: 2021-11-03
---
$$\begin{aligned}
J&=arg\min_{u(.)}\int^{t_f}_{t_0}C(x(t), u(t))dt  \\
s.t.\quad x(t_0)&=x_0   \\
\dot{x}(t) &=f(x(t), u(t))   \quad \forall t  \quad \text{(states function)} \\
g(x)&\leq g_i,  \quad \forall t \quad \text{(path constraint)} 
\end{aligned}$$

最有控制问题解法一般分为间接法和直接法。间接法主要根据变法法理论确定最优性条件，之后通过解BVP问题得到极值点，在根据极值点判断出最优解。直接法是通过离散控制量和状态量，把积分和微分方程转变为更加简单的形式，由此转换为非线性优化问题求解。

- indirect methods: calculus of variations, boundary-value problem. 
- direct methods: discretize control or state

## 微分和积分的数值方法

time-marching

collocation:
    - Gauss methods
    - Radau methods
    - Lobatto methods

    - Euler
    - Runge-Kutta
    - orthogonal collocation
        - Chebyshev polynominals
        - Legendre polynominals

## 非线性优化的数值方法
The NLP may either be dense (i.e., a large percentage of the derivatives of the objective function and the
constraint functions with respect to the components ofzare nonzero) or may be sparse (i.e., a large percentage
of the derivatives of the objective function and the constraint functions with respect to the components of z
are zero). Dense NLPs typically are small (consisting of at most a few hundred variables and constraints)
while sparse NLPs are often extremely large (ranging anywhere from thousands of variables and constraints
to millions of variables and constraints). Numerical methods for solving NLPs fall into categories: gradientbased methods and heuristic methods

gradient-based methods

heuristic methods: global technique

- genetic algorithms(进化算法), evolutionary approach
- Simulated Annealing(模拟退火)
- particle swarm optimization(PSO, 粒子滤波)

## indirect



## direct

#### Direct shooting method

#### Direct Multiple Shooting Method

#### Direct collocation methods

局部曲线连接

leads to  a large sparse NLP


#### pseudospectral method

a global form of  orthogonal collocation： 全局曲线，点是选择的曲线上的点，

spectrally: approximation will converge spectrally (i.e., at an exponential rate) as a function of the number of collocation points

当前一般使用拉格朗日多项式


## ref

- paper
    - [2010-A Survey of Numerical Methods for Optimal Control](https://www.researchgate.net/publication/268042868_A_Survey_of_Numerical_Methods_for_Optimal_Control)
- project
    - [opty: using direct collocation in the optimization of dynamic systems](https://github.com/csu-hmc/opty/blob/master/opty)
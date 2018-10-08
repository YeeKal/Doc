---
title: closed constraint motion planning
categories: paper
tags: closed
date: 2016-06-01
---

## A Probabilistic Roadmap Approach for Systems with Closed

- 1999

1. break the chain loops
2. randomized gradient descent to generate samples
3. tangent space sample to connect neighbor points

## A Kinematics-Based Probabilistic Roadmap Method for Closed Kinematic Chains

- 2000
- KBPRM: kinematics based prm

1. node generation
    - randomly generate $\theta_a$
    - forward kinematics to compute end-frame configuration $g_{la}$
    - inverse kinematics to solve $\theta_p$
    - $\theta=(\theta_a,\theta_p)$,is retained if it is collision-free
2. node connection

## Randomized path planning for linkages with closed kinematic chains

- 2001
- randomized gradient descent

**random samples**

0. kinematic error
$$e(q)=\sum_{k\in B}||J_k(q)-J^{'}_k(q)||^2$$
1. random q in $C_{free}$
2. compare and select q with smaller error(gradient descend)

Other approaches, such as the **Levenberg-Marquardt** nonlinear optimization algorithm could be used instead of randomized descent.

*GENERATE_RANDOM_SAMPLE()*

1. q$\gets$ RANDOM_CONFIGURATION();
2. $i\gets 0;j\gets 0$
3. while $i<I$ and $j<J$ and $e(q)>\epsilon$ do
4. &emsp; i++; j++;
5. &emsp; $q'\gets \text{RANDOM_NHBR}(q)$;
6. &emsp;if $e(q')<e(q)$ then
7. &emsp;&emsp; $j\gets 0;q\gets q';$
8. if $e(q)\leq \epsilon$ then 
9. &emsp;Return $q$
9. else 
10. &emsp;Return FAILURE

**connect points: incremental motions**

step is small enough

1. tangent space sample: SVD on the matrix of the partial derivatives to find the orthonormal basis.recursive derivative:
$$\begin{bmatrix} X_n \\ Y_n\\1 \end{bmatrix}=\begin{bmatrix} cos(q_n) & -sin(q_n) & l_{n-1}\\ sin(q_n) &  cos(q_n) 0 \\0& 0& 1 \end{bmatrix}\begin{bmatrix} X_{n-1} \\ Y_{n-1}\\1  \end{bmatrix}$$
$$\begin{aligned}
\frac{\partial{X_n}}{\partial{q_i}}&=\begin{cases}cos(q_n)\frac{\partial{X_{n-1}}}{\partial{q_i}}-sin(q_n)\frac{\partial{Y_{n-1}}}{\partial{q_i}} &i\leq n\\ -sin(q_n)X_{n-1}-cos(q_n)Y_{n-1} &i= n  \end{cases}    \\
\frac{\partial{Y_n}}{\partial{q_i}}&=\begin{cases}sin(q_n)\frac{\partial{X_{n-1}}}{\partial{q_i}}-cos(q_n)\frac{\partial{Y_{n-1}}}{\partial{q_i}} &i\leq n\\ cos(q_n)X_{n-1}-sin(q_n)Y_{n-1} &i= n  \end{cases}
\end{aligned}$$
then the position could be computed with the derivatives directly:
$$\begin{aligned}
X_n&=\frac{\partial{Y_n}}{\partial{q_n}}+l_{n-1}\\
Y_n&=-\frac{\partial{X_n}}{\partial{q_n}}
\end{aligned}$$

2. random sample 

*CONNECT_CONFIGURATIONS(q,q')*

1. $i\gets 0;j\gets 0; k\gets 0; L\gets {q};$
2. while $i<I$ and $j<J$ and$k<K$ and $\rho (LAST(L),q')>\rho_0$ do
3. &emsp; i++; j++;
4. &emsp; $q{''}\gets \text{RANDOM_NHBR}(LAST(L))$;
5. &emsp;if $e(q{''})<\epsilon$ then
6. &emsp;&emsp; $j\gets 0;k++;$
7. &emsp;&emsp;if $\rho(q{''},q')<\rho(LAST(L),q')$ then 
8. &emsp;&emsp;&emsp;$k\gets 0; L\gets L+{q{''}};$
9. if($\rho (LAST(L),q')\leq \rho_0$) then
10. &emsp;Return L; 
11. else 
10. &emsp;Return FAILURE


**tangent space**

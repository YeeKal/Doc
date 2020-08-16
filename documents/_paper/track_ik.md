---
title: track ik
categories: paper
tags: kinematics
date: 2019-01-4
---

Reference: **TRAC-IK: An Open-Source Library for Improved Solving of Generic Inverse Kinematics**

TRAC-IK: an improved ik algorithm which used a set of sequential quadratic programming(SQP).

**KDL-RR**:when the iteration get stuck in local minima($q_{next}-q_{prev}\approx 0$), use random seeds to restart iteration when local minima are detected.

**SQP**
to handle constraints like joint limits, it's viewed as a nonlinear optimization problem which can be solved locally using sequential quadratic programming.
$$arg\ \min_{q\in \mathcal{R}^n}\ (q_{seed}-q)^T(q_{seed}-q) \\
s.t.\ f_i(q)\leq b_i, i=1,\dots,m.$$
where the inequality constraints $f_i(q)$ are the joint limits, the euclidean distance error and the angular distance error.

works poorly. minimize the overall amount of joint movement and only considering cartesian error as constraint.

**SQP-DQ**

The nonlinear optimization formulation was changed to minimize **cartesian pose error** directly, and only **joint limits** continue to be constraints. The amount of joint motion is not needed.

The cartesian error which combines translation and orientation is expressed with **dual quaternion**.The minimize function is defined by:
$$\phi_{DQ}=4(log(e)\cdot log(e)^T) \\
e=q1*q2^*$$
where e represents the pose error in dual quaternion form.

**SQP-SS**

$$\phi_{SS}=twist_{err}\cdot twist^T_{err}$$

**SQP-L2**

$$\phi_{SS}=\sqrt{twist_{err}\cdot twist^T_{err}}$$

**TRACK-IK**

spawns two solvers, one running **SQP-SS** and another running **KDL-RR**. once either finishes with a solution, both thread are terminated and the resulting solution is returned.

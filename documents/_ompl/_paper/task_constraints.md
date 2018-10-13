---
title: task constraint motion planning
categories: paper
tags: closed
date: 2018-07-24
---

## Motion Planning With Constraints Using Configuration Space Approximations

```
read: 2018-09-27
publish: 2012
```
- rejection sampling
- jacobian projection
- optimization-based approaches

1. starts with compution an approximation of the constraint manifold offline
2. planning on the constraint manifold directly instead of planning in the full configuration space

** approximating constraint manifolds**

1. generating an approximation graph

line 1-4, generate a feasible configuration;line 5-10, compute valid expansion edges
```c
Algorithm 1 Generate Constraint Manifold Approximation
Input: c: task constraint; ns : # configs; ne : # edges/config
Output: Approximation Graph
1: Approx = EmptyApproximation()
2: while ConfigCount(Approx) < ns do
3:  if Sample(c, x) then
4:      AddSample(Approx, x)
5: for i = 0 to ConfigCount(Approx)-1 do
6:  j =0
7:  while OutEdges(Approx, i) < ne and j < ConfigCount(Approx) do
8:      if i 6= j and ValidEdge(Approx, i, j) then
9:          AddEdge(Approx, i, j)
10:         j = j +1
11: return Approx
```
2. planning directly on the constraint manifold
3. smapling on approximation graph 
    - sampling an interger value $i\in [0,n_s-1]$, which represents the configuration at index $i$ in the approximation graph.
    - sampling configurations uniformly in a ball
3. 

## sampling-based-methods-for-motion-planning-with-constraints

```
read: 2018-07-1
publish: 2018
```

### introduction
    
1. potential field methods
2. heuristic search techniques
3. sampling bsaed algorithms

- geometry constraints 
    - cartesian constraints: cartesian curve tracking
- soft constraints: penalty function

### motion planning and constraints

**configuration space**: represent the robot with a point in a higher-dimensional space. It is a metric space(度量空间,有序对的集合，点点之间定义了距离函数). The dimensionality n of Q corresponds to the number of degrees of freedom of the robot.

**geometry constraints**: not velocity or acceleration constraints. 

- constraints function: $F;Q\rightarrow \mathcal{R}^k$ such that $F(q)=0$,continuous and differentiable
- m=n-k, the effective number of degrees of freedom
- constraint function defines an m-dimensional implicit constrained configuration space eithin the ambient configuration space:
$$X=\{q\in Q|F(q)=0\}$$

**end-effector constraints**

**methodology overview**

- relaxation
    - changing $F(q)=0$ to $||F(q)||\leq \epsilon$, introducing an allowable tolerance to the constraint
- projection
    - takes a configuration and projects it into the set of satisfying configurations, retracting the point to a minimum of the constraint function. 
    - A common implementation of projection is a Newton procedure with Jacobian inverse gradient descent.
- tangent space
    - defines a locally linear approximation of the constraint manifold to a Euclidean space, which extends until the curvature ofthe manifold bends sufficiently away.
    - the tangent vector pointing from the initial configuration to the goal is projected into the tangent space and then generated the next configuration
    - curve tracking constraints for redundant manipulators
    - works well when constraints are closer linear
- atlas
    - require that the constraint function defines a manifold
    - atlasrrt: handling singularities
    - tb-rrt
- reparameterization: 
    - compute a new reparameterized space
    - the constrained planning problem can be reduced to the unconstrained instance
- offline sampling
    - sampling before planning take place

two core primitive operations:

- sampling constraint-satisfying configurations
- generating constraint-satisfying continuous motion

- projection through iteration:
        $$\begin{align}
        \text{PROJECTION(q)}:&\\
        &x\gets F(q)\\
        &\text{while } ||x||>\epsilon \text{ do}\\
        &\quad \Delta q\gets J(q)^{\dagger}x \\
        & \quad q\gets q-\Delta q \\
        & x\gets F(q)  \\
        &\text{return }q
        \end{align}$$

## Global manipulation planning in robot joint space with task constraints

```
read: 2018-07-10
publish: 2007/2010
key: tangent space sampling(TS)
     first order retraction(FR)
     randomized gradient descent(RGD)
```

1. representation of constraints
    - $q_i$: joint space coordinates
    - $x_i$: task space coordinates
    - $T^A_B$: rigid body transformation
    - $\mathcal{F}^0$: world frame
    - $\mathcal{F}^t$: task frame
    - $\mathbb{C}$: motion constraint vector
    $$\begin{aligned}
    \mathbb{C}&=\begin{bmatrix}c_x & c_y & c_z&c_{\phi} &c_{\theta}&c_{\psi}\end{bmatrix}^T  \\
    c_i&=1 \quad \text{indicates the end-effector along this coordinate is invalid}
    \end{aligned}$$
2. specifying constraints
    - fixed frames: universal constraint on the robot end-effector
        - $\mathcal{F}^t$ is any frame in which the axes align with the directions of constrained motion
        - $\mathbb{C}_t$ indicates which axes permit valid displacements
    - simple frame parameters: constraint respect to the configuration of the robot
    - kinematic closure constraints
        - compare the multiple end effector transformations
    - constraint on nonlinear paths and surfaces
3. constrained sampling
    - distance: transformation for $\mathbb{F}^e$ with respect to the task frame $\mathbb{F}^t$
    $$T^t_e(q)=(T^0_t)^{-1}T^0_e(q)$$
    which will be regarded as the error:
    $$\Delta x\equiv=T^t_e(q)$$
    the invalid error is determined by motion constraint vector:
    $$\Delta x_{err}=C\Delta x$$
    where C is a diagonal-selection matrix respect to $\mathbb{C}$
    - jacobian
        - task frame jacobian: $J^t=\begin{bmatrix}R^t_0 & 0 \\0&R^t_0 \end{bmatrix}J^0$
        - map velocity in the workspace to task space: $J(q_s)=E(q_s)J^t(q_s)$
        - right pseudoinverse: $J^\dagger=J^T(JJ^T)^{-1}$ or LU decomposition

        $\Delta x$ 是任务空间的误差，$J^{\dagger}\Delta x$ 把任务空间的误差映射到关节空间。同理$J\Delta q$把关节空间误差映射到任务空间。

    - tangent space sampling
        - these displacements have no instantaneous component in the direction of task error:
        $$CJ\Delta q=0$$
        $$\Delta q^{'}=(I-J^\dagger CJ)\Delta q$$
        - the project sample: $q^{'}_s=q_{near}+\Delta q^{'}$. Due to the nonlinearty of the constraint manifold, $q^{'}_s$ is still unlikely to within error tolerance, then RGD is applied to further reduce the task-space error.
    - first-order retraction
        - find the task space error and compute the least-norm joint space displacement that compensates for error

        在`end-effector constraints` 中，限制函数显示作用在任务空间中，所以通过正运动学对关节空间中变量求得任务空间中误差，再通过雅可比伪逆球的关节空间中误差。
        $$\begin{aligned}
        \Delta q_{err}&=J^\dagger \Delta x_{err}\\
        q^{'}_s&=q_s-\Delta q_{err}
        \end{aligned}$$
    - linear jacobian transformation $E_{rpy}(q)$
    
    

## Manipulation Planning on Constraint Manifolds

```
 read: 2018-07-24
 publish: 2009
 key: CBIRRT
```

two strategies for dealing with constraints: rejection and projectin. **rejection**: check if a given configuration meets the constraint, which is effective when there is a high probability of randomly sampling configurations that satisfy this constraint. **Projection**: more robust to stringent constraints.

$T^0_c$: constraint frame, reference to the base frame. Then constraint are defined in terms of the permissible differences between the end-effector frame $T^0_e$ and $T^0_c$. The motion constraint matrix：
$$C=\begin{bmatrix}
c_{x_{min}} & c_{x_{max}} \\ 
c_{y_{min}} & c_{y_{max}}  \\
c_{z_{min}} & c_{z_{max}}  \\
c_{\psi_{min}} & \psi_{x_{max}} \\ 
c_{\theta_{min}} & \theta_{y_{max}}  \\
c_{\phi_{min}} & \phi_{z_{max}}  \\
\end{bmatrix}$$
First compute transformation from end-effector to constraint frame:
$$T^c_e=(T^0_c)^{-1}T^0_e$$
Then $T^c_e$ will be transferd to 6-d vector:
$$d^c=\begin{bmatrix}
t^c_e \\
arctan2(R^c_{e32},R^c_{e33}) \\
-arcsin(R^c_{e31})  \\
arctan2(R^c_{e32},R^c_{e33}) \\
 \end{bmatrix}$$
Get the displacement error$\Delta X$:
$$\Delta x_i=
\left\{
\begin{aligned} 
d^c_i-C_{i_{max}} \quad& if d_i^c>C_{i_{max}} \\
d^c_i-C_{i_{min}} \quad& if d_i^c<C_{i_{min}} \\
0                   \quad& otherwise
\end{aligned}
\right.$$

## Smapling-Based Methods for Motion Planning with Constraints





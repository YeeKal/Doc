
## optimal control based planning

$$\begin{aligned}
u^*(t):&=arg\min_{u(.)}\int^{t_f}_{t_0}C(x(t), u(t))dt  \\
s.t.\quad x(t_0)&=x_0   \\
\dot{x}(t) &=f(x(t), u(t))   \quad \forall t \\
x(t) &\in \mathcal{X}_{feas},  \quad \forall t \quad \text{(collision-free)} \\
u(t) &\in \mathcal{U}_{feas},  \quad \forall t \quad \text{(control-limits)} 
\end{aligned}$$

- In the view of control: generate feasible control inputs under dynamics constraints

- In the view of planning: generate dynamically-feasible waypoints (which will be tracked with appropriate control methods)

#### methods

- explicit methods: convex problem,  LQR
- numerical methods: shooting, collocation
    - convex
        - software: CVX, OSQP
        - internal: Gurobi, Sedumi, Mosek
    - non-convex
        - interior point: IPOPT, SNOPT
        - active  set methods: SAS


lqr, mpc


#### considerate dynamics

directly generate dynamically-feasible trajectory, the tricky points:

- obstacle avoidance
- hybrid mode switch (contact force)
- energy efficiency and smoothness(min jerk, snap)

#### obstacle avoidance

simple geometric constraints: e.g. $(x-x_{obs})^2+(y-y_{obs})^2\geq r^2$. such constraints are general non-convex.

to make it convex:

- mixed-integer formulation

```
8Richards and How, “Aircraft trajectory planning with collision avoidance using mixed integer linear programming”.
9Deits and Tedrake, “Footstep planning on uneven terrain with mixed-integer convex optimization”.
10Deits and Tedrake, “Efficient mixed-integer planning for UAVs in cluttered environments”.
```

- dual variables

```
1Zhang, Liniger, and Borrelli, “Optimization-based collision avoidance
github: https://github.com/XiaojingGeorgeZhang/OBCA
```

- chomp/stomp/ Sequential Convex Optimization

```
2Schulman et al., “Motion planning with sequential convex optimization and convex collision checking”
```

## contact force

Optimization through contact(contact invariant optimization): contact force is zero or distance between contact points should be zero.

application case: manipulation with finger contact, legged robotics

```
lab: https://homes.cs.washington.edu/~todorov/projects.html
github: https://github.com/robbierolin/Contact-Invariant-Optimization-Project
Contact-Invariant Optimization for Hand Manipulation: https://homes.cs.washington.edu/~zoran/MordatchSCA12.pdf
Discovery of Complex Behaviors through Contact-Invariant Optimization
```



## paper reading:

**Simultaneous path planning and trajectory optimization for robotic manipulators using discrete
mechanics and optimal control**

- three stage
    - path planning
    - trajectory planning: velocity, smooth
    - control: torque
- swarm-intelligence based algorithm:
    - PSO(Particle Swarm Optimization)
    - ACO(Ant Colony OPtimization)
    - ABC(Artificial Bee Colony Optimization)
    - FA(Firefly Algorithms)
    - BA(Bat Algorithm) 
- dp



- trajectory planning
- trajectory optimization
- optimal trajectory planning


Time-optimal Control of Manipulators: 李群上机械臂的最有控制，路径规划和轨迹优化同时进行


**Efficient Trajectory Optimization for Robot Motion Planning**

an optimal control based approach to address the path planning and trajectory planning
subproblems simultaneously

- Pseudospectral Method: Legendre拟谱方法
- Chebyshev-Lobatto points：$T_i=\frac{t_f}{2}(cos(\frac{i\pi}{N})+1) i=0,\cdots,N$
- barycentric interpolation


## Pseudospectral

ref: 最优控制问题的Legendre_伪谱法求解及其应用

- Gauss  伪谱法
- radau  伪谱法
- Legendre  伪谱法
- Chebyshev  伪谱法

## ref

- blog
    - [References on Optimal Control, Reinforcement Learning and Motion Planning](https://github.com/eleurent/phd-bibliography)

- course
    - [Robotic Systems](https://motion.cs.illinois.edu/RoboticSystems/)
    - [Model Predictive Control](http://cse.lab.imtlucca.it/~bemporad/mpc_course.html)
- projects
    - [Efficient Trajectory Optimization for Robot Motion Planning -- Examples](https://github.com/yzhao334/Efficient-Trajectory-Optimization-for-Robot-Motion-Planning--Examples)
    - [towr](https://github.com/ethz-adrl/towr)
    - [gpmp2](https://github.com/gtrll/gpmp2)
- paper
    - pseudospectral
        - [2010-A Pseudospectral Optimal Motion Planner for Autonomous Unmanned Vehicles](https://core.ac.uk/download/pdf/36737091.pdf)
        - [2007-A Pseudospectral Method for Real-Time Motion Planning and Obstacle Avoidance ](https://apps.dtic.mil/sti/pdfs/ADA478686.pdf)
    - [Obstacle avoidance using optimal control theory](https://www.semanticscholar.org/paper/Obstacle-avoidance-using-optimal-control-theory-Hagenaars/7fc04bb7953ad69efdfe00721f589dce60e69f5f)
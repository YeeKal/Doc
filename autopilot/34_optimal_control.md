
Optimal Control :

- direct methods: transform into Nonlinear Program
    - single shooting: discretized controls
    - collocation: discretized controls and states
    - multiple shooting: controls and node start values



- locally optimal control
    - shooting
    - collocation
- forward dynamics models and shooting
    - lqr
    - ddp

ODE(Ordinary differential equation): 常微分方程



||Indirect method|Direct method|
|:--|:--|:--|
|Solution Scheme|First optimize, then discretize(e.g. Pontryagin (PMP))|First discretize, then optimize (transfer the infinite problem into finite- imensional Nonlinear Programming problem (NLP), and solve NLP)|
|Pros|1. Boundary value problem with only 2n_x ODE 2. can treat large scale systems|1. can use state-of-the-art methods for NLP solution 2. can treat inequality constraints and multipoint constraints much easier|
|Cons|1. only necessary conditions for local optimality2. Need explicit expression for control u*(t), singular arcs difficult to treat3. ODE is strongly nonlinear and unstable4. inequalities lead to ODE with state-dependent switches|1. obtain only suboptimal/approximate solution|
|Applications|optimal control e.g. in satellite orbit planning at CNES|most commonly used nowadays due to their easy applicability and robustness|



## shooting

$$\min_{u^0,\cdots,u^T}\sum_t C^t(x^t), x^{t+1}=f(x^t, u^t)$$

对定步长时间序列，通过参数方程对控制变量离散化： $u(t,q)$

$$u(t,q)=q_k \quad \text{for} \quad t\in[t_K, t_{k+1}]$$

$x(t)$则被视为因变量，通过对状态方程积分得到。因此有可以被写为$x(t,q)$. 如此转化为关于q的最优化问题。

## collocation

$$\min_{x^0,\cdots,x^T}\sum_t C^t(x^t), u^{t}=f^{-1}(x^t, x^{t+1})$$


## ref

- course
    - [Numerical Optimal Control](https://www.syscop.de/teaching/ss2020/numerical-optimal-control-online)
    - [NUMERICAL METHODS FOR OPTIMAL CONTROL](https://mariozanon.wordpress.com/numerical-methods-for-optimal-control/)




initial point/goal point/intermediata points/constraints

many constraints with a straight path.

**cubic polynomial**

initial conditions:

$$\begin{align}\theta(0)&=\theta_0 \\\theta(t_f)&=\theta_f \\ \dot{\theta}(0)&=0 \\ \dot{\theta}(t_f)&=0 \end{align}$$

At least 3-order polynomials could satisfy these, and the 4 conditions determine the unique cubic polynomial. More constraints need higher order polynomial.

$$\theta(t)=a_0+a_1t+a_2t^2+a_3t^3$$

- continuous velocity: derivable in 1st order
- continuous acceleration: derivable in 2nd order

$$\begin{align}a_0&=\theta_0 \\ a_1&=0 \\ a_2&=\frac{3}{t^2_f}(\theta_f-\theta_0) \\ a_3&=-\frac{3}{t^3_f}(\theta_f-\theta_0) \end{align}$$

**cubic polynomial through intermediate points**


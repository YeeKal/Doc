---
title: throw objects
categories: motion planning
tags: planning
date: 2019_06_17
---

## Mathematical model

The parabolic trajectory:
        $$x=v_xt+x_0 \\
        y=-\frac{1}{2}gt^2+v_yt+y_0$$
when the flying object hit ground, let $y=0$:
        $$\text{flying time: }  t=\sqrt{\frac{2y_0}{g}+\frac{v_y^2}{g^2}}+\frac{v_y}{g}\\
        \text{flying distance: }    d=x_0+v_x \sqrt{\frac{2y_0}{g}+\frac{v_y^2}{g^2}}+\frac{v_xv_y}{g}       $$
assume $x_0=y_0=0$:
        $$y=-\frac{1}{2}\frac{g }{v_x^2}x^2+\frac{v_y}{v_x}x$$

Velocity in cartesian space transformed to joint space:
        $$\dot{q}=J^{-1}(q)v$$

Orientation constraint:
- perpendicular to the velocity vector
- follow the parabolic trajectory for a while to wait for gripper open competely

```
______97977754767676757755_______6278458_____________________________4237889________
______66868686849840327946_______7452874__________________________92764___23784__________
_____________5756546_____________6472657_________________________27387_____72383________
_____________7634566_____________5712638_______________________673788_______729345_____
_____________5643565_____________2647592______________________647267_________728399_____
_____________7645487_____________1703820_____________________3467287_________2786845_____               
_____________4863133_____________4628745_____________________6348178_________7248537_____
_____________4689461_____________6728975______________________893485_________893039____
_____________8745879_____________7198503_______________________787239_______374875_____
______56556789567893789378_______782345298457348602339___________83259_____95039______
______46387354561816181318_______203485028357834578001____________73859___86590______
______56867893758765987689_______672971857023574890348_______________6487238____________
// a joke test
```

## Accurate Object Throwing by an Industrial Robot Manipulator

- 2008
- throw objects at given targets
- on kuka

path planning pipeline:
```
|---------------|           |---------------------|             |---------------|
| acceleration  |   --->    | parabola following  |     --->    | deceleration  |        
|---------------|           |---------------------|             |---------------|
                                      ___
                                     /   \
                                    /     \
                                ___/       \___
```
In acceleration, the most suitable velocity vector $\dot{q}$ in joint space can be chosen due to the first weighting criterion(**??**):
        $$j_1=min(\dot{q}^T(\beta) W \dot{q}(\beta))$$
At the end of the path planning a second weighting criterion is applied(**??**):
        $$j_2=min(\begin{bmatrix}j_1 \\ e^{-n^2}\end{bmatrix}^T G \begin{bmatrix}j_1 \\ e^{-n^2}\end{bmatrix})$$

In the experiment the following time is 12 ms. 

## Throwing motion generation using nonlinear optimization on a 6-degree-of-freedom robot manipulator

- 2009
- trajectory generated with dynamic limitations on 6-dof rigid robot
- trajectory is generated **off-line** as cubic spline using general constrained nonlinear optimization
- trajectory tracking using a discrete-time constrained optimal control technique
- on 6dof self-designed robot

In introduction:
- before handle with lower dof robot arms(2 link or 3)

planning algorithm:
- given the release position and velocity
- use cubic polynomial to generate the acceleration and deceleration trajectory in joint sapce
        $$\text{acceleration: } Q_a(t)=a_at^3+b_at^2c_at+d_a \\
        \text{deceleration: } Q_b(t)=a_bt^3+b_bt^2c_bt+d_b  \\
        Q_a(t_r)=q_r=Q_b(t_r)   \\
        \dot Q_a(t_r)=\dot q_r=\dot Q_b(t_r)    \\
        \dot Q_a(0)=0=\dot Q_b(t_e)     \\
        \ddot Q_a(t_r)=0=\ddot Q_b(t_r)$$
- then define the object function to optimize


## Planning Longest Pitch Trajectories for Compliant Serial Manipulators

- 2016
- plan an optimal pitching trajectory for compliant serial manipulators
- on kuka
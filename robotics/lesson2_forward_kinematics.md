kinematics(运动学): 只讨论运动本身，而不涉及产生运动所需的力。

dynamics(动力学): 讨论力/力矩如何产生运动。

## link description

**lower pair**: the relative motion is characterized by two surfaces sliding over one another. A joint may have more than one degrees of freedom. We will consider only manipulators that have joints with a single degree of freedom, such as **revolute joints** and **prismatic joints**.

Link **$i$**, is defined by two parameters: **link length**, $a_{i}$  and  **link twist**, $\alpha_{i}$. The common joint $i$ between the neighboring links is defined by two parameters: **link offset**, $d_i$ and **joint angle**, $\theta_i$. The link offset is variable for prismatic joint, while the joint angle for revolute joint. Hence, any robot can be described kinematically by giving the values of for quantities for each link. In the usual case, there is one variable in these four parameters, and the orther three are fixed. The definition of mechanisms by means of these quantities is called the **Debavit Hartenberg notation**.

**Affixing frames** to links, $Z_i$ is coincident with the joint axis $i$, $X_i$ points along $a_i$ in the direction from joint $i$ to joint $i+1$. The origin is located where the $a_i$ perpendicular intersects the joint $i$ axis. Frame 0 is attached to the base of the robot and doesn't move. Usually, frame 0 coincides with frame 1 when the variable 1 is zero. Coincidering this convention, we will always have $a_0=0, \alpha_0=0$. For the end frame N, $d_n=0 \quad or \quad\theta_n =0$. (把连杆和节点看作一个组合，当下组合中连杆的参数和下一个组合中节点的参数确定下一个组合的坐标系。第0组合被视为基坐标，不会动，只有连杆没有节点，且两个连杆参数都设为0；最后一个组合附着于最后一个关节).

## link transformation

$$ \begin{align} ^{i-1}_iT&=R_x(\alpha_{i-1})D_x(a_{i-1})R_z(\theta_{i})D_z(d_{i})\\&=\begin{bmatrix} c\theta_i&-s\theta_i&0&a_{i-1}\\s\theta_i c\alpha_{i-1}&c\theta_i c\alpha_{i-1} &-s\alpha_{i-1}& -s\alpha_{i-1}d_i \\s\theta_i s\alpha_{i-1}&c\theta_i s\alpha_{i-1} &c\alpha_{i-1}& c\alpha_{i-1}d_i \\0&0&0&1  \end{bmatrix} \end{align} $$



## space

A set of n joint variables is often refered to as the $n\times1$ **joint vector**. The space of all such joint vectors is refered to as **joint space**. The 3D **operational space ** is called **Cartesian space** or **task-oriented space**. The joint variables is defined by the *actuator positions* with sensors, so some computations must be performed to realize the joint vector as a function of a set of actuator values, or actuator vector.

$$actuator space\Longleftrightarrow joint space\Longleftrightarrow Cartesian space $$ 

## frames with standard names

- B, the base frame=frame{0}
- W, the wrist frame,another name for frame{N}, affixed to the last link of the manipulator.
- T, the tool frame, is fixxed to the end of any tool the robot happens to be holding. The tool frame is always specified with respect to the wrist frame.
- S, the station frame, the universe frame.
- G, the goal frame, the location to which the robot is to move the tool.

**the tool **

$$^S_TT=^B_ST^{-1}\cdot^B_WT\cdot ^W_TT \\$$


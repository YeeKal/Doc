---
title: K-Order Markov Optimization
categories: motion planning
tags: komo;motion planning
date: 2023-03-29
---

## Ref

- [paper](https://arxiv.org/abs/1407.0414)
- [code](https://github.com/MarcToussaint/rai)
- [docu1](https://marctoussaint.github.io/robotics-course/simlab.html)
- [docu2-wiki](https://github.com/MarcToussaint/rai/wiki)
- [docu3 - optimization problem about features](https://www.user.tu-berlin.de/mtoussai/teaching/20-LabCourse/02-motion.pdf)

## KOMO implementation

<font color='Tomato'>Notation:</font>

$$\begin{array}{ll}
q \in \mathbb{R}^n & \text { vector of joint angles (robot configuration) } \\
\dot{q} \in \mathbb{R}^n & \text { vector of joint angular velocities } \\
\phi: q \mapsto y \in \mathbb{R}^d & \text { feature (or fwd kinematic ) } \\
& \text { e.g. position } \in \mathbb{R}^3 \text { or vector } \in \mathbb{R}^3 \\
J(q)=\frac{\partial \phi}{\partial q} \in \mathbb{R}^{d \times n} & \text { Jacobian } \\
\|v\|_W^2=v^{\top} W v & \text { squared norm of } v \text { w.r.t. metric } W
\end{array}$$

<font color='Tomato'>Inverse kinematics:</font>

$$y^* \mapsto q^*=\underset{q}{\operatorname{argmin}}\left\|\phi(q)-y^*\right\|_C^2+\left\|q-q_0\right\|_W^2$$

Solution with linearization at 

$$q_0: \quad q^*=q_0+J^{\sharp}\left(y^*-y_0\right) \\J^{\sharp}=W^{-1} J^{\top}\left(J W^{-1} J^{\top}+C^{-1}\right)^{-1}$$

<font color='Tomato'>Operational space control:</font>

$$\ddot{y}^* \mapsto u^*=\underset{u}{\operatorname{argmin}}\left\|\ddot{\phi}(q)-\ddot{y}^*\right\|_C^2+\|u\|_H^2$$

**<font color='Tomato'>It's all about features:</font>**

consider the IK problem:
$$
q^*=\underset{q}{\operatorname{argmin}}\left\|\phi(q)-y^*\right\|_C^2+\left\|q-q_0\right\|_W^2
$$
- $q_0$ is the current state
- We want to compute $q_1$, the next state
- Let $\Phi_1=\sqrt{C}\left(\phi(q)-y^*\right)$, and $\Phi_2=\sqrt{W}\left(q-q_0\right)$
- And let $\Phi=\left(\Phi_1 ; \Phi_2 ; \ldots\right)$, stacking all features in a single vector 

Then IK is a sum-of-squares problem
$$
q^*=\underset{q}{\operatorname{argmin}} \Phi^{\top} \Phi
$$

$\longrightarrow$ to design motion:
- think of all kinds of features you want to penalize,
- zero calibrate them (subtract the target),
- scale them (multiply with some pC),
- stack them into a big feature vector,
- call an efficient SOS optimization method

**<font color='Tomato'>Hard constraints: beyond just penalizing</font>**

$$\min _q \sum_{k \in S} \phi_k(q)^{\top} \phi_k(q) \quad \text { s.t. } \quad \underset{k \in I}{\forall} \phi_k(q) \leq 0, \underset{k \in E}{\forall} \phi_k(q)=0$$

- some features $\phi_k, k \in S$, are SOS
- some features $\phi_k, k \in I$, impose inequalities
- some features $\phi_k, k \in E$, impose equalities

$\longrightarrow$ to design motion
- define features as above
- but also specify the type of each feature: if sos, eq, or ineq

**<font color='Tomato'>k-order Features:</font>**

- In IK, define a feature $\Phi_2=\sqrt{W}(q_1-q_0)$ to penalize motion/velocity $\implies$ a feature over 2 configurations($q_0, q_1$)
- In Operational Space Control, we have to define a feature that depends on the acceleration $(q_1+q_{-1}-2q_0)/\tau^2 \implies$  a feature over 3 configurations $(q_{-1}, q_0, q_1)$
- In general we can have <font color='Tomato'>k-order features</font>, which depend on k − 1
consecutive configurations and typically compute finite difference velocities, accelerations, jerks, etc.

All the above generalizes to not only solve for the next configuration $q_1$, but also a whole sequence of future configurations $q_1, . ., q_T$.
$$
\min _{x_1, . ., x_n} \sum_{k \in S} \phi_k\left(x_{\pi_k}\right)^{\top} \phi_k\left(x_{\pi_k}\right) \quad \text { s.t. } \quad \underset{k \in I}{\forall} \phi_k\left(x_{\pi_k}\right) \leq 0, \underset{k \in E}{\forall} \phi_k\left(x_{\pi_k}\right)=0,
$$
- Each feature computes something for (at most $k-1$ ) consecutive configurations $\pi_k$
- Each feature $\phi_k$ penalizes some aspect of the path locally in time

**<font color='Tomato'>Predefined features in KOMO</font>**

- Symbols for pre-defined features
```yaml
position, positionDiff, positionRel,
quaternion, quaternionDiff, quaternionRel,
pose, poseDiff, poseRel, [avoid these]
vectorX, vectorXDiff, vectorXRel,
vectorY, vectorYDiff, vectorYRel,
vectorZ, vectorZDiff, vectorZRel,
scalarProductXX, scalarProductXY, scalarProductXZ, scalarProductYX, scalarProductYY,
scalarProductYZ, scalarProductZZ,
gazeAt, angularVel,
accumulatedCollisions, jointLimits, distance, oppose,
qItself,
aboveBox, insideBox,
standingAbove,
physics, contactConstraints, energy,
transAccelerations, transVelocities,
qQuaternionNorms,
```
- Full objective specification
```yaml
addObjective(times, featureSymbol, frameNames, objectiveType, scale, target, order)
(There are many more features defined in the code, but not interfaced with a symbol.)
```

## obstacle collision

```cpp
shared_ptr<ScalarFunction> rai::Shape::functional(bool worldCoordinates){
  rai::Transformation pose = 0;
  if(worldCoordinates) pose = frame.ensure_X();
  //create mesh for basic shapes
  switch(_type) {
    case rai::ST_none: HALT("shapes should have a type - somehow wrong initialization..."); break;
    case rai::ST_box:
      return make_shared<DistanceFunction_ssBox>(pose, size(0), size(1), size(2), 0.);
    case rai::ST_sphere:
      return make_shared<DistanceFunction_Sphere>(pose, radius());
    case rai::ST_cylinder:
      return make_shared<DistanceFunction_Cylinder>(pose, size(-2), size(-1));
    case rai::ST_capsule:
      return make_shared<DistanceFunction_Capsule>(pose, size(-2), size(-1));
    case rai::ST_ssBox: {
      return make_shared<DistanceFunction_ssBox>(pose, size(0), size(1), size(2), size(3));
    default:
      return shared_ptr<ScalarFunction>();
    }
  }
```

## ref

- Optimization-based: KOMO(K-Order Markov Optimization) (using RAI https://github.com/MarcToussaint/rai)
	- [doc](https://github.com/MarcToussaint/rai/wiki)
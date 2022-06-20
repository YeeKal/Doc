---
title: spiral based planner
categories: 
tags: 
date: 2022-05-31
---

## Trajectory Planning for Autonomous Ground Vehicles Driving in Structured Environments

2017

piecewise spiral curve

1. satisfy accuracy
2. reduce computational complexity

**direct solution**

symmetric configuration

$$\begin{aligned}
&l=\frac{d}{D(\alpha)} \\
&\kappa(s)=\frac{6 \alpha D(\alpha)^{3}}{d^{3}}\left(\frac{d^{2}}{4 D(\alpha)^{2}}-s^{2}\right) \\
&D(\alpha)=2 \int_{0}^{1 / 2} \cos \left(\alpha\left(3 / 2-2 s^{2}\right) s\right) d s
\end{aligned}$$

**direct solution**

symmetric configuration

$$\begin{aligned}
&l=\frac{d}{D(\alpha)} \\
&\kappa(s)=\frac{6 \alpha D(\alpha)^{3}}{d^{3}}\left(\frac{d^{2}}{4 D(\alpha)^{2}}-s^{2}\right) \\
&D(\alpha)=2 \int_{0}^{1 / 2} \cos \left(\alpha\left(3 / 2-2 s^{2}\right) s\right) d s
\end{aligned}$$

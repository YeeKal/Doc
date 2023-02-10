---
title: 贝塞尔曲线
categories: 
tags: 
date: 2022-06-16
---


- [generate Bézier curves using continuity conditions C2 and C1](https://www.jointjs.com/blog/how-to-create-nice-looking-curves-in-svg-with-fixed-tangents)
- [Smooth Bézier Spline Through Prescribed Points](https://www.particleincell.com/2012/bezier-splines/)

## generate Bézier curves using continuity conditions C2 and C1

只有两个点,考虑方向

Catmull-Rom splines: pass through all control points

- [Catmull-Rom splines](https://lucidar.me/en/mathematics/catmull-rom-splines/)

长度: 根据三次多项式积分得到曲线长度
## collision

interact for line to curve:

distance for point to curve:

极值点： 通过极值点构造bounding box， 缩小碰撞检测范围


## numerical solution

- [spiral-curves](https://www.slideshare.net/haroldtaylor1113/spiral-curves)



## g1 spiral

- [G1fitting blog](https://onlinelibrary.wiley.com/doi/abs/10.1002/mma.3114)
- [G1fitting](https://github.com/ebertolazzi/G1fitting)

 - Spiral Curves for Highway Alignment
- [Spiral curves ](http://what-when-how.com/the-3-d-global-spatial-data-model/spiral-curves-geometrical-models-for-spatial-data-computations-the-3-d-global-spatial-data-model/)
- [](https://www.youtube.com/watch?v=CCpi0eNks94&ab_channel=DanielFindley)
- [construction-surveying-curves](https://mypdh.engineer/courses/construction-surveying-curves/)

- [spiral-curves](https://mypdh.engineer/lessons/spiral-curves/)

## 优化


- [萧潇子：Apollo ReferenceLine Smooth--Polynomial Spiral平滑原理](https://zhuanlan.zhihu.com/p/347373426)
- [spiral_reference_line_smoother](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/reference_line/spiral_reference_line_smoother.h)


## ref

- blog
    - [A Primer on Bézier Curves](https://pomax.github.io/bezierinfo/#curvature)
    - [CAGD/Bézier Curves](https://en.wikiversity.org/wiki/CAGD/B%C3%A9zier_Curves)
- code
    - [path smoothing](https://github.com/MithunNallana/path-smoothing)
    - [Bezier-Curve](https://github.com/reiniscimurs/Bezier-Curve)
- paper
    - [Continuous Curvature Path Generation Based on B¶ezier Curves for Autonomous Vehicles]()
    - [Bezier曲线的拼接及其连续性]()
    - [An Analytical Continuous-Curvature Path-Smoothing Algorithm]()
    - [On the generation of spiral-like paths within planar shapes](https://www.sciencedirect.com/science/article/pii/S2288430017301562)
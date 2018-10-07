---
title: constraint
categories: ompl
tags: planning
date: 2018-07-22
---
## ProjectEvaluator

[ProjectorEvaluator reference](http://ompl.kavrakilab.org/classompl_1_1base_1_1ProjectionEvaluator.html#details)

Abstract definition for a class computing projections to $R^n$.

```c++
auto constraint_space=std::make_shared<ompl::base::ProjectedStateSpace>(space,constraint);
//注册自定义投影类
constraint_space->registerProjection("sphere", std::make_shared<SphereProjection>(constraint_space));
```
---
title: interpolation in local planning
categories: ompl
tags: planning
date: 2018-10-21
---

ompl中对普通空间中的规划结果的采样,会根据两个状态之间的`validSegment`来确定两点之间的插值个数。`si_->getMotionStates`会调用`stateSpace_->interpolate`进行简单线性插值。

```c++
 void ompl::geometric::PathGeometric::interpolate()
 {
     std::vector<base::State *> newStates;
     const int segments = states_.size() - 1;
 
     for (int i = 0; i < segments; ++i)
     {
         base::State *s1 = states_[i];
         base::State *s2 = states_[i + 1];
 
         newStates.push_back(s1);
         unsigned int n = si_->getStateSpace()->validSegmentCount(s1, s2);
 
         std::vector<base::State *> block;
         si_->getMotionStates(s1, s2, block, n - 1, false, true);
         newStates.insert(newStates.end(), block.begin(), block.end());
     }
     newStates.push_back(states_[segments]);
     states_.swap(newStates);
 }
```

约束空间中的插值先检测是否存在合法的测地路径，之后进行插值。检测后会把所有的路径点保存在一个向量里，之后插值函数根据保存有测地路径的向量和两点之间的距离进行插值。

```c++
void ConstrainedStateSpace::interpolate(const State *from, const State *to, const double t,   State *state) const
 {
     // Get the list of intermediate states along the manifold.
     std::vector<State *> geodesic;
     // Default to returning `from' if traversal fails.
     auto temp = from;
     //check whether a valid path exists
     if (discreteGeodesic(from, to, true, &geodesic))
         temp = geodesicInterpolate(geodesic, t);
     copyState(state, temp);
     for (auto s : geodesic)
         freeState(s);
 }
```

[ProjectedStateSpace](http://ompl.kavrakilab.org/ProjectedStateSpace_8cpp_source.html)实现了`discreteGeodesic()`和三个采样函数。


distance and interpolation in se3 spaec.

约束空间插值没有考虑函数参数中的个数。

```c++
//class ConstrainedSpaceInformation
unsigned int getMotionStates(const State *s1, const State *s2, std::vector<State *> &states,
                                          unsigned int count, bool endpoints, bool alloc) const override
             {
                 bool success = stateSpace_->as<ConstrainedStateSpace>()->discreteGeodesic(s1, s2, true, &states);
 
                 if (endpoints)
                 {
                     if (!success && states.size() == 0)
                         states.push_back(cloneState(s1));
 
                     if (success)
                         states.push_back(cloneState(s2));
                 }
 
                 return states.size();
             }
```
---
title: planner in ompl
categories: ompl
tags: planning
date: 2019-03-08
---

1. [rrt.cpp in github](https://github.com/ompl/ompl/blob/master/src/ompl/geometric/planners/rrt/src/RRT.cpp)
2. [rrt.h in github](https://github.com/ompl/ompl/blob/master/src/ompl/geometric/planners/rrt/RRT.h)

```c++
si_->getStateSpace()->interpolate();
```
调用空间的插值函数。约束空间插值先离散投影（耗时），再进行插值。

```c++
si_->checkMotion(const State *s1, const State *s2);

//调用成员变量,可以设置

motionValidator_->checkMotion(s1,s2);
//set default 
void ompl::base::SpaceInformation::setDefaultMotionValidator()
{
    if (dynamic_cast<ReedsSheppStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<ReedsSheppMotionValidator>(this);
    else if (dynamic_cast<DubinsStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<DubinsMotionValidator>(this);
    else if (dynamic_cast<ConstrainedStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<ConstrainedMotionValidator>(this);
    else
        motionValidator_ = std::make_shared<DiscreteMotionValidator>(this);
}

bool DiscreteMotionValidator::checkMotion(const State *s1, const State *s2) const{
    
    int nd = stateSpace_->validSegmentCount(s1, s2);
    interpolate();
    si_->isValid();
}
```

```c++
si_->isValid();

return stateValidityChecker_->isValid(state);
//isValid()只判断点是否又碰撞，在约束空间中并不进行是否在流形上的判断，因为采样器已经保证每一个点必定在流形上。
```
```c++
//in constrainedStateSpace
virtual unsigned int validSegmentCount(const State* s1, const State* s2) const override
            {
                return distance(s1, s2) * (1. / delta_) * lambda_;
            }
//in common StateSpace
unsigned int validSegmentCount(const State *state1, const State *state2) const
 {
     return longestValidSegmentCountFactor_ * (unsigned int)ceil(distance(state1, state2) / longestValidSegment_);
 }
```
```c++
si_->getMotionStates();
//in constrainedSpaceInformation, 'count' is not used
//the states num is decided by discreteGeodesic(s1, s2, true, &states)
```
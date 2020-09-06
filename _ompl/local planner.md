SpaceInformation中调用MotionValidator进行checkMotion(),检测两点间是否存在合法路径。
```c++
//SpaceInformation 构造器中调用
void ompl::base::SpaceInformation::setDefaultMotionValidator()
{
    if (dynamic_cast<ReedsSheppStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<ReedsSheppMotionValidator>(this);
    else if (dynamic_cast<DubinsStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<DubinsMotionValidator>(this);
    else if (dynamic_cast<ConstrainedStateSpace *>(stateSpace_.get()))
        motionValidator_ = std::make_shared<ConstrainedMotionValidator>(this);
    else
        //the default motion validator
        motionValidator_ = std::make_shared<DiscreteMotionValidator>(this);
}
```
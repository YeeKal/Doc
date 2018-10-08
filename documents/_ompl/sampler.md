---
title: sampler in ompl
categories: ompl
tags: planning
date: 2018-07-25
---

```c++
//rrt.cpp
sampler_ = si_->allocStateSampler();//generate a new sampler
sampler_->sampleUniform(rstate);//sample a rand state
si_->checkMotion(nmotion->state, dstate);//check a valid path exists or not

```

## StateSampler

- virtual sampleUniform(state): 随机采样，不对状态合法性进行判断

##validStateSampler

- virtual sample(State *state): 合法性采样

继承者： ConstrainedValidStateSampler

- bool sample(State *state)；//先通过随机采样，再进行合法性判断
```c++
do
    sampler_->sampleUniformNear(state, near, distance);
while (!(valid = si_->isValid(state) && constraint_->isSatisfied(state)) && ++tries < attempts_);
return valid;
```

## SpaceInformation

- isvalid(State* state): 调用`ValidityChecker`的`isvalid`函数，碰撞检测判断
- checkMotion: 插值对两点之间路径进行检测
- allocStateSampler: 调用`StateSpace`的方法

## ProjectedStateSpace

有限制的采样将调用`ProjectedStateSampler`
```c++
 StateSamplerPtr allocStateSampler() const override
{
    return std::make_shared<ProjectedStateSampler>(this, space_->allocStateSampler());
}
```
类`ProjectedStateSampler`的采样会调用`constraint`的`project`方法进行投影：

```c++
 void ompl::base::ProjectedStateSampler::sampleUniform(State *state)
 {
     WrapperStateSampler::sampleUniform(state);
     constraint_->project(state);
     space_->enforceBounds(state);
 }
 ```
## Constraint

- `function(const Eigen::Ref< const Eigen::VectorXd > &x, Eigen::Ref< Eigen::VectorXd > out)`: define functions
- `jacobian (const Eigen::Ref< const Eigen::VectorXd > &x, Eigen::Ref< Eigen::MatrixXd > out) const
`: Compute the Jacobian of the constraint function at x, the default jacobian will be implemented if the user dont override 
- `isSatisfied`: check whether a state state satisfies the constraints
- `virtual bool project (Eigen::Ref< Eigen::VectorXd > x) const`:Project a state x given the constraints. If a valid projection cannot be found, this method will return false. 

[project() definition](http://ompl.kavrakilab.org/Constraint_8cpp_source.html)

```c++
bool ompl::base::Constraint::project(Eigen::Ref<Eigen::VectorXd> x) const
 {
     // Newton's method
     unsigned int iter = 0;
     double norm = 0;
     Eigen::VectorXd f(getCoDimension());
     Eigen::MatrixXd j(getCoDimension(), n_);
 
     const double squaredTolerance = tolerance_ * tolerance_;
 
     function(x, f);
     while ((norm = f.squaredNorm()) > squaredTolerance && iter++ < maxIterations_)
     {
         jacobian(x, j);
         x -= j.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(f);
         function(x, f);
     }
 
     return norm < squaredTolerance;
 }
 ```

 对jacobian的理解

 **projection on manifolds**

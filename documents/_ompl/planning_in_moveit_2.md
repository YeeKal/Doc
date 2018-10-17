---
title: planning in moveit - constraint sampling 
categories: ompl
tags: planning
date: 2018-10-08
---

**load robot model**

```c++
//in motion_planning_api_tutorial.launch
<include file="$(find pr2_moveit_config)/launch/planning_context.launch">
    <arg name="load_robot_description" value="true"/>
  </include>

//in planning_context.launch
//the robot_description was launched
<!-- Load universal robot description format (URDF) -->
  <param if="$(arg load_robot_description)" name="$(arg robot_description)" command="$(find xacro)/xacro --inorder '$(find pr2_description)/robots/pr2_no_kinect.urdf.xacro'"/>

//then in your code
robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
robot_model::RobotModelPtr robot_model = robot_model_loader.getModel();
planning_scene::PlanningScenePtr planning_scene(new planning_scene::PlanningScene(robot_model));
robot_state::RobotState& robot_state = planning_scene->getCurrentStateNonConst();
//or
robot_state::RobotStatePtr robot_state(new robot_state::RobotState(robot_model));
```

moveit_msgs::DisplayTrajectory

```
DisplayTrajectory->
    RobotTrajectory[] ->trajectory_msgs/JointTrajectory
    ->trajectory_msgs::JointTrajectoryPoint
    ->double[] positions

```

**PlanningScene**

- [PlanningScene.h](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/planning_scene/include/moveit/planning_scene/planning_scene.h)
- [PlanningScene.cpp](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/planning_scene/src/planning_scene.cpp)

self collision checking and obstacle collision checking.

In `move_group`, `planning_scene_interface` is used.

- [PlanningSceneInterface](https://github.com/ros-planning/moveit/blob/54d516a4e6fdc5db9dfcba4da9e916d807ea312a/moveit_ros/planning_interface/planning_scene_interface/src/planning_scene_interface.cpp)
- [PlanningSceneInterface.cpp](https://github.com/ros-planning/moveit/blob/54d516a4e6fdc5db9dfcba4da9e916d807ea312a/moveit_ros/planning_interface/planning_scene_interface/src/planning_scene_interface.cpp)

```c++
private:
    ros::ServiceClient planning_scene_service_;
    ros::ServiceClient apply_planning_scene_service_;
    ros::Publisher planning_scene_diff_publisher_;
void addCollisionObjects(){
    ......//构造完planning_scene,然后发布出去
    moveit_msgs::PlanningScene planning_scene;
    planning_scene_diff_publisher_.publish(planning_scene);
}
```

obstacle通过PlanningSceneInterface添加，发布出去后被PlanningSceneMonitor接收，并更新planning_scene。

## constraints in PlanningContext

**constructs constraints by user**

- [kinematic_constraints cpp](https://github.com/kunal15595/ros/tree/master/moveit/src/moveit_core/kinematic_constraints/src)
- [kinematic_constraints head](https://github.com/kunal15595/ros/tree/master/moveit/src/moveit_core/kinematic_constraints/include/moveit/kinematic_constraints)


MotionPLanRequest通过`kinematic_constraints::constructGoalConstraints()`来构造约束方式。`move_group_interface`中`constructMotionPlanRequest()`也是通过不同的约束标记来构造`MotionPlanRequest res`.

```c++
//MotionPlanRequest definition
WorkspaceParameters workspace_parameters
RobotState start_state
Constraints[] goal_constraints  //
Constraints path_constraints	//
TrajectoryConstraints trajectory_constraints //
string planner_id
string group_name
int32 num_planning_attempts
float64 allowed_planning_time
float64 max_velocity_scaling_factor
float64 max_acceleration_scaling_factor
//Constraints
string name
JointConstraint[] joint_constraints  //[low,high]
PositionConstraint[] position_constraints
OrientationConstraint[] orientation_constraints //[orientation tolerance]
VisibilityConstraint[] visibility_constraints
```

res中一个Constraints: path_constraints,另一个Constraints[]: goal_constraints是数组，可以直接进行构造。path_constraints中加入orientationConstraint, goal_constraints中加入目标点。

**constructs constraints by planner**

- [constraint_samplers cpp](https://github.com/ros-planning/moveit/tree/kinetic-devel/moveit_core/constraint_samplers/src)
- [constraint_sampler head](https://github.com/ros-planning/moveit/tree/kinetic-devel/moveit_core/constraint_samplers/include/moveit/constraint_samplers)

```c++
/*in omplinterface::getPlanningContext()*/
configureContext(context);//构造constraints_approximation,但是需要用户自定义，默认没有

/*in planning context_manager:getPLanningContext()*/
context.reset(new ModelBasedPlanningContext(config.name, context_spec));//会处理path_constraints.
//store path_constraints
context->setPathConstraints(req.path_constraints, &error_code);
//store goal_constraints
//ompl_simple_setup_->setGoal(goal);
context->setGoalConstraints(req.goal_constraints, req.path_constraints, &error_code);

context->configure();
```
```c++
configure(...){
    ....
    //state_space_: reference planning_context_manager.cpp in line 224
    ompl::base::ScopedState<> ompl_start_state(spec_.state_space_);
    spec_.state_space_->copyToOMPLState(ompl_start_state.get(), getCompleteInitialRobotState());
    ompl_simple_setup_->setStartState(ompl_start_state);//set start state
    ompl_simple_setup_->setStateValidityChecker(ob::StateValidityCheckerPtr(new StateValidityChecker(this)));//set default validity checker
    ....
}
```
```c++
//in constructor function
ompl_simple_setup_->getStateSpace()->setStateSamplerAllocator(boost::bind(&ModelBasedPlanningContext::allocPathConstrainedSampler, this, _1));
ompl::base::StateSamplerPtr allocPathConstrainedSampler(){
    if(path_constraints_){
        ....
        constraint_samplers::ConstraintSamplerPtr cs;
        if (spec_.constraint_sampler_manager_)
            cs = spec_.constraint_sampler_manager_->selectSampler(getPlanningScene(), getGroupName(), path_constraints_->getAllConstraints());
        if (cs)
        {
            logInform("%s: Allocating specialized state sampler for state space", name_.c_str());
            return ob::StateSamplerPtr(new ConstrainedSampler(this, cs));
        }
    }
    logDebug("%s: Allocating default state sampler for state space", name_.c_str());
    return ss->allocDefaultStateSampler();
}
typedef std::function< StateSamplerPtr(const StateSpace *)> 	StateSamplerAllocator;
```

cs 是constraint_samplers::ConstraintSampler的一个子类，定义在ompl_interface/detail中，返回的是ob::StateSampler类型，即constraintSampler作为ob:StateSampler的一个属性而存在. 

多约束情况下，函数返回UnionConstraintSampler，是ConstraintSampler众多子类的集合。

```c++
bool UnionConstraintSampler::sample(...){
    ...
    for (std::size_t i = 1; i < samplers_.size(); ++i)
    {
        state.updateLinkTransforms();
        if (!samplers_[i]->sample(state, state, max_attempts))
        return false;
    }
}
```


**sampling** 


```c++
void ompl_interface::ConstrainedSampler::sampleUniform(ob::State *state)
{
    //调用3次
    if (!sampleC(state) && !sampleC(state) && !sampleC(state))
        default_->sampleUniform(state);
}

bool ompl_interface::ConstrainedSampler::sampleC(ob::State *state)
{
    //调用moveit定义的constraintSampler::sample()
    if (constraint_sampler_->sample(work_state_, planning_context_->getCompleteInitialRobotState(), planning_context_->getMaximumStateSamplingAttempts()))
    {
        planning_context_->getOMPLStateSpace()->copyToOMPLState(state, work_state_);
        if (space_->satisfiesBounds(state))
        {
        ++constrained_success_;
        return true;
        }
    }
    ++constrained_failure_;
    return false;
}
```

在[default_constraint_sampler.h](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/constraint_samplers/include/moveit/constraint_samplers/default_constraint_samplers.h)中，默认构建了两个子类：JointConstraintSampler,IKConstraintSampler来分别处理joint_constraints和position_constraints/orientation_constraints.

```c++
bool IKConstraintSampler::sample(robot_state::RobotState& state, const robot_state::RobotState& reference_state,
                                 unsigned int max_attempts)
{
  return sampleHelper(state, reference_state, max_attempts, false);
}

bool IKConstraintSampler::sampleHelper(robot_state::RobotState& state, const robot_state::RobotState& reference_state,
                                       unsigned int max_attempts, bool project)
{
    ....
    for (unsigned int a = 0; a < max_attempts; ++a)
    {
        // sample a point in the constraint region
        Eigen::Vector3d point;
        Eigen::Quaterniond quat;
        samplePose(point, quat, reference_state, max_attempts)

        //求逆解
        if (callIK(ik_query, adapted_ik_validity_callback, ik_timeout_, state, project && a == 0))
            return true;
    }
    ....
}

bool samplePose(){
    if (sampling_pose_.position_constraint_){
    }
    if (sampling_pose_.orientation_constraint_){
        // sample a rotation matrix within the allowed bounds
        //
    }
}
```

**inverse kinematics**

- [kinematics_base.cpp](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/kinematics_base/src/kinematics_base.cpp)
- [kinematics_base.h](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/kinematics_base/include/moveit/kinematics_base/kinematics_base.h)
- [moveit kinematics](https://github.com/ros-planning/moveit/tree/kinetic-devel/moveit_kinematics)

moveit kinemtics继承kinematics_base, 是逆解的具体执行者。

```c++
//in callIk()
/*
geometry_msgs::Pose& ik_query;
std::vector<double> ik_sol;
std::vector<double> seed;
*/
kinematics::KinematicsBaseConstPtr kb_; 
kb_->searchPositionIK(ik_query, seed, timeout, ik_sol, adapted_ik_validity_callback, error)

//in robotState
setFromIk(){
    ....
    const kinematics::KinematicsBaseConstPtr& solver = jmg->getSolverInstance();
    solver->searchPositionIK(ik_queries, seed, timeout, consistency_limits, ik_sol, ik_callback_fn, error, options,this);
    ....
}
```

```c++
typedef boost::function< bool(RobotState *robot_state, const JointModelGroup *joint_group, const double *joint_group_variable_values)> 	GroupStateValidityCallbackFn;
```







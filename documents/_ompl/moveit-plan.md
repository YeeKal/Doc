---
layout: post
title: moveitPlan
categories: ompl
tags: planning
description: note 1 for cs229:Machine Learning in Coursera
---
## moveit 规划源码解析

- `MoveGroupInterface`类构建`move_group`
- `Plan` 结构体实例化`my_plan`
- `move_group.plan(my_plan)`执行规划,结果保存在`my_plan`里面

源码地址：

- [move_group_interface.h](http://docs.ros.org/kinetic/api/moveit_ros_planning_interface/html/move__group__interface_8h_source.html)
- [move_group_interface.cpp](http://docs.ros.org/kinetic/api/moveit_ros_planning_interface/html/move__group__interface_8cpp_source.html)

**struct Plan**

```c++
//definition in `move_group_interface.h`
struct Plan
{
		moveit_msgs::RobotState start_state_;
		moveit_msgs::RobotTrajectory trajectory_;
		double planning_time_;
};
```

**MoveGroupInterface::plan(Plan *plan)**

```c++
//调用了impl_的同名函数
//MoveGroupInterfaceImpl* impl_;
MoveGroupInterface::plan(Plan& plan)
{
		return impl_->plan(plan);
}
```

**MoveGroupInterfaceImpl::plan(Plan \*plan)**

```c++
//definition in `move_group_interface.cpp`
	MoveItErrorCode plan(Plan& plan)
	{
		if (!move_action_client_)
		{
			return MoveItErrorCode(moveit_msgs::MoveItErrorCodes::FAILURE);
		}
		if (!move_action_client_->isServerConnected())
		{
			return MoveItErrorCode(moveit_msgs::MoveItErrorCodes::FAILURE);
		}

		moveit_msgs::MoveGroupGoal goal;
		constructGoal(goal);
		goal.planning_options.plan_only = true;
		goal.planning_options.look_around = false;
		goal.planning_options.replan = false;
		goal.planning_options.planning_scene_diff.is_diff = true;
		goal.planning_options.planning_scene_diff.robot_state.is_diff = true;

		move_action_client_->sendGoal(goal);//move_action_client_
		if (!move_action_client_->waitForResult())
		{
			ROS_INFO_STREAM_NAMED("move_group_interface", "MoveGroup action returned early");
		}
		if (move_action_client_->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		{
			plan.trajectory_ = move_action_client_->getResult()->planned_trajectory;
			plan.start_state_ = move_action_client_->getResult()->trajectory_start;
			plan.planning_time_ = move_action_client_->getResult()->planning_time;
			return MoveItErrorCode(move_action_client_->getResult()->error_code);
		}
		else
		{
			ROS_WARN_STREAM_NAMED("move_group_interface", "Fail: " << move_action_client_->getState().toString() << ": "
																														 << move_action_client_->getState().getText());
			return MoveItErrorCode(move_action_client_->getResult()->error_code);
		}
	}

```

**move_action_client_**

```c++
//definition in `move_group_interface.cpp`
move_action_client_.reset(
				new actionlib::SimpleActionClient<moveit_msgs::MoveGroupAction>(node_handle_, move_group::MOVE_ACTION, false));
```

**SimpleActionClient**

## planning interface

- [default capabilities](https://github.com/kunal15595/ros/tree/master/moveit/src/moveit_ros/move_group/src/default_capabilities)
- [move_action_capability.cpp](https://github.com/kunal15595/ros/blob/master/moveit/src/moveit_ros/move_group/src/default_capabilities/move_action_capability.cpp)
- [planning_exeuction.cpp](https://github.com/kunal15595/ros/blob/master/moveit/src/moveit_ros/planning/plan_execution/src/plan_execution.cpp)

```c++
MoveGroupMoveAction::executeMoveCallback_PlanAndExecute(){
	context_->plan_execution_->planAndExecute(plan, planning_scene_diff, opt);
}

struct MoveGroupContext{
	plan_execution::PlanExecutionPtr plan_execution_;
}
//move_group_client最终转化为request
context_->planning_pipeline_->generatePlan(the_scene, goal->request, res);
```
- [planning pipeline head](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_ros/planning/planning_pipeline/include/moveit/planning_pipeline/planning_pipeline.h)
- [planning pipeline cpp](https://github.com/kunal15595/ros/blob/master/moveit/src/moveit_ros/planning/planning_pipeline/src/planning_pipeline.cpp)

- [planning_interface_head](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_core/planning_interface/include/moveit/planning_interface/planning_interface.h)

```c++
planning_interface::PlannerManagerPtr planner_instance_;
bool PlanningPipeline::generatePlan(...)const
{
	...
	planning_interface::PlanningContextPtr context = planner_instance_->getPlanningContext(planning_scene, req, res.error_code_);
	solved = context ? context->solve(res) : false;
	...
}
```
## ompl interface

[ompl_interface_cpp](https://github.com/ros-planning/moveit_planners/tree/kinetic-devel/ompl/ompl_interface/src)
[ompl_interface_head](https://github.com/ros-planning/moveit_planners/tree/kinetic-devel/ompl/ompl_interface/include/moveit/ompl_interface)



```c++

OMPLPlannerManager : public planning_interface::PlannerManager{
	getPlanningContext(const  planning_scene,const  req,error_code) const
  {
    return ompl_interface_->getPlanningContext(planning_scene, req, error_code);
  }
};

OMPLInterface::getPlanningContext(){
	ModelBasedPlanningContextPtr ctx = context_manager_.getPlanningContext(planning_scene, req, error_code);
}

PlanningContextManager::getPlanningContext(){
	//初始化context
}

```

```c++
context->solve(res);
bool ompl_interface::ModelBasedPlanningContext::solve(planning_interface::MotionPlanResponse& res){
	solve(res.time,res.attempts);
	res.trajectory_=...
}
bool ompl_interface::ModelBasedPlanningContext::solve(double timeout, unsigned int count)
{
	preSolve();
	ompl_simple_setup_->solve();//ompl_parallel_plan_->solve();
	postSolve();
}

```
**ModelBasedPlanningContext**

```c++
class ModelBasedPlanningContext : public planning_interface::PlanningContext{
	//构造函数中将spec中ompl_simple_setup指针赋值给ompl_simple_setup
	ModelBasedPlanningContext(const std::string &name, const ModelBasedPlanningContextSpecification &spec) ;
	solve(double timeout,unsigned int count){
	//SimpleSetup 将调用自身属性base::PlannerPtr planner_的solve()函数。
	ompl_simple_setup_->solve(ob::PlannerTerminationCondiction ptc);
}
	ompl::geometry::SimpleSetupPtr ompl_simple_setup_;
};
//PlanningContext定义在planning_interface.h里面
//该类中有设置goal/statevaliditychecker/projectevaluator

struct ModelBasedPlanningContextSpecification{
	...
	ModelBasedStateSpacePtr state_space_;
	og::SimpleSetupPtr ompl_simple_setup_;
	...

};

class ModelBasedStateSpace : public ompl::base::StateSpace{

};
```

- [ompl interface 使用](https://github.com/davetcoleman/moveit_hrp2/blob/master/hrp2jsknt_moveit_demos/src/hrp2_demos.cpp)

**construct trajectory**
```c++
void ModelBasedPlanningContext::convertPath(const ompl::geometric::PathGeometric& pg,
		robot_trajectory::RobotTrajectory& traj) const
{
  robot_state::RobotState ks = complete_initial_robot_state_;
  for (std::size_t i = 0; i < pg.getStateCount(); ++i)
  {
    spec_.state_space_->copyToRobotState(ks, pg.getState(i));
    traj.addSuffixWayPoint(ks, 0.0);
  }
}

void ModelBasedStateSpace::copyToRobotState(robot_state::RobotState& rstate,
	const ompl::base::State* state) const
{
  rstate.setJointGroupPositions(spec_.joint_model_group_, state->as<StateType>()->values);
  rstate.update();
}
```
**construct constraints**

- [kinematic_constraints utils.cpp](https://github.com/kunal15595/ros/blob/master/moveit/src/moveit_core/kinematic_constraints/src/utils.cpp)
- [moveit msgs](https://github.com/ros-planning/moveit_msgs/tree/kinetic-devel/msg)

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



## model based state space

[model-based-state-space.cpp](https://github.com/ros-planning/moveit/blob/kinetic-devel/moveit_planners/ompl/ompl_interface/src/parameterization/model_based_state_space.cpp)
[revolute_joint_model.h](http://docs.ros.org/kinetic/api/moveit_core/html/revolute__joint__model_8h_source.html)
[joint_model.h](http://docs.ros.org/kinetic/api/moveit_core/html/joint__model_8h_source.html)

```c++
struct ModelBasedStateSpaceSpecification
{
	robot_model::RobotModelConstPtr robot_model_;
	const robot_model::JointModelGroup* joint_model_group_;
	robot_model::JointBoundsVector joint_bounds_;//关节极限值
};
class ModelBasedStateSpace : public ompl::base::StateSpace
{
	protected:
		ModelBasedStateSpaceSpecification spec_;
}
class StateType : public ompl::base::State{
		double *values;
};

//以joint_model_group作为关节空间的值
double ompl_interface::ModelBasedStateSpace::distance(const ompl::base::State* state1,
												const ompl::base::State* state2) const
{
	if (distance_function_)
		return distance_function_(state1, state2);
	else
		return spec_.joint_model_group_->distance(state1->as<StateType>()->values, state2->as<StateType>()->values);
}

bool ompl_interface::ModelBasedStateSpace::equalStates(const ompl::base::State* state1,
																											 const ompl::base::State* state2) const
{
	for (unsigned int i = 0; i < variable_count_; ++i)
		if (fabs(state1->as<StateType>()->values[i] - state2->as<StateType>()->values[i]) >
				std::numeric_limits<double>::epsilon())
			return false;
	return true;
}

void ompl_interface::ModelBasedStateSpace::enforceBounds(ompl::base::State* state) const
{
	spec_.joint_model_group_->enforcePositionBounds(state->as<StateType>()->values, spec_.joint_bounds_);
}

bool ompl_interface::ModelBasedStateSpace::satisfiesBounds(const ompl::base::State* state) const
{
	return spec_.joint_model_group_->satisfiesPositionBounds(state->as<StateType>()->values, spec_.joint_bounds_,
																													 std::numeric_limits<double>::epsilon());
}

class JointModelGroup{
	std::vector< const JointModel * > 	active_joint_model_vector_;
	JointModelGroup(...const std::vector<const JointModel*>& unsorted_group_joints..){
		joint_model_vector_ = unsorted_group_joints;
		std::sort(joint_model_vector_.begin(), joint_model_vector_.end(), OrderJointsByIndex());
		....
		active_joint_model_vector_.push_back(joint_model_vector_[i]);
		....
	}
};

class RevoluteJointModel : public JointModel{
	bool RevoluteJointModel::enforcePositionBounds(double* values, const Bounds& bounds) const{
		//与SO2StateSpace::enforceBounds(State *state)函数类似定义
	}
}
```



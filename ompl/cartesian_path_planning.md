---
title: cartesian path planning
categories: ompl
tags: moveit
date: 2019-07-05
---

[move group interface](http://docs.ros.org/kinetic/api/moveit_ros_planning_interface/html/classmoveit_1_1planning__interface_1_1MoveGroupInterface.html)

move_group_interface中的地卡尔路径规划器调用impl中的规划函数，impl中通过调用'move_group/MoveGroupExecuteTrajectoryAction'来获得路径。
```c++
/*in move_group_interface*/

double 	computeCartesianPath (const std::vector< geometry_msgs::Pose > &waypoints, 
                double eef_step, double jump_threshold, moveit_msgs::RobotTrajectory &trajectory,
                 bool avoid_collisions=true, moveit_msgs::MoveItErrorCodes *error_code=NULL);
//with path constraints
double computeCartesianPath (const std::vector< geometry_msgs::Pose > &waypoints,
                 double eef_step, double jump_threshold, moveit_msgs::RobotTrajectory &trajectory, 
                 const moveit_msgs::Constraints &path_constraints, bool avoid_collisions=true, 
                 moveit_msgs::MoveItErrorCodes *error_code=NULL);

/**************************************************************
@waypoints:         the points in cartrsian space
@eef_step:          step in cartesian space
@jump_threshold:    max step in joint space
@trajectory:        result trajectory
@avoid_collisions:  whether or not check collision
@path_constraints:  path constraints

@return:            [0.0,1.0], the success fraction
**************************************************************/

{
    ...
    return impl_->computeCartesianPath(waypoints, eef_step, jump_threshold, 
                                        trajectory, path_constraints,
                                        avoid_collisions, *error_code);
    ...
}


/*MoveGroupInterfaceImpl*/
MoveGroupInterfaceImpl::computeCartesianPath(){
    ...
    cartesian_path_service_.call(req, res);
    ...

}
```

[cartesian_path_service_capability.cpp](https://github.com/ros-planning/moveit/blob/master/moveit_ros/move_group/src/default_capabilities/cartesian_path_service_capability.cpp)
```c++

bool MoveGroupCartesianPathService::computeService
            (moveit_msgs::GetCartesianPath::Request& req,
            moveit_msgs::GetCartesianPath::Response& res){
    ...
    res.fraction = moveit::core::CartesianInterpolator::computeCartesianPath
    (
        &start_state, jmg, traj, start_state.getLinkModel(link_name), 
        waypoints, global_frame,moveit::core::MaxEEFStep(req.max_step),
        moveit::core::JumpThreshold(req.jump_threshold), constraint_fn
    );
    robot_state::robotStateToRobotStateMsg(start_state, res.start_state);
    ...
    trajectory_processing::IterativeParabolicTimeParameterization time_param;
    time_param.computeTimeStamps(rt, 1.0);
}
/***************************************************************
1. construct constraint function
2. check the reference frame
3. call CartesianInterpolator::computeCartesianPath() to calculate
4. retrive the cartesian path
5. compute time parameters
***************************************************************/
```

[cartesian_interpolator.cpp](https://github.com/ros-planning/moveit/blob/ff50476c4070eb86d0a70aa39281d5805db13fa5/moveit_core/robot_state/src/cartesian_interpolator.cpp)

```c++
/*compute cartesian path*/
double computeCartesianPath();
/*
1. construct joint jump vector ----> consistency_limits
2. interpolation in rotation and translation respectively
3. call robot_state->setFromIK() to do inverse kinematics
4. check joint space jump
*/

/*check joint space jump*/
double checkJointSpaceJump(const JointModelGroup* group, 
                            std::vector<std::shared_ptr<RobotState>>& traj,
                            const JumpThreshold& jump_threshold){
    if (jump_threshold.factor > 0.0)
        percentage_solved *= checkRelativeJointSpaceJump(group, traj, jump_threshold.factor);

    if (jump_threshold.revolute > 0.0 || jump_threshold.prismatic > 0.0)
        percentage_solved *= checkAbsoluteJointSpaceJump(group, traj, jump_threshold.revolute, jump_threshold.prismatic);
}

double checkRelativeJointSpaceJump();
double checkAbsoluteJointSpaceJump();

```
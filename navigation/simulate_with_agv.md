---
title: simulate with agv
categories: navigation
tags: navigation
date: 2019-10-10
---

open in terminal:

> roslaunch rrbot_gazebo rrbot_world.launch  
> roslaunch agv_nav gmapping_demo.launch
> rosrun rviz rviz -d `rospack find rbx1_nav`/nav.rviz
> rosrun teleop_twist_keyboard teleop_twist_keyboard.py 

- taleop_twist_keyboard:键盘控制


## costmap_2d:

ref: https://blog.csdn.net/Neo11111/article/details/104798065

- param
    - global_frame
    - robot_base_frame
- topic
    - /map: 全局地图，初始化的全局静态地图
    - /scan： 实时更新的传感器数据，来更新局部地图

根据global_frame和robot_base_frame的tf坐标转换更新机器人当前的位置

```c++

footprint_spec_
resolution: 在离散地图和世界真实长度之间做转换

```

## global_planner:

- pub: /plan

```c++
// 主要接口
class BaseGlobalPlanner:
    void initialize(std::string name, costmap_2d::Costmap2DROS* costmap_ros)
    bool makePlan(const geometry_msgs::PoseStamped& start, 
          const geometry_msgs::PoseStamped& goal, std::vector<geometry_msgs::PoseStamped>& plan)
```

## local_planner:
    - pub: 
        - global_plan: 当前在跟踪的全局路径的一部分
        - local_plan: 局部规划结果
        - cost_cloud: 代价地图
    in: /odom, 提供机器人当前速度
    param: 
    odomCallback(const nav_msgs::Odometry::ConstPtr& msg):
        里程计回调函数，存储速度

```c++
class BaseLocalPlanner:
    void initialize(std::string name, tf2_ros::Buffer* tf, costmap_2d::Costmap2DROS* costmap_ros)

    // 设置局部规划器跟踪的全局规划的一部分
    bool setPlan(const std::vector<geometry_msgs::PoseStamped>& plan);

    // 局部规划器调用，输出下一时刻速度命令
    bool computeVelocityCommands(geometry_msgs::Twist& cmd_vel);
```

## move_base

[ref](https://haoqchen.site/2018/11/27/move-base-code/)

```c++
move_base:
    MoveBase():
        planner_: global planner
        tc_: local planner

        // 规划回调
        as_ = new MoveBaseActionServer(ros::NodeHandle(), "move_base", boost::bind(&MoveBase::executeCb, this, _1), false);

        //set up the planner's thread
        planner_thread_ = new boost::thread(boost::bind(&MoveBase::planThread, this));

        // plan topic
        goal_sub_ = simple_nh.subscribe<geometry_msgs::PoseStamped>("goal", 1, boost::bind(&MoveBase::goalCB, this, _1));
        // convert topic to call goal action
        action_goal_pub_ = action_nh.advertise<move_base_msgs::MoveBaseActionGoal>("goal", 1);

        // make plan service    
        make_plan_srv_ = private_nh.advertiseService("make_plan", &MoveBase::planService, this);
    
    planThread():
        全局规划线程，通过runPlanner_控制是否运行
        makePlan()
    makePlan():
        global plan
    
    // global plan service callback
    planService(nav_msgs::GetPlan::Request &req, nav_msgs::GetPlan::Response &resp):
        planner_->makePlan(start, p, global_plan)

    executeCb()：
        // get goal pose and publish
        geometry_msgs::PoseStamped goal = goalToGlobalFrame(move_base_goal->target_pose);
        current_goal_pub_.publish(goal);

        runPlanner_ = true;
        // plan
        bool done = executeCycle(goal, global_plan);

    executeCycle(global_plan):
        // global plan
        if(new_global_plan_){
            tc_->setPlan(*controller_plan_)
        }else{

        }

        // local plan
        tc_->computeVelocityCommands(cmd_vel)
        vel_pub_.publish(cmd_vel)
    
    goalCB(goal):
        action_goal_pub_.publish(action_goal);
```

## eband local planner

```cpp


class EBandPlanner:

    convertPlanToBand(global_plan_, elastic_band_);
        // 根据cost计算与最近障碍物的距离
        calcObstacleKinematicDistance();
        refineBand(elastic_band_)
            removeAndFill() // remove redundant Bubbles and fill gabs recursively
    optimizeBand()
        1. 重新计算bubble半径
        2. refineBand()
        3. optimize iterative
            3.1 modifyBandArtificialForce(tmp_band)
                calcInternalForces()
                calcExternalForces()
                suppressTangentialForces()
            3.2 refineBand(tmp_band)
    
    removeAndFill(band,start_iter, end_iter)
        // 根据bubble半径计算首尾bubble的重合度有没有大于阈值（0.66）
        overlap = checkOverlap(start, end)  
        if  overlap:
            band.remove(start+1, end);
        else 中间有其他bubble:
            // 取中间，分治递归调用 removeAndFill()
            tmp_iter = start_iter + mid_int;
            removeAndFill(band, start_iter, tmp_iter)
            removeAndFill(band, tmp_iter, end_iter)

            // 检测中点是否是多余的
        
        case3: fill gap
    
    calcInternalForces(bubble_num, band, cur_bubble, force)
```






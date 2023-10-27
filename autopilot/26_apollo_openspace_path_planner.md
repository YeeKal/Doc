---
title: apollo 中的 openspace path planner
categories: autopilot
tags: 
date: 2021-11-15
---

采用分步计算：

1. 通过hybrid a*计算出初始轨迹
2. 进行轨迹平滑

```cpp
//  distance_approach_problem_wrapper.cc
DistancePlan():
    //  1st step: call palnner
    !hybridA_ptr->Plan(sx, sy, sphi, ex, ey, ephi, XYbounds_, obstacles_ptr->GetObstacleVec(), &hybrid_astar_result))

    // 2nd step: trajectory optimization
    DistanceSmoothing(planner_open_space_config_, *obstacles_ptr,
                             piece_wise_sx, piece_wise_sy, piece_wise_sphi,
                             piece_wise_ex, piece_wise_ey, piece_wise_ephi,
                             XYbounds_, &partition_trajectories[i],
                             &state_result_ds_vec[i], &control_result_ds_vec[i],
                             &time_result_ds_vec[i], &dual_l_result_ds_vec[i],
                             &dual_n_result_ds_vec[i], dual_tmp, ipopt_tmp)

DistanceSmoothing():
    DistanceApproachProblem* distance_approach_ptr =
      new DistanceApproachProblem(planner_open_space_config);
    bool status = distance_approach_ptr->Solve();   // 根据配置文件选择不同的优化算法
    
```

优化方法继承关系：

[apollo 优化方法源码](https://github.com/ApolloAuto/apollo/tree/master/modules/planning/open_space/trajectory_smoother)

![apollo_openspace.png](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/notes_img_backup/autopilot/imgs/apollo_openspace.png)

**DistanceApproachInterface**

```cpp
/* interface function */

eval_f();                           // objective function
eval_grad_f();                      // gradient of objective
eval_g();                           // constraint residuals
eval_jac_g();                       // jacobian
eval_h();                           // hessian of lagrangian
```


**DistanceApproachIPOPTInterface**

利用Voronoi Diagram计算到障碍物的距离

```cpp



/**
eval_f() -> eval_obj()                           // objective function
eval_grad_f() -> gradient()                     // gradient of objective
eval_g() -> eval_constraints()                           // constraint residuals
eval_jac_g();                       // jacobian
eval_h();                           // hessian of lagrangian
**/


eval_obj(n, x, obj_value):
    // 1. objective to minimize state diff to warm up
    // 2. minimize u square
    // 3. minimize input change rate for last value
    // 4. minimize input change rate
    // 5. minimize total time
eval_constraints():


```

**DistanceApproachIPOPTFixedDualInterface**

```cpp
eval_obj(n, x, obj_value):
    // same to upper
```


## ref: 

- [openspace planner](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/open_space/tools/distance_approach_problem_wrapper.cc)
- [apollo 优化方法集合](https://github.com/ApolloAuto/apollo/tree/master/modules/planning/open_space/trajectory_smoother)
- [apollo 平滑优化解析](https://www.cxyzjd.com/article/linxigjs/104040053)

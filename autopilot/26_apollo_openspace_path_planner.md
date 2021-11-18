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
    //  one step: call palnner
    !hybridA_ptr->Plan(sx, sy, sphi, ex, ey, ephi, XYbounds_, obstacles_ptr->GetObstacleVec(), &hybrid_astar_result))

    // trajectory optimization
    DistanceSmoothing(planner_open_space_config_, *obstacles_ptr,
                             piece_wise_sx, piece_wise_sy, piece_wise_sphi,
                             piece_wise_ex, piece_wise_ey, piece_wise_ephi,
                             XYbounds_, &partition_trajectories[i],
                             &state_result_ds_vec[i], &control_result_ds_vec[i],
                             &time_result_ds_vec[i], &dual_l_result_ds_vec[i],
                             &dual_n_result_ds_vec[i], dual_tmp, ipopt_tmp)

DistanceSmoothing():
    
```


ref: 

- [openspace planner](https://github.com/ApolloAuto/apollo/blob/master/modules/planning/open_space/tools/distance_approach_problem_wrapper.cc)
- [apollo 平滑优化解析](https://www.cxyzjd.com/article/linxigjs/104040053)

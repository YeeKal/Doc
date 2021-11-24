---
title: 自动驾驶中的运动规划 
categories: autopilot
tags: planning
date: 2021-08-11
---

## hybrid a-star


$$f(x) = |x|, \quad \frac{df}{dx} = \frac{x}{|x|},\quad x \neq 0$$

```python
# A*
'''
g: 路径代价,哪个点值得搜索 找到的路径最小
h(g+h): 哪个点最先被搜索 最快地找到路径

在进行代价比较时只使用了g_cost，这是因为规划的最终目的就是使得这个cost最小。

而在取下一个待访问节点时比较的是 g+h，这是为了通过诱导cost更快地找到路径
'''
for next in graph.neighbors(current):
      new_cost = cost_so_far[current] + graph.cost(current, next)
      if next not in cost_so_far or new_cost < cost_so_far[next]:
         cost_so_far[next] = new_cost
         priority = new_cost + heuristic(goal, next)
         frontier.put(next, priority)
         came_from[next] = current

# hrbrid A*
g_cost: 通过离散化转向和reeds_shepp路径计算cost, 这里取邻近点时只能预定义几个
h_cost: 从目标点开始，计算到当前点的dijkstra路径代价

？ 那使用rrt也能使用这种算法

 frontier: g_cost + h_cost
            # node self only save g_cost
         # g_cost: 哪个点值得搜索 找到的路径最小
        # g+h: 哪个点最先被搜索 最快地找到路径
```

## ref

- project:
    - [a-star implemented in ros](https://github.com/karlkurzer/path_planner)
    - [Dynamic Voronoi](http://www2.informatik.uni-freiburg.de/~lau/dynamicvoronoi/)
    - [Dubins-Curves](https://github.com/AndrewWalker/Dubins-Curves/)
    - [explain code](https://github.com/Habrador/Self-driving-vehicle)
- blog
    - [zhihu](https://zhuanlan.zhihu.com/p/161660932)
    - [blog](https://blog.habrador.com/2015/11/explaining-hybrid-star-pathfinding.html)



- paper
    - [2020-Speed Planning for Autonomous Driving in Dynamic Urban Driving Scenarios](https://ieeexplore.ieee.org/document/9235659)
    - [2016-Path Planning in Unstructured Environments: A Real-time Hybrid A* Implementation for Fast and Deterministic Path Generation for the KTH Research Concept Vehicle]()
    - [hybrid a* short version: 2008 - Practical Search Techniques in Path Planning for Autonomous Driving]()
    - [hybrid a* long version: 2010 - Path Planning for Autonomous Vehicles in Unknown Semi-structured Environments]()


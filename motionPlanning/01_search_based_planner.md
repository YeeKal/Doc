


**planning algorithms**

- combinatorial planning
    - cell decomposition
- sampling-based planning
    - BFS: breadth first search, visit all nodes but not give the path
    - DFS: depth first search, visit all nodes but not give the path
    - Dijkstra's algorithm: adding cost(start,current)
    - greedy best first search: one closest to the goal will be explored first
    - [A*](https://www.redblobgames.com/pathfinding/a-star/introduction.html):  adding obstacle cost and distance cost together
    - ant colony algorithm(蚁群算法)
    - PRM(probability road maps)
    - RRT(randomly exploring randomized trees)
- differential constraints

```python
'''
这一类算法途中保留了三种点：
- 已访问的点 (closed)
- 边界点，已加入待访问队列 (open)
- 未访问
'''
# Dijkstra: 以障碍代价构造优先队列，优先访问代价较少的
frontier = PriorityQueue()
frontier.put(start, 0)
came_from = dict()
cost_so_far = dict()
came_from[start] = None
cost_so_far[start] = 0

while not frontier.empty():
   current = frontier.get()

   if current == goal:
      break
   
   for next in graph.neighbors(current):
      new_cost = cost_so_far[current] + graph.cost(current, next)
      if next not in cost_so_far or new_cost < cost_so_far[next]:
         cost_so_far[next] = new_cost
         priority = new_cost
         frontier.put(next, priority)
         came_from[next] = current


# A*： 增加当前到目标点的诱导方向
frontier = PriorityQueue()
frontier.put(start, 0)
came_from = dict()
cost_so_far = dict()
came_from[start] = None
cost_so_far[start] = 0

while not frontier.empty():
   current = frontier.get()

   if current == goal:
      break
   
   for next in graph.neighbors(current):
      new_cost = cost_so_far[current] + graph.cost(current, next)
      if next not in cost_so_far or new_cost < cost_so_far[next]:
         cost_so_far[next] = new_cost
         priority = new_cost + heuristic(goal, next)
         frontier.put(next, priority)
         came_from[next] = current
```

**运动规划**

1. Principles of Robot Motion Theory, Algorithms, and Implementations
2. Planning Algorithms

**基础的运动学和动力学**

1. Introduction to Robotics Mechanics and Control 3rd edition
2. Robotics_ Modelling, Planning and Control-Springer-Verlag London (2009)
3. Springer Handbook of Robotics-2nd

**research**

- [ijrr](http://journals.sagepub.com/home/ijr)
- [ras](http://www.ieee-ras.org/) 
- [icra2018](https://icra2018.org/program/)







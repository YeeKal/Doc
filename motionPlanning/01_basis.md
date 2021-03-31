
**optimization**

- probabilistically complete: finds a feasible path with probability approaching one as the number of iterations approaches infinity.
- asymptotic optimality: the path is shotest with enough time

**geometrical representation**

- configuration space: representation of robot manipulation states

**collision checking**

- FCL: Flexible Collision Library
- PCD: Proximity Collision Detection

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







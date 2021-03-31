The *RRT* series algorithms are similar to most incremental sampling-based planning algorithms. The body of the rrt algorithms is:
```matlab
%body of rrt algorithm
V.Initial(q_init); E.Initial();i=0;
while i<N do
    G.Update(V,E);
    q_rand=Sample(G);
    (V,E)=Extend(G,q_rand);

%functions demonstration
Steer(q_near, q_rand)   朝着q_rand的方向在步长范围内产生一个新的最近的点
Nearest(G, q_rand)      最近的一个点
Near(G,q_new)           某一距离范围内的一些点
Parent(G,q_neig)        树结构中点的父节点
```
##RRT

 rapidly exploring random tree

```matlab
%Extend(G,q_rand) in rrt
q_near=Nearest(G, q_rand);
q_new=Steer(q_near, q_rand);
if ObstacleFree(q_near,q_new) then
    V.Update(q_new);
    E.Update(q_near,q_rand);
return V,E
```

​	应用到机器人路径规划，当新节点距离目标在一定范围内结束。对环境类型不敏感，当C空间中包含大量障碍物或狭窄通道时，算法收敛速度慢，效率会降低。该算法概率完备，但是随着迭代次数增加，路径并不会变得更优。

- 随机采样。当然不是完全随机，根据目标点的位置定义heuristic function

```matlab
%基于概率朝目标点移动
if rand > 0  %generate a random number
  sample=rand(1,2) .* size(map); % random sample
else
  sample=goal; % sample taken as goal to bias tree generation to goal
end
```
- 最近的点。一般是以欧式距离进行计算，但也会根据具体的构型进行加权平均计算距离。*K-d树*。

  
## bidirectional rrt

```matlab
map1(init),map2(init)
While i<N do
    q_rand=Sample();
    q_nearst=Nearest(q_rand,map1);
    q_new;
    if ObstacleFree(q_new,q_near) 
        map1.Update(q_new);

        % set q_new as the rand q for map2
        q2_nearst=Nearest(q_new,map2);
        q2_new;
        if ObstacleFree(q2_new,q2_nearst)
            map2.Update(); 

            While Not ObstacleFree(q_new,q_new2) do
                q2_nearst=q2_new;
                q2_new;
                if ObstacleFree(q2_new,q2_nearst)
                    map2.Update();
                else
                    break;
        %判断上面循环的退出是否由于两个图已经连接
        if  ObstacleFree(q_new,q_new2) 
            Path found;
            break;
    if |map2|<|map1|
        swap(map1,map2)
```

## rrg

```matlab
%Extend(G,q_rand) in rrg
q_near=Nearest(G, q_rand);
q_new=Steer(q_near, q_rand);
if ObstacleFree(q_near,q_new) then
    V.Update(q_new);
    E.Update(q_near,q_rand);
    q_neighbors=Near(G,q_new);
    for q_neig in q_neighbors :
        if ObstacleFree(q_neig,q_new) then
            E.Update(q_neig,q_rand);
return V,E
```
In this algorithm, there are more connections and it will finally construct a graph not a tree.

## rrt*

rrt\* derives from rrg, which is slightly modified to maintain a tree structure while preserving the asymptotic optimality properties as well. rrt\* algorithm converges towards an optimal solution as the iteration numbers increases.
```matlab
%Extend(G,q_rand) in rrt*
q_near=Nearest(G, q_rand);
q_new=Steer(q_near, q_rand);
if ObstacleFree(q_near,q_new) then
    V.Update(q_new);
    q_min=q_near;
    q_neighbors=Near(G,q_new);

    %the edge with minimum cost
    for q_neig in q_neighbors :
        if ObstacleFree(q_neig,q_new) then
            cost_new=Cost(q_neig)=Cost(Line(q_neig,q_new));
            if cost_new<Cost(q_new) then
                q_min=q_neig;
    E.Update(q_min,q_new);
    for q_neig in (q_neighbors \ q_min) :
        if ObstacleFree(q_neig,q_new) and Cost(q_neig)>Cost(q_new)+Cost(Line(q_neig,q_new))  then:
            q_parent=Parent(G,q_neig);
            E.Delete(q_parent,q_neig);
            E.Update(q_neig,q_new);
return V,E
```

**reference**

1. [The RRT page](http://msl.cs.uiuc.edu/rrt/index.html)
2. [blog-rahul kala](http://rkala.in/codes.php)
3. [RRT路径规划算法](http://www.cnblogs.com/21207-iHome/p/7210543.html)
4. [Karaman, Sertac, and Emilio Frazzoli. "Sampling-based algorithms for optimal motion planning." The international journal of robotics research 30.7 (2011): 846-894.](http://journals.sagepub.com/doi/abs/10.1177/0278364911406761)

  ​
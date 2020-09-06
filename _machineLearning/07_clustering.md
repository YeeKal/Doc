---
 title: 07_clustering
 categories: ml
 tags: ml
 date: 2018-06-03
---

Training datas without labels are just a set of points.

##clustering

- partitional algorithms
    - k-means clustering
    - mixture-model based clustering
- hierarchical algorithms
    - bottom-up agglomerative
    - top-down divisive
- density-based algorithms
    - DBSCAN

##hierarchical clustering

Build a tree-based hierarchical cludtering of a set of documents

##partioning algorithms

construct apartion of n objects into a set of k clusters

**k-means algorithm**

Input:

- K(number of clusters)
- training set $\{x^{(1) \cdots x^{(m)}}\}$

Optimization objective:

$$J=\frac{1}{m}\sum_{i=1}^{m}||x^{(i)}-\mu_c^{(i)}||$$

Algorithm:

```c++
randomly initialize K cluster centroids
while true{
    for i=1 to m
        c:=index of cluster centroid closest to x_i
    for k=1 to K
        u:=means of points assigned to cluster k
}
//if no points assigned to cluster, then decrease k of re-initialize the centroids
```

In random initialization, randomly pick K training examples and set the centroids equal to these examples. Maybe the initialization could have many loops and the one with smallest J will be choosed.

In choosing the value of K, the elbow method suggests the K will be the corner of the J-k curve.









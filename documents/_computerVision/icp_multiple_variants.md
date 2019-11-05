---
title: icp-multiple variants
categories: cv
tags: icp
date: 2019-11-03
---

- 加快搜索效率
    - K-D tree [Zhang, 1994]
    - Voronoi graph
- 距离度量方式
    - 点到点
    - PLICP: 点到线 [2008]
    - 点到面
    - GICP： 面到面, 泛化的ICP
- 封闭解
    - SVD
    - Unit Quaternions: 单位四元数
    - The ICP error function minimization via orthonormal matrices ?
    - Dual Quaterions
- 数值解
    - Levenberg-Marquardt algorithm:
        > Jerbić, B., et al. (2015). "Robot Assisted 3D Point Cloud Object 
        Registration." 
    - 点到面 线性最小二乘法
        > Low, K.-L. (2004). "Linear Least-Squares Optimization for Point-to-Plane ICP Surface Registration."
- optimization
    - 观测误差
    - 部分重叠
    - 离群点(outlies)
    - 不满足一一对应
    - IDC / Trimmed ICP / MBICP / EM-ICP / NICP / GO-ICP /eICP

## CSM: Canonical Scan Matcher

[CSM](https://censi.science/software/csm/): a pure C implementation of a very fast variation of ICP using a point-to-line metric optimized for range-finder scan matching



## Super4PCS

- [Super4PCS Library: Not maitained ](http://nmellado.github.io/Super4PCS/)
- [OpenGR: replace the initial Super4PCS](https://storm-irit.github.io/OpenGR/index.html)
- [CSDN-点云配准算法之super-4pcs](https://blog.csdn.net/peach_blossom/article/details/80955343)
- [4PCS阅读笔记](https://blog.csdn.net/Ha_ku/article/details/79480613)

```python
# install
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make install

# install folder
-- Installing: /usr/local/scripts/run-example.sh
-- Installing: /usr/local/scripts/run-example.bat
-- Installing: /usr/local/assets
-- Installing: /usr/local/assets/hippo2.obj
-- Installing: /usr/local/assets/hippo1.obj
-- Installing: /usr/local/doc
-- Installing: /usr/local/doc/Doxyfile
- Installing: /usr/local/lib/cmake/Super4PCSConfig.cmake
-- Installing: /usr/local/lib/cmake/Super4PCSConfigVersion.cmake
-- Installing: /usr/local/lib/libsuper4pcs_io.a
-- Installing: /usr/local/lib/libsuper4pcs_algo.a
-- Installing: /usr/local/bin/Super4PCS
```

## Generalized ICP

- [Generalized icp](http://www.robots.ox.ac.uk/~avsegal/generalized_icp.html)

## ref

- [点云匹配和ICP算法概述](https://www.cnblogs.com/yhlx125/p/4955337.html)


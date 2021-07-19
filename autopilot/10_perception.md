---
title: 感知
categories: CV
tags: autopilot
date: 2021-06-14
---

大感知：定位/（小）感知/预测
小感知：检测，追踪

- 任务
    - 2D检测
    - 3D检测
    - 深度估计：MVDepthNet,Monodepth
    - 融合
- 硬件
    - 单目
    - 双目(立体相机)
    - 雷达


## 融合

前融合： 融合数据，再对数据进行估计
后融合：先对单个传感器进行识别，在融合识别的结果

## 三维重建

1. 场景
- 特征匹配
- 稀疏重建：SFM
- 稠密重建：MVS(Multiple View Stereo),多视图立体几何，在相机位姿已知的前提下，逐像素的计算图像中每一个像素点对应的三维点
    - 基于体素：vocel based
    - 基于点云扩散：feature point growing based
    - 基于深度图融合:depth-map merging based
        - TSDF
2. 方法
    - Atlas

## 3D检测

- input: 3D场景数据(RGB/depth/radar images)
- output: 定位/形状/语义(3D bbx)

历史：
1. 模板：需要提供模板，不能呢个泛化
    - generalized hough voting(2010)
    - descriptor -> matching -> ICP(2012)
2. clustering-based
    - object discovery in 3D scenes via Shape Analysis(2013)
3. sliding shape based
    - sliding shapes for 3D object detection in depth images(2014)
4. deep learning
    - image-driven
        - monocular or Stereo based
        - rgb-d data based: Frustum pointnets





ref:

- [CCCV2017讲习班笔记-基于图像的大规模场景三维重建](https://www.leiphone.com/category/yanxishe/9dxX6g30dlEoqvPZ.html)


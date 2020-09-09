---
title: ch4 hsv segmentation
categories: cv
tags: cv
date: 2019-09-10
---

## hsv颜色系统

HSV是一种在人们生活中甚至更常用的颜色系统，在电视遥控器上、在画画的调色板中、在你用爱某艺视频调整亮度时都很常见，因为它更符合人们描述颜色的方式——是什么颜色、颜色有多深、颜色有多亮。

H——Hue即色相，就是我们平时所说的红、绿，如果你分的更细的话可能还会有洋红、草绿等等；在HSV模型中，用度数来描述色相，其中红色对应0度，绿色对应120度，蓝色对应240度.

S——Saturation即饱和度，色彩的深浅度(0-100%) ，对于一种颜色比如红色，我们可以用浅红——大红——深红——红得发紫等等语言来描述它（请原谅一个纯理科生的匮乏的颜色系统），对应在画水彩的时候即一种颜料加上不同分量的水形成不同的饱和度。

V——Value即色调，纯度，色彩的亮度(0-100%) ，这个在调整屏幕亮度的时候比较常见


PS中hsv范围： H[0-360],S[0-1],V[0-1] 
opencv中hsv范围： H[0-180],S[0-255],V[0-255] 

## cv::inRange()

```c++
//Checks if array elements lie between the elements of two other arrays
/*
one channel: dst(I) = lowerb(I)0 ≤ src(I)0 < upperb(I)0
three channels: dst(I) = lowerb(I)0 ≤ src(I)0 < upperb(I)0 ∧ lowerb(I)1 ≤ src(I)1 < upperb(I)1 ∧lowerb(I)2 ≤ src(I)2 < upperb(I)2
*/
void inRange(InputArray src, InputArray lowerb, InputArray upperb, OutputArray dst);

```

## ref
[CSDN-利用函数inRange进行颜色分割（针对HSV颜色空间）](https://blog.csdn.net/zhangping1987/article/details/74449630)
[CSDN-HSV颜色空间超极详解&inRange函数用法及实战](https://blog.csdn.net/coldwindha/article/details/82080176)
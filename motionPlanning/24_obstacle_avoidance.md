---
title: obstacle avoidance
categories: motion planning
tags: optimal control 
date: 2021-10-29
---

两个box 碰撞检测

分两种情况: 有一个点在另一个内部/重叠但是没有点在内部

![box collision](pics/box_collision.jpg)

第一种情况 三角形面积大于原始正方形;第二种情况在连续动态的环境里不会发生，如果发生必定已经发生了第一种情况。

$$S_{\Delta P A B}+S_{\Delta P B C}+S_{\Delta P C D}+S_{\Delta P D A}>S_{\square A B C D}$$
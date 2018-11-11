---
title: suspension model
categories: engineer
tags: test
description: suspension model test
date: 2017-12-10
---
## passive suspension model

$z_b$ :body

$z_w$: tyre

$z_g$: road input

$$m_b\ddot{z_b}=-K_s(z_b-z_w)-Cs(\dot{z_b}-\dot{z_w}) \\ m_w\ddot{z_w}=-K_t(z_w-z_g)+K_s(z_b-z_w)+Cs(\dot{z_b}-\dot{z_w}) \\$$

Then:

$$\ddot{z_b}=\frac{-K_s}{m_b}z_b+\frac{K_s}{m_b}z_w+\frac{-C_s}{m_b}\dot{z_b}+\frac{C_s}{m_b}\dot{z_w} \\ $$

$$\ddot{z_w}=\frac{K_s}{m_w}z_b+\frac{-K_s-K_t}{m_w}z_w+\frac{C_s}{m_w}\dot{z_b}+\frac{-C_s}{m_w}\dot{z_w}+\frac{K_t}{m_w}z_g \\ $$

The state space；

$$\begin{bmatrix} \dot{z_b}\\\dot{z_w}\\\ddot{z_b}\\\ddot{z_w} \end{bmatrix}=\begin{bmatrix} 0&0&1&0\\0&0&0&1\\\frac{-K_s}{m_b}&\frac{K_s}{m_b}&\frac{-C_s}{m_b}&\frac{C_s}{m_b}\\\frac{K_s}{m_w}&\frac{-K_s-K_t}{m_w}&\frac{C_s}{m_w}&\frac{-C_s}{m_w} \end{bmatrix} \cdot \begin{bmatrix} z_b\\z_w\\\dot{z_b}\\\dot{z_w} \end{bmatrix} +\begin{bmatrix} 0\\0\\0\\\frac{K_t}{m_w} \end{bmatrix} z_g\\$$

$$\begin{bmatrix} {z_b}-{z_w}\\{z_w}-{z_g} \\ \ddot{z_b} \end{bmatrix}=\begin{bmatrix} 1&-1&0&0\\0&1&0&0\\\frac{-K_s}{m_b}&\frac{K_s}{m_b}&\frac{-C_s}{m_b}&\frac{C_s}{m_b}\ \end{bmatrix} \cdot \begin{bmatrix} z_b\\z_w\\\dot{z_b}\\\dot{z_w} \end{bmatrix} +\begin{bmatrix} 0\\-1\\0 \end{bmatrix} z_g\\$$

The desirable output variables: $\ddot{z_b}$: body acceleration; $z_b-z_w$: suspension work space; $z_w-z_g$: dynamic tire displacement.

##  active suspension model

$$m_b\ddot{z_b}=-K_s(z_b-z_w)+F_U \\ m_w\ddot{z_w}=-K_t(z_w-z_g)+K_s(z_b-z_w)-F_U \\$$

Then,

$$\ddot{z_b}=\frac{-K_s}{m_b}z_b+\frac{K_s}{m_b}z_w+\frac{F_U}{m_b}  \\\ddot{z_w}=\frac{K_s}{m_w}z_b+\frac{-K_s-K_t}{m_w}z_w+\frac{K_t}{m_w}z_g-\frac{F_U}{m_w} \\ $$

the state space:

$$\begin{bmatrix} \dot{z_b}\\\dot{z_w}\\\ddot{z_b}\\\ddot{z_w} \end{bmatrix}=\begin{bmatrix} 0&0&1&0\\0&0&0&1\\\frac{-K_s}{m_b}&\frac{K_s}{m_b}&0&0\\\frac{K_s}{m_w}&\frac{-K_s-K_t}{m_w}&0&0 \end{bmatrix} \cdot \begin{bmatrix} z_b\\z_w\\\dot{z_b}\\\dot{z_w} \end{bmatrix} +\begin{bmatrix} 0&0\\0&0\\0&\frac{1}{m_b}\\\frac{K_t}{m_w}&\frac{-1}{m_w} \end{bmatrix} \begin{bmatrix}z_g\\F_U \end{bmatrix}\\$$

$$\begin{bmatrix} {z_b}-{z_w}\\{z_w}-{z_g} \\ \ddot{z_b} \end{bmatrix}=\begin{bmatrix} 1&-1&0&0\\0&1&0&0\\\frac{-K_s}{m_b}&\frac{K_s}{m_b}&0&0 \end{bmatrix} \cdot \begin{bmatrix} z_b\\z_w\\\dot{z_b}\\\dot{z_w} \end{bmatrix} +\begin{bmatrix} 0&0\\-1&0\\0&\frac{1}{m_b} \end{bmatrix} \begin{bmatrix}z_g\\F_U \end{bmatrix} \\$$

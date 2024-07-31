---
title: request
categories: web
tags: web
date: 2024-03-08
---

ajax   同域  异步

axios

- XMLHttpRequest
- fetch 
- axios

## 使用 async/await 取代 .then() 

.then 是 Promise 的一种语法，用于处理异步操作的结果。当一个 Promise 完成（或拒绝）时，你可以通过 .then 方法链式地添加回调函数来处理结果。这种方式被称为基于回调的异步编程

async/await 使得异步回调更加直观和清晰

## XMLHttpRequest

原生XHR

## ajax

对XMLHttpRequest的封装，可不不刷新页面的情况下，与服务器交换数据

## axios

基于 Promise 对ajax的进一步封装

浏览器端发起XMLHttpRequests请求
node端发起http请求

fetch 是 JavaScript 原生库，浏览器都支持，无需安装直接使用；axios 不是原生库，需要安装才能使用；
fetch 只能在浏览器环境中运行；axios 既可以在浏览器、也可以在node.js 环境中运行。
---
title: vue 开发教程
categories: 
tags: 
date: 2023-10-09
---

- vuepress: 基于vue的博客框架
- element plus: 恶了么 开源vue组件库

nuxt+ vue+ vercel 

- 前端框架
    - [nuxt]()
    - [next.js]()
    - [vite]()
- 后端
    - node.js
    - python-django
- 组件
    - antdesign
    - daisyui
    - shadcn/ui

## unite with Django

from [connecting-django-and-vue](https://www.webucator.com/article/connecting-django-and-vue/):

- 模板嵌套：vue的基类模板嵌套到django的模板中，把vue的输出路径重定向到django的模板路径
- 路由
- 前端数据传输到后段： ajax请求
- 后段数据传输到前端： json格式
- 数据传输： axio请求

## 模板语法

```html
v-bind:title  -> :title
v-on:click    -> @click

<!-- dynamic attribute -->
<a v-bind:[attributeName]="url"> ... </a>
```


**<font color='Tomato'>setup</font>**

暴露数据或者变量或者函数给模板

使用'<script setup>'简化'setup return'的写法

## 组件通信

- 父传子：props， 
- 子传父：emit， ref
- 兄弟组件：eventBus; provide/inject


## ref

- [vue examples](https://vuejs.org/examples/#hello-world)
- [vue pages](https://vuejs.org/guide/quick-start.html)
- [codementor practice](https://www.codementor.io/projects/vue)
- [深入理解Vue.js实战](https://godbasin.github.io/vue-ebook/vue-ebook/3.html#_3-1-vue-%E5%AE%9E%E4%BE%8B)
- [music player](https://github.com/maomao1996/Vue-mmPlayer)
- [create-a-modern-application-with-django-and-vue](https://www.ericsdevblog.com/posts/create-a-modern-application-with-django-and-vue-1/)
- [vue implemente 163music](https://github.com/qier222/YesPlayMusic)

- project
    - [email-helper](https://github.com/shengxinjing/email-helper/tree/main)
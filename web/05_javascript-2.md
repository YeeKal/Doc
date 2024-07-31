---
title: JavaScript 2
categories: 
tags: 
is_draft: false
date: 2024-04-08
keywords: 
cover: 
description: 
---

## this

在 JavaScript 中 this 不是固定不变的，它会随着执行环境的改变而改变

- 在方法中，this 表示该方法所属的对象
- 单独使用 this，则它指向全局(Global)对象。

## let & const

JavaScript 拥有动态类型。这意味着相同的变量可用作不同的类型：

```js
var x;               // x 为 undefined
var x = 5;           // 现在 x 为数字
var x = "John";      // 现在 x 为字符串
```

- var定义的变量，没有块的概念，可以跨块访问, 不能跨函数访问。
- let定义的变量，只能在块作用域里访问，不能跨块访问，也不能跨函数访问。
- const用来定义常量，使用时必须初始化(即必须赋值)，只能在块作用域里访问，而且不能修改

```js
var x = 10;
// 这里输出 x 为 10
{ 
    let x = 2;
    // 这里输出 x 为 2
}
// 这里输出 x 为 10

```

```js

var x = 10;
// 这里输出 x 为 10
{ 
    const x = 2;
    // 这里输出 x 为 2
}
// 这里输出 x 为 10
```

const 实际定义了一个常量引用，因此使用 const 定义的对象或者数组，其实是可变的

## Function

```js
// 函数声明
function functionName(parameters) {
  执行的代码
}

// 函数表达式
var x = function (a, b) {return a * b};
```
**<font color='Tomato'>箭头函数(arrow function)</font>**

```js


(参数1, 参数2, …, 参数N) => { 函数声明 }

(参数1, 参数2, …, 参数N) => 表达式(单一)
// 相当于：(参数1, 参数2, …, 参数N) =>{ return 表达式; }

(单一参数) => {函数声明}
单一参数 => {函数声明}

() => {函数声明}  // 无参数

// ES6 使用 const 比使用 var 更安全，因为函数表达式始终是一个常量
const x = (x, y) => x * y;
```

**<font color='Tomato'>Closure 闭包</font>**

在函数内部返回定义的子函数，从而通过子函数访问函数内部变量。

好处：

1. 可以读取函数内部的变量
2. 让这些变量的值始终保持在内存中

```js
function makeFunc() {
  var name = "Mozilla";
  function displayName() {
    alert(name);
  }
  return displayName;
}

var myFunc = makeFunc();
myFunc();
```


## Object

JavaScript 对象是键值对的容器, 类似python中的字典

## Json

JSON 格式在语法上与创建 JavaScript 对象代码是相同的.


```js
{"sites":[
    {"name":"Runoob", "url":"www.runoob.com"}, 
    {"name":"Google", "url":"www.google.com"},
    {"name":"Taobao", "url":"www.taobao.com"}
]}

var obj = JSON.parse(text);

// convert java var to json string
var str = {"name":"菜鸟教程", "site":"http://www.runoob.com"}
str_pretty1 = JSON.stringify(str)
```

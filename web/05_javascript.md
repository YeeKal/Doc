---
title: JacaScript tutorial
categories: 
tags: 
is_draft: false
date: 2023-04-08
keywords: 
cover: 
description: 
---


## script tag

internal: inside the html file
```html
<!-- INTERNAL -->
<html>
<head>yeekal</head>
<body>
    <script>document.write("hello world!");
<!-- to output text/html -->
  	<script>document.write("<h1>Hello world!</h1>");</script>
    </script>
</body>
</html>
```

external: outside the html file
```html
<script src="demo.js"></script>
```

demo.js

```javascript
alert("this is an alert box");
//not contain <script> tags
```


Script tag can take two attributes, **language** and **type** , which specify the script type. The language attribute is deprecated, and should not be used. the type is not needed as js is the default script for html.

```html
<script language="javascript" type="text/javascript">
  
  </script>
```

comment:

```js

//this is a comment
/*
this is multiple lines
comment
*/
```


## data type

**variables**

```js
var x=10;
//case sensitive
//no assignment value is 'undefined'
```

**Number**

> not define different types of numbers
>
> js numbers are always stored as double precision floating point numbers

**String**

```javascript
var name="john";
var name='john';
//double or single served as the same function
var text="my name is 'john'";

//use backslash
var sayHello = 'Hello world! \'I am a JavaScript programmer.\' ';
//use + to joint two strings and space will fill between them
```

**Boolean**

true: any with a real value;

false: 0/null/undefined

## operation

**arithmetic operation**

- +/  - * %  ++  --
- ++ :在前，先计算后赋值；在后，先赋值，再计算；

**comparision operation**

==: equal to

===: identical(equal and of same type)

!=: not equal

!==: not identical

**logical operators**

&&: and

||: or

!: not

**conditional operator**

```js
var isAdult = (age < 18) ? "Too young": "Old enough";
```

## statement flow

**if else**

```javascript
//format
if (condition){
  //statement
}
else if{
  //statement
}
else{
  //
}

//example
var num1=3;
var num2=4;
if (num1<num2){
  alert("who is bigger is taller");
}
else{
  alert("haha");
}
```

**switch**

```javascript
switch(n)
  {
    case 1:
      //
      break;
    case 2:
      //
      break;
    default:
      //
  }
```

**for**

```javascript
//for
for (var i=0;i<10;i++)
  {
    document.write(i);
  }

//for in
for (x in person)
  {
    //
  }
```

**while/do while**

**break/continue**

break:  skip to next statements;

continue: skip this loop and execute next loop;

## function

```javascript
function myFunction(){
  alert("hello ,this is my function");
}
```

## popupalert

```javascript
//alert
alert("hello!");//to send an alert and ok must be pressed to proceed

//prompt
var user=prompt("please enter your name:");
alert(user);

//confirm
//to have the user verify or accept something
var result=confirm("do you want to leave me?");
if (result==true){
  alert("i am so sad!");
}
else{
  alert("my cute darling!");
}
```

# objects

有对象而无类

## object constructor

set an 'object type to create a number of objects'

```javascript
function person(name,age,color){
  this.name=name;
  this.age=age;
  this.color=color;
}

//create objects
var p1=new person("yee",23,"white");

//1
person=new Object();
person.firstname="Bill";
person.lastname="Gates";
person.age=56;
person.eyecolor="blue";
//2
person={firstname:"John",lastname:"Doe",age:50,eyecolor:"blue"};
```

**object initialization**

```javascript
var John={name:"john",age:23};
//use object literal or initializer syntax to create single objects
```

**add method**

```javascript
//definition inside
function person(name, age) {
  this.name = name;  
  this.age = age;
  this.changeName = function (name) {
    this.name = name;
  }
}

//definition outside
function person(name, age) {
  this.name= name;  
  this.age = age;
  this.yearOfBirth = bornYear;
}
function bornYear() {
  return 2016 - this.age;
}
```

## array

**creating array**

```javascript
//def1
var courses=new Array("html","css","js");
//def2
var courses=new Array(3);
courses[0]="html";
courses[1]="css";
courses[2]="js";
//def3
var courses=new Array();
/*
js array is dynamic, so you can not pass any argumrnts to the Array() constructor.
*/
//def4
//array literal
//The array literal syntax is the recommended way to declare arrays
var courses = ["HTML", "CSS", "JS"]; 

//access
var course=courses[0];
document.write(courses[10]);//return the value 'undefined'

//change value
courses[1]="c++";
```

**array method**

- length

- concat - join arrays to create a new array

  ```javascript
  var course=c1.concat(c2)
  ```

**asssociate array**

not commend

```javascript
var person = []; //empty array
person["name"] = "John";
person["age"] = 46;
document.write(person["age"]);
//use name index
//Outputs "46"
/*
the person array is treated as an object
*/
```

## Math

- E
- LN2
- LN10
- LOG2E
- LOG10E
- PI

```javascript
document.write(Math.PI);
//Math has no constructor.There's no need to create a Math object first.
```

**Math method**

- abs(x);
- acos;asin;atan;acos;sin(x);cos(x);
- exp(x);log(x);pow(x,y);sqrt(x);
- ceil(x)- rounded upwards to  the nearest integer
- floor(x)- rounded downwards to the nearest number
- max(a,b,c);min(a,b,c,d);
- random()- a random value between 0 and 1;
- round(x)- nearest integer;

## Data

**setInterval**

calls a function/statement at specified intervals in milliseconds

```javascript
function myAlert(){
  alert("we meet again!");
}
setInterval(myAlert,3000);
```

**method**

- Date()- current time
- getFullYear()
- getMonth()
- getDate()
- getDay()
- getHours()
- getMinutes()
- getSeconds()
- getMilliseconds()

```javascript
var d = new Date();
var hours = d.getHours();
//hours is equal to the current hour
```

## Number

[number object manual](http://www.w3school.com.cn/jsref/jsref_obj_number.asp)

- all num is 64-bit
- with 0 head as  octal(8进制)
- with 0x head as  hexadecimal

| [toString](http://www.w3school.com.cn/jsref/jsref_tostring_number.asp) | 把数字转换为字符串，使用指定的基数。         |
| ---------------------------------------- | -------------------------- |
| [toLocaleString](http://www.w3school.com.cn/jsref/jsref_tolocalestring_number.asp) | 把数字转换为字符串，使用本地数字格式顺序。      |
| [toFixed](http://www.w3school.com.cn/jsref/jsref_tofixed.asp) | 把数字转换为字符串，结果的小数点后有指定位数的数字。 |
| [toExponential](http://www.w3school.com.cn/jsref/jsref_toexponential.asp) | 把对象的值转换为指数计数法。             |
| [toPrecision](http://www.w3school.com.cn/jsref/jsref_toprecision.asp) | 把数字格式化为指定的长度。              |
| [valueOf](http://www.w3school.com.cn/jsref/jsref_valueof_number.asp) | 返回一个 Number 对象的基本数字值。      |

## String

- length
- match("str")- true then return str/ false return null
- replace(/str1/,"str2")- replace str1 with str2

## regular expression

# DOM

## the dom

Document Object Model

an object oriented model of its logical structure.

**dom tree**

realtionship between elements:

child  parent  sibling

**document object**

document- a predefined object,the root of all objects 

```javascript
document.body.innerHTML="string";
//change the content
//the innerHTML property can be used on almost all html elements to change content
```

## select elements

all html elements are objects.

```javascript
document.getElementById("demo");
//select particular one

document.getElementsByClassName("demo");
document.getElementsByTagName("demo");
////select as an array
```

element.**childNodes** returns an array of an element's child nodes.
element.**firstChild **returns the first child node of an element.
element.**lastChild **returns the last child node of an element.
element.**hasChildNodes **returns true if an element has any child nodes, otherwise false.
element.**nextSibling **returns the next node at the same tree level.
element.**previousSibling **returns the previous node at the same tree level.
element.**parentNode **returns the parent node of an element.



## change elements

change attributes

change styles

```javascript
arr.style.color="#123456";
//no dashes(-), "background-color" should be replaced by "backgroundColor"
```

## create element

- element.cloneNode()- clones an element and returns the resulting node
- document.createElement(<element>)- 
- document.createTextNode(str)
- element.appendChild(node)
- element.insertBefore(node1,node2)- insert node1 as a child before node2

```javascript
//add: create-append text-find by id-append child
var el = document.createElement ("li");
var txt = document.createTextNode("B");
el.appendChild(txt);
var ul = document.getElementByiD("list");
ul.appendChild(el);

//remove
var parent=document.getElementById("demo");
var child=document.getElementById("p1");
parent.removeChild(child);
//another way
child.parentNode.removeChild(child);

//replace
parent.replaceChild(p,child);
```

## animation

## events

when an event sccurs on a target

common events:

- onclick-
- onload
- onunload
- onchange- occurs when the content of a form element,the selection or the checked state have changed.
- onmouseover-pointer is moved onto an element
- onmouseout- pointer is moved
- onmousedown- press a mouse button
- onmouseup-relese a mouse button
- onblur- loses focus
- onfocus- gets focus

**handle events**

```javascript
//m1
<button onclick="show()">click me</button>;

//m2
var x=document.getElementById("demo");
x.onclick=function (){
  //
}

//m3,a more flexible way
bt.addEventListener("click",myFunction);
bt.removeEventListener("click",myFunction);
//no "on"
```

```javascript
windows.onload=function(){
  //used to run code after the whole page is loaded
}
```

**event propagation**

- bubbling- innermost elements' event is handled first
- capturing- 

```javascript
addEventListener(event,function,useCapture);
addEventListener(event,function,true);
```

**image slider**


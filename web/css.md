*css*

[TOC]

**[intro](#intro)**

**[basic](#basic)**

​	[css definition](#css-definition)

​	[css rules](#css-rules)

​	[css comments](#css-coments)	

**[text property](#text-property)**

​	[font](#font)

​	[text](#text)	

**[element](#element)**

​	[box model](#box-model)

​	[size](#size)

​	[background](#background)

​	[list style](#list-style)

​	[table style](#table-style)

​	[link style](#link-style)

​	[mouse cursor](#mouse-cursor)

**[css3 basic](#css3-basic)**

​	[rounded corners](#rounded-corners)

​	[box-shadow](#box-shadow)

​	[transparency effect](#transparency-effect)

​	[presudo](#presudo)

​	[world-wrap](#world-wrap)

​	[@font-face](#font-face)

​	[gradients](#gradients)

​	[background-](#background-)

​	[opacity](#opacity)

**[trans](#trans)**

​	[transition](#transition)

​	[transform](#transform)

​	[animation](#animation)

​	[3dtransform](#3dtransform)



# intro

**CSS：C**ascading **S**tyle **S**heets, to separate **style** from **content**

# basic

## css definition

**inline CSS**

```html
<p style="color:white;background-color:gray;">
  This is an example off inline styling.
</p>
```

**embeded css**

internal styles defined within **\<style\>** element,inside the **head** section 

```html
<html>
<head>
  <style>
    p{
      color:white;
      background-color:gray;
    }
  </style>
</head>
  
<body>
   <p>I am happy to meet you again!</p> 
</body>
</html>
```

**external css**

styling rules are contained in a single text file saved with .css extension.

```html
<head>
  <link rel="stylesheet" href="example.css">
</head>
```

the **example.css**

```css
p{
  color:white;
  background-color:gray;
}
```

## css rules

**css syntax**

a stle rule has three parts: **selector  property  value**

```css
h1 {color:orange}
```

**type selector**

targets elements types on the page.

for example, to target all the paragraphs on  the page:

```css
p{
  color:red;
  font-size:20px;
}
```

**id selector**

html:

```html
<div id="intro">
  <p>i love you.</p>
</div>
```

css:

```css
#intro{
  color:white;
}
```

**class selector**

html:

```html
<div>
  <p class="sunday">a good day.</p>
  <p class="badday">a rainy day</p>  
</div>

<p class="sunday">another sun day</p>
```

css:

```css
.sunday{
  color:red;
}
.badday{
  color:blue;
}
```

- id can only be applied**once**;while class can be possessed by **many owners**.

**descendant selector**

派生选择器


html:

```html
<div id ="intro">
  <p class="exe1">This paragraph contains <em>this </em>to be selected.</p>
  <p class="exe1">this will not</p>
</div>
```

css:

```css
#intro .exe1 em{
  color:pink;
}
```

## css comments

```css
/* comments here*/
/*
multilines comments;
line;
*/
p{
  color:orange;
}
```

**css cascade and inheritance**

a cascade contains three main sources:

- stylesheets created
- broweser's default styles
- strles specified by users

# text property

## font

**font-family**

- font family: a specific font family
- generic family: a group of font families

five generic family:

- serif
- sans-serif
- monospace
- cursive
- fantasy

```css
p .serif{
  font-family:"times new roman",times,serif;
}
p .monospace{
  font-family:"courier new",courier,monospace;
}
/*
use comma to indicate they are alternative
quotation marks to quote more than one word
add the generic family as a fallback
*/
```

**font-size**

keywords: **x-small, small, medium,large,larger,x-large**

numerical values: **px,em;em=default px**

**font-style**

```css
italic
normal
oblique
/*<i> tag will produce exactly the same result as the italic font style.*/
```

**font-weight**

```css
100-900
normal	400
light
bold	700
bolder
```

**font-variant**

```css
normal
small-caps
```

**color**

color name:	red, white,.....

rgb:	`color:rgb(255,0,0)`defines individual values for red, green, blue

hexadecimal values: `color:#FFFFFF`

## text

**text-align**

```css
left
right
center
justify
/*justify: each line is strenched to get equal width*/
```

**vertical-align**

```css
top
middle
bottom
/* most used in table*/

baseline
sub
super
+/- xx(px/pt/cm)
```

**text-decoration**

```css
none
inherit
overline
underline
line-through

@deprecated
  blink
```

**text-indent**

```css
p{
  text-indent:30px
}
/*negative value is valid*/
```

**text-shadow**

```css
text-shadow:4px 2px 4px grey;
/*
4px - x-coordinate
2px - y-coordinate
4px - the blur radius
grey - the color of the shadow
*/
```

**text-transform**

```css
capitalize
uppercase
lowercase
```

**letter-spacing**

```css
letter-spacing:normal;
letter-spacing:4px;
/*negative value is valid*/
```

**word-spacing**

as above

**white-space**

```css
pre
pre-line
pre-wrap
```

# property

## box model

all html elements can be considered as boxes:

![box model](https://api.sololearn.com/DownloadFile?id=2613)

properties work in the same order: **top right bottom left**

total width: **padding+border+margin+content**

width and height properties: **content**

background-color cover: **content + padding** 

## size

**border**

```css
p{
  padding:10px;
  border:5px solid orange;
}

p{
  padding:10px;
  border-width:5px;
  border-style:solid;
  border-color:orange;
}

/*
none of the border properties will have any effect unless the border-style property is set.
*/
borderstyle:dotted/dashed/double/....
border-top-style
border-right-style
border-bottom-style
border-left-style
```

**width and height**

1. numerical value(pixels)
2. percents

min-width/min-height/max-width/max-height

## background-

**background-color**

**background-image**

```css
background-image:url("URL")
```

**background-repeat**

```css
{
  background-image:url("URL");
  background-repeat:repeat-x;
}
```

repeat-x: horizontal

repeat-y: vertical

no-repeat: show once

repeat:

inherit:	inheritance from parent element

**background-attachment**

sets whether a background image is fixed or scrolls with the rest of the page.

```css
fixed;
scroll;
inherit;
```

## list style

**list-style-type**

[list style all types from w3school](http://www.w3school.com.cn/tiy/t.asp?f=csse_list-style-type_all)

```css
ol .lower-alpha{	/*ordered list*/
  list-style-type:lower-alpha;
}

ul .circle{			/*unordered list*/
  list-style-type:circle;
}
```

**list-style-image**

```css
list-style-image:url("URL");
```

**list-style-position**

```css
list-style-position:inside;
/*outside is the default value*/
```

**list-style**

```css
list-style:square outside none;
/*equals to*/
list-style-type:square;
list-style-position:outside;
list-style-image:none;
/*the missing value will set the default*/

```

## table style

**border-collapse**

- separate:  double borders
- collapse:   single

**border-spacing**

```css
/*distance between two borders*/
border-spacing:20px 40px;
```

**caption-side**

​	specify the placement of table caption

- top
- bottom

**empty-cells**

- show
- hide

**table-layout**

​	specify the width of table columns

- auto (default)
- fixed

## link style

preudo selectors for link:

- a:link  unvisited links
- a:visited  visited links
- a:hover  when the mouse is over it
- a:active  once you click on it

property:

- color
- font-family
- text-decoration (:none)   remove underline
- ...

## mouse cursor

**cursor**: specifies the desired cursor style when you mouse over an element

![possible value](https://api.sololearn.com/DownloadFile?id=2983)

# element

## 列表

```css
ul li{
  display:block;
  float:left;
  width:30px;
}
/*为了让列表项水平显示，将其设置为左浮动。为了定义宽度则设为块级元素*/
/*当然设置为inline内联元素也可以水平，但却不能定义宽度*/
```



## display

**display**

- block:  change an inline element to a block element
- inline:  reverse
- none:  hide elements; as no such element
- list-item
- grid
- ...

**visibility**

- hidden:  remain space without content
- visible

## position

**position**

- static:  default
- fixed:  will not move even the window is scrolled
- relative: relative to its normal position
- absolute

**top/right/bottom/left**

**floating**

​	for img floating in the text

​	for elements next to each other

​	脱离原来的文档流，不占位置

- left
- right
- none

**clear**

elements that come after the floating element will flow around it

use clear

- left
- right
- both





**overflow**

specify the content overflowing the box

- scroll:  add scroll bar
- auto: adding scroll bar when overflow happens, not add if not
- hidden:  the rest remains invisible
- visible: default, no bars

**z-index**

whos num is larger, who lay upper

as seeing from z-axis

position elements is necessary

**对齐**

```css
//水平对齐。'!doctype'
margin-left:auto;
margin-right:auto;
```



# css3 basic

**vender prefixe**

to add support for new css features

```css
-webkit-border-radius:24px;
/*
most browsers today will work without prefixes
it is essential to know these for backgrounds capability
*/
```

![browser prefixes](https://api.sololearn.com/DownloadFile?id=2665)

## rounded corners

```css
border-radius:20px;

/*specify values respectively as order:top-left  top-right  bottom-right  bottom-left*/
border-radius: 0 0 20px 20px;

/*create a circle*/
div{
  height:200px;
  width:200px;
  border-radius:100px;
  background-color:green;
  color:white;
}
```

## box-shadow

```css
box-shadow:10px 10px #888888;
/*
10px:  horizontal offset
10px:  vertical offset
#:     color
for material design
*/

box-shadow:10px 10px 8px -4px #888888;
/*
optional values:
blur and spread
*/
/*values can be set negative except blur-option*/

box-shadow:inset 10px 10px 5px #888888;
/*create an inner shadow with keyword:inset
凹陷/凸起感*/

/*multiple layer*/
box-shadow:
inset 10px 10px 5px #888888,
0 0 10px 30px #ffdab9;
```

## transparency effect

**rgba(red,green,blue,alpha)**

```css
div{ 
background: linear-gradient(90deg, 
     rgba(255, 255, 255, 0) 0%, 
     rgba(255, 255, 255, 0.2) 25%, 
     rgba(255, 255, 255, 0.2) 75%, 
     rgba(255, 255, 255, 0) 100%);
box-shadow: 0 0 25px rgba(0, 0, 0, 0.1),
     inset 0 0 1px rgba(255, 255, 255, 0.6);
}
/*beautiful*/
```

## presudo

**presudo class**

`:`

html:

```css
<div id="parent">
   <p>First paragraph</p>
   <p>Second paragraph</p>
   <p>Third paragraph</p>
   <p>Fourth paragraph</p>
</div>
```

css:

```css
#parent p:first-child {
   color: green;
   text-decoration: underline;   
}
/*matches the first p in div with id named parent*/
/*last-child*/
```

**presudo element**

used to select specific parts of an elements

five elements in css, starting with a double colon `::`

**::first-line** - the first line of the text in a selector

**::first-letter** - the first letter of the text in a selector

**::selection** - selects the portion of an element that is selected by a user

**::before **- inserts some content before an element

**::after** - inserts some content after an element

```css
p::before{
  content:url("img.jpg");
}
```

## word-wrap

```css
word-wrap:normal;	/*a long word not break*/
word-wrap:break-word;	
/*
when the word-wrap property is set to break-word, the browser breaks a word when it is too long for fit within its container.
*/
```

## @fonr-face

allows custom fonts to be loaded into a webpage.

In Internet Explorer 8 and earlier, the URL must point to an **Embedded OpenType** (eot) file, while Firefox, Chrome, etc. support **True Type Fonts** (ttf) fonts and **OpenType Fonts** (otf).

```css
@font-face{
  font-family:delicious;
  src:url('delicilous-roman.otf');
  font-weight:bold;
}

/*ie has a built-in bug when multiple @font-face rules are defined
using #iefix as following example*/
@font-face { 
   font-family: Delicious; 
   src: url('Delicious-Roman.ttf');
   src: url('Delicious-Roman.eot?#iefix'); 
}
```



## gradients

**linear gradient**

```css
background:-moz-linear-gradient(blue 20%, yellow 30%, green 85%);
 background:linear-gradient(white 20%,gray 50%,green 50%,red 80%);
/*sharp color
colorname/rga/rgba/hex values/hsl*/

background:-webkit-linear-gradient(left,white 20%,gray 50%,green 50%,red 80%);
/*
change direction:
left/right/top/botttom/bottom right
0-180deg
*/

background:-moz-repeating-linear-gradient(blue, green 20px);
/*repeating per 20px*/
```

**radical-gradient**

```css
/*universal format*/
radial-gradient(position size/shape color);
/*
shape:
circle
eclipse
position: top left/0% 0%/20px 20px
*/
background:radial-gradient(white 15%,black 				    15%,rgba(200,200,200,0.2) 100%);
```

## background-

**background-size**

specify the size of background images, using either lengths or percentages

```css
div{
  height:150px;
  width:200px;
  border:1px solid #000;
  background:url("css.png") no-repeat 50% 50%;
  background-size:100px 100px;
}

/*keywords*/
contain;
cover;
```

**background-clip**

specify the painting area of the background

still work with image

border-box: (default)

padding-box:

content-box:

```css
border: 20px solid rgba(0, 0, 0, 0.3);
background-clip:padding-box;
/*Transparency effect is achieved with the background-clip:padding-box. Without it, the background of the box also goes beneath the borders, making it non-transparent.*/
```

**multiple backgrounds**

```css
div {
  width: 400px;
  height: 300px;
  background-image: url(csslogo.png), url(csscode.jpg);
  background-position: right bottom, left top;
  background-repeat: no-repeat;
} 
/*another way*/
background: url(csslogo.png) right top no-repeat, 
url(csscode.jpg) left top no-repeat; 
```

## opacity

an excellent means of adding opacity to any element

```css
#img1{
  opacity:0.5;
}
/*opacity value must be between 0.0-1.0*/

/*to work in ie*/
opacity:0.5;
filter.alpha(opacity=50);
```



# trans

## transition

allow us to change one property value to another one over a given duration

**transition-property** - specifies the property to be transitioned
**transition-duration** - specifies the duration over which transitions should occur
**transition-timing-function** - specifies how the pace of the transition changes over its duration
**transition-delay** - specifies a delay (in seconds) for the transition effect

example:

```css
div {
   width: 50px;
   height: 50px;
   background: #32CD32;
   transition: width 3s;
}
div:hover {
   width: 250px;
}
/*if you hover the div element it will anlarge duriing 3 seconds*/
```

**transition-timing-function**

**ease **- the animation starts slowly, then accelerates quickly.
**ease-in** - starts slowly, then accelerates, and stops abruptly.
**ease-out** - starts quickly, but decelerates to a stop.
**ease-in-out** - similar to ease, but with more subtle acceleration and deceleration.
**linear **- constant speed throughout the animation; often best for color or opacity changes.

**cubic-besizer()**: value from0 to 1

```css
transition-timing-function: cubic-bezier(0,0,1,1);
```

## transform

**rotate**

```css
transform:rotate(10deg);/*negative value will generate counter-clockwise*/
```

**transform-origin**

change the position of the transform point

```css
transform:rotate(15deg);
transform-origin:25% 75%;
```

**translate**

```css
transform:translate(100px,50px);/**/
```

**skew**

```css
transform:skew(30deg,30deg);/*平行四边形*/
```

**scale**

```css

```

**multiple trans**

```css
transform:rotate(45deg) translate(100px);/*no comma*/
```

```css
/*transition定义了类型，时间，在动作中定义transform具体的行为*/
div
{
width:100px;
height:100px;
background:yellow;
transition:width 2s, height 2s;
-moz-transition:width 2s, height 2s, -moz-transform 2s; /* Firefox 4 */
-webkit-transition:width 2s, height 2s, -webkit-transform 2s; /* Safari and Chrome */
-o-transition:width 2s, height 2s, -o-transform 2s; /* Opera */
}

div:hover
{
width:200px;
height:200px;
transform:rotate(180deg);
-moz-transform:rotate(180deg); /* Firefox 4 */
-webkit-transform:rotate(180deg); /* Safari and Chrome */
-o-transform:rotate(180deg); /* Opera */
}
```



## animation

```css
div {
   width: 100px;
   height: 100px;
   background-color: red;
   animation-name: colorchange;		/*bind name*/
   animation-duration: 1s;			/*time*/
}
@keyframes colorchange {			/*from to*/
   0% {background-color: red;}
   50% {background-color: green;}
   100% {background-color: blue;}
} 
```

**animation-name**

**animation-duration**

**animation-timing-function**

same as transtion-timing-function

**animation-delay**

​	s/ms(milliseconds)

**animation-iteration-count**

numerical/infinite

```css
animation-iteration-count:5;  /*repeat 5 times*/
```

**animation-direction**

The values can be set as:
normal - the default value, which means it plays forward from 0 % to 100%. 
reverse - plays the keyframe in an opposite direction from 100 % to 0%
alternate - the animation first runs forward, then backward, then forward.

**multiple include**

```css
div {
   animation-name: colorchange;
   animation-duration: 3s;
   animation-timing-function: ease-in;
   animation-delay: 1s;
   animation-iteration-count: infinite;
   animation-direction: reverse;
}
/*can be revised as following*/
div { 
   animation: colorchange 3s ease-in 1s infinite reverse;
}
/*order can not be altered*/
```

## 3dtransform

**rotate**

rotate3d=rotatex+rotatey+rotatez

```css
div.X {
   transform: rotateX(150deg);
}
div.Y {
   transform: rotateY(150deg);
}
div.Z {
   transform: rotateZ(150deg);
}
```

**translate**

```css
#mybox1 {
   transform: translate3d(-20px, 4em, 10px);
}
/*equal to*/
#mybox1 {
   transform: translateX(29px) 
   translateY(5em) 
   translateZ(-13px);
}
```

**percpective**

```css
div.empty-div {
   perspective: 100px;
}
div.green-div {
   transform: rotateX(45deg);
}
/*The perspective property only affects 3D transformed elements.*/
```


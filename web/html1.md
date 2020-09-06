**HTML**

*outline*

[TOC]

# Temp

## 简介

- HTML: Hyper Text Markup Language, 超文本标记语言
- 标记语言是一套**标记标签**（makeup tag）
- HTML使用标记标签描述网页
- 对纯文本概念的理解，符号只是赋予文本以格式，浏览器对标签进行解析
- 超文本(hypertext),集合文档成一个完整的信息库，完全控制文档在屏幕上的显示以及浏览顺序

---

## 元素

- 开始标签起始，结束标签终止
- 空元素（empty content）在**开始标签中关闭** ，如：`<br \>`
- 标签推荐使用小写
- 默认情况下，HTML 会自动地在块级元素前后添加一个额外的空行，比如段落、标题元素前后

### 常用标签

| 标签               | 描述                      |      |
| ---------------- | ----------------------- | ---- |
| <html>           |                         |      |
| <body>           |                         |      |
| <h>              | 标题，1-6多级标题，自动前后添加空行     |      |
| <p>              |                         |      |
| <a href="">      | 链接，href属性中指定地址          |      |
| <hr />           | 创建水平线 （**空元素**）         |      |
| <!-- comment --> | 注释                      |      |
| <img src="">     | 图片，src属性定义图片地址（**空元素**） |      |
| <head>           |                         |      |
|                  |                         |      |

### 链接

**超链接的两种方式**

1. 通过使用 href 属性 - 创建指向另一个文档的链接
2. 通过使用 name 属性 - 创建文档内的书签

**语法**

>  使用图像作链接

```html
<a href="/example/html/lastpage.html">
<img border="0" src="/i/eg_buttonnext.gif" />
</a>
```

> target定义链接文档在何处显示

```html
<!-- open in a new page -->
<a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>
```

> name 规定锚(anchor),创建页内标签
>
> *假如浏览器找不到已定义的命名锚，那么就会定位到文档的顶端。不会有错误发生*

```html
<a name="anchor">tips</a>	<!--链接目标文本-->
<a href="#anchor">link</a>	<!-- 链接文本 -->
<!-- 指向其他页面的标签 -->
<a href="http://www.w3school.com.cn/html/html_links.asp#tips">有用的提示</a>
```

### 图像

> 插入普通图象与gif动图没区别

`<img src="url" width="15px" height="20px" alt="img">`

> 插入图像背景

`<body background="url"> </body>`

> 文本中图像的高低位置

`align="bottom/middle/top"`

> 图像浮动

`align="left/right"`

> map创建图像映射

```html
<!-- 指定mapid -->
<img
src="/i/eg_planets.jpg"
border="0" usemap="#planetmap"
alt="Planets" />

<!-- 指定mapid -->
<map name="planetmap" id="planetmap">

<!-- 划定点击区域 -->
<area
shape="circle"
coords="180,139,14"
href ="/example/html/venus.html"
target ="_blank"
alt="Venus" />

<area
shape="circle"
coords="129,161,10"
href ="/example/html/mercur.html"
target ="_blank"
alt="Mercury" />

<area
shape="rect"
coords="0,0,110,260"
href ="/example/html/sun.html"
target ="_blank"
alt="Sun" />

</map>
```

### 表格

> <table>开始；<tr>指定行；<td>定义元素；border指定边框

```html
<table border="8">
<tr>
  <td>First</td>
  <td>Row</td>
</tr>   
<tr>
  <td>Second</td>
  <td>Row</td>
</tr>
</table>
<!-- 空单元格-->
<td>&nbsp;</td>
```

**表格标签**

| 表格                                       | 描述          |
| ---------------------------------------- | ----------- |
| [table](http://www.w3school.com.cn/tags/tag_table.asp) | 定义表格        |
| [caption](http://www.w3school.com.cn/tags/tag_caption.asp) | 定义表格标题。     |
| [th](http://www.w3school.com.cn/tags/tag_th.asp) | 定义表格的表头。    |
| <tr>                                     | 定义表格的行。     |
| [td](http://www.w3school.com.cn/tags/tag_td.asp) | 定义表格单元。     |
| <thead>                                  | 定义表格的页眉。    |
| <tbody>                                  | 定义表格的主体。    |
| <tfoot>                                  | 定义表格的页脚。    |
| <col>                                    | 定义用于表格列的属性。 |
| <colqroup>                               | 定义表格列的组。    |

### 列表

| 标签                                       | 描述                                       |
| ---------------------------------------- | ---------------------------------------- |
| [ol](http://www.w3school.com.cn/tags/tag_ol.asp) | 定义有序列表。type="/A/a/I/i"                   |
| [ul](http://www.w3school.com.cn/tags/tag_ul.asp) | 定义无序列表。type="disc/circle/square"         |
| 描述                                       | [](http://www.w3school.com.cn/tags/tag_ol.asp) |
| 定义有序列表。                                  | [](http://www.w3school.com.cn/tags/tag_ul.asp) |
| 定义无序列表。                                  | [](http://www.w3school.com.cn/tags/tag_li.asp) |
| 定义列表项。                                   | [](http://www.w3school.com.cn/tags/tag_dl.asp) |

---

## 属性

- 属性以**名称/值**成对的方式出现：name="value"
- 名称/值 推荐小写
- 一般在开始标签中定义
- 始终为属性值加引号（单引号或双引号）

### 常见全局属性列表

| 属性    | 值                  | 描述                      |
| ----- | ------------------ | ----------------------- |
| class | *classname*        | 规定元素的类名（classname）      |
| id    | *id*               | 规定元素的唯一 id              |
| style | *style_definition* | 规定元素的行内样式（inline style） |
| title | *text*             | 规定元素的额外信息（可在工具提示中显示）    |

### style

> HTML4 中引入的新的改变元素样式的方式

```html
<html>
 <!--淘汰了旧的属性：bgcolor,font,align -->
<body style="background-color:green">
  <p style="font-family:verdana;color:red;font-size:20px;text-align:center;">

  </p>

  </body>
  </html>
```

---

## 文本格式化

### 文本格式化标签列表

| 标签                                       | 描述      |
| ---------------------------------------- | ------- |
| [b](http://www.w3school.com.cn/tags/tag_font_style.asp) | 定义粗体文本。 |
| [big](http://www.w3school.com.cn/tags/tag_font_style.asp) | 定义大号字。  |
| [em](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义着重文字。 |
| [i](http://www.w3school.com.cn/tags/tag_font_style.asp) | 定义斜体字。  |
| [small](http://www.w3school.com.cn/tags/tag_font_style.asp) | 定义小号字。  |
| [strong](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义加重语气。 |
| [sub](http://www.w3school.com.cn/tags/tag_sup.asp) | 定义下标字。  |
| [sup](http://www.w3school.com.cn/tags/tag_sup.asp) | 定义上标字。  |
| [ins](http://www.w3school.com.cn/tags/tag_ins.asp) | 定义插入字。  |
| [del](http://www.w3school.com.cn/tags/tag_del.asp) | 定义删除字。  |

### 计算机输出标签

| 标签                                       | 描述         |
| ---------------------------------------- | ---------- |
| [code](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义计算机代码。   |
| [kbd](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义键盘码。     |
| [samp](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义计算机代码样本。 |
| [tt](http://www.w3school.com.cn/tags/tag_font_style.asp) | 定义打字机代码。   |
| [var](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义变量。      |
| [pre](http://www.w3school.com.cn/tags/tag_pre.asp) | 定义预格式文本。   |

### 引用和术语标签

| 标签                                       | 描述                       |
| ---------------------------------------- | ------------------------ |
| [abbr](http://www.w3school.com.cn/tags/tag_abbr.asp) | 定义缩写。                    |
| [acronym](http://www.w3school.com.cn/tags/tag_acronym.asp) | 定义首字母缩写。                 |
| [address](http://www.w3school.com.cn/tags/tag_address.asp) | 定义地址。 通常以*斜体*显示,元素前后添加折行 |
| [bdo](http://www.w3school.com.cn/tags/tag_bdo.asp) | 定义文字方向。                  |
| [blockquote](http://www.w3school.com.cn/tags/tag_blockquote.asp) | 定义长的引用。                  |
| [q](http://www.w3school.com.cn/tags/tag_q.asp) | 定义短的引用语。                 |
| [cite](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义引用、引证。                 |
| [dfm](http://www.w3school.com.cn/tags/tag_phrase_elements.asp) | 定义一个定义项目。                |

### 类

> 为相同的类设置相同的样式,div/span

```html
<!-- 在head中定义-->
<style>
.cities {
    background-color:black;
    color:white;
    margin:20px;
    padding:20px;
}
<!-- class属性引用-->
  <div class="cities">
  </div>

```



---

## CSS样式表

>  HTML4.0，格式化代码可移出 HTML 文档，移入一个独立的样式表

**外部样式表**

```html
<head>
<link rel="stylesheet" type="text/css" href="mystyle.css">
</head>
```

**内部样式表**

```html
<head>
<style type="text/css">
body {background-color: red}
p {margin-left: 20px}
</style>
</head>
```

**内联样式**

```html
<p style="color: red; margin-left: 20px">
This is a paragraph
</p>
```

| 标签                                       | 描述              |
| ---------------------------------------- | --------------- |
| [style](http://www.w3school.com.cn/tags/tag_style.asp) | 定义样式定义。         |
| [link](http://www.w3school.com.cn/tags/tag_link.asp) | 定义资源引用。         |
| [div](http://www.w3school.com.cn/tags/tag_div.asp) | 定义文档中的节或区域（块级）。 |
| [span](http://www.w3school.com.cn/tags/tag_span.asp) | 定义文档中的行内的小块或区域。 |

*[一个示例](http://www.runoob.com/try/try.php?filename=tryhtml_styles)*

```html
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>菜鸟教程(runoob.com)</title>
</head>
<body>

<div style="opacity:0.5;position:absolute;left:50px;width:300px;height:150px;background-color:#40B3DF"></div>

<div style="font-family:verdana;padding:20px;border-radius:10px;border:10px solid #EE872A;">

<div style="opacity:0.3;position:absolute;left:120px;width:100px;height:200px;background-color:#8AC007"></div>
haha
<h3>Look! Styles and colors</h3>

<div style="letter-spacing:12px;">Manipulate Text</div>

<div style="color:#40B3DF;">Colors
<span style="background-color:#B4009E;color:#ffffff;">Boxes</span>
</div>

<div style="color:#000000;">and more...</div>

</div>
<div style="background-color:#B4009E;opacity:0.5;font-size:20px">
	<p>a new para</p>
	</div>
</body>
</html>
```
##HTML5布局

**HTML5 语义元素 **

```html
header
定义文档或节的页眉
nav
定义导航链接的容器
section
定义文档中的节
article
定义独立的自包含文章
aside
定义内容之外的内容（比如侧栏）
footer
定义文档或节的页脚
details
定义额外的细节
summary
定义 details 元素的标题
```

## HTML响应设计

RWD:Responsive Web Design
改变网页大小，自动改变布局
Bootstrap框架

## 框架

在同一窗口浏览多个页面

```pascal
//水平
<frameset rows="25%,50%,25%">
  <frame src="/example/html/frame_a.html">
  <frame src="/example/html/frame_b.html">
  <frame src="/example/html/frame_c.html">
</frameset>

//垂直
<frameset cols="25%,50%,25%">
  <frame src="/example/html/frame_a.html">
  <frame src="/example/html/frame_b.html">
  <frame src="/example/html/frame_c.html">
</frameset>

//格式
<frameset cols/rows="%%%">
	<frame src="<>">
	<frame src="<>">
	<frame src="<>">
	</frameset>
	
<frmae src="<>" noresize="noresize">	//不可改变框的大小
<noframes> <body> </body> </noframes> 	//在<noframes>标签中用body标签
```

**内联框架**
在网页指定区域内内显示网页

```html
<iframe src="URL" width="" height=""></iframe>
frameborder="0"	移除边框
name=""			作为链接目标，网页在框架内显示
```

## 背景

```html
bgcolor:
<body bgcolor="#000000">
<body bgcolor="rgb(0,0,0)">
<body bgcolor="black">

background
<body background="clouds.gif">
<body background="http://www.w3school.com.cn/clouds.gif">
使用style来定义
```

## 脚本

<script>定义脚本
<noscript>若浏览器不支持脚本则显示提示信息
type	规定脚本MIME类型 js

## 头部元素

```html
<head>
<title>	标题
<base>	为链接定义默认地址或默认目标
<link>	文档与外部资源之间的关系
<strle>
	<style type="text/css">
	body {background-color:yellow}
	p {color:blue}
	</strle>
	
<meta> 	元数据，浏览器可认
```

## 字符实体

转义字符

显示结果	描述	实体名称	实体编号
 	空格	&nbsp;	&#160;
<	小于号	&lt;	&#60;

> ```
> 大于号	&gt;	&#62;
> ```
>
> &	和号	&amp;	&#38;
> "	引号	&quot;	&#34;
> '	撇号 	&apos; (IE不支持)	&#39;
> ￠	分（cent）	&cent;	&#162;
> £	镑（pound）	&pound;	&#163;
> ¥	元（yen）	&yen;	&#165;
> €	欧元（euro）	&euro;	&#8364;
> §	小节	&sect;	&#167;
> ©	版权（copyright）	&copy;	&#169;
> ®	注册商标	&reg;	&#174;
> ™	商标	&trade;	&#8482;
> ×	乘号	&times;	&#215;
> ÷	除号	&divide;	&#247;

## URL

URL - Uniform Resource Locator
同一资源定位符
scheme://host.domain:port/path/filename

scheme - 定义因特网服务的类型。最常见的类型是 http   /https/ftp
host - 定义域主机（http 的默认主机是 www）
domain - 定义因特网域名，比如 w3school.com.cn
:port - 定义主机上的端口号（http 的默认端口号是 80）
path - 定义服务器上的路径（如果省略，则文档必须位于网站的根目录中）。
filename - 定义文档/资源的名称

## URL编码

- URL 只能使用 ASCII 字符集来通过因特网进行发送
- 超出字符以%xx两位十六进制数来表示非ASCII字符
- 通常以+来表示空格

# XHTML

XML+HTML

### 文档结构

- XHTML DOCTYPE 是*强制性的*
- <html> 中的 XML namespace 属性是*强制性的*
- <html>、<head>、<title> 以及 <body> 也是*强制性的*

### 元素语法

- XHTML 元素必须*正确嵌套*
- XHTML 元素必须始终*关闭*
- XHTML 元素必须*小写*
- XHTML 文档必须有*一个根元素*

### 属性语法

- XHTML 属性必须使用*小写*
- XHTML 属性值必须用*引号包围*
- XHTML 属性最小化也是*禁止的*

# HTML表单

```pascal
<form>
	.
	form  elements
	.
</form>
```

## 元素

**input**

- type属性：

| 类型     | 描述                 |
| ------ | ------------------ |
| text   | 定义常规文本输入。          |
| radio  | 定义单选按钮输入（选择多个选择之一） |
| submit | 定义提交按钮（提交表单）       |

- name:保证正确提交，每个字段必须设置name属性
- action：提交表单时执行的动作
- method：表单提交时所使用的方法`GET&POST`

```pascal
<form action="action_page.php" method="GET">
<input type="text" name="firstname">
<br/>
<input type="radio" name="sex" value="male" >
<br/>
<input type="submit" value="Submit">
</form>
```

**select**

定义下拉列表

*实例*

```html
<select name="cars">
  <option value="volvo" selected>Volvo</option>
  <!--selected预定义选项 -->
  <option value="saab">Saap</option>
  <option value="fiat">Fiat</option>
 </select>
```

**textarea**

多行输入文本域，空格和换行会完整呈现

```html
<textarea name="message" rows="10" cols="30">
The cat was playing in the garden.
</textarea>
```

**button**

```html
<button type="button" onclick="alert('Hello World!')">Click Me!</button>
```

**datalist(html5)**

- 为input元素规定预定义选项列表
- input引用datalist的id

```html
<input list="broesers" name="broweser">
<datalist id="browesers">
  <option value="internet explorer">
  <option value="firefox">
  <option value="chrome">
</datalist>
```



**keygen(html5)**

**output(html5)**





**fieldset**

- <fieldset>组合表单数据
- <legend>定义标题

## 属性

**form元素所有属性**

```pascal
//实例
<form action="action_page.php" method="GET" target="_blank" accept-charset="UTF-8"
ectype="application/x-www-form-urlencoded" autocomplete="off" novalidate>
.
form elements
 .
</form> 
```

*Here is the list of <form> attributes:*

| 属性             | 描述                                       |
| -------------- | ---------------------------------------- |
| accept-charset | 规定在被提交表单中使用的字符集（默认：页面字符集）。               |
| action         | 规定向何处提交表单的地址（URL）（提交页面）。                 |
| autocomplete   | 规定浏览器应该自动完成表单（默认：开启）。                    |
| enctype        | 规定被提交数据的编码（默认：url-encoded）。              |
| method         | 规定在提交表单时所用的 HTTP 方法（默认：GET）。             |
| name           | 规定识别表单的名称（对于 DOM 使用：document.forms.name）。 |
| novalidate     | 规定浏览器不验证表单。                              |
| target         | 规定 action 属性中地址的目标（默认：_self）。            |

## 输入类型

- text

- radio

- submit

- password  (输入字段不可见)

- checkbox  (radio只能择其一)

- button

  ```html
  <input type="button" onclick="alert('Hello World!')" value="Click Me!">
  ```

**html输入类型**

- color

- date

- datetime

- datetime-local

- email

- month

- number

- range

- search

- tel

- time

- url

- week

  若不被支持则视为text

## 输入属性

- value规定初始值
- readonly 只读 不需要值
- disabled 禁用
- size 字段尺寸，以字符记
- maxlength 最大字段

**html新增**

- autocomplete
- autofocus
- form
- formaction
- formenctype
- formmethod
- formnovalidate
- formtarget
- height 和 width
- list
- min 和 max
- multiple
- pattern (regexp)
- placeholder
- required
- step

并为 <form> 增加如需属性：

- autocomplete
- novalidate
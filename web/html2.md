*HTML5*

[TOC]



# intro

## 新增

[new elements](http://www.w3school.com.cn/html/html5_new_elements.asp)

```html
<!DOCTYPE html>
<html>
  <head>
  <meta charset="UTF-8"/>
  <title>Title</title>    
  </head>
  
  <body>
   Content ... 
  </body>
  
</html>
```

**新特性**

- 新的语义元素，比如 <header>, <footer>, <article>, and <section>。
- 新的表单控件，比如数字、日期、时间、日历和滑块。
- 强大的图像支持（借由 <canvas> 和 <svg>）
- 强大的多媒体支持（借由 <video> 和 <audio>）
- 强大的新 API，比如用本地存储取代 cookie。

**被删元素**

- <acronym>
- <applet>
- <basefont>
- <big>
- <center>
- <dir>
- <font>
- <frame>
- <frameset>
- <noframes>
- <strike>
- <tt>

**新增8个块级元素**

```
header, section, footer, aside, nav, main, article, figure
```

## 迁移

| 典型的 HTML4          | 典型的 HTML5 |
| ------------------ | --------- |
| <div id="header">  | <header>  |
| <div id="menu">    | <nav>     |
| <div id="content"> | <section> |
| <div id="post">    | <article> |
| <div id="footer">  | <footer>  |

# 图形

## Canvas

- 使用javascript在网页上绘图

## SVG

# 媒体

## Audio

**使用插件**

```html
<object height="100" width="100" data="song.mp3"></object>

<embed height="100" width="100" src="/i/horse.mp3"></embed>
```

**audio**

```html
<audio controls="controls">
  <source src="song.mp3" type="audio/mp3" />
  <source src="song.ogg" type="audio/ogg" />
Your browser does not support this audio format.
</audio>
```

**结合**

```html
<audio controls="controls" height="100" width="100">
  <source src="song.mp3" type="audio/mp3" />
  <source src="song.ogg" type="audio/ogg" />
<embed height="100" width="100" src="song.mp3" />
</audio>
```

**yahoo媒体播放器**

```html
<a href="song.mp3">Play Sound</a>

<script type="text/javascript" src="http://mediaplayer.yahoo.com/js">
</script>
```

## Video

```html
<video width="320" height="240" controls="controls">
  <source src="movie.mp4" type="video/mp4" />
  <source src="movie.ogg" type="video/ogg" />
  <source src="movie.webm" type="video/webm" />
  <object data="movie.mp4" width="320" height="240">
    <embed src="movie.swf" width="320" height="240" />
  </object>
</video>
```

**优酷**

上传到优酷，引入链接

```html
<embed src="http://player.youku.com/player.php/sid/XMzI2NTc4NTMy/v.swf" 
width="480" height="400" 
type="application/x-shockwave-flash">
</embed>
```

# html5 API

## 地理位置

## 拖放

## web存储


响应式布局


## viewport 视口

1. 布局视口 = 设备视觉视口
2. 不可缩放

```html
<meta name="viewport" content="width=device-width, user-scalable=no,initial-scale=1.0 ,maximum-scale=1.0,minimum-scale=1.0">

<!-- viewport:说明是视口标签。
width=device-width：宽度是设备宽度。
user-scalable=no：用户不能缩放 -->
```

## 媒体查询

```css

body {
    background-color: black;
}
@media screen and (min-width: 480px) { /* 大于等于480 的情况*/
  body {
    background-color: lightgreen;
  }
@media screen and (min-width: 992px) { /* 大于等于992 的情况*/
  body {
    background-color: pink;
  }
}
```

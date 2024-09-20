---
title: Tailwind CSS
categories: 
tags: 
is_draft: false
date: 2024-04-15
keywords: 
cover: 
description: 
---

## center element

- justify-center: center in horizontal
- items-center: center in vertical
- text-center: center text

```html
<div class="flex justify-center items-center"> </div>
```

## 自定义属性

- --background: 背景颜色，默认设置为HSL色彩空间的值（色相、饱和度、亮度）。
- --foreground: 前景颜色，通常用于文本或其他前置元素。
- --card: 卡片背景颜色。
- --card-foreground: 卡片前景或文本颜色。
- --popover: 弹出框或弹出层的背景颜色。
- --popover-foreground: 弹出框内的文本或元素颜色。
- --primary: 主要品牌颜色，用于突出显示最重要的元素，比如按钮或链接。
- --primary-foreground: 主要颜色元素上的文本颜色。
- --secondary: 次要品牌颜色，用于次重要或补充性的元素。
- --secondary-foreground: 次要颜色元素上的文本颜色。
- --muted: 较低对比度的背景色，用于那些不需要太多关注的区域。
- --muted-foreground: 与较轻背景色配合使用的文本颜色。
- --accent: 强调色，用来吸引用户注意或标示交互元素。
- --accent-foreground: 强调色元素上的文本颜色。
- --destructive: 错误或警告颜色，用以提示危险操作，例如删除按钮。
- --destructive-foreground: 错误或警告元素上的文本颜色。
- --border: 边框颜色。
- --input: 输入框背景色。
- --ring: 焦点环（focus ring）颜色，用来提高可访问性，指示当前聚焦的元素。
- --radius: 元素的圆角大小。
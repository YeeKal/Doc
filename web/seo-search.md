---
title: SEO
categories: 
tags: 
date: 2024-03-19
---

ref : [google seo](https://developers.google.com/search/docs/crawling-indexing/sitemaps/build-sitemap?hl=zh-cn)
- robots.txt
- sitemap
- 关键测
- TDK
- 外链
- 死链
- og
- 重建索引
- www 重定向

## seo tools

- [ahrefs关键字生成器](https://ahrefs.com/zh/keyword-generator/?country=cn&input=%E6%90%9C%E7%B4%A2)
- [外链检查](https://ahrefs.com/zh/backlink-checker/?input=www.shuowen.space&mode=subdomains)
- [aitdk seo 扩展插件](https://aitdk.com/zh-CN/extension/)
- [SimilarWeb]()
- [Internet archive](https://archive.org/): 互联网信息存档

## 外链

## word list

渲染

| 缩写    | 全称                          | 中文名         |
| ------- | ----------------------------- | -------------- |
| **SSG** | **Static Site Generation**    | 静态渲染       |
| **SSR** | **Server Side Rendering**     | 服务端渲染     |
| **CSR** | **Client Side Rendering**     | 客户端渲染     |
| **MRR** | **Monthly Recurring Revenue** | 月度经常性收入 |
|   **ARR**  |    **Annual Recurring Revenue**  |    年度经常性收入            |

## special tags

- [directives in google](https://developers.google.com/search/docs/crawling-indexing/robots-meta-tag#directives)

- noindex: To not show this page in search results.
- nofollow: To not follow the links on this page.

```html
<meta name="robots" content="noindex,nofollow" />
```

Canonical tags: 重复页面的标记标签，标记哪个页面是主要页面



## 内容

- 内链
- 文章结构
    - 标题
    - 关键词加重


## opengraph

```html
<!-- HTML Meta Tags -->
<title>notes thoughts ideas-Yeekal</title>
<meta name="description" content="Yeekal's(yeekal.store)  blog and notes about AI,robotics, and IT technology. 关于人工智能,机器人以及IT技术的博客和笔记。">

<!-- Facebook Meta Tags -->
<meta property="og:url" content="https://yeekal.store">
<meta property="og:type" content="website">
<meta property="og:title" content="notes thoughts ideas-Yeekal">
<meta property="og:description" content="Yeekal's(yeekal.store)  blog and notes about AI,robotics, and IT technology. 关于人工智能,机器人以及IT技术的博客和笔记。">
<meta property="og:image" content="https://opengraph.b-cdn.net/production/documents/016e0c73-7ca3-42ae-8b80-4ca6fbe0b3fa.png?token=lYVxKhb8mr4GSdT5NxCZlq4hqKxqWbeaczTR4qKeSJQ&height=675&width=1200&expires=33249275493">

<!-- Twitter Meta Tags -->
<meta name="twitter:card" content="summary_large_image">
<meta property="twitter:domain" content="yeekal.store">
<meta property="twitter:url" content="https://yeekal.store">
<meta name="twitter:title" content="notes thoughts ideas-Yeekal">
<meta name="twitter:description" content="Yeekal's(yeekal.store)  blog and notes about AI,robotics, and IT technology. 关于人工智能,机器人以及IT技术的博客和笔记。">
<meta name="twitter:image" content="https://opengraph.b-cdn.net/production/documents/016e0c73-7ca3-42ae-8b80-4ca6fbe0b3fa.png?token=lYVxKhb8mr4GSdT5NxCZlq4hqKxqWbeaczTR4qKeSJQ&height=675&width=1200&expires=33249275493">

<!-- Meta Tags Generated via https://www.opengraph.xyz -->
```

- [Twitter Card Tags](https://developer.x.com/en/docs/twitter-for-websites/cards/overview/markup)

## 重建索引

ref: [要求 Google 重新檢索網址](https://developers.google.com/search/docs/crawling-indexing/ask-google-to-recrawl?hl=zh-tw)

1. 少量网页： 使用网址检查工具
2. 大量网页： 使用sitemap 站点地图


![not indexed](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240322102252.png)

**<font color='Tomato'>google index</font>**

- Alternate page with proper canonical tag(带有正确规范标签的替代页面)


## og

rich link preview

示例公众号文章：

![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240328111339.png)

```html

```

## 添加 robots.txt 文件

```txt
User-agent: * Allow: / Disallow: /admin/
sitemap: https://yeekal.store/sitemap.xml
```

## sitemap

1. django 自动生成
2. 使用sitemap生成器
    - [sitemaps](https://xml-sitemaps.com/)
3. 提交给google： https://support.google.com/webmasters/answer/7451001?hl=zh-cn

4. 提交至百度

**<font color='Tomato'>django 生成</font>**

[django sitemaps](https://docs.djangoproject.com/en/5.0/ref/contrib/sitemaps/)


```python
# static
class StaticViewSitemap(sitemaps.Sitemap):
    priority = 0.5
    changefreq = "daily"

    def items(self):
        return ["main", "about", "license"]

    def location(self, item):
        return reverse(item)
# dynamic
from django.contrib.sitemaps import Sitemap
from blog.models import Entry


class BlogSitemap(Sitemap):
    changefreq = "never"
    priority = 0.5

    def items(self):
        return Entry.objects.filter(is_draft=False)

    def lastmod(self, obj):
        return obj.pub_date

#  handle dynamic
# set priority
from django.contrib.sitemaps import Sitemap
from notes.content import getAllPosts
from django.urls import reverse

# static sitemap
class ArticleSitemap(Sitemap):
    changefreq = 'daily'
    priorities = {
        'home': 1.0,
        'notes_home': 1.0,  # 首页的权重设置为最高
        'notes_cate': 0.8,  # 默认分类页面的权重稍低
        'notes_cate_file': 0.64,  # 默认分类页面的权重稍低
        "default": 0.5
    }

    def items(self):

        _, categories = getAllPosts()
        paths = ['home','notes_home']
        for cat in categories:
            paths.append("notes:" + cat['name'])
            paths.extend(["notes:" + cat['name'] + ':' + f[:-3] for f in cat['files']])
        print(paths)
        return paths
    def location(self, item):
        nodes = item.split(":")
        if len(nodes) == 1:
            return reverse(item)
        
        if len(nodes) == 2:
            return reverse('notes_cate', args=[nodes[1]])
        
        if len(nodes) == 3:
            return reverse('notes_cate_file', args=[nodes[1], nodes[2]])

    def priority(self, item):
        nodes = item.split(":")
        if len(nodes) == 1:
            return self.priorities.get(item, self.priorities['default'])
        
        if len(nodes) == 2:
            return self.priorities.get('notes_cate', self.priorities['default'])

        
        if len(nodes) == 3:
            return self.priorities.get('notes_cate_file', self.priorities['default'])

        return self.priorities['default']

```


## 关键词

查找某一话题的关键词

列表类

建议类

最佳的

```
以下是在搜索结果中寻找的一些常见内容角度：
个人体验 → 21 Best Online Marketing Tools That We Use At Ahrefs
最佳的 → 6 Best Marketing Podcasts
专家建议 → 33 Expert-Backed Decluttering Tips
针对初学者 → 17 Blogging Tips For Beginners
具体结果 → 12 Quick SEO Tips to Increase Organic Traffic
久经测试 → 26 Best Free Chrome Extensions for SEOs (Tried & Tested)
新鲜的→ Content Marketing: A Comprehensive Guide For 2021
```

- 标题包含关键词

## 图片

1. 使用描述性文件名。应该使用 cute-puppy.jpg，而不是 IMG_95742.jpg。
2. 添加描述性的替代文本。用几句话描述你的图像，以帮助使用屏幕阅读器的视障用户。
3. 压缩。为此，请使用 ShortPixel 或 EWWW Image Optimizer 等插件。

## TDK


```html
<meta data-vue-meta="1" name="description" content="2月1日，字节跳动在国内正式推出一站式AI Bot开发平台扣子（英文名 Coze）。">
<meta data-vue-meta="1" name="keywords" content="硬科技、新消费、金融创新、新工业、汽车出行、医疗健康、房产新居住、传媒、能源与材料、人工智能、5G、新零售、产业互联网、新居住、在线教育">
<title>上线即崩溃？字节版GPTs「Coze 扣子」发布_亿欧</title>
```

T：Title，页面标题，指代该网站的名称
D：Description，页面描述，用来介绍该网站/页面是什么
K：Keywords，页面关键词


## 外链

## 死链

及时删除


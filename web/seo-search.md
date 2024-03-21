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

## og

rich link preview

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


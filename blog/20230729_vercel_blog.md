---
title: Vercel 国内无法访问? CloudFare 域名解析解除封印！
categories: blog
tags: blog
date: 2023-07-29
---

## Vercel: 搭建个人独立博客

[Vercel](https://vercel.com/) 是知名的网站托管平台，可以高效创建和部署 Web 应用程序，类似于Github pages 和 Netlify. 但远为更加强大，速度也很快。与Github账号连接可以无缝衔接对网站进行构建和部署，并且每次提交commit之后会自动更新网站。

![Vercel](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230729213513.png)

Vercel 免费版提供每月100G的带宽服务，这对于个人简单的博客来说完全够用了。基于其丰富的模板和简捷的部署流程，Vercel成了很多人构建个人博客的首选白嫖方案。

Vercel 支持几乎所有流行的前端框架，在模板库里提供了对应的上手实操小项目。比如我其实对前端不怎么熟悉，在模板库里只认识python.

![vercel template](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230729215730.png)

点进去之后，点击 `Deploy` 就会跳转到部署界面。

![deploy](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230729215918.png)

在该界面会提示用户在个人的Github空间创建一个新的仓库存放代码，之后点击 `Create` 就会真正开始部署。

![vercel_create](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230729220119.png)

完成之后点击网址会看到如下的界面，说明部署完成。虽然页面很简单，但是稍微丰富一下，你就拥有了自己的博客网站，任何人可以随时随地访问。

![vercel_demo](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230729220636.png)

但是，很不幸， Vercel 平台在2021年开始国内断断续续出现无法访问的情况。

然而，幸运的是，互联网是万能的，接下来我们可以通过另一种方式达到曲线救国的目的。

## CloudFlare: 给博客网址开一扇门

CloudFlare 的主流服务是域名解析，简单来说就是当你输入`baidu.com`的时候告诉计算机它所指向的ip地址是什么。这也是一个可以白嫖的网站，因为基础版的域名解析也是免费的。虽然免费，功能却一样不少，甚至更安全更丰富。CloudFare对域名解析的同时提供代理服务，隐藏真实的ip，保护站点免受不法攻击。

Vercel 部署之后会自动生成一个以`vercel.app`为后缀的域名，也支持自定义域名。自定义域名可以通过CloudFare进行域名解析并利用代理服务达到访问Vercel的目的。

之前在阿里云买了一个域名，在阿里云买的域名默认在阿里云设置域名解析。如果要在Cloudflare进行解析，需要在阿里云设置使用Cloudflare的域名解析服务器，之后才可以在Cloudflare设置域名解析。类似于把改名字的权限先移交，再进行改名操作。

![cloudflare_ns](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230730085647.png)

以之前部署的 Astro 博客模板为例。右侧域名 [`yee-blog.vercel.app`](https://yee-blog.vercel.app/) 是默认生成的. 点击上述图片的`Domains`按钮，可以进行修改操作。其中`Edit`只是修改三级域名`yee-blog`的，类似`....vercel.app`的域名依然无法正常访问。这里就需要输入自己的域名并点击`Add`来添加。不过此时自己的域名还没有被解析到，需要先在CloudFare里面添加记录。

![vercel_astro](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230730091425.png)

在 Cloudflare 添加一条`CNAME`类型的解析，比如这个博客模板就是把[`vercel.yeekal.store`](http://vercel.yeekal.store/)重定向到[`yee-blog.vercel.app`](https://yee-blog.vercel.app/)，并打开 proxy 服务。

![cloudflare_cname](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230730092137.png)

此时可以在Vercel里面添加自己的域名，添加之后会进行校验，校验完成就可以通过[`vercel.yeekal.store`](http://vercel.yeekal.store/)进行访问了。

把之前的几篇内容也添加进去了，github同步提交就会更新，非常方便，大家可以访问试一下 https://vercel.yeekal.store/notes (仅作样例，博客还未完善).

![vercel_blog](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/07/20230730093727.png)
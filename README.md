## structure

- _layouts
  - default.html: 网页模板框架，包含_includes中组件
  - post.html: 文章模板, 由文章直接继承
  - page.html: 非文章页面模板
- index.html: 继承default
- about.md: 继承page
- category/index.html: 继承page
- archive/index.html: 继承page
- tag/index.html: 继承page
- page.layout == "page" 查找菜单栏的各选型

## improve

- 高亮
- 首页色块

## reference

- [侧边栏](http://www.thomaszhao.cn/2015/01/08/how-do-i-build-this-jekyll-blog/)
- [github markdown css](https://github.com/sindresorhus/github-markdown-css/blob/gh-pages/github-markdown.css)
- [docsify tutorial](https://blog.csdn.net/weixin_33874713/article/details/88705987)
- [liquid api](https://huang-qing.github.io/github/2017/10/19/GitHub-Jekyll-Liquid-API/)

---
title: 网络爬虫2
categories: python
tags: spider
date: 2023-08-21
---

<!-- <p style="text-align:center;font-size:24px">网络爬虫进阶  -->

- [Beautiful Soup](#beautiful-soup)
- [Selenium](#selenium)
- [scrapy](#scrapy)

异步 代理池

## cookie

- [browser_cookie3](https://github.com/borisbabic/browser_cookie3): Loads cookies used by your web browser into a cookiejar object

```python
>>> import browser_cookie3
>>> import requests
>>> cj = browser_cookie3.chrome()
>>> r = requests.get(url, cookies=cj)
>>> get_title(r.content)
'richardpenman / home &mdash; Bitbucket'
```


## Proxy

- github opensource project
    - [haipproxy](https://spiderclub.github.io/haipproxy/)
    - [proxy_pool](https://github.com/jhao104/proxy_pool)

```python
proxies={
    "http":"<ip>:<port>",
    "https":"<ip>:<port>"
}
requests.get(url, proxies = proxies, verify=False)

```


## 异步 / 协程

iohttp

## requests

```python
# http res

res.content  # binary
res.text    # string
res.json()  # json result
```

## Beautiful Soup

## Selenium

## ​scrapy
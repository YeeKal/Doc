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

## headers

- [fake-useragent](https://github.com/fake-useragent/fake-useragent)

```python
# pip3 install fake_headers
>>> from fake_headers import Headers
>>> headers = Headers(headers=True).generate()
>>> headers
{'Accept': '*/*', 'Connection': 'keep-alive', 'User-Agent': 'Mozilla/5.0 (X11; Linux i686 on x86_64; rv:52.7.1) Gecko/20100101 Firefox/52.7.1', 'Accept-Encoding': 'gzip, deflate, br', 'Upgrade-Insecure-Requests': '1'}
>>> 
```

## Proxy

```python
proxies={
    "http":"<ip>:<port>",
    "https":"<ip>:<port>"
}
requests.get(url, proxies = proxies, verify=False)

```


**<font color='Tomato'>免费代理池</font>**

- github opensource project
    - [haipproxy](https://spiderclub.github.io/haipproxy/)
    - [proxypool: proxy crawer ref](https://github.com/Python3WebSpider/ProxyPool/blob/master/proxypool/crawlers/public/kuaidaili.py)
    - [proxy_pool](https://github.com/jhao104/proxy_pool)
    - [proxy-scraper](https://github.com/iw4p/proxy-scraper/tree/master)
- web
    - [scrapingant](https://app.scrapingant.com/dashboard)





**<font color='Tomato'>云函数代理池</font>**

- [SCFProxy](https://github.com/shimmeris/SCFProxy)

```bash
# http
./scfproxy  deploy http  -p tencent -r ap-*
./scfproxy http -l :8066 -c ~/.config/scfproxy/cert/scfproxy.cer -k ~/.config/scfproxy/cert/scfproxy.key


#  socks
./scfproxy socks -l 8066 -s 8067 -h 118.89.135.45
curl -x socks5://ip:port myip.ipip.net
```

- [install certificate](http://mitm.it/#Linux)

1. deploy on tencent cloud
2. install mitmprocy
    - 安装证书 https://blog.csdn.net/u013091013/article/details/101430260

```bash
openssl x509 -in  mitmproxy-ca-cert.pem -inform PEM -out mitmproxy-ca-cert.crt
```
3. install cer certificate

```bash
sudo cp mycert.cer /usr/share/ca-certificates/mycert.pem
$ sudo dpkg-reconfigure ca-certificates
$ sudo update-ca-certificates
```


## 异步 / 协程

iohttp

**<font color='Tomato'>同步&异步</font>**

```python
cf = partial(singleSkuCheckAsyncProxy, session=session,sku_id=sku, product_id=product)
ff = loop.run_in_executor(None, cf)
```

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

## ref

- [python 爬虫教程](https://www.yuanrenxue.cn/crawler/crawl-app-tricks.html)
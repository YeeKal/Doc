---
title: boost page load speed
categories: 
tags: 
date: 2024-03-19
---
## 速度优化

connection:

1. cloudflare 缓存设置, 若有更新，则手动清楚缓存
2. First Contentful Paint (FCP) 
    优化白屏时间
3. performance 分析
4. gzip 压缩: dajngo gzip   800kb -> 16.5kb  346 ms

```bash
curl -H "Accept-Encoding: gzip" -I https://yeekal.store
>> HTTP/2 200 
>> age: 0
>> cache-control: public, max-age=0, must-revalidate
>> content-encoding: gzip
>> content-type: text/html; charset=utf-8
>> cross-origin-opener-policy: same-origin
>> date: Wed, 20 Mar 2024 09:05:38 GMT
>> referrer-policy: same-origin
>> server: Vercel
>> strict-transport-security: max-age=63072000
>> vary: Accept-Encoding
>> x-content-type-options: nosniff
>> x-frame-options: DENY
>> x-vercel-cache: MISS
>> x-vercel-id: hkg1::iad1::dzjc2-1710925538674-8d3d6969ec45
```

- reduce search data size:
    - 1.83s -> 1.85s
    - size 87kb -> 27kb
- blog data cache
- Expires headers
- vercel cache

```
 "rewrites": [
    { "source": "/:url*", "destination": "https://www.wgzdy.top/:url*" }
  ],
"headers": [
      {
        "source": "/static/(.*)",
        "headers": [
          {
            "key": "Cache-Control",
            "value": "public, max-age=36000, must-revalidate"
          }
        ]
      }
    ]
```

## test tool

- [Pingdom Website Speed Test](https://tools.pingdom.com/)
- [PageSpeed Insights](https://pagespeed.web.dev/)

|     |  PageSpeed   |  Pingdom   |
| --- | --- | --- |
| 20240319    | ![PageSpeed test](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240319190939.png)    |  ![Pingdom test](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240319190837.png)   |
| 20240320    | ![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240320214342.png)    |  ![](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240320214558.png)  |

**<font color='Tomato'>chrome Performance tool</font>**

- Loading ：加载时间
- Scripting ：js计算时间
- Rendering ：渲染时间
- Painting ：绘制时间
- Other ：其他时间
- Idle ：浏览器闲置时间

![chrome Performance tool](https://cdn.jsdelivr.net/gh/YeeKal/img_land/blog/24/03/20240319191213.png)





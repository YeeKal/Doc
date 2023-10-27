---
title: 网络爬虫3
categories: 
tags: 
date: 2023-10-16
---

##  Setting up a proxy server


```bash
# squid  https://cuiqingcai.com/2022104.html

```

## adsl 拨号 代理

- [tutorial 1](https://cuiqingcai.com/2022104.html)
- [ADSLProxyPool code example](https://github.com/Germey/ADSLProxyPool)
    - [corresponding blog](https://cuiqingcai.com/4596.html)

```bash
#  https://asiyun.cn/user/selfvps2all.asp
ssh -p <port> 

#  change ip
pppoe-stop;pppoe-start

#  os prepare
sudo yum -y update
yum -y install tmux git 
yum install -y python3-pip
bash 高亮
tmux 安装

#  install squid
https://cuiqingcai.com/2022104.html
yum -y install squid
systemctl start squid
systemctl enable squid # 开机自启动
systemctl status squid


vim /etc/squid/squid.conf
http_access deny all ->  http_access allow all
acl all src 0.0.0.0/0

request_header_access Via deny all
request_header_access X-Forwarded-For deny all

port: 8010
```

## ECS 实例

## bloomfilter 内存优化

## TLS 指纹

- [curl_cffi](https://zhuanlan.zhihu.com/p/601474166)

## redis

ubuntu

```bash
#  install and start
udo apt update
sudo apt install redis-server
sudo systemctl status redis-server

# remote access
sudo vim /etc/redis/redis.conf
bind 127.0.0.1 ::1 -> bind 0.0.0.0 ::1
sudo systemctl restart redis-server  # restart
systemctl status redis-server
# open tcp access from 6379

# test
redis-cli -h <REDIS_IP_ADDRESS> ping
-> PONG
```
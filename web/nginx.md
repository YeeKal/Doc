---
title: nginx 
categories: 
tags: 
date: 2024-03-12
---

- http 和https的同步配置
- 路径

## https 发起http 跨域请求

在Nginx中，你可以配置服务器来接收HTTPS请求，并将这些请求转发到HTTP后端。这通常涉及到设置一个SSL/TLS终端，以及配置代理来转发请求。以下是具体的步骤和配置示例：

步骤 1: 生成SSL/TLS证书
首先，你需要为Nginx服务器生成SSL/TLS证书。你可以使用Let's Encrypt免费获取证书，或者使用自签名证书进行测试。以下是使用OpenSSL生成自签名证书的基本命令：

openssl genrsa -out privkey.pem 2048
openssl req -new -x509 -key privkey.pem -out cert.pem -days 365
这将生成一个私钥（privkey.pem）和一个自签名证书（cert.pem），有效期为365天。

步骤 2: 配置Nginx
接下来，你需要配置Nginx来接收HTTPS请求，并将它们转发到HTTP后端。以下是一个基本的Nginx配置示例：

# 基本的HTTP服务器配置
server {
    listen 80;
    server_name example.com; # 你的域名

    location / {
        proxy_pass http://your_http_backend; # 你的HTTP后端地址
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }
}

# HTTPS服务器配置
server {
    listen 443 ssl;
    server_name example.com; # 你的域名

    # SSL证书和密钥的路径
    ssl_certificate /path/to/cert.pem;
    ssl_certificate_key /path/to/privkey.pem;

    # 可选的SSL配置
    ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
    ssl_ciphers HIGH:!aNULL:!MD5;

    location / {
        # 转发到HTTP后端
        proxy_pass http://your_http_backend;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
    }
}
请确保将/path/to/cert.pem和/path/to/privkey.pem替换为你的证书和私钥的实际路径，以及将example.com替换为你的实际域名或服务器地址。

```bash
#  restart nginx
sudo service nginx restart
```

## 遇到的问题

- fastapi 跨域请求
- nginx https
- axios http 强制转换为https
- axios 异步

## cloudflare 生成ssl证书

ssl -> origin server -> create 


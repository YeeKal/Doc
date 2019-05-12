---
title: linux command
categories: linux
tags: linux
date: 2019-04-02
---

1. install .deb 

dpkg -i xxxx.deb

2. .desktop 快捷方式

/usr/share/aplications

3. pip change source list

pip install <package> -i <source-url>

- 清华大学 https://pypi.tuna.tsinghua.edu.cn/simple/
- 阿里云 http://mirrors.aliyun.com/pypi/simple/
- 中国科技大学 https://pypi.mirrors.ustc.edu.cn/simple/
- 豆瓣(douban) http://pypi.douban.com/simple/
- 中国科学技术大学 http://pypi.mirrors.ustc.edu.cn/simple/

4. add chinese input method

- ibus: sudo ibus-setup
- fctix: 
	- https://www.cnblogs.com/voyagee/p/6898054.html

5. ubuntu & shadowsocks

- command line: sslocal -c /etc/shadowsocks/config.json
- open chrome with proxy: google-chrome --proxy-server="socks5://127.0.0.1:1080"

- gui: https://github.com/shadowsocks/shadowsocks-qt5/releases

6.  ss+chrome 

- sslocal -c /etc/shadowsocks/config.json
- google-chrome-stable --proxy-server="socks5://127.0.0.1:1080"

7. cannot connect wifi
	
- update kernel from 4.4 to 4.13




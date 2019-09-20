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

8. git 下载速度

- 配置socks代理：

git config --global https.proxy 'socks5://127.0.0.1:1080'

9. vscode 配置

- 官网下载.deb
- 

10. linux 实时内核补丁

- [patch](https://mirrors.edge.kernel.org/pub/linux/kernel/projects/rt/)
- [kernel in tsinghua]
- ref to [csdn1](https://blog.csdn.net/x356982611/article/details/77370385)

11. set priority

- [ref1:set real time attributes](https://www.cyberciti.biz/faq/howto-set-real-time-scheduling-priority-process/)
- [ref2: 处理nice与priority](https://ubuntuqa.com/article/1176.html)
- [ref3: build a simple rt application](https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/application_base)
- set real time:'chrt -f -p [1-99] {pid}'

12. screenshot via ssh

- xwd -out <name>.xwd -root -display :0.0

13. openrave

- [ref1](https://scaron.info/teaching/installing-openrave-on-ubuntu-16.04.html)
- [ref2](https://fsuarez6.github.io/blog/workstation-setup-xenial/)

14. ros-move_group died

- when affine3d converted to geometry_msgs::pose, this fault will occur if the rotation in affine3d is not the standard rotation matrix

15 mp4 to gif

- apt-get install mplayer
- apt-get install imagemagick
- mplayer -ao null xxxx.mp4 -vo jpeg:outdir=output	//生成jpeg文件
- convert output/*.jpg -resize 45% output/view.gif	//生成gif文件
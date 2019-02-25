---
title: git command
categories: linux
tags: linux
date: 2018-01-15
---

> git init

initialize a repository and the existing file will remain.

> git remote add orogin git@github.com:YeeKal/yeebot.git

将本地仓库和远程仓库连接起来。

> git clone

```python
git remote  #list all remote 
git remote -v #参看远程主机的网址
git remote rm <remote-name> #delete
git remote add <remote-name> <address>
git remote rename <old-name> <new-name>
```

```python
git checkout -b <new-branch> #等同下面两条
git branch <new-branch>  #新建
git branch -vv #查看各个分支追踪关系
git checkout <new-branch>  ##切换
```



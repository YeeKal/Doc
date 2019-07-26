---
title: git command
categories: linux
tags: linux
date: 2018-01-15
---

## git init

initialize a repository and the existing file will remain.

> git remote add origin git@github.com:YeeKal/yeebot.git

将本地仓库和远程仓库连接起来。

## git clone

```python
git remote  #list all remote 
git remote -v #参看远程主机的网址
git remote rm <remote-name> #delete
git remote add <remote-name> <address>
git remote rename <old-name> <new-name>
```

```python
#切换分支
git checkout -b <new-branch> #等同下面两条
git branch <new-branch>  #新建
git branch -vv #查看各个分支追踪关系
git checkout <new-branch>  ##切换

#本地创建新分支关联远程
git checkout -b <new branch>  #create local branch
git branch -vv  #show the local branch connection relationship
git push origin <new branch>  #create new branch in remote
git branch --set-upstream-to=origin/<new branch>  #create new connection

#删除分支
git branch -d <dev> #删除本地分支
git push origin --delete <dev> #删除远程分支
```


## git fetch

```python
git fetch origin master #取回远程master分支更新到本地，但不会merge
git merge origin/master #本地分支合并远程分支，origin/master鄙视远程分支在本地的历史记录
git rebase origin/master #若本地也做了更改，则将本地更改放在远程更新之后
git

```
## git pull

```python
git pull <远程主机名> <远程分支名>:<本地分支名> #取回远程分支并合并
```

## 更新远程分支信息
```
git remote update origin --prune

```

## git merge

```python
git checkou	master  #switch to mster branch
git merge <sub branch>  #merge sub branch to master branch
git push origin mster		#push remote

```

## big file

若在push过程中由于监测到大文件而push失败，则
1. 大文件不跟踪
```python
git rm --cached <big_file_name>
git commit --amend -CHEAD
git push
```

2. 突破大文件限制
```python
# install lfs
sudo apt install linuxbrew-wrapper
brew install git-lfs

# handle giant files
git lfs track "FrameworkFold/XXXFramework/xxx"
#常规的push操作
git add .
git commit -m "add large file"
git push

#追踪单个文件：
git lfs track "FrameworkFold/XXXFramework/xxx"
#追踪指定类型的文件：
git lfs track "*.exe"
#追踪指定目录下的文件：
git lfs track "FrameworkFold/*"

```



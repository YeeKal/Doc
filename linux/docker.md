---
title: docker 使用
categories: linux
tags: linux
date: 2022-05-30
---

```bash
docker rm <id>  # delete container id
docker rmi <id>  # delete image id
docker rmi $(docker images |grep sim |awk '{print $3;}' )  # batch delete

docker ps
docker top b42f2f2bc562
```
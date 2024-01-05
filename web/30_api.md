---
title: API collections
categories: 
tags: 
date: 2023-09-06
---

## Slack

## vercel  as proxy

- [vercel-api-prox](https://github.com/souying/vercel-api-proxy)

## Zapier

## cloudfare worker

## telegram bot

## discord bot 

## Notion API

- [developers.notion](https://developers.notion.com/)
- [python notion client](https://github.com/ramnes/notion-sdk-py)

- config:
    - add integration
    - add connection 
    - code
- ref
    - [getting-started-with-python](https://www.pynotion.com/getting-started-with-python)
    - [how-to-use-python-with-notion-api](https://dev.to/mihaiandrei97/how-to-use-python-with-notion-api-1n61)

example:

**<font color='Tomato'>Example: read database</font>**

```python
import json
import requests

token = '<secret>'
database_id = 'b8e06af88a7d4c9394a1e6a09a50708a'


def readDatabase():
    url = f'https://api.notion.com/v1/databases/{database_id}/query'

    r = requests.post(url, headers={
        "Authorization": f"Bearer {token}",
        "Notion-Version": "2022-06-28",
        "Content-Type": "application/json"
    })

    return r

r = readDatabase()

res = r.json()
for i in res["results"]:
    print("{}  {}".format(i['properties']['key']['rich_text'][0]['text']['content'], i['properties']['Name']['title'][0]['text']['content']))

```

**<font color='Tomato'>远程数据同步</font>**

- [notion2pg](https://github.com/aaugustin/notion2pg/tree/main)

## 微信



**<font color='Tomato'>企业微信</font>**

**<font color='Tomato'>公众号</font>**

- 配置过程
    - 服务器配置
    - 验证
    - 回复消息
- ref:
    - [基础消息能力 /被动回复用户消息](https://developers.weixin.qq.com/doc/offiaccount/Message_Management/Passive_user_reply_message.html)
    - [模板消息](https://developers.weixin.qq.com/doc/offiaccount/Message_Management/Template_Message_Interface.html)
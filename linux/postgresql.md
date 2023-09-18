---
title: postgresqpl notes
categories: linux
tags: linux
date: 2023-08-15
---

## install 

## Usage

```shell
sudo -i -u postgres 
psql

CREATE DATABASE myproject;
CREATE USER yee WITH PASSWORD 'password';
ALTER ROLE yee SET client_encoding TO 'utf8';
ALTER ROLE yee SET default_transaction_isolation TO 'read committed';
ALTER ROLE yee SET timezone TO 'UTC';

GRANT ALL PRIVILEGES ON DATABASE myproject TO myprojectuser;
```

## python api with psycopg2

```python
# -*- coding: utf-8 -*-
'''
pip3 install psycopg2
'''
import psycopg2
import time


DB_HOST=""
DB_USER=""
DB_NAME=""
DB_PORT=""
DB_PASSWORD=""

# 获得连接
t1 = time.time()
conn = psycopg2.connect(database=DB_NAME, user=DB_USER, password=DB_PASSWORD, host=DB_HOST, port=DB_PORT)
# 获得游标对象
cursor = conn.cursor()
elapsed_time = time.time() - t1
print("connect elapsed time:{:.3f}".format(elapsed_time))

def getSQL(sql):
    # 执行语句
    cursor.execute(sql)
    # 获取单条数据.
    data = cursor.fetchall()
    return data
# 打印
data = getSQL("SELECT VERSION()")
print("database version : %s " % data)

t1 = time.time()
data = getSQL("SELECT * FROM notes_notes;")
elapsed_time = time.time() - t1

print("{:.3f}s get notes_notes : {} ".format(elapsed_time,len(data)))


# 事物提交
conn.commit()
# 关闭数据库连接
conn.close()
```
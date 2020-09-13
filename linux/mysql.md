---
title: mysql learning
categories: linux
tags: mysql
date: 2020-06-21
---

## install in ubuntu

```python
> mysql
# The program 'mysql' can be found in the following packages:
#  * mysql-client-core-5.7
#  * mariadb-client-core-10.0
# Try: sudo apt install <selected package>
> sudo apt install mysql-client-core-5.7
> sudo apt install mariadb-client-core-10.0
> sudo apt-get install mysql-server

# 验证
# 如果看到有mysql 的socket处于 listen 状态则表示安装成功
> sudo netstat -tap | grep mysql
```

## command

```python
# login
$ mysql -u root -p
$ mysql -h localhost -u root -p

# service start/stop
service mysql start | service mysql stop | service mysql start
/etc/inint.d/mysql start # start with script

# check port
netstat -tl | grep mysql

"""
common 
"""
create database new_dbname;--新建数据库
drop database old_dbnane; --删除数据库
show databases;--显示数据库
use databasename;--使用数据库
select database();--查看已选择的数据库

show tables;--显示当前库的所有表
create table tablename(fieldname1 fieldtype1,fieldname2 fieldtype2,..)[ENGINE=engine_name];--创建表
drop table tablename; --删除表
create table tablename select statement;--通过子查询创建表
desc tablename;--查看表结构
show create table tablename;--查看建表语句

alter table tablename add new_fielname new_fieldtype;--新增列
alter table tablename add new_fielname new_fieldtype after 列名1;--在列名1后新增列
alter table tablename modify fieldname new_fieldtype;--修改列
alter table tablename drop fieldname;--删除列
alter table tablename_old rename tablename_new;--表重命名

insert into tablename(fieldname1,fieldname2,fieldnamen) valuse(value1,value2,valuen);--增
delete from tablename [where fieldname=value];--删
update tablename set fieldname1=new_value where filename2=value;--改
select * from tablename [where filename=value];--查

truncate table tablename;--清空表中所有数据，DDL语句

show engines;--查看mysql现在已提供的存储引擎:
show variables like '%storage_engine%';--查看mysql当前默认的存储引擎
show create table tablename;--查看某张表用的存储引擎（结果的"ENGINE="部分）
alter table tablename ENGINE=InnoDB--修改引擎
create table tablename(fieldname1 fieldtype1,fieldname2 fieldtype2,..) ENGINE=engine_name;--创建表时设置存储引擎

# 数据库 memory
# 1，切换数据库
use `information_schema`;

#2，查看数据库使用大小
select concat(round(sum(data_length/1024/1024),2),'MB') as data from tables where table_schema='DB_Name' ;

#3，查看表使用大小
select concat(round(sum(data_length/1024/1024),2),'MB') as data from tables where table_schema='DB_Name' and table_name='Table_Name';
```
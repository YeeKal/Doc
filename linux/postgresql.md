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
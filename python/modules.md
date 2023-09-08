---
title: 常用模块
categories: python
tags: python
date: 2023-09-06
---

## logging

```python
#     format参数中可能用到的格式化串
#     %(name)s Logger的名字
#     %(levelno)s 数字形式的日志级别
#     %(levelname)s 文本形式的日志级别
#     %(pathname)s 调用日志输出函数的模块的完整路径名，可能没有
#     %(filename)s 调用日志输出函数的模块的文件名
#     %(module)s 调用日志输出函数的模块名
#     %(funcName)s 调用日志输出函数的函数名
#     %(lineno)d 调用日志输出函数的语句所在的代码行
#     %(created)f 当前时间，用UNIX标准的表示时间的浮 点数表示
#     %(relativeCreated)d 输出日志信息时的，自Logger创建以 来的毫秒数
#     %(asctime)s 字符串形式的当前时间。默认格式是 “2003-07-08 16:49:45,896”。逗号后面的是毫秒
#     %(thread)d 线程ID。可能没有
#     %(threadName)s 线程名。可能没有
#     %(process)d 进程ID。可能没有
#     %(message)s用户输出的消息

import logging

def getLogger(name, print_screen: bool, log_level = logging.ERROR, log_file_path = None):
    # Create a custom logger
    logger = logging.getLogger(name)
    log_format = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s %(filename)s %(funcName)s[line:%(lineno)d] - %(message)s', datefmt='%Y-%m-%d %H:%M:%S')


    # Create handlers
    c_handler = logging.StreamHandler()
    c_handler.setLevel(log_level)
    c_handler.setFormatter(log_format)

    f_handler = None
    if log_file_path is not None:
        f_handler = logging.FileHandler(log_file_path)
        f_handler.setLevel(log_level)
        f_handler.setFormatter(log_format)


    # Add handlers to the logger
    if f_handler is not None:
        logger.addHandler(f_handler)
    if print_screen:
        logger.addHandler(c_handler)

    if not print_screen and f_handler is None:
        logger.addHandler(c_handler)
    
    logger.setLevel(log_level)

    return logger

if __name__ == "__main__":
    logger = getLogger("haha", print_screen = True, log_level=logging.INFO)
    logger.debug("haha1")
    logger.info("haha2")
    logger.error("haha")
```
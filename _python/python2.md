[TOC]

# Level2

# I/O

## read&write

```python
#read
f = open('/Users/michael/test.txt', 'r')#无则IOError
pass
f.close()
#防止错误
with open('/path/to/file', 'r') as f:
    pass
f.read() #read all
f.read(int) #read for size
f.readline()#read by lines
f.readlines()# return to a list with all lines

```

```python
#open
r:read
w:write#若文件存在则文件长度清为0若文件不存在则建立该文件
a:add#若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾
b:binary
+:read&write
'rb'#读取图片。视频等二进制文件
```

```python
#write
#紧接着写，没有换行
#return the lenth of str
```

> 文件流/io流  read/write-file like

## 内存读写

> StringIO和BytesIO是在内存中操作str和bytes的方法，使得和读写文件具有一致的接口

```python
#StringIO
>>> from io import StringIO
f = StringIO('Hello!\nHi!\nGoodbye!')#默认值初始化
>>> f = StringIO()		#DEFINITION
>>> f.write('hello')	#WRITE
5
>>> f.write(' ')
1
>>> f.write('world!')
6
>>> print(f.getvalue())	#GET ALL STR
hello world!

```

```python
#BytesIO
>>> from io import BytesIO
>>> f = BytesIO()
>>> f.write('中文'.encode('utf-8'))
6
>>> print(f.getvalue())
b'\xe4\xb8\xad\xe6\x96\x87
```

## 文件和目录

```python
#os
import os
os.name#posix:Linux,Unix,Mac OS/nt:windows
os.environ#环境变量
os.environ.get('key')#get the path with name:key
os.path.abspath('.')#当前目录绝对路径
os.path.join(str,str)#join path
os.mkdir(path)#create one file
>>> os.path.split('/Users/michael/testdir/file.txt')
('/Users/michael/testdir', 'file.txt')
>>> os.path.splitext('/path/to/file.txt')
('/path/to/file', '.txt')
os.rename('test.txt', 'test.py')
os.remove('test.py')
```

## 序列化

```python
>>> import pickle
>>> d = dict(name='Bob', age=20, score=88)
>>> f=open('dump.txt','wb')
#pickle.dumps(d),把任意对象序列化成一个bytes
>>> pickle.dump(d,f)#序列化对象并存入一个file-like object
>>> f.close()
>>> f=open('dump.txt','rb')
>>> d=pickle.load(f)	#反序列化
>>> f.close()
>>> d
{'score': 88, 'name': 'Bob', 'age': 20}
```

> json:把对象序列化为标准格式.JSON表示出来就是一个字符串，可以被所有语言读取，也可以方便地存储到磁盘或者通过网络传输。JSON不仅是标准格式，并且比XML更快，而且可以直接在Web页面中读取，非常方便。

| JSON类型     | Python类型   |
| ---------- | ---------- |
| {}         | dict       |
| []         | list       |
| "string"   | str        |
| 1234.56    | int或float  |
| true/false | True/False |
| null       | None       |

```python
import ison
>>> d = dict(name='Bob', age=20, score=88)
>>> json.dumps(d)
'{"age": 20, "score": 88, "name": "Bob"}'
#json.dump()#write in file-like object
json.lodes()#反序列化
json.lode()#from file-like object 反序列化

#json序列化类
```

# 进程和线程

> 进程（process），子任务->线程（thread）
>
> 单任务的进程，也就是只有一个线程
>
> 多任务：
>
> - 多进程模式；
> - 多线程模式；
> - 多进程+多线程模式；
>
> Python既支持多进程，又支持多线程
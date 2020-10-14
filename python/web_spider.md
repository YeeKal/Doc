**WebSpider**

[TOC]

# 爬虫了解

## what is url

URL:

​	 Uniform Resource Locator,统一资源定位符,URI的一个子集

格式

​	protocol :// hostname[:port] / path / [;parameters][?query]#fragmentURL三部分组成： 

> ①第一部分是协议(或称为服务方式)。
>
> ②第二部分是存有该资源的主机IP地址(有时也包括端口号)。
>
> ③第三部分是主机资源的具体地址，如目录和文件名等。
>
> - 第一部分和第二部分用“://”符号隔开，第二部分和第三部分用“/”符号隔开。第一部分和第二部分是不可缺少的，第三部分有时可以省略

 

## 进阶之路

1. 基本原理

 ​urllib:

  	a package  that collects several modules for working with URLs 

 ​	python2中的urllib和urllib统一python3中的urllib

 ​re:

2. 爬虫利器

 ​requests

 ​Beautifulsoup  [官方文档](http://beautifulsoup.readthedocs.io/zh_CN/latest/)

 ​Selenium 模拟浏览器提交类似用户的操作，处理js动态产生的网页

 ​scrapy

3. 数据存储
4. 分布式/多线程

# urllib

## urllib 简介

- urllib.request可以用来发送request和获取request的结果
- urllib.error包含了urllib.request产生的异常
- urllib.parse用来解析和处理URL
- urllib.robotparse用来解析页面的robots.txt文件

## urllib.request

​	提供最基本的构造http请求的方法，它可以模拟浏览器的一个请求发起过程

```python
#urllib.request.urlopen
response = urllib.request.urlopen('https://www.python.org')	#HTTPResponse 		类的对象
	#methods：
    read()、readinto()、getheader(name)、getheaders()、fileno()
    #属性
    msg、version、status、reason、debuglevel、closed
    status: #200,success;404 未找到网页
    response.read().decode('utf-8')
urllib.request.urlopen(url, data=None, [timeout, ]*, cafile=None,	     		capath=None, cadefault=False, context=None) 
	data#data = bytes(urllib.parse.urlencode({'word': 'hello'}), 					encoding='utf8') 
    timeout#超过请求时间则忽略，抛出time out 错误
```

```python
#urllib.request.Request
request = urllib.request.Request('https://python.org')
response = urllib.request.urlopen(request)	#利用更强大的Request类来构建一个请求
#参数
class urllib.request.Request(url, data=None, headers={}, origin_req_host=None, 		unverifiable=False, method=None)
	#headers:字典，add_header()方法来添加请求头，伪装浏览器
	#origin_req_host:请求方的host名称或者IP地址
    #unverifiable: 这个请求是不是无法验证的，默认是False
    #method：请求使用的方法，GET,POST,PUT
```

## urllib.request的高级特性

> BaseHandler:父类
>
> - `HTTPDefaultErrorHandler`用于处理HTTP响应错误，错误都会抛出`HTTPError`类型的异常。
> - `HTTPRedirectHandler`用于处理重定向。
> - `HTTPCookieProcessor`用于处理`Cookie`。
> - `ProxyHandler`用于设置代理，默认代理为空。
> - `HTTPPasswordMgr`用于管理密码，它维护了用户名密码的表。
> - `HTTPBasicAuthHandler`用于管理认证，如果一个链接打开时需要认证，那么可以用它来解决认证问题

```python
#认证
    #创建handler——添加属性——build_opener——install_opener——urlopen
auth_handler = urllib.request.HTTPBasicAuthHandler()
auth_handler.add_password(realm='PDQ Application',
                          uri='https://mahler:8092/site-updates.py',
                          user='klem',
                          passwd='kadidd!ehopper')
opener = urllib.request.build_opener(auth_handler)
urllib.request.install_opener(opener)
urllib.request.urlopen('http://www.example.com/login.html')
#代理
proxy_handler = urllib.request.ProxyHandler({
    'http': 'http://218.202.111.10:80',
    'https': 'https://180.250.163.34:8888'
})	#参数是一个字典，key是协议类型，比如http还是https等，value是代理链接，可以添加	多个代理
opener = urllib.request.build_opener(proxy_handler)
response = opener.open('https://www.baidu.com')
print(response.read())
#cookies
filename = 'cookie.txt'
cookie = http.cookiejar.MozillaCookieJar(filename)
#cookie = http.cookiejar.LWPCookieJar(filename)	
	#保存格式不一样
handler = urllib.request.HTTPCookieProcessor(cookie)
opener = urllib.request.build_opener(handler)
response = opener.open('http://www.baidu.com')
cookie.save(ignore_discard=True, ignore_expires=True)
```

## urllib.error

> urllib.error.URLError
>
> urllib.error.HTTPError
>
> - code
> - reason
> - headers
>
> ```python
> try:
>     response=request.urlopen('http://cuiqingcai.com/index.htm')
>     print(response)
> except error.HTTPError as e:
>     print(e.reason,e.code,e.headers,sep='\n')
> finally:
>     print('this must process')
> print('then how about this?')
> ```
>
> *更优质的写法，先写HTTPError子类，再加上父类*
>
> ```python
> try:
>     response = request.urlopen('http://cuiqingcai.com/index.htm')
> except error.HTTPError as e:
>     print(e.reason, e.code, e.headers, sep='\n')
> except error.URLError as e:
>     print(e.reason)
> else:
>     print('Request Successfully')
> ```
>
> *e.reason`返回的不一定是字符串*
>
> *设置超时时间*
>
> ```python
> import socket
> import urllib.request
> import urllib.error
>
> try:
>     response = urllib.request.urlopen('https://www.baidu.com', timeout=0.01)
> except urllib.error.URLError as e:
>     print(type(e.reason))
>     if isinstance(e.reason, socket.timeout):
>         print('TIME OUT')
> ```

## http状态码

| 状态码  | 说明        | 详情                                 |
| ---- | --------- | ---------------------------------- |
| 100  | 继续        | 请求者应当继续提出请求。服务器已收到请求的一部分，正在等待其余部分。 |
| 101  | 切换协议      | 请求者已要求服务器切换协议，服务器已确认并准备切换。         |
| 200  | 成功        | 服务器已成功处理了请求。                       |
| 201  | 已创建       | 请求成功并且服务器创建了新的资源。                  |
| 202  | 已接受       | 服务器已接受请求，但尚未处理。                    |
| 203  | 非授权信息     | 服务器已成功处理了请求，但返回的信息可能来自另一来源。        |
| 204  | 无内容       | 服务器成功处理了请求，但没有返回任何内容。              |
| 205  | 重置内容      | 服务器成功处理了请求，内容被重置。                  |
| 206  | 部分内容      | 服务器成功处理了部分请求。                      |
| 300  | 多种选择      | 针对请求，服务器可执行多种操作。                   |
| 301  | 永久移动      | 请求的网页已永久移动到新位置，即永久重定向。             |
| 302  | 临时移动      | 请求的网页暂时跳转到其他页面，即暂时重定向。             |
| 303  | 查看其他位置    | 如果原来的请求是POST，重定向目标文档应该通过GET提取。     |
| 304  | 未修改       | 此次请求返回的网页未修改，继续使用上次的资源。            |
| 305  | 使用代理      | 请求者应该使用代理访问该网页。                    |
| 307  | 临时重定向     | 请求的资源临时从其他位置响应。                    |
| 400  | 错误请求      | 服务器无法解析该请求。                        |
| 401  | 未授权       | 请求没有进行身份验证或验证未通过。                  |
| 403  | 禁止访问      | 服务器拒绝此请求。                          |
| 404  | 未找到       | 服务器找不到请求的网页。                       |
| 405  | 方法禁用      | 服务器禁用了请求中指定的方法。                    |
| 406  | 不接受       | 无法使用请求的内容响应请求的网页。                  |
| 407  | 需要代理授权    | 请求者需要使用代理授权。                       |
| 408  | 请求超时      | 服务器请求超时。                           |
| 409  | 冲突        | 服务器在完成请求时发生冲突。                     |
| 410  | 已删除       | 请求的资源已永久删除。                        |
| 411  | 需要有效长度    | 服务器不接受不含有效内容长度标头字段的请求。             |
| 412  | 未满足前提条件   | 服务器未满足请求者在请求中设置的其中一个前提条件。          |
| 413  | 请求实体过大    | 请求实体过大，超出服务器的处理能力。                 |
| 414  | 请求URI过长   | 请求网址过长，服务器无法处理。                    |
| 415  | 不支持类型     | 请求的格式不受请求页面的支持。                    |
| 416  | 请求范围不符    | 页面无法提供请求的范围。                       |
| 417  | 未满足期望值    | 服务器未满足期望请求标头字段的要求。                 |
| 500  | 服务器内部错误   | 服务器遇到错误，无法完成请求。                    |
| 501  | 未实现       | 服务器不具备完成请求的功能。                     |
| 502  | 错误网关      | 服务器作为网关或代理，从上游服务器收到无效响应。           |
| 503  | 服务不可用     | 服务器目前无法使用。                         |
| 504  | 网关超时      | 服务器作为网关或代理，但是没有及时从上游服务器收到请求。       |
| 505  | HTTP版本不支持 | 服务器不支持请求中所用的 HTTP 协议版本。            |

## urllib.parse

urllib.parse.urlparse(*urlstring*, *scheme=''*, *allow_fragments=True*)

> 一个标准链接分成6部分
>
> scheme://netloc/path;parameters?query#fragment
>
> allow_fragments 若设为False,`fragment`部分就会被忽略,被解析成其他项的一部分

urllib.parse.urlunparse()

> list or tuple必须接收6个参数，可以为空
>
> ```python
> data = ['http', 'www.baidu.com', 'index.html', 'user', 'a=6', 'comment']
> print(urlunparse(data))
> ```

urllib.parse.urlsplit()

> 将parameters合并到path中

urllib.parse.urlunsplit()

urllib.parse.urljoin(base,url,allow_fragments=True)

>`base_url`提供了三项内容，`scheme`、`netloc`、`path`，如果这三项在新的链接里面不存在，那么就予以补充，如果新的链接存在，那么就使用新的链接的部分。`base_url`中的`parameters`、`query`、`fragments`是不起作用的

## 模拟登陆

http消息:get/post

get:

1. cookies加入到headers（简单网页，无需验证码）
2. ​



# RegularExpressions

## 相关注解

数量词的贪婪模式

> 正则表达式通常用于在文本中查找匹配的字符串。Python 里数量词默认是贪婪的（在少数语言里也可能是默认非贪婪），总是尝试匹配尽可能多的字符；非贪婪的则相反，总是尝试匹配尽可能少的字符。例如：正则表达式 ”ab\*” 如果用于查找 ”abbbc”，将找到 ”abbb”。而如果使用非贪婪的数量词 ”ab*?”，将找到 ”a”
>
> 我们一般用非贪婪模式

反斜杠

> 原生字符串：r“d”
>
> 取消python本身的转换

## re

> - re.**compile**(string[,flag])  
> - re.**match**(pattern, string[, flags])
> - re.**search**(pattern, string[, flags])
> - re.**split**(pattern, string[, maxsplit])
> - re.**findall**(pattern, string[, flags])
> - re.**finditer**(pattern, string[, flags])
> - re.**sub**(pattern, repl, string[, count])
> - re.**subn**(pattern, repl, string[, count])

```python
pattern=re.compile(patter,flags=0)
#pattern='<string>'
re.match(pattern,string,flags=0)
	#prog = re.compile(pattern)
	#result = prog.match(string)
    #必须从开始处匹配，否则返回 None
re.search(pattern,string,flags=0)
```

```python
re.split(pattern, string, maxsplit=0,flags=0)
re.findall(pattern,string,flags=0)
re.finditer(pattern,string,flags=0)	#return to a iterator
re.sub(pattern, repl, string, count=0, flags=0)	
	#repl可以是字符串，函数，顺序模板
    #count 用于指定最多替换次数，不指定时全部替换
re.subn(pattern, repl, string, count=0, flags=0)
	#返回 字符串和替换次数组成的元祖
```

| 修饰符  | 描述                                      |
| ---- | --------------------------------------- |
| re.I | 使匹配对大小写不敏感                              |
| re.L | 做本地化识别（locale-aware）匹配                  |
| re.M | 多行匹配，影响 ^ 和 $                           |
| re.S | 使 . 匹配包括换行在内的所有字符                       |
| re.U | 根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B. |
| re.X | 该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。         |

> - 属性
>
>   *re.match 与re.search相同*
>
> string: 匹配时使用的文本
>
> re: 匹配时使用的Pattern对象
>
> pos: 文本中正则表达式开始搜索的索引
>
> endpos: 文本中正则表达式结束搜索的索引
>
> lastindex: 最后一个被捕获的分组在文本中的索引。如果没有被捕获的分组，将为None。lastgroup: 最后一个被捕获的分组的别名。如果这个分组没有别名或者没有被捕获的分组，将为None。
>
> - 方法
>
> group([group1, …]):获得一个或多个分组截获的字符串；指定多个参数时将以元组形式返回。group1可以使用编号也可以使用别名；编号0代表整个匹配的子串；不填写参数时，返回group(0)；没有截获字符串的组返回None；截获了多次的组返回最后一次截获的子串。
>
> groups([default]):以元组形式返回全部分组截获的字符串
>
> groupdict([default]):返回以有别名的组的别名为键、以该组截获的子串为值的字典，没有别名的组不包含在内。
>
> start([group]):返回指定的组截获的子串在string中的起始索引
>
> end([group]):返回指定的组截获的子串在string中的结束索引（子串最后一个字符的索引+1。
>
> span([group]):返回(start(group), end(group))。
>
> expand(template):将匹配到的分组代入template中然后返回。template中可以使用\id或\g、\g引用分组，但不能使用编号0。\id与\g是等价的；但\10将被认为是第10个分组，如果你想表达\1之后是字符’0’，只能使用\g0。

## 实战技巧

- 匹配模式换行
- 匹配结果替换

```python
def replaceTool(self,x):
        removeImg=re.compile('<img.*?>')
        removeAddr = re.compile('<a.*?>|</a>')
        #把换行的标签换为\n
        replaceLine = re.compile('<tr>|<div>|</div>|</p>')
        #将表格制表<td>替换为\t
        replaceTD= re.compile('<td>')
        #把段落开头换为\n加空两格
        replacePara = re.compile('<p.*?>')
        #将换行符或双换行符替换为\n
        replaceBR = re.compile('<br><br>|<br>')
        #将其余标签剔除
        removeExtraTag = re.compile('<.*?>')
        x = re.sub(removeImg,"",x)
        x = re.sub(removeAddr,"",x)
        x = re.sub(replaceLine,"\n",x)
        x = re.sub(replaceTD,"\t",x)
        x = re.sub(replacePara,"\n    ",x)
        x = re.sub(replaceBR,"\n",x)
        x = re.sub(removeExtraTag,"",x)
        #strip()将前后多余内容删除
        return x.strip()
```



## 语法表

![expression](http://img.blog.csdn.net/20130515113723855)
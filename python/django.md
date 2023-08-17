---
 title: django notes
 categories: python
 tags: django
 date: 2020-08-30
---


## 简介

<u>urls.py</u>
网址入口，关联到对应的views.py中的一个函数（或者generic类），访问网址就对应一个函数。

<u>views.py</u>
处理用户发出的请求，从urls.py中对应过来, 通过渲染templates中的网页可以将显示内容，比如登陆后的用户名，用户请求的数据，输出到网页。

<u>models.py</u>
与数据库操作相关，存入或读取数据时用到这个，当然用不到数据库的时候 你可以不使用。

<u>forms.py</u>
表单，用户在浏览器上输入数据提交，对数据的验证工作以及输入框的生成等工作，当然你也可以不使用。

<u>templates older</u>

views.py 中的函数渲染templates中的Html模板，得到动态内容的网页，当然可以用缓存来提高速度。

<u>admin.py</u>
后台，可以用很少量的代码就拥有一个强大的后台。

<u>settings.py</u>
Django 的设置，配置文件，比如 DEBUG 的开关，静态文件的位置等。

## 安装

**1. 安装**

Django版本众多，兼容性差。指定版本安装	**`pip install django==1.10.6.`**

**2. 检查安装**

**`cmd>python`**进入python

**`import django`**不报错，安装成功

**`print(django.get_version())`** 打印版本信息



## build the first aproject


**1. create**

> django-admin startproject yeeblog

终端执行建立工程文件夹-project

**2. 目录说明**

- **HelloWorld:** 项目的容器。
- **manage.py:** 一个实用的命令行工具，可让你以各种方式与该 Django 项目进行交互。
- **HelloWorld/__init__.py:** 一个空文件，告诉 Python 该目录是一个 Python 包。
- **HelloWorld/settings.py:** 该 Django 项目的设置/配置。
- **HelloWorld/urls.py:** 该 Django 项目的 URL 声明; 一份由 Django 驱动的网站"目录"。
- **HelloWorld/wsgi.py:** 一个 WSGI 兼容的 Web 服务器的入口，以便运行你的项目。

**3. 开启服务器**

```python
python manage.py runserver  # 开启服务器
python manage.py runserver 8001 #使用其它端口，ctrl+C退出
python manage.py runserver 0.0.0.0:8000
python manage.py runserver 0.0.0.0:80
#监听机器上所有ip 8000端口，访问时用电脑的ip代替 127.0.0.1
ctrl+c //终止
```
##build first app

1. `python manage.py startapp firstapp`多了一个firstapp文件

```python
#文件结构
learn/
|--migrations
├── __init__.py
├── admin.py
├── models.py
├── tests.py
└── views.py
|-- apps.py
```

2. 把新定义的app注册到settings.py的INSTALL_APPS
3. 修改views文件，自定义显示
4. 修改视图函数相关url

## 加法实例

```python
#views.py
def add(request):
    a=request.GET['a']
    b=request.GET['b']
    c=int(a)+int(b)
    return HttpResponse(str(c))
#urls.py
url(r'^add/$',first_views.add,name='add'),
#net
http://127.0.0.1:8000/add/?a=4&b=5
```


## 基本命令

```python
python manage.py startapp app-name
#新建app

python manage.py syncdb
#同步数据库
'''
注意：Django 1.7.1及以上的版本需要用以下命令
python manage.py makemigrations
python manage.py migrate
'''

python manage.py flush
#清空数据库

python manage.py createsuperuser
'''
创建超级管理员
按照提示输入用户名和密码，邮箱可以留空
python manage.py changepassword username #修改用户密码
'''

python manage.py dumdata appname > appname.json
python manage.py loaddata appname.json
#导入导出数据

python manage.py shell
#终端运行

python manage.py dbshell
#数据库命令行

python manage.py
#命令详解
```
#URL 

## html url path

"/index/": 表示绝对路径

“index/”: 表示相对路径

## url解析

```python
#reverse()
def get_absolute_url(self):
        return reverse('myfirstapp:detail',kwargs={'pk':self.pk})
#html文件中解析，可以传入参数
{% url 'myfirstapp:archives' date.year date.month %}
#避免使用硬编码，方便修改
```



#templates

describes how Django will load and render templates

## 基本用法

1. 在appname下新建templates文件夹/或者在根项目下建立模板
2. templates下放要引用的html文件,<home.html>.
3. views.py
```python
# -*- coding: utf-8 -*-
from django.shortcuts import render

def home(request):
    return render(request, 'home.html')
```

## 进阶
**1. 传递字符串**
```python
#定义
def home(request):
  string=u"hello"
  return render(request,'home.html',{'string':string})
#引用
{{string}}    #home.html
```
**2. for循环,列表,字典**
```python
#定义
def home(request):
  tutor=["Html","CSS","Python"]
  return render(request,'home.html',{'tutor',tutor})
#引用
{% for i in tutor %}  #功能语句%%
{{i}}     #变量用{{}}
{% endfor %}
#字典引用
{{dict.key}}
or
{%for key,value in dict %}
{{key}}:{{value}}
{% endfor %}
```
**3.for循环高阶操作**
```python
#嵌套格式
{% for items in list%}
  {{item}}
  {%if not <>%}
  <do>
  {% endif %}
{% endfor %}
```

变量	描述
forloop.counter	索引从 1 开始算
forloop.counter0	索引从 0 开始算
forloop.revcounter	索引从最大长度到 1
forloop.revcounter0	索引从最大长度到 0
forloop.first	当遍历的元素为第一项时为真
forloop.last	当遍历的元素为最后一项时为真
forloop.parentloop
用在嵌套的 for 循环中，获取上一层 for 循环的 forloop
empty 判断为空元素

**4. 获取用户信息**
```Python
{{request.user}}
{{request.path}}
{{request.GET.urlencode}}
```
#model
- 每个模型都是django.db.models.Model 的一个Python 子类
- 模型的每个属性都表示为数据库中的一个字段
- Django 提供一套自动生成的用于数据库访问的API
##数据库配置
```python
#settings.py
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',  # or mysql.connector.django
        'NAME': 'myblog',
        'USER': 'root',
        'PASSWORD': '1225',
        'HOST':'localhost',
        'PORT':'3306',
        #'ENGINE': 'django.db.backends.sqlite3',
        #'NAME': os.path.join(BASE_DIR, 'db.sqlite3'),
    }
}

pip install mysqlclient #install mysql驱动
import mysqldb  #检验是否安装
```

##def model
修改`app/models.py`
```Python
from django.db import models

class Persons(models.Model):  #继承自models.models
  name = models.CharField(max_length=30)
  age = models.IntegerField()
"""
由于分类名和标签名一般都是用字符串表示，因此我们使用了 CharField 来指定 name 的数据类型，同时 max_length 参数则指定 name 的最大长度。除了 CharField ，django 还为我们提供了更多内置的数据类型，比如时间类型 DateTimeField、整数类型 IntegerField 等等
dields字段类型官网文档
https://docs.djangoproject.com/en/dev/ref/models/fields/

"""

#生成数据库表
python manage.py makemigrations
python manage.py migrate
#之前要先打开数据库
```
##模型实例化

**实例**

```python
python manage.py shell  #打开python交互命令行
from myapp.models import Persons #导入类实例
p1=Person(name="Yeekal",age=22) #create
p1.save()         #save to databases
p2=Person.objects.create(name="Haley",age=19) #一次完成创建和保存


1. Person.objects.create(name=name,age=age)
2. p = Person(name="WZ", age=23)
   p.save()
3. p = Person(name="TWZ")
   p.age = 23
   p.save()
4. Person.objects.get_or_create(name="WZT", age=23)
5. p.delete()
"""
这种方法是防止重复很好的方法，但是速度要相对慢些，返回一个元组，第一个为Person对象，第二个为True或False, 新建时返回的是True, 已经存在时返回False.
"""
```

**选择**

```python

p_list=Person.objects.all();
def __unicode__(self):		#可视化
    # 在Python3中使用 def __str__(self)
        return self.name
```

**过滤**

1. Person.objects.all() 返回类似于列表的数据结构

2. Person.objects.all()[:10] 切片操作，获取10个人，不支持负索引，切片可以节约内存

3. Person.objects.get(name=name)

   get是用来获取一个对象的，如果需要获取满足条件的一些人，就要用到filter

4. Person.objects.filter(name="abc") # 等于Person.objects.filter(name__exact="abc") 名称严格等于 "abc" 的人

5. Person.objects.filter(name__iexact="abc") # 名称为 abc 但是不区分大小写，可以找到 ABC, Abc, aBC，这些都符合条件

6. Person.objects.filter(name__contains="abc") # 名称中包含 "abc"的人

7. Person.objects.filter(name__icontains="abc") #名称中包含 "abc"，且abc不区分大小写

8. Person.objects.filter(name__regex="^abc") # 正则表达式查询

9. Person.objects.filter(name__iregex="^abc")# 正则表达式不区分大小写

   filter是找出满足条件的，当然也有排除符合某条件的

10. Person.objects.exclude(name__contains="WZ") # 排除包含 WZ 的Person对象

11. Person.objects.filter(name__contains="abc").exclude(age=23) # 找出名称含有abc, 但是排除年龄是23岁的

## 创建用户

```python
python manage.py createsuperuser
username:yee
password:
```



## 自定义Field

http://www.ziqiangxuetang.com/django/django-custom-field.html



## queryset进阶

http://www.ziqiangxuetang.com/django/django-queryset-advance.html

# 进阶

## 后台

http://www.ziqiangxuetang.com/django/django-admin.html

```python
python manage.py createsuperuser	#创建超级管理员

#修改admin.py文件
from django.contrib import admin
from .models import Article
admin.site.register(Article)
#runserver就可以添加文章了

```

## 表单

1. 新建app/forms.py

   ```python
   from django import forms
    //继承自forms.form 或者 forms.ModelForm
   class AddForm(forms.Form):
       a = forms.IntegerField()
       b = forms.IntegerField()
   ```

2. views.py定义函数

##静态文件

```css
appname/static/appname---css
				    |---js
```

## 支持markdown

```python
#第三方库
pip install markdown
#渲染文章主题
post.body=markdown.markdown(post.body,
             extensions=[
            'markdown.extensions.extra',
             'markdown.extensions.codehilite',#语法高亮
             'markdown.extensions.toc',#自动生成目录
            ])
#引用时添加过滤器，否则只显示原始的html代码
{{post.body|safe}}
```

## 代码高亮

```python
pip install pygments
#markdown引入扩展
extensions=[
            'markdown.extensions.extra',
             'markdown.extensions.codehilite',#语法高亮
             'markdown.extensions.toc',#自动生成目录
            ])

//html文件引入代码高亮格式文件
<link rel="stylesheet" href="{% static 'blog/css/highlights/github.css' %}">
```






## 模板语法

- [ref1](https://www.cnblogs.com/huchong/p/7723525.html)

## static file

- [ref1](https://stackoverflow.com/questions/28879731/django-1-6-how-to-access-static-files-in-view)

## url 
- [url](https://docs.djangoproject.com/zh-hans/3.1/topics/http/urls/)

## ali

开放端口：
- [阿里云](https://yq.aliyun.com/articles/701181)
- [ufw](https://www.shareintelli.com/272/)

## 3d

- [three 3d](https://stemkoski.github.io/Three.js/)
- [frontend](https://freefrontend.com/three-js-examples/)

## code

```
python manage.py createsuperuser
python manage.py runserver 0.0.0.0:8234
nohup python manage.py runserver 0.0.0.0:8234 1>/dev/null 2>1 &
python manage.py makemigrations
python manage.py migrate
```
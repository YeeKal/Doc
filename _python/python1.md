****


# 概述

## Interpreter

interactive mode

>  `quit()`  退出

source code encoding

> `# _*_ coding:encoding _*_`
>
> `#!/usr/bin/env python3` to start with a unix "shebang" line

*In interactive mode, the last printed expression is assigned to the variable 
`_`*

# 变量

## numbers

```python
int
float
/	# float
//	#fractional part
%	#remainder
**	#power

```

j or J suffix to indicate the imaginary part

## strings

- indexed/immutable


- backslashes `\` to escape quotes
- `print()`  produce a more readable output
- *raw string* by adding `r`before the first quote`print(r"I love you \n")`
- triple quotes`"""..."""` ('''...''')  to span multiple lines,自动加入换行，`\`取消换行

```python
+	#concatenate
''''	#自动连接
```



# 数据类型

## List

- mutable
- \+ to concatenation

```python
#定义
classmates = ['Michael', 'Bob', 'Tracy']
#访问
L[index]
L[-1] #最后一个
#切片
L[:2]	#从第一个索引值开始至最后一个索引值之前一位
L[:]
	#i企鹅片可批量赋值
#索引值
L.index(value)
#增加
L.append()
L.insert(index,obj);
#删除
L.pop()  #last one
L.pop(i)
L.remove(value) #remove first occurrence of value
```
## Tuple

```python
#def
classmates = ('Michael', 'Bob', 'Tracy')
#空元素
t=（）
#一个元素
t=（1，）
#可变元素
>>> t = ('a', 'b', ['A', 'B'])
>>> t[2][0] = 'X'
>>> t[2][1] = 'Y'
>>> t
	('a', 'b', ['X', 'Y'])
```
## Dict

```python
#Def
d={'Yee':92,"Hna":87,"Mar":95}
d['car']=93
#访问
d['yee'] #KeyError
'Yee' in d
d.get('Yee') #不存在返回none
d.get('Yee',87) #不存在赋新值
#切片
L[0:3]#3 stop get first 3
L[:3]#from 0
L[-3:]#最后三个
L[:10:2]#前10每两个取一个
L[::5]#所有数，每五个
L[::]#copy
tuple/str #都适用切片 无序
```
## Set 

> 不可变对象 不重复

```python
#Definition
a=set()	#创建一个空元素
a-b	# 差集
a|b	#并集
a&b	#交集
a^b	#交集的补集
```
## Function 

> 占位符

```python
#def
def add_func(a,b):
	return a+b
pass #语句
#如果没有return语句，函数执行完毕后也会返回结果，只是结果为None。
#return None可以简写为return
#参数
power(x,n=2)#m默认参数
def add_end(L=None): #列表参数
    if L is None:
        L = []
        L.append('END')
        return L
def calc(*numbers):#可变参数
	 sum = 0
	 for n in numbers:
		  sum = sum + n * n
	 return sum
calc(*nums)#利用*号传入列表或元祖的元素
def person(name, age, **kw):#关键字参数
#关键字参数允许你传入0个或任意个含参数名的参数，这些关键字参数在函数内部自动组装为一个dict
>>> person('Bob', 35, city='Beijing')
name: Bob age: 35 other: {'city': 'Beijing'}
>>> person('Adam', 45, gender='M', job='Engineer')
name: Adam age: 45 other: {'gender': 'M', 'job': 'Engineer'}
```
# Concepts

## 关键字

break:

continue:

pass:

def:



## iteration

> 迭代

```python

	d = {'a': 1, 'b': 2, 'c': 3}
	for key in d:
		print(key)  #元素的遍历
	for i in d.values()
	for i in d.items()
	#可迭代对象：str
	#可迭代判断：
    	from collections import Iterable
		isinstance('abc', Iterable) # str是否可迭代
        True
```

## List Comprehension

> 列表生成式

```python

>>> L = []
>>> for x in range(1, 11):
...    L.append(x * x)
...
>>> L
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

L=[x*x for x in range(1,11)]
L=[x * x for x in range(1, 11) if x % 2 == 0]#加判断
[m + n for m in 'ABC' for n in 'XYZ']#2级
>>>['AX', 'AY', 'AZ', 'BX', 'BY', 'BZ', 'CX', 'CY', 'CZ']
[s.lower() for s in L]
```
## Generator

> 生成器，一边循环一边计算的机制

```python
 g = (x * x for x in range(10))#列表生成式变括号创建
	 for i in g:  #调用
			print i
	 next(g) #调用  until StopIteration ERROR
yield#关键字定义，在每次调用next()的时候执行，
	#遇到yield语句返回，再次执行时从上次返回的yield语句处继续执行
```
## Iterator

> 迭代器

```python
iterable:
	#可迭代对象(for 循环)：list tuple dict dict set str//generator//
Iterator
	#可以被next（）调用 生成器
	from　collections　import　
```
# Functional-Programming

>函数式编程
>
>函数：面向过程的基本单元
>
>没有副作用：输入输出确定
>
>有副作用：变量状态不确定
>
>函数式编程的一个特点就是，允许把函数本身作为参数传入另一个函数，还允许返回一个函数

## Higher-order-function

```python
#变量指向函数
>>>f=abs
>>>f
<built-in function abs>
>>> f(-10)
10
#函数名也是变量/指向函数的变量
>>> abs = 10
>>> abs(-10)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'int' object is not callable
   #abs是定义在import builyins模块中所以要让修改abs变量的指向在其它模块也生效，要用import
	#builtins; builtins.abs = 10 
#传入函数/函数作为参数
def add(x, y, f):#函数作为参数传入，如此称为高阶函数，函数式编程--高度抽象的编程范式
    return f(x) + f(y)
```

## map/reduce/filter/sorted

```python
#map
map(f,iterable)#接收两个参数，一个是函数，一个是Iterable,把结果作为新的Iterator返回
>>> def f(x):
...     return x * x
...
>>> r = map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9])#Iterator是惰性序列，因此通过list()函数让它把整个序列都计算出来并返回一个list
>>> list(r)
[1, 4, 9, 16, 25, 36, 49, 64, 81]
```

```python
#reduce
reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)#累计运算
#序列求和
>>> from functools import reduce
>>> def add(x, y):
...     return x + y
...
>>> reduce(add, [1, 3, 5, 7, 9])
25
#str to int
from functools import reduce
def str2int(s):
    def fn(x, y):
        return x * 10 + y
    def char2num(s):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
    return reduce(fn, map(char2num, s))
```

```python
#filter
#filter()把传入的函数依次作用于每个元素，然后根据返回值是True还是False决定保留还是丢弃该元素
def is_odd(n):
    return n % 2 == 1
list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15]))
# 结果: [1, 5, 9, 15]
```

```python
#sorted
#排序
>>> sorted([36, 5, -12, 9, -21])#对list进行排序
[-21, -12, 5, 9, 36]
>>> sorted([36, 5, -12, 9, -21], key=abs)#自定义（绝对值）排序
[5, 9, -12, -21, 36]
#字符串排序
>>> sorted(a)
['Zoo', 'bad', 'bob', 'car', 'yee']
>>> sorted(a,key=str.lower)
['bad', 'bob', 'car', 'yee', 'Zoo']
>>> sorted(a,key=str.lower,reverse=True)
['Zoo', 'yee', 'car', 'bob', 'bad']
#函数自定义排序
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
def by_name(t):
    return t[0]
L2 = sorted(L, key=by_name)
print(L2)
>>>[('Adam', 92), ('Bart', 66), ('Bob', 75), ('Lisa', 88)]
```

## 返回函数

> 函数作为返回值

```python
#sum all
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum
#调用lazy_sum()时，返回的并不是求和结果，而是求和函数
>>> f = lazy_sum(1, 3, 5, 7, 9)
>>> f
<function lazy_sum.<locals>.sum at 0x101c6ed90>
#调用f时才是求和结果
>>> f()
25
```

## 匿名函数

```python
#lambda
#没有名字
#作为一个函数对象，可以复制给变量
>>> f = lambda x: x * x
>>> f
<function <lambda> at 0x101c6ef28>
>>> f(5)
25
#可以作为返回值
def build(x, y):
    return lambda: x * x + y * y
```

## Decorator

```python
#定义装饰器
#在函数调用前后自动打印日志，但又不希望修改now()函数的定义
import functools

def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator
#定义函数  
@log('execute')
def now():
    print('2015-3-25')
```

## partial function

[廖雪峰网站](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/00143184474383175eeea92a8b0439fab7b392a8a32f8fa000)

## oneline

```python
python -m http.server 8080
```



# Development Enviroment

## Modules

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

' a test module '

__author__ = 'Michael Liao'

import sys

def test():
    args = sys.argv
    if len(args)==1:
        print('Hello, world!')
    elif len(args)==2:
        print('Hello, %s!' % args[1])
    else:
        print('Too many arguments!')

if __name__=='__main__':
    test()
```

> 第一行：文件直接在unix/linux/mac上运行
>
> line4：任何模块代码的第一个字符串都被视为模块的文档注释
>
> line6：作者名

>运行`hello`模块文件时，Python解释器把一个特殊变量`__name__`置为`__main__`，而如果在其他地方导入该`hello`模块时，`if`判断将失败，因此，这种`if`测试可以让一个模块通过命令行运行时执行一些额外的代码，最常见的就是运行测试。

```python
python3 hello.py
>>>Hello, world!
python hello.py Michael
>>>Hello, Michael!
```

```python
#添加模块
#添加自己的搜索路径
#设置环境变量PYTHONPATH，该环境变量的内容会被自动添加到模块搜索路径中
```



## 运行

> IDLE:Python Integrated Development Environment
>
> GUI:graphical user interfac 图形用户界面
>
> IDE:Integrated Development Environment

> cmd
>
> 1.切换到文件路径
>
> 2.输入文件名

>shell:idle(gui)/command line
>
>Command line：cmd-py/python 交互式shell
>
>Idle: 人性化

# OOP

> Object Oriented Programming 面向对象编程

## 类和实例

```python
#定义
#数据封装/属性和方法
class Student(object):
    def __init__(self,name,score):    #第一个必须是self
        self.name=name                  #类的方法定义参数与函数类似 默认参数，可变参数，关键字参数
        self.score=score
    def print_score(self):
        print('%s: %s' % (self.name,self.score))
#实例
bart=Student('Yee',98)
#可自由给实例变量绑定属性/修改属性
bart.age=20
```

## 私有变量

> ```python
> class Student(object):
>   def __init__(self,name,score):    
>       self.__name=name                
>       self.__score=score              #私有属性
>
>   def print_score(self):
>       print('%s: %s' % (self.__name,self.__score))
>   def get_name(self):
>       return self.__name
>   def get_score(self):
>       return self.__score
>   def set_name(self, name):
>       self.__name=name
>   def set_score(self,score):
>       self.__score=score
>       return None
> ```

*Python本身没有任何机制阻止你干坏事，一切全靠自觉*

```python
__xxx__		#系统特殊变量，可以直接访问
-xxx		#约定俗成，虽然我可以被访问，但请不要随意访问
——Student__name#访问私有变量 __name,不同版本不一样，不推荐
```

## 继承和多态

> 继承属性和方法
>
> 子类覆盖父类override

### 获取对象信息

```python
dir()#获取对象的所有属性和方法
hasattr()
setattr()
getattr() #没有则抛出AttributeError
>>> hasattr(obj, 'x') # 有属性'x'吗？
True
>>> hasattr(obj, 'y') # 有属性'y'吗？
False
>>> setattr(obj, 'y', 19) # 设置一个属性'y'
>>> hasattr(obj, 'y') # 有属性'y'吗？
True
>>> getattr(obj, 'y') # 获取属性'y'
19
>>> getattr(obj, 'z', 404) # 获取属性'z'，如果不存在，返回默认值404
404
>>> fn = getattr(obj, 'power') # 获取属性'power'并赋值到变量fn
>>> fn # fn指向obj.power
<bound method MyObject.power of <__main__.MyObject object at 0x10077a6a0>>
>>> fn() # 调用fn()与调用obj.power()是一样的
81
```

## 实例属性/类属性

```python
class Student(object):#类属性直接定义
    name = 'Student'
>>> s = Student() # 创建实例s
>>> print(s.name) # 打印name属性，因为实例并没有name属性，所以会继续查找class的name属性
Student
>>> print(Student.name) # 打印类的name属性
Student
>>> s.name = 'Michael' # 给实例绑定name属性
>>> print(s.name) # 由于实例属性优先级比类属性高，因此，它会屏蔽掉类的name属性
Michael    
```

# OOP高级应用

## 动态绑定

```python
#实例绑定方法
>>> def set_age(self, age): # 定义一个函数作为实例方法
...     self.age = age
...
>>> from types import MethodType
>>> s.set_age = MethodType(set_age, s) # 给实例绑定一个方法
>>> s.set_age(25) # 调用实例方法
>>> s.age # 测试结果
25
#类绑定方法（从根本上改变,所有实例均可调用）
Student.set_age=set_age
```

```python
#属性限制
class Student(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
 #对子类无效，若子类适用__slots__,则父类的也算
```

## @property

```python
#方法当作属性使用
class Student(object):

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
#不定义setter方法就是一个只读属性
class Student(object): 
	@property
    def birth(self):
        return self._birth

    @birth.setter
    def birth(self, value):
        self._birth = value

    @property
    def age(self):#age可以根据birth和当前时间计算出来。
        return 2015 - self._birth
```

## 多重继承

```python
#Mixln
class Dog(Mammal, Runnable):
    pass
```

## 定制类

```python
__slots__
```

```python
__str__#定制打印
>>> class Student(object):
...     def __init__(self, name):
...         self.name = name
...     def __str__(self):
...         return 'Student object (name: %s)' % self.name
...
>>> print(Student('Michael'))
Student object (name: Michael)
#no print
>>> s = Student('Michael')
>>> s
<__main__.Student object at 0x109afb310>
#直接显示变量调用的不是__str__()，而是__repr__()，
#两者的区别是__str__()返回用户看到的字符串，
#而__repr__()返回程序开发者看到的字符串，#
#也就是说，__repr__()是为调试服务的
class Student(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'Student object (name=%s)' % self.name
    __repr__ = __str__
```

```python
__iter__# 返回迭代对象
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration();
        return self.a # 返回下一个值
 
>>> for n in Fib():
...     print(n)
...
1
1
2
3
5
...
46368
75025
```

```python
__getitem__#列表
class Fib(object):
    def __getitem__(self, n):
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a
    
```

```python
__getattr__
```

```python
__call__#直接在实例上调用
class Student(object):
    def __init__(self, name):
        self.name = name

    def __call__(self):
        print('My name is %s.' % self.name)
>>> s = Student('Michael')
>>> s() # self参数不要传入
My name is Michael.

callable()#判断是否可以调用
```

## 枚举类

> enumerate  [ɪ'numəret]

```python
from enum import Enum

Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))

for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)
    Jan => Month.Jan , 1
Feb => Month.Feb , 2
Mar => Month.Mar , 3
Apr => Month.Apr , 4
May => Month.May , 5
Jun => Month.Jun , 6
Jul => Month.Jul , 7
Aug => Month.Aug , 8
Sep => Month.Sep , 9
Oct => Month.Oct , 10
Nov => Month.Nov , 11
Dec => Month.Dec , 12
```

## metaclass

```python
#type()动态创建类
>>> def fn(self, name='world'): # 先定义函数
...     print('Hello, %s.' % name)
...
>>> Hello = type('Hello', (object,), dict(hello=fn)) # 创建Hello class
>>> h = Hello()
>>> h.hello()
Hello, world.
>>> print(type(Hello))
<class 'type'>
>>> print(type(h))
<class '__main__.Hello'>
#3个参数
#1.class的名称；
#2.继承的父类集合，注意Python支持多重继承，如果只有一个父类，别忘了tuple的单元素写法；
#3.class的方法名称与函数绑定，这里我们把函数fn绑定到方法名hello上。
```

> metaclass允许你创建类或者修改类。换句话说，你可以把类看成是metaclass创建出来的“实例”。
>
> 先定义metaclass，就可以创建类，最后创建实例

# 错误/调试/测试

## 错误

```python
#try...except...finally
try:
    print('try...')
    r = 10 / int('a')
    print('result:', r)
except ValueError as e:
    print('ValueError:', e)
except ZeroDivisionError as e:
    print('ZeroDivisionError:', e)
finally:			#可有可无，一定会被执行
    print('finally...')
print('END')
#不但捕获该类型的错误，还把其子类也“一网打尽”
#在顺序级别中，下面的子类永远也不会被捕获
```

```python
#error record
import logging
try:
    pass
except Exceptions as e:
    logging.exception(e)#程序打印完错误信息后会继续执行，并正常退出
 pass
```

```python
#throw error
raise ValueError('invalid value: %s' % s)
```

```python
#transport error
try:
    10 / 0
except ZeroDivisionError:
    raise ValueError('input error!')
```

## 单元测试


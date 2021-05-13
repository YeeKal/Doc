---
title: 常见面试问题
categories: CAT
tags: TAG
date: 2021-05-07
---
0. 实现c++标准函数

```c++
char * myStrcpy(char *s1,const char *s2 ){
    assert(s1 !=NULL && s2!= NULL);
    while((*s1++=*s2++)!='\0');
    return s1;
}

void* myMemcpy(void *dest,const void* src,size_t n){
    assert(dest !=NULL && src!=NULL);
    char *c1=(char *)dest;
    char *c2=(char *)src;
    while(n-- >0){
        *c1++=*c2++;
    }
    return dest;
}
```

1. 重载、重写的区别

- 重载：函数名相同，函数的参数个数、参数类型或参数顺序三者中必须至少有一种不同。函数返回值的类型可以相同，也可以不相同。发生在一个类内部，不能跨作用域。

- 重定义：也叫做隐藏，子类重新定义父类中有相同名称的非虚函数 ( 参数列表可以不同 ) ，指派生类的函数屏蔽了与其同名的基类函数。可以理解成发生在继承中的重载。

- 重写：也叫做覆盖，一般发生在子类和父类继承关系之间。子类重新定义父类中有相同名称和参数的虚函数。(override)

2.  封装/继承/多态

- 封装：把数据和函数等集合放在类中
- 继承：子类通过继承父类实现资源共用
- 多态

3. 内存泄漏

- 是什么：动态分配的内存在使用完毕后没有及时释放

4. 内存：

- 栈：编译器自动分配管理，存放临时变量和函数参数（局部变量），函数执行结束自动释放
- 堆：由程序员手动分配
- 全局静态存储区：全局变量和静态变量
- 常量存储区：存放常量


## ref

- [C++知识点](https://github.com/huihut/interview)
- [C++常见面试问题汇总-无答案](https://github.com/Making-It/CS_Review/blob/master/%E7%9F%A5%E8%AF%86%E7%82%B9%E6%80%BB%E7%BB%93/C%2B%2B%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E9%97%AE%E9%A2%98.md)
- [awesome-cs-books: 超过 200 本经典的计算机书籍分享](https://github.com/imarvinle/awesome-cs-books)
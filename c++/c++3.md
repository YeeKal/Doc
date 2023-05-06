## const

1. const 对象默认为文件局部变量，其他文件访问需要显示指定extern

```c++
//extern_file1.cpp
extern const int ext=12;
//extern_file2.cpp
#include<iostream>
extern const int ext;
int main(){
    std::cout<<ext<<std::endl;
}
```

2. 指针与常量

```c++
#include<iostream>
using namespace std;
int main(){

    int n=0;           // 非常量
    const int m=1;      // 常量

    int * p1=&n;        // 
    //p1=&m;              // 常量的地址只能赋值给指向常量的指针
    const int * cp1=&n;     // 允许把非const对象的地址赋给指向const对象的指针
    const int * cp2=&m;

    int * const pc1=&n;   //const指针必须初始化
    //int * const pc2=&m;   //const指针不能指向常量地址

    const int * const cpc1=&n;  // 指向常量的常指针都可以
    const int * const cpc2=&m;

    cout<<"n:"<<*cpc1<<"    "<<"m:"<<*cpc2<<endl;
}
```
3. 函数参数使用常量

```c++
void func(const A &a);  // 增加效率同时防止修改
// 对于基本变量不需要const修饰，因为传入的时候就是值传递。由于基本变量的复制很快所以也不需要使用引用
```

4. 类中使用常量

```c++
// const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数
// 常量须在初始化列表中初始化，或者与static 结合

static const int apple_number=10;
// 或者
const int apple_number=10;

// c++ 98 不允许非静态成员在类内初始化，c++ 11 已经支持
// static 成员在类外初始化

int Apple:a=10;
```

## static 

静态成员贯穿整个程序的生命周期

```c++
// static 成员在类外初始化
int Apple:a=10;
```

下述程序中类在程序最后才析构，如果是非静态成员则在打印最后一行之前析构。
```c++
#include<iostream> 
using namespace std; 

class Apple 
{ 
    int i; 
    public: 
    Apple() 
    { 
        i = 0; 
        cout << "Inside Constructor\n"; 
    } 
    ~Apple() 
    { 
        cout << "Inside Destructor\n"; 
    } 
}; 

int main() 
{ 
    int x = 0; 
    if (x==0) 
    { 
        static Apple obj; 
    } 
    cout << "End of main\n"; 
} 

/*
Inside Constructor
End of main
Inside Destructor
*/
```

## this指针

this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。this指针的使用:

- 在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this。
- 当参数与成员变量名相同时，如this->n = n （不能写成n = n)。

在普通成员函数中，this是一个指向非const对象的const指针（如类类型为Student，那么this就是Student *const类型的指针）。在const成员函数中，this指针是一个指向const对象的const指针（如类类型为Student，那么this就是const Student * const类型的指针)


## template

```c++
template<content>
// content can be:
// 1. class T/typename T
// 2. a specific data type
// 3. an integer specification
// 4. An integral constant/pointer/reference which maps to specification mentioned above
```

Pointers, References and Arrays with Templates

```c++
template<class T>
T average(T arr[],int n);
T average(T* arr, int n);
void TwiceIt(T& tData);

template<class  T>
T Twice(const T& data);
```

Multiple Types with Function Templates
```c++
template<class T1, class T2, ... >;
```

- function template: 适用于函数的模板，需要提供参数类型来是实例化为函数
- template function: 函数模板的实例化，已经明确了模板的类型，需要提供参数
```c++
template<class Type>
void Show(Type tData) {}
Show(1234); // 函数模板的一次调用
Show<double>//模板函数，等待传参
Show<double> ( 1234 ); // pass int , but wish to instantiate as double

// 这种也叫做 Explicit Template Argument Specification
template<class T>
T max(T t1, T t2)
{
   if (t1 > t2)
      return t1;
   return t2;
}
max(120, 14.55);// error, 参数不明
max<double>(120, 14.55)
```




## 智能指针

```c++
typedef std::shared_ptr<Object> ObjectPtr;
typedef std::shared_ptr<const Object> ObjectPtr;
//初始化
shared_ptr<Object> object;
object.reset(new Object(paras));
object.reset();//重置为空

shared_ptr<Object> object=make_shared<Object>(paras);

Object *obj=new Object(paras);
shared_ptr<Object> object(obj);//普通指针构造

shared_ptr<Object> object2=object;//复制，指向同一块内存

//逻辑运算
if(!object){}//判断是否为空
if(object==object2){}//equal

*object;//获取内部数据指针 ?
Object *obj=object.get();//获取内部数据指针

std::cout<<object.use_count()<<std::endl;//指向同一个内部数据指针的个数
```

## 继承与多态


- 继承
    - 子类可以使用父类的非私有函数
    - 子类不能访问私有成员变量或函数
    - 父类**指针或引用**可以在不进行显示类型转换的情况下指向子类对象，但只能调用基类方法
    - struct定义的继承默认为public，class定义的继承默认为private
```c++
//赋值： 子类赋值给基类，仅把基类部分赋给基类对象

//引用： 仅能访问基类的方法和属性
Child child;
Base& base=child;

//指针： 父类指针指向子类对象，仅能访问基类的方法和属性
Base* base=new Child();
```

- 虚函数

 虚函数的作用是允许在派生类中重新定义与基类同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。父类中定义为虚函数的，子类中是否加virtual关键字都被认为是虚函数，建议在子类中加入virtual关键字，方便阅读。

 虚函数通过一张虚函数表(Virtual Table)来实现, 简称为V-Table. 在子类重写了基类的虚函数时，虚函数表中被重写的函数将被替换为子类的函数对象，因此调用时将调用子类方法。

 ```c++
//引用： 可以访问子类重定义的虚函数
Child child;
Base& base=child;

//指针： 可以访问子类重定义的虚函数
Base* base=new Child();
```

- 纯虚函数

子类必须实现的虚函数。

纯虚函数是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。在基类中实现纯虚函数的方法是在函数原型后加“=0” 。

包含纯虚函数的类称为**抽象类**。不能定义抽象类的对象。抽象类的主要作用是将有关的操作作为结果接口组织在一个继承层次结构中，由它来为派生类提供一个公共的根，派生类将具体实现在其基类中作为接口的操作。

如果子类没有重新定义纯虚函数，只是继承了基类的纯虚函数，则派生类仍然是一个抽象类。

- 类占用的内存

空的类是会占用内存空间的，而且大小是1，原因是C++要求每个实例在内存中都有独一无二的地址。

（一）类内部的成员变量：

普通的变量：是要占用内存的，但是要注意对齐原则（这点和struct类型很相似）。
static修饰的静态变量：不占用内容，原因是编译器将其放在全局变量区。

（二）类内部的成员函数：

普通函数：不占用内存。
虚函数：要占用4个以上字节，用来指定虚函数的虚拟函数表的入口地址。所以一个类的虚函数所占用的地址是不变的，和虚函数的个数是没有关系的。

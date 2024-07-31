

[TOC]

# 类

## 定义

**类声明**

```c++
#include<string>

class Stock {
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tolt() {
		total_val = shares*share_val;
	}
public:
	void acquire(const std::string &co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
};
```

一般将共有函数用到的实现细节作为私有函数。

**成员函数实现**

```c++
void Stock::buy(long num,double price){
    
}
//chuan创建类声明中的成员函数
//使用作用域解析运算符‘::’标识函数所述的类
//不同的类可以有相同的函数名
```

```c++
class Stock{
private:
  void set_tot();//类的内联函数
public：
  ...
}

inline void Stock::set_tot(){//类声明之外定义成员函数
    total_val=shares*share_val;
}
```

## 构造函数和析构函数

**构造函数**

既要保证数据隐藏，又要能够方便初始化数据。

没有返回值，没有void声明，函数原型位于类声明的共有部分。

构造函数可以方便的重置对象。

```c++
//constructor prototype with some default arguments
Stock(const string &co,long n=0,double pr=0);

//constructor definition
Stock::Stock(const string &co,long n=0,double pr=0){
    ...
}//参数名中不能使用成员名
```

```c++
//初始化对象
Stock food=Stock("yeekal",350,1.25);//显式调用
Stock food("yeekal",350,1.25);//隐式调用
Stock *pfood=new Stock("yeekal",350,1.25);//结合指针
Stock food={"yeekal",350,1.25};//列表初始化
//构造函数在对象创建时自动调用，之后u能通过对象“别有心机”地调用构造函数。
```

```c++
//成员初始化列表 member initializer list
//在构造函数之前初始化常量
//常量和引用都必须使用这种方法
//该方法可以初始化任何变量
Queue::Queue(int qs) :qsize(qs)   //initialize const variable
{
	front = rear = nullptr;
	items = 0;
  //qsize=qs;
}

//类内初始化
class Queue{
    int items=0;
    qsize=10;//类内初始化
}
```



**默认构造函数**

弱程序中未定义构造函数，则c++提供默认构造函数，对象的创建方式是`Stock food`，即隐式初始化。若定义了构造函数，则必须提供默认构造函数才能使用隐式初始化。

```c++
Stock(const string &co="yeekal",long n=0,double pr=0);//第一种是提供默认值
Stock::Stock()//第二种是无参数列表
{
    company="yeekal";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
//真正的声明里利用了函数重载
Stock();
Stock(const std::string &co,long n=0;double pr=0.0);

//创建
Stock food;
Stock food=Stock();
Stock *pfood=new Stock;//没有括号
```

**析构函数**

```c++
~Stock();//声明，有参数
Stock::~Stock(){
    cout<<"Bye"<<company<<endl;
}//析构函数不承担任何重要的工作，所以函数可以不执行任何程序
//但为了表明什么时候该函数被调用，可以编写是上面的输出代码
//若未定义析构函数，程序结束时会自动调用默认析构函数
```

**const成员函数**

```c++
void show() const;//promise not to change invoking object
void Stock::show() const;//definition

const Stock food;
food.show();//若不做const声明，将无法调用，因为不带const的成员函数有改变属性值的潜在可能
```

一般，只要类方法不修改调用对象，就应该将其声明为const

## this指针

每个成员函数都有一个this指针，其指向该对象本体。因此`*this`代表整个调用对象。

## 对象数组

```c++
Stock food[4]={
    Stock("yee",23.4,0.0),
  Stock(),
  Stock("yeekal"),
}//余下的一个使用默认构造函数初始化
```

## 类作用域

## 运算符重载

```c++
operator op (arguments-list);//造作符函数格式
//以下例子
Time Time::Sum(const Time &t) const {//参数为引用。为了提高效率
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator+ (const Time & t) const {
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
//引用
Time coding(2, 40);
Time fixing(5, 55);
Time total;

total=coding.operator+(fixing);//+之间的空格不作要求
total=coding+fixing;
total=coding.Sum(fixing);
```

编译器将根据造作数的类型自动选择操作

重载的操作符不必是成员函数，但必须至少有一个操作数是用户自定义类型。（因为标准类型的操作已被确定，操作符重载的标识就是根据操作数的类型来变更的）

不能修改操纵符原来的语法规则，不能修改优先级，不能定义新的操作符。

## 友元

类对私有成员的访问限制过于严格，为了开放访问权限，提供了“友元”(We are friends.\*__\\*)

- 友元函数
- 友元类
- 友元成员函数

**友元函数**

赋予普通函数以成员函数相同的访问权限

非成员操作符重载的友元函数：

```c++
//声明
//函数声明前加关键字 friend
//函数声明放在类声明中，但却不是成员函数
//因此调用函数不用成员操纵符
friend Time operator* (double m,const Time & t);

//定义
//函数定义不需要friend，也不需要类声明空间
Time operator* (double m,const Time & t){
    
}
//调用
//非成员操作符重载函数将所有的操作数都作为显式参数
A=1.2*B;
A=operator *(1.2,B);
```

```c++
//重载<<
#include<iostream>
//类声明
friend std::ostream & operator<< (std::ostream & os, const Time &t);

//定义
std::ostream & operator << (std::ostream & os, const Time &t) {
	os << t.hours << "hours, " << t.minutes << "minutes";
	return os;
}

//调用
cout<<total;
```

重载操作符一般作为成员函数

# 类的动态内存分配

静态成员，无论创建了多少个成员，程序都只创建一个静态变量副本，即不同的对象实例共享一个静态成员。不能在类声明中初始化静态成员。

## Special member function

- a default constructor if you define no constructor
- a default destructor if...
- a copy constructor if
- an assignment operator(赋值操作符)
- an address operator

**复制构造函数**

当函数按值传递对象或函数返回对象时都将使用copy constructor 。

由于按值传递会调用复制构造函数，故应该按引用传递对象。

```c++
//calls StringBad(const StringBad &)
StringBad ditto(motto);
StringBad metto=motto;
StringBad also=StringBad(motto);
StringBad *psbird=new StringBad(motto);
```

编译器生成临时对象时也将使用复制构造函数。例如将三个类对象相加，编译器可能生成临时的对象来保存中间结果。

```c++
StringBad sailor=sports;
//what have happened
//由于默认调用了复制构造函数，将逐个复制非静态成员的值
//equal to
StringBad sailor;
sailor.str=sports.str;
sailor.len=sports.len;
//而静态成员的值不受影响，公用
```

上述（不在本文中，我明白就好）程序隐式调用了两次复制构造函数，导致析构函数更新了计数，但是静态成员num_strings并没有更新，因此程序无法准确地记录对象数目。解决办法是提供一个对技术进行更新的显式复制构造函数。

```c++
StringBad::StringBad(const StringBad & s){
    num_strings++;
  //other important statements
}
//若类中存在类似于这样对象被创建时发生更改的静态成员，则应该提供一个显式复制构造函数来处理计数问题
```

隐式复制构造函数按值传递数据，因此其中的指针成员将指向同一个地址（字符串等），因此当一个析构函数已经释放掉了指针的内存，另一个析构函数试图再次释放时就会出错。因此应定义显式构造函数进行深度复制（如果有必要，比如new初始化的指针）。

```c++
StringBad::StringBad(const StringBad & s){
    num_strings++;
    len=s.len;
    str=new str[len+1];
    std::strcpy(str,s.str);
    cout << num_strings << ":\"" << str << "\" object created\n";
}
//这事实上意味着把构造函数的内容复制到赋值函数里面？
```

**赋值操作符**

将导致复制构造函数的调用，因此可以编写赋值运算符重载。

```c++
StringBad & StringBad::operator=(const StringBad & st)
{
    if(this == &st)
      return *this;
  delete [] str; //free old str
  len=st.len;
  str=new char [len +1 ];
  std::strcpy(str,st,str);
  retrurn this;
}
```

*空指针：0 / NULL / nullptr(建议)*

**静态成员函数**

# temp

'endl' 控制符，manipulator；

“\n”，换行符

**延迟程序**

```c++
using namespace std;
cout << "Seconds to be delayed:\n";
float sec;
cin >> sec;
clock_t delay = sec*CLOCKS_PER_SEC;
clock_t start=clock();
while (clock() - start < delay)
  ;
cout << "done" << endl;
```

## 文件组织

- 头文件：结构和类的声明和函数原型
- 源代码文件：函数的定义（包含头文件）
- 源代码文件：main入口（包含头文件）




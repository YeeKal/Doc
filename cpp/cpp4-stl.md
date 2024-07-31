## vector

```c++
//初始化
vector<int> a(10);
vector<int> a(10,1);
vector<int> a(b); 
vector<int> a(b.begin(),b.begin+3);

int b[7]={1,2,3,4,5,9,8};
vector<int> a(b,b+7);


a.back();       //返回a的最后一个元素
a.front();      //返回a的第一个元素
a.begin();      //
a.end();        //
a.rbegin();
a.rend();
a.empty();      //判断a是否为空，空则返回ture,不空则返回false
a.push_back();
a.pop_back();   //delete last one

//assign
//assign会清空a的内存重新分配数据
void assign(const_iterator first,const_iterator last);
void assign(size_type n,const T& x = T());
a.assign(b.begin(), b.begin()+3);   //赋值b中的数据
a.assign(4,2);      //赋值4个2

//insert
iterator insert(iterator it,const T& x);//向量中迭代器指向元素前增加一个元素x
iterator insert(iterator it,int n,const T& x);//向量中迭代器指向元素前增加n个相同的元素x
iterator insert(iterator it,const_iterator first,const_iterator last);//向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据

//erase
iterator erase(iterator it);//删除向量中迭代器指向元素
iterator erase(iterator first,iterator last);//删除向量中[first,last)中元素

//size
a.size();   //元素个数
a.capacity();   //容器能够存储的元素个数，有：capacity() >= size()
a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100
                //reserve只是分配了空间，但是并没有对象，不能用[]取值。对原有的值不影响
```


## map

- unordered_map: hashed by keys
- map
- map中不能使用指针

- map和set的元素没有顺序，故insert函数不需要制定位置
- vector插入元素有顺序，故需要指明迭代器
- string同vector，但是string的位置指定可以是迭代器也可以是size_t

```c++
unordered_map<char,int> map;
//insert && visit
map['a']=3;
pair<string,double> myshopping ("baking powder",0.3);
myrecipe.insert (myshopping);                        // 复制插入
myrecipe.insert (make_pair<string,double>("eggs",6.0)); // 移动插入
myrecipe.insert (mypantry.begin(), mypantry.end());  // 范围插入
myrecipe.insert ({{"sugar",0.8},{"salt",0.1}});    // 初始化数组插入(可以用二维一次插入多个元素，也可以用一维插入一个元素)
myrecipe["coffee"] = 10.0;  //数组形式插入

//遍历
//for ( auto it = map.begin(); it != map.end(); ++it )
for(auto p:map){
    cout<<p.first()<<":"<<p.second()<<endl;
}
```
## set

- unordered_set: hashed by keys
- set

```c++
set<int> s;
set<int> s={1,2,3,4,5};

size();
pair<set<T>::iterator,bool> insert(T);//判断集合元素是否已存在
iterator find( const Key& key );  

begin();
end();

//set 中有自定义的默认排序，插入完成之后排序就完成了
```


## string
```c++
//operator
// ==
// >
// <
// >=
// <=
// !=
// +
// +=
// []
s = s + 'a' + 'b' + 'c'; //这样写是可以的
s += 'a' + 'b' + 'c'; //这样写是不对的

//add
append(str);
append( size_type num, char ch );
append( const char *str );
assign();//参数同append

size_type copy( char *str, size_type num, size_type index );//拷贝自己的num个字符到str中（从索引index开始）。返回值是拷贝的字符数

insert();//迭代器或者位置都可以
iterator insert( iterator i, const char &ch );
basic_string &insert( size_type index, const basic_string &str );
basic_string &insert( size_type index, const char *str );
basic_string &insert( size_type index1, const basic_string &str, size_type index2, size_type num );
basic_string &insert( size_type index, const char *str, size_type num );
basic_string &insert( size_type index, size_type num, char ch );
void insert( iterator i, size_type num, const char &ch );
void insert( iterator i, iterator start, iterator end );

basic_string substr( size_type index, size_type num = npos );

//erase
iterator erase( iterator pos );
iterator erase( iterator start, iterator end );
basic_string &erase( size_type index = 0, size_type num = npos );

//find
find( char, pos=0);
find(str,pos=0,len);    //从前len长度里查找

find_first_of(str,pos); //在源串中从位置pos起往后查找，只要在源串中遇到一个字符，该字符与目标串中任意一个字符相同，就停止查找

length();   
size();//   
const char * c_str();   //string to char *

string::iterator begin();
string::iterator end();
empty();
```
c中的字符判断函数

```c++
isalpha();  //check if character is alphabetic
isupper();  //check is upper
islower();  //check is lower
isdigit();  //check is number
```

## queue & stack

队列: 先进先出(FIFO)
  栈: 先进后出(FILO)

```c++
#include <queue>
queue<int> q;

empty();
size();
front();
back();

push(); //insert element at back
pop();//remove element at front

#include <stack>
stack<int> s;

empty();
size();
top();
push();// push to stack
pop();
```

```c++
//priority_queue: 优先队列
```


## algorithm

```c++
#include <algorithm>
int a[10];
vector<int> v;

//find
vector<int>::iterator s=find(v.begin(),v.end(),50);

//fill
fill(Iterator first, Iterator last, const T& value);
fill(v.begin(), v.end(), -1);
fill(a,a+10,-1);

//com
const T& min( const T& a, const T& b); // Returns the smaller of a and b.
ForwardIt min_element(ForwardIt first, ForwardIt last); //Finds the smallest element in the range [first, last)
int a[10];
min_element(a,a+10);//

sort(v.begin(),v.end());

#include<numeric>
accumulate(ivec.begin() , ivec.end() , 0);  // 求和
```

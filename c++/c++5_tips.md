## auto 遍历

```c++
//c++11

int a[]={1,2,3,4};
std::vector<int> a={1,2,3,4};
for(auto& e:a){
    std::cout<<e*2<<std::endl;
}

/*
1. auto &&:         modifiable access(不太理解，vector<bool>)
2. auto &:          reference access
3. const auto &:    read-only access
4. auto:            local copy
*/
```

## string -- int

```c++
/* char[] */
atoi(); //char[] to int
itoa(); //int to char[]
/* string */
#include <string>
stoi(); //string to int
stod(); //string to double
to_string();    //double/int to string

//大小写转换
char c,a;
if(isupper(c)) a=c+32;
else a=c-32;


//  int溢出 
//  用一个long先存储数据
long res=0;
int sign=1;
while(isdigit(str[i]) && i<str.size())
{
    res=res*10+(str[i++]-'0');
    if(res>INT_MAX) 
    {
        if(sign==1) return INT_MAX;
        else return INT_MIN;
    }
}
return res*sign;

//商和余数
int a,b;
a/b;
a%b;

#include<math.h>
double a,b;
fmod(a,b);
```



## tips

- sizeof(class) 只计算数据成员和虚函数表（地址）的大小，多重继承时，每一个继承维护一个虚函数。
- sizeof(char *) 为指针大小（4/8）， 而sizeof(char[])为字符串长度

```c++
//try catch
/*
- 执行 try 块中的语句，如果执行的过程中没有异常拋出，那么执行完后就执行最后一个 catch 块后面的语句，所有 catch 块中的语句都不会被执行；
- 如果 try 块执行的过程中拋出了异常，那么拋出异常后立即跳转到第一个“异常类型”和拋出的异常类型匹配的 catch 块中执行（称作异常被该 catch 块“捕获”），执行完后再跳转到最后一个 catch 块后面继续执行。
*/
try {
    语句组
}
catch(异常类型) {
    异常处理代码
}
...
catch(异常类型) {
    异常处理代码
}
```
**初始化数组**
```c++
//1. 全局变量和静态变量初始化时会自动被设置为0
int arr[1024]; // This is global
int main(void)
{
    //statements
}

//2. 如果一个数组被部分初始化，没有被初始化的元素会被自动设置为相应类型的0
int is[26]={0};

// 3. memset
```

**随机序列**

```c++
//随机打乱一个序列
//O(n)
vector<int> res;
for(int i=0;i<size_;i++){
    int pos=rand()%(size_-i);
    int tem=res[i+pos];
    res[i+pos]=res[i];
    res[i]=tem;
}
```
**缺失数字**

位运算中的异或

给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

> 输入: [3,0,1]
> 输出: 2

示例 2:

> 输入: [9,6,4,2,3,5,7,0,1]
> 输出: 8

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            result^=i^nums[i];
        }
        return result^nums.size();
    }
};
```

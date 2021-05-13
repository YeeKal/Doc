## OJ输入模板

```c++
// 同一行多个数字
int a,b;
cin>>a>>b;

// 多行输入
int n; // 数据的组数
cin >> n; // 读取组数
for(int i=0; i<n; ++i){
    int a, b;
    cin >> a >> b;
    cout << a+b <<endl;
}

// 一整行
string s;
getline(cin, s);

// 多行，行数未知
string str;
vector<string> vec;
while(getline(cin,str)){
    if(str.size()>0){
        vec.push_back(str);
    }
}
``` 

## 控制台输入

```c++
// 多个数字以空格隔开
int a,b,c;
cin>>a>>b>>c;

//单个字符串，无空格
string str;
cin>>str;

//读取一整行
string str;
getline(cin,str);

cin.getline(char[],len);//读取一定数目到字符数组

cin.sync();//清空控制台
```

## 文件读取

```c++
/* fstream: 逐行读取 */
#include <fstream>

string file_dir="Pt.txt";
ifstream pts_file;

pts_file.open(file_dir);
if(!pts_file.is_open()){
    cout<<"file is not opened\n";
    return -1;
}

string line;
while(getline(pts_file,line)){
    cout<<line.length()<<"\t"<<line<<endl;
}

/* fstream: 逐字符读入 */
ifstream in_file;
char c;
while (!infile.eof())
{
    infile >> c;
    cout<<c<<endl;
}
```
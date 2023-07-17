---
title: goosle test 使用
categories: linux
tags: linux
date: 2021-11-18
---

## intro

source code: https://github.com/google/googletest

下载下来编译安装：

```
mkdir build
cd build
cmake ..
make
```

## usage

```cpp
#include<gtest/gtest.h>
int add(int a,int b){
    return a+b;
}

TEST(testCase,test0){
    EXPECT_EQ(add(2,3),5);
}

TEST(testCase,test1){
    EXPECT_TRUE(add(2, 3) == 5);
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}


/* 直接编译 */
//  g++ gtest_demo.cpp -o gtest_demo -lgtest -lpthread

/* use camke */

/**
find_package(GTest REQUIRED)

add_executable(gtest_demo gtest_demo.cpp)
target_include_directories(gtest_demo PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(gtest_demo ${GTEST_BOTH_LIBRARIES}  pthread)
*/

```

## common grammar

- fatal failure: 断言失败则程序崩溃
- non-fatal failure: 断言失败程序继续运行

基础断言

| Fatal assertion          | Nonfatal assertion       | Verifies           |
| :----------------------- | :----------------------- | :----------------- |
| ASSERT_TRUE(condition);  | EXPECT_TRUE(condition);  | condition is true  |
| ASSERT_FALSE(condition); | EXPECT_FALSE(condition); | condition is false |


二值比较

| Fatal assertion       | Nonfatal assertion    | Verifies     |
| :-------------------- | :-------------------- | :----------- |
| ASSERT_EQ(val1,val2); | EXPECT_EQ(val1,val2); | val1 == val2 |
| ASSERT_NE(val1,val2); | EXPECT_NE(val1,val2); | val1 != val2 |
| ASSERT_LT(val1,val2); | EXPECT_LT(val1,val2); | val1 < val2  |
| ASSERT_LE(val1,val2); | EXPECT_LE(val1,val2); | val1 <= val2 |
| ASSERT_GT(val1,val2); | EXPECT_GT(val1,val2); | val1 > val2  |
| ASSERT_GE(val1,val2); | EXPECT_GE(val1,val2); | val1 >= val2 |

字符串比较

| Fatal assertion              | Nonfatal assertion           | Verifies                                                |
| :--------------------------- | :--------------------------- | :------------------------------------------------------ |
| ASSERT_STREQ(str1,str2);     | EXPECT_STREQ(str1,str2);     | the two C strings have the same content                 |
| ASSERT_STRNE(str1,str2);     | EXPECT_STRNE(str1,str2);     | the two C strings have different content                |
| ASSERT_STRCASEEQ(str1,str2); | EXPECT_STRCASEEQ(str1,str2); | the two C strings have the same content, ignoring case  |
| ASSERT_STRCASENE(str1,str2); | EXPECT_STRCASENE(str1,str2); | the two C strings have different content, ignoring case |


## 代码共用 Test Fixture

```cpp  
class FooTest : public ::testing::Test {
public:
    // 全局设置， 静态变量
    static void SetUpTestCase() {

    }

    static void TearDownTestCase() {

    }

    // 局部设置， 每个test有独立的上下文数据
    virtual void SetUp(){

    }

    virtual void TearDown(){

    }
}

```

静态成员需要预先初始化

---
title: industrical driver basic class
categories: ros
tags: industrical driver
date: 2018-10-12
---
[industrical](http://docs.ros.org/kinetic/api/simple_message/html/namespaceindustrial.html)

[ByteArray](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1byte__array_1_1ByteArray.html)

```c++
std::deque<char> buffer_; //双向队列存储数据
std::vector<char> getRawDataPtr_buffer_;//temporary continuous buffer for getRawDataPtr() use

load();//load the data to this,revise the size
unload();//upload this.data to data
```

[SimpleSerialize](http://docs.ros.org/kinetic/api/simple_message/html/simple__serialize_8h.html)

```c++
virtual unsigned int byteLength ()=0
//Virtual method returns the object size when packed into a ByteArray
virtual bool load (industrial::byte_array::ByteArray *buffer)=0
//Virtual method for loading an object into a ByteArray
virtual bool unload (industrial::byte_array::ByteArray *buffer)=0
//Virtual method for unloading an object from a ByteArray
```

**JointData**

```c++
/*
inherited from: simple_serialize
data: data_size and data_array
*/
private:
    shared_int MAX_NUM_JOINTS = 10;
    shared_real joints_[MAX_NUM_JOINTS];
```

**JointTraPt**

```c++
/*
inherited from: simple_serialize
data: 以joint_data为数据点
*/
private:
    shared_real duration;//joint move duration
    JointData joint_position_;
    shared_int sequence_;//sequence number 第几个点
    shared_real velovity_;
```

**JointTraj**

```c++
/*
inherited from: simple_serialize
*/
JointTrajPt points_ [MAX_NUM_POINTS];
static const shared_int MAX_NUM_POINTS = 200;
shared_int 	size_;
```


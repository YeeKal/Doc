
## thread

```cpp
class std::thread;
thread(f,n);
thread(f,ref(n));   // pass by reference

get_id();   
joinable();
join()
detach();
hardware_concurrency(); // 静态成员函数，返回当前计算机最大的硬件并发线程数目
```

## mutex
```cpp
#include <mutex>
// mutex, 最基本的线程锁，需要调用unlock释放
mutex mtx;
mtx.lock();
    // do omething
mtx.unlock();


// 创建即加锁，作用域结束自动释放锁
lock_guard<mutex> g(m);

// 线程同步.多个线程对同一个lock加同步锁，则线程间会等待另一个线程中的同步锁生命周期结束后才解锁。
// 使用方法很丰富，可以在需要的时候上锁或者解锁
std::mutex mymutex;
unique_lock<mutex> lock(mymutex);
unique_lock<mutex> g1(m, defer_lock);//始化了一个没有加锁的mutex
cout << "不拉不拉不拉" << endl;
g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock();注意，不是m.lock()
cout << "proc1函数正在改写a" << endl;
cout << "原始a为" << a << endl;
cout << "现在a为" << a + 2 << endl;
g1.unlock();//临时解锁
cout << "不拉不拉不拉"  << endl;
g1.lock();
cout << "不拉不拉不拉" << endl;
```


## condition_variable

用于多线程之间通信，配合`std::unique_lock`使用。当std::condition_variable对象的某个wait函数被调用的时候，它使用std::unique_lock(通过std::mutex)来锁住当前线程。当前线程会一直被阻塞，直到另外一个线程在相同的std::condition_variable对象上调用了notification函数来唤醒当前线程

```cpp
wait(); // 当前线程调用wait()后将被阻塞，直到另外某个线程调用notify_*唤醒当前线程
wait_for(); //可以指定一个时间
wait_until();   // 可以制定一个时间点
notify_all();   // 唤醒所有的wait线程
notify_one();   //唤醒某个wait线程，如果当前没有等待线程，则该函数什么也不做；
                //如果同时存在多个等待线程，则唤醒某个线程是不确定的(unspecified)
```

## future
异步线程

```cpp
#include <future>
double a = 2.3;
double b = 6.7;
future<double> fu = async(t1, a, b);//创建异步线程线程，并将线程的执行结果用fu占位；
cout << "正在进行计算" << endl;
cout << "计算结果马上就准备好，请您耐心等待" << endl;
cout << "计算结果：" << fu.get() << endl;//阻塞主线程，直至异步线程return
    //cout << "计算结果：" << fu.get() << endl;//取消该语句注释后运行会报错，因为future对象的get()方法只能调用一次。

```

## atomic

原子操作的数据类型（atomic_bool,atomic_int,atomic_long等等），对于这些原子数据类型的共享资源的访问，无需借助mutex等锁机制，也能够实现对共享资源的正确访问.

```cpp

```

## ref 

- blog
    - [生产者-消费者模型](https://blog.csdn.net/chenxun_2010/article/details/49848865)
- project
    - [A simple C++11 Thread Pool implementation](https://github.com/progschj/ThreadPool)
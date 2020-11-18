---
title: shared memory
categories: c++
tags: c++
date: 2019-05-20
---
## In C 

[进程间通信-共享内存](https://www.jianshu.com/p/014b6bd0b4da)

**System V API**

```c++
key_t ftok(const char *path, int id) // 创建key
int shmget(key_t key, size_t size, int shmflg) // 创建or获取共享内存
void *shmat(int shmid, const void *shmaddr, int shmflg) // 映射共享内存
int shmdt(const void *shmaddr) // 删除共享内存引用
int shmctl(int shmid, int cmd, struct shmid_ds *buf) // 控制共享内存(获取状态，修改属性，删除)
```

**Posix API**

```c++
int shm_open(const char *name, int oflag, ...);
int shm_unlink(const char *name);
void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t len);
int msync(void *addr, size_t len, int flags);
```

## iN C++

Boost

[共享内存(C++)](https://www.jianshu.com/p/56efa9d1500a)
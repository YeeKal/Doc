---
title: openrave learning
categories: planning
tags: openrave
date: 2019_10_23
---

## api

- [examples-python](http://openrave.org/docs/latest_stable/tutorials/openravepy_examples/)
- [write a plugin](http://openrave.org/docs/latest_stable/coreapihtml/writing_plugins.html)
- [c++ core api](http://openrave.org/docs/latest_stable/coreapihtml/annotated.html)
- [plugin list](http://www.openrave.org/docs/0.8.2/plugins/)
- [plugin api](https://github.com/rdiankov/openrave/tree/master/plugins/rplanners)
- [openrave.h](http://openrave.org/docs/latest_stable/coreapihtml/openrave_8h_source.html)

```c++
//dReal
#if OPENRAVE_PRECISION // 1 if double precision
typedef double dReal;
#define g_fEpsilon 1e-15
#else
typedef float dReal;
#define g_fEpsilon 2e-7f
#endif
```
## write a plugin
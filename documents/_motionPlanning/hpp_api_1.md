---
title: hpp api 1
categories: hpp
tags: planning
date: 2019_07_13
---
## Device

[device-api](https://gepettoweb.laas.fr/hpp/hpp-pinocchio/doxygen-html/a00067.html)


## Configuration_t

[hpp-pinocchio](https://gepettoweb.laas.fr/hpp/hpp-pinocchio/doxygen-html/a00106.html#aa4c05e8989d13ccf9f2d786b50142888)
```c++
typedef pinocchio::Configuration_t hpp::core::Configuration_t
typedef vector_t hpp::pinocchio::Configuration_t
typedef Eigen::Matrix<value_type, Eigen::Dynamic, 1> hpp::pinocchio::vector_t

typedef Eigen::Ref<const Configuration_t> hpp::pinocchio::ConfigurationIn_t
typedef Eigen::Ref<Configuration_t> hpp::pinocchio::ConfigurationOut_t
```

## Path

```c++
PathPtr_t path;
path->initial();        //return the first configuration
path->end();            //return the last configuration
typedef std::pair<value_type, value_type> hpp::core::interval_t
path->extract(const interval_t &subInterval);   //extract path in [t1,t2]
path->extract(t1,t2); 
```
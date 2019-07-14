---
title: hpp api 1
categories: hpp
tags: planning
date: 2019_07_13
---
## Device

- [device-api](https://gepettoweb.laas.fr/hpp/hpp-pinocchio/doxygen-html/a00067.html)
- [abstract device](https://gepettoweb.laas.fr/hpp/hpp-pinocchio/doxygen-html/a00061.html)
```c++
/***********************************************************************
hpp::pinocchio::AbstractDevice <-- hpp::pinocchio::Device
************************************************************************/
numberDof();        //
configSize();       //
nbJoints();         //number of (active) joints
currentConfiguration(); //return the current configuration
neutralConfiguration();

```

## ProblemSolver
the complete wrapper class

- [github cpp](https://github.com/humanoid-path-planner/hpp-core/blob/master/src/problem-solver.cc)

```c++
distanceType (const std::string& type);
steeringMethodType (const std::string& type);
pathPlannerType (const std::string& type);
configurationShooterType (const std::string& type);
addPathOptimizer (const std::string& type);
pathValidationType (const std::string& type,const value_type& tolerance);
```

## extraConfigspace

[ExtraConfigSpace](https://github.com/humanoid-path-planner/hpp-pinocchio/blob/master/include/hpp/pinocchio/extra-config-space.hh)
```c++
lower(i);
lower();
upper(i);
upper();
dimension();
private: setDimension();

size_type dimension_;
vector_t lowerBounds_;
vector_t upperBounds_;
friend class Device;
```


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

## Joint


## typedef

```c++
typedef ::pinocchio::SE3 hpp::pinocchio::Transform3f
typedef ::pinocchio::SE3 hpp::pinocchio::SE3

```


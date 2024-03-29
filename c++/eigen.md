---
title: conversition between eigen
categories: c++
tags: eigen
date: 2018-10-21
---
## 数据转换

```c++
int array[12];
Eigen::Map<Eigen::Matrix3i>(array);
MatrixXd eigenX = Map<MatrixXd>( array, nRows, nCols );
Eigen::Map<Eigen::VectorXi, 0, InnerStride<2> >(array, 6);

double a[6]={0.1,0.1,0.1,0.01,0.01,3.14159};
//double a[6]={0.1,0.1,0.1,0.1,0.1,0.1};
tolerance_=Eigen::Map<Eigen::VectorXd>(a,6); 

float* p = nullptr;
Eigen::Map<Eigen::MatrixXf>(p, m.rows(), m.cols());
Eigen::Map<Eigen::MatrixXf>(p, m.rows(), m.cols()) = m;//copy matrix to the pointer array

std::vector<float> vec;
Eigen::Map<Eigen::MatrixXf>(vec.data(), m.rows(), m.cols());
Eigen::Map<Eigen::MatrixXf>(vec.data(), m.rows(), m.cols()) = m;//copy matrix to vector

//vector/array 深度复制
p=new float[vec.size()];
memcpy(p, &vec[0], vec.size()*sizeof(float));

memcpy(&vec[0],p,10*sizeof(float));

double *array=new double[6];
Eigen::Map<Eigen::VectorXd> map(array,6);//share the same memory
//copy the <Eigen::Map> to construct vector
//does not share the memory
Eigen::VectorXd test1_eigen=Eigen::Map<Eigen::VectorXd>(array,6);

```

## geometry

- Eigen::Affine3d: 仿射变换=线性变换+平移
- EIgen::Isometry3d: 等距变换对应的是U矩阵($R*R=I$),欧式空间中的等距变换对应正交矩阵($R^TR=I$).

```c++

// isometry from rotation and translation
Eigen::Isometry3d t1=Eigen::Isometry3d::Identity();
t1.rotate(rot_max);
t1.pretranslate(trans_max);

// quaternion to matrix3d
Eigen::Quaterniond q1(w, x, y, z);// 第一种方式

Eigen::Quaterniond q2(Vector4d(x, y, z, w));// 第二种方式

Eigen::Quaterniond q2(Matrix3d(R));// 第三种方式
Eigen::Quaterniond q(w,x,y,z);
q.x() = 0;
q.y() = 1;
q.z() = 0;
q.w() = PI/8;    // Half of the rotation angle must be specified, even IDK why

Eigen::Matrix3d R = q.normalized().toRotationMatrix();

// rotation matrix to quaternion
Matrix3f mat;
Quaternionf q(mat);

Quaternionf q;
q = mat;

//  angle axis to rotation matrix
Eigen::Vector3d r;
r=start_rot1.eulerAngles(2,1,0);//z y x 按欧拉角顺序
Eigen::Matrix3d after;
after=(Eigen::AngleAxisd(r[0],Eigen::Vector3d::UnitZ()))* (Eigen::AngleAxisd(r[1], Eigen::Vector3d::UnitY()))*(Eigen::AngleAxisd(r[2], Eigen::Vector3d::UnitX()));

Eigen::Matrix3f m;
m = AngleAxisf(0.25*M_PI, Vector3f::UnitX())
  * AngleAxisf(0.5*M_PI, Vector3f::UnitY())
  * AngleAxisf(0.33*M_PI, Vector3f::UnitZ());

// rotation matrix ro axgle axis
Vector3f ea = m.eulerAngles(2, 1, 0);
    
```

```c++
Eigen::MatrixXd::Zero(6,6);
```

[eigen geometry reference](https://github.com/Ewenwan/MVision/blob/master/vSLAM/ch3/useGeometry/eigenGeometry.cpp)

eigen 构造函数进行转换

Matrix3d rot;
Quaterniond q(rot);

AngleAxis a(rot);

[] 只针对vector合法

Eigen::Ref<>:若不加const则无需加引用


## 求逆

```c++
//线性方程组求逆
Eigen::MatrixXd jac;
Eigen::VectorXd vels;
jac.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(vels);
jac.colPivHouseholderQr().solve(vels);

//正交基
Eigen::MatrixXd z_jac(z_axis.transpose());
Eigen::FullPivLU<Eigen::MatrixXd> decomp =z_jac.fullPivLu();
Eigen::MatrixXd phi( decomp.kernel().householderQr().householderQ() * Eigen::MatrixXd::Identity(3, 2));
```
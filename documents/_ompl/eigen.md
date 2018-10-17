## 数据转换

```c++
int array[12];
Eigen::Map<Eigen::Matrix3i>(array);
MatrixXd eigenX = Map<MatrixXd>( array, nRows, nCols );
Eigen::Map<Eigen::VectorXi, 0, InnerStride<2> >(array, 6);

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
```

## 几何变换

```c++
Eigen::Quaterniond q(w,x,y,z);
q.x() = 0;
q.y() = 1;
q.z() = 0;
q.w() = PI/8;    // Half of the rotation angle must be specified, even IDK why

Eigen::Matrix3d R = q.normalized().toRotationMatrix();
```
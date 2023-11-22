---
title: intro to ceres
categories: optimization
tags: optimization
date: 2022-01-01
---



## 基本用法

**<font color='Tomato'>Define a problem</font>**
```c++
Problem ceres_problem;
CostFunction* cost_function =
      new AutoDiffCostFunction<CostFunctor, 1, PARAM_NUM>(
          new CostFunctor(problem.s0, problem.s1));
ceres_problem.AddResidualBlock(cost_function, NULL, opt_params.data());
Solver::Options options;
Solver::Summary summary;
Solve(options, &ceres_problem, &summary);

// 常量设置
problem->SetParameterBlockConstant(&pose_start_iter->second.x);
void Problem::SetParameterLowerBound(double *values, int index, double lower_bound);                                              
void Problem::SetParameterUpperBound(double *values, int index, double upper_bound);

```

**<font color='Tomato'>Cost function</font>**

```cpp
// define cost function
struct CostFunctor {
  template <typename T>
  bool operator()(const T* const x, T* residual) const {
    residual[0] = 10.0 - x[0];
    return true;
  }
};

CostFunction* cost_function
    = new AutoDiffCostFunction<MyScalarCostFunctor, 1, 2, 2>(
        new MyScalarCostFunctor(1.0));              ^  ^  ^
                                                    |  |  |
                        Dimension of residual ------+  |  |
                        Dimension of x ----------------+  |
                        Dimension of y -------------------+
```

三种方式

```cpp
/ derivative: http://ceres-solver.org/gradient_tutorial.html
// 1. autodiff
//      - define template operator()
//      - add 
return new ceres::AutoDiffFirstOrderFunction<Rosenbrock, kNumParameters>(
        new Rosenbrock);
// 2. numeric differentiation
//      - define simple double operator()
//      - add 
return new ceres::NumericDiffFirstOrderFunction<Rosenbrock,
                                                    ceres::CENTRAL,
                                                    kNumParameters>(
        new Rosenbrock);

// 3. compute derivative by hand
// f(x,y) = (1-x)^2 + 100(y - x^2)^2;
class Rosenbrock final  : public ceres::FirstOrderFunction {
  public:
    ~Rosenbrock() override {}

    bool Evaluate(const double* parameters,
                           double* cost,
                           double* gradient) const override {
       const double x = parameters[0];
       const double y = parameters[1];

       cost[0] = (1.0 - x) * (1.0 - x) + 100.0 * (y - x * x) * (y - x * x);
       if (gradient) {
         gradient[0] = -2.0 * (1.0 - x) - 200.0 * (y - x * x) * 2.0 * x;
         gradient[1] = 200.0 * (y - x * x);
       }
      return true;
   }

   int NumParameters() const override { return 2; }
};
```


```cpp

// mass add
ceres::Problem problem;
for (int i = 0; i < bal_problem.num_observations(); ++i) {
  ceres::CostFunction* cost_function =
      SnavelyReprojectionError::Create(
           bal_problem.observations()[2 * i + 0],
           bal_problem.observations()[2 * i + 1]);
  problem.AddResidualBlock(cost_function,
                           nullptr /* squared loss */,
                           bal_problem.mutable_camera_for_observation(i),
                           bal_problem.mutable_point_for_observation(i));
}

```


## options

## lossfunction

抑制异常点

class Trivialloss 8
$$
\rho(s)=s
$$
class HuberLoss
$$
\rho(s)= \begin{cases}s & s \leq 1 \\ 2 \sqrt{s}-1 & s>1\end{cases}
$$
class softLoneLoss
$$
\rho(s)=2(\sqrt{1+s}-1)
$$
class CauchyLoss
$$
\rho(s)=\log (1+s)
$$
class ArctanLoss
$$
\rho(s)=\arctan (s)
$$
class TolerantLoss
$$
\rho(s, a, b)=b \log \left(1+e^{(s-a) / b}\right) \ldots b \log \left(1+e^{-a / b}\right)
$$


CauchyLoss example
```c++

//  change
problem.AddResidualBlock(cost_function, nullptr , &m, &c);
//  to
problem.AddResidualBlock(cost_function, new CauchyLoss(0.5) , &m, &c);
//  to add kernel loss function
```

$$\min \sum(r^2_i) \quad \longrightarrow \quad \min c^2\cdot log(1+(\frac{r_i}{c})^2)$$

## Manifold


**<font color='Tomato'>Manifold</font>**

Manifold 是用来描述问题中优化变量所属的拓扑空间（topological space）或者几何体（manifold）.比如在处理方向或旋转时，他们并不在常规的欧氏空间（Euclidean space） 常常把它们视为特殊的流形。比如说SO(3)，即3D旋转矩阵构成的流形，虽然我们可以用3x3矩阵来表示一个旋转，但是这9个参数并不是全部自由的，实际上只有3个自由度，并且需要满足一些约束条件。

Manifold 提供一个通用的接口，可以自定义+/-以及梯度。

```cpp
class Manifold {
 public:
  virtual ~Manifold();
  virtual int AmbientSize() const = 0;
  virtual int TangentSize() const = 0;
  virtual bool Plus(const double* x,
                    const double* delta,
                    double* x_plus_delta) const = 0;
  virtual bool PlusJacobian(const double* x, double* jacobian) const = 0;
  virtual bool RightMultiplyByPlusJacobian(const double* x,
                                           const int num_rows,
                                           const double* ambient_matrix,
                                           double* tangent_matrix) const;
  virtual bool Minus(const double* y,
                     const double* x,
                     double* y_minus_x) const = 0;
  virtual bool MinusJacobian(const double* x, double* jacobian) const = 0;
};
```

**<font color='Tomato'>AutoDiffManifold</font>**

```cpp
ceres::Manifold* angle_manifold = AngleManifold::Create();
problem->SetManifold(&yaw_radians, angle_manifold);


// Defines a manifold for updating the angle to be constrained in [-pi to pi).
class AngleManifold {
 public:
  template <typename T>
  bool Plus(const T* x_radians,
            const T* delta_radians,
            T* x_plus_delta_radians) const {
    *x_plus_delta_radians = NormalizeAngle(*x_radians + *delta_radians);
    return true;
  }

  template <typename T>
  bool Minus(const T* y_radians,
             const T* x_radians,
             T* y_minus_x_radians) const {
    *y_minus_x_radians =
        NormalizeAngle(*y_radians) - NormalizeAngle(*x_radians);

    return true;
  }

  static ceres::Manifold* Create() {
    return new ceres::AutoDiffManifold<AngleManifold, 1, 1>;
  }
};
```

- relative: [MatrixManifoldsInCeres](https://github.com/tolgabirdal/MatrixManifoldsInCeres)

## 曲线拟合实现

使用模板 为了与ceres兼容

**<font color='Tomato'>样条曲线</font>**

- 输入 为控制点
- 输出 曲线参数

一般使用有限个控制点生成多段曲线，优化变量为中间控制点的横向偏移而不是曲线参数


## ref

- [pose-graph-optimization](https://github.com/shinsumicco/pose-graph-optimization)
- [curvefitting](https://github.com/mpkuse/advanced_techniques_for_curvefitting)
- [Parameter Estimation Techniques: A Tutorial with Application to Conic Fitting, Zhengyou Zhang]()
- [Ceres Solver Python Tutorial](https://notes.andrewtorgesen.com/doku.php?id=public:ceres)



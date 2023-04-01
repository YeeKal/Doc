---
title: intro to ceres
categories: optimization
tags: optimization
date: 2022-01-01
---



## basic structure

```c++
Problem ceres_problem;
CostFunction* cost_function =
      new AutoDiffCostFunction<CostFunctor, 1, PARAM_NUM>(
          new CostFunctor(problem.s0, problem.s1));
ceres_problem.AddResidualBlock(cost_function, NULL, opt_params.data());
Solver::Options options;
Solver::Summary summary;
Solve(options, &ceres_problem, &summary);


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

// derivative: http://ceres-solver.org/gradient_tutorial.html
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


## ref

- [pose-graph-optimization](https://github.com/shinsumicco/pose-graph-optimization)
- [curvefitting](https://github.com/mpkuse/advanced_techniques_for_curvefitting)
- [Parameter Estimation Techniques: A Tutorial with Application to Conic Fitting, Zhengyou Zhang]()
- [Ceres Solver Python Tutorial](https://notes.andrewtorgesen.com/doku.php?id=public:ceres)



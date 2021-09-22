## 

```c++
#include <acado_toolkit.hpp>
#include <acado_gnuplot.hpp>
/**
 * optimal control demo:
 * 
 * 最优控制与轨迹优化
 * 
 * 定义状态方程
 * 定义约束
 * 定义目标函数
 */ 
 
int main(){
    USING_NAMESPACE_ACADO
 
    DifferentialState q1,q2,dot_q1,dot_q2;
    Control u_a;
    // Parameter T; // 约束变量，而又不是优化参数
    double Ts = 0.2;
    double T= 2;
    double m1=1.0;
    double m2=0.3;
    double l= 0.5;
    double g=9.81;
    double d=1.0;

 
    DifferentialEquation f(0.0,T);
    f << dot(q1) == dot_q1;
    f << dot(q2) == dot_q2;
    f << dot(dot_q1) == (l*m2*sin(q2)*dot_q2*dot_q2+u_a+m2*g*cos(q2)*sin(q2))/(m1+m2*(1-cos(q2)*cos(q2)));
    f << dot(dot_q2) ==  -(l*m2*cos(q2)*sin(q2)*dot_q2*dot_q2+u_a*cos(q2)+(m1+m2)*g*sin(q2))/(l*m1+l*m2*(1-cos(q2)*cos(q2)));
 
    Function h;     // 优化目标
    h << u_a;
    
    // 权重参数矩阵
    DMatrix Q(1,1);    
    Q(0,0) = 1.0;
    
    // 偏移量
    DVector r(1);
    r.setAll(0.0);
    
    // ocp(start, end, step_number)
    // step_number 指定中间间隔步长，银子如果算上起始变量，实际变量个数应为 step_number + 1
    OCP ocp(0.0,T,50);
    ocp.minimizeLSQ(Q,h,r);
 
    ocp.subjectTo(f);       // 约束方程

    // 起点约束
    ocp.subjectTo(AT_START, q1 == 0.0);
    ocp.subjectTo(AT_START, q2 == 0.0);
    ocp.subjectTo(AT_START, dot_q1 == 0.0);
    ocp.subjectTo(AT_START, dot_q2 == 0.0);
    

    // 终点约束
    ocp.subjectTo(AT_END, q1 == d);
    ocp.subjectTo(AT_END, q2 == 3.14159);
    ocp.subjectTo(AT_END, dot_q1 == 0.0);
    ocp.subjectTo(AT_END, dot_q2 == 0.0);
 
    ocp.subjectTo(0 <= q1 <= 2);
    ocp.subjectTo(-20<= u_a <= 20);
    // ocp.subjectTo(0.0 <= T <= 3.0);
 
    OptimizationAlgorithm algorithm(ocp);
 
    GnuplotWindow window;
    window.addSubplot(q1, "Distance m1");
    window.addSubplot(q2,"angle pole");
    window.addSubplot(dot_q1,"velocity m1");
    window.addSubplot(u_a,"control u_a");
    algorithm << window;
    algorithm.solve();
 
    return 0;
    
}
```
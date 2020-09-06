
```c++
void add(InputArray src1, InputArray src2, OutputArray dst,InputArray mask=noArray(), int dtype=-1);//dst = src1 + src2
void subtract(InputArray src1, InputArray src2, OutputArray dst,InputArray mask=noArray(), int dtype=-1);//dst = src1 - src2
void multiply(InputArray src1, InputArray src2,OutputArray dst, double scale=1, int dtype=-1);//dst = scale*src1*src2
void divide(InputArray src1, InputArray src2, OutputArray dst,double scale=1, int dtype=-1);//dst = scale*src1/src2
void divide(double scale, InputArray src2,OutputArray dst, int dtype=-1);//dst = scale/src2
void scaleAdd(InputArray src1, double alpha, InputArray src2, OutputArray dst);//dst = alpha*src1 + src2
void addWeighted(InputArray src1, double alpha, InputArray src2,double beta, double gamma, OutputArray dst, int dtype=-1);//dst = alpha*src1 + beta*src2 + gamma
void sqrt(InputArray src, OutputArray dst);//计算每个矩阵元素的平方根
void pow(InputArray src, double power, OutputArray dst);//src的power次幂
void exp(InputArray src, OutputArray dst);//dst = e**src（**表示指数的意思）
void log(InputArray src, OutputArray dst);//dst = log(abs(src))

// bit operation
/*
1. bitwise_and是对二进制数据进行“与”操作，即对图像（灰度图像或彩色图像均可）每个像素值进行二进制“与”操作，1&1=1，1&0=0，0&1=0，0&0=0
2. bitwise_or是对二进制数据进行“或”操作，即对图像（灰度图像或彩色图像均可）每个像素值进行二进制“或”操作，1|1=1，1|0=0，0|1=0，0|0=0
3. bitwise_xor是对二进制数据进行“异或”操作，即对图像（灰度图像或彩色图像均可）每个像素值进行二进制“异或”操作，1^1=0,1^0=1,0^1=1,0^0=0
4. bitwise_not是对二进制数据进行“非”操作，即对图像（灰度图像或彩色图像均可）每个像素值进行二进制“非”操作，~1=0，~0=1
*/
bitwise_and、bitwise_or、bitwise_xor、bitwise_not这四个按位操作函数。
void bitwise_and(InputArray src1, InputArray src2,OutputArray dst, InputArray mask=noArray());//dst = src1 & src2
void bitwise_or(InputArray src1, InputArray src2,OutputArray dst, InputArray mask=noArray());//dst = src1 | src2
void bitwise_xor(InputArray src1, InputArray src2,OutputArray dst, InputArray mask=noArray());//dst = src1 ^ src2
void bitwise_not(InputArray src, OutputArray dst,InputArray mask=noArray());//dst = ~src
```

**reference**

1. [OpenCV之bitwise_and、bitwise_not等图像基本运算及掩膜](https://blog.csdn.net/u011028345/article/details/77278467)



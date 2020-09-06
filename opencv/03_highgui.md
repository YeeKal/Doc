## filter

- 方框滤波——boxblur函数
- 均值滤波（邻域平均滤波）——blur函数
- 高斯滤波——GaussianBlur函数
- 中值滤波——medianBlur函数
- 双边滤波——bilateralFilter函数

低通就是模糊，高通就是锐化.
邻域算子(Neighbourhood operator),卷积核。

** linear filter **

```c++
//box filter
boxFilter(img, out, -1, Size(5,5));
blur(InputArray src, OutputArray dst, Size ksize);
GaussianBlur(img, gau, Size(size_filter*2+1,size_filter*2+1), 0,0);//正奇数
```

**nonlinear filter **

median filter(中值滤波)：把数字图像或数字序列中一点的值用该点的一个邻域中各点值的中值代替，去噪声能力高，但是计算量更大（相比与boxFilter）。

bilateral filter(双边滤波): 取最邻近值。

```c++
medianBlur(img, med, size_filter*2+3);//odd and greater than 1
bilateralFilter(img, bia, 5, 50, 12);mor
```
## morphology

```c++
enum    cv::MorphShapes { 
  cv::MORPH_RECT = 0, 
  cv::MORPH_CROSS = 1, 
  cv::MORPH_ELLIPSE = 2 
}
    shape of the structuring element

enum    cv::MorphTypes { 
  cv::MORPH_ERODE = 0, 
  cv::MORPH_DILATE = 1, 
  cv::MORPH_OPEN = 2, 
  cv::MORPH_CLOSE = 3, 
  cv::MORPH_GRADIENT = 4, 
  cv::MORPH_TOPHAT = 5, 
  cv::MORPH_BLACKHAT = 6, 
  cv::MORPH_HITMISS = 7 
}
    type of morphological operation
```
**erode and dilate**

膨胀就是图像中的高亮部分进行膨胀，“领域扩张”，效果图拥有比原图更大的高亮区域。腐蚀就是原图中的高亮部分被腐蚀，“领域被蚕食”，效果图拥有比原图更小的高亮区域。膨胀在数学上可以看做是原图与核的卷积中取最大值，而腐蚀是取最小值。

```c++
    Mat element = getStructuringElement(element_shape, Size(an*2+1, an*2+1), Point(an, an) );
    Mat element=getStructuringElement(MORPH_RECT, Size(15,15));
        //MORPH_RECT  MORPH_CROSS  MORPH_ELLIPSE
  erode(img, ero, element);
  dilate(img, dia, element);
```

**higher api**

opening operation: 先腐蚀后膨胀，可以用来消除小物体、在纤细点处分离物体、平滑较大物体的边界的同时并不明显改变其面积。

closing operation: 先腐蚀后膨胀

morphological gradient:膨胀与腐蚀之差，突出团块边缘，可以保留物体的轮廓

top hat: 原图与开运算之差。开运算带来的结果是放大了裂缝或者局部低亮度的区域，从原图中减去开运算后的图，得到的效果图突出了比原图轮廓周围的区域更明亮的区域。顶帽运算往往用来分离比邻近点亮一些的斑块。当一幅图像具有大幅的背景的时候，而微小物品比较有规律的情况下，可以使用顶帽运算进行背景提取。

black hat: 闭运算与原图之差

## feature detection

**边缘检测算子**

```c++
Canny(img,out,50,150,3);
Sobel();
Scharr();
Laplacian();

```
**hough transform**

在特征提取中，霍夫变换可以检测直线和圆。对于经过某一点的直线可唯一由(r，$\theta$)来确定，若两点有相同的参数，则两点在同一条直线上。而对于经过一点的圆由三个参数（a,b,r）来确定，若三点的三个参数相等，则三个点共圆。

```c++
HoughLines(midImg, lines, 1, CV_PI/180, 200);
HoughLinesP(midImg, plines, 1, CV_PI/180, 100,30,5);
HoughCircles(destImg_circle, circles, HOUGH_GRADIENT, 2, 10,200,100);
```

**flood fill**

漫水填充:自动选中了和种子点相连的区域，接着将该区域替换成指定的颜色.

**corner**

```c++
//geometrical transformation
remap();
dst_img.create(kaola_img.size(), kaola_img.type());
map_x.create(kaola_img.size(), CV_32FC1);//col
map_y.create(kaola_img.size(), CV_32FC1);//row

for(int i=0;i<kaola_img.rows;i++){
    for(int j=0;j<kaola_img.cols;j++){
        map_x.at<float>(i,j)=static_cast<float>(j);
        map_y.at<float>(i,j)=static_cast<float>(kaola_img.rows-i);
    }
}

remap(kaola_img, dst_img, map_x, map_y, CV_INTER_LINEAR);
```

## 直方图(Histogram)

图像直方图是反映一个图像像素分布的统计表，其实横坐标代表了图像像素的种类，可以是灰度的，也可以是彩色的。纵坐标代表了每一种颜色值在图像中的像素总数或者占所有像素个数的百分比。

比如图像灰度直方图表示第k个灰度级的个数。而归一化直方图表示第k个灰度级出现的数量比上所有灰度级的数量总和。

均衡化(Histogram Equalization): 尽量使得每个灰度级的像素数量相等.





[TOC]

[opencv马拉松-csdn](https://blog.csdn.net/abcd1992719g/article/category/9262421/2)

**ubuntu**
include files:

```c++
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp >
#include <opencv2/highgui.hpp>

using namespace cv;
```

## 载入和显示

cv::Mat: 保存图像数据的数据结构

```c++
Mat imread(const string& filename,intflags=1);
//flags >0返回一个3通道的彩色图像。
//flags =0返回灰度图像。
//flags <0返回包含Alpha通道的加载的图像。
void nameWindow(const string& winname,int flags=WINDOW_AUTOSIZE );
/*
WINDOW_NORMAL设置了这个值，用户便可以改变窗口的大小（没有限制）
WINDOW_AUTOSIZE如果设置了这个值，窗口大小会自动调整以适应所显示的图像，并且不能手动改变窗口大小。
WINDOW_OPENGL 如果设置了这个值的话，窗口创建的时候便会支持OpenGL。
*/
void imshow(const string& winname, InputArray mat); 
//要显示的窗口和要显示的图像
bool imwrite(const string& filename,InputArray img, const vector<int>& params=vector<int>() );  
waitKey(0);//无限制等待
waitKey(5);//5ms为一个循环等待，若没有按下按键则继续等待
```

## 图像混合

**ROI**

感兴趣区域

```c++
Mat imageROI;
imageROI=image(Rect(500,250,logo.cols,logo.rows)); //way1
imageROI=srcImage3(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));//way2
```

**混合图像操作**

```c++
Mat weigImag(string picname1, string picname2) {
	Mat img1 = imread(picname1);
	Mat img2 = imread(picname2);
	Mat imgroi = img1(Rect(200, 250, img2.cols, img2.rows));//region of interest

	Mat mask = imread(picname2, 0);//灰度图
	img2.copyTo(imgroi, mask);
	return img1;
}
```

**线性混合**

```c++
void addWeighted(InputArray src1, double alpha, InputArray src2, double beta, double gamma, OutputArray dst, int dtype=-1); 
//dst = src1[I]*alpha+ src2[I]*beta + gamma;
```

```c++
Mat linearBlend(string picname1, string picname2) {
	Mat img1 = imread(picname1);
	Mat img2 = imread(picname2);
	Mat imgroi = img1(Rect(200, 250, img2.cols, img2.rows));//region of interest
		//两幅混合图像尺寸要一样大，故在此设置感兴趣区域
	addWeighted(imgroi, 0.5, img2, 0.5, 0, imgroi);
	return img1;
}
```
**channels split**

```c++
vector<Mat> channels;
split(image,channels);//split channels
merge(channels,image);//combine channels
Mat img=channels.at(0);
```
**track bar**

```c++
C++: int createTrackbar(conststring& trackbarname, conststring& winname, 
 int* value, int count, TrackbarCallback onChange=0,void* userdata=0); 
```

## draw

[ref](https://docs.opencv.org/master/d3/d96/tutorial_basic_geometric_drawing.html)

```c++
//data types
Point pt;
pt.x = 10;
pt.y = 8;
Point pt =  Point(10, 8);

//Represents a 4-element vector. 
//The type Scalar is widely used in OpenCV for passing pixel values.
//It is not necessary to define the last argument if it is not going to be used.
Scalar( a, b, c )

rectangle( rook_image,
         Point( 0, 7*w/8 ),
         Point( w, w),
         Scalar( 0, 255, 255 ),
         FILLED,
         LINE_8 );

ellipse( img,
       Point( w/2, w/2 ),
       Size( w/4, w/16 ),
       angle,
       0,
       360,
       Scalar( 255, 0, 0 ),
       thickness,
       lineType );
 circle( img,
      center,
      w/32,
      Scalar( 0, 0, 255 ),
      FILLED,
      LINE_8 );
line( img,
    start,
    end,
    Scalar( 0, 0, 0 ),
    thickness,
    lineType );
```





**initialize**

```c++
//mat constructor
int rows=400,cols=600;//rows,列数，cols,行数
cv::Size size(cols,rows); //

cv::Mat myMat(rows,cols,CV_8UC3,Scalar(0,0,255));//行列与size，point不同
CV::Mat myMat=cv::Mat(rows,cols,CV_8UC1)
cv::Mat myMat(size,CV_8UC1);

Mat map = Mat::zeros(800, 600, CV_8UC1);//ones/eye/zeros
```

在cv::Size和cv::Point中x为cols/width， y为rows/height，方向与图片坐标不同。


**copy**

```
Mat A,B;//create the header parts
A=imread("img.png"); //allocate matrix
Mat C(A);   //copy constructor
B=A;   //assignment operator    
//these three point to the same single data matrix,
//even with different headers

//deep copy, copy the matrix data
B=A.clone();
A.copyTo(B);
Mat RowClone = C.row(1).clone();

//slice
img_creata.rowRange(0, 4).colRange(0,3);
```

**visit**

```c++
//method1
map.at<uchar>(row, col) = 1;
img.at<Vec3b>(i,j)[k];  
//method2
uchar *data=(uchar*)map.data;
int index=i*cols+j;i=0;//rows-1
data[index];
/*
if color : 
    data[index * 3 + 0] = 0；
    data[index * 3 + 1] = 0;
    data[index * 3 + 2] = 0;
 */

//method3
//ptr()  Returns a pointer to the specified matrix row
for ( int i=0; i<rows; i++ )
{
    uchar *data = image.ptr<uchar>( i );
    for ( int j=0; j<cols; j++ )
    {
        data[j] = 0;
        //*data++=0;
        /*
            if color one:
            data[j*3 + 0] = 0;
            data[j*3 + 1] = 0;
            data[j*3 + 2] = 0;
        */
    }
}

```

**convert**

[cvtColor](https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor)
```c++
void cvtColor(InputArray src, OutputArray dst, int code, int dstCn=0 );

//usual
cvtColor(src, bwsrc, CV_RGB2GRAY);
// dst=0.299r+0.587g+0.114b

Mat Mat::clone();
void Mat::copyTo(OutputArray m);
copyTo(OutputArray m, InputArray mask);
```

**type**

|        | C1   | C2   | C3   |  C4  |
| ------ | ---- | ---- | ---- | ---- |
| CV_8U  | 0    | 8    | 16   | 24   |
| CV_8S  | 1    | 9    | 17   | 25   |
| CV_16U | 2    | 10   | 18   | 26   |
| CV_16S | 3    | 11   | 19   | 27   |
| CV_32S | 4    | 12   | 20   | 28   |
| CV_32F | 5    | 13   | 21   | 29   |
| CV_64F | 6    | 14   | 22   | 30   |

|C1| C2 | C3|  C4|  C6|
| ------ | ---- | ---- | ---- | ---- |
uchar |  uchar |  cv::Vec2b|   cv::Vec3b |  cv::Vec4b|
short  | short|   cv::Vec2s  | cv::Vec3s  | cv::Vec4s|
int |int| cv::Vec2i  | cv::Vec3i|   cv::Vec4i|
float|   float  | cv::Vec2f  | cv::Vec3f |  cv::Vec4f |  cv::Vec6f|
double|  double|  cv::Vec2d |  cv::Vec3d  | cv::Vec4d  | cv::Vec6d|

```c++
template<typename _Tp, int n> class Vec : public Matx<_Tp, n, 1> {...};

typedef Vec<uchar, 2> Vec2b;
typedef Vec<uchar, 3> Vec3b;
typedef Vec<uchar, 4> Vec4b;

typedef Vec<short, 2> Vec2s;
typedef Vec<short, 3> Vec3s;
typedef Vec<short, 4> Vec4s;

typedef Vec<int, 2> Vec2i;
typedef Vec<int, 3> Vec3i;
typedef Vec<int, 4> Vec4i;

typedef Vec<float, 2> Vec2f;
typedef Vec<float, 3> Vec3f;
typedef Vec<float, 4> Vec4f;
typedef Vec<float, 6> Vec6f;

typedef Vec<double, 2> Vec2d;
typedef Vec<double, 3> Vec3d;

typedef Vec<double, 4> Vec4d;
typedef Vec<double, 6> Vec6d;

```


1. [type in opencv](https://www.jianshu.com/p/204f292937bb)
2. [vector深度拷贝](https://blog.csdn.net/hust_bochu_xuchao/article/details/72850862)
3. 虽然我们都说RGB,但实际存储是BGR,第一个byte是blue
4. CV_32F范围是[0.0-1.0]


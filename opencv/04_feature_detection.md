##general

```c++
//特征提取的统一接口
Ptr<FeatureDetector> detector = FeatureDetector::create();
FeatureDetectot->detect(Mat <object>,std::vector<KeyPoint>);
FeatureDetectot->compute(Mat <object>,Mat <descriptor>);
FeatureDetectot->detectAndCompute(Mat <object>,Mat(),vector<KeyPoint>,Mat <descriptor>);


```

## sift

## surf

## orb

## fast
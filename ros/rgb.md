---
title: web camera in ros
categories: ros
tags: computer vision
date: 2018-05-19
---

## open the web camera

```
#require packages
usb_cam

#run
roslaunch usb_cam usb_cam-test.launch 
    #ofcourse you can build another launch file in your own package
    #to diy the params
```

## kinect driver

```
#require packages
openni2_camera
openni2_launch
image_view

#run
roscore
roslaunch openni2_launch openni2.launch
rosrun image_view image_view imag:=/camera/depth/image
```

**openni_camera**

[reference](https://my.oschina.net/sunzhiming/blog/408474)

**openni_launch**

[launch](http://wiki.ros.org/openni_launch)

**errors**

- primesense_Warning: USB events thread - failed to set priority. This might cause loss of data
    - sudo -s


## calibrate a monocular camera

> rosrun camera_calibration cameracalibrator.py --size 8x7 --square 0.025 image:=/camera/rgb/image_raw camera:=/camera/rgb

**kinect result**

```
('D = ', [0.04705851105125837, -0.16011921239065316, 0.002059536895705162, -0.0008912326362268281, 0.0])
('K = ', [534.3043369960869, 0.0, 310.98616217191346, 0.0, 534.974358588841, 230.29287061389448, 0.0, 0.0, 1.0])
('R = ', [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
('P = ', [532.0972290039062, 0.0, 309.96771653092947, 0.0, 0.0, 536.6486206054688, 230.89104796466563, 0.0, 0.0, 0.0, 1.0, 0.0])
None
# oST version 5.0 parameters


[image]

width
640

height
480

[narrow_stereo]

camera matrix
534.304337 0.000000 310.986162
0.000000 534.974359 230.292871
0.000000 0.000000 1.000000

distortion
0.047059 -0.160119 0.002060 -0.000891 0.000000

rectification
1.000000 0.000000 0.000000
0.000000 1.000000 0.000000
0.000000 0.000000 1.000000

projection
532.097229 0.000000 309.967717 0.000000
0.000000 536.648621 230.891048 0.000000
0.000000 0.000000 1.000000 0.000000

```

**usb cam**

```
('D = ', [-0.007491278130383288, -0.07074561089562179, -0.0031065863775797736, -0.002144833588196088, 0.0])
('K = ', [647.9671808840058, 0.0, 324.71156168768897, 0.0, 649.2919825544608, 219.1072839157247, 0.0, 0.0, 1.0])
('R = ', [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
('P = ', [644.1636962890625, 0.0, 323.7579115530316, 0.0, 0.0, 647.3536376953125, 218.08820951721646, 0.0, 0.0, 0.0, 1.0, 0.0])
None
# oST version 5.0 parameters


[image]

width
640

height
480

[narrow_stereo]

camera matrix
647.967181 0.000000 324.711562
0.000000 649.291983 219.107284
0.000000 0.000000 1.000000

distortion
-0.007491 -0.070746 -0.003107 -0.002145 0.000000

rectification
1.000000 0.000000 0.000000
0.000000 1.000000 0.000000
0.000000 0.000000 1.000000

projection
644.163696 0.000000 323.757912 0.000000
0.000000 647.353638 218.088210 0.000000
0.000000 0.000000 1.000000 0.000000


('D = ', [-0.007491278130383288, -0.07074561089562179, -0.0031065863775797736, -0.002144833588196088, 0.0])
('K = ', [647.9671808840058, 0.0, 324.71156168768897, 0.0, 649.2919825544608, 219.1072839157247, 0.0, 0.0, 1.0])
('R = ', [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0])
('P = ', [644.1636962890625, 0.0, 323.7579115530316, 0.0, 0.0, 647.3536376953125, 218.08820951721646, 0.0, 0.0, 0.0, 1.0, 0.0])
# oST version 5.0 parameters


[image]

width
640

height
480

[narrow_stereo]

camera matrix
647.967181 0.000000 324.711562
0.000000 649.291983 219.107284
0.000000 0.000000 1.000000

distortion
-0.007491 -0.070746 -0.003107 -0.002145 0.000000

rectification
1.000000 0.000000 0.000000
0.000000 1.000000 0.000000
0.000000 0.000000 1.000000

projection
644.163696 0.000000 323.757912 0.000000
0.000000 647.353638 218.088210 0.000000
0.000000 0.000000 1.000000 0.000000

```

##access opencv in ros with kinect

[tutorial]()


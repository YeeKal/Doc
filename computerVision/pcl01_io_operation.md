---
title: ch1-introduction
categories: cv
tags: cv
date: 2019-08-10
---

## ref

- [official tutorial](http://pointclouds.org/documentation/tutorials/)
- [personal pcl notes-github ](https://github.com/MNewBie/PCL-Notes)
- [personal-csdn](https://blog.csdn.net/xuezhisdc/article/details/51018872)
- [icp-zhihu](https://zhuanlan.zhihu.com/p/30327449)
- [models](https://www.cc.gatech.edu/projects/large_models/)

## point data

- PointXYZ
- PointXYZI
- PointXYZRGBA
- PointXYZRGB
- PointXY
- InterestPoint
- Normal
- PointNormal
- PointXYZRGBNormal
- PointXYZINormal

## read/write

**pcb file**
point cloud data file format
```c++
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

typedef pcl::PointXYZ PointT;

int main (int argc, char** argv)
{
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
    //read pcd
	if(pcl::io::loadPCDFile<PointT>("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd",*cloud)==-1){
		PCL_ERROR("could not read file\n");
		return (-1);
	}

	for(size_t i=0;i<cloud->points.size();i++){
		cloud->points[i].x = 20*cloud->points[i].x;
        cloud->points[i].y = 20*cloud->points[i].y;
        cloud->points[i].z = 20*cloud->points[i].z;
	}

	std::cout<<"width:"<<cloud->width<<"\t height:"<<cloud->height<<std::endl;
	std::cout<<"cloud size:"<<cloud->size()<<std::endl;
    //save pcd
	pcl::io::savePCDFile("bunny_saved.pcd", *cloud);

	return 0;
}
```

**ply**
 polygon file format
```c++
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/io/ply_io.h>//ply
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

typedef pcl::PointXYZ PointT;

int main (int argc, char** argv)
{
	pcl::PolygonMesh mesh;
	pcl::io::loadPLYFile("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.ply", mesh);
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->addPolygonMesh(mesh,"mesh");
	while(!viewer->wasStopped()){
		viewer->spinOnce();
	}
    //pcl::io::savePLYFile("saveName.ply", mesh);
	return 0;
}

```

**ply to pcd**
```c++
//1
pcl::PCLPointCloud2 clod;
pcl::PLYReader reader;
reader.read("raw.ply", clod);
pcl::PCDWriter writer;
writer.writeASCII("raw11.pcd", clod); 
//2
pcl::PLYReader reader;
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
reader.read<pcl::PointXYZ>("coffee_table_1_2.ply", *cloud);
pcl::io::savePCDFile("pointcloud.pcd", *cloud );
```

## viewer
CloudViewer
```c++
pcl::visualization::CloudViewer viewer("Cloud Viewer");
viewer.showCloud(cloud);
//callback function
// viewer.runOnVisualizationThreadOnce (viewerOneOff);
// viewer.runOnVisualizationThread (viewerPsycho);
while(!viewer.wasStopped()){

}
```
PCLVisualizer
[more](http://pointclouds.org/documentation/tutorials/pcl_visualizer.php#pcl-visualizer)
```c++
#include <ros/ros.h>
// PCL specific includes
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
// pcl in ros
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>


typedef pcl::PointXYZ PointT;

int main (int argc, char** argv)
{
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
	if(pcl::io::loadPCDFile<PointT>("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd",*cloud)==-1){
		PCL_ERROR("could not read file\n");
		return (-1);
	}
	for(size_t i=0;i<cloud->points.size();i++){
		cloud->points[i].x = 20*cloud->points[i].x;
        cloud->points[i].y = 20*cloud->points[i].y;
        cloud->points[i].z = 20*cloud->points[i].z;
	}

//visualizer
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->setBackgroundColor(0, 0, 0);
	viewer->addPointCloud<pcl::PointXYZ>(cloud, "sample cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
	viewer->addCoordinateSystem(1.0);
	viewer->initCameraParameters();
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
	
	return 0;
}

```

rviz
```c++
#include <ros/ros.h>
// PCL specific includes
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
// pcl in ros
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

typedef pcl::PointXYZ PointT;

int main (int argc, char** argv)
{
	//Initialize ROS
	ros::init (argc, argv, "pcl_temp");
	ros::NodeHandle nh;
	ros::Publisher pcl_pub = nh.advertise<sensor_msgs::PointCloud2> ("bunny", 1);
	sensor_msgs::PointCloud2 output;

	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
	if(pcl::io::loadPCDFile<PointT>("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd",*cloud)==-1){
		PCL_ERROR("could not read file\n");
		return (-1);
	}
	for(size_t i=0;i<cloud->points.size();i++){
		cloud->points[i].x = 20*cloud->points[i].x;
        cloud->points[i].y = 20*cloud->points[i].y;
        cloud->points[i].z = 20*cloud->points[i].z;
	}
//display by rviz
	pcl::toROSMsg(*cloud, output);
	output.header.frame_id = "map";
	ros::Rate loop_rate(1);
	while (ros::ok())
    {
        pcl_pub.publish(output);
        ros::spinOnce();
        loop_rate.sleep();
    }
	ros::shutdown();
	return 0;
}

```

## concatenate point clouds

```c++
//combine cloud_a with cloud_b
//[pa]
//[pb]
cloud_c  = cloud_a;
cloud_c += cloud_b;

//[pa,pb]
pcl::concatenateFields (cloud_a, n_cloud_b, p_n_cloud_c); //拼接（点）cloud_a和（法向量）n_cloud_b到p_n_cloud_c
```

## visualize a range image

```c++
#include <ros/ros.h>
#include <iostream>
// PCL specific includes
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/common_headers.h>
#include <pcl/range_image/range_image.h>
#include <pcl/visualization/range_image_visualizer.h>
// pcl in ros
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>


typedef pcl::PointXYZ PointT;


void setViewerPose (pcl::visualization::PCLVisualizer& viewer, const Eigen::Affine3f& viewer_pose)
{
  Eigen::Vector3f pos_vector = viewer_pose * Eigen::Vector3f(0, 0, 0);
  Eigen::Vector3f look_at_vector = viewer_pose.rotation () * Eigen::Vector3f(0, 0, 1) + pos_vector;
  Eigen::Vector3f up_vector = viewer_pose.rotation () * Eigen::Vector3f(0, -1, 0);
  viewer.setCameraPosition (pos_vector[0], pos_vector[1], pos_vector[2],
                            look_at_vector[0], look_at_vector[1], look_at_vector[2],
                            up_vector[0], up_vector[1], up_vector[2]);
}

int main (int argc, char** argv)
{
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
	pcl::PointCloud<PointT>& point_cloud=*cloud;
	// if(pcl::io::loadPCDFile<PointT>("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd",*cloud)==-1){
	// 	PCL_ERROR("could not read file\n");
	// 	return (-1);
	// }
//create
	for (float x=-0.5f; x<=0.5f; x+=0.01f)
    {
      for (float y=-0.5f; y<=0.5f; y+=0.01f)
      {
        PointT point;
		point.x = x;  
		point.y = y;  
		point.z = 2.0f - y;
        point_cloud.points.push_back (point);
      }
    }
    point_cloud.width = (int) point_cloud.points.size ();  point_cloud.height = 1;


	for(size_t i=0;i<cloud->points.size();i++){
		cloud->points[i].x = 20*cloud->points[i].x;
        cloud->points[i].y = 20*cloud->points[i].y;
        cloud->points[i].z = 20*cloud->points[i].z;
	}
	
	Eigen::Affine3f scene_sensor_pose (Eigen::Affine3f::Identity ());
	scene_sensor_pose=Eigen::Affine3f (Eigen::Translation3f (point_cloud.sensor_origin_[0],                              point_cloud.sensor_origin_[1],
     point_cloud.sensor_origin_[2])) *
                        Eigen::Affine3f (point_cloud.sensor_orientation_);

//create range image
	float noise_level = 0.0;
	float min_range = 0.0f;
	int border_size = 1;
	pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
	float angular_resolution_x,angular_resolution_y;
	if(argc==3){
		angular_resolution_x = pcl::deg2rad (std::stod(argv[1]));
		angular_resolution_y = pcl::deg2rad (std::stod(argv[2]));
		
	}else{
		angular_resolution_x = pcl::deg2rad (0.5);
		angular_resolution_y = pcl::deg2rad (0.5);
	}
	pcl::RangeImage::Ptr range_image_ptr(new pcl::RangeImage);
	pcl::RangeImage& range_image = *range_image_ptr; 
	range_image.createFromPointCloud(point_cloud,angular_resolution_x,angular_resolution_y,
									pcl::deg2rad(360.0f),pcl::deg2rad(360.0f),
									scene_sensor_pose,coordinate_frame,noise_level,min_range,border_size);
	
//visualizer
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->setBackgroundColor(1, 1, 1);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointWithRange> single_color(range_image_ptr, 0, 0.4, 0);
	viewer->addPointCloud(range_image_ptr, single_color,"sample cloud");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
	// viewer->addCoordinateSystem(1.0);
	viewer->initCameraParameters();
	setViewerPose(*viewer, range_image.getTransformationToWorldSystem ());

	pcl::visualization::RangeImageVisualizer range_image_widget ("Range image");
	range_image_widget.showRangeImage (range_image);
	while (!viewer->wasStopped())
	{
		range_image_widget.spinOnce();
		viewer->spinOnce();
		pcl_sleep(0.01);
		//live update
		scene_sensor_pose = viewer->getViewerPose();
    	range_image.createFromPointCloud (point_cloud, angular_resolution_x,angular_resolution_y, pcl::deg2rad (360.0f), pcl::deg2rad (180.0f),
                                      scene_sensor_pose, pcl::RangeImage::LASER_FRAME, noise_level, min_range, border_size);
    	range_image_widget.showRangeImage (range_image);
	}

	return 0;
}

```

## k-nearest search

```c++
#include <ros/ros.h>
#include <iostream>
// PCL specific includes
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h> // pcd读写相关头文件
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h> //kdtree
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/common_headers.h>
#include <pcl/range_image/range_image.h>
#include <pcl/visualization/range_image_visualizer.h>
// pcl in ros
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>



typedef pcl::PointXYZ PointT;

int main (int argc, char** argv)
{
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
	pcl::PointCloud<PointT>& point_cloud=*cloud;
	if(pcl::io::loadPCDFile<PointT>("/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd",*cloud)==-1){
		PCL_ERROR("could not read file\n");
		return (-1);
	}
//create
//the same
//pcl::search::KdTree<PointT>::Ptr kdtree(new pcl::search::KdTree<PointT>);
std::shared_ptr<pcl::KdTreeFLANN<PointT>> kdtree(new pcl::KdTreeFLANN<PointT>);

kdtree->setInputCloud(cloud);

std::vector<int> indices;
std::vector<float> distances;

PointT point=cloud->points[0];//initialize a point to be searched
int k=10;

//k-nearest
int size=kdtree->nearestKSearch(point,k,indices,distances);
std::cout<<"seach point:"<<size<<std::endl;

//r-nearest
double radius=0.5;
size=kdtree->radiusSearch(point,radius,indices,distances);
std::cout<<"search point:"<<size<<std::endl;
	
return 0;
}


```
#include <iostream>
#include <string>
#include <ros/ros.h>
#include <thread>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>


#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/console/parse.h>



using namespace std;
typedef pcl::PointXYZ PointT;


int main (int argc, char** argv)
{	
	string pcd_file="/home/yee/ros_ws/temp_ws/src/pcl_tutorial/materials/bunny.pcd";
	if(argc>1){
		pcd_file=argv[1];
	}
	pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
    cout<<"height:"<<cloud->height<<" width:"<<cloud->height<<endl;
	pcl::PointCloud<PointT>& point_cloud=*cloud;
	pcl::PointCloud<pcl::PointWithViewpoint> far_ranges; //带视角的点构成的点云
	if(pcl::io::loadPCDFile<PointT>(pcd_file,*cloud)==-1){
		PCL_ERROR("could not read file\n");
		return (-1);
	}

    /*create point cloud*/
    pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
    std::cout << "Generating example point clouds.\n\n";
    // We're going to make an ellipse extruded along the z-axis. The colour for
    // the XYZRGB cloud will gradually go from red to green to blue.
    uint8_t r(255), g(15), b(15);
    for (float z(-1.0); z <= 1.0; z += 0.05)
    {
        for (float angle(0.0); angle <= 360.0; angle += 5.0)
        {
            pcl::PointXYZ basic_point;
            basic_point.x = 0.5 * std::cos (pcl::deg2rad(angle))*0.05;
            basic_point.y = sinf (pcl::deg2rad(angle))*0.05;
            basic_point.z = z;
            basic_cloud_ptr->points.push_back(basic_point);

        }
    }
    basic_cloud_ptr->width = (int) basic_cloud_ptr->points.size ();
    basic_cloud_ptr->height = 1;
    pcl::io::savePCDFileASCII ("basic_pcd.pcd", *basic_cloud_ptr);
 
    pcl::visualization::PCLVisualizer viewer("pointcloud viewer");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> sig(cloud, 0, 234, 0);
    viewer.addPointCloud(cloud, sig, "cloud");
    while (!viewer.wasStopped())
    {
        viewer.spinOnce();
    }
}
// #include <iostream>
// #include <string>

// #include <pcl/io/ply_io.h>
// #include <pcl/point_types.h>
// #include <pcl/registration/icp.h>
// #include <pcl/visualization/pcl_visualizer.h>
// #include <pcl/console/time.h>

// using namespace std;

// typedef pcl::PointXYZ PointT;
// typedef pcl::PointCloud<POintT> PointCloudT;
// bool next_iteration=false;

// void print4x4Matrix(const Eigen::Matrix4d &matrix){
//     printf ("Rotation matrix :\n");
//     printf ("    | %6.3f %6.3f %6.3f | \n", matrix (0, 0), matrix (0, 1), matrix (0, 2));
//     printf ("R = | %6.3f %6.3f %6.3f | \n", matrix (1, 0), matrix (1, 1), matrix (1, 2));
//     printf ("    | %6.3f %6.3f %6.3f | \n", matrix (2, 0), matrix (2, 1), matrix (2, 2));
//     printf ("Translation vector :\n");
//     printf ("t = < %6.3f, %6.3f, %6.3f >\n\n", matrix (0, 3), matrix (1, 3), matrix (2, 3));
// }

// void keyboardEventOccurred(const pcl::visualization::KeyboardEvent& event,void *nothing){
//     if(event.getKeySym()=="space" && event.keyDown()){
//         next_iteration=true;
//     }
// }

// int main(int argc, char *argv[]){
//     PointCloudT::Ptr cloud_in(new PointCloudT);//original point cloud
//     PointCloudT::Ptr cloud_tr(new PointCloudT);//transformed point cloud
//     PointCloudT::Ptr cloud_icp(new PointCloudT);//icp output cloud

//     if(argc<2){
//         printf ("Usage :\n");
//         printf ("\t\t%s file.ply number_of_ICP_iterations\n", argv[0]);
//         cout<<"Provide one ply file.\n";
//         return (-1);
//     }
//     int iteration=1;
//     if(argc>2){
//         iteration=atoi(argv[2]);
//         if(iteration<1){
//             cout<<"iteration number should be >=1\n";
//             return -1;
//         }
//     }

//     pcl::console::TicToc time;
//     time.tic();
//     if(pcl::io::loadPLYFile(argv[1],*cloud_in)<0){
//         cout<<"Error loading cloud "<<argv[1]<<endl;
//         return -1;
//     }

//     Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity ();
//     // A rotation matrix (see https://en.wikipedia.org/wiki/Rotation_matrix)
//     double theta = M_PI / 8;  // The angle of rotation in radians
//     transformation_matrix (0, 0) = std::cos (theta);
//     transformation_matrix (0, 1) = -sin (theta);
//     transformation_matrix (1, 0) = sin (theta);
//     transformation_matrix (1, 1) = std::cos (theta);

//     // A translation on Z axis (0.4 meters)
//     transformation_matrix (2, 3) = 0.4;
//     cout<<"Applying this transformation to cloud_in:\n";
//     print4x4Matrix(transformation_matrix);

//     pcl::transformPointCLoud(*cloud_in,*cloud_icp,transformation_matrix);
//     *cloud_tr=*cloud_icp;//backup cloudicp to cloudtr

//     //the iterative closet point algorithim
//     time.tic();
//     pcl::IterativeClosetPoint<PointT,Point> icp;
//     icp.setMaximumIterations(iteration);
//     icp.setInputSource(cloud_icp);
//     icp.setInputTarget(cloud_in);
//     icp.align(*cloud_icp);
//     icp.setMaximumIterations(1);//We set this variable to 1 for the next time we will call .align () function
//     std::cout<< "Applied " << iterations << " ICP iteration(s) in " << time.toc () << " ms" << std::endl;

//     if(icp.hasCnverged()){
//         std::cout << "\nICP has converged, score is " << icp.getFitnessScore () << std::endl;
//         std::cout << "\nICP transformation " << iterations << " : cloud_icp -> cloud_in" << std::endl;
//         transformation_matrix = icp.getFinalTransformation ().cast<double>();
//         print4x4Matrix (transformation_matrix);
//     }
//     else{
//         cout<<"Icp has not converged.\n";
//         return -1;
//     }

//      // Visualization
//     pcl::visualization::PCLVisualizer viewer ("ICP demo");
//     // Create two vertically separated viewports
//     int v1 (0);
//     int v2 (1);
//     viewer.createViewPort (0.0, 0.0, 0.5, 1.0, v1);
//     viewer.createViewPort (0.5, 0.0, 1.0, 1.0, v2);

//      // The color we will be using
//     float bckgr_gray_level = 0.0;  // Black
//     float txt_gray_lvl = 1.0 - bckgr_gra

//     // Original point cloud is white
//     pcl::visualization::PointCloudColorHandlerCustom<PointT> cloud_in_color_h (cloud_in, (int) 255 * txt_gray_lvl, (int) 255 * txt_gray_lvl,
//                                                                              (int) 255 * txt_gray_lvl);\
//     viewer.addPointCloud(cloud_in,cloud_in_color_h,"cloud_in_v1",v1);
//     viewer.addPointCloud(cloud_in,cloud_in_color_h,"cloud_in_v2",v2);

//     //transformed point cloud is green
//     pcl::visualization::PointCloudColorHandlerCustom<POintT> cloud_tr_color_h(cloud_tr,20,180,20);
//     viewer.addPointCloud(cloud_tr,"cloud_trv1",v1);

//     //icp aligned point cloud is red
//     pcl.visualization::PointCloudColorHandlerCustom<PoinT> cloud_icp_color_h(cloud_icp,180,20,20)

//     // Adding text descriptions in each viewport
//     viewer.addText ("White: Original point cloud\nGreen: Matrix transformed point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_1", v1);
//     viewer.addText ("White: Original point cloud\nRed: ICP aligned point cloud", 10, 15, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "icp_info_2", v2);

//     std::stringstream ss;
//     ss<<iterations;
//     string iterations_cnt="ICP iterations="+ss.str();
//     viewer.addText(iterations_cnt,10,60,16,txt_gray_lvl,txt_gray_lvl,txt_gray_lvl,"iteration_cnt",v2);
//     // Set background color
//     viewer.setBackgroundColor (bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v1);
//     viewer.setBackgroundColor (bckgr_gray_level, bckgr_gray_level, bckgr_gray_level, v2);

//     // Set camera position and orientation
//     viewer.setCameraPosition (-3.68332, 2.94092, 5.71266, 0.289847, 0.921947, -0.256907, 0);
//     viewer.setSize (1280, 1024);  // Visualiser window size

//     viewer.registerKeyboardCallback(&keyboardEventOccurred,(void*)NULL);

//     //display
//     while(!viewer.wasStopped()){
//         viewer.spinOnce();

//         //the user prssed space
//         if(next_iteration){
//             //icp algorithm
//             time.tic();
//             icp.align(*cloud_icp);
//             cout<< "Applied 1 ICP iteration in " << time.toc () << " ms" << std::endl;
//             if (icp.hasConverged ())
//             {
//                 printf ("\033[11A");  // Go up 11 lines in terminal output.
//                 printf ("\nICP has converged, score is %+.0e\n", icp.getFitnessScore ());
//                 std::cout << "\nICP transformation " << ++iterations << " : cloud_icp -> cloud_in" << std::endl;
//                 transformation_matrix *= icp.getFinalTransformation ().cast<double>();  // WARNING /!\ This is not accurate! For "educational" purpose only!
//                 print4x4Matrix (transformation_matrix);  // Print the transformation between original pose and current pose

//                 ss.str ("");
//                 ss << iterations;
//                 std::string iterations_cnt = "ICP iterations = " + ss.str ();
//                 viewer.updateText (iterations_cnt, 10, 60, 16, txt_gray_lvl, txt_gray_lvl, txt_gray_lvl, "iterations_cnt");
//                 viewer.updatePointCloud (cloud_icp, cloud_icp_color_h, "cloud_icp_v2");
//             }
//             else
//             {
//                 PCL_ERROR ("\nICP has not converged.\n");
//                 return (-1);
//             }
//         }
//         next_iteration=false;
//     }
//     return 0;
// }

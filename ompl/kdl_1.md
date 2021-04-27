---
title: kdl 1
categories: ompl
tags: kinematics
date: 2018-11-12
---

- [kdl user manual](http://www.orocos.org/kdl/user-manual)
- [kdl api](http://docs.ros.org/indigo/api/orocos_kdl/html/)
- [kdl api github](https://github.com/orocos/orocos_kinematics_dynamics/tree/master/orocos_kdl)
- [kdl parser github](https://github.com/ros/kdl_parser/tree/melodic-devel/kdl_parser)
- TODO:track-ik,[paper](https://personal.traclabs.com/~pbeeson/publications/b2hd-Beeson-humanoids-15.html),[source](https://bitbucket.org/traclabs/trac_ik/src/f5a4c1743f29b95923ae3549886bd50bb7707af4/trac_ik_lib/src/trac_ik.cpp?at=master&fileviewer=file-view-default)

kdl_parser([ros package](http://wiki.ros.org/kdl_parser)) provides tools to construct a KDL tree from an XML robot representation in URDF.  
- kdl_parser::treeFromFile(".urdf"),直接解析的是urdf对象，对于'.xacro'文件
可通过launch转化为urdf，再通过'kdl_parser::treeFromParam()'进行解析。

```c++
//comparation between ik solver
KDL::ChainIkSolverPos_NR; //duration: 0.000104653; accuracy:high
KDL::ChainIkSolverPos_LMA;//duration: 0.000001688; accuracy:low
RobotState::setFromIK;    //duration: 0.000146478; accuracy:high
```

```c++
//api examples
std::ifstream ifs(urdf_path);
std::string urdf_xml_string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
urdf::ModelInterfaceSharedPtr urdf_model=urdf::parseURDF(urdf_xml_string);
if(!kdl_parser::treeFromUrdfModel(*urdf_model,tree)){
    printf("error. filed to parse urdf model.\n");
    return -1;
}
for(int i=0;i<urdf_model->getRoot()->child_links.size();i++){
    printf("link%d, name:%s\n",i,urdf_model->getRoot()->child_links[i]->name.c_str());
}
```

## kdl ik

## kdl twist:

[diff()](https://github.com/orocos/orocos_kinematics_dynamics/blob/master/orocos_kdl/src/frames.inl)

differentiate position and orientations 

```c++

// Returns a vector with the direction of the equiv. axis
// and its norm is angle
Vector Rotation::GetRot() const
{
Vector axis;
double angle;
angle = Rotation::GetRotAngle(axis,epsilon);
return axis * angle;
}

// from frames.inl
IMETHOD Vector diff(const Rotation& R_a_b1,const Rotation& R_a_b2,double dt) {
	Rotation R_b1_b2(R_a_b1.Inverse()*R_a_b2);
	return R_a_b1 * R_b1_b2.GetRot() / dt;
}

IMETHOD Twist diff(const Frame& F_a_b1,const Frame& F_a_b2,double dt) {
	return Twist(
			diff(F_a_b1.p,F_a_b2.p,dt),
			diff(F_a_b1.M,F_a_b2.M,dt)
			);
}
```

interpolation for rigid body motion

## kdl dynamics

[RNE: recursive newton euler](http://docs.ros.org/indigo/api/orocos_kdl/html/classKDL_1_1ChainIdSolver__RNE.html)


---
title: motoman driver structure
categories: ros
tags: industrical driver
date: 2018-10-11
---

[industrical](http://docs.ros.org/kinetic/api/simple_message/html/namespaceindustrial.html)

## mesage connection

![inherited relationship](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1smpl__msg__connection_1_1SmplMsgConnection__inherit__graph.png)

- [tcp_client](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1tcp__client_1_1TcpClient.html#a08dfcd76a00fbb7358fe4d64b184e72b)
- [tcp_socket](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1tcp__socket_1_1TcpSocket.html)
- [simple_socket](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1simple__socket_1_1SimpleSocket.html)

- tcp_client: init, connect
- tcp_socket: rawSentBytes,rawReceiveBytes,rawPoll. 原生buffer数据收发的执行者
- simple_socket: sendBytes,receiveBytes,发送的是ByteArray类数据，进一步解构后再通过rawSend/Receive进行执行。
```c++
sockaddr_in sockaddr_;
int sock_handle_;
//获取socket的函数
int  getSockHandle() const
{
	return sock_handle_;
}
```
- smpl_msg_connection: sendAndReceiveMsg,消息收发的高层函数.sendMsg和receiveMsg小队message结构再通过send/receiveBytes执行。
```c++
bool sendAndReceiveMsg (industrial::simple_message::SimpleMessage &send, industrial::simple_message::SimpleMessage &recv, bool verbose=false)
receiveMsg(SimpleMessage & message);
sendMsg(SimpleMessage & message)
```

## message manager

接收线程

- [message_manager](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1message__manager_1_1MessageManager.html)
- [message_handler](http://docs.ros.org/kinetic/api/simple_message/html/classindustrial_1_1message__handler_1_1MessageHandler.html)

```c++
//manager不断循环接收下位机发送来的消息，并根据不同的消息类型选择handler进行处理
spin(){
	while(true):{
		this->spinOnce();
	}
}
spinOnce(){
	connection_->receiveMsg(msg);
	handler_->callback(msg);//many handlers according to type
}
//handler
callback(msg){
	internalCB(msg);
}

//joint_relay_handler
//把关节值以"/feedback_states""/joint_states"发布出去

```

## joint trajectory action

接收moveit action线程

```c++
//把接收的action发布出去，并接收feedback states消息
actionServer_ :"joint_trajectory_action" /goalCB;
pub_trajectory_command_ :joint_path_command"/publisher;//DynamicJointTrajectory
sub_trajectory_state_:"/feedback_states"/subscriber;
sub_robot_status_ ="robot_status"/subscriber; 

//循环
void run()
{
	ros::spin();
}
```
## streaming

发送线程

joint_trajectory_interface

```c++
this->srv_joint_trajectory_ = this->node_.advertiseService(
                              "joint_path_command", &JointTrajectoryInterface::jointTrajectoryExCB, this);
this->sub_joint_trajectory_ = this->node_.subscribe(
                              "joint_path_command", 0, &JointTrajectoryInterface::jointTrajectoryExCB, this);
this->srv_stop_motion_ = this->node_.advertiseService(
                         "stop_motion", &JointTrajectoryInterface::stopMotionCB, this);
jointTrajectoryExCB(DynamicJointTrajectoryptr msg){
	std::vector<SimpleMessage> robot_msgs;
  	trajectory_to_msgs(msg, &robot_msgs);
  	send_to_robot(robot_msgs);
}                       
```
把ros的消息格式转化为tcp通信统一的simple_message格式。

JointTrajectoryStreamer

```c++
streamingThread(){
	while (ros::ok())
	{
	ros::Duration(0.005).sleep();
	this->mutex_.lock();
	SimpleMessage msg, tmpMsg, reply;

	switch (this->state_)
	{
	case TransferStates::IDLE:
		ros::Duration(0.250).sleep();  //  slower loop while waiting
	case TransferStates::STREAMING:
		this->connection_->sendAndReceiveMsg(msg, reply, false);
	default:
		ROS_ERROR("Joint trajectory streamer: unknown state");
		this->state_ = TransferStates::IDLE;
		break;
	}
	this->mutex_.unlock();
	}
}

send_to_robot(msg)
{
  this->mutex_.lock();
  {
    this->state_ = TransferStates::STREAMING;//
  }
  this->mutex_.unlock();

  return true;
}
```

MotomanJointTrajectoryStreamer

继承`JointTrajectoryStreamer`，用法同此。

## message type

[StandardMsgType](http://docs.ros.org/kinetic/api/simple_message/html/simple__message_8h_source.html)

```c++
/*
when send message, the msg_type was labled here
in JointTrajectoryInterface::create_message
*/
//JointTrajPtMessage
init(industrial::joint_traj_pt::JointTrajPt & point)
{
	this->init();
	this->point_.copyFrom(point);
 }
 
init()
{
	this->setMessageType(StandardMsgTypes::JOINT_TRAJ_PT);
	this->point_.init();
}
```


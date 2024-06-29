#include<ros/ros.h>
#include<turtlesim/Pose.h>

void PoseCallBack(const turtlesim::Pose::ConstPtr& pose){
    ROS_INFO("x: %.2f, y: %.2f, theta: %.2f, linear_velocity: %.2f, angular_velocity: %.2f "
    , pose->x, pose->y, pose->theta, pose-> linear_velocity, pose->angular_velocity);
}

int main(int argc, char**argv){
    ros::init(argc, argv,"task6_node");
    ros::NodeHandle n;

    ros::Subscriber sub_pose = n.subscribe("turtle1/pose",100,PoseCallBack);
    ros::Rate loop_rate(60);

    while(ros::ok()){
        ros::spinOnce();
        loop_rate.sleep();
    }
}
#include<ros/ros.h>
#include<LiveChat_msgs/livechatMsg.h>
#include<iostream>

using namespace std;

void MsgCallback(const LiveChat_msgs::livechatMsg::ConstPtr& LiveChat_msg);

int main(int argc, char**argv){
    ros::init(argc, argv,"UserB_node");
    ros::NodeHandle n;

    ros::Publisher pub_Livechat_msg = n.advertise<LiveChat_msgs::livechatMsg>("msg_b",1000);
    ros::Subscriber sub_Livechat_msg = n.subscribe("msg_a",100,MsgCallback);
    ros::Rate loop_rate(60);

    string input_B;
    while(ros::ok()){
        LiveChat_msgs::livechatMsg Livechat_msg;
        Livechat_msg.send = "UserB"; // 보낼 사람 : 유저 B

        cout<<"UserB: ";
        getline(cin,input_B);
        Livechat_msg.message = input_B;

        pub_Livechat_msg.publish(Livechat_msg);

        ros::spinOnce();
        loop_rate.sleep();
    }
}

void MsgCallback(const LiveChat_msgs::livechatMsg::ConstPtr& LiveChat_msg){
    cout << LiveChat_msg->send << ":" << LiveChat_msg->message << endl;
}
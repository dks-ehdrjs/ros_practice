#include<ros/ros.h>
#include<LiveChat_msgs/livechatMsg.h>
#include<iostream>

using namespace std;

void MsgCallback(const LiveChat_msgs::livechatMsg::ConstPtr& LiveChat_msg);

int main(int argc, char**argv){
    ros::init(argc,argv,"UserA_node");
    ros::NodeHandle n;

    ros::Publisher pub_Livechat_msg = n.advertise<LiveChat_msgs::livechatMsg>("msg_a",1000);
    ros::Subscriber sub_Livechat_msg = n.subscribe("msg_b",100,MsgCallback);
    ros::Rate loop_rate(60);
    
    string input_A;
    while(ros::ok()){
        LiveChat_msgs::livechatMsg Livechat_msg;
        Livechat_msg.send = "UserA"; // 보낼 사람 : 유저 A

        cout<<"UserA: ";   
        getline(cin,input_A); // cin 에 입력 받고 input 변수를 이용하여 문자열 담음
        Livechat_msg.message = input_A; // message 에 저장
        
        pub_Livechat_msg.publish(Livechat_msg);

        ros::spinOnce();
        loop_rate.sleep();

    }
}

void MsgCallback(const LiveChat_msgs::livechatMsg::ConstPtr& LiveChat_msg){
    cout << LiveChat_msg->send << ":" << LiveChat_msg->message << endl;
}
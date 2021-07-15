
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include "beginner_tutorials/test_custom_msg.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: XD [%s]", msg->data.c_str());
}

void testMsgCallback(const beginner_tutorials::test_custom_msg::ConstPtr& msg)
{
    ROS_INFO("I heard: XD [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "listener");


    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

    ros::Subscriber sub2 = n.subscribe("forwordedChatter", 1000, chatterCallback);

    ros::Subscriber sub3 = n.subscribe("/beginner_tutorials/test_msg", 1000, testMsgCallback);

    ros::spin();


    return 0;
}

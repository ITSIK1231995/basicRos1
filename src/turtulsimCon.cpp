
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

#include "beginner_tutorials/test_custom_msg.h"



class turtulsimCon{
private:
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber;
    ros::Publisher publisher;
    ros::Publisher customMsgPublisher;
    ros::Publisher colorPublisher;

public:
    turtulsimCon(){
        std::cout << "started"<< std::endl;
//        beginner_tutorials::test_custom_msg msg;
//        msg.data

        subscriber = nodeHandle.subscribe("/turtle1/pose", 1000, &turtulsimCon::callback,this);
        publisher = nodeHandle.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

        customMsgPublisher = nodeHandle.advertise<beginner_tutorials::test_custom_msg>("/beginner_tutorials/test_msg", 1000);\




    }

    void callback(const turtlesim::Pose::ConstPtr& msg)
    {

//        std::cout << "x = " << msg->x << ", y = " << msg->y << std::endl;
//        ROS_INFO("x: [%f], y: [%f]", msg->x, msg->y);
        geometry_msgs::Twist newMsg;
        if(msg->x > 11 or msg->y > 11 or msg->x < 0.1 or msg->y < 0.1){
            newMsg.angular.z = rand()/50;
        }
        newMsg.linear.x = 6;

        publisher.publish(newMsg);

        beginner_tutorials::test_custom_msg ustomMsg;
        ustomMsg.data = "test";
        ustomMsg.counter=123;
        customMsgPublisher.publish(ustomMsg);



        ros::spinOnce();


    }
    void start(){
        ros::spin();
    }

};



int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtulsimCon");

    turtulsimCon f;
    f.start();
    return 0;
}

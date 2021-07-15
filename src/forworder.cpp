
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

class forworder{
private:
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber;
    ros::Publisher publisher;
public:
    forworder(){
        publisher = nodeHandle.advertise<std_msgs::String>("forwordedChatter", 1000);
        subscriber = nodeHandle.subscribe("chatter", 1000, &forworder::callback,this);

    }
    void callback(const std_msgs::String::ConstPtr& msg)
    {
        ROS_INFO("Im forwording: [%s]", msg->data.c_str());

        std_msgs::String newMsg;
        std::stringstream ss;
        ss << msg->data.c_str()<< " !F!W! ";
        newMsg.data = ss.str();

        publisher.publish(newMsg);


        ros::spinOnce();


    }
    void start(){
        ros::spin();
    }

};



int main(int argc, char **argv)
{
    ros::init(argc, argv, "forworder");

    forworder f;
    f.start();
    return 0;
}

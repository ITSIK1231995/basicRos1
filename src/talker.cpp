
#include "ros/ros.h"

#include "std_msgs/String.h"

#include "beginner_tutorials/add2Ints.h"
#include <sstream>


int main(int argc, char **argv)
{

    ros::init(argc, argv, "talker");

    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    ros::ServiceClient client = n.serviceClient<beginner_tutorials::add2Ints>("beginner_tutorials/add2Ints");

    int count = 0;
    while (ros::ok())
    {

        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

        beginner_tutorials::add2Ints srv;
        srv.request.a = count;
        srv.request.b = 2;
        if (client.call(srv)){
            ROS_INFO("Sum: %ld", (long int)srv.response.sum);
            count= srv.response.sum;
        }
        else{
            ROS_ERROR("Failed to call service add_2_ints");
            ++count;
        }

    }


    return 0;
}

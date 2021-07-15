
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

#include "beginner_tutorials/test_custom_msg.h"

#include "beginner_tutorials/add2Ints.h"

class add2IntSrv{
private:
    ros::NodeHandle nodeHandle;

public:
    add2IntSrv(){
        std::cout << "started"<< std::endl;

        ros::ServiceServer service = nodeHandle.advertiseService("beginner_tutorials/add2Ints",add);
    }
    bool static add(beginner_tutorials::add2Ints::Request  &req,beginner_tutorials::add2Ints::Response &res){
        res.sum = req.a + req.b;
        ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
        ROS_INFO("sending back response: [%ld]", (long int)res.sum);
        return true;
    }

    void start(){
        ros::spin();
    }

};



int main(int argc, char **argv)
{
    ros::init(argc, argv, "add2IntSrv");

    add2IntSrv f;
    f.start();
    return 0;
}

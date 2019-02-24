#include <ros/ros.h>
#include <math.h>


//Scanner libs and msgs
#include <sensor_msgs/LaserScan.h>

//User libs and msgs
#include <reactive_robot/obstacle.h>

//For isnan debug
#include<cmath>


//Constant
#define RAD_TO_DEG (double)(180.0 / 3.14159)

//Publisher
ros::Publisher obstacle_pub;

/**
 * isSymmetrical  - Determines whether an obstacle is symmetric within a 10% tolerance
 * 
 * @param start_index: the start index of the obstacle
 * @param end_index: the end index of the obstacle
 * @param obstacle_event: the message sent from the LaserScan sensor messages containing the information of the scan
 * 
 * @return bool: returns true if the obstacle is symmetric and false if the object is asymmetric
 */
bool isSymmetrical(int start_index, int end_index, const sensor_msgs::LaserScan::ConstPtr& obstacle_event) 
{
    //Set the return boolean to true to start
    bool symmetric = true;
    //Find the middle index of the obstalce
    int mid_index = (start_index + end_index) / 2;
    //Loop from left side and right side and cross check distances
    for(int left = start_index; left < mid_index; ++left)
    {
        for(int right = end_index; right > mid_index; --right)
        {
            //Assign the distance to variables so ranges is only called once for each side respectively
            float left_distance = obstacle_event->ranges[left];
            float right_distance = obstacle_event->ranges[right];
            //If the right distance is outside of left distance with a 10% tolerance, set symmetric to false and break 
            if((left_distance + left_distance * 0.05) > right_distance || (left_distance - left_distance * 0.05) < right_distance)
            {
                symmetric = false;
                break;
            }
        }
    }
    return symmetric;
}

/**
 * calculateDistance - Calculates the closest distance of the obstacle
 */
float calculateDistance(int start_index, int end_index, const sensor_msgs::LaserScan::ConstPtr& obstacle_event)
{
    //Set closest disance to 1 meter, as all distances of the object will be closer (i.e. 1 foot or less)
    float closest_distance = 1;
    for(start_index; start_index <= end_index; ++start_index)
    {
        closest_distance = (obstacle_event->ranges[start_index] < closest_distance) ? obstacle_event->ranges[start_index] : closest_distance;
    }
    return closest_distance;
}

/**
 * scanCallback - Detects obstacles in front of the robot and deduces the symmetry and distance
 * of the object.
 * 
 * @param obstacle_event: the message sent from the LaserScan sensor messages containing the information of the scan
 */
void scanCallback(const sensor_msgs::LaserScan::ConstPtr& obstacle_event)
{
    //Declare the obstacle message as a local variable
    reactive_robot::obstacle obstacle_msg;

    //Start and end indices of an object
    int start_point = INT_MAX;
    int end_point   = INT_MAX;





    double right_scan[213];
    double center_scan[213 + 1];
    double left_scan[213];
    
    double distance_to_left_obj = INT_MAX;
    double distance_to_right_obj = INT_MAX;




    //Right third
    for(int i = 0; i < 213; i++)
    {
        if(!std::isnan(obstacle_event->ranges[i] && obstacle_event->ranges[i] <= distance_to_right_obj))
        {
            distance_to_right_obj = obstacle_event->ranges[i];
        }
    } 

    //Left third
    for(int i = 427; i < 640; i++)
    {
        if(!std::isnan(obstacle_event->ranges[i] && obstacle_event->ranges[i] <= distance_to_left_obj))
        {
            distance_to_left_obj = obstacle_event->ranges[i];
        }
    } 


    if(distance_to_left_obj < distance_to_right_obj)
    {
        //Turn left
    }
    else if (distance_to_left_obj > distance_to_right_obj) {
        //Turn right
    }
    


    //Loop through the ranges vector at each angle
    for(int angle = 0; angle < obstacle_event->ranges.size(); ++angle)
    {
        //Determine if an obstacle is detected within one foot of the robot
        if(obstacle_event->range_min < obstacle_event->ranges[angle] && 1 >= obstacle_event->ranges[angle] && !std::isnan(obstacle_event->ranges[angle]))
        {
            //If the start point has not already been set
            if(start_point == INT_MAX)
            {
                start_point = angle;
            }
        }
        //Else an obstacle is not detected
        else
        {
            //If the start point has been set and the end point has not been set
            if(start_point != INT_MAX && end_point == INT_MAX)
            {
                end_point = angle - 1;
            }
        }
    }

    if(start_point != INT_MAX && end_point == INT_MAX)
    {
        end_point = obstacle_event->ranges.size() - 1;
    }


    printf("start_point=%d, end_point=%d w/ range_min=%f \n\r\n\r", start_point, end_point,obstacle_event->range_min);


    //If an object was detected
    if(start_point != INT_MAX) 
    {
        //Determine if it is symmetric
        bool symmetric = isSymmetrical(start_point, end_point, obstacle_event);
        //Set symmetric or asymmetric
        obstacle_msg.state = symmetric ? obstacle_msg.SYMMETRIC : obstacle_msg.ASYMMETRIC;
        //Calculate distance
        obstacle_msg.distance = calculateDistance(start_point, end_point, obstacle_event);
        //Set the angle of the midpoint of the object in degrees relative to scanner
        obstacle_msg.angle = ((((start_point + end_point) / 2) * obstacle_event->angle_increment) + obstacle_event->angle_min) * RAD_TO_DEG;
    }
    else 
    {
        obstacle_msg.state = obstacle_msg.EMPTY;
    }
    //Publish message
    obstacle_pub.publish(obstacle_msg);
}
/**
 * Runs the loop needed to handle obstacle detection 
 */
int main(int argc, char **argv)
{
    //Start the node
    ros::init(argc, argv, "obstacle_avoid_node");

    //Set up the node handle for auto driving
    ros::NodeHandle obstacle_avoid_node;

    //Subscribe to the scanner
    ros::Subscriber obstacle_sub = obstacle_avoid_node.subscribe(obstacle_avoid_node.resolveName("/scan"), 10, &scanCallback);

    //Publish state to the obstacle topic
    obstacle_pub = obstacle_avoid_node.advertise<reactive_robot::obstacle>(obstacle_avoid_node.resolveName("/reactive_robot/obstacle"), 10);

    //Handle the callbacks
    ros::spin();
}

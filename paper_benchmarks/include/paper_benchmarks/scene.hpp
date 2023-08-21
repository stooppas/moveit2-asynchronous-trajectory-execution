#ifndef SETUP_SCENE_H
#define SETUP_SCENE_H

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

struct Block
{
    Block(shape_msgs::msg::SolidPrimitive primitive, geometry_msgs::msg::Pose pose)
    {
        this->pose = pose;
        this->primitive = primitive;
    }
    geometry_msgs::msg::Pose pose;
    shape_msgs::msg::SolidPrimitive primitive;
    std::string id;
};

class Scene
{
public:
    Scene(rclcpp::Node::SharedPtr node);
    bool attachObject();
    bool detachObject();
    void create_random_scene();
    void add_objects_to_scene(int);

private:
    rclcpp::Node::SharedPtr node;
    rclcpp::Publisher<moveit_msgs::msg::PlanningScene>::SharedPtr planning_scene_diff_publisher;
    std::list<Block> blockList;
    bool createNewObject(int counter, float min_x, float max_x, float max_y, float min_y,
                         std::vector<moveit_msgs::msg::CollisionObject> &collision_objects,
                         std::vector<moveit_msgs::msg::ObjectColor> &object_colors);
};
#endif
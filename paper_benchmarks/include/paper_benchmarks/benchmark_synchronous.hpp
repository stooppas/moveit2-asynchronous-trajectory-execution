#ifndef BENCHMARK_SYNCHRONOUS_H
#define BENCHMARK_SYNCHRONOUS_H

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include "paper_benchmarks/scene.hpp"
#include "paper_benchmarks/primitive_pick_and_place.hpp"
#include "std_msgs/msg/string.hpp"
#include "paper_benchmarks/cube_selector.hpp"

rclcpp::Node::SharedPtr node;

std::shared_ptr<primitive_pick_and_place> pnp_1;
std::shared_ptr<primitive_pick_and_place> pnp_2;
std::shared_ptr<primitive_pick_and_place> pnp_dual;

//moveit::planning_interface::MoveGroupInterface arm_group("dual_arm");

tray_helper blue_tray_1(4,4,0.11,-0.925,0.06,0.1,true);
tray_helper red_tray_1(4,4,-0.425,-0.925,0.06,0.1,true);
tray_helper blue_tray_2(4,4,0.11,0.925,0.06,0.1,false);
tray_helper red_tray_2(4,4,-0.425,0.925,0.06,0.1,false);

const rclcpp::Logger LOGGER = rclcpp::get_logger("benchmark_synchronous");
void main_thread();
void update_planning_scene();

rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
std::vector<std::string> all_objects;
Point3D e(0,0,0);
ThreadSafeCubeQueue objs(e);


std::map<std::string, moveit_msgs::msg::CollisionObject> objMap;
std::map<std::string, moveit_msgs::msg::ObjectColor> colors;
bool update_scene_called_once = false;

#endif
#pragma once

#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>


namespace example {


class Example : public rclcpp::Node {

 public:

  Example();

 private:

  void setup();

  void topicCallback(const std_msgs::msg::Int32::ConstSharedPtr& msg);

 private:

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscriber_;

  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
};


}

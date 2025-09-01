#include <functional>

#include <example/example.hpp>


namespace example {


Example::Example() : Node("example") {

  this->setup();
}


void Example::setup() {
  subscriber_ = this->create_subscription<std_msgs::msg::Int32>("~/input", 10, std::bind(&Example::topicCallback, this, std::placeholders::_1));
  RCLCPP_INFO(this->get_logger(), "Subscribed to '%s'", subscriber_->get_topic_name());

  publisher_ = this->create_publisher<std_msgs::msg::Int32>("~/output", 10);
  RCLCPP_INFO(this->get_logger(), "Publishing to '%s'", publisher_->get_topic_name());
}


void Example::topicCallback(const std_msgs::msg::Int32::ConstSharedPtr& msg) {

  std_msgs::msg::Int32 out_msg;
  out_msg.data = msg->data;
  publisher_->publish(out_msg);
  RCLCPP_INFO(this->get_logger(), "Message published: '%d'", out_msg.data);
}
}


int main(int argc, char *argv[]) {

  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<example::Example>());
  rclcpp::shutdown();

  return 0;
}

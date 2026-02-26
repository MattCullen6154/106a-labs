import rclpy
from rclpy.node import Node
import forward_kinematics.forward_kinematics as fk
# message here (joint_states)
from sensor_msgs import joint_state

class ForwardKinematicsNode(Node):
    def __init__(self):
        super().__inti__('forward_kinematics_node')

        # COPIED MINIMAL SUBSCRIBER
        self.subscription = self.create_subscription(
            String,
            'joint_state',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):ros2 topic 
        # does this output transform matrix?
        self.get_logger().info(fk.ur7e_forward_kinematics_from_joint_state(joint_state.position))


def main(args=None):
    rclpy.init(args=args)

    forward_kinematics_node = ForwardKinematicsNode()

    rclpy.spin(forward_kinematics_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    forward_kinematics_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
        
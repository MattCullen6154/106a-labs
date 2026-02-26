#!/usr/bin/env python3

import tf2_ros
import sys
from rclpy.node import Node
from rclpy.time import Time
import rclpy

#DEBUG
import os
print("Running: ", os.path.abspath(__file__))

class TfEcho(Node):
    def __init__(self, target_frame, source_frame):
        super().__init__('tf_echo')
        self.target_frame = target_frame
        self.source_frame = source_frame

        self.tfBuffer = tf2_ros.Buffer()
        self.tfListener = tf2_ros.TransformListener(self.tfBuffer, self)

        self.timer = self.create_timer(0.1, self.listener_callback)

        self.get_logger().info(f"Transform: target={target_frame}, source={source_frame}")

    def listener_callback(self):
        try:
            trans = self.tfBuffer.lookup_transform(self.target_frame, self.source_frame, rclpy.time.Time())
            t = trans.transform.translation
            q = trans.transform.rotation


            self.get_logger().info(f"Translation: x={t.x: .3f}, y={t.y: .3f}, z={t.z: .3f}")
            self.get_logger().info(f"Rotation: w={q.w: .3f}, x={q.x: .3f}, y={q.y: .3f}, z={q.z: .3f}")
        
        except(tf2_ros.LookupException,
               tf2_ros.ConnectivityException, 
               tf2_ros.ExtrapolationException) as ex:
               self.get_logger().warn(f"TF lookup failed: {ex}")

def main():
    rclpy.init()

    target_frame = sys.argv[1]
    source_frame = sys.argv[2]

    node = TfEcho(target_frame, source_frame)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

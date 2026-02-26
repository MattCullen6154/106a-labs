#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
import sys
import tty
import termios
import threading
import select

# Key mappings
INCREMENT_KEYS = ['1','2','3','4','5','6']
DECREMENT_KEYS = ['q','w','e','r','t','y']
JOINT_STEP = 0.15 # radians per key press

class JointPositionController(Node):
    def __init__(self, joint_angles):
        super().__init__('ur7e_joint_position_controller')
        
        self.joint_names = [
            'shoulder_lift_joint',
            'elbow_joint',
            'wrist_1_joint',
            'wrist_2_joint',
            'wrist_3_joint',
            'shoulder_pan_joint',
        ]

        self.joint_positions = list(joint_angles)
        #self.got_joint_states = False  # Failsafe: don't publish until joint states received
        
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        
        self.pub = self.create_publisher(JointTrajectory, '/joint_trajectory_validated', 10)
        
        #self.running = True
        #threading.Thread(target=self.cli_ingest, daemon=True).start()

    def joint_state_callback(self, msg: JointState):

        traj = JointTrajectory()
        traj.joint_names = self.joint_names
        point = JointTrajectoryPoint
        point.positions = self.joint_positions
        point.velocities = [0.0] * 6
        point.time_from_start = Duration(sec=1, nanosec=0)
        traj.points.append(point)

        self.pub.publish(traj)

def main(args=None):
    rclpy.init(args=args)
    joint_angles = [float(i) for i in sys.argv[1:7]]
    node = JointPositionController(joint_angles)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.running = False
        print("\nExiting joint controller...")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()


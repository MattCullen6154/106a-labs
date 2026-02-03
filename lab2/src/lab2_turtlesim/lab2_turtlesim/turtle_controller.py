import rclpy
import sys
from rclpy import Node
from geometry_msgs.msg import Twist
import turtlesim

class Turtle_Controller(Node):
    def __init__(self, turtle_name):
        super().__init__('turtle_controller')
        #see if this works
        if len(sys.argv[1] > 1):
            turtle_name = sys.argv[1]

# Publisher
# publish twist control msgs whern user presses keys

    def run(self):
        while rclpy.ok():
            user_in = input() #get input from user keystroke
            print(user_in) # see what this does




# Main stuff copied from chatter.my_talker

def main(args=None):
    # Initialize the rclpy library
    rclpy.init(args=args)
    # Create the node
    node = Turtle_Controller()
    
    try:
        node.run()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
    



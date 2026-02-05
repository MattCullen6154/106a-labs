import rclpy
import sys
from rclpy.node import Node
from geometry_msgs.msg import Twist
import turtlesim

class Turtle_Controller(Node):
    def __init__(self, turtle_name):
        super().__init__('turtle_controller')
        #see if this works
        #turtle_name = sys.argv[1]
        #print(turtle_name) # this works
        self.publisher_ = self.create_publisher(Twist, f'/{turtle_name}/cmd_vel', 10)

# Publisher
# publish twist control msgs whern user presses keys

    def publish_command(self, key):
        #left = 
        while rclpy.ok():
            #user_in = input("tell the turtle where to go; wasd = ^<v>. \n") #get input from user keystroke
            msg = Twist()
            if key == 'w':
                msg.linear.y = 1.0 
            elif key == 'a':
                msg.linear.x = -1.0
            elif key == 's':
                msg.linear.y = -1.0
            elif key == 'd':
                msg.linear.x = 1.0
            
            self.publisher_.publish(msg)
            return
            #rclpy.spin_once(self)


# Main stuff copied from chatter.my_talker

def main(args=None):
    # Initialize the rclpy library
    rclpy.init(args=args)


    if len(sys.argv) < 2:
        print("Usage: ros2 run <package> <node> <turtle_name>")
        return

    turtle_name = sys.argv[1]
    #adding extra CLI fields
    x = sys.argv[2]
    y = sys.argv[3]
    theta = sys.argv[4]
    velocity = sys.argv[5]
    omega = sys.argv[6]

    node = Turtle_Controller(turtle_name)
    
    try:
        while True:
            #rclpy.spin_once(node, timeout_sec=0.1)
            key_in = input("tell the turtle where to go; wasd = ^<v>. q to quit \n")
            
            if key_in == 'q':
                break

            elif key_in in ['w', 'a', 's', 'd']:
                node.publish_command(key_in)
                #key_in = input()
        
    except KeyboardInterrupt:
        pass

    finally:
        node.destroy_node()
        rclpy.shutdown()

        

    #except KeyboardInterrupt:
    #    pass
    #finally:
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
    



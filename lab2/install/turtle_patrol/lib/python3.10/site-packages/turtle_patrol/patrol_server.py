import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from std_srvs.srv import Empty
from turtlesim.srv import TeleportAbsolute
from turtle_patrol_interface.srv import Patrol


class Turtle1PatrolServer(Node):
    def __init__(self):
        super().__init__('turtle1_patrol_server')
        self._srv = self.create_service(Patrol, f'/turtle_patrol', self.patrol_callback)
        # Create dict keyed on turtle_name
        self.turtles = {}
        self._timer = self.create_timer(0.1, self.publish_all)
        # Publisher: actually drives turtle1
        #self._cmd_pub = self.create_publisher(Twist, f'/{turtle_name}/cmd_vel', 10)
        

        # Current commanded speeds (what timer publishes)
        self._lin = 0.0
        self._ang = 0.0

        # Timer: publish current speeds at 10 Hz
        

        self.get_logger().info('Turtle1PatrolServer ready (continuous publish mode).')

    def ensure_turtle(self, turtle_name: str):
        name = turtle_name.strip()
        if name in self.turtles:
            return self.turtles[name]
        
        pub = self.create_publisher(Twist, f'/{name}/cmd_vel', 10)
        tp = self.create_client(TeleportAbsolute, f"/{name}/teleport_absolute")
        self.get_logger().info(f"Turtle: {name}: {turtles[name].items()}")
        self.turtles[name] = {
            "pub": pub,
            "teleport": tp,
            "vel": 2.0,
            "omega": 2.0 #hardcoded get from turtle items
        }
        self.get_logger().info(f"Registered turtle '{name}")
        return self.turtles[name]

    def teleport(self, name: str, x: float, y: float, theta: float):
        st = self.ensure_turtle(name)
        tp = st["teleport"]

        if not tp.wait_for_service(timeout_sec=1.0):
            return False, f"/{name}/teleport_absolute service not available."
            
        req = TeleportAbsolute.Request()
        req.x = float(x)
        req.y = float(y)
        req.theta = float(theta)

        future = tp.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)

        if not future.done():
            return False, "Teleport timed out."
        if future.exception() is not None:
            return False, f"Teleport failed: {future.exception()}"

        return True, "Teleported."

    # -------------------------------------------------------
    # Timer publishes current Twist
    # -------------------------------------------------------
    def publish_all(self):
        for name, st in self.turtles.items():
            tw = Twist()
            tw.linear.x = float(st["vel"])
            tw.angular.z = float(st["omega"])
            st["pub"].publish(tw)

            #self.get_logger().warn(f"PUBLISH {name}: lin.x={tw.linear.x} ang.z={tw.angular.z}")

    # -------------------------------------------------------
    # Service callback: update speeds
    # -------------------------------------------------------

    def patrol_callback(self, request: Patrol.Request, response: Patrol.Response):
        self.get_logger().warn(">>>PATROL CALLBACK HIT<<<")
        self.get_logger().warn(
            f"name={request.turtle_name}, vel={request.vel}, omega={request.omega}"
        )
        self.get_logger().info(f"Server got turtle_name: {request.turtle_name}")
        name = request.turtle_name.strip()
        if not name:
            response.success = False
            response.message = "turtle_name is empty"
            return response
        
        ok, msg = self.teleport(name, request.x, request.y, request.theta)
        if not ok:
            response.success = False
            response.message = msg
            return response
        
        st = self.ensure_turtle(name)
        st["vel"] = float(request.vel)
        st["omega"] = float(request.omega)

        response.success = True
        response.message = f"[{name}] {msg}; vel={request.vel}, omega={request.omega}"
        return response


def main(args=None):
    rclpy.init(args=args)
    node = Turtle1PatrolServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

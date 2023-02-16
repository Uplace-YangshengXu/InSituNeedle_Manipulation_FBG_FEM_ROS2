import rclpy
from rclpy.node import Node
from fbg_msgs.msg import FbgReading
from sm130_read import Interrogator

class interrogator_publisher(Node):

    def __init__(self):
        super().__init__('interrogator_publisher')
        self.publisher_ = self.create_publisher(FbgReading,'pub',10)
        timer_period = 2
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.address = "192.168.1.11"
        self.prot = 1852
        self.interrogator = Interrogator(address,port)
        self.header = interrogator.getHeader()
        self.available_ch = interrogator.available_ch

        print(self.header)
        print(self.available_ch)

    def timer_callback(self):
        print("timer_callback")
        #msg = FbgReading()
        #rawdata = self.interrogator.getData()
        #msg.signal_reading
        #self.get_logger().info('Publishing: "%s"' % msg.data)

def main(args = None):
    rclpy.init(args=args)

    sm130_publisher = interrogator_publisher()
    rclpy.spin(sm130_publisher)
    sm130_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


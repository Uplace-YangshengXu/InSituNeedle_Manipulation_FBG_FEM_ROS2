import rclpy
import numpy as np
from rclpy.node import Node
from fbg_msgs.msg import FbgReading
from .sm130_read import Interrogator
from array import array

class interrogator_publisher(Node):

    def __init__(self):
        super().__init__('interrogator_publisher')
        self.publisher_ = self.create_publisher(FbgReading,'sm130',10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.address = "192.168.1.11"
        self.port = 1852
        self.interrogator = Interrogator(self.address,self.port)
        self.header = self.interrogator.getHeader()
        self.total_reading_num = self.interrogator.total_reading_num
        self.available_channel_num = self.interrogator.available_channel_num
        self.available_ch = self.interrogator.available_ch


    def timer_callback(self):
        msg = FbgReading()
        rawdata = self.interrogator.getData()
        np.concatenate(msg.signal_reading,rawdata)
        print(msg.signal_reading)
        self.publisher_.publish(msg.signal_reading)
        #self.get_logger().info('Published %d readings from %d channels' %(self.total_reading_num,self.available_channel_num))


class interrogator_subscriber(Node):
    def __init__(self):
        super().__init__('interrogator_subscriber')
        self.subscription = self.create_subscription(
                FbgReading,
                'sm130',
                self.listener_callback,
                10)
    def listener_callback(self, msg):
        self.msg = msg
        print(msg.signal_reading)





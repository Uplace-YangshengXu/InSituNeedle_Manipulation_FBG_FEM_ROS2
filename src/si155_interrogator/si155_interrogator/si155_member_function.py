import rclpy
import numpy as np
from rclpy.node import Node
from fbg_msgs.msg import FbgReading
from .si155_read import Interrogator
from array import array
class interrogator_publisher(Node):

    def __init__(self):
        super().__init__('interrogator_publisher')
        self.publisher_ = self.create_publisher(FbgReading,'interrogator',10)
        timer_period = 0.01
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.address = '10.0.0.55'
        self.msg = FbgReading()

        self.interrogator = Interrogator(self.address)
        self.is_ready = self.interrogator.is_ready
        # get total signal readings
        self.total_reading_num = self.interrogator.total_reading_num
        # get signal in each ch
        self.signal_each_ch = self.interrogator.signal_each_ch
    
        # pass to msg
        self.msg.total_reading_num = self.total_reading_num
        self.msg.signal_each_ch = self.signal_each_ch.astype(np.uint8)
        #
        self.available_ch = self.interrogator.available_ch
        
        

    def timer_callback(self):
        
        rawdata = self.interrogator.getData() #np ndarray
        self.msg.total_reading_num = self.total_reading_num
        self.msg.signal_each_ch = self.signal_each_ch.astype(np.uint8)
        self.msg.signal_reading = array("d",array("d",rawdata)) # array.array
        #print(msg.signal_reading)
        self.publisher_.publish(self.msg)
        #self.get_logger().info('Published %d readings' %self.total_reading_num)


class interrogator_subscriber(Node):
    def __init__(self):
        super().__init__('interrogator_subscriber')
        self.subscription = self.create_subscription(
                FbgReading,
                'interrogator',
                self.listener_callback,
                10)
    def listener_callback(self, msg):
        self.msg = msg
        print(self.msg.signal_each_ch)
        self.callback()
    def callback(self):
        print(self.msg.signal_reading)





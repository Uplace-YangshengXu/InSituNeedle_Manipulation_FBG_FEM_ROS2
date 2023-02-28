import rclpy
import numpy as np
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape,Curvature

class needle_shape_subscriber(Node):
    def __init__(self):
        super().__init__('needle_shape_subscriber')
        self.matlab_listener = 0
        self.curv_listener = 0

        self.needle_subscription = self.create_subscription(
                NeedleShape,
                'needle_shape',
                self.matlab_listener_callback,
                10)
        self.curv_subscription = self.create_subscription(
                Curvature,
                'Pub_Curv',
                self.curv_listener_callback,
                10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period,self.plot_needle_shape)




    def matlab_listener_callback(self,msg):
        self.matlab_listener = 1
        self.needle_msg = msg
        #print(self.needle_msg.needle_total_length)
        #print(self.msg.active_area_location)
        #print(self.msg.needle_x_axis)
        #print(self.msg.needle_y_axis)
        #print(self.msg.needle_z_axis)
        #print(self.msg.needle_slope)

    def curv_listener_callback(self,msg):
        self.curv_listener = 1
        self.curv_msg = msg
        #print(self.curv_msg.curvature_xz)

    def plot_needle_shape(self):
        if self.matlab_listener == 1:
            print(self.needle_msg.needle_total_length)
        if self.curv_listener == 0:
            print("no data from curv pub")
        

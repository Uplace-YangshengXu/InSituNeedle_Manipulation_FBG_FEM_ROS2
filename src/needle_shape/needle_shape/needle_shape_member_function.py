import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape,Curvature
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

class needle_shape_subscriber(Node):
    def __init__(self):
        super().__init__('needle_shape_subscriber')

        # ini figure
        self.matlab_listener = 0
        self.curv_listener = 0
        self.fig = plt.figure()
        self.axs = plt.axes(projection='3d')
        #self.axs = plt.axes()
        self.axs.set_xlabel('x(mm)')
        self.axs.set_ylabel('y(mm)')
        self.axs.set_zlabel('z(mm)')
        self.axs.set_title('Needle Shape')
        self.axs.grid(True)

        self.if_init_needle_shape = 0
        self.if_init_active_area =0


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
        

        plot_timer_period = 0.01
        self.plottimer = self.create_timer(plot_timer_period,self.plot_needle_shape)



    def matlab_listener_callback(self,msg):
        self.needle_msg = msg
        if self.if_init_needle_shape == 0:
            # first get msg from matlab
            # ini line element here
            # create needle in 3d
            self.needle_3d, = self.axs.plot3D([0,self.needle_msg.needle_total_length],[-10,10],[0,0])

            plt.setp(self.needle_3d,linestyle='-',linewidth=2,color='k')
            self.if_init_needle_shape = 1
        
        self.matlab_listener = 1


        print("receive msg from matlab pub")
        #print(self.needle_msg.needle_total_length)
        #print(self.needle_msg.active_area_location)
        #print(self.needle_msg.needle_x_axis)
        #print(self.needle_msg.needle_y_axis)
        #print(self.needle_msg.needle_z_axis)
        #print(np.asarray(self.needle_msg.needle_z_axis))
        #print(self.msg.needle_slope)

    def curv_listener_callback(self,msg):

            
        self.curv_listener = 1
        self.curv_msg = msg
        print("receive msg from curv pub")
        #print(self.curv_msg.curvature_xz)


    
    def plot_needle_shape(self):
        if self.matlab_listener == 1 and self.if_init_needle_shape == 1:
            #update needle shape

            self.needle_3d.set_xdata(np.asarray(self.needle_msg.needle_x_axis))
            self.needle_3d.set_ydata(np.asarray(self.needle_msg.needle_y_axis))
        
            self.needle_3d.set_3d_properties(np.asarray(self.needle_msg.needle_z_axis))

            # plot
            self.fig.tight_layout()
            plt.axis('equal')
            plt.pause(0.01)
            
            self.matlab_listener = 0
        
        if self.curv_listener == 1:
            # update curvature
            
            self.curv_listener = 0




import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape,Curvature
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import sys

class needle_shape_visulisation(Node):
    def __init__(self):
        super().__init__('needle_shape_visulisation')

        # ini figure
        self.matlab_listener = 0
        self.curv_listener = 0
        matplotlib.use('Qt5Agg')
        # QtAgg Qt5Agg agg
        self.fig = plt.figure()
        bk = matplotlib.get_backend()
        matplotlib.rcParams['figure.raise_window'] = 'False'
        #rw = matplotlib.rcParams['figure.raise_window']
        #print(bk)
        #print(rw)
        # open interact mode
        plt.ion()
        
        self.axs = plt.axes(projection='3d')
        
        self.axs.set_xlabel('x(mm)')
        self.axs.set_ylabel('y(mm)')
        self.axs.set_zlabel('z(mm)')
        self.axs.set_title('Needle Shape')
        self.axs.grid(True)

        self.if_init_needle_shape = 0
        self.if_init_active_area = 0


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
        

        plot_timer_period = 0.05
        self.plottimer = self.create_timer(plot_timer_period,self.plot_needle_shape)



    def matlab_listener_callback(self,msg):
        self.needle_msg = msg
        if self.if_init_needle_shape == 0:
            # first get msg from matlab


            self.if_init_needle_shape = 1

            # analyse the content in msg
            # needle base tip and AA relative location
            self.needle_aa_rel_loc = np.asarray(self.needle_msg.active_area_location)
            self.needle_base_rel_loc = 0
            self.needle_tip_rel_loc = self.needle_msg.needle_total_length

            # ini line element here
            # create needle in 3d
            self.needle_3d, = self.axs.plot3D([0,self.needle_msg.needle_total_length],[0,0],[0,0])

            plt.setp(self.needle_3d,linestyle='-',linewidth=2,color='k')
            # create those scatter points
            self.needle_base = self.axs.scatter(0,0,0,marker='v')

            self.active_area = self.axs.scatter(10,10,10,marker='*')
            self.needle_tip = self.axs.scatter(100,10,10,marker='^')

            plt.ioff()
            plt.pause(0.01)
            plt.show(block=False)


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
            
            #update needle shape use animation

            self.needle_3d.set_xdata(np.asarray(self.needle_msg.needle_x_axis))
            self.needle_3d.set_ydata(np.asarray(self.needle_msg.needle_y_axis))
        
            self.needle_3d.set_3d_properties(np.asarray(self.needle_msg.needle_z_axis))

            # plot
            plt.ioff()
            plt.pause(0.01)
            plt.show(block=False)
            
            self.matlab_listener = 0
        
        if self.curv_listener == 1 and self.if_init_active_area == 1:
            # update curvature
            
            self.curv_listener = 0

        
        if self.curv_listener == 0 or self.matlab_listener == 0:
            print("viewer has been suspend")
            plt.show()

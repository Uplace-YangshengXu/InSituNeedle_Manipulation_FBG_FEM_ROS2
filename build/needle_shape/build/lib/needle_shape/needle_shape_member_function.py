import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import sys

class needle_shape_visulisation(Node):
    def __init__(self):
        super().__init__('needle_shape_visulisation')

        # ini figure
        self.matlab_listener = 0

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
        self.axs.grid(False)

        self.if_init_needle_shape = 0


        self.needle_subscription = self.create_subscription(
                NeedleShape,
                'needle_shape',
                self.matlab_listener_callback,
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
            needle_aa_rel_loc = np.asarray(self.needle_msg.active_area_location)
            needle_base_rel_loc = self.needle_msg.needle_x_axis[0]

            needle_tip_rel_loc = self.needle_msg.needle_x_axis[-1]

            # get index
            x_loc = np.asarray(self.needle_msg.needle_x_axis)
            self.needle_base_index = 0
            self.needle_tip_index = []
            self.needle_aa_index = []

            for i in range(len(x_loc)):
                if x_loc[i] in needle_aa_rel_loc:
                    self.needle_aa_index.append(i)
                if needle_tip_rel_loc == x_loc[i]:
                    self.needle_tip_index = i
            
            # ini line element here
            # create needle in 3d
            #print(self.needle_msg.needle_y_axis[self.needle_base_index])
            #print(self.needle_msg.needle_y_axis[self.needle_tip_index])
            #print(self.needle_tip_index)


            self.needle_3d, = self.axs.plot3D(
                    [np.asarray(self.needle_msg.needle_x_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_x_axis[self.needle_tip_index])],
                    [np.asarray(self.needle_msg.needle_y_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_y_axis[self.needle_tip_index])],
                    [np.asarray(self.needle_msg.needle_z_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_z_axis[self.needle_tip_index])]
                    )

            plt.setp(self.needle_3d,linestyle='-',linewidth=2,color='k')
            # create those scatter points
            self.needle_base = self.axs.scatter3D(
                    self.needle_msg.needle_x_axis[self.needle_base_index],
                    self.needle_msg.needle_y_axis[self.needle_base_index],
                    self.needle_msg.needle_z_axis[self.needle_base_index],
                    marker='.',c='brown')

            self.active_area = self.axs.scatter3D(
                    np.asarray(self.needle_msg.needle_x_axis)[self.needle_aa_index],
                    np.asarray(self.needle_msg.needle_y_axis)[self.needle_aa_index],
                    np.asarray(self.needle_msg.needle_z_axis)[self.needle_aa_index],
                    marker='.',c='yellow') # from dark to light??

            self.needle_tip = self.axs.scatter3D(
                    self.needle_msg.needle_x_axis[self.needle_tip_index],
                    self.needle_msg.needle_y_axis[self.needle_tip_index],
                    self.needle_msg.needle_z_axis[self.needle_tip_index],
                    marker='.',c='orange')

            # create needle tip projection
            self.xy_projection, = self.axs.plot3D(
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],self.needle_msg.needle_x_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],self.needle_msg.needle_y_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],0]
                    )

            self.xz_projection, = self.axs.plot3D(
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],self.needle_msg.needle_x_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],0],
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],self.needle_msg.needle_z_axis[self.needle_tip_index]]
                    )

            self.yz_projection, = self.axs.plot3D(
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],0],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],self.needle_msg.needle_y_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],self.needle_msg.needle_z_axis[self.needle_tip_index]]
                    )
            
            plt.setp(self.xy_projection,linestyle='--',linewidth=1,color='b',alpha=0.5)
            plt.setp(self.yz_projection,linestyle='--',linewidth=1,color='r',alpha=0.5)
            plt.setp(self.xz_projection,linestyle='--',linewidth=1,color='g',alpha=0.5)


            plt.ioff()
            plt.pause(0.01)
            plt.show(block=False)

        self.matlab_listener = 1

        #print("receive msg from matlab pub")
        #print(self.needle_msg.needle_total_length)
        #print(self.needle_msg.active_area_location)
        #print(self.needle_msg.needle_x_axis)
        #print(self.needle_msg.needle_y_axis)
        #print(self.needle_msg.needle_z_axis)
        #print(np.asarray(self.needle_msg.needle_z_axis))
        #print(self.msg.needle_slope)


    
    def plot_needle_shape(self):
        if self.matlab_listener == 1 and self.if_init_needle_shape == 1:
            
            #update needle shape use animation

            self.needle_3d.set_xdata(np.asarray(self.needle_msg.needle_x_axis))
            self.needle_3d.set_ydata(np.asarray(self.needle_msg.needle_y_axis)) 
            self.needle_3d.set_3d_properties(np.asarray(self.needle_msg.needle_z_axis))
            
            #self.needle_base._offsets3d = (
            #        np.asarray(self.needle_msg.needle_x_axis[self.needle_base_index]),
            #        np.asarray(self.needle_msg.needle_y_axis[self.needle_base_index]),
            #        np.asarray(self.needle_msg.needle_z_axis[self.needle_base_index])
            #        )

            #self.needle_tip._offsets3d = (
            #        np.asarray(self.needle_msg.needle_x_axis[self.needle_tip_index]),
            #        np.asarray(self.needle_msg.needle_y_axis[self.needle_tip_index]),
            #        np.asarray(self.needle_msg.needle_z_axis[self.needle_tip_index])
            #        )

            #self.active_area._offsets3d = (
            #        np.asarray(self.needle_msg.needle_x_axis)[self.needle_aa_index],
            #        np.asarray(self.needle_msg.needle_y_axis)[self.needle_aa_index],
            #        np.asarray(self.needle_msg.needle_z_axis)[self.needle_aa_index]
            #        )

            self.xy_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index]])
            self.xy_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index]])
            self.xy_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], 0])

            self.xz_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index]])
            self.xz_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],0])
            self.xz_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index]])

            self.yz_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index], 0])
            self.yz_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index]])
            self.yz_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index]])

            
            # plot
            plt.ioff()
            plt.axis('equal')
            plt.pause(0.01)
            plt.show(block=False)
            
            self.matlab_listener = 0
        
        
        #if self.curv_listener == 0 and self.matlab_listener == 0:
            #print("viewer has been suspend")
            

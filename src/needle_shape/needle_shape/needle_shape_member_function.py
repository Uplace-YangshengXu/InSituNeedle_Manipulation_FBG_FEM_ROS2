import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape,Curvature
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib
import sys
from curvature_srvcli.curvature_member_function import CalClient

class needle_shape_visulisation(Node):
    def __init__(self):
        super().__init__('needle_shape_visulisation')

        # ini figure
        self.matlab_listener = 0
        self.curv_listener = 0
        self.curv_text = {}
        matplotlib.use('Qt5Agg')
        # QtAgg Qt5Agg agg
        #matplotlib.rcParams['figure.figsize'] = (3,3)
        self.fig = plt.figure()

        bk = matplotlib.get_backend()
        matplotlib.rcParams['figure.raise_window'] = 'False'
        #rw = matplotlib.rcParams['figure.raise_window']
        #print(bk)
        #print(rw)
        # open interact mode
        plt.ion()
        
        self.axs = plt.axes(projection='3d')
        self.axs.set_box_aspect(aspect = (3,2,1))
        self.axs.view_init(elev=90, azim=-90, roll=0)

        self.axs.set_xlabel('x(mm)')
        self.axs.set_ylabel('y(mm)')
        self.axs.set_zlabel('z(mm)')
        self.axs.set_title('Needle Shape')
        self.axs.set_xlim(-200,80)
        self.axs.set_ylim(-50,50)
        self.axs.set_zlim(-20,20)
        self.axs.set_aspect('equal')
        self.axs.grid(True)
        self.if_init_needle_shape = 0
        self.if_init_curv_plot = 0

        self.tip_traj_x = []
        self.tip_traj_y = []
        self.tip_traj_z = []

        self.needle_subscription = self.create_subscription(
                NeedleShape,
                'needle_shape',
                self.matlab_listener_callback,
                10)
        '''
        self.curv_subscription = self.create_subscription(
                Curvature,
                'Pub_Curv',
                self.curv_listener_callback,
                10)
        '''

        plot_timer_period = 0.05
        self.plottimer = self.create_timer(plot_timer_period,self.plot_needle_shape)
        
        self.client = CalClient()
        
    '''
    def curv_listener_callback(self,msg):   
        self.curv_msg = msg
        if self.if_init_curv_plot == 0:
            # init plot
            self.if_init_curv_plot = 1
            print(curv_msg.curvatures_xy)
        self.curv_listener = 1
    '''


    def matlab_listener_callback(self,msg):
        self.needle_msg = msg
        #update tip traj
        self.tip_traj_x.append(self.needle_msg.needle_x_axis[-1])
        self.tip_traj_y.append(self.needle_msg.needle_y_axis[-1])
        self.tip_traj_z.append(self.needle_msg.needle_z_axis[-1])

        if self.if_init_needle_shape == 0:
            # first get msg from matlab


            self.if_init_needle_shape = 1

            # analyse the content in msg
            # needle base tip and AA relative location
            needle_aa_rel_loc = np.asarray(self.needle_msg.active_area_location)
            print(needle_aa_rel_loc)
            needle_base_rel_loc = self.needle_msg.needle_x_axis[0]

            needle_tip_rel_loc = self.needle_msg.needle_x_axis[-1]

            # get index
            x_loc = np.asarray(self.needle_msg.needle_x_axis)
            self.needle_base_index = 0
            self.needle_tip_index = []
            self.needle_aa_index = []
            for i in range(len(x_loc)):
                #if x_loc[i] in needle_aa_rel_loc:
                #    self.needle_aa_index.append(i)
                if needle_tip_rel_loc == x_loc[i]:
                    self.needle_tip_index = i
            self.needle_aa_index = np.int32((len(x_loc)-1)/int(self.needle_msg.needle_total_length)* needle_aa_rel_loc)
            print((len(x_loc)-1)/int(self.needle_msg.needle_total_length)* needle_aa_rel_loc)
            # ini line element here
            # create needle in 3d


            self.needle_3d, = self.axs.plot3D(
                    [np.asarray(self.needle_msg.needle_x_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_x_axis[self.needle_tip_index])],
                    [np.asarray(self.needle_msg.needle_y_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_y_axis[self.needle_tip_index])],
                    [np.asarray(self.needle_msg.needle_z_axis[self.needle_base_index]),np.asarray(self.needle_msg.needle_z_axis[self.needle_tip_index])]
                    )
            
            self.needle_tip_3d, = self.axs.plot3D(
                    [np.asarray(self.tip_traj_x)],
                    [np.asarray(self.tip_traj_y)],
                    [np.asarray(self.tip_traj_z)]
                    )

            plt.setp(self.needle_3d,linestyle='-',linewidth=2,color='k')
            # create those scatter points
            self.needle_base = self.axs.scatter(
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
            
            self.base_text = self.axs.text(self.needle_msg.needle_x_axis[self.needle_base_index], 
                                           self.needle_msg.needle_y_axis[self.needle_base_index],
                                           self.needle_msg.needle_z_axis[self.needle_base_index], "base", color='red')
            
            self.tip_text = self.axs.text(self.needle_msg.needle_x_axis[self.needle_tip_index], 
                                           self.needle_msg.needle_y_axis[self.needle_tip_index],
                                           self.needle_msg.needle_z_axis[self.needle_tip_index], "tip", color='red')
            
            for i in range(len(self.needle_aa_index)):
                self.curv_text[i] = self.axs.text(self.needle_msg.needle_x_axis[self.needle_aa_index[i]], 
                                           self.needle_msg.needle_y_axis[self.needle_aa_index[i]]-2,
                                           self.needle_msg.needle_z_axis[self.needle_aa_index[i]],"AA" + str(i), color = 'black' )

            # create needle tip projection
            '''
            self.xy_projection, = self.axs.plot3D(
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],self.needle_msg.needle_x_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],self.needle_msg.needle_y_axis[self.needle_tip_index]],
                    #[self.needle_msg.needle_z_axis[self.needle_tip_index],0]
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],self.axs.get_zlim()[0]]
                    )

            self.xz_projection, = self.axs.plot3D(
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],self.needle_msg.needle_x_axis[self.needle_tip_index]],
                    #[self.needle_msg.needle_y_axis[self.needle_tip_index],0],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],self.axs.get_ylim()[0]],
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],self.needle_msg.needle_z_axis[self.needle_tip_index]]
                    )
            '''
            self.yz_projection, = self.axs.plot3D(
                    #[self.needle_msg.needle_x_axis[self.needle_tip_index],0],
                    [self.needle_msg.needle_x_axis[self.needle_tip_index],self.axs.get_xlim()[0]],
                    [self.needle_msg.needle_y_axis[self.needle_tip_index],self.needle_msg.needle_y_axis[self.needle_tip_index]],
                    [self.needle_msg.needle_z_axis[self.needle_tip_index],self.needle_msg.needle_z_axis[self.needle_tip_index]]
                    )
            
            #plt.setp(self.xy_projection,linestyle='--',linewidth=1,color='b',alpha=0.5)
            plt.setp(self.yz_projection,linestyle='--',linewidth=1,color='r',alpha=0.5)
            #plt.setp(self.xz_projection,linestyle='--',linewidth=1,color='g',alpha=0.5)


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
        if self.client.cli.service_is_ready() == 1:
                response = self.client.send_request()
                self.curv_msg = response.curvature
                self.if_init_curv_plot = 1


        if self.matlab_listener == 1 and self.if_init_needle_shape == 1:
            
            #update needle shape use animation

            self.needle_3d.set_xdata(np.asarray(self.needle_msg.needle_x_axis))
            self.needle_3d.set_ydata(np.asarray(self.needle_msg.needle_y_axis)) 
            self.needle_3d.set_3d_properties(np.asarray(self.needle_msg.needle_z_axis))

            self.needle_tip_3d.set_xdata(np.asarray(self.tip_traj_x))
            self.needle_tip_3d.set_ydata(np.asarray(self.tip_traj_y))
            self.needle_tip_3d.set_3d_properties(np.asarray(self.tip_traj_z))


            self.base_text.set_position([self.needle_msg.needle_x_axis[self.needle_base_index],
                                         self.needle_msg.needle_y_axis[self.needle_base_index]+2,
                                         self.needle_msg.needle_z_axis[self.needle_base_index]+1])
            self.base_text.set_text("[" + str(round(self.needle_msg.needle_x_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_y_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_z_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_slope[self.needle_base_index],3))
                                        + "]")


            
            self.tip_text.set_position([self.needle_msg.needle_x_axis[self.needle_tip_index],
                                         self.needle_msg.needle_y_axis[self.needle_tip_index]+2,
                                         self.needle_msg.needle_z_axis[self.needle_tip_index]+1])
            

            self.tip_text.set_text("[" + str(round(self.needle_msg.needle_x_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_y_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_z_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg.needle_slope[self.needle_tip_index],3))
                                        + "]")
            for i in range(len(self.needle_aa_index)):
                self.curv_text[i].set_position([self.needle_msg.needle_x_axis[self.needle_aa_index[i]], 
                                           self.needle_msg.needle_y_axis[self.needle_aa_index[i]]-15,
                                           self.needle_msg.needle_z_axis[self.needle_aa_index[i]]])
                if self.if_init_curv_plot == 1:
                        print(self.curv_msg)
                        self.curv_text[i].set_text("[" + str(round(self.curv_msg.curvature_xy[i],4)) + ", " + str(round(self.curv_msg.curvature_xz[i],4)) + "]")

            self.needle_base._offsets3d = (
                    np.ma.ravel(self.needle_msg.needle_x_axis[self.needle_base_index]),
                    np.ma.ravel(self.needle_msg.needle_y_axis[self.needle_base_index]),
                    np.ma.ravel(self.needle_msg.needle_z_axis[self.needle_base_index]),
                    )
            self.needle_tip._offsets3d = (
                    np.ma.ravel(self.needle_msg.needle_x_axis[self.needle_tip_index]),
                    np.ma.ravel(self.needle_msg.needle_y_axis[self.needle_tip_index]),
                    np.ma.ravel(self.needle_msg.needle_z_axis[self.needle_tip_index])
                    ) 
            self.active_area._offsets3d = (
                    np.ma.ravel(np.asarray(self.needle_msg.needle_x_axis)[self.needle_aa_index]),
                    np.ma.ravel(np.asarray(self.needle_msg.needle_y_axis)[self.needle_aa_index]),
                    np.ma.ravel(np.asarray(self.needle_msg.needle_z_axis)[self.needle_aa_index])
                    )
            '''
            self.xy_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index]])
            self.xy_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index]])
            #self.xy_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], 0])
            self.xy_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index],self.axs.get_zlim()[0]])

            self.xz_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index]])
            #self.xz_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],0])
            self.xz_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],self.axs.get_ylim()[0]])
            self.xz_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index]])
            '''
            #self.yz_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index], 0])
            self.yz_projection.set_xdata([np.asarray(self.needle_msg.needle_x_axis)[self.needle_tip_index],self.axs.get_xlim()[0]])
            self.yz_projection.set_ydata([np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index],np.asarray(self.needle_msg.needle_y_axis)[self.needle_tip_index]])
            self.yz_projection.set_3d_properties([np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index], np.asarray(self.needle_msg.needle_z_axis)[self.needle_tip_index]])

            
            # plot
            plt.ioff()
            #plt.axis('equal')
            plt.pause(0.01)
            plt.show(block=False)
            
            self.matlab_listener = 0
        
        
        #if self.curv_listener == 0 and self.matlab_listener == 0:
            #print("viewer has been suspend")
            



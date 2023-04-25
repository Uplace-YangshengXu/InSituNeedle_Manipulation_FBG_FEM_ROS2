import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import NeedleShape,Curvature

from itertools import product, combinations

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
        self.fbg_listener = 0

        self.curv_text = {}
        matplotlib.use('Qt5Agg')
        # QtAgg Qt5Agg agg
        #matplotlib.rcParams['figure.figsize'] = (3,3)
        self.fig = plt.figure()
        #self.axs_cube = self.fig.add_subplot(111 , projection = '3d')
        bk = matplotlib.get_backend()
        matplotlib.rcParams['figure.raise_window'] = 'False'
        #rw = matplotlib.rcParams['figure.raise_window']
        #print(bk)
        #print(rw)
        # open interact mode
        plt.ion()
        
        self.axs = plt.axes(projection='3d')
        self.axs.set_box_aspect(aspect = (3,2,1))
        self.axs.view_init(elev=26, azim=-36, roll=0)

        self.axs.set_xlabel('x(mm)')
        self.axs.set_ylabel('y(mm)')
        self.axs.set_zlabel('z(mm)')
        self.axs.set_title('Needle Shape')
        self.axs.set_xlim(-170,50)
        self.axs.set_ylim(-50,50)
        self.axs.set_zlim(-20,20)
        self.axs.set_aspect('equal')
        self.axs.grid(True)
        self.if_init_needle_shape = 0
        self.if_init_curv_plot = 0
        self.if_init_fbg_shape = 0
        #self.data = np.ones(np.array([20,20,20]))
        self.tip_traj_x = []
        self.tip_traj_y = []
        self.tip_traj_z = []

        self.needle_subscription = self.create_subscription(
                NeedleShape,
                'needle_shape',
                self.matlab_listener_callback,
                10)
        
        self.fbg_subscription = self.create_subscription(
                NeedleShape,
                'needle_shape_fbg',
                self.fbg_listener_callback,
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
        
            #self.axs.voxels(self.data, facecolors="yellow")

            rx = [-30,30]
            ry = [-40,40]
            rz = [-20,20]
            for s, e in combinations(np.array(list(product(rx, ry, rz)))+np.array([20, 0, 0]), 2):
                if np.sum(np.abs(s-e)) == rx[1]-rx[0]:
                        self.axs.plot3D(*zip(s, e), color="gray")
                if np.sum(np.abs(s-e)) == ry[1]-ry[0]:
                        self.axs.plot3D(*zip(s, e), color="gray")
                if np.sum(np.abs(s-e)) == rz[1]-rz[0]:
                        self.axs.plot3D(*zip(s, e), color="gray")
            self.axs.legend(['Needle', 'TipTraj'])   
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

    def fbg_listener_callback(self,msg):
                self.needle_msg_fbg = msg

                if self.if_init_fbg_shape == 0:
                # first get msg from matlab


                        self.if_init_fbg_shape = 1

                        # analyse the content in msg
                        # needle base tip and AA relative location
                        needle_aa_rel_loc = np.asarray(self.needle_msg.active_area_location)
                        print(needle_aa_rel_loc)
                        needle_base_rel_loc = self.needle_msg_fbg.needle_x_axis[0]

                        needle_tip_rel_loc = self.needle_msg_fbg.needle_x_axis[-1]

                        # get index
                        x_loc = np.asarray(self.needle_msg_fbg.needle_x_axis)
                        self.needle_base_index = 0
                        self.needle_tip_index = []
                        self.needle_aa_index = []
                        for i in range(len(x_loc)):
                                #if x_loc[i] in needle_aa_rel_loc:
                                #    self.needle_aa_index.append(i)
                                if needle_tip_rel_loc == x_loc[i]:
                                        self.needle_tip_index = i
                        self.needle_aa_index = np.int32((len(x_loc)-1)/int(self.needle_msg_fbg.needle_total_length)* needle_aa_rel_loc)
                        print((len(x_loc)-1)/int(self.needle_msg_fbg.needle_total_length)* needle_aa_rel_loc)
                        # ini line element here
                        # create needle in 3d


                        self.needle_3d_fbg, = self.axs.plot3D(
                                [np.asarray(self.needle_msg_fbg.needle_x_axis[self.needle_base_index]),np.asarray(self.needle_msg_fbg.needle_x_axis[self.needle_tip_index])],
                                [np.asarray(self.needle_msg_fbg.needle_y_axis[self.needle_base_index]),np.asarray(self.needle_msg_fbg.needle_y_axis[self.needle_tip_index])],
                                [np.asarray(self.needle_msg_fbg.needle_z_axis[self.needle_base_index]),np.asarray(self.needle_msg_fbg.needle_z_axis[self.needle_tip_index])]
                                )
                        

                        plt.setp(self.needle_3d_fbg,linestyle='-',linewidth=2,color='red')
                        # create those scatter points
                        self.needle_base_fbg = self.axs.scatter(
                                self.needle_msg_fbg.needle_x_axis[self.needle_base_index],
                                self.needle_msg_fbg.needle_y_axis[self.needle_base_index],
                                self.needle_msg_fbg.needle_z_axis[self.needle_base_index],
                                marker='.',c='brown')

                        self.active_area_fbg = self.axs.scatter3D(
                                np.asarray(self.needle_msg_fbg.needle_x_axis)[self.needle_aa_index],
                                np.asarray(self.needle_msg_fbg.needle_y_axis)[self.needle_aa_index],
                                np.asarray(self.needle_msg_fbg.needle_z_axis)[self.needle_aa_index],
                                marker='.',c='yellow') # from dark to light??

                        self.needle_tip_fbg = self.axs.scatter3D(
                                self.needle_msg_fbg.needle_x_axis[self.needle_tip_index],
                                self.needle_msg_fbg.needle_y_axis[self.needle_tip_index],
                                self.needle_msg_fbg.needle_z_axis[self.needle_tip_index],
                                marker='.',c='orange')
                        
                        self.base_text_fbg = self.axs.text(str(round(self.needle_msg_fbg.needle_x_axis[self.needle_base_index]),1), 
                                                        str(round(self.needle_msg_fbg.needle_y_axis[self.needle_base_index]),1),
                                                        str(round(self.needle_msg_fbg.needle_z_axis[self.needle_base_index]),1), "base", color='red')
                        
                        self.tip_text_fbg = self.axs.text(self.needle_msg_fbg.needle_x_axis[self.needle_tip_index], 
                                                        self.needle_msg_fbg.needle_y_axis[self.needle_tip_index],
                                                        self.needle_msg_fbg.needle_z_axis[self.needle_tip_index], "tip", color='red')
                        

                        # create needle tip projection

                        self.yz_projection_fbg, = self.axs.plot3D(
                                #[self.needle_msg.needle_x_axis[self.needle_tip_index],0],
                                [self.needle_msg_fbg.needle_x_axis[self.needle_tip_index],self.axs.get_xlim()[0]],
                                [self.needle_msg_fbg.needle_y_axis[self.needle_tip_index],self.needle_msg.needle_y_axis[self.needle_tip_index]],
                                [self.needle_msg_fbg.needle_z_axis[self.needle_tip_index],self.needle_msg.needle_z_axis[self.needle_tip_index]]
                                )
                        
                        #plt.setp(self.xy_projection,linestyle='--',linewidth=1,color='b',alpha=0.5)
                        plt.setp(self.yz_projection_fbg,linestyle='--',linewidth=1,color='y',alpha=0.5)
                        #plt.setp(self.xz_projection,linestyle='--',linewidth=1,color='g',alpha=0.5)


                        plt.ioff()
                        plt.pause(0.01)
                        plt.show(block=False)

                self.fbg_listener = 1



    
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
                    if len(self.curv_msg.curvature_xy) == 0 or len(self.curv_msg.curvature_xz) == 0:
                        self.curv_text[i].set_text("simulate data")
                        print(i)
                        print(self.curv_msg.curvature_xy)
                    else:
                        self.curv_text[i].set_text("[" + str(round(self.curv_msg.curvature_xy[i],2)) + ", " + str(round(self.curv_msg.curvature_xz[i],2)) + "]")


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

        if self.fbg_listener == 1 and self.if_init_fbg_shape == 1:
            
            #update needle shape use animation

            self.needle_3d_fbg.set_xdata(np.asarray(self.needle_msg_fbg.needle_x_axis))
            self.needle_3d_fbg.set_ydata(np.asarray(self.needle_msg_fbg.needle_y_axis)) 
            self.needle_3d_fbg.set_3d_properties(np.asarray(self.needle_msg_fbg.needle_z_axis))

            self.base_text_fbg.set_position([self.needle_msg_fbg.needle_x_axis[self.needle_base_index],
                                         self.needle_msg_fbg.needle_y_axis[self.needle_base_index]+2,
                                         self.needle_msg_fbg.needle_z_axis[self.needle_base_index]+1])
            self.base_text_fbg.set_text("[" + str(round(self.needle_msg_fbg.needle_x_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_y_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_z_axis[self.needle_base_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_slope[self.needle_base_index],3))
                                        + "]")


            
            self.tip_text_fbg.set_position([self.needle_msg_fbg.needle_x_axis[self.needle_tip_index],
                                         self.needle_msg_fbg.needle_y_axis[self.needle_tip_index]+2,
                                         self.needle_msg_fbg.needle_z_axis[self.needle_tip_index]+1])
            

            self.tip_text_fbg.set_text("[" + str(round(self.needle_msg_fbg.needle_x_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_y_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_z_axis[self.needle_tip_index],3))
                                        + ", "
                                        + str(round(self.needle_msg_fbg.needle_slope[self.needle_tip_index],3))
                                        + "]")


            self.needle_base_fbg._offsets3d = (
                    np.ma.ravel(self.needle_msg_fbg.needle_x_axis[self.needle_base_index]),
                    np.ma.ravel(self.needle_msg_fbg.needle_y_axis[self.needle_base_index]),
                    np.ma.ravel(self.needle_msg_fbg.needle_z_axis[self.needle_base_index]),
                    )
            self.needle_tip_fbg._offsets3d = (
                    np.ma.ravel(self.needle_msg_fbg.needle_x_axis[self.needle_tip_index]),
                    np.ma.ravel(self.needle_msg_fbg.needle_y_axis[self.needle_tip_index]),
                    np.ma.ravel(self.needle_msg_fbg.needle_z_axis[self.needle_tip_index])
                    ) 
            self.active_area_fbg._offsets3d = (
                    np.ma.ravel(np.asarray(self.needle_msg_fbg.needle_x_axis)[self.needle_aa_index]),
                    np.ma.ravel(np.asarray(self.needle_msg_fbg.needle_y_axis)[self.needle_aa_index]),
                    np.ma.ravel(np.asarray(self.needle_msg_fbg.needle_z_axis)[self.needle_aa_index])
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
            self.yz_projection_fbg.set_xdata([np.asarray(self.needle_msg_fbg.needle_x_axis)[self.needle_tip_index],self.axs.get_xlim()[0]])
            self.yz_projection_fbg.set_ydata([np.asarray(self.needle_msg_fbg.needle_y_axis)[self.needle_tip_index],np.asarray(self.needle_msg_fbg.needle_y_axis)[self.needle_tip_index]])
            self.yz_projection_fbg.set_3d_properties([np.asarray(self.needle_msg_fbg.needle_z_axis)[self.needle_tip_index], np.asarray(self.needle_msg_fbg.needle_z_axis)[self.needle_tip_index]])

            
            # plot
            plt.ioff()
            #plt.axis('equal')
            plt.pause(0.01)
            plt.show(block=False)
            
            self.fbg_listener = 0
        
        
        #if self.curv_listener == 0 and self.matlab_listener == 0:
            #print("viewer has been suspend")
            



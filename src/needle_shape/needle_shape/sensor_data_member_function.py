import rclpy
import numpy as np
import time
from rclpy.node import Node
from fbg_msgs.msg import FbgReading,Curvature
import matplotlib
import matplotlib.pyplot as plt

class sensor_data_visulisation(Node):
    def __init__(self):
        super().__init__('sensor_data_visulisation')
        
        self.declare_parameter('channel_selection',1)
        self.declare_parameter('plot_point',200)
        self.channel_selection = self.get_parameter('channel_selection').get_parameter_value().integer_value
        self.plot_point = self.get_parameter('plot_point').get_parameter_value().integer_value

        #
        self.curv_listener = 0
        self.sm130_listener = 0
        self.color_list = ['r','b','g','y','c','k','w','m']

        self.current_point_num = 0
        self.current_time = 0
        #
        matplotlib.use('Qt5Agg')
        bk = matplotlib.get_backend()
        matplotlib.rcParams['figure.raise_window'] = 'False'

        plt.ion()

        self.if_init_sm130_plot = 0

        #self.curv_subscription = self.create_subscription(
        #        Curvature,
        #        'Pub_Curv',
        #        self.curv_listener_callback,
        #        10)

        self.sm130_subscription = self.create_subscription(
                FbgReading,
                'sm130',
                self.sm130_listener_callback,
                10)

        plot_timer_period = 0.05
        self.plottimer = self.create_timer(plot_timer_period,self.plot_sensor_reading)

    def sm130_listener_callback(self,msg):
        self.sensor_reading_msg = msg

        if self.channel_selection == self.get_parameter('channel_selection').get_parameter_value().integer_value and self.plot_point == self.get_parameter('plot_point').get_parameter_value().integer_value:
            # param not change
            pass
        else:
            self.if_init_sm130_plot = 0
            plt.close(self.fig)
            # redo init
        

        if self.if_init_sm130_plot == 0:
            self.channel_selection = self.get_parameter('channel_selection').get_parameter_value().integer_value
            self.plot_point = self.get_parameter('plot_point').get_parameter_value().integer_value
            print("Currently plot data from interrogator channel %d" %(self.channel_selection))

            # init plot
            self.if_init_sm130_plot = 1
            
            self.axs_num = self.sensor_reading_msg.signal_each_ch[self.channel_selection-1]
            if self.axs_num == 0:
                print("data reading for this channel is 0")
                self.if_init_sm130_plot = 0
                return
            
            self.fig,self.axs = plt.subplots(self.axs_num,1)
            plt.subplots_adjust(wspace=0.3,hspace=0.8)
            self.fig.set_figwidth(20)
            self.fig.set_figheight(12)

            # determine data start index
            self.data_start_index = 0
            for i in range(self.channel_selection-1):
                self.data_start_index += self.sensor_reading_msg.signal_each_ch[i]


            #print(self.data_start_index)


            self.count = time.perf_counter()
            AA_count = 1
            self.buff_x = []
            self.buff_x.append(self.current_time)
            self.buff_y = []
            for items in self.axs:
                items.grid()
                items.set_xlabel("time(s)")
                items.set_ylabel("Wavelength")
                items.set_title("Interrogator_CH%d AA%d" %(self.channel_selection,AA_count))
                ydata = self.sensor_reading_msg.signal_reading[self.data_start_index+AA_count - 1]
                items.plot(self.current_time,ydata,self.color_list[AA_count-1])
                self.buff_y.append([ydata])
                AA_count += 1
                    
            # buff_y should be 1*numAA list
            plt.ioff()
            plt.pause(0.01)
            plt.show(block=False)
            self.current_point_num += 1
            self.time_interval = time.perf_counter() - self.count
        self.sm130_listener = 1


        #def curv_listener_callback(self,msg):
        #    
        #    self.curv_msg = msg
        #    
        #    if self.if_init_curv_plot == 0:

                # init plot
        #        self.if_init_curv_plot = 1
        #        pass
        #
        #    self.curv_listener = 1

        
    def plot_sensor_reading(self):
        if self.sm130_listener == 1 and self.if_init_sm130_plot == 1:
            # update plot
            self.count = time.perf_counter()
            self.current_time += self.time_interval

            if self.current_point_num < self.plot_point:
                    
                AA_count = 1
                self.buff_x.append(self.current_time)
                for items in self.axs:
                    items.grid()
                    items.set_xlabel("time(s)")
                    items.set_ylabel("Wavelength")
                    items.set_title("Interrogator_CH%d AA%d" %(self.channel_selection,AA_count))

                    ydata = self.sensor_reading_msg.signal_reading[self.data_start_index+AA_count - 1]
                    self.buff_y[AA_count-1].append(ydata)
                    items.plot(self.buff_x,self.buff_y[AA_count-1],self.color_list[AA_count-1])
                    items.plot(
                            [self.buff_x[0],self.buff_x[-1]],
                            [self.buff_y[AA_count-1][-1],self.buff_y[AA_count-1][-1]], 
                            linestyle='--',
                            color=self.color_list[AA_count-1],
                            linewidth=1)
                    AA_count += 1


            else:
                self.buff_x.pop(0)
                AA_count = 1
                self.buff_x.append(self.current_time)
                for items in self.axs:
                    items.grid()
                    items.set_xlabel("time(s)")
                    items.set_ylabel("Wavelength")
                    items.set_title("Interrogator_CH%d AA%d" %(self.channel_selection,AA_count))
                        
                    ydata = self.sensor_reading_msg.signal_reading[self.data_start_index+AA_count - 1]
                    self.buff_y[AA_count-1].pop(0)
                    self.buff_y[AA_count-1].append(ydata)
                    items.plot(self.buff_x,self.buff_y[AA_count-1],self.color_list[AA_count-1])
                    items.plot(
                            [self.buff_x[0],self.buff_x[-1]],
                            [self.buff_y[AA_count-1][-1],self.buff_y[AA_count-1][-1]], 
                            linestyle='--',
                            color=self.color_list[AA_count-1],
                            linewidth=1)
                    AA_count += 1

            plt.ioff()
            plt.pause(0.01)
            plt.show(block=False)
                
            # clear the plot
            for items in self.axs:
                items.clear()


            self.current_point_num += 1
            self.sm130_listener = 0
            self.time_interval = time.perf_counter() - self.count


from fbg_msgs.srv import CalCurvature
from fbg_msgs.msg import FbgReading, Curvature

#from sm130_member_function import interrogator_subscriber
from .FBG import FBG_process
import rclpy
from rclpy.node import Node
from array import array
import numpy as np

class CalService(Node):

    def __init__(self,Load_json_filename):
        
        self.if_init_fbg_process = 0
        self.Load_json_filename = Load_json_filename

        super().__init__('CalCurv_service')
        self.srv = self.create_service(CalCurvature,'cal_curv',self.cal_curv_callback)
        self.sub = self.create_subscription(
                FbgReading,
                'sm130',
                self.listener_callback,
                10)
         
        
    
    def cal_curv_callback(self, request, response):
        #calculate response
        #print("get request from client")
        #print(request)
        #print(response)
        if self.if_init_fbg_process == 1:
            #ref = self.fbg_process.ref_wavelength
            curvatures = self.fbg_process.getCurvatures(np.asarray(self.msg.signal_reading))

            #print("ref wavelength:")
            #print(self.fbg_process.ref_wavelength)
            if len(curvatures) == 0:
                print("get empty curvatures")
                response.curvature.curvature_xy = array("d",[])
                response.curvature.curvature_xz = array("d",[])
            else:    
                response.curvature.curvature_xy = array("d",curvatures[:,0])
                response.curvature.curvature_xz = array("d",curvatures[:,1])

            print("send msgs to client:")
            print(response)
            
        else:
            print("fbg ref data miss, try again!")

        return response



    def listener_callback(self, msg):

        self.msg = msg
        if self.if_init_fbg_process == 0:
      
            self.fbg_process = FBG_process(self.Load_json_filename,self.msg.total_reading_num,self.msg.signal_each_ch,np.asarray(self.msg.signal_reading))
            self.if_init_fbg_process = 1
        #end if




class CalClient(Node):
    def __init__(self):
        super().__init__('CalCurv_client')
        self.cli = self.create_client(CalCurvature,'cal_curv')
        #while not self.cli.wait_for_service(timeout_sec = 1.0):
        self.req = CalCurvature.Request()

    def send_request(self):
    
        #sm130_subscriber = interrogator_subscriber()
        self.req.command = "requested"
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        return self.future.result()




class CurvPublisher(Node):
    def __init__(self):
        super().__init__('Curv_publisher')
        
        self.publisher_ = self.create_publisher(Curvature,'pub_Curv',10)
        timer_period = 0.05
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.msg = Curvature()
        
        self.client = CalClient()
    
    
    def timer_callback(self):
        response = self.client.send_request()
        print("get curvature from server")
        self.msg = response.curvature
        self.publisher_.publish(self.msg)

'''
class CurvPublisher(Node):
    def __init__(self):
        super().__init__('Curv_publisher')
        self.client = self.create_client(CalCurvature,'cal_curv')
        self.req = CalCurvature.Request()
        
        self.publisher_ = self.create_publisher(Curvature,'pub_Curv',10)
        timer_period = 0.1  
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.msg = Curvature()
        
        
        #self.client = CalClient()
    
    def send_request(self):
        #sm130_subscriber = interrogator_subscriber()
        self.req.command = "requested"
        self.future = self.client.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        return self.future.result()
    
    def timer_callback(self):
        response = self.send_request()
        print(response)
        self.msg = response.curvature
        self.publisher_.publish(self.msg)
        
'''

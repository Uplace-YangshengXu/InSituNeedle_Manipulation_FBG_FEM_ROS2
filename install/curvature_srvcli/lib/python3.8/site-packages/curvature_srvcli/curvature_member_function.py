from fbg_msgs.srv import CalCurvature
from fbg_msgs.msg import FbgReading
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
        print("get request from client")
        if self.if_init_fbg_process == 1:
            curvatures = self.fbg_process.getCurvatures(np.asarray(self.msg.signal_reading))
            


            response.curvature.curvature_xy = array("d",curvatures[:,0])
            response.curvature.curvature_xz = array("d",curvatures[:,1])
            print("send msgs to client:")
            #print(curvatures)
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


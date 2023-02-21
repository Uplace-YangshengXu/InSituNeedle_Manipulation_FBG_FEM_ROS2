from fbg_msgs.srv import CalCurvature
#from sm130_member_function import interrogator_subscriber

import rclpy
from rclpy.node import Node
from array import array
import numpy as np

class CalService(Node):

    def __init__(self):
        super().__init__('CalCurv_service')
        self.srv = self.create_service(CalCurvature,'cal_curv',self.cal_curv_callback)
        
    def cal_curv_callback(self, request, response):
        #calculate response
        rawdata = array("d",[1,2,3])
        response.curvature.curvature_xy = request.fbg_reading.signal_reading
        response.curvature.curvature_xz = rawdata
        return response


class CalClient(Node):
    def __init__(self):
        super().__init__('CalCurv_client')
        self.cli = self.create_client(CalCurvature,'cal_curv')
        #while not self.cli.wait_for_service(timeout_sec = 1.0):
        self.req = CalCurvature.Request()

    def send_request(self,msg):
    
        #sm130_subscriber = interrogator_subscriber()
        self.req.fbg_reading.signal_reading = msg 
        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self,self.future)
        return self.future.result()


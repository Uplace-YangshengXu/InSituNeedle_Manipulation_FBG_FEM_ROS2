from .curvature_member_function import CalService
import rclpy
import os
def main():
    #json_filename = '2CH_3AA_0006.json' #old json file without temperature compensation
    json_filename = '3CH_2AA_0006wTC.json' #newest json file with temperature compensation
    cwd = os.getcwd()
    json_params_file_path = os.path.join(cwd,"src/curvature_srvcli/curvature_srvcli",json_filename)

    rclpy.init()
    
    server = CalService(json_params_file_path)
    
    rclpy.spin(server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()

from .curvature_member_function import CalService
import rclpy
import os
def main():
    json_filename = '3CH_4AA_0006.json'
    cwd = os.getcwd()
    json_params_file_path = os.path.join(cwd,"src/curvature_srvcli/curvature_srvcli",json_filename)

    rclpy.init()
    
    server = CalService(json_params_file_path)
    
    rclpy.spin(server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()

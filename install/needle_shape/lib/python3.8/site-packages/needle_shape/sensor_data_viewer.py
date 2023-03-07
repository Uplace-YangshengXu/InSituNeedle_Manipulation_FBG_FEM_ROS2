from .sensor_data_member_function import sensor_data_visulisation
import rclpy
import sys

def main(args = None):
    rclpy.init(args=args)
    viewer = sensor_data_visulisation()
    rclpy.spin(viewer)
    viewer.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    

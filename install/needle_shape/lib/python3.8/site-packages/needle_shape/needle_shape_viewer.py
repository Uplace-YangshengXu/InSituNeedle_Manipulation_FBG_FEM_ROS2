from .needle_shape_member_function import needle_shape_visulisation 
import rclpy

def main(args = None):
    rclpy.init(args=args)
    viewer = needle_shape_visulisation() 
    rclpy.spin(viewer)
    viewer.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

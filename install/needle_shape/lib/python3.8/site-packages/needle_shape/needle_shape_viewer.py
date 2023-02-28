from .needle_shape_member_function import needle_shape_subscriber 
import rclpy

def main(args = None):
    rclpy.init(args=args)
    subscriber = needle_shape_subscriber() 
    rclpy.spin(subscriber)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

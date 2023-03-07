from .sm130_member_function import interrogator_subscriber
import rclpy
def main(args=None):
    rclpy.init(args=args)
    sm130_subscriber = interrogator_subscriber()
    rclpy.spin(sm130_subscriber)

    sm130_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

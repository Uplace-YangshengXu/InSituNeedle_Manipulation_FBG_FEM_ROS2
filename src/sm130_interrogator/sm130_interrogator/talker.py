from .sm130_member_function import interrogator_publisher
import rclpy

def main(args = None):
    rclpy.init(args=args)

    sm130_publisher = interrogator_publisher()
    rclpy.spin(sm130_publisher)
    sm130_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

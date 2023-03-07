from .sm130_member_function import interrogator_publisher
import rclpy

def main(args = None):
    rclpy.init(args=args)

    sm130_publisher = interrogator_publisher()
    if sm130_publisher.is_ready == 1:
        print("sm130 interrogator publisher starts")
        rclpy.spin(sm130_publisher)
        sm130_publisher.destroy_node()
        rclpy.shutdown()
    else:
        print("sm130 interrogator publisher fail to start")


if __name__ == '__main__':
    main()

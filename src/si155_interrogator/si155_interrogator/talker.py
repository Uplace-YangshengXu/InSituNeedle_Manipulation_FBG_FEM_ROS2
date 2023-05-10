from .si155_member_function import interrogator_publisher
import rclpy

def main(args = None):
    rclpy.init(args=args)

    si155_publisher = interrogator_publisher()
    if si155_publisher.is_ready == 1:
        print("si155 interrogator publisher starts")
        rclpy.spin(si155_publisher)
        si155_publisher.destroy_node()
        rclpy.shutdown()
    else:
        print("si155 interrogator publisher fail to start")


if __name__ == '__main__':
    main()

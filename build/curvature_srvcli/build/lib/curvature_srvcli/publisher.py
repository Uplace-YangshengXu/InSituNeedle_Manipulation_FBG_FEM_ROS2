from .curvature_member_function import CurvPublisher
import rclpy

def main(args = None):
    rclpy.init(args=args)

    curv_publisher = CurvPublisher()
    #if curv_publisher.is_ready == 1:
    print("curvature publisher starts")
    rclpy.spin(curv_publisher)
    curv_publisher.destroy_node()
    rclpy.shutdown()
    #else:
    #    print("curvature publisher fail to start")

if __name__ == '__main__':
    main()

from .curvature_member_function import CalService
import rclpy

def main():
    rclpy.init()

    server = CalService()

    rclpy.spin(server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
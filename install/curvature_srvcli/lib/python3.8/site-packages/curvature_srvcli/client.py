from .curvature_member_function import CalClient
import rclpy
def main():
    rclpy.init()

    client = CalClient()
    response = client.send_request()
    print(response)
    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
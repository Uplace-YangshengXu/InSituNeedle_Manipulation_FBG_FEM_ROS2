from .curvature_member_function import CalClient
import rclpy
from array import array
def main():
    rclpy.init()

    client = CalClient()
    rawdata = array("d",[0,0,0])
    response = client.send_request(rawdata)
    print(response)
    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
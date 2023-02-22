from .curvature_member_function import CalClient
import rclpy
import time

def main():
    start = time.time()
    rclpy.init()
    client = CalClient()
    for i in range(1000):
        response = client.send_request()
        #print(response)
        end = time.time()
        print("get one response")
        print(end - start)
        start = end

    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

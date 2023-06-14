from .curvature_member_function import CalClient
import rclpy
import time

def main():
    start = time.time()
    rclpy.init()
    client = CalClient()
    #for i in range(10):
    while True:
        response = client.send_request(0)
        print(response)
        end = time.time()
        print("get one response")
        print(end - start)
        start = end
        time.sleep(0.5)

    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

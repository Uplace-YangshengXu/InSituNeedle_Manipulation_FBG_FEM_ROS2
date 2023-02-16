from curvature_member_fuction import CalClient

def main():
    rclpy.init()

    client = CalClient()
    response = client.send_request()
 
    client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
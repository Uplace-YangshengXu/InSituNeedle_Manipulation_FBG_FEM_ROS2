from curvature_member_fuction import CalService

def main():
    rclpy.init()

    server = CalService()

    rclpy.spin(server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()
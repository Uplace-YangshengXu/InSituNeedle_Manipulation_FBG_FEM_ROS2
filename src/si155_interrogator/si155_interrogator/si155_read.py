from .hyperion import Hyperion
from socket import gaierror

class Interrogator():
    def __init__(self, address, timeout: float = 1):
        self.address = address
        self.is_connected = False
        connect()


    def connect( self ):
        self.interrogator = Hyperion( self.address )
        try:
            self.interrogar.is_ready
            self.is_connected = True
            self.num_chs = self.interrogator.channel_count
        except OSError:
            self.is_connected = False

  


def main( args=None):
    interrogator = Interrogator("10.0.0.55")
    print(interrogator.interrogator.is_ready)
    print(interrogator.is_connected)
    print(interrogator.num_chs)
    print(interrogator.interrogator.peaks)



if __name__ == "__main__":
    main()




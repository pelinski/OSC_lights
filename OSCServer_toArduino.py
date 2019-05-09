
import argparse
import math
import serial

from pythonosc import dispatcher
from pythonosc import osc_server


def selectProgram_handler(unused_addr, args): 
    x = args[0]
    y = args[1]
    value = args[2]
    s.write("p"+ x + y + value )
    
def speedFader_handler(unused_addr, args):  
    value = args[0]
    s.write("f" + value )                            

def selectBulbs_handler(unused_addr, args):
    x = args[0]
    y = args[1]
    value = args[2]
    s.write("b"+ x + y + value )

def switchManually_handler(unused_addr, args):
    x = args[0]
    y = args[1]
    value = args[2]
    s.write("m"+ x + y + value )


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--ip",
                        default="127.0.0.1", help="The ip to listen on")
    parser.add_argument("--port",
                        type=int, default=5005, help="The port to listen on")
    args = parser.parse_args()

    dispatcher = dispatcher.Dispatcher()
    dispatcher.map("/program/selectMatrix", selectProgram_handler)
    dispatcher.map("/program/speedFader", speedFader_handler )
    dispatcher.map("/selectBulbs/selectMatrix", selectBulbs_handler)
    dispatcher.map("/switchManually/selectMatrix", switchManually_handler)
    s = serial.Serial('/dev/ttyAMA0', 9600) # Namen ggf. anpassen
    s.open()

    server = osc_server.ThreadingOSCUDPServer(
        (args.ip, args.port), dispatcher)
    print("Serving on {}".format(server.server_address))
    server.serve_forever()
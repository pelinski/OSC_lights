import types
import argparse
import math
import serial

from pythonosc import dispatcher
from pythonosc import osc_server


def selectProgram_handler(addr, args):
    addr =  addr[-3:]
    num = 0
    if(addr[0]== '1'):
        num = 5
    num = num + int(addr[2])
    
    print("p;"+ str(num)+ ";" + str(int((args))))
        
    #print("Received selectProgram-message:", args[0], args[1], args[2])
    #s.write("p"+ x + y + value )
    
def speedFader_handler(addr, args):
    print("f;"+ str(int((args))))                          

def selectBulbs_handler(addr, args):
    addr =  addr[-3:]
    num = 0
    if(addr[0]== '1'):
        num = 6
    num = num + int(addr[2])
    
    print("b;"+ str(num)+ ";" + str(int((args))))

def switchManually_handler(addr, args):
    addr =  addr[-3:]
    num = 0
    if(addr[0]== '1'):
        num = 6
    num = num + int(addr[2])
    
    print("m;"+ str(num)+ ";" + str(int((args))))


if __name__ == "__main__":
    #parser = argparse.ArgumentParser()
    #parser.add_argument("--ip",
    #                   default="192.168.222.222", help="The ip to listen on")
    #parser.add_argument("--port",
    #                    type=int, default=8000, help="The port to listen on")
    #args = parser.parse_args()

    dispatcher = dispatcher.Dispatcher()
    dispatcher.map("/program/selectMatrix/*/*", selectProgram_handler)
    dispatcher.map("/selectBulbs/selectMatrix/*/*", selectBulbs_handler)
    dispatcher.map("/switchManually/selectMatrix/*/*", switchManually_handler)
    dispatcher.map("/program/speedFader", speedFader_handler )
    #s = serial.Serial('/dev/ttyAMA0', 9600) # Namen ggf. anpassen
    #s.open()

    server = osc_server.ThreadingOSCUDPServer(
        ('192.168.2.112', 5000), dispatcher)
    print("Serving on {}".format(server.server_address))
    server.serve_forever()

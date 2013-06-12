import socket
import sys

PORT = 45001

def waitForConnection() :
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # force a socket bind even
                                                            #if OS still reservs socket to cleanup stray packets

    s.bind(('127.0.0.1', PORT))
    s.listen(1)
     
    return s.accept()



conn, addr = waitForConnection()

msgHeader = bytearray([0,11])
conn.sendall(msgHeader + "hello$world")

conn.close()

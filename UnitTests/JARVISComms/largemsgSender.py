import socket
import sys

PORT = 45002

def waitForConnection() :
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # force a socket bind even
                                                            #if OS still reservs socket to cleanup stray packets

    s.bind(('127.0.0.1', PORT))
    s.listen(1)
     
    return s.accept()



conn, addr = waitForConnection()

msgHeader = bytearray([125,208])
msg = msgHeader + "hello$" + 'a'*3000 #3006
conn.sendall(msg)

conn.close()


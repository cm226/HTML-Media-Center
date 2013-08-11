import socket
import sys
import MediaRendereVideo

SERVER = 'localhost'
PORT = 45001


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((SERVER,PORT))
data = s.recv(1024)

if data:
    print data
                            
                                                    
s.close()


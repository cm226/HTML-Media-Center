import socket
import sys
import MediaRendereVideo

SERVER = '192.168.0.199'
PORT = 45001


def waitForConnection() :
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # force a socket bind even
                                                            #if OS still reservs socket to cleanup stray packets

    s.bind(('192.168.0.100', PORT))
    s.listen(1)
     
    return s.accept()

    
    
while(1):
	conn, addr = waitForConnection()
	data = conn.recv(1024)

	if data:
		print data
		
					
	conn.close()

sys.exit()

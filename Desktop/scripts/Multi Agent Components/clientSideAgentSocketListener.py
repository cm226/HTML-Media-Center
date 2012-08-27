import socket
import sys
import MediaRendereVideo

SERVER = '192.168.0.199'
PORT = 45001


def waitForConnection() :
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # force a socket bind even
                                                            #if OS still reservs socket to cleanup stray packets

    s.bind(('127.0.0.1', PORT))
    s.listen(1)
     
    return s.accept()

def rendererFactory(command, data, socket):
    return {'PLAY_VID_STREAM':  MediaRendereVideo.render
           }[command](data,socket)
		   
def canRanderFactory(command, data):
    return {'PLAY_VID_STREAM':  MediaRendereVideo.canRender
           }[command](data)
    
    
while(1):
	conn, addr = waitForConnection()
	data = conn.recv(1024)

	if data:
		splitData = data.split(',',1)
		if(canRanderFactory(splitData[0],splitData[1])):
			socketConnection.send("PLAY_STREAM_REPLY,OK")
			rendererFactory(splitData[0],splitData[1],conn)
		else
			socketConnection.send("PLAY_STREAM_REPLY,FAIL")
		
					
	conn.close()

sys.exit()

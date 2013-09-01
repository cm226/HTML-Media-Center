import socket
import sys
import MediaRendereVideo
import MediaRendereAudio

#SERVER = '192.168.0.199'
PORT = 45001
BORADCASTPORT = 40002
AGENT_HELLO_BROADCAST = 7

def getServerIP():
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        
        s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        s.bind(('0.0.0.0', BORADCASTPORT))
        
        msg = s.recv(1025)
        if ord(msg) == AGENT_HELLO_BROADCAST:
                print "reply from server: "+ str(msg)
                return

        print 'Bad send from server' + msg

        return
        

def waitForConnection() :
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # force a socket bind even
                                                            #if OS still reservs socket to cleanup stray packets

    s.bind(('0', PORT))
    s.listen(1)
     
    return s.accept()

def rendererFactory(command, data, socket):
    return {'PLAY_VID_STREAM':  MediaRendereVideo.render,
            'PLAY_MUSIC_STREAM': MediaRendereAudio.render
           }[command](data,socket)
                   
def canRanderFactory(command, data):
    return {'PLAY_VID_STREAM':  MediaRendereVideo.canRender,
            'PLAY_MUSIC_STREAM': MediaRendereAudio.canRender
           }[command](data)
    
   
getServerIP()
print 'server hello ok wateing for connection'
while(1):
        conn, addr = waitForConnection()
        data = conn.recv(1024)

        if data:
                splitData = data.split(',',1)
                if(canRanderFactory(splitData[0],splitData[1])):
                        conn.send("PLAY_STREAM_REPLY,OK")
                        rendererFactory(splitData[0],splitData[1],conn)
                else:
                        conn.send("PLAY_STREAM_REPLY,FAIL")
                
                                        
        conn.close()

sys.exit()

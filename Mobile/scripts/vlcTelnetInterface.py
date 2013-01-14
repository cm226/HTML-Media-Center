import socket
import sys

#command args
#-add <video name> <video url>
#-pause <video name>
#-play <video name>

#remeber and make this script NOT a total frig later craig.....

def openSocket():
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.connect(('localhost',  4212))
	return s

def sendString(s,string):
        s.send(string+"\r\n")
        print s.recv(1024)	
	print s.recv(1024)
        

def authenticate(s):
        print s.recv(1024)
	sendString(s,"mediaPWLOL")


def pauseVideo(name):
        s = openSocket();
        authenticate(s)
	sendString(s,"control "+name+" pause")

	s.close()

def playVideo(name):
        s = openSocket()
        authenticate(s)
        sendString(s,"control "+name+" play")

	s.close()

def stopVideo(name):
        s = openSocket()
        authenticate(s)
        sendString(s,"control "+name+" stop")

	s.close()


def removeAll():
        s = openSocket()
        authenticate(s)
        sendString(s,"del all")

	s.close()

def remove(name):
        s = openSocket()
        authenticate(s)
        sendString(s,"del "+name)

	s.close()

def addVideo(name, url):

	s = openSocket()
	authenticate(s)
	
	
	s.send("new "+name+" broadcast enabled\r\n");
	print s.recv(1024);
	print s.recv(1024);
	
	s.send("setup "+name+" input "+url+"\r\n");
	print s.recv(1024);
	print s.recv(1024);


	s.send("setup "+name+" output #standard{access=http,mux=ts,dst=192.168.1.199:8080/"+name+"}\r\n")
	print s.recv(1024);
	print s.recv(1024);

        s.send("control "+name+" play\r\n")
	print s.recv(1024);
	print s.recv(1024);

	s.close();


if sys.argv[1] == '-add': 
        addVideo(sys.argv[2],sys.argv[3])
elif sys.argv[1] == '-pause':
        pauseVideo(sys.argv[2])
elif sys.argv[1] == '-stop':
        stopVideo(sys.argv[2])
elif sys.argv[1] == '-play':
        playVideo(sys.argv[2])
elif sys.argv[1] == '-remove':
        remove(sys.argv[2])
elif sys.argv[1] == '-removeAll':
        removeAll()

        
	



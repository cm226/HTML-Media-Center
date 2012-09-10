import socket
import sys

#command args
#-add <video name> <video url>

def addVideo(name, url):
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.connect(('localhost',  4212))
	
	print s.recv(1024);
	s.send("mediaPWLOL\r\n");
	print s.recv(1024);	

	print s.recv(1024);
	s.send("new "+name+" broadcast enabled\r\n");
	print s.recv(1024);
	print s.recv(1024);
	
	s.send("setup "+name+" input /home/craig/Desktop/Supernatural.S07E23.HDTV.x264-LOL.mp4\r\n");
	print s.recv(1024);
	print s.recv(1024);


	s.send("setup "+name+" output #standard{access=http,mux=ts,dst=192.168.0.104:8080/"+name+"}\r\n")
	print s.recv(1024);
	print s.recv(1024);

	s.send("control "+name+" play\r\n")
	print s.recv(1024);
	print s.recv(1024);
	
	s.close();


if sys.argv[1] == '-add': 
    addVideo(sys.argv[2],sys.argv[3])
	



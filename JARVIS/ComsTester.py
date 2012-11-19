import socket
import readline
import sys

SERVER = 'localhost'
PORT = 46000


def printhelp():
	print "<Command>: <desc>"
	print "lsPlgin: lists loaded plugins"
	print "c&c_sd: shutdown JARVIS"
	print "rpp: request plugin page"

def openSocket():
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.connect((SERVER, PORT))
	return s

def sendString(s,string):
        s.send(string+"\r\n")
        return s.recv(1024)	

def lsPlgin():
	s = openSocket()
	print sendString(s,"ppoll$")
def ccsd():
	s = openSocket()
	print sendString(s,"c&c$1") #1 is the shutdown
def rpp():
	s = openSocket()
	print sendString(s,"rpp$Email")

def parseCmd(s):
	if s=="help\n":
		printhelp()
	elif s=="lsPlgin\n":
		lsPlgin()
	elif s=="c&c_sd\n":
		ccsd()
	elif s=="rpp\n":
		rpp()

nb = ""
while nb != "kill\n":
	nb = sys.stdin.readline()
	parseCmd(nb)

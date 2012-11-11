import socket
import readline
import sys

SERVER = '127.0.0.1'
PORT = 45001


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
	print sendString(s,"pp$")
def ccsd():
	s = openSocket()
	print sendString(s,"$")
def rpp():
	s = openSocket()
	print sendString(s,"hello
$")

def parseCmd(s):
	if s=="help\n":
		printhelp()
	elif s=="lsPlgin\n":
		lsPlgin()
	elif s=="c&c_sd\n":
		ccsd()
	elif s=="rpp":
		rpp()

nb = ""
while nb != "kill\n":
	nb = sys.stdin.readline()
	parseCmd(nb)

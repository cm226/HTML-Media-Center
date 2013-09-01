import sys
import socket


class InvalidMessageFormatException(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)

BORADCASTPORT = 40002
AGENT_HELLO_BROADCAST = 7

def listenForHandshake():
    s = bindSocket()
    beginCommunications(s)
    return

def bindSocket():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        
    s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('0.0.0.0', BORADCASTPORT))

    return s

def beginCommunications(s):
    msg = s.recv(1024)
    if ord(msg[0]) == AGENT_HELLO_BROADCAST:
        parsedIP = parseIPAddress(msg);
        print "Recieved broadcast from server:" + parsedIP
        sendBoradcastReply(parsedIP)
        return parsedIP

    print 'Bad send from server' + msg


def parseIPAddress(ipBytes):
    parsedServerIP = ""

    if len(ipBytes) != 5:
        raise InvalidMessageFormatException("Message is of incorrect length")

    parsedServerIP = parsedServerIP + str(ord(ipBytes[1])) + "."
    parsedServerIP = parsedServerIP + str(ord(ipBytes[2])) + "."
    parsedServerIP = parsedServerIP + str(ord(ipBytes[3])) + "."
    parsedServerIP = parsedServerIP + str(ord(ipBytes[4]))
    return parsedServerIP
    
def sendBoradcastReply(parsedIP):
    return

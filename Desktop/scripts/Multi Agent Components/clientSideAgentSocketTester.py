import socket

HOST = 'localhost'
PORT = 45001

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.sendall('Hello, world')
s.close()

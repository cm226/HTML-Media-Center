import socket

SERVER = '192.168.0.199'
PORT = 45001

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(('', PORT))
s.listen(1)
conn, addr = s.accept()
while 1:
    data = conn.recv(1024)
    if not data: break
    print data
conn.close()

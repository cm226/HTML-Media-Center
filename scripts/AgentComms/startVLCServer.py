import os

os.system("vlc -vvv /var/www/HTML-Media-Center/test.mp4 --sout '#standard{access=http,mux=ts,dst=192.168.0.199:8080/current}' --fake-tty");

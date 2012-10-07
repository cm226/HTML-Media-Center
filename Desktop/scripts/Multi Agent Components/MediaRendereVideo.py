import os
from subprocess import Popen, PIPE

def canRender(url):
	return true;  # we can do better error checking later

def render(url, socketConnection):
        os.system("omxplayer "+url)
        socketConnection.send("PLAY_STREAM_END,"+url)
        return

    
def pause(mediaName, conn):
        keypress('key p')
        socketConnection.send("PAUSE_STREAM_REPLY,OK")

def stop(mediaName, conn):
        keypress('key q')
        socketConnection.send("STOP_STREAM_REPLY,OK")

def keypress(sequence):
    p = Popen(['xte'], stdin=PIPE)
    p.communicate(input=sequence)
        

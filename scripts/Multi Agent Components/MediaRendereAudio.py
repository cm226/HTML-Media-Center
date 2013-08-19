import os

def canRender(url):
	return True;  # we can do better error checking later

def render(url, socketConnection):
        os.system("vlc "+url)
        socketConnection.send("PLAY_STREAM_END,"+url)
        return

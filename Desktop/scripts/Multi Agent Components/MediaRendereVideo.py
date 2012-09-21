import os

def canRender(url):
	return true;  # we can do better error checking later

def render(url, socketConnection):
        os.system("omxplayer "+url)
        socketConnection.send("PLAY_STREAM_END,"+url)
        return

    

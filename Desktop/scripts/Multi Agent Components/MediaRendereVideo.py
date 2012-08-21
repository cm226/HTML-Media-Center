import os

def render(url, socketConnection):
    socketConnection.send("PLAY_STREAM_REPLY,OK") # we can do better error checking later
    os.system("omxplayer "+url)
    return

    

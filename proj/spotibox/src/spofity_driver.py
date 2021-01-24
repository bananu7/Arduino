import serial
import spotipy
from spotipy.oauth2 import SpotifyOAuth

import os
from datetime import datetime
from time import sleep

os.environ['SPOTIPY_CLIENT_ID']="8be610ea3a3b4c4da47f78f1c2570809"
os.environ['SPOTIPY_CLIENT_SECRET']="57d59080a0424dc29640b562f966bc27"
os.environ['SPOTIPY_REDIRECT_URI']="https://banachewicz.pl"

scope = "user-read-playback-state"
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(scope=scope, username="bananu7"))

ser = serial.Serial('COM10')

def get_current_track():
    curr = sp.current_playback()

    song = curr['item']['name']
    artist = curr['item']['artists'][0]['name']
    print(song)
    print(artist)

    ser.write(b'c\n')
    ser.write(('p00' + song + '\n').encode('utf-8'))
    ser.write(('p10' + artist + '\n').encode('utf-8'))
    ser.flush()

    #results = sp.current_user_saved_tracks()
    #for idx, item in enumerate(results['items']):
    #    track = item['track']
    #    print(idx, track['artists'][0]['name'], " – ", track['name'])

def print_clock():
    now = datetime.now()

    h = now.hour
    h = str(h) if h > 9 else ' '+str(h)
    m = now.minute
    m = str(m) if m > 9 else ' '+str(m)

    ser.write(('p75' + h + ':' + m + '\n').encode('utf-8'))

def main():
    while True:
        get_current_track()
        print_clock()
        sleep(30)

     
if __name__ == "__main__":
    main()
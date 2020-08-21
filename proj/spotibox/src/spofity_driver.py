import serial
import spotipy
from spotipy.oauth2 import SpotifyOAuth

import os
import time
os.environ['SPOTIPY_CLIENT_ID']="8be610ea3a3b4c4da47f78f1c2570809"
os.environ['SPOTIPY_CLIENT_SECRET']="57d59080a0424dc29640b562f966bc27"
os.environ['SPOTIPY_REDIRECT_URI']="https://banachewicz.pl"

scope = "user-read-playback-state"
sp = spotipy.Spotify(auth_manager=SpotifyOAuth(scope=scope, username="bananu7"))

ser = serial.Serial('COM10')

def get_current_track():
    curr = sp.current_playback()
    print(curr)

    song = curr['item']['name']
    artist = curr['item']['artists'][0]['name']

    ser.write(('p00' + song).encode('utf-8'))
    ser.flush()
    time.sleep(1)
    ser.write(('p10' + artist).encode('utf-8'))

    #results = sp.current_user_saved_tracks()
    #for idx, item in enumerate(results['items']):
    #    track = item['track']
    #    print(idx, track['artists'][0]['name'], " – ", track['name'])


def main():

    get_current_track()

     
if __name__ == "__main__":
    main()
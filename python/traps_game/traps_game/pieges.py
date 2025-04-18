import fltk
from page_principale import main_page_principale
from pydub import AudioSegment
from pydub.playback import play
import threading
import time


def play_background_music(file_path):
    """a function who play the music and restart it
    parametres : 
        file_path : the relative to the music document str()
    """
    sound = AudioSegment.from_file(file_path)
    while True:
        play(sound)
        time.sleep(1)

l = 1000
h = 700
music_file_path = "Fairy_tail_song.mp3"

# Create a thread for playing background music
#music_thread = threading.Thread(target=play_background_music, args=(music_file_path,))

#Start the music thread
#music_thread.start()

fltk.cree_fenetre(l, h)
main_page_principale(l, h)
# Wait for the window to be closed before ending the script
"""fltk.attend_fermeture()"""
fltk.ferme_fenetre()

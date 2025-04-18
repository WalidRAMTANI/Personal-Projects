from fltk import *
import time

# Fonction pour détecter si un clic de souris se trouve à l'intérieur du rectangle
def est_dans_rectangle(x, y, ax, ay, bx, by):
    return ax <= x <= bx and ay <= y <= by

# Créez la fenêtre
cree_fenetre(400, 400)

# Dessinez le rectangle
rectangle(10, 10, 100, 50)

# Surveillez les événements
while True:
    event = wait()  # Attendre un événement

    if event == FL_PUSH:  # Si un clic de souris se produit
        x, y = Fl.event_x(), Fl.event_y()  # Obtenez les coordonnées du clic
        if est_dans_rectangle(x, y, 10, 10, 100, 50):
            print("Rectangle cliqué !")  # Faites quelque chose en réponse au clic
    elif event == FL_CLOSE:  # Si la fenêtre est fermée
        break  # Quittez la boucle

ferme_fenetre()
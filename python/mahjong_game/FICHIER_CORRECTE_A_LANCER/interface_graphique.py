# Partie interface graphique

"""
Cette partie de code est dédiée à l'interface graphique
"""

from fltk import *


# Dimension de la taille de l'écran


LARGEUR = 1280
HAUTEUR = 720
MILEU_LARGEUR = LARGEUR // 2
MILEU_HAUTEUR = HAUTEUR // 2


def generer_fenetre(l, h):
    """
    Fonction qui genere une fenêtre avec fond d'écran en utilisant fltk.
    """
    print("Jeu ouvert")
    # generation d'une fenetre
    cree_fenetre(l, h)
    image(l, h, 'fond.png',largeur=l*2,hauteur=h*2, ancrage = 'center', tag='im')
    ligne(0,720//4,1280+720*4,0)
    attend_ev()
    ferme_fenetre()
    
    return print("Jeu fermé")


 
#On appelle la fonction qui genere la fenetre et le fond d'écran
generer_fenetre(LARGEUR,HAUTEUR)
information_jeu(0,0,399,399)


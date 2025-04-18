# Partie interface graphique

"""
Cette partie de code est dédiée à l'interface graphique, par SAO Kingson
"""

from fltk import *
import time

# Dimension de la taille de l'écran


LARGEUR = 1280
HAUTEUR = 720

MILEU_LARGEUR = LARGEUR // 2
MILEU_HAUTEUR = HAUTEUR // 2


def cadre(Larg,Haut):
    """
    Fonction qui permet de faire le cadrant des informations du jeu
    """
    rectangle(-1, 0, Larg*Larg, Haut//8, remplissage="green")
    ligne(0, Haut//8, (Larg*Larg), 0, epaisseur=4)


def compteur(temps):
    """
    Fonction qui fait le compteur 
    """
  
    while temps:
        m, s = divmod(temps, 60)
        minute_seconde_format = '{:02d}:{:02d}'.format(m, s)
        changement = str(minute_seconde_format)
        timer = texte(LARGEUR//2, HAUTEUR//12, changement, couleur="white", ancrage = "center", taille=20)
        mise_a_jour()
        efface(timer)
        time.sleep(1)
        temps -= 1
    return texte(LARGEUR//2, HAUTEUR//12, "Fin du jeu !", couleur="red", ancrage = "center", taille=20)
    
    
        


    
def temps_du_jeu(L,H):
    """
    Indique le temps du jeu
    """
    TEMPS = "Temps du jeu :"
    texte(L//2, H//32, TEMPS, couleur="yellow", ancrage="center", taille=20)
    
    

        
        
    

def evenement_quitter():
    """
    Fonction qui fait le moment ou l'utilisateur quitte le jeu.
    NOTE : Il faut double cliquer pour bien fermer la fenêtre
    """
    
    while True:
        # derniere action de l'utilisateur
        Quitte = donne_ev()

        # Si l'utilisateur quitte le jeu
        if type_ev(Quitte) == 'Quitte':
            break

        # On met à jour le dernier evenement de l'utilisateur
        mise_a_jour()

    # L"utilisateur veut quitter, on ferme donc la fenêtre
    ferme_fenetre()
    
    


def generer_fenetre_jeu(l, h):
    """
    Fonction qui genere une fenêtre avec fond d'écran en utilisant fltk.
    """
    print("Jeu ouvert")
    
    # generation d'une fenetre
    cree_fenetre(l, h)
    
    #fenêtre score
    image(l, h, 'fond.png',largeur=l*2,hauteur=h*2, ancrage = 'center', tag='im')
    cadre(l,h)
    
    #temps du jeu
    temps_du_jeu(l, h)
    compteur(5) #A CHANGER EN MINUTE SI ON VEUT CHANGER LE TEMPS
    
    
    #évenement
    attend_ev()
    evenement_quitter()
    
    return print("Jeu fermé")



 
#On appelle la fonction qui genere la fenetre et le fond d'écran
generer_fenetre_jeu(LARGEUR,HAUTEUR)



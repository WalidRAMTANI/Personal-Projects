# Partie interface graphique

"""
Cette partie de code est dédiée à l'interface graphique, par SAO Kingson
"""

from fltk import *
import time

# Dimension de la taille de l'écran


LARGEUR = 1920
HAUTEUR = 1080


MILIEU_LARGEUR = LARGEUR // 2
MILIEU_HAUTEUR = HAUTEUR // 2



def message_information():
    """
    Fonction qui affiche un message d'avertissement que si
    le joueur decide de quitter en pleine partie ou pas
    """
    rectangle(MILIEU_LARGEUR + MILIEU_LARGEUR//2,
                MILIEU_HAUTEUR + MILIEU_HAUTEUR//2,
                LARGEUR//4, HAUTEUR//4, remplissage="grey",epaisseur=5)

    MESSAGE = "Etes-vous sur d'arreter la partie ?"
    texte(MILIEU_LARGEUR, HAUTEUR//3, MESSAGE,
                couleur="orange", ancrage = "center")

    # Bouton Oui et Non

    OUI = rectangle((MILIEU_LARGEUR//2 + LARGEUR//4),
                HAUTEUR//4 + HAUTEUR//2,
                LARGEUR//4, HAUTEUR//2,remplissage="white",epaisseur=3)

    NON = rectangle((MILIEU_LARGEUR + LARGEUR//4),HAUTEUR//2,
                LARGEUR//2 ,
                ((LARGEUR-HAUTEUR)+(HAUTEUR-(LARGEUR-HAUTEUR)))-(HAUTEUR//4),
                        remplissage="red",epaisseur=3)

def Score():
    """
    Fonction qui indique le score du joueur
    """
    texte(LARGEUR//4, HAUTEUR//16, "Score :",
                couleur="blue", ancrage = "center", taille=30)




def cadre(Larg,Haut):
    """
    Fonction qui permet de faire le cadrant des informations du jeu
    """
    rectangle(-1, 0, Larg*Larg, Haut//8, remplissage="green")
    ligne(0, Haut//8, (Larg*Larg), 0, epaisseur=4)


def compteur(temps):
    """
    Fonction qui fait le compteur ou interrompe la partie
    """


    while temps: # tant que temps vaut True (si le temps ne s'est pas écoulé)

        m, s = divmod(temps, 60)
        minute_seconde_format = '{:02d}:{:02d}'.format(m, s)
        changement = str(minute_seconde_format)

        timer = texte(LARGEUR//2, HAUTEUR//12, changement,
                couleur="white", ancrage = "center", taille=20)

        mise_a_jour() #mise à jour du temps
        efface(timer)

        #au cas ou l'utilisateur quitte en plein milieu de partie

        Quitte = donne_ev()
        if type_ev(Quitte) == 'Quitte':

            message_information()
            attend_ev()
            if type_ev(Quitte) == 'Quitte':
                ferme_fenetre()





        #Sinon le timer découle de son temps
        time.sleep(1)
        temps -= 1

    return texte(LARGEUR//2, HAUTEUR//12, "Fin du jeu !",
                couleur="red", ancrage = "center", taille=20)





def temps_du_jeu(L,H):
    """
    Fonction qui indique "temps du jeu"
    """
    TEMPS = "Temps du jeu :"
    texte(L//2, H//32, TEMPS, couleur="yellow", ancrage="center", taille=20)






def evenement_quitter():
    """
    Fonction qui fait le moment ou l'utilisateur quitte le jeu.
    NOTE : Il faut parfois double cliquer pour bien fermer la fenêtre
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
    Score()
    compteur(60) # <- A CHANGER EN MINUTE SI ON VEUT CHANGER LE TEMPS

    #évenement
    attend_ev()
    evenement_quitter()
    return print("Jeu fermé")




#On appelle la fonction qui genere la fenetre et le fond d'écran
try:
    generer_fenetre_jeu(LARGEUR,HAUTEUR)
except:
    print("jeu interrompu")



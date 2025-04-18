# Partie interface graphique


"""
Cette partie de code est dédiée à l'interface graphique, par SAO Kingson
"""


from fltk import *
import pygame # UNIQUEMENT POUR LA MUSIQUE
import time


# score
score = 0

# Dimension de la taille de l'écran
RESOLUTION = [[1280,720],[1920,1080]]

# Niveau de temps
TEMPS = [600,300,60]


# lecture du fichier audio
AUDIO = "Tomoko_Aran-Midnight_Pretenders_(Instrumental).mp3"
pygame.mixer.init()
pygame.mixer.music.load(AUDIO)


############################## INITIALISATION CMD ##############################

try:
    CHOIX_RESOL = RESOLUTION[int(input(
    "Taper 0 pour la résolution 1280x720"", "
    "Taper 1 pour la résolution 1920x1080 : "
    ))]

    try:
        CHOIX_NIVEAU_TEMPS = TEMPS[int(input(
        "Taper 0 pour le niveau FACILE"", "
        "Taper 1 pour le niveau MOYEN:"", "
        "Taper 2 pour le niveau EXPERT"
        ))]
    except:
        print("-------------------------------------------------------")
        print("Erreur A2 : Valeur ou caractère incorrect")


except:
    print("-------------------------------------------------------")
    print("Erreur A1 : Valeur ou caractère incorrect")

try:
    # obligé d'essayer car la variable CHOIX_RESOL doit fonctionner
    LARGEUR = CHOIX_RESOL[0]
    HAUTEUR = CHOIX_RESOL[1]

    MILIEU_LARGEUR = LARGEUR // 2
    MILIEU_HAUTEUR = HAUTEUR // 2


except:
    print("-------------------------------------------------------")




##################### TOUTES LES FONCTIONS DU PROGRAMME ########################




def message_information(affiche):

    """
    Fonction qui affiche un message d'avertissement que si
    le joueur decide de quitter en pleine partie ou pas
    """

    if affiche:
        # On définit le cadre du message
        affiche = rectangle(MILIEU_LARGEUR + MILIEU_LARGEUR//2,
                    MILIEU_HAUTEUR + MILIEU_HAUTEUR//2,
                    LARGEUR//4, HAUTEUR//4, remplissage="grey",epaisseur=5)

        MESSAGE = "Etes-vous sur d'arreter la partie ?"
        texte(MILIEU_LARGEUR, HAUTEUR//3, MESSAGE,
                    couleur="Red", ancrage = "center")

        # Bouton Oui et Non

        # Oui
        OUI = rectangle((MILIEU_LARGEUR//2 + LARGEUR//4),
                    HAUTEUR//4 + MILIEU_HAUTEUR,
                    LARGEUR//4, MILIEU_HAUTEUR,remplissage="white",epaisseur=3)

        Oui_affiche = texte(((MILIEU_LARGEUR//2)+(LARGEUR-HAUTEUR)+MILIEU_LARGEUR//8)
                    -(HAUTEUR-(HAUTEUR//3)), MILIEU_HAUTEUR + HAUTEUR//8, "Oui",
                    couleur="black", ancrage="center", taille="30")


        # Non
        NON = rectangle((MILIEU_LARGEUR + LARGEUR//4),MILIEU_HAUTEUR,
                    LARGEUR//2 ,
                    ((LARGEUR-HAUTEUR)+(HAUTEUR-(LARGEUR-HAUTEUR)))-(HAUTEUR//4),
                    remplissage="black",epaisseur=3)

        Non_affiche = texte(((MILIEU_LARGEUR)+(LARGEUR-HAUTEUR)+MILIEU_LARGEUR//8)
                    -(HAUTEUR-(HAUTEUR//3)), MILIEU_HAUTEUR + HAUTEUR//8, "Non",
                    couleur="white", ancrage="center", taille="30")

        print("OUI OU NON :",OUI, NON)


    else:
        affiche = None
        MESSAGE = None
        OUI = None
        Oui_affiche = None
        NON = None
        Non_affiche = None
    return affiche, MESSAGE, OUI, Oui_affiche, NON, Non_affiche




def Score(score):
    """
    Fonction qui indique le score du joueur
    """
    texte(LARGEUR//8, HAUTEUR//16, "Score :",
                couleur="blue", ancrage = "center", taille=30)

    score = texte(LARGEUR//4, HAUTEUR//16, score,
                couleur="Brown", ancrage="center",taille=40)




def compteur(temps):
    """
    Fonction qui fait le compteur ou interrompe la partie
    """
    while temps > 0:

        m, s = divmod(temps, 60)
        minute_seconde_format = '{:02d}:{:02d}'.format(m, s)
        changement = str(minute_seconde_format)

        timer = texte(LARGEUR//2, HAUTEUR//12, changement,
                couleur="white", ancrage="center", taille=20)

        mise_a_jour()
        efface(timer)
        evenement_quitter()

        # Sinon, le timer défile de son temps
        pygame.time.delay(1000)
        temps -= 1

    texte(LARGEUR//2, HAUTEUR//12, "Fin du jeu !",
          couleur="red", ancrage="center", taille=20)


"""

if est_dans_rectangle(abscisse(ev), ordonnee(ev), (MILIEU_LARGEUR//2 + LARGEUR//4),
        HAUTEUR//4 + MILIEU_HAUTEUR, LARGEUR//4, MILIEU_HAUTEUR):
            print("OUI !")


"""
def temps_du_jeu(L,H):
    """
    Fonction qui indique "temps du jeu"
    """
    TEMPS = "Temps du jeu :"
    texte(L//2, H//32, TEMPS, couleur="yellow", ancrage="center", taille=20)



def evenement_clique():
    """
    Fonction qui determine les évenements du clique du joueur
    """
    global ev, x, y

    ev = donne_ev()
    tev = type_ev(ev)

    # Action dépendant du type d'événement reçu :

    if tev == 'Touche':
        print('Appui sur la touche', touche(ev))

    elif tev == "ClicDroit":
        print("Clic droit au point", abscisse(ev), ordonnee(ev))


    elif tev == "ClicGauche":
        print("Clic gauche au point", abscisse(ev), ordonnee(ev))

    if tev == "ClicGauche" and est_dans_rectangle_non(abscisse(ev), ordonnee(ev),(MILIEU_LARGEUR//2 + LARGEUR//4),
                    HAUTEUR//4 + MILIEU_HAUTEUR,
                    LARGEUR//4, MILIEU_HAUTEUR):
                        mise_a_jour()
                        message_information(False)

    return ev



def est_dans_rectangle_oui(x, y, ax, ay, bx, by) :
    """
    Fonction pour détecter si un clic de souris se trouve à l'intérieur
    du rectangle oui
    """
    print(ax , x , bx)
    print(ay , y , by)
    return ax >= x >= bx and ay >= y >= by



def est_dans_rectangle_non(x, y, ax, ay, bx, by) :
    """
    Fonction pour détecter si un clic de souris se trouve à l'intérieur
    du rectangle oui
    """
    #print(ax , x , bx)
    #print(ay , y , by)
    return ax <= x >= bx and ay >= y >= by



def evenement_quitter():

    """
    Fonction qui fait le moment ou l'utilisateur quitte le jeu.
    NOTE : Il faut parfois double cliquer pour bien fermer la fenêtre
    """
    # derniere action de l'utilisateur
    Quitte = evenement_clique()
    choix = type_ev(Quitte)
    # Si l'utilisateur quitte le jeu
    if type_ev(Quitte) == 'Quitte':
        # On met à jour le dernier evenement de l'utilisateur
        """if est_dans_rectangle(abscisse(ev), ordonnee(ev), (MILIEU_LARGEUR//2 + LARGEUR//4),
        HAUTEUR//4 + MILIEU_HAUTEUR, LARGEUR//4, MILIEU_HAUTEUR):
            print("OUI !")
        """
        message_information(True)
        print("x, y")
        attend_ev()
    else:
        mise_a_jour()
        message_information(False)
         # L"utilisateur veut quitter, on ferme donc la fenêtre





def generer_fenetre_jeu(l, h):
    """
    Fonction qui genere une fenêtre en utilisant fltk.
    """
    print("Jeu ouvert")

    # generation d'une fenetre
    cree_fenetre(l, h)
    # fenêtre score
    image(l, h, 'mahjong.jpg',largeur=l*2,hauteur=h*2, ancrage = 'center', tag='im')

    # temps du jeu
    temps_du_jeu(l, h)
    # score
    Score(score)
    # musique
    pygame.mixer.music.play()
    #evenement_clique()
    evenement_quitter()
    # timeur
    compteur(CHOIX_NIVEAU_TEMPS)
    # évenement
    attend_ev()
    pygame.mixer.music.stop()
    return print("Jeu fermé")



### On appelle la fonction qui genere la fenetre et le fond d'écran

generer_fenetre_jeu(LARGEUR, HAUTEUR)
"""
except:
    print("fenêtre fermé")
    pygame.mixer.music.stop()
"""


#Credit

print("-------------------------------------------------------")
print('CREDIT : RAMTANI Walid, SAO Kingson, NASIH Anas ')
print("Etudiants L1 Maths-Info de l'Université Gustave Eiffel")



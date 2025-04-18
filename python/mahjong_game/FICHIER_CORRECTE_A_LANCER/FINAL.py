from fltk import *
import random
import math
import time



def message_information(MILIEU_LARGEUR, MILIEU_HAUTEUR, LARGEUR, HAUTEUR):

    """
    Fonction qui affiche un message d'avertissement que si
    le joueur decide de quitter en pleine partie ou pas
    """

    # On définit le cadre du message
    condi = True
    while condi == True:
        rectangle(3 * MILIEU_LARGEUR // 2,
                        MILIEU_HAUTEUR // 2,
                        LARGEUR // 4, MILIEU_HAUTEUR, remplissage="grey",epaisseur=5, tag='roct')

        MESSAGE = "Etes-vous sur d'arreter la partie ?"
        message = texte(MILIEU_LARGEUR, HAUTEUR // 3, MESSAGE,
                        couleur="Red", ancrage = "center", tag='m1')

        # Bouton Oui et Non

        # Oui
        OUI = rectangle((MILIEU_LARGEUR //2 + LARGEUR // 4),
                        HAUTEUR // 4 + MILIEU_HAUTEUR,
                        LARGEUR//4, MILIEU_HAUTEUR,remplissage="white", epaisseur=3, tag='roctoui')

        Oui_affiche = texte(3 * MILIEU_LARGEUR // 2 + 3*(LARGEUR//4 - 3 * MILIEU_LARGEUR // 2)//4
                                , MILIEU_HAUTEUR + HAUTEUR//8, "Oui",
                            couleur="black", ancrage="center", taille=24, tag='1oui')


        # Non
        NON = rectangle((MILIEU_LARGEUR + LARGEUR//4),MILIEU_HAUTEUR,
                        LARGEUR//2 ,
                        ((LARGEUR-HAUTEUR)+(HAUTEUR-(LARGEUR-HAUTEUR)))-(HAUTEUR//4),
                                remplissage="white",epaisseur=3, tag='roctnon')

        Non_affiche = texte(3 * MILIEU_LARGEUR // 2 + (LARGEUR//4 - 3 * MILIEU_LARGEUR // 2)//4
                            , MILIEU_HAUTEUR + HAUTEUR//8, "Non",
                            couleur="black", ancrage="center", taille=24, tag='1non')
        touch = donne_ev()
        typetouch = type_ev(touch)
        if typetouch == 'ClicGauche':
            x = abscisse(touch)
            y = ordonnee(touch)
            if (x <= MILIEU_LARGEUR //2 + LARGEUR//4 and x >= LARGEUR//4
                and y <= HAUTEUR // 4 + MILIEU_HAUTEUR and y >= MILIEU_HAUTEUR):
                print("hohoh")
                ferme_fenetre()
            elif (x >= MILIEU_LARGEUR //2 + LARGEUR//4 and x <= 2 * MILIEU_LARGEUR // 2 + LARGEUR// 4
                  and y <= HAUTEUR // 4 + MILIEU_HAUTEUR and y >= MILIEU_HAUTEUR):
                efface('roctnon')
                efface('roctoui')
                efface('1oui')
                efface('1non')
                efface('m1')
                efface('roct')
                condi = False

        mise_a_jour()


def temps_du_jeu(L , H, marge):
    """
    Fonction qui indique "temps du jeu"
    """
    TEMPS = "Temps du jeu :"
    texte(L//2, marge // 4, TEMPS, couleur="yellow", ancrage="center", taille=24)



def Score(LARGEUR, HAUTEUR, marge):
    """
    Fonction qui indique le score du joueur
    """
    texte(LARGEUR// 2, HAUTEUR - marge // 4, "Score :",
                couleur="blue", ancrage = "center", taille=24)


def matrice(taille, nombre_image):
    """
    Fonction qui retoune une matrice remplie de nombre aléatoirement
    """
    nombre = int(taille[0] * taille[1] / nombre_image) 
    liste = []
    grille_liste = []
    
    for i in range(nombre):
        for j in range(nombre_image):
            liste.append(i)

    for i in range(taille[1]):
        liste_temp = []
        for j in range(taille[0]):
            nombre1 = random.choice(liste)
            indice = liste.index(nombre1)
            liste_temp.append(nombre1)
            liste.remove(nombre1)
        grille_liste.append(liste_temp)

    liste = []

    return grille_liste



def affichage(taille, matrice, taille_case, marge):
    """
    Fonction qui affichage les images en faisant la relation entre
    la matrice principale et le dictionnare d'image
    """
    
    dic_image = {'0' : "image.png", '1' : "naruto.png", '2': "happy.png",
                 '3': "luffy.png", '4': "natsu.png", '5' : "yugi.png",
                 '6' : "drapeau_snk.png", '7' : "clover_trefle.png",
                 '7' : "Chibi.png", '8' : "Chibi1.png", '9' : "fille.png",
                 '10' : "fille1.png", '11' : "ichigofriend.png",
                 '12' : "kakashi.png", '13' : "kirito.png", '14' : "anime_girl.png",
                 '15' : "grim_reaper.png", '16' : "leo.png", '17' : "minecraft.png",
                 '16' : "red_dead.png", '17' : "ronaldo.png", '18' : "tauraus.png", '19' : "witch.png",
                 '17' : "yin_yang.png", '18' : "demon.png", '19' : "magic_hat.png", '20' : "pokemon.png",
                 '21' : "wizard.png", '22' : "cards.png", '23' : "vampire.png"}
    larg = marge / 2 + taille_case / 2
    haut = marge / 2 + taille_case / 2
    liste_positionnement = []
    emplacement_image = []
    
    for i in range(taille[1]):
        larg = marge / 2 + taille_case / 2
        emplacement_image = []
        
        for j in range(taille[0]):
            indice = str(matrice[i][j])
            tag = 'tag' + str(i) + str(j)
            image(larg, haut, dic_image[indice], largeur=taille_case, hauteur=taille_case, tag=tag)
            emplacement_image.append((larg, haut))

            larg += taille_case
        liste_positionnement.append(emplacement_image)
        haut += taille_case

        mise_a_jour()
    return liste_positionnement

def calcule_id(largeur, hauteur, marge, taille_case):
    """
    fonction qui return les cordonnees du click droit dans la matrice
    """
    larg = math.floor((largeur - marge / 2) / taille_case)
    haut = math.floor((hauteur - marge / 2) / taille_case)
    return larg, haut


def effacer_rect(liste):
    """
    une fonction qui efface les rectangle qui entourent les images
    """
    efface('rect' + str(liste[0]) + str(liste[1]))
    efface('rect' + str(liste[2]) + str(liste[3]))



def effacer_image(liste, matrice1):
    """
    fonction qui suppriment deux images à l'aide de la matrice pricipale
    et les cordonnees de les images de la matrice (liste)
    """
    efface('tag'+str(liste[0])+str(liste[1]))
    efface('tag'+str(liste[2])+str(liste[3]))
    matrice1[liste[0]][liste[1]] = -1
    matrice1[liste[2]][liste[3]] = -1



def fonction_click_meme_image(liste):
    """
    une fonction qui determine si on a cliqué sur la meme image
    pour supprimer les rectangles qui entourent l'image
    """

    if liste[0] == liste[2] and liste[1] == liste[3]:
        effacer_rect(liste)
        return True
    else:
        return False



def dessiner_rectangle(x, y, larg, haut, marge, taille_case):
    """
    une fonction pour dessiner un rectangle
    """
    if (x >= larg * taille_case + marge / 2
                and x <= (larg + 1) * taille_case + marge / 2
                and y >= haut * taille_case + marge / 2
                and y <= (haut + 1) * taille_case + marge/2):

            rectangle(larg * taille_case + marge / 2,
                          haut * taille_case + marge/2,
                          (larg+1)*taille_case + marge/2,
                          (haut + 1) * taille_case + marge/2,
                          couleur='black',
                          tag='rect' + str(haut) + str(larg))



def parcourir_une_ligne(liste, j, indice1, indice2, matrice1):
    """"
    une fonction qui parcours une ligne et qui renvoie true si la ligne est vide
    et false si c'est l'inverse
    """

    if indice1 > indice2:
        c = 0
        for f in range(indice2 + 1, indice1):
            if matrice1[j][f] == -1:
                c += 1
        if c == indice1 - indice2 - 1:
            return True
        else:
            return False
    elif indice1 < indice2:
        c = 0
        for f in range(indice1 + 1, indice2):
            if matrice1[j][f] == -1:
                c += 1
        if c == indice2 - indice1 - 1:
            return True
        else:
            return False




def parcourir_une_colone(liste, j, matrice1):
    """
    une fonction qui verifie que toute une colonne est vide
    """

    if liste[0] > liste[2]:
        c = 0
        for f in range(liste[2] + 1, liste[0]):
            if matrice1[f][j] == -1:
                c += 1
        if c == liste[0] - liste[2] - 1:
            return True
        else:
            return False
    elif liste[0] < liste[2]:
        c = 0
        for f in range(liste[0] + 1, liste[2]):
            if matrice1[f][j] == -1:
                c += 1
        if c == liste[2] - liste[0] - 1:
            return True
        else:
            return False




def fonction_liste( matrice1, indice1, indice2):
    """
    cette fonction verifie ci il y'a des cases vides au dessus
    et en dessous de l'image et return la liste des cases
    """

    liste1 = []
    j = indice1 - 1
    while j < indice1 and j > -1:
        if matrice1[j][indice2] == -1:
            liste1.append(j)
            j = j - 1
        else:
            j = -100
    j = indice1 + 1
    while j > indice1 and j < len(matrice1):
        if matrice1[j][indice2] == -1:
            liste1.append(j)
            j = j + 1
        else:
            j = 100

    return liste1


def fonction_liste2(matrice1, indice1, indice2):
    """
    cette fonction verifie ci il y'a des cases vides à droite et à gauche de l'image et return la liste des cases
    """
    j = indice1 - 1
    liste1 = []
    while j < indice1 and j > -1:
        if matrice1[indice2][j] == -1:
            liste1.append(j)
            j = j - 1
        else:
            j = -100

    j = indice1 + 1
    while j > indice1 and j < len(matrice1[0]):
        if matrice1[indice2][j] == -1:
            liste1.append(j)
            j = j + 1
        else:
            j = 100
    return liste1

def effacer_image2(liste_image, liste, matrice1, score):
    """
    une fonction qui caclucle les differents chemin entre les deux images en partant de la gauche jusqu'à la droite
    et suppriment les deux images si y'a un chemin
    """
    condition = False
    liste1 = fonction_liste2(matrice1, liste[1], liste[0])
    liste2 = fonction_liste2(matrice1, liste[3], liste[2])

    liste1.append(liste[1])
    liste2.append(liste[3])

    if (len(matrice1[0]) - 1) in liste1 and (len(matrice1[0]) - 1) in liste2:
        effacer_image(liste, matrice1)

        condition = True
    elif 0 in liste1 and 0 in liste2:
        effacer_image(liste, matrice1)
        condition = True
    else:
        j = 0
        while j < len(liste1):
            n = 0
            while n < len(liste2):
                if liste1[j] == liste2[n]:
                    if parcourir_une_colone(liste, liste1[j], matrice1) == True:
                        effacer_image(liste, matrice1)
                        condition = True
                n = n + 1
            j = j + 1
    if condition == True:
        score = afficher_score(score)
    return condition, score



def effacer_image1(liste_image, liste, matrice1, score):
    """
    une fonction qui caclucle les differents chemin entre les deux images en partant du haut jusqu'àu bas
    et suppriment les deux images si y'a un chemin
    """
    condition = False

    liste1 = fonction_liste(matrice1, liste[0], liste[1])
    liste2 = fonction_liste(matrice1, liste[2], liste[3])
    liste1.append(liste[0])
    liste2.append(liste[2])
    if 0 in liste1 and 0 in liste2:
        effacer_image(liste, matrice1)
        condition = True
    elif (len(matrice1) - 1) in liste1 and (len(matrice1) - 1) in liste2:
        effacer_image(liste, matrice1)
        condition = True
    else:
        j = 0
        while j < len(liste1):
            n = 0
            while n < len(liste2):
                if liste1[j] == liste2[n]:
                    if parcourir_une_ligne(liste, liste1[j], liste[1], liste[3], matrice1) == True:
                        effacer_image(liste, matrice1)
                        condition = True
                n = n + 1
            j = j + 1
    if condition == True:
        score = afficher_score(score)

    return condition, score

def afficher_score(score):
    """
    Fonction qui incrémente le score de +2 si 2 images sont identiques lors du jeu
    """
    return score + 2

def afficher_time(LARGEUR, HAUTEUR):
    """
    Fonction qui indique le temps
    """
    texte(LARGEUR//4, HAUTEUR//16, "Time : ",
                couleur="blue", ancrage = "center", taille=30)

def game_over(score, taille1, taille2, temps, largeur_fenetre, hauteur_fenetre):
        """
        Fonction qui affiche le game over
        Autrement dit, si le temps est écoulé, cette fonction s'active.
        """
        j = 0
        print("oui")
        while j < 200:
            efface_tout()
            image(largeur_fenetre // 2, hauteur_fenetre // 2, "game_over.png",
            largeur=largeur_fenetre, hauteur=hauteur_fenetre)
            if score == taille1 * taille2:
                texte(largeur_fenetre // 2, hauteur_fenetre - hauteur_fenetre / 3, 'YOU WIN ',
                couleur="red", ancrage = "center", taille=30)
            else:
                texte(largeur_fenetre // 2, hauteur_fenetre - hauteur_fenetre / 3, 'YOU LOSE ',
                couleur="red", ancrage = "center", taille=30)
            temps = 0
            j = j + 1
            mise_a_jour()
        efface_tout()
        page_acceuil(largeur_fenetre, hauteur_fenetre)


def page_information(largeur_fenetre, hauteur_fenetre):
    """
    Fonction qui permet d'afficher les pages d'informations
    """
    efface_tout()
    #tant que la page d'information est présent
    while True:
        texte3 = "Le jeu se déroule sur une grille 8×12 remplie de tuiles"
        texte1 =  "Le but du jeu est d'éliminer toutes les tuiles (ou au moins le plus possible)"
        texte2 =  "en couplant des paires de tuiles du même type (donc avec la même image)"
        texte4 = "Les deux tuiles aux extrémités sont du même type. Ces deux tuiles sont à éliminer."
        texte5 = "Il n'y a aucune tuile sur le chemin, sauf aux deux extrémités (les deux tuiles à éliminer)."
        texte6 = "Il y a au plus deux virages sur le chemin, qui sont forcément de 90 degrés"
        texte7 = "Enfin pour selection une image il faut cliquer sur clique gauche."
        texte(50, hauteur_fenetre // 10, texte3, taille=15, couleur='black')
        texte(50, 2 * hauteur_fenetre // 10, texte1 , taille=15, couleur='black')
        texte(50, 3 * hauteur_fenetre // 10, texte2, taille=15, couleur='black')
        texte(50, 4 * hauteur_fenetre // 10, texte4, taille=15, couleur='black')
        texte(50, 5 * hauteur_fenetre // 10,  texte5, taille=15, couleur='black')
        texte(50, 6 * hauteur_fenetre // 10, texte6, taille=15, couleur='black')
        texte(50, 7 * hauteur_fenetre // 10, texte7, taille=15, couleur='black')


        rectangle(50, hauteur_fenetre - 100, 200, hauteur_fenetre - 10 , remplissage='white')
        texte(125, hauteur_fenetre - 100 + 30,
              'retour', taille=24, couleur='black', ancrage = "center")
        clique = donne_ev()
        type_clique = type_ev(clique)
        if type_clique == 'Quitte':
            ferme_fenetre()
        if type_clique == 'ClicGauche':
            x = abscisse(clique)
            y = ordonnee(clique)
            if x >= 50 and x <= 200 and y >= hauteur_fenetre - 100  and y <= hauteur_fenetre - 10:
                efface_tout()
                page_acceuil(largeur_fenetre, hauteur_fenetre)

        mise_a_jour()



def calculer(liste_image, matrice1 ,marge, taille_case, largeur_fenetre, hauteur_fenetre, score, taille1, taille2):
    """
    fonction pour gerer les calcules de la suppression des images
    """
    liste = []
    i = 0
    temps = 4000
    f = True
    while f == True:
        efface('temps12')
        texte(largeur_fenetre - largeur_fenetre // 4, marge // 4, str(temps),
                couleur="yellow", ancrage = "center", taille=24, tag='temps12')
        temps = temps - 1
        temps_du_jeu(largeur_fenetre, hauteur_fenetre, marge)
        Score(largeur_fenetre, hauteur_fenetre, marge)
        efface('score12')
        texte(largeur_fenetre - largeur_fenetre // 4, hauteur_fenetre - marge // 4, str(score),
                couleur="blue", ancrage = "center", taille=30, tag='score12')
        photo = donne_ev()
        type_photo = type_ev(photo)

        if type_photo == 'Quitte':

            message_information(largeur_fenetre / 2, hauteur_fenetre / 2,
                                                largeur_fenetre, hauteur_fenetre)

        if type_photo == 'ClicGauche':
            x = abscisse(photo)
            y = ordonnee(photo)
            larg, haut = calcule_id(x, y, marge, taille_case)
            liste.append(haut)
            liste.append(larg)
            dessiner_rectangle(x, y, larg, haut, marge, taille_case)
            i += 1
        if i >= 2:
            condition = False
            nombre1 = matrice1[liste[0]][liste[1]]
            nombre2 = matrice1[liste[2]][liste[3]]
            if nombre1 == nombre2 and nombre1 != -1:

                if fonction_click_meme_image(liste) == True:
                    print()
                elif (resultat := effacer_image2(liste_image, liste, matrice1, score))[0] == True:
                    score = resultat[1]
                elif (resultat := effacer_image1(liste_image, liste, matrice1, score))[0] == True:
                    score = resultat[1]
            else:
                effacer_rect(liste)
            i = 0
            effacer_rect(liste)
            liste = []
        if score == taille1*taille2 or temps <= -2: #Si le temps == 0 ou Si tout les images sont effacées.

            game_over(score, taille1, taille2, temps, largeur_fenetre, hauteur_fenetre)
            #page_acceuil(largeur_fenetre, hauteur_fenetre)




        mise_a_jour()

def page_acceuil(largeur_fenetre, hauteur_fenetre):
    """
    Fonction qui affiche la page d'accueil
    """
    while True:
        fond = image(largeur_fenetre // 2, hauteur_fenetre // 2, 'mahjong.png',
        largeur=largeur_fenetre, hauteur=hauteur_fenetre, ancrage='center')
        play = rectangle(largeur_fenetre // 3, hauteur_fenetre // 3,
                largeur_fenetre - largeur_fenetre // 3, hauteur_fenetre // 3 + 100, remplissage='white')

        play_text = texte(largeur_fenetre // 3 + (largeur_fenetre - 2 * largeur_fenetre // 3) // 3,
                        hauteur_fenetre // 3 + 30, 'PLAY', taille=24, couleur='black')
        information = rectangle(largeur_fenetre // 3, hauteur_fenetre // 3 + 200,
                largeur_fenetre - largeur_fenetre // 3, hauteur_fenetre // 3 + 300, remplissage='white')

        information_text = texte(largeur_fenetre // 3,
                                    hauteur_fenetre // 3 + 230, 'INFORMATION', taille=24, couleur='black')

        clique = donne_ev()
        typeclique = type_ev(clique)

        if typeclique == 'Quitte':
            ferme_fenetre()

        if typeclique == 'ClicGauche':
            x = abscisse(clique)
            y = ordonnee(clique)

            if (x >= largeur_fenetre // 3 and y >= hauteur_fenetre // 3
            and x <= largeur_fenetre - largeur_fenetre // 3 and y <= hauteur_fenetre // 3 + 100):
                efface(play_text)
                efface(play)
                efface(information)
                efface(information_text)
                efface_tout()
                #efface(fond)
                liste_image = affichage(taille, matrice1, taille_case, marge)
                calculer(liste_image, matrice1, marge, taille_case, largeur_fenetre, hauteur_fenetre, score, taille1, taille2)
                break
            elif (x >= largeur_fenetre // 3 and y >= hauteur_fenetre // 3 + 200
            and x <= largeur_fenetre - largeur_fenetre // 3 and y <= hauteur_fenetre // 3 + 300):
                page_information(largeur_fenetre, hauteur_fenetre)
        if typeclique == 'ClicGauche':
                page_acceuil(largeur_fenetre, hauteur_fenetre)
        mise_a_jour()

# algorithme principale:

"""taille1 = int(input('entrez la largeur : '))
taille2 = int(input('entrez la  hauteur : '))
recurence_image = int(input('entrez le coefficent de repetition de chaque image : '))
taille_case = int(input('entrez la taille de la case : '))
#marge = int(input('entrez la marge : '))
"""
taille1 = 12
taille2 = 8
recurence_image = 4
taille_case = 60
marge = 200
taille = [taille1, taille2]
largeur_fenetre = taille[0] * taille_case + marge
hauteur_fenetre = taille[1] * taille_case + marge

try:
    cree_fenetre(largeur_fenetre, hauteur_fenetre)
    #On génère la fenêtre
    matrice1 = matrice(taille, recurence_image)
    #score
    score = 0
    #page d'accueil
    page_acceuil(largeur_fenetre, hauteur_fenetre)
    ferme_fenetre()
except:
    print("fenêtre fermé")


from grille import *
from fltk import *
from balles import *
from planches import *
from affichage import *
from bouttons import *
from random import randint
import math
import time


def afficher_ball(balle, i):
    """
    fonction pour mise à jour la balle
    """
    efface('cercl' + str(i))
    cercle(balle.x, balle.y, balle.rayon, couleur="red", 
           remplissage='red', tag='cercl' + str(i))


def affiche_planche(planche):
    """
    fonction pour mise à jour la planche
    """
    efface('planche')
    rectangle(planche.x_g, planche.y_g, planche.x_d, planche.y_d, 
              remplissage = 'purple', tag = 'planche')

def calcule_id(largeur, hauteur, marge, taille_case_ver, taille_case_hori):
    # une fonction qui return les cordonnees du click droit dans la matrice
    larg = math.floor((largeur - marge / 2) / taille_case_hori)
    haut = math.floor((hauteur - marge / 2) / taille_case_ver)
    return larg, haut


def affichage(matrice):
    """
        une fonction qui affichage les images en faisant la relation entre
          la matrice principale et le dictionnare d'image
    """
    dic_image = {'0' : "yellow", '1' : "blue", '2' : "green", 
                 '3' : "grey", '4' : "red", '5' : 'orange'}
    indice = 0
    for i in range(len(matrice)):
        indice += 1
        indice = i % 6
        for j in range(len(matrice[i])):
            tag = 'tag' + str(i) + str(j)
            u, v, w, x = matrice[i][j].x_g, matrice[i][j].y_g, matrice[i][j].x_d, matrice[i][j].y_d
            rectangle(u, v, w, x, remplissage=dic_image[f'{indice}'] 
                  , tag=tag)
            matrice[i][j].color = dic_image[f'{indice}']




def dead_ball(balle, planche, vie):
    sup = False
    if balle.y + balle.rayon >= planche.y_d + 25:
        vie -= 1
        sup = True
    if vie <= 0:
        return (vie, False, sup)
    return (vie, True, sup)


def boredure(balle, planche):

    """
    fonction qui gere les rebondissement sur les bordures de la fenetre
    """
    if balle.y - balle.rayon <= 0:
        balle.vy *= -1
    if balle.x - balle.rayon <= 0:
        balle.vx *= -1
        balle.x = balle.rayon
    if  balle.x + balle.rayon >= largeur_fenetre:
        balle.vx *= -1
        balle.x = largeur_fenetre - balle.rayon
    if (balle.y + balle.rayon >= planche.y_g 
        and balle.y + balle.rayon <= planche.y_d):
        if  planche.x_g  <= balle.x <= planche.x_d:
            balle.change_direction() 
    if balle.x < planche.x_g and balle.vx >= 0 and balle.vy >= 0:   
        if (balle.x + balle.rayon >= planche.x_g and 
            balle.y >= planche.y_g and 
            balle.y <= planche.y_d):
            balle.vx *= -1
    if balle.x > planche.x_d and balle.vx <= 0 and balle.vy >= 0:
        if (balle.x - balle.rayon <= planche.x_d and 
            balle.y >= planche.y_g and 
            balle.y <= planche.y_d):
            balle.vx *= -1
    

def bonus(m, x, y, indice):
    if m[y][x].bonus == 1:
        x_1 = randint(0, largeur_fenetre)
        balle = ball(x_1, 2 * hauteur_max_fenetre / 4, r, vx, -vy)
        liste_balle.append(balle)
    elif (m[y][x].bonus == 2 or m[y][x].bonus == 5 or 
          m[y][x].bonus == 3 or m[y][x].bonus == 4):
        rect = planche(m[y][x].x_g, m[y][x].y_g, 
                       m[y][x].x_d, m[y][x].y_d, m[y][x].color)
        liste_balle.append(rect)


def collision(balle, m, planche_j):
    condition = False
    if balle.vy >= 0:
        x, y = calcule_id(balle.x, balle.y + balle.rayon, marge, 
                          taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.y + balle.rayon > m[y][x].y_g:
                    balle.vy *= -1
                    efface('tag' + str(y) + str(x))
                    bonus(m, x, y, 1)
                    m[y][x] = None
                    condition = True
                   
    if balle.vy < 0:
        x, y = calcule_id(balle.x, balle.y - balle.rayon, 
                          marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:

                if balle.y - balle.rayon < m[y][x].y_d:
                    balle.vy *= -1
                    efface('tag' + str(y) + str(x))
                    bonus(m, x, y, 1)
                    m[y][x] = None
                    condition = True
    if balle.vx >= 0:
        x, y = calcule_id(balle.x + balle.rayon, balle.y, 
                          marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.x + balle.rayon > m[y][x].x_g:
                    balle.vx *= -1
                    efface('tag' + str(y) + str(x))
                    bonus(m, x, y, 1)
                    m[y][x] = None
                    condition = True
                    
    if balle.vx < 0:
        x, y = calcule_id(balle.x - balle.rayon, balle.y, 
                          marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.x - balle.rayon < m[y][x].x_d:
                    balle.vx *= -1
                    efface('tag' + str(y) + str(x))
                    bonus(m, x, y, 1)
                    m[y][x] = None
                    condition = True

    return condition

def no_ball(liste):
    ig_1 = 0
    ig_2 = 0
    for elt in liste:
        if isinstance(elt, ball):
            ig_1 +=1
            if elt.x >= 500 and elt.y <= -500:
                ig_2 +=1
    print(ig_1, ig_2)
    if ig_1 == ig_2:
        return True
    return False


def afficher_rect(rect, i):
    """
    fonction pour mise à jour la balle
    """
    efface('rect' + str(i))
    rectangle(rect.x_g, rect.y_g, rect.x_d, rect.y_d, 
              couleur=rect.color, remplissage='white', tag='rect' + str(i))


def pause(largeur, hauteur, minutes_ecoule, secondes_ecoule):
    pause = True
    debut = time.time()
    texte(largeur / 2.5 + 25, (4 * hauteur) / 8 , "PAUSE", 
          couleur="white", taille=30, police='Courier', tag = 'txt')
    b_pause = [bouton((1.5 * largeur / 4), ((2.5 * largeur) / 4), 
                                  ((5 * hauteur) / 8), ((5.5 * hauteur) / 8), 'REPRENDRE'),
               bouton((1.5 * largeur / 4), ((2.5 * largeur) / 4), 
                                  ((6 * hauteur) / 8), ((6.5 * hauteur) / 8), 'QUITTER')]
    
    for i in range(len(b_pause)):
        u, v, w, x = b_pause[i].x_gauche, b_pause[i].y_haut, b_pause[i].x_droit, b_pause[i].y_bas
        rectangle(u, v, w, x, remplissage= 'white'
                , tag='pause')
        texte(largeur / 2.5 + 25, v + 10, f"{b_pause[i].nom}",
              couleur="black", taille=20, police='Courier', tag = 'txt')
        
    while pause:
        ev = donne_ev()
        tev = type_ev(ev)
        if tev == 'Quitte':  # Clic sur le bouton "FIN" ou fermeture de la fenêtre
            pause = False
            efface('txt')
            efface('pause')
            temps_ecoule = time.time() - debut
            minute_ecoule , seconde_ecoule = divmod(int(temps_ecoule), 60)
            minute_ecoule += minutes_ecoule
            seconde_ecoule += secondes_ecoule
            return(minute_ecoule, seconde_ecoule, True)
        
        if tev == "ClicGauche":
            abs = abscisse(ev)
            ord = ordonnee(ev)
            for i in range(len(b_pause)):
                act = None
                act = b_pause[i].clic(abs, ord)
                if act is not None:
                    break
            if act == 'REPRENDRE':
                pause = False
                efface('txt')
                efface('pause')
                temps_ecoule = time.time() - debut
                minute_ecoule , seconde_ecoule = divmod(int(temps_ecoule), 60)
                minute_ecoule += minutes_ecoule
                seconde_ecoule += secondes_ecoule
                return (minute_ecoule, seconde_ecoule, True)
            elif act == 'QUITTER':
                pause = False
                efface('txt')
                efface('pause')
                temps_ecoule = time.time() - debut
                minute_ecoule , seconde_ecoule = divmod(int(temps_ecoule), 60)
                minute_ecoule += minutes_ecoule
                seconde_ecoule += secondes_ecoule
                return (minute_ecoule, seconde_ecoule, False)
        mise_a_jour()

def main(balle):
    vie = 3
    scor = 0
    debut = time.time()
    minutes_ecoule, secondes_ecoule = (0, 0)
    minutes_init = 2
    secondes_init = 59
    planche_j = planche(largeur_fenetre // 4, 
                        ((3 * hauteur_max_fenetre) / 4) + 15,
                        (2 * largeur_fenetre) // 4,
                        ((3 * hauteur_max_fenetre) / 4) + 20, "")
    m = matrice(12, 10, taille_case_hori, marge, taille_case_ve)
    rectangle(0, 0, largeur_fenetre, hauteur_max_fenetre, remplissage = 'black')
    rectangle(0, ((3 * hauteur_max_fenetre) / 4) + 60, largeur_fenetre, 
              hauteur_max_fenetre, remplissage = '#581845')
    affichage(m)
    game = True
    while game:
        a_souris = abscisse_souris()
        ev = donne_ev()
        tev = type_ev(ev)

        if tev == 'Quitte':  # Clic sur le bouton "FIN" ou fermeture de la fenêtre
            game = False
            break

        elif tev == 'Touche':
            tch = touche(ev)
            if tch == 'Escape':
                minutes_ecoule, secondes_ecoule, game = pause(largeur_fenetre, 
                                                        hauteur_max_fenetre, 
                                                        minutes_ecoule, 
                                                        secondes_ecoule)
                if game is False:
                    break

        planche_j.x_g = a_souris - planche_j.taille / 2
        planche_j.x_d = a_souris + planche_j.taille / 2
        i = 0
        while i < len(liste_balle):
            if isinstance(liste_balle[i], ball):

                liste_balle[i].move()
                if collision(liste_balle[i], m, planche_j):
                    scor += 1
                vie, game, sup = dead_ball(liste_balle[i], planche_j, vie)
                if sup:
                    liste_balle[i].sup()
                
                boredure(liste_balle[i], planche_j)
                afficher_ball(liste_balle[i], i) 
            if isinstance(liste_balle[i], planche):
                if liste_balle[i].color == 'red':
                    liste_balle[i].move_haut(20)
                    afficher_rect(liste_balle[i], i)
                elif liste_balle[i].color == 'yellow':
                    liste_balle[i].move_bas(20)
                    afficher_rect(liste_balle[i], i)
                elif liste_balle[i].color == 'blue':
                    liste_balle[i].move_gauche(20)
                    afficher_rect(liste_balle[i], i)
                elif liste_balle[i].color == 'green':
                    liste_balle[i].move_droite(20)
                    afficher_rect(liste_balle[i], i)
                if liste_balle[i].x_d <= 0:
                    liste_balle[i] = None
                elif liste_balle[i].x_g >= largeur_fenetre:
                    liste_balle[i] = None
                elif liste_balle[i].y_d <= 0:
                    liste_balle[i] = None
                elif liste_balle[i].y_g >= hauteur_max_fenetre:
                    liste_balle[i] = None
            if no_ball(liste_balle):
                x_1 = randint(0, largeur_fenetre)
                balle = ball(x_1, 3 * hauteur_max_fenetre / 4, r, vx, vy)
                liste_balle.append(balle)
            i += 1
        affiche_planche(planche_j)
        score(250, 750, scor, 'purple')
        score(700, 750, vie, 'purple', name='VIE')
        temps_ecoule = time.time() - debut
        minutes, secondes = divmod(int(temps_ecoule), 60)
        minutes = minutes_init - minutes + minutes_ecoule
        secondes = secondes_init - secondes + secondes_ecoule
        if minutes == 0 and secondes == 0:
            game = False
            break
        temps(100, 750, minutes, secondes, 'black')
        mise_a_jour()


taille = (12, 10)
taille_case_hori = 60
taille_case_ve = 30
marge = 100
vx = 4
vy = -4
r = 5
liste_balle = []
largeur_fenetre = taille[0] * taille_case_hori + marge
hauteur_fenetre = taille[1] * taille_case_ve + marge
hauteur_max_fenetre = 2 * hauteur_fenetre
x = randint(0, largeur_fenetre)
balle = ball(x, 3 * hauteur_max_fenetre / 4, r, vx, vy)
liste_balle.append(balle)
#balle1 = ball(largeur_fenetre / 2, 2 * hauteur_max_fenetre / 4, r, vx, vy)
cree_fenetre(largeur_fenetre, hauteur_max_fenetre, frequence=60)
main(liste_balle)
ferme_fenetre()

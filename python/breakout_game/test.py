from grille import *
from fltk import *
from balles import *
from planches import *
import math
import time


def afficher_ball():
    """
    fonction pour mise à jour la balle
    """
    efface('cercl')
    cercle(balle.x, balle.y, balle.rayon, couleur="red", remplissage='red', tag='cercl')

def affiche_planche(planche):
    """
    fonction pour mise à jour la planche
    """
    efface('planche')
    rectangle(planche.x_g, planche.y_g, planche.x_d, planche.y_d, remplissage = 'purple', tag = 'planche')

def calcule_id(largeur, hauteur, marge, taille_case_ver, taille_case_hori):
    # une fonction qui return les cordonnees du click droit dans la matrice
    larg = math.floor((largeur - marge / 2) / taille_case_hori)
    haut = math.floor((hauteur - marge / 2) / taille_case_ver)
    return larg, haut


def affichage(matrice, taille_case_hori, marge, taille_case_v):
    """
        une fonction qui affichage les images en faisant la relation entre
          la matrice principale et le dictionnare d'image
    """
    dic_image = {'0' : "yellow", '1' : "blue", '2' : "green", '3' : "grey", '4' : "red", '5' : 'orange'}
    larg = marge / 2
    haut = marge / 2
    print(matrice)
    for i in range(len(matrice)):
        larg = marge / 2
        for j in range(len(matrice[i])):
            indice = str(matrice[i][j])
            tag = 'tag' + str(i) + str(j)
            rectangle(larg, haut, larg + taille_case_hori, haut + taille_case_v, remplissage=dic_image[indice] 
                  , tag=tag)
            larg += taille_case_hori
        haut += taille_case_ve


def boredure(balle):

    """
    fonction qui gere les rebondissement sur les bordures de la fenetre
    """
    if balle.y - balle.rayon <= 0:
        balle.vy *= -1
    elif balle.x - balle.rayon <= 0:
        balle.vx *= -1
        balle.x = balle.rayon
    elif  balle.x + balle.rayon >= largeur_fenetre:
        balle.vx *= -1
        balle.x = largeur_fenetre - balle.rayon


def collision(balle, m):
    """
    une fonction qui calcule les collisions et efface les rectangles touchés.
    """
    if balle.vy > 0 and balle.vx > 0:
        x, y = calcule_id(balle.x, balle.y + balle.rayon, marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0:
            if balle.vy >= 0:
                if balle.vx >= 0:
                    if m[y][x] != 0:
                        if balle.y + balle.rayon >= marge / 2 + y * taille_case_ve:
                            balle.vy *= -1
                            balle.y = marge / 2 + y * taille_case_ve - balle.rayon 

def main(balle, matrice):
    framerate = 60
    m = matrice(12, 10)
    affichage(m, taille_case_hori, marge, taille_case_ve)
    planche_j = planche(largeur_fenetre // 4, 
                        ((3 * hauteur_max_de_la_fenetre) / 4) + 15, 
                        (2 * largeur_fenetre) // 4, 
                        ((3 * hauteur_max_de_la_fenetre) / 4) + 25)
    game = True
    while game:
        ev = donne_ev()
        tev = type_ev(ev)
        if tev == 'ClicGauche':
            a = abscisse(ev)
            planche_j.x_g = a - planche_j.taille // 2
            planche_j.x_d = a + planche_j.taille // 2

        if tev == 'Touche':  # on indique la touche pressée

            nom_touche = touche(ev)
            if nom_touche == 'Right':
                if planche_j.x_d + 10 < taille[0] * taille_case_hori + marge + 10:
                    planche_j.moove(+10)
            
            if nom_touche == 'Left':
                if planche_j.x_g + 10 > 10:
                    planche_j.moove(-10)


        elif tev == 'Quitte':  # Clic sur le bouton "FIN" ou fermeture de la fenêtre
            game = False
            break

        balle.move()
        afficher_ball()
        affiche_planche(planche_j)
        collision(balle, m)
        boredure(balle)
        
            

        # mise à jour en 60 fps
        time.sleep(1 / framerate)
        mise_a_jour()
        




taille = (12, 10)
taille_case_hori = 60
taille_case_ve = 30
marge = 100
largeur_fenetre = taille[0] * taille_case_hori + marge
hauteur_fenetre = taille[1] * taille_case_ve + marge
hauteur_max_de_la_fenetre = 2 * hauteur_fenetre
balle = ball(largeur_fenetre / 2, 3 * hauteur_max_de_la_fenetre / 4, 15, -5, -5)
cree_fenetre(largeur_fenetre, hauteur_max_de_la_fenetre)
main(balle)
ferme_fenetre()
    
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


def affichage(matrice):
    """
        une fonction qui affichage les images en faisant la relation entre
          la matrice principale et le dictionnare d'image
    """
    dic_image = {'0' : "yellow", '1' : "blue", '2' : "green", '3' : "grey", '4' : "red", '5' : 'orange'}
    indice = 0
    for i in range(len(matrice)):
        larg = marge / 2
        indice += 1
        indice = i % 6
        for j in range(len(matrice[i])):
            tag = 'tag' + str(i) + str(j)
            u, v, w, x = matrice[i][j].x_g, matrice[i][j].y_g, matrice[i][j].x_d, matrice[i][j].y_d
            rectangle(u, v, w, x, remplissage=dic_image[f'{indice}'] 
                  , tag=tag)


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

    if balle.y + balle.rayon >= planche.y_g:
        if  planche.x_g  <= balle.x <= planche.x_d:
            balle.change_direction() 

def collision3(balle, m):
    if balle.vy >= 0:
        x, y = calcule_id(balle.x, balle.y + balle.rayon, marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.y + balle.rayon >= m[y][x].y_g:
                    balle.vy *= -1
                    efface('tag' + str(y) + str(x))
                    m[y][x] = None
    else:
        x, y = calcule_id(balle.x, balle.y - balle.rayon, marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                
                if balle.y - balle.rayon <= m[y][x].y_d:
                    balle.vy *= -1
                    efface('tag' + str(y) + str(x))
                    m[y][x] = None
    if balle.x >= 0:
        x, y = calcule_id(balle.x + balle.rayon, balle.y, marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.x + balle.rayon >= m[y][x].x_g:
                    balle.vx *= -1
                    efface('tag' + str(y) + str(x))
                    m[y][x] = None
    else:
        x, y = calcule_id(balle.x - balle.rayon, balle.y, marge, taille_case_ve, taille_case_hori)
        if x >= 0 and y >= 0 and x < taille[0] and y < taille[1]:
            if m[y][x] != None:
                if balle.x - balle.rayon <= m[y][x].x_d:
                    balle.vx *= -1
                    efface('tag' + str(y) + str(x))
                    m[y][x] = None




def main(balle):
    framerate = 60
    m = matrice(12, 10, taille_case_hori, marge, taille_case_ve)
    affichage(m)
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
        collision3(balle, m)
        boredure(balle, planche_j)
        
            

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
balle = ball(largeur_fenetre / 2, 3 * hauteur_max_de_la_fenetre / 4, 10, -5, -3)
cree_fenetre(largeur_fenetre, hauteur_max_de_la_fenetre)
main(balle)
ferme_fenetre()
    
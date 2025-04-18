from fltk import *
import math
import time
class ball:
    def __init__(self, x, y, r, vx, vy):
        self.x = x
        self.y = y
        self.rayon = r 
        self.vx = vx
        self.vy = vy

    def move(self):
        self.x += self.vx
        self.y += self.vy

    def change_direction(self):
        self.vy *= -1



def afficher_ball():
    """
    fonction pour mise à jour la balle
    """
    cercle(balle.x, balle.y, balle.rayon, couleur="red", remplissage='red', tag='cercl')

def calcule_id(largeur, hauteur, marge, taille_case_ver, taille_case_hori):
    # une fonction qui return les cordonnees du click droit dans la matrice
    larg = math.floor((largeur - marge / 2) / taille_case_hori)
    haut = math.floor((hauteur - marge / 2) / taille_case_ver)
    return larg, haut


def matrice(longeur, hauteur):
    """
    Renvoie une matrice pleine.
    """
    m = [[1 for _ in range(hauteur)] for j in range(longeur)]  # matrcie pleine
    return m






def affichage(taille, matrice, taille_case_hori, marge, taille_case_v):
    """
        une fonction qui affichage les images en faisant la relation entre
          la matrice principale et le dictionnare d'image
    """
    dic_image = {'0' : "yellow", '1' : "blue", '2' : "green", '3' : "grey", '4' : "red"}
    larg = marge / 2
    haut = marge / 2
    liste_positionnement = []
    emplacement_image = []
    h = 0
    for i in range(taille[1]):
        larg = marge / 2
        if h > 4:
            h = 0
        for j in range(taille[0]):
            indice = str(h)
            tag = 'tag' + str(i) + str(j)
            rectangle(larg, haut, larg + taille_case_hori, haut + taille_case_v, remplissage=dic_image[indice] 
                  , tag=tag)
            

            larg += taille_case_hori
        haut += taille_case_ve
        h += 1

def boredure(balle):

    """
    fonction qui gere les rebondissement sur les bordures de la fenetre
    """
    if balle.y - balle.rayon <= 0:
        ball.y = balle.rayon
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
        if x >= 0 and y >= 0 and x <= taille[0] - 1 and y <= taille[1] - 1:
                if m[y][x] != 0:
                    if balle.y + balle.rayon >= marge / 2 + y * taille_case_ve:
                        balle.change_direction()
                        balle.y = marge / 2 + y * taille_case_ve - balle.rayon
                        efface('tag' + str(y) + str(x))


def main(balle):
    m = matrice(12, 10)
    while True:
        efface('cercl')
        balle.move()
        afficher_ball()
        collision(balle, m)
        affichage(taille, m, taille_case_hori, marge, taille_case_ve)
        boredure(balle)
        mise_a_jour()
        time.sleep(1 / 60)




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
    
from fltk import *
from grille import *

def tube(x, y, name_tage, inside = 'white'):
    """
    fonction recenvant en paramètre de coordonnées, et affiche
    un tube à ces coordonnées.
    """
    cercle(x, y, 15, couleur = inside , remplissage = inside, tag = name_tage)
    cercle(x+70,y,15,couleur= inside , remplissage = inside, tag = name_tage)
    rectangle(x, y - 15, x + 70, y + 15, couleur = inside, remplissage = inside, tag = name_tage)


def score(x, y, score, color, name = 'SCORE', inside = 'white'):
    """pour afficher le score"""
    efface(f'{name}')
    efface(name)
    tube(x, y, f'{name}', inside)
    chaine=name
    police='Courier'
    taille=20
    texte(x + 35, y - 35, chaine, police = police, 
          taille = taille, couleur = inside, ancrage = 'center', tag = f'{name}')
    chaine=score
    texte(x + 35, y ,chaine, police = police, 
          taille = taille, couleur = color, ancrage = 'center', tag = f'{name}')
    

def temps(x, y, minutes, secondes, color, inside = 'white'):
    """pour afficher le temps"""
    efface('tt')
    efface('temps')
    efface('dure')
    tube(x, y, 'tt', inside)
    chaine = 'TEMPS'
    police = 'Courier'
    taille = 15
    texte(x + 35, y - 35, chaine, police = police,
          taille = taille, couleur = inside, ancrage = 'center', tag = 'temps')
    texte(x + 35, y, f'{minutes} : {secondes}', police = police,
          taille = taille, couleur = color, ancrage = 'center', tag = 'dure')
    

def quadrillage(x, y, taille_case):
    """
    fonction permettant d'afficher un quadrillage pour mieux 
    visualiser les cases du plateau de jeu
    """
    for i in range(1,x):
        ligne(i * taille_case, 0, i * taille_case, y * taille_case, couleur = 'blue')
        ligne(0, i * taille_case, x * taille_case, i * taille_case, couleur = 'blue')


def affichage(liste_image, taille_case_1, taille_case_2):
    for lig in range(len(liste_image)):
        for col in range(len(liste_image[lig])):
            x = (col * taille_case_1) + (0.5 * taille_case_1) + (2 * taille_case_1)  # Calcul des coordonnées x en fonction de la taille de la case
            y = (lig * taille_case_2) + (0.5 * taille_case_2) + (3 * taille_case_2)  # Calcul des coordonnées y en fonction de la taille de la case
            rectangle(x, y, x + (col * taille_case_1), y + (lig * taille_case_2), remplissage='yellow')


def main():


    framerate = 60
    taille_case_l = 60  # multiplicateur de la taille des cases
    taille_case_h = 30
    largeur_plateau = 16  # en nombre de cases
    hauteur_plateau = 25  # en nombre de cases
    cree_fenetre(taille_case_l * largeur_plateau, taille_case_h * hauteur_plateau)
    m = matrice(10,12)
    affichage(m, taille_case_l, taille_case_h)
    attend_ev()  # bloque l'exécution jusqu'à un clic ou une touche
    ferme_fenetre()
from brique import *
import random
def matrice(longeur, hauteur, taille_case_hori, marge, taille_case_v):
    """
    Renvoie une matrice pleine d'objet de brique
    """
    larg = marge / 2
    haut = marge / 2
    liste_bonus = []
    m = []
    i = 0
    color = ""
    for _ in range(hauteur):
        ligne = []
        larg = marge / 2
        for _ in range(longeur):
            """
            faut utiliser random pour ajouter des bonus
            """
            bonus = random.randint(1, 20)
            b = brique(larg, haut, larg + taille_case_hori, haut + taille_case_v, bonus, color)
            ligne.append(b)
            larg += taille_case_hori
        m.append(ligne)
        haut += taille_case_v
    return m


taille_case_hori = 60
taille_case_ve = 30
marge = 100
m = matrice(12, 10, taille_case_hori, marge, taille_case_ve)
print(m)
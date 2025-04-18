import fltk
from random import choice
from calcul import click_opposer

def creation_tirette(NB_CASE:int):
    """
    compteur_tirette: le nombre de fois ou la tirette a été tiré a gauche par ligne
    fonction qui créer la matrix des tirette
    >>> def foo(NB_CASE):
    ...     x = False
    ...     tirette_h, tirette_v = creation_tirette(NB_CASE)
    ...     for a in tirette_h:
    ...         for i in range(2, len(a)):
    ...             if not a[i]:
    ...                 for j in range(1, 2):
    ...                     if a[i - j]:
    ...                         x = True
    ...     y = False
    ...     for ligne in range(NB_CASE):
    ...         for colonne in range(NB_CASE + 2):
    ...             if not tirette_v[colonne][ligne]:
    ...                 for j in range(1, 2):
    ...                     if tirette_v[colonne - j][ligne]:
    ...                         y = True
    ...     return (x, y)
    ...
    >>> foo(7)
    (True, True)
    >>> foo(10)
    (True, True)
    >>> foo(50)
    (True, True)
    """
    tirette_h, tirette_v = [], []
    nb_pousse = 2
    for _ in range(NB_CASE):
        ligne_h = choice([[True, False, False],
                        [False, True, False],
                        [False, False, True]])
        ligne_v = choice([[True, False, False],
                        [False, True, False],
                        [False, False, True]])
        for a in range(3, NB_CASE + nb_pousse):
            choix_h = choice([True, False])
            choix_v = choice([True, False])
            if not choix_h:
                trouver = False
                for j in range(1, nb_pousse + 1):
                    if ligne_h[a - j]:
                        ligne_h.append(choix_h)
                        trouver = True
                        break
                if not trouver:
                    ligne_h.append(True)
            else:
                ligne_h.append(choix_h)
            if not choix_v:
                x = False
                for j in range(1, nb_pousse + 1):
                    if ligne_v[a - j]:
                        ligne_v.append(choix_v)
                        x = True
                        break
                if not x:
                    ligne_v.append(True)
            else:
                ligne_v.append(choix_v)
        tirette_h.append(ligne_h)
        tirette_v.append(ligne_v)
    return tirette_h, tirette_v

def modif_tirette_name(quadrillage: list, boxDimensions: tuple, margin: tuple):
    """
    compteur_tirette: le nombre de fois ou la tirette a été tiré a gauche par ligne
    tirette_h, tirette_v, quadrillage: liste de liste de bool
    margin: espace entre d'eux case
    boxDimensions: dimension d'une case largeur et hauteur
    fonction qui touve la tirrette a modifier en fonction
    de la position du click
    click a gauche du quadrillage décale la ligne de la tirrete horizontale
    click a droite du quadrillage décale la ligne de la tirrete horizontale
    click en haut du quadrillage décale la ligne de la tirrete verticale
    click en bas du quadrillage décale la ligne de la tirrete verticale
    """
    #coordonné du rectangle(case du jeu)
    x_min = quadrillage[0][0][0][0] - boxDimensions[0] // 2 + margin[0]
    x_max = quadrillage[-1][-1][0][0] + boxDimensions[0] // 2 - margin[0]
    y_min = quadrillage[0][0][0][1] - boxDimensions[1] // 2 + margin[1]
    y_max = quadrillage[-1][-1][0][1] + boxDimensions[1] // 2 - margin[1]
    x = fltk.abscisse_souris()
    y = fltk.ordonnee_souris()
    horizontale = None
    if x < x_min and y_min <= y <= y_max:#click a gauche
        horizontale = True
    if x > x_max and y_min <= y <= y_max:#click a droite
        horizontale = True
    if y < y_min and x_min <= x <= x_max:#click en haut
        horizontale = False
    if y > y_max and x_min <= x <= x_max:#click en bas
        horizontale = False
    return horizontale

def decale_tirette(tirette_h_def: tuple, tirette_v_def:tuple, quadrillage: list,
                    boxDimensions: tuple, margin:tuple, horizontale: bool,
                    compteur_tirette:list, tirette_h:list, tirette_v:list,
                    save_click:list):
    """
    compteur_tirette: le nombre de fois ou la tirette a été tiré a gauche par ligne
    tirette_, quadrillage, tirette_h, tirette_v,: liste de liste
    margin: espace entre d'eux case
    boxDimensions: dimension d'une case largeur et hauteur
    decale la ligne ou la collone dans la tirette 
    si "horizontale" == True alors c'est la tirette horizontale
    sinon c'est la tirette verticale
    >>> def foo2():
    ...     quadrillage = [[[(148.0, 98.0), '0'], [(204.0, 98.0), '0'], [(260.0, 98.0), '0'], [(316.0, 98.0), '0'], [(372.0, 98.0), '0'], [(428.0, 98.0), '0'], [(484.0, 98.0), '0'], [(540.0, 98.0), '0'], [(596.0, 98.0), 'purple'], [(652.0, 98.0), 'green']], [[(148.0, 154.0), '0'], [(204.0, 154.0), '0'], [(260.0, 154.0), '0'], [(316.0, 154.0), '0'], [(372.0, 154.0), '0'], [(428.0, 154.0), '0'], [(484.0, 154.0), '0'], [(540.0, 154.0), '0'], [(596.0, 154.0), 'blue'], [(652.0, 154.0), 'red']], [[(148.0, 210.0), '0'], [(204.0, 210.0), '0'], [(260.0, 210.0), '0'], [(316.0, 210.0), '0'], [(372.0, 210.0), '0'], [(428.0, 210.0), '0'], [(484.0, 210.0), '0'], [(540.0, 210.0), '0'], [(596.0, 210.0), '0'], [(652.0, 210.0), '0']], [[(148.0, 266.0), '0'], [(204.0, 266.0), '0'], [(260.0, 266.0), '0'], [(316.0, 266.0), '0'], [(372.0, 266.0), '0'], [(428.0, 266.0), '0'], [(484.0, 266.0), '0'], [(540.0, 266.0), '0'], [(596.0, 266.0), '0'], [(652.0, 266.0), '0']], [[(148.0, 322.0), '0'], [(204.0, 322.0), '0'], [(260.0, 322.0), '0'], [(316.0, 322.0), '0'], [(372.0, 322.0), '0'], [(428.0, 322.0), '0'], [(484.0, 322.0), '0'], [(540.0, 322.0), '0'], [(596.0, 322.0), '0'], [(652.0, 322.0), '0']], [[(148.0, 378.0), '0'], [(204.0, 378.0), '0'], [(260.0, 378.0), '0'], [(316.0, 378.0), '0'], [(372.0, 378.0), '0'], [(428.0, 378.0), '0'], [(484.0, 378.0), '0'], [(540.0, 378.0), '0'], [(596.0, 378.0), '0'], [(652.0, 378.0), '0']], [[(148.0, 434.0), '0'], [(204.0, 434.0), '0'], [(260.0, 434.0), '0'], [(316.0, 434.0), '0'], [(372.0, 434.0), '0'], [(428.0, 434.0), '0'], [(484.0, 434.0), '0'], [(540.0, 434.0), '0'], [(596.0, 434.0), '0'], [(652.0, 434.0), '0']], [[(148.0, 490.0), '0'], [(204.0, 490.0), '0'], [(260.0, 490.0), '0'], [(316.0, 490.0), '0'], [(372.0, 490.0), '0'], [(428.0, 490.0), '0'], [(484.0, 490.0), '0'], [(540.0, 490.0), '0'], [(596.0, 490.0), '0'], [(652.0, 490.0), '0']], [[(148.0, 546.0), '0'], [(204.0, 546.0), '0'], [(260.0, 546.0), '0'], [(316.0, 546.0), '0'], [(372.0, 546.0), '0'], [(428.0, 546.0), '0'], [(484.0, 546.0), '0'], [(540.0, 546.0), '0'], [(596.0, 546.0), '0'], [(652.0, 546.0), '0']], [[(148.0, 602.0), '0'], [(204.0, 602.0), '0'], [(260.0, 602.0), '0'], [(316.0, 602.0), '0'], [(372.0, 602.0), '0'], [(428.0, 602.0), '0'], [(484.0, 602.0), '0'], [(540.0, 602.0), '0'], [(596.0, 602.0), '0'], [(652.0, 602.0), '0']]]
    ...     boxDimensions = (56.0, 56.0)
    ...     margin = (3.5, 3.5)
    ...     tirette_h_def = [[False, True, False, False, True, True, False, False, True, False, False, True], [False, True, False, False, True, True, False, False, True, True, True, False], [True, False, False, True, False, False, True, True, True, True, True, False], [False, True, False, False, True, False, False, True, False, True, True, True], [False, True, False, False, True, True, True, False, True, True, True, False], [False, True, False, False, True, True, False, False, True, True, True, False], [True, False, False, True, False, False, True, False, False, True, False, False], [False, True, False, True, False, False, True, False, False, True, True, False], [False, True, False, False, True, True, False, True, False, False, True, True], [True, False, False, True, True, True, True, True, True, False, False, True]]
    ...     tirette_v_def = [[False, True, False, False, True, True, False, False, True, True], [True, False, True, False, False, False, True, False, False, False], [False, False, False, True, False, False, False, True, False, False], [True, True, True, True, True, True, True, False, True, True], [True, True, False, True, True, True, False, True, True, False], [False, True, False, True, False, False, False, False, False, False], [True, False, True, True, False, True, True, False, False, True], [True, False, True, False, True, False, True, True, True, True], [False, True, True, False, True, True, False, False, True, True], [True, True, False, True, False, False, True, True, False, True], [False, True, False, False, True, False, True, True, True, True], [True, True, True, True, True, True, False, True, False, True]]
    ...     compteur_tirette = [{'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}, {'h': 1, 'v': 1}]
    ...     tirette_h = [[True, False, False, True, True, False, False, True, False, False], [True, False, False, True, True, False, False, True, True, True], [False, False, True, False, False, True, True, True, True, True], [True, False, False, True, False, False, True, False, True, True], [True, False, False, True, True, True, False, True, True, True], [True, False, False, True, True, False, False, True, True, True], [False, False, True, False, False, True, False, False, True, False], [True, False, True, False, False, True, False, False, True, True], [True, False, False, True, True, False, True, False, False, True], [False, False, True, True, True, True, True, True, False, False]]
    ...     tirette_v = [[True, False, True, False, False, False, True, False, False, False], [False, False, False, True, False, False, False, True, Falsse, False], [True, True, True, True, True, True, True, False, True, True], [True, True, False, True, True, True, False, True, True, False], [False, True, False, True, False, False, False, False, False, False], [True, False, True, True, False, True, True, False, False, True], [True, False, True, False, True, False, True, True, True, True], [False, True, True, False, True, True, False, False, True, True], [True, True, False, True, False, False, True, True, False, True], [False, True, False, False, True, False, True, True, True, True]]
    ...     save_click = [10, -1]
    ...     fltk.cree_fenetre()
    ...     cherche_tirrete(tirette_h_def, tirette_v_def_copy, quadrillage, boxDimensions,\
    ...     margin, horizontale, compteur_tirette, tirette_h, tirette_v, save_click)
    """ 
    x = fltk.abscisse_souris()
    y = fltk.ordonnee_souris()
    nb_max_decallage = 2 #coorespond aux nombre max de fois ou on peut tirer la tirette
    for i in range(len(quadrillage)):
        if horizontale: #si la tirette horizontale
            indice1 = i
            indice2 = 0
        else:#si la tirette verticale
            indice1 = 0
            indice2 = i
        x_min = quadrillage[indice1][indice2][0][0] -\
                (boxDimensions[0] // 2 + margin[0])
        y_min = quadrillage[indice1][indice2][0][1] -\
                (boxDimensions[1] // 2 + margin[1])
        x_max = quadrillage[indice1][indice2][0][0] +\
                (boxDimensions[0] // 2 - margin[0] )
        y_max = quadrillage[indice1][indice2][0][1] +\
                (boxDimensions[1] // 2 - margin[1])
        
        if x < x_min and y_min <= y <= y_max and horizontale:#click a gauche
            if compteur_tirette[i]["h"] < nb_max_decallage and not click_opposer(save_click, ["gauche", i]):
                compteur_tirette[i]["h"] += 1
                tirette_h[i] = tirette_h_def[i][compteur_tirette[i]["h"]: len(tirette_h_def) + compteur_tirette[i]["h"]]
                return True, tirette_v, tirette_h
        
        elif x > x_max and y_min <= y <= y_max and horizontale:
            if compteur_tirette[i]["h"] > 0 and not click_opposer(save_click, ["droite", i]):
                compteur_tirette[i]["h"] -= 1
                tirette_h[i] = tirette_h_def[i][compteur_tirette[i]["h"]: len(tirette_h_def) + compteur_tirette[i]["h"]]
                return True, tirette_v, tirette_h
        
        elif y < y_min and x_min <= x <= x_max and not horizontale: #click en haut
            if compteur_tirette[i]["v"] < nb_max_decallage and not click_opposer(save_click, ["haut", i]):
                compteur_tirette[i]["v"] += 1
                tirette_v[i] = tirette_v_def[i][compteur_tirette[i]["v"]: len(tirette_h_def) + compteur_tirette[i]["v"]]
                return True, tirette_v, tirette_h
        
        elif y > y_max and x_min <= x <= x_max and not horizontale: #click en bas
            if compteur_tirette[i]["v"] > 0 and not click_opposer(save_click, ["bas", i]):
                compteur_tirette[i]["v"] -= 1
                tirette_v[i] = tirette_v_def[i][compteur_tirette[i]["v"]: len(tirette_h_def) + compteur_tirette[i]["v"]]
                return True, tirette_v, tirette_h
    return False, tirette_v, tirette_h
 
if __name__ == "__main__":
    import doctest
    doctest.testmod()

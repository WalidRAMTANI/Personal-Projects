import fltk
from time import sleep

def afficher_nombre_tire_possible(quadrillage, liste_nb_tirettes, 
                                  nb_case, nb_possible, taille_case):
    """
    une fonction qui affiche le nombre de fois qu'on peut tirer de chaque coté
    parametres: 
      quadrillage : une liste qui contient les cordonnees de chaque case list
      liste_nb_tirettes : la liste qui indique le nombre de tire possible (list)
      nb_case ! le nombre de case dans chaque ligne int
      nb_possible : le nombre de tire possible max (int)
      taille_case : les dimensions d'une case
    """
    texte = '1'
    taille = fltk.taille_texte(texte)

    for i in range(nb_case):

        # afficher le nombre de tire restant pour la tirettes verticale de bas
        """x = quadrillage[nb_case - 1][i][0][0]
        y = quadrillage[nb_case - 1][i][0][1]
        for j in range(liste_nb_tirettes[i]["v"]):
            fltk.rectangle(x - taille_case[0]/2, y + taille_case[1] / 2 + taille_case[1],
                           x + taille_case[0]/2, y + taille_case[1]/2, remplissage="red")
            y += taille_case[1]
        fltk.rectangle(x + taille_case[0]/ 8 , y + taille_case[1]/ 2, 
                       x - taille_case[0]/8, y + taille_case[1]/ 2 + taille_case[1], remplissage="red") 
        """
        fltk.texte(quadrillage[nb_case - 1][i][0][0] - taille[0] / 2, 
                   quadrillage[nb_case - 1][i][0][1] + taille_case[1], 
                   liste_nb_tirettes[i]["v"], couleur='black')
        


        # afficher le nombre de tire restant pour la tirettes verticale de haut
        """x = quadrillage[0][i][0][0]
        y = quadrillage[0][i][0][1]
        for j in range(nb_possible - liste_nb_tirettes[i]["v"]):
            fltk.rectangle(x - taille_case[0]/2, y - taille_case[1] / 2 - taille_case[1],
                           x + taille_case[0]/2, y - taille_case[1]/2, remplissage="red")
            y -= taille_case[1]
        fltk.rectangle(x + taille_case[0]/ 8 , y - taille_case[1]/ 2, 
                       x - taille_case[0]/8, y - taille_case[1]/ 2 - taille_case[1], remplissage="red") 
        """
        fltk.texte(quadrillage[0][i][0][0] - taille[0] / 2, 
                   quadrillage[0][i][0][1] - taille_case[1], 
                   nb_possible - liste_nb_tirettes[i]["v"], couleur='black')
        
        
        # afficher le nombre de tire restant pour la tirettes horizentale de droite
        """x = quadrillage[i][nb_case - 1][0][0]
        y = quadrillage[i][0][0][1]
        for j in range(nb_possible - liste_nb_tirettes[i]["h"]):
            fltk.rectangle(x + taille_case[0] + taille_case[0]/2, y - taille_case[1] / 2,
                           x + taille_case[0]/2, y + taille_case[1]/2, remplissage="red")
            x += taille_case[0]
        fltk.rectangle(x + taille_case[0]/ 2 + taille_case[0]/2, y - taille_case[1]/ 8, 
                       x + taille_case[0]/2, y + taille_case[1]/ 8, remplissage="red") 

        """
        fltk.texte(quadrillage[i][nb_case - 1][0][0] + taille_case[0], 
                   quadrillage[i][0][0][1] - taille[1] / 2, 
                   liste_nb_tirettes[i]["h"], couleur='black')
        fltk.texte(quadrillage[i][0][0][0] - taille_case[0], 
                   quadrillage[i][0][0][1] - taille[1] / 2, 
                   nb_possible - liste_nb_tirettes[i]["h"], couleur='black')
        
        
        
        # afficher les cases la tirettes horizontale qui sont  de gauche
        """x = quadrillage[i][0][0][0]
        y = quadrillage[i][0][0][1]
        for j in range(liste_nb_tirettes[i]["h"]):
            fltk.rectangle(x - taille_case[0] - taille_case[0]/2, y - taille_case[1] / 2,
                           x - taille_case[0]/2, y + taille_case[1]/2, remplissage="red")
            x -= taille_case[0]
        fltk.rectangle(x - taille_case[0]/ 2 - taille_case[0]/2, y - taille_case[1]/ 8, 
                       x - taille_case[0]/2, y + taille_case[1]/ 8, remplissage="red") 
        """
        fltk.texte(quadrillage[i][nb_case - 1][0][0] + taille_case[0], 
                   quadrillage[i][0][0][1] - taille[1] / 2, 
                   liste_nb_tirettes[i]["h"], couleur='black')

def afficher_trou(tirette_h, tirette_v, quadrillage, longeur, margin, NB_CASE:int):
    """
    une fonction qui en entrée la tirette et affiche les trous qui sont dans la tirette
    parametres:
        tirette : list de list
        quadrillage : list de list
        longeur : int
        couleur : str
        retour, bool
    
    return :
        il affiche les trous grace à fltk
    """
    h = fltk.hauteur_fenetre()
    l = fltk.largeur_fenetre()
    fltk.image(l / 2, h / 2, "res/bg.gif", 
                    largeur=int(l * 1.77), hauteur=h, ancrage='center')
    tirette_v_copy = [[0 for _ in range(NB_CASE)] for _ in range(NB_CASE + 2)]
    for ligne in range(NB_CASE):
        for colonne in range(NB_CASE):
            tirette_v_copy[colonne][ligne] = tirette_v[ligne][colonne]
    for i in range(len(tirette_h)): # parcourir la matrice
        for j in range(len(tirette_h[i])):
            case = quadrillage[i][j]
            if tirette_h[i][j] == False:#verifie si il n'y a pas de trou
                couleur = 'blue'
                fltk.rectangle(case[0][0] - longeur[0] // 2 + margin[0], 
                            case[0][1] - longeur[1] // 4 + margin[1], 
                            case[0][0] + longeur[0] // 2 - margin[0], 
                            case[0][1] + longeur[1] // 4 - margin[1],
                            couleur, tag = "plateau",
                            remplissage=couleur)
                
            if tirette_v_copy[i][j] == False:#verifie si il n'y a pas de trou
                couleur = 'orange'
                fltk.rectangle(case[0][0] - longeur[0] // 4 + margin[0], 
                            case[0][1] - longeur[1] // 2 + margin[1], 
                            case[0][0] + longeur[0] // 4 - margin[0], 
                            case[0][1] + longeur[1] // 2 - margin[1],
                            couleur, tag = "plateau",
                            remplissage=couleur)
            if case[1] != "0": #veifie si une balle est present
                couleur = case[1]
                fltk.cercle(case[0][0], case[0][1],
                            longeur[0] // 2 - 10, couleur, epaisseur=10)
                
            fltk.rectangle(case[0][0] - longeur[0] // 2 + margin[0], 
                            case[0][1] - longeur[1] // 2 + margin[1], 
                            case[0][0] + longeur[0] // 2 - margin[0], 
                            case[0][1] + longeur[1] // 2 - margin[1],
                            couleur='black', tag = "plateau")

def choix_balle(nb_balle: int, quadrillage: list, boxDimensions: tuple,
                margin: tuple, couleur: str, tirette_h: list, tirette_v: list):
    """
    tirette_h, tirette_v, quadrillage: liste de liste
    couleur: coorespond a la couleur du cercle/ le joueur
    margin: espace entre d'eux case
    boxDimensions: dimension d'une case largeur et hauteur
    nb_balle: nombre de balle que une personne sur le plateau
    fonction que tu lance au début du jeu pour choisir les case
    ou seront les balle 
    """
    if detection_case(quadrillage, boxDimensions, margin,
                      couleur, tirette_h, tirette_v):#si on a détecté une balle 
        return nb_balle - 1 
    return nb_balle       

def detection_case(quadrillage: list, boxDimensions: tuple,
                   margin: tuple, couleur: str, tirette_h: list, tirette_v: list):
    """
    tirette_h, tirette_v, quadrillage: liste de liste
    margin: espace entre d'eux case
    boxDimensions: dimension d'une case largeur et hauteur
    detecte si le clic a été effectué sur une case en parcourant le quadrillage
    coord: coordonné du clic gauche
    mettre une balle la ou la personne a clicker
    ">>>detection_case([[[0, 0, "0"], [0, 0, "0"], [0, 0, "0"]]], (10, 10), (0, 0), "bleu",\
    [[[True, False, False], [False, False, False], [False, False, False]]],\
    [[[True, False, False], [False, False, False], [False, False, False]]])"

    """
    coord = (fltk.abscisse_souris(), fltk.ordonnee_souris()) #coordonné de la souris
    x_souris = coord[0]
    y_souris = coord[1]
    NB_CASE = len(tirette_h)
    tirette_v_copy = [[0 for _ in range(NB_CASE)] for _ in range(NB_CASE + 2)]
    for ligne in range(NB_CASE):
        for colonne in range(NB_CASE):
            tirette_v_copy[colonne][ligne] = tirette_v[ligne][colonne]
    for i in range(len(quadrillage)):
        for a in range(len(quadrillage[i])):
            case = quadrillage[i][a]
            #coordonné du rectangle(case du jeu)
            x_min = case[0][0] - boxDimensions[0] // 2 + margin[0]
            x_max = case[0][0] + boxDimensions[0] // 2 - margin[0]
            y_min = case[0][1] - boxDimensions[1] // 2 + margin[1]
            y_max = case[0][1] + boxDimensions[1] // 2 - margin[1]
            #verifie si la souris est dans le rectange et que celui si na pas de balle
            if  x_min <= x_souris <= x_max and y_min <= y_souris <= y_max and\
                (not tirette_h[i][a] or not tirette_v_copy[i][a]) and case[1] == "0":
                quadrillage[i][a][1] = couleur
                fltk.cercle(case[0][0], case[0][1],boxDimensions[0] // 2 - 10,
                            couleur, epaisseur=10)
                return True

def aff_joueur(tour: int, joueur: dict, debut_partie: bool, nb_balle_playeur_max:int, joueur_name):
    """
    nb_balle_playeur: nombre de balle au debut du jeu par joueur
    debut_partie: qui nous previens si on est dans
                  la phase de placement des balle
    tour: nombre representant le joueur precedent a avoir jouer
    joueur: association du jour et de son nombre de balle
    fonction qui affiche les joueur sur les coins de l'écran
    et met l'affichage du joueur en couleur et les autres 
    """
    joueur_name = ["David", "Walid", "Abdel", "Kader", "Rekia", "Stephany"]
    x = max([fltk.taille_texte(i)[0] for i in joueur_name]) / 2
    taille = 24 #police d'ecriture
    espace_balle_perdue = 20
    list_coord = [(x, taille),
                  (fltk.largeur_fenetre() - x, taille),
                  (x, fltk.hauteur_fenetre() - taille - espace_balle_perdue ),
                  (fltk.largeur_fenetre() - x , 
                   fltk.hauteur_fenetre() - taille- espace_balle_perdue),
                  (x, (fltk.hauteur_fenetre() / 2) - taille - espace_balle_perdue)]
    list_coord.append((fltk.largeur_fenetre() - x , list_coord[4][1]))
    tour = cherche_tour(tour, joueur) #joueur actuel qui doit jouer
    for index, elemt in enumerate(joueur):
        chaine = joueur_name[index]
        coord  = list_coord[index]
        couleur = elemt
        nb_balle_tomber(coord, elemt, nb_balle_playeur_max, joueur, chaine)
        if tour == index: #verifie si c'est le tour du joueur
            aff_tour(elemt, chaine, x)#affiche le rectange en haut
        else:
            if debut_partie:
                couleur = "grey"
        fltk.texte(coord[0], coord[1], chaine, couleur, "center", taille=taille)
    return tour

def nb_balle_tomber(coord: tuple, couleur: str, nb_balle_playeur_max: int, joueur:dict,
                    chaine: str):
    """
    joueur: dict avec comme cle les couleur de chaque joueur associer a leur nombre de balle
    nb_balle_playeur_max: nombre de balle que les joueur on au début du jeu
    chaine: chaine de texte afficher
    couleur: couleur qui coorespond au joueur
    coord: les coordonné du texte qui represente le joueur
    affiche grace a fltk en dessous du pseudo du joueur les balles qu'il a fait tomber
    """
    nb_balle_joueur = joueur[couleur]
    nb_balle_restant = nb_balle_playeur_max - nb_balle_joueur
    diametre_cercle = 10
    y = coord[1] + (fltk.taille_texte(chaine)[1] // 2) + (diametre_cercle / 2)
    x = coord[0] - (fltk.taille_texte(chaine)[0] // 2) + (diametre_cercle / 2)
    for _ in range(nb_balle_restant):
        fltk.cercle(x, y, diametre_cercle / 2, couleur, epaisseur=2)
        x += diametre_cercle + 2
        if x > coord[0] + (fltk.taille_texte(chaine)[0] // 2) - diametre_cercle / 2:
            x = coord[0] - (fltk.taille_texte(chaine)[0] // 2) + 2
            y += diametre_cercle + 1

def aff_tour(couleur: str, nom, taille_x):
    """
    taille_x : taille du texte en largeur diviser par deux
    tour: tour du joueur actuelle
    affiche un rectangle en haut au millieu de la fenetre
    avec le joueur 
    """
    x = fltk.largeur_fenetre() // 2
    taille = fltk.taille_texte(nom)
    y = taille[1] #taille du texte en hauteur
    fltk.rectangle(x - taille_x, 0, x + taille_x + 2, y, remplissage=couleur)
    fltk.texte(x, y // 2, nom, "black", "center")

def cherche_tour(tour: int , joueur: dict):
    """
    tour: nombre representant le joueur precedent a avoir jouer
    joueur: association du jour et de son nombre de balle
    determine le tour du prohai  joueur
    >>> cherche_tour(2,{"green":0, "red":0, "blue":0, "yellow":1})
    3
    >>> cherche_tour(2,{"green":0, "red":1, "blue":0, "yellow":0})
    1
    """
    #verifie qu'il reste au moins une balle
    assert ([0] * len(joueur)) != list(joueur.values())
    #prend le joueur suivant
    if tour == len(joueur) - 1:#si on est a la fin de la liste
        tour = 0 
    else:#si on est pas a la fin de la liste
        tour += 1
    couleur = list(joueur.keys())[tour] #prend la couleur du joueur actuel
    if joueur[couleur] == 0: #verifie si il a pas une balle en jeu
        tour = cherche_tour(tour, joueur)#on recherche avec le joueur suivant
    return  tour

def verif_nombre_place(nb_balle_totale, tirette_h, tirette_v, nb_playeur):
    """
    fonction qui vas verifier si le nombre de balle que les joueurs
    doivent place est possible sur le plateau genere
    """
    nb_case = len(tirette_h)
    nb_balle_dispo = 0
    for i in range(nb_case):
        for j in range(nb_case):
            if (not tirette_h[i][j]) or (not tirette_v[i][j]):
                nb_balle_dispo += 1
                if nb_balle_dispo >= nb_balle_totale:
                    return nb_balle_totale // nb_playeur
                
    if nb_balle_dispo < nb_balle_totale:
        h = fltk.hauteur_fenetre()
        l = fltk.largeur_fenetre()
        fltk.image(l / 2, h / 2, "res/bg.gif", 
                largeur=int(l * 1.77), hauteur=h, ancrage='center')
        chaine = f"Le nombre de balle par \njoueur a été réduit a {nb_balle_dispo // nb_playeur} "
        fltk.texte(l / 2, h / 2, chaine, "red", police=24, ancrage="center")
        fltk.mise_a_jour()
        sleep(3)
    return nb_balle_dispo // nb_playeur

if __name__ == "__main__":
    import doctest
    doctest.testmod()

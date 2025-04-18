def creation_quadrillage(tile_hori, tile_verti, boxSize, coordinateNW):
    """
    This fonction will take the dimension of the board and
    will add all the parameters necessary for creating
    the box
    
    Args: The dimensions(tile_hori, tile_verti)
    
    Return:The coordinates of each square center as a module 
    
    Exemple with a 3x2 grid and a margin of 5  
    """
    x = coordinateNW[0] + boxSize[0]/2
    y = coordinateNW[1] + boxSize[1]/2 
    board_lst = []
    for i in range(tile_verti):
        board_line = []
        x = coordinateNW[0] + boxSize[0]/2
        for p in range(tile_hori):
             board_line.append([(x, y), "0"])#le deuxieme 0 est le tag
             x += boxSize[0]     
        board_lst.append(board_line)
        y += boxSize[1]
    return board_lst

def supp_balle(quadrillage: list, tirette_h: list,
               tirette_v: list, joueur: dict):
    """
    quadrillage, tirette_h, tirette_v: liste de liste
    fonction qui vas supprimer les balle qui sont dans des trous
    et le joueur qu'il n'a plus de balle
    >>> supp_balle([[[(0, 0), "green"], [(0, 50), "0"], [(0, 100), "0"]]],\
    [[[True, False, False], [False, False, False], [False, False, False]]],\
    [[[True, False, False], [False, False, False], [False, False, False]]],\
    {"green":0, "red":0, "blue":0, 'yellow':1})
    ([[[(0, 0), '0'], [(0, 50), '0'], [(0, 100), '0']]], {'green': 0, 'red': 0, 'blue': 0, 'yellow': 0})
    """
    for i in joueur:
        joueur[i] = 0
    NB_CASE = len(tirette_h)
    tirette_v_copy = [[0 for _ in range(NB_CASE)] for _ in range(NB_CASE + 2)]
    for ligne in range(NB_CASE):
        for colonne in range(NB_CASE):
            tirette_v_copy[colonne][ligne] = tirette_v[ligne][colonne]
    for i in range(len(quadrillage)):
        for a in range(len(quadrillage[i])): 
            if quadrillage[i][a][1] != "0" and\
                tirette_h[i][a] and tirette_v_copy[i][a]:
                quadrillage[i][a][1] = "0" #valeur par defaut d'une case
            elif quadrillage[i][a][1] != "0":
                couleur = quadrillage[i][a][1]
                joueur[couleur] += 1
    return quadrillage, joueur
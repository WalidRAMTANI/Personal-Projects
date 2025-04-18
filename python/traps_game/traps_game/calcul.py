def size_box(LARGEUR_windows, HAUTEUR_windows, nbBox):
    """
    This function will automatically calculate the size of
    the box depending of the windows size.
    It will also give the margin between box.
    
    Args: width / height of the windows / number of box
    
    Return: box size, margin, new center box-size
    >>> size_box(1000, 1000, 7)
    ((114.28571428571429, 114.28571428571429), (5.0, 5.0), (100.0, 100.0))
    """
    margin_center, largeur, hauteur = center_box(LARGEUR_windows, HAUTEUR_windows)    
    center_width = largeur * 0.9
    center_height = hauteur * 0.9
    margin = (largeur * 0.005, hauteur * 0.005)
    coordinateNW, coordinateSE = (largeur - center_width, hauteur - center_height), (center_width, center_height)   
    new_dimension = (coordinateSE[0] - coordinateNW[0], coordinateSE[1] - coordinateNW[1])
    box_size = ((new_dimension[0]) / nbBox), ((new_dimension[1]) / nbBox)
    coordinateNW = (coordinateNW[0] + margin_center[0], coordinateNW[1] + margin_center[1])
    return box_size, margin, coordinateNW

def center_box(LARGEUR, HAUTEUR):
    """
    This function is usefull when the width and height of
    the windows is different.
    It will add the marge necessary to center the box 
    
    Args: LARGEUR, HAUTEUR
    
    Return: Margin, and LARGEUR, HAUTEUR
    
    >>> center_box(800, 1000)
    ((0, 100.0), 800, 800)
    """
    margin_width, margin_height = 0, 0
    if LARGEUR > HAUTEUR:
        margin_width = (LARGEUR - HAUTEUR)/2
        LARGEUR = HAUTEUR
    elif HAUTEUR > LARGEUR:
        margin_height = (HAUTEUR - LARGEUR)/2 
        HAUTEUR = LARGEUR
    return (margin_width, margin_height), LARGEUR, HAUTEUR
       
def click_opposer(save_click:list, prochain_click:list):
    """
    fonction qui verifier si le joueur n'a pas click sur le coté opposer
    et renvoi True si c'est le cas sinon False
    >>> click_opposer([1, 2], ["gauche", 2])
    False
    >>> click_opposer([1, 2], ["droite", 3])
    False
    >>> click_opposer([1, 2], ["droite", 1])
    False
    >>> click_opposer([1, 2], ["droite", 2])
    True
    """
    if prochain_click[0] == "gauche":
        click, prochain_click[0] = 1, 1
    elif prochain_click[0] == "droite":
        click, prochain_click[0] = -1, -1
    elif prochain_click[0] == "haut":
        click, prochain_click[0] = 2, 2
    elif prochain_click[0] == "bas":
        click, prochain_click[0] = -2, -2
    else:
        click = save_click[0]
    if click == -save_click[0] and prochain_click[1] == save_click[1]:
        return True
    for a in range(len(save_click)):
        save_click[a] = prochain_click[a]
    return False

if __name__ == "__main__":
    import doctest
    doctest.testmod()
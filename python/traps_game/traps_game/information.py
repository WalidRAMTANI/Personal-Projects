import fltk
from page_settings import detection_save

def detection_save(x, y, p, c, b, l, h, color, coordoonees_save):
    """
    a function change the color of the save button when the mouse is in there
    parametres : 
    x : abscisse of the mouse  float
    y : ordonnee of the mouse  float
    p : Number of player int
    c : number of boxes int 
    l : width of the window
    h : height of the window
    margin : margin of the window
    >>> detection_save(150, 750, 2, 4, 6, 800, 800, "red", [(100, 700), (600, 800)])
    'yellow'
    """
    if color == 'red':
        # check if ou mouse is at the button save then change his color
        if (coordoonees_save[0][0]<= x and x <= coordoonees_save[1][0] and 
                coordoonees_save[0][1] <= y and y <= coordoonees_save[1][1]):
            fltk.efface_tout()
            color, dim = information(
                    l, h, 'yellow')
    else:
        """ check if our mouse had been at the button previously 
                so then we don't change his color
        """
        if (coordoonees_save[0][0] <= x and x <= coordoonees_save[1][0] and 
                coordoonees_save[0][1] <= y and y <= coordoonees_save[1][1]):
            pass
        else:
            # if not then reset his color
            fltk.efface_tout()
            color, dim = information(
                    l, h, 'red')
    return color        



def information(l, h, color):
    """
    a function who display information and rules of the game
    parametres :
    l: width of the window
    h : height of the window
    color : str
    return :
        color : str
        return_button_dimension : list liste of the dimension of the return button
    >>> information(800, 800, "red)
    'red', [(4.0, 635.2941176470588), (204.0, 800)]
    """
    list_text = ["The objective of this project is to implement a multi-player strategy game called",           
        "Traps! (Stay alive! in English), developed by Milton Bradley in 19711.",
        "Figure 1: An example part", "1 Rules of the game", 
        "The game consists of a 7×7 grid, with 14 zippers, 7 horizontal (orange)", 
        "and 7 vertical (white). Each zipper has a fixed number of holes, and can", 
        "be placed in three positions, by pushing or pulling on its ends. HAS", 
        "each point of the grid, when two holes are superimposed (that of the zipper", 
        "vertical and that of the horizontal pull), the ball located above falls, and the", 
        "player loses his ball. The game is played with 2, 3 or 4 players, each having 5", 
        "1Stay Alive, official website for the game. See also the 1994 French ad.", 
        "1 balls of your chosen color. The objective of the game is to be the last player to have", 
        "at least one ball on the board."]
    fltk.image(l / 2, h / 2, "res/bg.gif", 
                largeur=int(l * 1.77), hauteur=h, ancrage='center')
    x = l * 0.005
    h_case= h / (len(list_text) + 4)
    y = h_case / 2
    text = "return"
    return_button_dimension = []
    for i in range(len(list_text)):
        fltk.texte(x, y, list_text[i], taille=15)
        y += h_case
    # display button return
    fltk.rectangle(x, y, x + l * 0.25, 
                   h, couleur='black', remplissage=color)
    return_button_dimension.append((x, y))
    return_button_dimension.append((x + l * 0.25, h))
    
    taille = fltk.taille_texte(text)
    fltk.texte((x + l * 0.25 - taille[0]) / 2, (h + y - taille[1]) / 2 - taille[1], text)
    fltk.mise_a_jour()
    return color, return_button_dimension




def main_information(l, h, p, c, b):
    """
    a function who display the information page
    parametres:
      l: width of the window float
      h: height of the window float
      p : number of player int
      c: number of boxes int 
      b : number of billes int
    """
    color = "red"
    color, dimension_button = information(l, h, color)
    page_info = True
    while page_info:
        click = fltk.donne_ev()
        type_clic = fltk.type_ev(click)
        if type_clic == 'Quitte':
            fltk.ferme_fenetre()
        if type_clic == 'ClicGauche':
            x = fltk.abscisse(click)
            y = fltk.ordonnee(click)
            if (dimension_button[0][0] <= x <= dimension_button[1][0] and 
                        dimension_button[0][1] <= y <= dimension_button[1][1]):
                fltk.efface_tout()
                page_info = False
            # checking if we are clicking in the rectangles of the page_settings
        x_souris = fltk.abscisse_souris()
        y_souris = fltk.ordonnee_souris()
        # we check if our mouse is in the save button to hcnage his color
        color = detection_save(x_souris, y_souris, p, 
                               c, b, l, h, color, dimension_button)

        fltk.mise_a_jour()

    from page_principale import main_page_principale
    main_page_principale(l, h, p, c, b)


import fltk
from page_settings import main_settings
from main import play
from information import main_information

def page_(l, h, margin, j = 10):
    """
    fonction qui genere la page_principale du jeu
    parametres : 
        l : float width of the window
        h : float height of the window
        margin : tuple margin above and left
    return :
        dimension_rectangle : list contains dimension of rectangles
        l_case : float width of a rectangle
        h_case : float height of rectangle
    """
    marg = 20 # marge bettween rectangle
    l_case = l - 2 * margin[0]  # width of recatangle
    h_case = (h - 2 * margin[1] - 2 * marg) / 3 # height of rectangle
    play = "play"
    information = 'information'
    settings = 'settings'
    y_min = h + margin[1]
    dimension_rectangle = []
    x_min = margin[0]
    for i in range(3):
        if i == 0:
            chaine = play
        elif i == 1:
            chaine = information
        else:
            chaine = settings
        if i == j:
            cool = '#dabd2c'
        else:
            cool = '#125cc0'
        fltk.rectangle(x_min, y_min, x_min + l_case, y_min + h_case, 
                       remplissage=cool, tag='acceuil')
        dimension_rectangle.append((x_min, y_min))
        taille = fltk.taille_texte(chaine, taille=30)
        x = (2 * x_min + l_case - taille[0]) / 2
        y = (2 * y_min + h_case - taille[1]) / 2
        fltk.texte(x, y, chaine, couleur='black', tag='acceuil')
        y_min += h_case + marg

    return dimension_rectangle, l_case, h_case

    
def detection_rect(lst, x, y, l_case, h_case, h, l,  margin, j):
    """
    a function to detect if the mouse is in the rectangles , she takes in entry the list of dimension of the rectangles , 
    mouse_abscisse, mouse_ordonnée and width and height of a rectangle and j who is a hint to see if we update the page or not
    parametres : 
        lst : list
        x, y, l_case, h_case : float
        j : int
    
    return : 
        j : int
    """
    for i in range(len(lst)):
        if lst[i][0] <= x <= lst[i][0] + l_case and lst[i][1] <= y <= lst[i][1] + h_case: 
            if i != j:
                fltk.efface('acceuil')
                j = i
                page_(l, h, margin, i)
                return j
            elif i == j:
                return j   
    
    fltk.efface('acceuil')
    page_(l, h, margin)
    return 10


def main_page_principale(l, h, p = 2, c = 7, b = 7):
    game_name = 'S T A Y  A L I V E'
    fltk.image(l / 2, h / 2, "res/bg.gif", 
                    largeur=int(l * 1.77), hauteur=h, ancrage='center')
    taille = fltk.taille_texte(game_name, taille=40)
    xu = (l - taille[0]) / 2
    yu = (h - taille[1]) / 3
    fltk.texte(xu, yu, game_name, couleur="#3498db", taille=40)
    for cpt in range(4):
        if cpt == 0:
            cool = '#450521' 
        elif cpt == 1:
            cool = '#280c46' 
        elif cpt == 2:
            cool = '#810143' 
        else:
            cool = '#540687'

        fltk.rectangle(xu - 100 + 2 * cpt, yu - 50 + 2 * cpt, 
                       xu + taille[0] + 100 - 2 * cpt, yu + taille[1] / 2 + 50 - 2 * cpt, 
                       couleur= cool, epaisseur=2)
    margin = (200, 100)
    lst, l_case, h_case = page_(l, h / 2, margin)
    j = 10
    setting, game, information = False, False, False
    while not setting and not game and not information :
        clic = fltk.donne_ev()
        type_clic = fltk.type_ev(clic)
        if type_clic == 'Quitte':
            fltk.ferme_fenetre()
        elif type_clic == 'ClicGauche':
            x_souris = fltk.abscisse(clic)
            y_souris = fltk.ordonnee(clic)
            if (lst[2][0] <= x_souris <= lst[2][0] + l_case and 
                lst[2][1] <= y_souris <= lst[2][1] + h_case):
                fltk.efface_tout()
                setting = True

            elif (lst[0][0] <= x_souris <= lst[0][0] + l_case and 
                lst[0][1] <= y_souris <= lst[0][1] + h_case):
                fltk.efface_tout()
                game = True

            elif (lst[1][0] <= x_souris <= lst[1][0] + l_case and 
                lst[1][1] <= y_souris <= lst[1][1] + h_case):
                fltk.efface_tout()
                information = True

        x = fltk.abscisse_souris()
        y = fltk.ordonnee_souris()
        j = detection_rect(lst, x, y, l_case, h_case, h / 2, l, margin, j)
        fltk.mise_a_jour()

    if setting:
        main_settings(l, h, p, c, b)
    elif game:
        play(l, h, p, c, b)
    else:
        #la page ne se lance pas
        main_information(l, h, p, c, b)
                
main_page_principale(800, 700)

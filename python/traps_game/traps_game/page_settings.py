import fltk 

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
            p, c, b, liste_bouton, h_case, \
                coordoonees_save, l_case, color = page_settings(
                    l, h, 'yellow', p, c, b)
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
            p, c, b, liste_bouton, h_case, \
            coordoonees_save, l_case, color = page_settings(
                l, h, 'red', p, c, b)
    return color        

def page_settings(l, h, color, p = 2, c = 7, b = 7):
    """
    a function who create a new page where we display settings
    parametres : 
        l : int(width)
        h : int(height)
        color = str(color of the save button)
        p : int(number_player)
        c : int(number_case)
        b : int(number_bille)
    >>> page_settings(800, 800, "red", 2, 7, 7) 
    2, 7, 7, [[24.0, 616.0, 16.0], [24.0, 616.0, 192.0], [24.0, 616.0, 368.0]], 160, \
        [(200.0, 544.0), (600.0, 704.0)], 400, "red"
    """
    fltk.image(l / 2, h / 2, "res/bg.gif", 
                largeur=int(l * 1.77), hauteur=h, ancrage='center')
    marg = h * 0.02 # marge bettween rectangle
    l_case = l * 0.5  # width of recatangle
    h_case = h * 0.2  # height of rectangle
    x = l_case
    y = marg
    iterate_button_dimension = h_case # width of the small rectangle
    liste_button_iterate = [] #liste of the small buttons
    cordonnees_save = [] # list who contains the cordinnates of the save button
    cool = 'blue'
    if p < 2:
        number_player = 2
    elif p > 6:
        number_player = 6
    else:
        number_player = p
    if c < 7:
        number_case = 7
    else:
        number_case = c
    if b < 1:
        number_bille = 1
    else:
        number_bille = b
    liste_button = [('Number of player : ', number_player), 
                    ('Number of cases : ', number_case), 
                    ('Number of billes : ', number_bille), ("save", "")]
    # display number of player, cases and billes
    """ display the rectangle who are at the right and 
        left of the number of player, cases and billes
    """#display button save
    for i in range(len(liste_button)):
        if i == len(liste_button) - 1:
            cool = color
        else:
            cool = 'blue'
        fltk.rectangle(x - l_case / 2, y, x + l_case / 2, y + h_case, 
                       remplissage=cool, epaisseur=2)
        taille = fltk.taille_texte(liste_button[i][0], taille=30)
        fltk.texte(x, y + h_case / 2, liste_button[i][0], 
                   couleur='black', ancrage='center')
        fltk.texte(x , y + h_case - taille[1] // 2, 
                   str(liste_button[i][1]), ancrage='center')

        if i != 3:
            # button decrease
            fltk.rectangle(x - l_case / 2 - marg - iterate_button_dimension, y, 
                        x - l_case / 2 - marg, y + iterate_button_dimension 
                        ,epaisseur=2)
            fltk.rectangle(x - l_case / 2 - marg - iterate_button_dimension, 
                           y + iterate_button_dimension / 2 - marg, 
                        x - l_case / 2 - marg, y + iterate_button_dimension / 2 + marg 
                        ,epaisseur=2, remplissage='black')
            
            # button increase
            fltk.rectangle(x + l_case / 2 + marg, y, 
                        x + l_case / 2 + marg + iterate_button_dimension, 
                        y + iterate_button_dimension
                            , epaisseur=2)
            
            fltk.rectangle(x + l_case / 2 + marg, y + iterate_button_dimension / 2 - marg, 
                        x + l_case / 2 + marg + iterate_button_dimension, 
                        y + iterate_button_dimension / 2 + marg
                            , epaisseur=2, remplissage="black")
            
            fltk.rectangle(x + l_case / 2 + iterate_button_dimension / 2, y, 
                        x + l_case / 2 + 2 * marg + iterate_button_dimension / 2, 
                        y + iterate_button_dimension
                            , epaisseur=2, remplissage="black")


            liste_button_iterate.append(
                [x - l_case / 2 - marg - iterate_button_dimension, 
                 x + l_case / 2 + marg, y])
        if i == 3:
            cordonnees_save.append((x - l_case / 2,  y))
            cordonnees_save.append((x + l_case / 2, y + h_case))
        y += h_case + marg

    return number_player, number_case, number_bille, \
        liste_button_iterate, h_case, \
        cordonnees_save, l_case, color


def main_settings(l, h, p = 2, c = 7, b = 4):
    """
    a function who call page_settings and display it , and takes care of all transitions
    parametres : 
     l : width of the window float
     h : height of the window float
     p : number of player int
     c : number of boxes int 
     b : number of billes int 
    """
    p, c, b, liste_bouton, h_case, coordoonees_save, l_case, \
        color = page_settings(l, h, 'red', p, c, b)
    print(coordoonees_save)
    setting = True
    while setting:
        
        click = fltk.donne_ev()
        type_clic = fltk.type_ev(click)
        if type_clic == 'Quitte':
            fltk.ferme_fenetre()

        if type_clic == 'ClicGauche':
            x = fltk.abscisse(click)
            y = fltk.ordonnee(click)
            # checking if we are clicking in the rectangles of the page_settings
            for i in range(len(liste_bouton)):
                if i == 0:
                    # check if we decrease the number of player
                    if (liste_bouton[i][0] <= x <= liste_bouton[i][0] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case,\
                              coordoonees_save, l_case, color = page_settings( 
                                                l, h, color, p - 1, c, b)
                    # check if we increase the number of player
                    elif (liste_bouton[i][1] <= x <= liste_bouton[i][1] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case,\
                        coordoonees_save, l_case, color = page_settings( 
                                            l, h, color, p + 1, c, b)
                        
                elif i == 1:
                    # check if we decrease the number of boxes
                    if (liste_bouton[i][0] <= x <= liste_bouton[i][0] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case, \
                            coordoonees_save,l_case, color = page_settings( 
                                                l, h, color, p, c - 1, b)
                    # check if we increase the number of boxes
                    elif (liste_bouton[i][1] <= x <= liste_bouton[i][1] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case,\
                        coordoonees_save, l_case, color = page_settings(
                            l, h, color, p, c + 1, b)
                elif i == 2:
                    # check if we decrease the number of billes
                    if (liste_bouton[i][0] <= x <= liste_bouton[i][0] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case, \
                        coordoonees_save, l_case, color = page_settings( 
                                       l, h, color, p, c, b - 1)
                    # check if we increase the number of billes
                    elif (liste_bouton[i][1] <= x <= liste_bouton[i][1] + h_case and 
                        liste_bouton[i][2] <= y <= liste_bouton[i][2] + h_case):
                        fltk.efface_tout()
                        p, c, b, liste_bouton, h_case, \
                        coordoonees_save, l_case, color = page_settings(
                            l, h, color, p, c, b + 1)
            nb_balle_totale = p * (b)
            aire = c * c
            if nb_balle_totale >= aire:
                b  = aire // p
                p, c, b, liste_bouton, h_case, \
                coordoonees_save, l_case, color= page_settings(l, h, color, p, c, b)

            # if we click at the save button we return to main page
            if (coordoonees_save[0][0] <= x and x <= coordoonees_save[1][0] and 
                coordoonees_save[0][1] <= y and y <= coordoonees_save[1][1]):
                fltk.efface_tout()
                setting = False
            
        x_souris = fltk.abscisse_souris()
        y_souris = fltk.ordonnee_souris()
        # we check if our mouse is in the save button to hcnage his color
        color = detection_save(x_souris, y_souris, p, 
                               c, b, l, h, color, coordoonees_save)

        fltk.mise_a_jour()
    from page_principale import main_page_principale
    main_page_principale(l, h, p, c, b)

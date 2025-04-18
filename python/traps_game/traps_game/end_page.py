import fltk


def end_page(player, l, h, color):
    """
    a function who display the winner and end the game
    parametres : 
      player: the winner str
      l : width of the window
      h : height of he window
      color : color of the player's name str
    """
    winner = "winner is " + player
    end = "G A M E O V E R"
    return_text = "click to return"
    fltk.image(l / 2, h / 2, "res/bg.gif", 
                    largeur=int(l * 1.77), hauteur=h, ancrage='center')

    fltk.texte(l / 2 , h / 4, end, couleur="black", ancrage="center", taille=50)
    fltk.texte(l / 2, 3 * h / 4, winner, couleur=color, ancrage='center', taille=30)
    fltk.texte(0, h - fltk.taille_texte(return_text)[1], return_text, couleur="black")



def main_end(player, l, h, couleur):
    """
    a function who display the end page
    parametres : 
      player: the winner str
      l : width of the window
      h : height of he window
      color : color of the player's name str
    """
    end_page(player, l, h, couleur)
    condition = True
    while condition:
        clic = fltk.donne_ev()
        type_clic = fltk.type_ev(clic)
        if fltk.attend_clic_gauche():
            from page_principale import main_page_principale
            main_page_principale(l, h)
            condition = False
        fltk.mise_a_jour()


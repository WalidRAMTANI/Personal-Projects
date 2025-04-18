import fltk
from board import creation_quadrillage, supp_balle
from calcul import size_box
from tirette import  decale_tirette, creation_tirette, modif_tirette_name
from affichage import afficher_trou, choix_balle, aff_joueur,\
    afficher_nombre_tire_possible, verif_nombre_place
from end_page import main_end
 
# Normalement vous changez les constantes et ça s'adapte automatiquement
#LARGEUR = 700
#HAUTEUR = 700
    
def play(LARGEUR, HAUTEUR, nb_playeur, NB_CASE, nb_balle_playeur):
    """
    nb_playeur: int nombre de joueur
    NB_CASE: int nombre de case
    nb_balle_playeur:  int nombre de balle
    """
    nb_balle = nb_balle_playeur * nb_playeur #nombre de balle pour tout les joueur qui ne change jamais
    joueur_name = ["David", "Walid", "Abdel", "Kader", "Rekia", "Stephany"]
    couleur = ["green", "red", "brown", "white", "yellow", "#FF00E4"]
    joueur = {}
    for i in range(nb_playeur):
        cle = couleur[i]
        joueur[cle] = nb_balle_playeur

    save_click = [10, -1] #variable pour ne pas pouvoir click sur le cote opposer
    
    #le nombre de fois ou la tirette a été tiré a gauche/en haut par ligne
    compteur_tirette = [{"h": 1, "v": 1} ]
    for _ in range(NB_CASE - 1):
        compteur_tirette.append({"h": 1, "v": 1})
   
    tirette_h_def, tirette_v_def = creation_tirette(NB_CASE)
    tirette_h_def, tirette_v_def = tuple(tirette_h_def), tuple(tirette_v_def)
    tirette_v = [a[1:NB_CASE + 1]for a in tirette_v_def]
    tirette_h = [a[1:NB_CASE + 1]for a in tirette_h_def]
    nb_balle_playeur = verif_nombre_place(nb_balle, tirette_h, tirette_v, nb_playeur)

    nb_balle = nb_balle_playeur * nb_playeur
    boxDimensions, margin, coordinateNW = size_box(LARGEUR, HAUTEUR, NB_CASE)
    quadrillage = creation_quadrillage(NB_CASE, NB_CASE, boxDimensions, coordinateNW)
   
    #affiche le quadrillage, balle, et les tirettes
    afficher_trou(tirette_h, tirette_v, quadrillage, boxDimensions, margin, NB_CASE)
    tour = aff_joueur(-1, joueur, True, nb_balle_playeur, joueur_name) #tour du joueur précedent
    while True:
        ev = fltk.donne_ev()
        tev = fltk.type_ev(ev)
        afficher_nombre_tire_possible(quadrillage, compteur_tirette, NB_CASE, 2, boxDimensions)
        #print(tev) if ev != None else None
        if tev == 'Quitte':
            break

        if tev == 'ClicGauche' and nb_balle > 0: #pour posser les balle au debut du jeu
            nb_balle_avant = nb_balle 
            nb_balle = choix_balle(nb_balle, quadrillage, boxDimensions,
                                margin, list(joueur)[tour], tirette_h, tirette_v)
            if nb_balle_avant != nb_balle: #verifie si on a possé une balle ou pas
                tour = aff_joueur(tour, joueur, True, nb_balle_playeur, joueur_name)
            
        if tev == 'ClicGauche' and nb_balle <= 0: #pour bouger les tirettes
            horizontale = modif_tirette_name(quadrillage, boxDimensions, margin)
            if type(horizontale) != bool:
                continue
            modif, tirette_v, tirette_h = decale_tirette(tirette_h_def, tirette_v_def, quadrillage, boxDimensions,
                            margin, horizontale, compteur_tirette, tirette_h, tirette_v, save_click)
            if modif:
                fltk.efface_tout()
                quadrillage, joueur = supp_balle(quadrillage, tirette_h, tirette_v, joueur)
                cpt = 0
                gagnant = 0 #coorpondrat au gagnant
                for indice, cle in enumerate(joueur):
                        if joueur[cle] > 0:
                            cpt += 1
                            """coorpondrat au potentiele gagnant tuple du nom
                            et de la couleur du potentiele gagnant"""
                            gagnant = (joueur_name[indice], cle) 
                if cpt < 2: #verifie que plus d'une personne a des balle
                    """quand cette condition est valider alors la varible 
                    gagnant coorespond a l'indice du gagnant dans la
                    liste des couleurs et celle des noms"""
                    print(gagnant, couleur, joueur_name)
                    main_end(gagnant[0], LARGEUR, HAUTEUR, gagnant[1])
                
                afficher_trou(tirette_h, tirette_v, quadrillage, boxDimensions, margin, NB_CASE)
                tour = aff_joueur(tour, joueur, False, nb_balle_playeur, joueur_name)
        fltk.mise_a_jour()
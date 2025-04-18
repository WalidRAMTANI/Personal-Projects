class planche:
    def __init__(self, x_g, y_g, x_d, y_d, color):
        self.x_g = x_g
        self.y_g = y_g
        self.x_d = x_d
        self.y_d = y_d
        self.taille = x_d - x_g
        self.color = color

    def moove(self, dir):
        self.x_d += dir
        self.x_g += dir
    
    def move_bas(self, dir):
        self.y_d += dir
        self.y_g += dir

    def move_haut(self, dir):
        self.y_d -= dir
        self.y_g -= dir

    def move_gauche(self, dir):
        self.x_d -= dir
        self.x_g -= dir

    def move_droite(self, dir):
        self.x_d += dir
        self.x_g += dir




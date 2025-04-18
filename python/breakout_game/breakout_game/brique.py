class brique:
    def __init__(self, x_g, y_g, x_d, y_d, bonus, color):
        self.x_g = x_g
        self.y_g = y_g
        self.x_d = x_d
        self.y_d = y_d
        self.taille = x_d - x_g
        self.bonus = bonus
        self.color = color
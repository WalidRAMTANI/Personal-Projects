class ball:
    
    def __init__(self, x, y, r, vx, vy, vie = 3):
        self.x = x
        self.y = y
        self.rayon = r 
        self.vx = vx
        self.vy = vy

    def move(self):
        self.x += self.vx
        self.y += self.vy

    def change_direction(self):
        self.vy *= -1

    def sup(self):
         self.x = 5000
         self.y = -5000
         self.vx, self.vy = 0, 0
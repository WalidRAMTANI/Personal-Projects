#génerer un tableau mahjong au hasard ou etre sur quil est réalisable
#construction matrice, éléments de 1 à X, avec X le nombre de tuiles differentes, 0 lorsque c'est vide
# coder chaque mouvement possible sous forme mathematique

#pour verifier qu'il est realisable: trouver tous les identiques adjacents, puis tous les identiques adjacents séparés par "0"
#chaque image, nombre pair

[4, 4, 4, 0]



from random import*
 
Dim = 8, 12
NombTuiles = int((Dim[0]*Dim[1])/4)
Compteurs = []

for a in range(NombTuiles):
	Compteurs.append(4)

Matrice = []

"""
for i in range(Dim[0]):
	Matrice.append([])
	for j in range(Dim[1]):
		tuile = randint(1, NombTuiles)
		if Compteurs[tuile-1]>0:
			Matrice[i].append(tuile)
			Compteurs[tuile-1] -= 1
		else:
			j -= 1


print(Compteurs)
"""


liste = []
for j in range(4):
	for i in range(24):
		liste.append(i)

print(liste)
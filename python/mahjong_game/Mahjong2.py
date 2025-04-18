#génerer un tableau mahjong au hasard ou etre sur quil est réalisable
#construction matrice, éléments de 1 à X, avec X le nombre de tuiles differentes, 0 lorsque c'est vide
# coder chaque mouvement possible sous forme mathematique

#pour verifier qu'il est realisable: trouver tous les identiques adjacents, puis tous les identiques adjacents séparés par "0"
#chaque image, nombre pair
# 30 images max, 30*4 = 120, 12 * 10 taille max, tous les tableaux plus petits valides, calculer nombre de tuiles differentes
[4, 4, 4, 0]



from random import*
 
Dim = 8, 12
Matrice = []


liste = []
for j in range(4):
	for i in range(24):
		liste.append(i)

Comp = 0
template = []
for i in range(len(liste)):
	if Comp == Dim[x]:
		Comp = 0
	index = randint(0, Dim[0]*Dim[1]-i-1)
	Matrice.append(liste[index])
	liste.remove(liste[index])

print(liste)
print(Matrice)


"""
Dim = 8, 12
NombTuiles = int((Dim[0]*Dim[1])/4)
Compteurs = []

for a in range(NombTuiles):
	Compteurs.append(4)

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
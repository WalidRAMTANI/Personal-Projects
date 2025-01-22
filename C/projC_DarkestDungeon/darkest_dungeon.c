/*
	created by:
 		- RAMTANI Walid
   		- LI Elodie
     	for:
      		semester final project in C language
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Structures



typedef struct Accessoire{
    char nom[50];
    int attbonus; // points d'attaque bonus
    int defbonus; // points de defense bonus
    int HPbonus; // points de vie bonus
    int restbonus; // points de restauration bonus
    int strred; // points de stress réduits
} Accessoire;

typedef struct Ennemi{
    char nom[50];
    int niveau;
    int attenn; // points d'attaque ennemi
    int defenn; // points de defense ennemi
    float HPenn; // points de vie actuels ennemi
    int attstrenn; // points de stress ennemi infligés
} Ennemi;


// LISTE D'ENNEMIS

typedef struct EnnemiVivant{
    Ennemi *ennmi;
    struct EnnemiVivant *suivant;
}EnnemiVivant;

typedef struct Classe {
    char *nom;
    int att;
    int def;
    int HPmax;
    int rest;
} Classe;

typedef struct Personnage {
    char *nom;
    Classe *classe;
    int att;
    int def;
    int HPmax;
    float HP;
    int rest;
    int str;
    int nbcomb;
    Accessoire *acc1;
    Accessoire *acc2;
    
} Personnage;



typedef struct Sanitarium{
    Personnage *personnage;
    struct Sanitarium *suivant;
} Sanitarium;

typedef struct Taverne{
    Personnage *personnage;
    struct Taverne *suivant;
} Taverne;

typedef struct Roulotte{
    int numero;
    Accessoire accessoire;
    int prix;
    struct Roulotte *suivant;
} Roulotte;


typedef struct AccessoireDispo{
    Accessoire *accessoire;
    struct AccessoireDispo *suivant;
}AccessoireDispo;

typedef struct Perso_dispo {
    Personnage *perso;
    char action;
    struct Perso_dispo *suivant;
} Perso_dispo;

// Fonctions
void initClasses(Classe **classe) {
	/*
		initialise les differentes classes de personnages avec leurs attributs (nom, attaque, defense, etc)
	*/
    Classe *furie = (Classe *)malloc(sizeof(Classe));
    if (furie == NULL) exit(1);
    furie->nom = (char *)malloc(50 * sizeof(char));
    strcpy(furie->nom, "Furie");
    furie->att = 13;
    furie->def = 0;
    furie->HPmax = 20;
    furie->rest = 0;
    classe[0] = furie;

    Classe *vestale = (Classe *)malloc(sizeof(Classe));
    if (vestale == NULL) exit(1);
    vestale->nom = (char *)malloc(50 * sizeof(char));
    strcpy(vestale->nom, "Vestale");
    vestale->att = 3;
    vestale->def = 0;
    vestale->HPmax = 20;
    vestale->rest = 10;
    classe[1] = vestale;

    Classe *chasseur = (Classe *)malloc(sizeof(Classe));
    if (chasseur == NULL) exit(1);
    chasseur->nom = (char *)malloc(50 * sizeof(char));
    strcpy(chasseur->nom,"Chasseur");
    chasseur->att = 7;
    chasseur->def = 3;
    chasseur->HPmax = 25;
    chasseur->rest = 3;
    classe[2] = chasseur;

    Classe *maitre = (Classe *)malloc(sizeof(Classe));
    if (maitre == NULL) exit(1);
    maitre->nom = (char *)malloc(50 * sizeof(char));
    strcpy(maitre->nom, "Maître chien");
    maitre->att = 10;
    maitre->def = 6;
    maitre->HPmax = 17;
    maitre->rest = 5;
    classe[3] = maitre;
}

void afficherClasses(Classe **classe) {
	/*
		affiche les informations de toutes les classes de personnages
	*/
    for (int i = 0; i < 4; i++) {
        printf("Classe : %s\n", classe[i]->nom);
        printf("Attaque : %d\n", classe[i]->att);
        printf("Défense : %d\n", classe[i]->def);
        printf("Points de vie max : %d\n", classe[i]->HPmax);
        printf("Points de restauration : %d\n", classe[i]->rest);
        printf("\n");
    }
}

void ajouter_personnage(Classe **classe, Perso_dispo **p, int nb_classe) {
	/*
		ajoute un nouveau personnage a une liste de personnages disponibles
	*/
    Perso_dispo *element = (Perso_dispo *)malloc(sizeof(Perso_dispo));
    if (element == NULL) exit(1);

    element->perso = (Personnage *)malloc(sizeof(Personnage));
    element->perso->acc1 = NULL;
    element->perso->acc2 = NULL;

    if (element->perso == NULL) {
        free(element);
        exit(1);
    }

    element->perso->nom = (char *)malloc(50 * sizeof(char));
    if (element->perso->nom == NULL) {
        free(element->perso);
        free(element);
        exit(1);
    }

    printf("Entrez un premier nom : ");
    scanf("%49s", element->perso->nom);
    element->perso->classe = classe[nb_classe];
    element->perso->att = element->perso->classe->att;
    element->perso->def = element->perso->classe->def;
    element->perso->HP = element->perso->classe->HPmax;
    element->perso->HPmax = element->perso->classe->HPmax;
    element->perso->rest = element->perso->classe->rest;
    element->perso->str = 0;
    element->perso->nbcomb = 0;
    element->suivant = *p;
    *p = element;
}


void afficherPersonnage1(Personnage *p) {
	/*
		affiche les details d'un personnage specifique
	*/
    printf("/-----------------------------------------------------/\n");
    printf(" Nom : %s\n",p->nom);
    printf("Classe : %s, Att : %d, Déf : %d, HP/HPmax : %f/%d, Rest : %d, Stress : %d, NbComb : %d\n",
               p->classe->nom, p->att, p->def,
               p->HP, p->HPmax, p->rest,
                 p->str, p->nbcomb);
    
    printf("/-----------------------------------------------------/\n");

}


void afficherPersonnage(Perso_dispo *p) {
	/*
		affiche la liste des personnages disponibles
	*/
    printf("/-----------------------------------------------------/\n");
    int i = 1;
    for (Perso_dispo *temp = p; temp != NULL; temp = temp->suivant) {
        printf("%d - Nom : %s\n", i,temp->perso->nom);
        printf("Classe : %s, Att : %d, Déf : %d, HP/HPmax : %f/%d, Rest : %d, Stress : %d, NbComb : %d\n",
               temp->perso->classe->nom, temp->perso->att, temp->perso->def,
               temp->perso->HP, temp->perso->HPmax, temp->perso->rest,
               temp->perso->str, temp->perso->nbcomb);
        i++;
    }
    printf("/-----------------------------------------------------/\n");

}

// fonction pour creer un accessoire
Accessoire creerAccessoire(const char *nom, int att, int def, int HP, int rest, int stress) {
	/*
		cree un nouvel accessoire avec les attributs specifiés
	*/
    Accessoire acc;
    strcpy(acc.nom, nom); // Copie sécurisée du nom
    acc.attbonus = att;
    acc.defbonus = def;
    acc.HPbonus = HP;
    acc.restbonus = rest;
    acc.strred = stress;
    return acc;
}



void Free_personnage(Perso_dispo *p) {
	/*
		libere la memoire allouee pour la liste des personnages
	*/
    while (p != NULL) {
        Perso_dispo *temp = p;
        free(p->perso->nom);
        free(p->perso);
        p = p->suivant;
        free(temp);
    }
    printf("Tous les personnages ont été libérés.\n");
}

void FreeClasses(Classe **classe) {
	/*
		libere la memoire allouee pour les classes
	*/
    for (int i = 0; i < 4; i++) {
        if (classe[i] != NULL) {
            free(classe[i]->nom);
            free(classe[i]);
            classe[i] = NULL;
        }
    }
    printf("Toutes les classes ont été libérées.\n");
}

// creer les deux premiers acccessoire
void creer_start_accessoire(AccessoireDispo **l){
	/*
		cree et ajoute les premiers accessoires disponibles
	*/
    (*l) = (AccessoireDispo *) malloc(sizeof(AccessoireDispo));
    if((*l) == NULL) return;
    Accessoire *a1 = (Accessoire *)malloc(sizeof(Accessoire));
    Accessoire *a2 = (Accessoire *)malloc(sizeof(Accessoire));
    if(a1 == NULL || a2 == NULL) return;
    *a1 = creerAccessoire("Pendentif tranchant", 10, 5, 1, 0, 0);
    *a2 = creerAccessoire("Calice de jeunesse", 0, 3, 5, 0, 5);
    (*l)->accessoire = a1;
    (*l)->suivant = (AccessoireDispo *) malloc(sizeof(AccessoireDispo));
    if(!(*l)->suivant) return ;
    (*l)->suivant->accessoire = a2;
    (*l)->suivant->suivant = NULL;
}

// liberer les deux premiers acccessoire
void libererAccessoires(AccessoireDispo *l) {
	/*
		libere la memoire allouee pour la liste des accessoires
	*/
    AccessoireDispo *temp;

    // Parcourt la liste chaînée et libère les ressources
    while (l != NULL) {
        temp = l->suivant; // Sauvegarde du suivant
        if (l->accessoire != NULL) {
            free(l->accessoire); // Libère l'accessoire
        }
        free(l);
        l = temp;
    }
}


void afficherAccessoire(Accessoire acc) {
	/*
		affiche les details d'un accessoire specifique
	*/
    printf("Nom : %s\n", acc.nom);
    printf("Bonus d'attaque : %d\n", acc.attbonus);
    printf("Bonus de défense : %d\n", acc.defbonus);
    printf("Bonus de points de vie : %d\n", acc.HPbonus);
    printf("Bonus de restauration : %d\n", acc.restbonus);
    printf("Réduction de stress : %d\n\n", acc.strred);
}

void afficherListeAccessoires(AccessoireDispo *l) {
	/*
		affiche la liste des accessoires disponibles
	*/
    int i = 1;
    for (AccessoireDispo *p = l; p != NULL; p = p->suivant) {
        printf("%d ", i);
        i++;
        afficherAccessoire(*(p->accessoire));
    }
}



// ajouter personnage à une liste
void ajouterDebutPerso(Perso_dispo **liste, Perso_dispo *nouveau) {
	/*
		ajoute un personnage au debut d'une liste des personnages disponibles
	*/

    if (nouveau == NULL) {
        printf("personne est NULL, on n'ajoute rien, on quitte");
        return;
    }
    nouveau->suivant = *liste;
    *liste = nouveau;
    }



int tailleSanitarium(Sanitarium* liste) {
	/*
		calcule et retourne la taille de la liste du sanitarium
	*/
    int compteur = 0;
    while (liste != NULL) {
        compteur++;
        liste = liste->suivant; 
    }
    return compteur;
}



int ajouterDebutSanitarium(Sanitarium** liste, Personnage* nouveau) {
	/*
		ajoute un personnage au début de la liste du sanitarium
	*/
    if (nouveau == NULL) {
        printf("Le nouveau nœud est NULL, rien n'est ajouté.\n");
        return 0;
    }else if(tailleSanitarium(*liste) < 2){
        Sanitarium *elem = malloc(sizeof(Sanitarium));
        elem->personnage = nouveau;
        elem->suivant = *liste; 
        *liste = elem;
        return 1;
    }
    else{
        printf("Le sanitarium est deja remplie.\n");
        return 0;
    }
}



void ajouterDebutACC(AccessoireDispo **liste, Accessoire *nouveau) {
	/*
		ajoute un accessoire au début de la liste des accessoires disponibles
	*/
    if (nouveau == NULL) {
        printf("paccesoire est NULL, on n'ajoute rien, on quitte");
        return;
    }
    AccessoireDispo *elem = malloc(sizeof(AccessoireDispo));
    if(!elem) return;
    elem->accessoire = nouveau;
    elem->suivant = *liste;
    *liste = elem;
    }

// EXTRAIRE UN PERSONNAGE

Perso_dispo *ExtraireUnPersonnage(Perso_dispo **l, int id) {
	/*
		extrait un personnage de la liste des personnages disponibles par son ID
	*/
    if (*l == NULL) return NULL;  
    if (id <= 0) return NULL;     

    Perso_dispo *temp = *l;
    Perso_dispo *precedent = NULL;

    // Parcours pour trouver le personnage correspondant à l'id
    for (int i = 1; temp != NULL && i < id; i++) {
        precedent = temp;
        temp = temp->suivant;
    }

    // Si id dépasse la taille de la liste
    if (temp == NULL) return NULL;

    // Retrait de l'élément
    if (precedent == NULL) {
        // Suppression du premier élément
        *l = temp->suivant;
    } else {
        // Suppression d'un élément au milieu ou à la fin
        precedent->suivant = temp->suivant;
    }

    // couper la relation avant le suivant
    temp->suivant = NULL;
    return temp;
}

Sanitarium* ExtraireUnSanitarium(Sanitarium** liste, int id) {
	/*
		extrait un personnage du sanitarium par son ID
	*/
    if (*liste == NULL) return NULL;  // Si la liste est vide
    if (id <= 0) return NULL;        // Si l'ID est invalide

    Sanitarium* temp = *liste;
    Sanitarium* precedent = NULL;

    // Parcours pour trouver le nœud correspondant à l'id
    for (int i = 1; temp != NULL && i < id; i++) {
        precedent = temp;
        temp = temp->suivant;
    }

    // Si id dépasse la taille de la liste
    if (temp == NULL) return NULL;

    // Retrait de l'élément
    if (precedent == NULL) {
        // Suppression du premier élément
        *liste = temp->suivant;
    } else {
        // Suppression d'un élément au milieu ou à la fin
        precedent->suivant = temp->suivant;
    }

    // Couper la relation avec le reste de la liste
    temp->suivant = NULL;
    return temp;
}



Taverne* ExtraireUnTaverne(Taverne** liste, int id) {
	/*
		extrait un personnage de la taverne par son ID
	*/
    if (*liste == NULL) return NULL;  // Si la liste est vide
    if (id <= 0) return NULL;         // Si l'ID est invalide

    Taverne* temp = *liste;
    Taverne* precedent = NULL;

    // Parcours pour trouver le nœud correspondant à l'id
    for (int i = 1; temp != NULL && i < id; i++) {
        precedent = temp;
        temp = temp->suivant;
    }

    // Si id dépasse la taille de la liste
    if (temp == NULL) return NULL;

    // Retrait de l'élément
    if (precedent == NULL) {
        // Suppression du premier élément
        *liste = temp->suivant;
    } else {
        // Suppression d'un élément au milieu ou à la fin
        precedent->suivant = temp->suivant;
    }

    // Couper la relation avec le reste de la liste
    temp->suivant = NULL;
    return temp;
}


AccessoireDispo *ExtraireUnAccessoireParId(AccessoireDispo **l, char id) {
	/*
		extrait un accessoire de la liste des accessoires disponibles par son ID
	*/
    if (*l == NULL || id <= 0) return NULL;  // Vérifier si la liste est vide ou si id est invalide

    AccessoireDispo *temp = *l;
    AccessoireDispo *precedent = NULL;
    int compteur = 1;  // Initialiser le compteur à 1 pour correspondre à l'indice de l'élément

    // Parcours de la liste pour trouver l'accessoire à la position "id"
    while (temp != NULL) {
        if (compteur == id) {  // Si le compteur correspond à l'id recherché
            // Retrait de l'élément trouvé
            if (precedent == NULL) {
                // Suppression du premier élément
                *l = temp->suivant;
            } else {
                // Suppression d'un élément au milieu ou à la fin
                precedent->suivant = temp->suivant;
            }

            // Couper la relation avant le suivant
            temp->suivant = NULL;
            return temp;  // Retourner l'élément extrait
        }

        // Passer à l'élément suivant
        precedent = temp;
        temp = temp->suivant;
        compteur++;  // Incrémenter le compteur pour correspondre à l'indice
    }

    // Si l'élément avec l'ID spécifié n'est pas trouvé
    return NULL;
}


void AfficherPersonnagesAvecAccessoires(Perso_dispo *l) {
	/*
		affiche les details des personnages avec leurs accessoires
	*/
    printf("/----------------------------------------------------------------/\n");
    printf("L I S T E S     P E R S O N N A G E S      A V E C      A C C E S S O I R E S\n");
    if (l == NULL) {
        printf("Aucun personnage à afficher.\n");
        return;
    }

    Perso_dispo *temp = l;
    while (temp != NULL) {
        Personnage *perso = temp->perso;
        
        // Afficher les informations générales du personnage
        printf("Personnage : %s\n", perso->nom);
        printf("Classe : %s\n", perso->classe->nom);
        printf("Statistiques : Attaque = %d, Défense = %d, HP = %f/%d, Restauration = %d, Stress = %d\n",
               perso->att, perso->def, perso->HP, perso->HPmax, perso->rest, perso->str);
        printf("Nombre de combats : %d\n", perso->nbcomb);

        // Afficher le premier accessoire
        printf("Accessoire 1 : ");
        if (perso->acc1 != NULL) {
            printf("%s (Attaque +%d, Défense +%d, HP +%d, Restauration +%d, Stress réduit %d)\n",
                   perso->acc1->nom, perso->acc1->attbonus, perso->acc1->defbonus,
                   perso->acc1->HPbonus, perso->acc1->restbonus, perso->acc1->strred);
        } else {
            printf("Aucun\n");
        }

        // Afficher le deuxième accessoire
        printf("Accessoire 2 : ");
        if (perso->acc2 != NULL) {
            printf("%s (Attaque +%d, Défense +%d, HP +%d, Restauration +%d, Stress réduit %d)\n",
                   perso->acc2->nom, perso->acc2->attbonus, perso->acc2->defbonus,
                   perso->acc2->HPbonus, perso->acc2->restbonus, perso->acc2->strred);
        } else {
            printf("Aucun\n");
        }

        printf("----------------------------------------\n");
        temp = temp->suivant;
    }
}


void afficherHPStr(Perso_dispo *perso) {
	/*
		affiche les noms, HP et stress des combattants
	*/
    printf("/--------------------------------------------------/\n");
    printf("RAPPELLER LES NOMS , HP ET STR DES COMBATTANTS\n");
    Perso_dispo *element = perso;
    while (element != NULL) {
        Personnage *p = element->perso;
        if (p != NULL) {
            printf("Nom: %s, HP: %f, Stress: %d\n", p->nom, p->HP, p->str);
        }
        element = element->suivant;
    }
    printf("/--------------------------------------------------/\n");
}

void ajouter_accessoire_features(Personnage **perso, Accessoire *acc1){
	/*
		ajoute les caracteristiques d'un accessoire à un personnage
	*/
    (*perso)->att += acc1->attbonus ;
    (*perso)->def += acc1->defbonus ;
    (*perso)->HP += acc1->HPbonus;
    (*perso)->HPmax += acc1->HPbonus;
    (*perso)->rest += acc1->restbonus;
    (*perso)->str += acc1->strred;
}


Ennemi *CreerEnnemi(const char *nom, int niveau, int attenn, int defenn, int HPenn, int attstrenn) {
	/*
		cree un nouvel ennemi avec les attributs specifies
	*/
    Ennemi *e = (Ennemi *)malloc(sizeof(Ennemi));
    strcpy(e->nom, nom);
    e->niveau = niveau;
    e->attenn = attenn;
    e->defenn = defenn;
    e->HPenn = HPenn;
    e->attstrenn = attstrenn;
    return e;
}

// Function to free an Ennemi
void freeEnnemi(Ennemi *e) {
	/*
		libere la memoire allouee pour un ennemi
	*/
    free(e);
}

// Function to create an EnnemiVivant element
EnnemiVivant *createEnnemiVivant(Ennemi *ennmi) {
	/*
		cree un element de la liste des ennemis vivants
	*/
    EnnemiVivant *element = (EnnemiVivant *)malloc(sizeof(EnnemiVivant));
    element->ennmi = ennmi;
    element->suivant = NULL;
    return element;
}

// Function to add an EnnemiVivant to the list
void addEnnemiVivant(EnnemiVivant **head, Ennemi *ennmi) {
	/*
		ajoute un ennemi vivant a la tete de la liste
	*/
    EnnemiVivant *element = createEnnemiVivant(ennmi);
    element->suivant = *head;
    *head = element;
}


void freeEnnemis(EnnemiVivant *head) {
	/*
		libere la memoire allouee pour la liste des ennemis vivants
	*/
    EnnemiVivant *current = head;
    while (current != NULL) {
        EnnemiVivant *temp = current;
        current = current->suivant;
        freeEnnemi(temp->ennmi);
        free(temp);
    }
}


void AfficherEnnemisVivants(EnnemiVivant *head) {
	/*
		affiche la liste des ennemis vivants
	*/
    printf("/-----------------------------------/");
    printf("L I S T E S             D E S           E N N E M I S\n");
    EnnemiVivant *current = head;
    while (current != NULL) {
        Ennemi *e = current->ennmi;
        printf("Nom: %s, Niveau: %d, Attaque Physique: %d, Défense: %d, HP: %f, Stress: %d\n",
               e->nom, e->niveau, e->attenn, e->defenn, e->HPenn, e->attstrenn);
        current = current->suivant;
    }
    printf("/-----------------------------------/");

}


Perso_dispo *obtenirPersonnage(Perso_dispo *liste, int id) {
	/*
		retourne un personnage de la liste par son ID
	*/
    int compteur = 1;
    Perso_dispo *courant = liste;

    // Parcours de la liste
    while (courant != NULL) {
        if (compteur == id) {
            return courant; // Retourne le personnage trouvé
        }
        courant = courant->suivant; // Passe au personnage suivant
        compteur++;
    }
    return NULL;
}

float genererNombreAleatoireENTRE812(float min, float max) {
	/*
		genere un nombre random entre min et max
	*/
    printf("RANDOM %f\n", min + (rand() / (RAND_MAX + 1.0)) * (max - min));
    return min + (rand() / (RAND_MAX + 1.0)) * (max - min);      // Scales it to the desired range
}


// Fonction pour calculer la taille de la liste chaînée
int tailleListe(Perso_dispo *liste) {
	/*
		calcule et retourne la taille de la liste de personnages disponibles
	*/
    int taille = 0;
    Perso_dispo *perso = liste;

    while (perso != NULL) {
        taille++;               // Incrémenter le compteur
        perso = perso->suivant; // Passer au perso suivant
    }

    return taille;               // Retourner le nombre de personnage
}


void supprimerPerso(Perso_dispo **liste, Perso_dispo *Supprimer) {
	/*
		supprmime un personnage de la liste des personnages disponibles
	*/
    if (*liste == NULL || Supprimer == NULL) {
        return;
    }

    // Si le le personnage à supprimer est la tête de la liste
    if (*liste == Supprimer) {
        *liste = Supprimer->suivant;
        Supprimer->suivant = NULL;
        free(Supprimer->perso->acc1);
        free(Supprimer->perso->acc2);
        Free_personnage(Supprimer);          
        return;
    }

    // Rechercher du personage précédent 
    Perso_dispo *temp = *liste;
    while (temp->suivant != NULL && temp->suivant != Supprimer) {
        temp = temp->suivant;
    }

    // Si le personnage à supprimer a été trouvé
    if (temp->suivant == Supprimer) {
        temp->suivant = Supprimer->suivant; 
        Supprimer->suivant = NULL;
        free(Supprimer->perso->acc1);
        free(Supprimer->perso->acc2);
        Free_personnage(Supprimer);
    }
}

void supprimerEnnemi(EnnemiVivant **liste) {
	/*
		supprime un enniemi de la liste des ennemis vivants
	*/
    if (*liste == NULL) {
        return;
    }

    EnnemiVivant *Supprimer = *liste;    
    *liste = (*liste)->suivant;          
    free(Supprimer->ennmi);            
    free(Supprimer); 
}


void afficherSanitarium(Sanitarium **sant) {
	/*
		affiche les details des personnages dans le sanitarium
	*/
    Sanitarium *temp = *sant;
    if(*sant == NULL){
        printf("le sanitarium est vide \n");
        return;}
    printf("Contenu du Sanitarium:\n");
    while (temp != NULL) {
        if(temp->personnage->HP + 7 <= temp->personnage->HPmax){
            temp->personnage->HP += 7;
        }else{
            temp->personnage->HP = temp->personnage->HPmax;
        }
        afficherPersonnage1(temp->personnage);
        temp = temp->suivant;
    }
}


int tailleTaverne(Taverne *liste) {
	/*
		calcule et retourne la taille de la liste de la taverne
	*/
    int compteur = 0;
    while (liste != NULL) {
        compteur++;
        liste = liste->suivant;
    }
    return compteur;
}


int ajouterDebutTaverne(Taverne** liste, Personnage* nouveau) {
	/*
		ajoute un personnage au debut de la liste de la taverne
	*/
    if (nouveau == NULL) {
        printf("Le nouveau personnage est NULL, rien n'est ajouté.\n");
        return 0;
    }else if(tailleTaverne(*liste) < 2){
        Taverne *elem = malloc(sizeof(Taverne));
        elem->personnage = nouveau;
        elem->suivant = *liste; 
        *liste = elem;
        return 1;
    }
    else{
        printf("Le sanitarium est deja remplie.\n");
        return 0;
    }
}

void afficherTaverne(Taverne **liste) {
	/*
		affiche les details des personnages dans la taverne
	*/
    Taverne *temp = *liste;
    while (temp != NULL) {
        if(temp->personnage->str - 25 >= 0){
            temp->personnage->str -= 25;
        }else{
            temp->personnage->str = 0;
        }
        afficherPersonnage1(temp->personnage);
        temp = temp->suivant;
    }
}




Roulotte* creerRoulotte( char* nom, int attbonus, int defbonus, int HPbonus, int restbonus, int strred, int prix, int num) {
	/*
		cree une nouvelle roulotte avec les attributs specifies
	*/
    Roulotte *nouveau = (Roulotte *)malloc(sizeof(Roulotte));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nouveau->accessoire.nom, nom);
    nouveau->accessoire.attbonus = attbonus;
    nouveau->accessoire.defbonus = defbonus;
    nouveau->accessoire.HPbonus = HPbonus;
    nouveau->accessoire.restbonus = restbonus;
    nouveau->accessoire.strred = strred;
    nouveau->prix = prix;
    nouveau->numero = num;
    nouveau->suivant = NULL;
    return nouveau;
}

// Function to add a Roulotte node to the end of the list
void ajouterRoulotte(Roulotte **liste, Roulotte *nouveau) {
	/*
		ajoute une roulotte a la liste des roulottes disponibles
	*/
    if (*liste == NULL) {
        *liste = nouveau;
    } else {
        nouveau->suivant = *liste;
        *liste = nouveau;
    }
}

void afficherRoulottes(Roulotte *liste) {
	/*
		affiche la liste des accessoires dans la roulotte
	*/
    Roulotte *temp = liste;
    printf("Liste des accessoires dans la roulotte :\n");
    while (temp != NULL) {
        printf("%d-   Nom: %s, Prix: %d, Attaque: %d, Défense: %d, PV: %d, Restauration: %d, Stress réduit: %d\n",temp->numero,
               temp->accessoire.nom, temp->prix, temp->accessoire.attbonus,
               temp->accessoire.defbonus, temp->accessoire.HPbonus,
               temp->accessoire.restbonus, temp->accessoire.strred);
        temp = temp->suivant;
    }
}

// Free the memory allocated for the list
void libererRoulottes(Roulotte *liste) {
	/*
		libere la memoire allouee pour la liste des roulottes
	*/
    Roulotte *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }
}



void libererTraverne(Taverne *liste) {
	/*
		libere la memoire allouee pour la liste de la taverne
	*/
    Taverne *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp->personnage);
        free(temp);
    }
}



void libererSantarium(Sanitarium *liste) {
	/*
		libere la memoire pour la liste du sanitarium
	*/
    Sanitarium *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp->personnage);
        free(temp);
    }
}



Roulotte rechercherRoulotteParId(Roulotte *liste, int id) {
	/*
		recherche une roulotte par son ID
	*/
    while (liste != NULL) {
        if (liste->numero == id) {
            break;
        }
        liste = liste->suivant;
    }
    return *liste;

}



Personnage *ajouter_per(Perso_dispo *p, Classe **classe, int num){
	/*
		ajoute une classe a un personnage
	*/
    p->perso->classe = classe[num];
    p->perso->att = p->perso->classe->att;
    p->perso->def = p->perso->classe->def;
    p->perso->HPmax = p->perso->classe->HPmax;
    p->perso->rest = p->perso->classe->rest;
    return p->perso;
}

void Charger_information_simples(FILE *fichier ,int *p2, int *p4, int *p6, int *p8, int *nb_combat, int *or){
	/*
		charge les informations simples depuis un fichier
	*/
    if(fichier == NULL) exit(EXIT_FAILURE);
    fscanf(fichier, "%d %d %d %d %d %d\n", nb_combat, p2, p4, p6, p8, or);
    printf("%d %d %d %d %d %d\n", *nb_combat, *p2, *p4, *p6, *p8, *or);
}

void Charger_personnages_disponibles(FILE *fichier, Perso_dispo **personnage_disponible, Classe **classe) {
	/*
		charge les personnages disponibles depuis un fichier
	*/
    if (fichier == NULL) {
        printf("Erreur : Fichier invalide.\n");
        exit(EXIT_FAILURE);
    }

    char ligne[255];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Vérification : Ligne commençant par 'P'
        if (ligne[0] == 'P') {
            printf("Lecture de la ligne : %s", ligne);

            // Allocation pour le nouveau personnage
            Perso_dispo *perso = (Perso_dispo *)malloc(sizeof(Perso_dispo));
            if (perso == NULL) {
                printf("Erreur d'allocation pour Perso_dispo");
                exit(EXIT_FAILURE);
            }

            Personnage *p = (Personnage *)malloc(sizeof(Personnage));
            if (p == NULL) {
                printf("Erreur d'allocation pour Personnage");
                free(perso);
                exit(EXIT_FAILURE);
            }

            p->nom = (char *)malloc(50 * sizeof(char)); // Allouer pour le nom
            if (p->nom == NULL) {
                printf("Erreur d'allocation pour le nom du personnage");
                free(p);
                free(perso);
                exit(EXIT_FAILURE);
            }

            int la_classe;
            int nb_values = sscanf(ligne, "P %49s %d %f %d %d", p->nom, &la_classe, &p->HP, &p->str, &p->nbcomb);
            if (nb_values != 5) {
                printf("Erreur : données mal formatées pour un personnage.\n");
                free(p->nom);
                free(p);
                free(perso);
                continue;
            }

            printf("Personnage lu : %s, Classe : %d, HP : %.2f, Stress : %d, Combats : %d\n",
                   p->nom, la_classe, p->HP, p->str, p->nbcomb);

            p->acc1 = NULL;
            p->acc2 = NULL;
            if (la_classe >= 0 && la_classe < 4) {
                p->classe = classe[la_classe];
            } else {
                printf("Classe invalide pour le personnage %s\n", p->nom);
                free(p->nom);
                free(p);
                free(perso);
                continue;
            }
            perso->perso = p;
            p =  ajouter_per(perso, classe, la_classe);
            ajouterDebutPerso(personnage_disponible,perso);
        }
    }
    printf("Chargement terminé des personnages disponibles.\n");
    rewind(fichier);
}


void Charger_personnages_traverne(FILE *fichier, Taverne **traverne, Classe **classe) {
	/*
		charge les personnages de la taverne depuis un fichier
	*/
    if (fichier == NULL) {
        printf("Erreur : Fichier invalide.\n");
        exit(EXIT_FAILURE);
    }

    char ligne[255];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (ligne[0] != 'T') {
            continue; // Ignore non-T lines
        }

        printf("Lecture de la ligne : %s", ligne);

        // Allocate memory for Taverne and Personnage
        Taverne *perso = (Taverne *)malloc(sizeof(Taverne));
        if (!perso) {
            printf("Erreur d'allocation pour Taverne\n");
            exit(EXIT_FAILURE);
        }

        Personnage *p = (Personnage *)malloc(sizeof(Personnage));
        if (!p) {
            printf("Erreur d'allocation pour Personnage\n");
            free(perso);
            exit(EXIT_FAILURE);
        }

        p->nom = (char *)malloc(50 * sizeof(char));
        if (!p->nom) {
            printf("Erreur d'allocation pour le nom du personnage\n");
            free(p);
            free(perso);
            exit(EXIT_FAILURE);
        }

        int la_classe;
        Accessoire a1 = {0}, a2 = {0}; // Initialize to zero
        int nb_values = sscanf(ligne, "T %49s %d %f %d %d %d %d %d %s %d %d %d %d %d %s %d %d",
                               p->nom, &la_classe, &p->HP, &p->str, &p->nbcomb,
                               &a1.attbonus, &a1.defbonus, &a1.HPbonus, a1.nom,
                               &a1.restbonus, &a1.strred, &a2.attbonus, &a2.defbonus,
                               &a2.HPbonus, a2.nom, &a2.restbonus, &a2.strred);

        if (nb_values < 17) { // Adjust based on actual format
            printf("Erreur : données mal formatées pour un personnage.\n");
            free(p->nom);
            free(p);
            free(perso);
            continue;
        }

        p->acc1 = (a1.attbonus || a1.defbonus || a1.HPbonus || a1.restbonus || a1.strred) ? (Accessoire *)malloc(sizeof(Accessoire)) : NULL;
        if (p->acc1) {
            *(p->acc1) = a1;
            printf("Accessoire ajouté : %s, att : %d, str : %d, rest : %d\n",
               p->acc1->nom, p->acc1->attbonus, p->str, p->acc1->restbonus);
        }

        p->acc2 = (a2.attbonus || a2.defbonus || a2.HPbonus) || a2.restbonus || a2.strred ? (Accessoire *)malloc(sizeof(Accessoire)) : NULL;
        if (p->acc2) {
            *(p->acc2) = a2;
            printf("Accessoire ajouté : %s, att : %d, str : %d, rest : %d\n",
               p->acc2->nom, p->acc2->attbonus, p->str, p->acc2->restbonus);
        }

        if (la_classe >= 0 && la_classe < 4) {
            p->classe = classe[la_classe];
        } else {
            printf("Classe invalide pour le personnage %s\n", p->nom);
            free(p->nom);
            free(p->acc1);
            free(p->acc2);
            free(p);
            free(perso);
            continue;
        }

        // Add to Taverne
        perso->personnage = p;
        ajouterDebutTaverne(traverne, p);

        printf("Personnage ajouté : %s, Classe : %d, HP : %.2f, Stress : %d, Combats : %d\n",
               p->nom, la_classe, p->HP, p->str, p->nbcomb);
    }

    printf("Chargement terminé des personnages de la taverne\n");
    rewind(fichier);
}




void Charger_personnages_sanitarium(FILE *fichier, Sanitarium **sanitarium, Classe **classe) {
		/*
			charge les personnages du sanitarium depuis un fichier
		*/
    if (fichier == NULL) {
        printf("Erreur : Fichier invalide.\n");
        exit(EXIT_FAILURE);
    }

    char ligne[255];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (ligne[0] != 'S') {
            continue; // Ignore non-S lines
        }

        printf("Lecture de la ligne : %s", ligne);

        // Allocation mémoire pour Sanitarium et Personnage
        Sanitarium *perso = (Sanitarium *)malloc(sizeof(Sanitarium));
        if (!perso) {
            printf("Erreur d'allocation pour Sanitarium\n");
            exit(EXIT_FAILURE);
        }

        Personnage *p = (Personnage *)malloc(sizeof(Personnage));
        if (!p) {
            printf("Erreur d'allocation pour Personnage\n");
            free(perso);
            exit(EXIT_FAILURE);
        }

        p->nom = (char *)malloc(50 * sizeof(char));
        if (!p->nom) {
            printf("Erreur d'allocation pour le nom du personnage\n");
            free(p);
            free(perso);
            exit(EXIT_FAILURE);
        }

        int la_classe;
        Accessoire a1 = {0}, a2 = {0}; // Initialisation à zéro
        int nb_values = sscanf(ligne, "S %49s %d %f %d %d %d %d %d %s %d %d %d %d %d %s %d %d",
                               p->nom, &la_classe, &p->HP, &p->str, &p->nbcomb,
                               &a1.attbonus, &a1.defbonus, &a1.HPbonus, a1.nom,
                               &a1.restbonus, &a1.strred, &a2.attbonus, &a2.defbonus,
                               &a2.HPbonus, a2.nom, &a2.restbonus, &a2.strred);

        if (nb_values < 17) { // Ajuster selon le format réel
            printf("Erreur : données mal formatées pour un personnage.\n");
            free(p->nom);
            free(p);
            free(perso);
            continue;
        }

        p->acc1 = (a1.attbonus || a1.defbonus || a1.HPbonus || a1.restbonus || a1.strred) ? (Accessoire *)malloc(sizeof(Accessoire)) : NULL;
        if (p->acc1) {
            *(p->acc1) = a1;
            printf("Accessoire ajouté : %s, att : %d, str : %d, rest : %d\n",
                   p->acc1->nom, p->acc1->attbonus, p->str, p->acc1->restbonus);
        }

        p->acc2 = (a2.attbonus || a2.defbonus || a2.HPbonus || a2.restbonus || a2.strred) ? (Accessoire *)malloc(sizeof(Accessoire)) : NULL;
        if (p->acc2) {
            *(p->acc2) = a2;
            printf("Accessoire ajouté : %s, att : %d, str : %d, rest : %d\n",
                   p->acc2->nom, p->acc2->attbonus, p->str, p->acc2->restbonus);
        }

        if (la_classe >= 0 && la_classe < 4) {
            p->classe = classe[la_classe];
        } else {
            printf("Classe invalide pour le personnage %s\n", p->nom);
            free(p->nom);
            free(p->acc1);
            free(p->acc2);
            free(p);
            free(perso);
            continue;
        }

        // Ajout au Sanitarium
        perso->personnage = p;
        ajouterDebutSanitarium(sanitarium, p);

        printf("Personnage ajouté : %s, Classe : %d, HP : %.2f, Stress : %d, Combats : %d\n",
               p->nom, la_classe, p->HP, p->str, p->nbcomb);
    }

    printf("Chargement terminé des personnages du sanitarium\n");
    rewind(fichier);
}



void Charger_accessoires_dispo(FILE *fichier, AccessoireDispo **tete) {
	/*
		charge les accessoires disponibles depuis un fichier
	*/
    if (fichier == NULL) {
        printf("Erreur : Fichier invalide.\n");
        exit(EXIT_FAILURE);
    }

    char ligne[255];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (ligne[0] != 'A') {
            continue; // Ignore les lignes qui ne commencent pas par 'A'
        }

        printf("Lecture de la ligne : %s", ligne);

        // Allocation pour un nouvel accessoire
        Accessoire *acc = (Accessoire *)malloc(sizeof(Accessoire));
        if (!acc) {
            printf("Erreur d'allocation pour Accessoire\n");
            exit(EXIT_FAILURE);
        }
        int nb_values = sscanf(ligne, "A %49s %d %d %d %d %d",
                               acc->nom, &acc->attbonus, &acc->defbonus, &acc->HPbonus,
                               &acc->restbonus, &acc->strred);

        if (nb_values < 6) {
            printf("Erreur : données mal formatées pour un accessoire.\n");
            free(acc);
            continue;
        }
        printf("Accessoire chargé : %s, attbonus : %d, defbonus : %d, hpbonus : %d, restbonus : %d, strred : %d\n",
               acc->nom, acc->attbonus, acc->defbonus, acc->HPbonus, acc->restbonus, acc->strred);

        ajouterDebutACC(tete, acc);
    }

    printf("Chargement terminé des accessoires disponibles.\n");
    rewind(fichier);
}




void Supprimer_jusqu_a_id(EnnemiVivant **liste, int id) {
	/*
		supprime les ennemis de la liste jusqu'a un certain ID
	*/
    if (!liste || !(*liste)) {
        printf("La liste est vide ou invalide.\n");
        return;
    }

    EnnemiVivant *courant = *liste;
    EnnemiVivant *precedent = NULL;

    // Parcourir la liste jusqu'à ce que l'ID soit trouvé
    while (courant != NULL) {
        if (courant->ennmi && courant->ennmi->niveau == id) {
            break;
        }

        // Supprimer l'élément courant
        precedent = courant;
        courant = courant->suivant;

        // Libérer la mémoire de l'élément précédent
        if (precedent->ennmi) {
            free(precedent->ennmi);
        }
        free(precedent);
    }

    // Si on a trouvé l'ID, mettre à jour la tête
    if (courant != NULL) {
        *liste = courant; // Le reste de la liste commence ici
        printf("Suppression terminée jusqu'à l'ID : %d\n", id);
    } else {
        *liste = NULL;
        printf("Aucun élément avec l'ID : %d. Liste entièrement supprimée.\n", id);
    }
}


int main() {
	/*
		fonction principale qui execute le jeu avec toutes les fonctionnalites implementees
	*/
    int p2, p4, p6, p8;
    char *accesoire[] = {
        "Katana",
        "Shield",
        "Bow",
        "Arrow Quiver",
        "Magic Staff",
        "Dagger",
        "Armor",
        "Helmet",
        "Boots",
        "Gloves"
    };

    Roulotte *roulotte = NULL;

    ajouterRoulotte(&roulotte, creerRoulotte("Katana", 10, 10, 5, 5, 5, 36, 7));
    ajouterRoulotte(&roulotte, creerRoulotte("Shield", 8, 8, 5, 5, 5, 32, 6));
    ajouterRoulotte(&roulotte, creerRoulotte("Magic Staff", 7, 7, 5, 8, 8, 28, 5));
    ajouterRoulotte(&roulotte, creerRoulotte("Helmet", 7, 5, 3, 3, 3, 24, 4));
    ajouterRoulotte(&roulotte, creerRoulotte("Boots", 4, 4, 2, 1, 1, 20, 3));
    ajouterRoulotte(&roulotte, creerRoulotte("Dagger", 4, 2, 1, 0, 2, 16, 2));
    ajouterRoulotte(&roulotte, creerRoulotte("Armor", 2, 2, 0, 0, 0, 8, 1));

    int or = 0;
    int chargement;
    printf("Est ce que vous voulez recharger le fichier sauvegarde.txt ? 1 oui 0 non : ");
    scanf(" %d", &chargement);
    srand(time(NULL));
    // liste des classes
    Classe *classe[4];
    // listes des personnages disponibles
    Perso_dispo *personnage_disponible = NULL;
    
    // liste des combattants
    Perso_dispo *personnage_combattant = NULL;
    // liste accessoire disponible
    AccessoireDispo *accessoire_disponible = NULL;
    // declarer le sanitarium
    Sanitarium *sanitarium = NULL;
    // declarer la traverne
    Taverne *traverne = NULL;
    // CREER LES DEUX COMBATTANT
    // initialiser les classes
    initClasses(classe);
    afficherClasses(classe);
    if(chargement == 0){
        // ajouter le premier personnage
        int deuxime_classe = rand() % 4;
        ajouter_personnage(classe, &personnage_disponible, deuxime_classe);
        do{
            deuxime_classe = rand() % 4;
        }while(personnage_disponible->perso->classe == classe[deuxime_classe]);
        // ajouter le deuxieme personname
        ajouter_personnage(classe, &personnage_disponible, deuxime_classe);
        // CREER LES DEUX ACCESSOIRES
        creer_start_accessoire(&accessoire_disponible);
        afficherListeAccessoires(accessoire_disponible);
    }
    printf("/-------------------------------------------------------------/\n");

    printf("/------------------------------------------------------------/\n");
    printf("D E B U T     D U     C O M B A T 1\n");
    // debut combat
    int nb_combat = 1;
    char nb_combattant1, nb_combattant2, nb_combattant3;

    afficherPersonnage(personnage_combattant);

// CREATE ENNEMIS
    EnnemiVivant *listeEnnemisVivants = NULL;

    // Création et ajout de 10 ennemis dans la liste
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Seigneur du Chaos", 10, 36, 35, 40, 40));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Démon", 9, 30, 30, 35, 30));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Chevalier Noir", 8, 25, 20, 30, 27));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Vampire", 7, 20, 17, 27, 25));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Sorcière", 6, 18, 13, 25, 23));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Dragonnet", 5, 20, 11, 20, 22));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Troll", 4, 18, 11, 18, 20));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Orque", 3, 15, 8, 16, 20));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Loup", 2, 14, 4, 13, 10));
    addEnnemiVivant(&listeEnnemisVivants, CreerEnnemi("Gobelin", 1, 10, 3, 9, 0));
    if(chargement == 1){
        FILE *fichier = fopen("sauvegarde.txt", "r");
        Charger_information_simples(fichier,&p2, &p4, &p6, &p8, &nb_combat, &or);
        Charger_personnages_disponibles(fichier, &personnage_disponible, classe);
        Charger_personnages_traverne(fichier, &traverne, classe);
        Charger_personnages_sanitarium(fichier, &sanitarium,classe);
        Charger_accessoires_dispo(fichier, &accessoire_disponible);
        Supprimer_jusqu_a_id(&listeEnnemisVivants, nb_combat);
        fclose(fichier);
    }
    afficherPersonnage(personnage_disponible);
    AfficherEnnemisVivants(listeEnnemisVivants);
    while (listeEnnemisVivants &&  personnage_disponible) {
        // afficher les personnages disponibles:
		printf("PERSONNAGE DISPONIBLE : \n");
        afficherPersonnage(personnage_disponible);
        printf("PERSONNAGE COMBATTANT : \n");
        afficherPersonnage(personnage_combattant);
        // DEMANDER DE CHOISIR LES COMBATTANTS
        printf("Choix du premier combattant : ");
        scanf(" %c", &nb_combattant1);  // Utilisation de %d pour saisir un caractère (et un espace avant %d pour gérer les retours à la ligne)

        // Si l'utilisateur entre 'N', il n'ajoute pas de combattant
        if (nb_combattant1 == 'N') {
            printf("Aucun premier combattant sélectionné.\n");
            nb_combattant1 = 0;  // Pas de combattant sélectionné
        } else {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
            Perso_dispo *p = ExtraireUnPersonnage(&personnage_disponible, nb_combattant1 - '0'); // Convertir le caractère en entier
            printf("ectraction ici : %s \t",p->perso->nom);
            ajouterDebutPerso(&personnage_combattant, p);
        }
        
        // afficher les personnages disponibles : 
        afficherPersonnage(personnage_disponible);
        printf("Choix du deuxieme combattant : ");
        scanf(" %c", &nb_combattant2);

        if (nb_combattant2 != 'N') {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
            Perso_dispo *p = ExtraireUnPersonnage(&personnage_disponible, nb_combattant2 - '0');
            ajouterDebutPerso(&personnage_combattant, p);


            if(nb_combat >=5){
                // afficher les personnages disponibles : 
                afficherPersonnage(personnage_disponible);

                printf("Choix du troiseme combattant : ");
                scanf(" %c", &nb_combattant3);

                if (nb_combattant3 == 'N') {
                    nb_combattant3 = 0;  // Aucun troisième combattant
                } else {
                    // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
                    p = ExtraireUnPersonnage(&personnage_disponible, nb_combattant3 - '0');
                    ajouterDebutPerso(&personnage_combattant, p);
                }
            }
            }
             else {
            nb_combattant2 = 0;
            nb_combattant3 = 0;
        }
        printf("/-------------------------------------------------------------------/\n");
        printf(" CHOISIR LES ACCESSOIRS: \n");

    // CHOISIR LES ACCESSOIRES
        int compteur = 1;
        char accessoire1;

        for(Perso_dispo *perso = personnage_combattant; perso != NULL; perso = perso->suivant){
            afficherListeAccessoires(accessoire_disponible);
            printf("Accessoire 1 pour le combattant %d : ", compteur);
            scanf(" %c", &accessoire1);
            if (accessoire1 != 'N')
            {
                // appliquer les caracteriqtique des accessoire
                AccessoireDispo *accessoire_temporaire = (AccessoireDispo *)ExtraireUnAccessoireParId(&accessoire_disponible, accessoire1 - '0');
                perso->perso->acc1 = accessoire_temporaire->accessoire;
                //ajouter_accessoire_features(&perso->perso, perso->perso->acc1);
                free(accessoire_temporaire);
                accessoire_temporaire = NULL;
                
            }
            afficherListeAccessoires(accessoire_disponible);
            printf("Accessoire 2 pour le combattant %d : ", compteur);
            scanf(" %c", &accessoire1);
            if (accessoire1 != 'N'){
                // appliquer les caracteriqtique des accessoire
                AccessoireDispo *accessoire_temporaire = (AccessoireDispo *)ExtraireUnAccessoireParId(&accessoire_disponible, accessoire1 - '0');
                perso->perso->acc2 = accessoire_temporaire->accessoire;
                //ajouter_accessoire_features(&perso->perso, perso->perso->acc2);
                free(accessoire_temporaire);
                accessoire_temporaire = NULL;
            }
            compteur++;
        }
        int tour = 1;
        while(personnage_combattant && listeEnnemisVivants){
        	printf("\n Tour numero : %d\n", tour);
            printf("\n/---------------------------/\n");
            afficherHPStr(personnage_combattant);
            printf("\n/---------------------------/\n");
            printf("ACTION DES COMBATTANTS\n");
            for(Perso_dispo *temporaire = personnage_combattant; temporaire != NULL; temporaire = temporaire->suivant){
                if(temporaire->perso->str < 100){
                    printf("%s est entrain de choisir : \n", temporaire->perso->nom);
                    printf("Veuillez choisir une action %s entre : attaquer (A), défendre (D), et restaurer (R)\n", temporaire->perso->nom);
                    scanf(" %c", &temporaire->action);
                    if(temporaire->action == 'A'){
                        float dommage;
                        int attb1, attb2;
                        if(temporaire->perso->acc1){
                            attb1 = temporaire->perso->acc1->attbonus;
                        }else{
                            attb1 = 0;
                        }
                        if(temporaire->perso->acc2){
                            attb2 = temporaire->perso->acc2->attbonus;
                        }else{
                            attb2 = 0;
                        }
                        int atttotal = temporaire->perso->att + attb1 + attb2;
                        if(atttotal - listeEnnemisVivants->ennmi->defenn > 0){
                            float roll = genererNombreAleatoireENTRE812(0.8, 1.2);
                            dommage = (atttotal - listeEnnemisVivants->ennmi->defenn) * roll;
                        }else{
                            dommage = 1;
                        }
                        listeEnnemisVivants->ennmi->HPenn = listeEnnemisVivants->ennmi->HPenn - dommage;
                        printf("Dommages à l'ennemi : %f , restants HP: %f\n", dommage, listeEnnemisVivants->ennmi->HPenn);
                        if(listeEnnemisVivants->ennmi->HPenn <= 0){
                            break;
                        }
                    }else if(temporaire->action == 'D'){
                        printf("\n");
                    }else if(temporaire->action == 'R'){
                        int joueur;
                        printf("\n Quel joueur restaurer, veuillez choisir ne pas choisir votre personnage actuel : \n");
                        afficherPersonnage(personnage_combattant);
                        scanf(" %d", &joueur);
                        Perso_dispo *p = obtenirPersonnage(personnage_combattant, joueur);
                        int rest1, rest2;
                        float resttotal;
                        if(temporaire->perso->acc1){
                            rest1 = temporaire->perso->acc1->restbonus;
                        }else{
                            rest1 = 0;
                        }
                        if(temporaire->perso->acc2){
                            rest2 = temporaire->perso->acc2->restbonus;
                        }else{
                            rest2 = 0;
                        }
                        printf("\n%d %d \n", rest1, rest2);
                        resttotal = temporaire->perso->rest + rest1 + rest2;
                        if(p->perso->HP + resttotal > p->perso->HPmax){
                            resttotal = p->perso->HPmax - p->perso->HP;
                        }
                        p->perso->HP += resttotal;
                        printf("\n %f restaurés à %s , %f HP sur %d\n", resttotal, p->perso->nom, p->perso->HP, p->perso->HPmax);
                    }else{
                        printf("Mauvaise action vous perdez votre tour\n");
                    }
                }
                
            }
            if(listeEnnemisVivants->ennmi->HPenn > 0){
                int actionEnnemi = rand()%10;
                printf(" \n action enemi %d\n", actionEnnemi);
                int joueurVise = 1 + rand() % (tailleListe(personnage_combattant) - 1);
                printf("joueur vise : %d\n", joueurVise);
                Perso_dispo *p = obtenirPersonnage(personnage_combattant, joueurVise);
                if(actionEnnemi < 5){
                    float roll = genererNombreAleatoireENTRE812(0.8, 1.2);
                    float deff = p->perso->def;
                    if(p->action == 'D')
                    {
                        deff = deff + deff * 0.1;
                    }
                    float dommage = (listeEnnemisVivants->ennmi->attenn - deff) * roll;
                    printf("dommage eneenmi %f\n", dommage);
                    p->perso->HP -= dommage;
                    printf("\nL'ennemi attaque %s pour %f , %s descend à %f HP\n", p->perso->nom, dommage, p->perso->nom, p->perso->HP);
                    if(p->perso->HP <= 0.0){
                        printf("\n il atteint les profendeurs du dongeon, \n");
                        printf("mais nous entendrons ses souffrances pour l'eternité\n");
                        supprimerPerso(&personnage_combattant, p);
                    }
                }else{
                    if(p->perso->str < 100){
                        float strtotal = 0;
                        if(p->perso->acc1){
                            strtotal += p->perso->acc1->strred;
                            }
                        if(p->perso->acc2){
                            strtotal = p->perso->acc2->strred;
                        }
                        float roll = genererNombreAleatoireENTRE812(0.8, 1.2);
                        p->perso->str = p->perso->str + (int)(listeEnnemisVivants->ennmi->attstrenn - strtotal) * roll;

                    }else{
                        printf("L'ennemi peut pas attaquer avec des attaques des du stress\n");
                    }
                }}
            else{
                supprimerEnnemi(&listeEnnemisVivants);
                break;
            }
            tour++;
        }
        printf("\nF I N       D U        C O M B A T \n");
        if(personnage_combattant == NULL){
            printf("\nVous avez Perdue..\n");
            break;
        }else if(listeEnnemisVivants == NULL){
            printf("\nVous avez Gagné..\n");
        }else{
            or += 10;
            printf("\nMontant Or total : %d\n", or);
            int att = rand()%10;
            int def = rand()%7;
            int hp = rand()% 7;
            int rest = rand()%7;
            int stress = rand()%10;
            int access = rand()%9;
            Accessoire *acc = (Accessoire *) malloc(sizeof(Accessoire)); 
            *acc = creerAccessoire(accesoire[access], att, def,hp, rest, stress);
            ajouterDebutACC(&accessoire_disponible, acc);
            printf("Nom : %s, att: %d, def : %d, HP: %d rest: %d, stred ! %d\n\n", acc->nom, acc->attbonus, acc->defbonus, acc->HPbonus, acc->restbonus, acc->strred);
        }
        // ajouter un personnage
        if(nb_combat == 2){
            p2 = rand()%4;
            ajouter_personnage(classe, &personnage_disponible, p2);
            afficherPersonnage1(personnage_disponible->perso);
        }else if(nb_combat == 4){
            do{
                p4 = rand() % 4;
            }while(p2 == p4);
            ajouter_personnage(classe, &personnage_disponible, p4);
            afficherPersonnage1(personnage_disponible->perso);

        }else if(nb_combat == 6){
            do{
                p6 = rand() % 4;
            }while(p6 == p2 || p6 == p4);
            ajouter_personnage(classe, &personnage_disponible, p6);
            afficherPersonnage1(personnage_disponible->perso);
        }else if(nb_combat == 8){
            do{
                p8 = rand() % 4;
            }while(p8 == p2 || p8 == p4 || p8 == p6);
            ajouter_personnage(classe, &personnage_disponible, p8);
            afficherPersonnage1(personnage_disponible->perso);
        }


        // reset les accessoires
        for(Perso_dispo *p=personnage_combattant;p != NULL;p = p->suivant){
            if(p->perso->acc1){
                ajouterDebutACC(&accessoire_disponible, p->perso->acc1);
                p->perso->acc1 = NULL;
            }
            if(p->perso->acc2){
                ajouterDebutACC(&accessoire_disponible, p->perso->acc2);
                p->perso->acc2 = NULL;
            }
            p->perso->nbcomb++;

        }


        // retirer des personnages de santarium
        afficherSanitarium(&sanitarium);
        int j = 1;
        for(Sanitarium *temp = sanitarium;temp != NULL && sanitarium != NULL;){
            int i ;
            printf("voulez vous retirer %s du sanitarium ? 1 si oui et 0 si non : \n", temp->personnage->nom);
            scanf(" %d", &i);
            if(i == 1){
                Sanitarium *s = ExtraireUnSanitarium(&sanitarium, j);
                Perso_dispo *nouveau = (Perso_dispo *)malloc(sizeof(Perso_dispo));
                if(nouveau == NULL) return 0;
                nouveau->perso = s->personnage;
                ajouterDebutPerso(&personnage_disponible, nouveau);
                free(s);
                temp =  sanitarium;
            }else{
                j++;
                temp = temp->suivant;
            }
        }

        // AJOUTER DES PERSONNAGES AU SANTARIUM
        
        afficherPersonnage(personnage_combattant);
        // DEMANDER DE CHOISIR LES COMBATTANTS
        printf("\nChoix du premier combattant a ajouté à SANTARIUM: ");
        scanf(" %c", &nb_combattant1);  // Utilisation de %d pour saisir un caractère (et un espace avant %d pour gérer les retours à la ligne)

        // Si l'utilisateur entre 'N', il n'ajoute pas de combattant
        if (nb_combattant1 == 'N') {
            printf("Aucun premier combattant sélectionné.\n");
            nb_combattant1 = 0;  // Pas de combattant sélectionné
        } else {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
            Perso_dispo *p = ExtraireUnPersonnage(&personnage_combattant, nb_combattant1 - '0'); // Convertir le caractère en entier
            printf("ectraction ici : %s \t",p->perso->nom);
            int reponse = ajouterDebutSanitarium(&sanitarium, p->perso);
            if(reponse)
                free(p);
            else 
                ajouterDebutPerso(&personnage_combattant, p);
        }
        
        // afficher les personnages combattants : 
        afficherPersonnage(personnage_combattant);
        printf("Choix du deuxieme combattant a ajouté à SANTARIUM: ");
        scanf(" %c", &nb_combattant2);

        if (nb_combattant2 != 'N') {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
             Perso_dispo *p = ExtraireUnPersonnage(&personnage_combattant, nb_combattant2 - '0'); // Convertir le caractère en entier
            printf("ectraction ici : %s \t",p->perso->nom);
            int reponse = ajouterDebutSanitarium(&sanitarium, p->perso);
            if(reponse)
                free(p);
            else 
                ajouterDebutPerso(&personnage_combattant, p);
        }

        // retirer des personnages de la traverne 

        afficherTaverne(&traverne);
        j = 1;
        for(Taverne *temp = traverne;temp != NULL && traverne != NULL;){
            int i ;
            printf("voulez vous retirer %s de la traverne ? 1 si oui et 0 si non : \n", temp->personnage->nom);
            scanf(" %d", &i);
            if(i == 1){
                Taverne *s = ExtraireUnTaverne(&traverne, j);
                Perso_dispo *nouveau = (Perso_dispo *)malloc(sizeof(Perso_dispo));
                if(nouveau == NULL) return 0;
                nouveau->perso = s->personnage;
                ajouterDebutPerso(&personnage_disponible, nouveau);
                free(s);
                temp =  traverne;
            }else{
                j++;
                temp = temp->suivant;
            }
        }

        // AJOUTER DES PERSONNAGES À LA TRAVERNE
        
        afficherPersonnage(personnage_combattant);
        // DEMANDER DE CHOISIR LES COMBATTANTS
        printf("\nChoix du premier combattant a ajouté à TRAVERNE: ");
        scanf(" %c", &nb_combattant1);  // Utilisation de %d pour saisir un caractère (et un espace avant %d pour gérer les retours à la ligne)

        // Si l'utilisateur entre 'N', il n'ajoute pas de combattant
        if (nb_combattant1 == 'N') {
            printf("Aucun premier combattant sélectionné.\n");
            nb_combattant1 = 0;  // Pas de combattant sélectionné
        } else {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
            Perso_dispo *p = ExtraireUnPersonnage(&personnage_combattant, nb_combattant1 - '0'); // Convertir le caractère en entier
            printf("ectraction ici : %s \t",p->perso->nom);
            int reponse = ajouterDebutTaverne(&traverne, p->perso);
            if(reponse)
                free(p);
            else 
                ajouterDebutPerso(&personnage_combattant, p);
        }
        
        // afficher les personnages combattants : 
        afficherPersonnage(personnage_combattant);
        printf("Choix du deuxieme combattant a ajouté à TRAVERNE: ");
        scanf(" %c", &nb_combattant2);

        if (nb_combattant2 != 'N') {
            // DEPLACER LE COMBATTANT DE LA LISTE PERSONNAGES DISPONIBLES DANS LA LISTE DES COMBATTANTS
             Perso_dispo *p = ExtraireUnPersonnage(&personnage_combattant, nb_combattant2 - '0'); // Convertir le caractère en entier
            printf("ectraction ici : %s \t",p->perso->nom);
            int reponse = ajouterDebutSanitarium(&sanitarium, p->perso);
            if(reponse)
                free(p);
            else 
                ajouterDebutPerso(&personnage_combattant, p);
        }


        // ROULOUTE
        afficherRoulottes(roulotte);
        char roloute = 'A';
        while(roloute != 'Q'){
            printf("OR : %d\n", or);
            printf("Achat : ");
            scanf(" %c", &roloute);
            if(roloute != 'Q'){
                Accessoire *c = (Accessoire *) malloc(sizeof(Accessoire));
                Roulotte r = rechercherRoulotteParId(roulotte, roloute - '0');
                *c = r.accessoire;
                ajouterDebutACC(&accessoire_disponible, c);
                or -= r.prix;
            }
        }


        // vider la liste des combattants
        for(;personnage_combattant != NULL;){
            Perso_dispo *p = ExtraireUnPersonnage(&personnage_combattant, 1);
            ajouterDebutPerso(&personnage_disponible, p);
        }
        tour = 1;
        nb_combat++;
        afficherListeAccessoires(accessoire_disponible);
        AfficherPersonnagesAvecAccessoires(personnage_combattant);
    }
            
    // LIBERATION DE LA MEMOIRE 
    libererRoulottes(roulotte);
    libererTraverne(traverne);
    libererSantarium(sanitarium);
    freeEnnemis(listeEnnemisVivants);
    libererAccessoires(accessoire_disponible);
    Free_personnage(personnage_disponible);
    Free_personnage(personnage_combattant);
    FreeClasses(classe);

    return 0;
}

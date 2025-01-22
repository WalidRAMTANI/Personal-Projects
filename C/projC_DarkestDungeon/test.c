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
    printf("/-----------------------------------------------------/\n");
    printf(" Nom : %s\n",p->nom);
    printf("Classe : %s, Att : %d, Déf : %d, HP/HPmax : %f/%d, Rest : %d, Stress : %d, NbComb : %d\n",
               p->classe->nom, p->att, p->def,
               p->HP, p->HPmax, p->rest,
                 p->str, p->nbcomb);
    
    printf("/-----------------------------------------------------/\n");

}


void afficherPersonnage(Perso_dispo *p) {
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
    printf("Nom : %s\n", acc.nom);
    printf("Bonus d'attaque : %d\n", acc.attbonus);
    printf("Bonus de défense : %d\n", acc.defbonus);
    printf("Bonus de points de vie : %d\n", acc.HPbonus);
    printf("Bonus de restauration : %d\n", acc.restbonus);
    printf("Réduction de stress : %d\n\n", acc.strred);
}

void afficherListeAccessoires(AccessoireDispo *l) {
    int i = 1;
    for (AccessoireDispo *p = l; p != NULL; p = p->suivant) {
        printf("%d ", i);
        i++;
        afficherAccessoire(*(p->accessoire));
    }
}



// ajouter personnage à une liste
void ajouterDebutPerso(Perso_dispo **liste, Perso_dispo *nouveau) {

    if (nouveau == NULL) {
        printf("personne est NULL, on n'ajoute rien, on quitte");
        return;
    }
    nouveau->suivant = *liste;
    *liste = nouveau;
    }



int tailleSanitarium(Sanitarium* liste) {
    int compteur = 0;
    while (liste != NULL) {
        compteur++;
        liste = liste->suivant; 
    }
    return compteur;
}



int ajouterDebutSanitarium(Sanitarium** liste, Personnage* nouveau) {
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
    (*perso)->att += acc1->attbonus ;
    (*perso)->def += acc1->defbonus ;
    (*perso)->HP += acc1->HPbonus;
    (*perso)->HPmax += acc1->HPbonus;
    (*perso)->rest += acc1->restbonus;
    (*perso)->str += acc1->strred;
}


Ennemi *CreerEnnemi(const char *nom, int niveau, int attenn, int defenn, int HPenn, int attstrenn) {
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
    free(e);
}

// Function to create an EnnemiVivant element
EnnemiVivant *createEnnemiVivant(Ennemi *ennmi) {
    EnnemiVivant *element = (EnnemiVivant *)malloc(sizeof(EnnemiVivant));
    element->ennmi = ennmi;
    element->suivant = NULL;
    return element;
}

// Function to add an EnnemiVivant to the list
void addEnnemiVivant(EnnemiVivant **head, Ennemi *ennmi) {
    EnnemiVivant *element = createEnnemiVivant(ennmi);
    element->suivant = *head;
    *head = element;
}


void freeEnnemis(EnnemiVivant *head) {
    EnnemiVivant *current = head;
    while (current != NULL) {
        EnnemiVivant *temp = current;
        current = current->suivant;
        freeEnnemi(temp->ennmi);
        free(temp);
    }
}


void AfficherEnnemisVivants(EnnemiVivant *head) {
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
    printf("RANDOM %f\n", min + (rand() / (RAND_MAX + 1.0)) * (max - min));
    return min + (rand() / (RAND_MAX + 1.0)) * (max - min);      // Scales it to the desired range
}


// Fonction pour calculer la taille de la liste chaînée
int tailleListe(Perso_dispo *liste) {
    int taille = 0;
    Perso_dispo *perso = liste;

    while (perso != NULL) {
        taille++;               // Incrémenter le compteur
        perso = perso->suivant; // Passer au perso suivant
    }

    return taille;               // Retourner le nombre de personnage
}


void supprimerPerso(Perso_dispo **liste, Perso_dispo *Supprimer) {
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
    if (*liste == NULL) {
        return;
    }

    EnnemiVivant *Supprimer = *liste;    
    *liste = (*liste)->suivant;          
    free(Supprimer->ennmi);            
    free(Supprimer); 
}


void afficherSanitarium(Sanitarium **sant) {
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
    int compteur = 0;
    while (liste != NULL) {
        compteur++;
        liste = liste->suivant;
    }
    return compteur;
}


int ajouterDebutTaverne(Taverne** liste, Personnage* nouveau) {
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
    if (*liste == NULL) {
        *liste = nouveau;
    } else {
        nouveau->suivant = *liste;
        *liste = nouveau;
    }
}

void afficherRoulottes(Roulotte *liste) {
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
    Roulotte *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }
}



Roulotte rechercherRoulotteParId(Roulotte *liste, int id) {
    while (liste != NULL) {
        if (liste->numero == id) {
            break;
        }
        liste = liste->suivant;
    }
    return *liste;

}



Personnage *ajouter_per(Perso_dispo *p, Classe **classe, int num){
    p->perso->classe = classe[num];
    p->perso->att = p->perso->classe->att;
    p->perso->def = p->perso->classe->def;
    p->perso->HPmax = p->perso->classe->HPmax;
    p->perso->rest = p->perso->classe->rest;
    return p;
}


void Charger_information_simples(FILE *fichier ,int *p2, int *p4, int *p6, int *p8, int *nb_combat, int *or){
    if(fichier == NULL) exit(EXIT_FAILURE);
    fscanf(fichier, "%d %d %d %d %d %d\n", nb_combat, p2, p4, p6, p8, or);
    printf("%d %d %d %d %d %d\n", *nb_combat, *p2, *p4, *p6, *p8, *or);
}
void Charger_personnages_disponibles(FILE *fichier, Perso_dispo **personnage_disponible, Classe **classe) {
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : Fichier invalide.\n");
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
                perror("Erreur d'allocation pour Perso_dispo");
                exit(EXIT_FAILURE);
            }

            Personnage *p = (Personnage *)malloc(sizeof(Personnage));
            if (p == NULL) {
                perror("Erreur d'allocation pour Personnage");
                free(perso);
                exit(EXIT_FAILURE);
            }

            p->nom = (char *)malloc(50 * sizeof(char)); // Allouer pour le nom
            if (p->nom == NULL) {
                perror("Erreur d'allocation pour le nom du personnage");
                free(p);
                free(perso);
                exit(EXIT_FAILURE);
            }

            // Lecture des données du personnage
            int la_classe;
            int nb_values = sscanf(ligne, "P %49s %d %f %d %d", p->nom, &la_classe, &p->HP, &p->str, &p->nbcomb);
            if (nb_values != 5) {
                fprintf(stderr, "Erreur : données mal formatées pour un personnage.\n");
                free(p->nom);
                free(p);
                free(perso);
                continue;
            }

            printf("Personnage lu : %s, Classe : %d, HP : %.2f, Stress : %d, Combats : %d\n",
                   p->nom, la_classe, p->HP, p->str, p->nbcomb);

            // Initialisation des accessoires
            p->acc1 = NULL;
            p->acc2 = NULL;

            // Lier la classe au personnage
            if (la_classe >= 0 && la_classe < 4) {
                p->classe = classe[la_classe];
            } else {
                fprintf(stderr, "Classe invalide pour le personnage %s\n", p->nom);
                free(p->nom);
                free(p);
                free(perso);
                continue;
            }

            // Lier le personnage à la liste des disponibles
            perso->perso = p;
            p =  ajouter_per(perso, classe, la_classe);
            ajouterDebutPerso(personnage_disponible,perso);
            afficherPersonnage(*personnage_disponible);
        }
    }
    printf("Chargement terminé des personnages disponibles.\n");
    rewind(fichier);
}



void Charger_personnages_traverne(FILE *fichier, Taverne **traverne, Classe **classe) {
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
}





void libererTraverne(Taverne *liste) {
    Taverne *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp->personnage);
        free(temp);
    }
}



void libererSantarium(Sanitarium *liste) {
    Sanitarium *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp->personnage);
        free(temp);
    }
}






void Charger_personnages_sanitarium(FILE *fichier, Sanitarium **sanitarium, Classe **classe) {
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




int main() {
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
    afficherPersonnage(personnage_disponible);
    int nb_combat;
    FILE *fichier = fopen("sauvegarde.txt", "r");
    Charger_information_simples(fichier,&p2, &p4, &p6, &p8, &nb_combat, &or);
    Charger_personnages_disponibles(fichier, &personnage_disponible, classe);
    afficherPersonnage(personnage_disponible);
    printf("traverbe \n");
    Charger_personnages_traverne(fichier, &traverne, classe);
    afficherTaverne(&traverne);
    rewind(fichier);
    Charger_personnages_sanitarium(fichier, &sanitarium,classe);
    afficherSanitarium(&sanitarium);
    rewind(fichier);
    Charger_accessoires_dispo(fichier, &accessoire_disponible);
    afficherListeAccessoires(accessoire_disponible);
    fclose(fichier);
    libererRoulottes(roulotte);
    libererTraverne(traverne);
    libererSantarium(sanitarium);
    libererAccessoires(accessoire_disponible);
    Free_personnage(personnage_disponible);
    Free_personnage(personnage_combattant);
    FreeClasses(classe);
}




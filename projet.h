#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  //Constitue la structure de l'élément Cité.
{
    char nom[30];   //Nom de la cité (ex: Dolet).
    char adresse[30];   //Adresse de la cité (ex: 10 Boulevard Paul Locher Lagaye).
    int refcite;   //Référence de la cité (ex: 100).
	int chambre; //Nombre de chambre disponibiles.
	int studio; //Nombre de studio disponibiles.
	int T1; //Nombre de studio disponibiles.
	int T2; //Nombre de studio disponibiles.
} Cite;

typedef struct  //Constitue la structure de l'élément Logement.
{
    char ref[5];    //Référence du logement (Le premier chiffre donne la cité, la lettre donne le bâtiment de la cité, le chiffre suivant l'étage et les 2 derniers le numéro de la chambre). On ne prend pas en compte des bâtiments de plus de 9 étages.
    int handicap;    //Permet de savoir si une chambre permet d'accueillir un handicapé (ex: 1 pour Oui et 0 pour Non).
    int etat;   //Permet de savoir l'état d'une chambre (ex: 0 pour Libre, 1 pour Occupé et 2 pour En Travaux).
	char type[2];   //Type de logement demandé (ex: C pour Chambre, S pour Studio T1 et T2).
} Logement;

typedef struct  //Constitue la structure de l'élément Etudiant.
{
    char nom[20];   //Nom de l'étudiant (ex: Dupont).
    char prenom[20];    //Prénom de l'étudiant (ex: Arthur).
	int refetud; //Numéro d'étudiant. 
   int bourse; //Echelon de la bourse de l'étudiant (De 0 à 7 ou -1 si l'étudiant n'a pas le droit aux bourses).
    int handicap;  //Permet de savoir si un étudiant est handicpé ou non (ex: 1 pour Oui et 0 pour Non).
    char refchamb[5];  // Référence de la chambre qu'occupe l'étudiant (ex: 1A001)

typedef struct  //Constitue la structure de l'élément Demande.
{
    Etudiant etud;   //est constitué de la structure étudiant.
	int ordre;		//Ordre dans lequel l'étudiant a créé sa demande.
    int refcite;   //Référence de la cité demandée par l'étudiant (ex: 1).
    char type[2];   //Type de logement demandé (ex: C pour Chambre, S pour Studio, T1 et T2).
} Demande;

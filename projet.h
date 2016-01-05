#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  //Constitue la structure de l'élément Cité.
{
    char nom[30];   //Nom de la cité (ex: Dollet).
    char adresse[30];   //Adresse de la cité (ex: 10 Boulevard Paul Locher Lagaye).
    char ville[30];    //Ville de la cité (ex: Aubière).
    int ref;   //Référence de la cité (ex: 100).
	int nblogement //Nombre de logements dont la cité dispose.
} cite;

typedef struct
{
	char bat; //Référence du batiment.
	int etage; //Référence l'étage.
	int numero; //Référence le numéro de la chambre.
}chambre;

typedef struct  //Constitue la structure de l'élément Logement.
{
    char ref[4];    //Référence du logement (Première lettre donne la cité, le chiffre suivant l'étage et les 2 derniers le numéro de la chambre).
    int handicap;    //Permet de savoir si une chambre permet d'accueillir un handicapé (ex: 1 pour Oui et 0 pour Non).
    int etat;   //Permet de savoir l'état d'une chambre (ex: 0 pour Libre, 1 pour Occupé et 2 pour En Travaux).
} logement;

typedef struct  //Constitue la structure de l'élément date que l'on utilise dans la structure de Etudiant.
{
    int jour;   //Jour de naissance (ex: 03).
    int mois;   //Mois de naissance (ex: 01).
    int annee;  //Annee de naissance (ex: 1997).
} date;

typedef struct  //Constitue la structure de l'élément Etudiant.
{
    char nom[20];   //Nom de l'étudiant (ex: Dupont).
    char prenom[20];    //Prénom de l'étudiant (ex: Arthur).
    date naissance; //est constitué de l'élement Date (ex: 03/01/1997).
    int bourse; //Echelon de la bourse de l'étudiant (De 1 à 7 ou 0 si l'étudiant n'a pas le droit aux bourses).
    int handicap;  //Permet de savoir si un étudiant est handicpé ou non (ex: 1 pour Oui et 0 pour Non).
    char etude[30];    //Permet de savoir quelles études réalisent l'étudiant (ex: DUT Informatique).
    char refchamb[4];  // Référence de la chambre qu'occupe l'étudiant (ex: A001 ou 0 s'il n'a pas encore de chambre).
} etudiant;

typedef struct  //Constitue la structure de l'élément Demande.
{
    etudiant etud;   //est constitué de la structure étudiant.
    char refcite[20];   //Référence de la cité demandée par l'étudiant (ex: Dolet).
    char type[2];   //Type de logement demandé (ex: C pour Chambre, S pour Studio T1 et T2).
} demande;

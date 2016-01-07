#include "projet.h"

Cite lirecite(FILE *flot)
{
Cite c;
fgets(c.nom,30,flot);
c.nom[strlen(c.nom)-1]='\0';
fgets(c.adresse,30,flot);
c.adresse[strlen(c.adresse)-1]='\0';
fscanf(flot,"%d\n%d\n\n%d\n%d\n%d",&c.refcite,&c.chambre,&c.studio,&c.T1,&c.T2);
return c;
}

int chargefcite(char *nomfichier,Cite *tcite[])
{
int n=0;
Cite c;
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier cite.don"); return -1;}
c=lirecite(fe);
while (feof(fe)==0)
	{
    tcite[n]=(Cite*)malloc(sizeof(Cite));
    if(tcite==NULL){printf("\n Probleme malloc");return -1;}
	*tcite[n]=c;
	c=lirecite(fe);
	n++;
	}
fclose(fe);
return n;
}

void affichecite(Cite **cite,int nbcite)
{
int i;
printf("******Affichage des cités******\n");
for(i=0;i<nbcite;i++)
    {
    printf("%s \n%s \n%d \n%d \n%d \n%d \n%d \n",cite[i]->nom,cite[i]->adresse,cite[i]->refcite,cite[i]->chambre,cite[i]->studio,cite[i]->T1,cite[i]->T2);
    }
}

Etudiant lireetudiant(FILE *flot)
{
Etudiant e;
fscanf(flot,"%d",&e.refetud);
fgets(e.nom,20,flot);
e.nom[strlen(e.nom)-1]='\0';
fgets(e.prenom,20,flot);
e.prenom[strlen(e.prenom)-1]='\0';
fscanf(flot,"%d \n%d",&e.bourse,&e.handicap);
fgets(e.refchamb,4,flot);
e.refchamb[strlen(e.refchamb)-1]='\0';
return e;
}

int chargeetudiant(char *nomfichier,Etudiant *tetu[])
{
int n=0;
Etudiant e;
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier etudiant.don"); return -1;}
e=lireetudiant(fe);
while (feof(fe)==0)
	{
    tetu[n]=(Etudiant*)malloc(sizeof(Etudiant));
    if(tetu==NULL){printf("\n Probleme malloc");return -1;}
	*tetu[n]=e;
	e=lireetudiant(fe);
	n++;
	}
fclose(fe);
return n;
}

void afficheetudiant(Etudiant **etu,int nbetud)
{
int i;
printf("******Affichage des étudiants******\n");
for(i=0;i<nbetud;i++)
    {
    printf("%d \n%s \n%s \n%d \n%d \n%s \n",etu[i]->refetud,etu[i]->nom,etu[i]->prenom,etu[i]->bourse,etu[i]->handicap,etu[i]->refchamb);
    }
}

int menu(void)
{int i;
printf("\nMenu :");
printf("\n1)Charger et afficher les cités.");
printf("\n2)Charger et afficher les étudiants.");
printf("\n0)Quitter.");
printf("\nQue voulez-vous faire :");
scanf("%d",&i);
return i;
}

void global(void)
{
int m,nbcite,nbetud;
Cite *tresidence[100];
Etudiant *tetud[100];
m=menu();
while (m!=0)
	{
	if (m==1)
		{nbcite=chargefcite("cite.don",tresidence);
		affichecite(tresidence,nbcite);
		}
	if (m==2)
		{nbetud=chargeetudiant("etudiant.don",tetud);
		afficheetudiant(tetud,nbetud);
		}
	m=menu();
	}
return;
}

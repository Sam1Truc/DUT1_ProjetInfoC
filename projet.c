#include "projet.h"

/***********************************************************************************************/

Cite lirecite(FILE *flot)
{
Cite c;
fgets(c.nom,30,flot);
c.nom[strlen(c.nom)-1]='\0';
fgets(c.adresse,30,flot);
c.adresse[strlen(c.adresse)-1]='\0';
fscanf(flot,"%d %d %d %d %d",&c.refcite,&c.C,&c.S,&c.T1,&c.T2);
return c;
}

int chargefcite(char *nomfichier,Cite *tcite[])
{
int n=0;
Cite c;
char line[80];
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier cite.don"); return -1;}
c=lirecite(fe);
while (fgets(line,80,fe) != NULL)
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
    printf("Nom: %s \nAdresse: %s \nRéférence de la cité: %d \nNb de chambre dispo: %d \nNb de studios dispo: %d \nNb de T1 dispo: %d \nNb de T2 dispo: %d\n\n",cite[i]->nom,cite[i]->adresse,cite[i]->refcite,cite[i]->C,cite[i]->S,cite[i]->T1,cite[i]->T2);
    }
}

/***********************************************************************************************/

Etudiant lireetudiant(FILE *flot)
{
Etudiant e;
fgets(e.nom,20,flot);
e.nom[strlen(e.nom)-1]='\0';
fgets(e.prenom,20,flot);
e.prenom[strlen(e.prenom)-1]='\0';
fscanf(flot,"%d %d %d %s",&e.refetud,&e.bourse,&e.handicap,e.refchamb);
return e;
}

int chargeetudiant(char *nomfichier,Etudiant *tetu[])
{
int n=0;
Etudiant e;
char line[80];
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier etudiant.don"); return -1;}
e=lireetudiant(fe);
while (fgets(line,80,fe) != NULL)
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
    printf("Nom: %s\nPrénom: %s\nRef : %d\nBourse/Handicap/Refchambre : %d/%d/%s\n\n",etu[i]->nom,etu[i]->prenom,etu[i]->refetud,etu[i]->bourse,etu[i]->handicap,etu[i]->refchamb);
    }
}

/***********************************************************************************************/
Demande liredemande(FILE *flot)
{Demande d;
int ref;
d.etud=lireetudiant(flot);
fscanf(flot,"%d %d %s",&d.ordre,&ref,d.type);
d.refcite=ref+'0';
return d;
}

int chargedemande(char *nomfichier,Demande *tdem[])
{
int n=0;
Demande dem;
char line[80];
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier demande.don"); return -1;}
dem=liredemande(fe);
while (fgets(line,80,fe) != NULL)
	{
    tdem[n]=(Demande*)malloc(sizeof(Demande));
    if(tdem==NULL){printf("\n Probleme malloc");return -1;}
	*tdem[n]=dem;
	dem=liredemande(fe);
	n++;
	}
fclose(fe);
return n;
}

void affichedemande(Demande **dem,int nbdem)
{
int i;
printf("******Affichage des demandes******\n");
for(i=0;i<nbdem;i++)
    {
    printf("Nom: %s\nPrénom: %s\nRef : %d\nBourse/Handicap : %d / %d \nOrdre de demande : %d \nRéf Cité demandée: %c \nType Logement demandé : %s\n\n",dem[i]->etud.nom,dem[i]->etud.prenom,dem[i]->etud.refetud,dem[i]->etud.bourse,dem[i]->etud.handicap,dem[i]->ordre,dem[i]->refcite,dem[i]->type);
    }
}

/***********************************************************************************************/

void Permute(Demande **t,int i,int j)
{Demande *temp;
temp=t[i];
t[i]=t[j];
t[j]=temp;
}

void tridemande(Demande **t,int n)
{int i,k;
for(k=1;k<n;k++)
 for(i=n-1;i>=k;i--)
	{if(t[i]->etud.handicap>t[i-1]->etud.handicap)
		Permute(t,i,i-1);
	if(t[i]->etud.handicap==t[i-1]->etud.handicap && t[i]->etud.bourse>t[i-1]->etud.bourse)
		Permute(t,i,i-1);
	if(t[i]->etud.bourse==t[i-1]->etud.bourse && t[i]->ordre<t[i-1]->ordre)
		Permute(t,i,i-1);
	}
}
/***********************************************************************************************/
Logement lirelogement(FILE *flot)
{Logement l;
fscanf(flot,"%s %d %d %s",l.ref,&l.handicap,&l.etat,l.type);
return l;
}

int chargelogement(char *nomfichier,Logement *tlog[])
{
int n=0;
Logement log;
char line[80];
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier logement.don"); return -1;}
log=lirelogement(fe);
while (fgets(line,80,fe) != NULL)
	{
    tlog[n]=(Logement*)malloc(sizeof(Logement));
    if(tlog==NULL){printf("\n Probleme malloc");return -1;}
	*tlog[n]=log;
	log=lirelogement(fe);
	n++;
	}
fclose(fe);
return n;
}

void affichelogement(Logement **log,int nblog)
{
int i;
printf("******Affichage des logements******\n");
for(i=0;i<nblog;i++)
    {
    printf("Référence cité: %c\nRéférence logement: %s\nHandicap : %d\nEtat : %d \nType logement : %s \n\n",(*log[i]).ref[0],log[i]->ref,log[i]->handicap,log[i]->etat,log[i]->type);
    }
}

/***********************************************************************************************/
Etudiant chargeetudemande(char *nom,char *prenom,int refetud,int bourse,int handicap,char *refchamb)
{Etudiant e;

strcpy(e.nom,nom);
strcpy(e.prenom,prenom);
e.refetud=refetud;
e.bourse=bourse;
e.handicap=handicap;
strcpy(e.refchamb,refchamb);

return e;
}

/***********************************************************************************************/

int attribution(Cite **tcite,Logement **tlog,Etudiant **tetud,Demande **tdem,int nbdem, int nblog)
{//On charge au préalable les tableaux par l'action du menu (sauf tetud que l'on va remplir maintenant).
int i,j,n,nbetud=0;
Etudiant e;

//On doit utiliser le tableau étudiant et ne pas rentrer en brut dans le fichier étudiant.
//Utiliser suppression de la demande quand on trouve un logement et afficher via une autre boucle les demandes restantes mises en attente.
FILE *fs;
fs=fopen("etudiant.don","w");
for (i=0;i<nbdem;i++)
	{
	for(j=0;j<nblog;j++)
		{if ((tdem[i]->etud.handicap==tlog[j]->handicap) && (strcmp(tdem[i]->type,tlog[j]->type)==0) && (tdem[i]->refcite==(*tlog[j]).ref[0]) && (tlog[j]->etat==0))
			{tlog[j]->etat=1;
			tetud[nbetud]=(Etudiant*)malloc(sizeof(Etudiant));
    		if(tlog==NULL){printf("\n Probleme malloc");return -1;}
			*tetud[nbetud]=chargeetudemande(tdem[i]->etud.nom,tdem[i]->etud.prenom,tdem[i]->etud.refetud,tdem[i]->etud.bourse,tdem[i]->etud.handicap,tlog[j]->ref);
			nbetud++;
			printf("\n%s %s a obtenu un logement: %s",tdem[i]->etud.nom,tdem[i]->etud.prenom,tlog[j]->ref);
//fonction suppression de de la demande i du tab demande(cf fonctions ci-dessous à adapter)
			}
		}

for (i=0;i<nbdem;i++)
		printf("\n%s %s n'a pas obtenu de logement.",tdem[i]->etud.nom,tdem[i]->etud.prenom);
	}
printf("\n\n");
fclose(fs);
return nbetud;
}



/***********************************************************************************************/

int rechdich(char *code,Article **tart,int nbart)
{
int deb=0,m,fin;
fin=nbart-1;
while (deb<=fin)
	{
	m=(deb+fin)/2;
	if (strcmp(code,tart[m]->ref)<0)
		fin=m-1;
	else
		deb=m+1;
	}
return deb;
}

/***********************************************************************************************/

int supprime(Article **tArtt,int nbart)
{int r,i;
char ref[6],rep[3];

printf("Saisir la référence à supprimer :");
scanf("%s",ref);
r=rechdich(ref,tArtt,nbart);
r=r-1;
printf("\nLa désignation de l'article est : %s",tArtt[r]->des);
printf("\nConfirmez-vous cette suppression ? Tapez Oui ou Non :");
scanf("%s",rep);
if (strcmp(rep,"Oui")==0)
	{free(tArtt[r]);
	for(i=r;i<nbart;i++)
		tArtt[i]=tArtt[i+1];
	nbart--;
	}
if (strcmp(rep,"Non")==0)
	printf("\nSuppression annulée !");
return nbart;
}

/***********************************************************************************************/
int menu(void)
{int i;
printf("Menu :");
printf("\n1)Charger et afficher les cités.");
printf("\n2)Charger,trier et afficher les demandes.");
printf("\n3)Charger et afficher les logements.");
printf("\n4)Attribuer les logements.");
printf("\n5)Afficher le tableau des étudiants.");
printf("\n0)Quitter.");
printf("\nQue voulez-vous faire :");
scanf("%d",&i);
return i;
}

void global(void)
{
system("clear");
int m,nbcite,nbetud,nbdem,nblog;
Cite *tresidence[100];
Etudiant *tetudiant[100];
Demande *tdemande[100];
Logement *tlogement[100];
m=menu();
while (m!=0)
	{
	if (m==1)
		{nbcite=chargefcite("cite.don",tresidence);
		affichecite(tresidence,nbcite);
		}
	if (m==2)
		{nbdem=chargedemande("demande.don",tdemande);
		tridemande(tdemande,nbdem);
		affichedemande(tdemande,nbdem);
		}
	if (m==3)
		{nblog=chargelogement("logement.don",tlogement);
		affichelogement(tlogement,nblog);
		}
	if (m==4)
		{
		nbcite=chargefcite("cite.don",tresidence);
		nbdem=chargedemande("demande.don",tdemande);
		tridemande(tdemande,nbdem);
		nblog=chargelogement("logement.don",tlogement);
		nbetud=attribution(tresidence,tlogement,tetudiant,tdemande,nbdem,nblog);
		}
	if (m==5)
		{
		afficheetudiant(tetudiant,nbetud);
		}
	m=menu();
	}
system("clear");
return;
}

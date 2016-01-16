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

void PermuteDem(Demande **t,int i,int j)
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
		PermuteDem(t,i,i-1);
	if(t[i]->etud.handicap==t[i-1]->etud.handicap && t[i]->etud.bourse>t[i-1]->etud.bourse)
		PermuteDem(t,i,i-1);
	if(t[i]->etud.bourse==t[i-1]->etud.bourse && t[i]->ordre<t[i-1]->ordre)
		PermuteDem(t,i,i-1);
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

void affichelogementdispo(Logement **log,int nblog)
{
int i;
printf("******Affichage des logements disponibles******\n");
for(i=0;i<nblog;i++)
    {if (log[i]->etat==0)
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

int attribution(Cite **tcite,Logement **tlog,Etudiant **tetud,Demande **tdem,int nbdem, int nblog,int *nbetu)
{int i,j,n,nbsuppr=0,tsuppr[100],nbetud=*nbetu;
Etudiant e;

FILE *fs;
fs=fopen("etudiant.don","w");
for (i=0;i<nbdem;i++)
	{
	for(j=0;j<nblog;j++)
		{if ((tdem[i]->etud.handicap==tlog[j]->handicap) && (strcmp(tdem[i]->type,tlog[j]->type)==0) && (tdem[i]->refcite==(*tlog[j]).ref[0]) && (tlog[j]->etat==0))
			{tlog[j]->etat=1;

			tetud[nbetud]=(Etudiant*)malloc(sizeof(Etudiant));
    		if(tetud[nbetud]==NULL){printf("\n Probleme malloc");return -1;}

			*tetud[nbetud]=chargeetudemande(tdem[i]->etud.nom,tdem[i]->etud.prenom,tdem[i]->etud.refetud,tdem[i]->etud.bourse,tdem[i]->etud.handicap,tlog[j]->ref);
			nbetud++;
			printf("\n%s %s a obtenu un logement: %s",tdem[i]->etud.nom,tdem[i]->etud.prenom,tlog[j]->ref);

			tsuppr[nbsuppr]=tdem[i]->etud.refetud;
			nbsuppr++;	
			break;	
			}
		}

	}
*nbetu=nbetud;
//fonction suppression de de la demande i du tab demande(cf fonctions ci-dessous à adapter)
for (i=0;i<nbsuppr;i++)
	{nbdem=supprdemande(tdem,nbdem,tsuppr[i]);}

for (i=0;i<nbdem;i++)
		printf("\n%s %s n'a pas obtenu de logement.",tdem[i]->etud.nom,tdem[i]->etud.prenom);
printf("\n\n");
fclose(fs);
return nbdem;
}



/***********************************************************************************************/

int rech(int ref,Demande **tdem,int nbdem)
{
int i;
for (i=0;i<nbdem;i++)
	if(ref==tdem[i]->etud.refetud) return i;
return -1;
}

/***********************************************************************************************/

int supprdemande(Demande **tdem,int nbdem,int refetud)
{int r,i;

r=rech(refetud,tdem,nbdem);
if (r==-1){printf("\nRéférence étudiant inconnue.");return nbdem;}
printf("\nLa référence de l'étudiant supprimé est : %d",tdem[r]->etud.refetud);
free(tdem[r]);
for(i=r;i<nbdem;i++)
	{tdem[i]=tdem[i+1];
	}
nbdem--;
return nbdem;
}

/***********************************************************************************************/
Demande lireinsertdem(int ordre,int refetud)
{Demande d;
int refcite;
printf("Entrer le nom de l'étudiant à insérer :");
scanf("%s",d.etud.nom);
printf("Entrer le prénom de l'étudiant à insérer :");
scanf("%s",d.etud.prenom);
d.etud.refetud=refetud;
printf("Entrer l'échelon de bourse de l'étudiant :");
scanf("%d",&d.etud.bourse);
printf("Entrer l'état d'handicap de l'étudiant (0 ou 1) :");
scanf("%d",&d.etud.handicap);
strcpy(d.etud.refchamb,"0");
d.ordre=ordre;
printf("Entrer la référence de la cité demandée par l'étudiant :");
scanf("%d",&refcite);
d.refcite=refcite+'0';
printf("Entrer le type de logement demandé par l'étudiant :");
scanf("%s",d.type);

return d;
}
/***********************************************************************************************/

int insertion(char *nom,int nbdem,Demande **tdem,Etudiant **tetu,int nbetu)
{int i,j,ordre,ref;
Demande dem;
ref=tdem[0]->etud.refetud;
ordre=tdem[0]->ordre;
for (i=1;i<nbdem;i++)
	{if (ordre<tdem[i]->ordre)
		ordre=tdem[i]->ordre;
	if(ref<tdem[i]->etud.refetud)
		ref=tdem[i]->etud.refetud;
	}
for (j=0;j<nbetu;j++)
	if (ref<tetu[j]->refetud)
		ref=tetu[j]->refetud;
	
ref++;	
ordre++;
dem=lireinsertdem(ordre,ref);
tdem[nbdem]=(Demande*)malloc(sizeof(Demande));
if(tdem[nbdem]==NULL){printf("\n Probleme malloc");return nbdem;}
*tdem[nbdem]=dem;
nbdem++;

return nbdem;
}
/***********************************************************************************************/
void sauveetudiant(Etudiant **t,int nb)
{int i;
FILE *fs;
fs=fopen("etudiant.don","w");
for (i=0;i<nb;i++)
	fprintf(fs,"%s\n%s\n%d\n%d %d %s\n",t[i]->nom,t[i]->prenom,t[i]->refetud,t[i]->bourse,t[i]->handicap,t[i]->refchamb);
printf("Fichier etudiant.don sauvegardé.\n");
fclose(fs);
return;
}

void sauvelogement(Logement **t,int nb)
{int i;
FILE *fs;
fs=fopen("logement.don","w");
for (i=0;i<nb;i++)
	fprintf(fs,"%s %d %d %s\n",t[i]->ref,t[i]->handicap,t[i]->etat,t[i]->type);
printf("Fichier logement.don sauvegardé.\n");
fclose(fs);
return;
}

void sauvedemande(Demande **t,int nb)
{int i;
FILE *fs;
fs=fopen("demande.don","w");
for (i=0;i<nb;i++)
	fprintf(fs,"%s\n%s\n%d\n%d %d %s\n%d %c %s\n",t[i]->etud.nom,t[i]->etud.prenom,t[i]->etud.refetud,t[i]->etud.bourse,t[i]->etud.handicap,t[i]->etud.refchamb,t[i]->ordre,t[i]->refcite,t[i]->type);
printf("Fichier demande.don sauvegardé.\n");
fclose(fs);
return;
}
/***********************************************************************************************/

int supprEtu(Etudiant **tEtu,Logement **tLog, int nbetu,int refetud,int nbLog)
{
int a=-1,b=-1,i,d;
for (i=0;i<nbetu;i++)
	if(refetud==tEtu[i]->refetud){b=i;}
if(b==-1){printf("\nRéférence non existante\n");return nbetu;}
for (i=0;i<nbLog;i++)
	if(strcmp(tEtu[b]->refchamb,tLog[i]->ref)==0){a=i;}
if(a==-1){printf("\nErreur référence chambre\n");return nbetu;}
tLog[a]->etat=0;
printf("\nL'étudiant dont la référence est %d va être supprimé.\n",tEtu[b]->refetud);
free(tEtu[b]);
for(i=b;i<nbetu;i++)
	{tEtu[i]=tEtu[i+1];}
nbetu=nbetu-1;
sauveetudiant(tEtu,nbetu);
sauvelogement(tLog,nbLog);
return nbetu;
}
/***********************************************************************************************/
void PermuteLog(Logement **t,int i,int j)
{Logement *temp;
temp=t[i];
t[i]=t[j];
t[j]=temp;
}

void trilogement(Logement **t,int n)
{
int i,k;
for(k=1;k<n;k++)
 for(i=n-1;i>=k;i--)
	if(strcmp(t[i]->ref,t[i-1]->ref)<0)
		PermuteLog(t,i,i-1);
}

/***********************************************************************************************/
Logement lireinsertlog(void)
{Logement l;
int refcite;
printf("Entrer la référénce du logement:");
scanf("%s",l.ref);
printf("Entrer si la chambre est adaptée pour une personne handicapée (0 pour Non ou 1 pour Oui :");
scanf("%d",&l.handicap);
l.etat=0;
printf("Entrer le type de logement (C,S,T1 ou T2) :");
scanf("%s",l.type);

return l;
}
/***********************************************************************************************/
int modiflogement(Logement **tlog,int nblog)
{int i,r=-1,etat=0,handicap=0,reslog;
char reflog[5],type[2];
printf("\n1) Modifier un logement disponible.\n2)Ajouter un logement disponible.\nSinon, validez n'importe quelle autre touche pour quitter.\nQue voulez-vous faire :");
scanf("%d",&reslog);

if (reslog==1)
	{printf("\nIndiquez la référence du logement à modifier :");
	scanf("%s",reflog);
	for (i=0;i<nblog;i++)
		if ((strcmp(tlog[i]->ref,reflog)==0) && (tlog[i]->etat==0))
			r=i;
	if(r==-1){printf("\nLa référence ne correspond pas à un logement disponible.\n");return nblog;}
	else
		{printf("\nVoici le logement :\nRéférence: %s\nHandicap: %d\nEtat: %d\nType: %s\n",tlog[r]->ref,tlog[r]->handicap,tlog[r]->etat,tlog[r]->type);
	printf("\nModification de la chambre %s :",tlog[r]->ref);
	printf("\nChambre pour handicapé (0 pour Non ou 1 pour Oui):");scanf("%d",&handicap);
	tlog[r]->handicap=handicap;
	tlog[r]->etat=0;
	printf("Type de la chambre (C,S,T1 ou T2):");scanf("%s",type);
	strcpy(tlog[r]->type,type);
	printf("\nVoici le logement modifié:\nRéférence: %s\nHandicap: %d\nEtat: %d\nType: %s\n\n",tlog[r]->ref,tlog[r]->handicap,tlog[r]->etat,tlog[r]->type);
		}
	}
if (reslog==2)
	{Logement log;
	log=lireinsertlog();
	for (i=0;i<nblog;i++)
		if(strcmp(log.ref,tlog[i]->ref)==0)
			{printf("\nCette référence a déjà été enregistrée. Requête annulée.\n");
			return nblog;
			}
	tlog[nblog]=(Logement*)malloc(sizeof(Logement));
	if(tlog[nblog]==NULL){printf("\n Probleme malloc");return nblog;}
	*tlog[nblog]=log;
	printf("\nVoici le logement ajouté:\nRéférence: %s\nHandicap: %d\nEtat: %d\nType: %s\n\n",tlog[nblog]->ref,tlog[nblog]->handicap,tlog[nblog]->etat,tlog[nblog]->type);
	nblog++;
	}	

if (reslog!=1 || reslog!=2)
	return nblog;

return nblog;
}

/***********************************************************************************************/
void PermuteEtud(Etudiant **t,int i,int j)
{Etudiant *temp;
temp=t[i];
t[i]=t[j];
t[j]=temp;
}

void trilogementetudiant(Etudiant **t,int n)
{
int i,k;
for(k=1;k<n;k++)
 for(i=n-1;i>=k;i--)
	{if(strcmp(t[i]->refchamb,t[i-1]->refchamb)<0)
		PermuteEtud(t,i,i-1);
	if(strcmp(t[i]->nom,t[i-1]->nom)<0)
		PermuteEtud(t,i,i-1);
	if((strcmp(t[i]->nom,t[i-1]->nom)==0) && (strcmp(t[i]->prenom,t[i-1]->prenom)<0))
		PermuteEtud(t,i,i-1);
	}
}
/***********************************************************************************************/
void affichelogementetudiant(Etudiant **tetud,Logement **tlog,int nbetud,int nblog)
{int i,j;
for (i=0;i<nbetud;i++)
	{printf("Nom: %s\nPrénom: %s\nReférence Etudiant : %d\n",tetud[i]->nom,tetud[i]->prenom,tetud[i]->refetud);
	for (j=0;j<nblog;j++)
		if(strcmp(tetud[i]->refchamb,tlog[j]->ref)==0)
			printf("Référence cité: %c\nRéférence logement: %s\nHandicap : %d\nEtat : %d \nType logement : %s \n\n",(*tlog[i]).ref[0],tlog[i]->ref,tlog[i]->handicap,tlog[i]->etat,tlog[i]->type);
	}
}
/***********************************************************************************************/
int menu(void)
{int i;
printf("Menu :");
printf("\n1)Charger et afficher les cités.");
printf("\n2)Charger,trier et afficher les demandes.");
printf("\n3)Charger et afficher les logements.");
printf("\n4)Attribuer les logements.");
printf("\n5)Afficher la liste des étudiants.");
printf("\n6)Afficher la liste des demandes.");
printf("\n7)Insérer une nouvelle demande.");
printf("\n8)Supprimer un étudiant.");
printf("\n9)Editer la liste des chambres disponibles.");
printf("\n10)Editer la liste des locations en cours.");
printf("\n0)Quitter.");
printf("\nQue voulez-vous faire :");
scanf("%d",&i);
return i;
}

void global(void)
{
system("clear");
int m,nbcite,nbetud,nbdem,nblog,ordre,refetud;
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
		sauvedemande(tdemande,nbdem);
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
		nbetud=chargeetudiant("etudiant.don",tetudiant);
		nbdem=attribution(tresidence,tlogement,tetudiant,tdemande,nbdem,nblog,&nbetud);
		sauvedemande(tdemande,nbdem);
		sauveetudiant(tetudiant,nbetud);
		sauvelogement(tlogement,nblog);
		}
	if (m==5)
		{nbetud=chargeetudiant("etudiant.don",tetudiant);
		afficheetudiant(tetudiant,nbetud);
		}
	if (m==6)
		{nbdem=chargedemande("demande.don",tdemande);
		affichedemande(tdemande,nbdem);
		}
	if (m==7)
		{
		nbcite=chargefcite("cite.don",tresidence);
		nbdem=chargedemande("demande.don",tdemande);
		affichedemande(tdemande,nbdem);
		nbetud=chargeetudiant("etudiant.don",tetudiant);
		afficheetudiant(tetudiant,nbetud);
		nbdem=insertion("demande.don",nbdem,tdemande,tetudiant,nbetud);
		tridemande(tdemande,nbdem);
		affichedemande(tdemande,nbdem);
		sauvedemande(tdemande,nbdem);
		sauveetudiant(tetudiant,nbetud);
		}
	if (m==8)
		{
		nbdem=chargedemande("demande.don",tdemande);
		nblog=chargelogement("logement.don",tlogement);
		nbetud=chargeetudiant("etudiant.don",tetudiant);
		afficheetudiant(tetudiant,nbetud);
		printf("\nEntrez la référence de l'étudiant à supprimer:");
		scanf("%d",&refetud);
		supprEtu(tetudiant,tlogement,nbetud,refetud,nblog);
		}
	if (m==9)
		{nblog=chargelogement("logement.don",tlogement);
		trilogement(tlogement,nblog);
		affichelogementdispo(tlogement,nblog);
		sauvelogement(tlogement,nblog);
		nblog=chargelogement("logement.don",tlogement);
		nblog=modiflogement(tlogement,nblog);
		sauvelogement(tlogement,nblog);
		}
	if (m==10)
		{nbetud=chargeetudiant("etudiant.don",tetudiant);
		nblog=chargelogement("logement.don",tlogement);
		trilogementetudiant(tetudiant,nbetud);
		affichelogementetudiant(tetudiant,tlogement,nbetud,nblog);
		printf("\nEntrez la référence de l'étudiant à supprimer (0 pour ne rien faire):");
		scanf("%d",&refetud);
		if (refetud!=0)
			supprEtu(tetudiant,tlogement,nbetud,refetud,nblog);
		}
	if (m==7 || m==8 || m==10)
		m=4;
	else	
		m=menu();
	}
system("clear");
return;
}

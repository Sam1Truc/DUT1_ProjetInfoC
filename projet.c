#include "projet.h"

Cite lirecite(FILE *flot)
{
Cite c;
fgets(c.nom,30,flot);
c.nom[strlen(c.nom)-1]='\0';
fgets(c.adresse,30,flot);
c.adresse[strlen(c.adresse)-1]='\0';
fscanf(flot,"%d %d %d %d %d",c.refcite,c.chambre,c.studio,c.T1,c.T2);
return c;
}

int fchargementcite(char *nomfichier,Cite *cite[])
{
int n,i;
Cite c;
FILE *fe;
fe=fopen(nomfichier,"r");
if(fe==NULL) {printf("\n Pb ouverture fichier cite.don"); exit(1);}
fscanf(fe,"%d",&n);
for (i=0;i<n;i++)
	{
    c=lirecite(fe);
    cite[i]=(Cite*)malloc(sizeof(Cite));
    if(cite==NULL){printf("Probleme malloc");return -1;}
	*cite[i]=c;
	}
fclose(fe);
printf("\n %d \n",n);
return n;
}

void affichecite(Cite **cite,int nbcite)
{
int i;
for(i=0;i<nbcite;i++)
    {
    printf("\n %s \n %s \n %d \n %d \n %d \n %d \n %d \n",cite[i]->nom,cite[i]->adresse,cite[i]->refcite,cite[i]->chambre,cite[i]->studio,cite[i]->T1,cite[i]->T2);
    }
}
void global(void)
{
int nbat;
Cite **tabresidence;
nbat=fchargementcite("cite.don",tabresidence);
affichecite(tabresidence,nbat);
return;
}

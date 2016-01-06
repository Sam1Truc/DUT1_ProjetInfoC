#include "projet.h"

Cite lirecite(FILE *flot)
{
Cite c;
fgets(c.nom,30,flot);
c.nom[strlen(c.nom)-1]='\0';
fgets(c.adresse,30,flot);
c.adresse[strlen(c.adresse)-1]='\0';
fscanf(flot,"%d %d %d %d %d",&c.refcite,&c.chambre,&c.studio,&c.T1,&c.T2);
return c;
}

int chargefcite(char *nomfichier,Cite *tcite[],int tmax)
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
for(i=0;i<nbcite;i++)
    {
    printf(" %s \n %s \n %d \n %d \n %d \n %d \n %d \n",cite[i]->nom,cite[i]->adresse,cite[i]->refcite,cite[i]->chambre,cite[i]->studio,cite[i]->T1,cite[i]->T2);
    }
}
void global(void)
{
int nbcite;
Cite *tresidence[100];
nbcite=chargefcite("cite.don",tresidence,100);
affichecite(tresidence,nbcite);
return;
}

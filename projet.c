#include "projet.h"

int fchargementcite(cite **cite)
{
int n,i;
FILE *fe;
fe=fopen("cite.txt","r");
if(fe==NULL) {printf("\n Pb ouverture Cite.txt"); exit(1);}
fscanf(fe,"%d",&n);
for (i=0;i<n;i++)
	{
	fscanf("%s %s %s %c",cite->nom,cite->adresse,cite->ville,cite
	}
fclose(fe);
printf("\n %d \n",n);
return n;
}

void affichecite(cite **cite,int n)
{
int i;
for(i=0;i<n;i++)
    {
    printf("%s \n %s \n %s \n %c \n \n ",cite[i]->nom,cite[i]->adresse,cite[i]->ville,cite[i]->bat);
    }
}
void global(void)
{
int nbat;
cite *residence[10];
nbat=fchargementcite(residence);
affichecite(residence,nbat);
return;
}

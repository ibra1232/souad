#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int NCIN,age,decision;
    char nom[20],prenom[20];
}candidats;
candidats saisie()
{
    candidats c;
     puts ("donner nom");
    scanf ("%s",c.nom);
    puts ("donner prenom");
    scanf ("%s",c.prenom);
     puts ("donner NCIN");
    scanf ("%d",&c.NCIN);
     puts ("donner age");
    scanf ("%d",&c.age);
    puts ("donner decision");
    scanf ("%d",&c.decision);
    return c;
}
void remplir(candidats t[],int n)
{
    int i;
    for(i=0;i<n;i++){
        t[i]=saisie();
    }
}
void trier(candidats t[],int n)
{
    int i;
    candidats aux;
    for(i=0;i<n;i++){
        if(t[i].age>t[i+1].age){
            aux=t[i];
            t[i]=t[i+1];
            t[i+1]=t[i];
            }
    }

}
void charger(candidats t[],int n)
{
    FILE*f=fopen("concours.txt","w");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    int i;
    for (i=0;i<n;i++){
        fprintf(f,"%s %s %d %d %d ",t[i].nom,t[i].prenom,t[i].NCIN,t[i].age,t[i].decision);
    }
    fclose(f);
}
void pourcentage(candidats t[],int n)
{
    int i,x;
    x=0;
    float p;
    for(i=0;i<n;i++){
        if(t[i].decision==1){
            x=x+1;
        }
    }
    p=(x*n)/100;
    printf("%f",p);

}
void supprimer(){
    FILE *f=fopen("concours.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    FILE *f1=fopen("admis.txt","w");
    if (f1==NULL){
        printf("erreur");
        exit(-1);
    }
    candidats c;
    while (!feof(f)){
        fscanf(f,"%s %s %d %d %d ",&c.nom,&c.prenom,&c.NCIN,&c.age,&c.decision);
            if(c.age>30){
               fprintf(f1,"%s %s %d %d %d ",c.nom,c.prenom,c.NCIN,c.age,c.decision);
            }


    }
    fclose(f);
    fclose(f1);
}

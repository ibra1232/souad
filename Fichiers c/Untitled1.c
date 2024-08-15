#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id,num;
    char nom[20],prenom[20],adresse[20];
    float salaire;
}salairie;
salairie saisie(){
    salairie s;
    puts ("donner nom");
    scanf ("%s",s.nom);
    puts ("donner prenom");
    scanf ("%s",s.prenom);
     puts ("donner adresse");
    scanf ("%s",s.adresse);
     puts ("donner identifiant");
    scanf ("%d",&s.id);
    puts ("donner num");
    scanf ("%d",&s.num);
     puts ("donner salaire");
    scanf ("%f",&s.salaire);
    return s;
}
void lire(salairie t[],int n)
{
    int i;
    for(i=0;i<n;i++){
        t[i]=saisie();
    }
}
void enregistrer( t[],int n)
{
    FILE *f=fopen("salariés.txt","w");
    if (f==NULL){
        printf("erreur");
        exit(-1);
        int i;
    }
    for (i=0;i<n;i++){
        fprintf(f,"%s %s %s %d %d %f",t[i].nom,t[i].prenom,t[i].adresse,t[i].num,t[i].id,t[i].salaire);
    }
    fclose(f);
}
void afficher()
{
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s;
    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",s.nom,s.prenom,s.adresse,&s.num,&s.id,&s.salaire);
        printf("le prenom est %s le nom est %s l'adresse est %s l'id est %d le num est %d le salaire est %f ",s.prenom,s.nom,s.adresse,s.id,s.num,s.salaire);
    }
    fclose(f);
}
void ajout(){
    FILE *f=fopen("salariés.txt","a");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s;
    fprintf(f,"%s %s %s %d %d %f\n",s.nom,s.prenom,s.adresse,&s.num,&s.id,&s.salaire);
    fclose(f)
}
void modifier(){
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    FILE *f1=fopen("sala.txt","w");
    if (f1==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s;
    int id,num;
     puts ("donner num");
    scanf ("%d",&num);
    puts ("donner identifiant");
    scanf ("%d",&id);
    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",&s.nom,&s.prenom,&s.adresse,&s.num,&s.id,&s.salaire);
            if(s.id==id){
                s.num=num;
            }
        fprintf(f1,"%s %s %s %d %d %f\n",s.nom,s.prenom,s.adresse,s.num,s.id,s.salaire);

    }
    fclose(f);
    fclose(f1);
    remove("salariés.txt");
    rename("sala.txt","salariés.txt");
}
void supprimer()
{
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    FILE *f1=fopen("sala.txt","w");
    if (f1==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s;
    int id;
    puts ("donner identifiant");
    scanf ("%d",&id);
    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",&s.nom,&s.prenom,&s.adresse,&s.num,&s.id,&s.salaire);
            if(s.id!=id){
                fprintf(f1,"%s %s %s %d %d %f\n",s.nom,s.prenom,s.adresse,s.num,s.id,s.salaire);

            }
    }
    fclose(f);
    fclosef(f1);
    remove("salariés.txt");
    rename("sala.txt","salariés.txt");}
float avg(){
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    float s=0,n=0;
    salairie s;
    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",&s.nom,&s.prenom,&s.adresse,&s.num,&s.id,&s.salaire);
        s=s+s.salaire;
        n=n+1;
    }
    fclosef(f);
    return s/n;

}
void copy(){
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    FILE *f1=fopen("sala.txt","w");
    if (f1==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s;
    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",&s.nom,&s.prenom,&s.adresse,&s.num,&s.id,&s.salaire);
        fprintf(f1,"%s %s %d %f\n",s.nom,s.prenom,s.id,s.salaire);

    }
    fclose(f);
    fclose(f1);}
void tri()
{
    FILE *f=fopen("salariés.txt","r");
    if (f==NULL){
        printf("erreur");
        exit(-1);
    }
    salairie s,t[100],aux;
    int n=0;

    while (!feof(f)){
        fscanf(f,"%s %s %s %d %d %f\n",&s.nom,&s.prenom,&s.adresse,&s.num,&s.id,&s.salaire);
        t[n]=s;
        n++;}
    do{
        test=1;
        for(int i=0,i<n,i++){
            if(t[i].id>t[i+1]){
                aux=t[i];
                t[i]=t[i+1];
                t[i+1]=aux;
                test=0;
            }
        }
    }while(test)
}

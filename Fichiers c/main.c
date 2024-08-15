#include <stdio.h>
#include <stdlib.h>
/*typedef struct Employee
{
    char PR[20];
    int NBEN;
}Employee;
void nbemp()
{

    FILE * f=fopen("nombre_enfants.txt","w");
    if (f==NULL){
        printf("erreur");
        return -1;}
    int nb,i;
    printf("donner nb");
    scanf("%d",&nb);
    Employee e;
    for(i=0;i<nb;i++){
           // fflush(stdin);
        printf("donner un prenom");
        scanf("%s",e.PR);
        printf("donner un nombre d'enfants");
        scanf("%d",&e.NBEN);
        fprintf(f,"%s\t%d\n",e.PR,e.NBEN);
    }
    fclose(f);
}
int f2()
{
    FILE * f=fopen("nombre_enfants.txt","r");
    if (f==NULL){
        printf("erreur");
        return -1;}
    Employee e;
    int s=0;
    while(!feof(f)){
        fscanf(f,"%s\t%d\n",&e.PR,&e.NBEN);
        s=e.NBEN+s;
    }
    fclose(f);
    return s;
}
int f3()
{
    FILE * f=fopen("nombre_enfants.txt","r");
    if (f==NULL){
        printf("erreur");
        return -1;}
    Employee e;
    char pre[20];
    int  s=-1;
    printf("donner un prenom\n");
    scanf("%s",&pre);
    while(!feof(f)){
        fscanf(f,"%s\t%d\n",&e.PR,&e.NBEN);
        if (strcmp(pre,e.PR)==0){
        s=e.NBEN;
    }    }
fclose(f);
    return s;

}
void f4()
{
    FILE * f=fopen("nombre_enfants.txt","r");
    if (f==NULL){
        printf("erreur");
        return -1;}
    Employee e;
    int n;
    printf(" donner n");
    scanf("%d",&n);
    while(!feof(f)){
        fscanf(f,"%s\t%d\n",&e.PR,&e.NBEN);
        if (e.NBEN>n){
            printf("%s\n",e.PR);
        }
    }
    fclose(f);

}

int main()
        {nbemp();
        int n=f2();
        printf("%d\n",n);
        int z=f3();
        printf("%d",z);
        f4();

        }



typedef struct{
char nom [20],prenom [20], adresse[20];
int num,id;
float salaire;
}salarie;
salarie saisie()
{ salarie s;
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
void lire (salarie t[], int n)
{
    for ( int i=0 ; i<n;i++)
    {t[i]=saisie();}
}
void ChargerFichier (salarie t[], int n)
{
    FILE *f =fopen("salarie.txt","w");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
  for (int i=0;i<n;i++)
        fprintf (f,"%d %s %s %s %d %f\n",t[i].id,t[i].nom,t[i].prenom,t[i].adresse,t[i].num,t[i].salaire);

fclose(f);
}
void affiche ()
{    FILE *f =fopen("salarie.txt","r");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
 salarie s;
 while (!feof(f))
 {fscanf  (f,"%d %s %s %s %d %f\n",&s.id,s.nom,s.prenom,s.adresse,&s.num,&s.salaire);
printf ("le nom est %s le prenom est %s l adresse est %s l id est %d le num est %d le salaires est %f\n", s.nom,s.prenom,s.adresse,s.id,s.num,s.salaire );
}
fclose (f);
}
void ajout()
{ FILE *f =fopen("salarie.txt","a");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    salarie s=saisie();
    fprintf (f,"%d %s %s %s %d\n",s.id,s.nom,s.prenom,s.adresse,s.num,s.salaire);

fclose(f);
}
void modifier ()
{
    FILE *f =fopen("salarie.txt","r");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
        FILE *f1 =fopen("sala.txt","w");
    if (f1==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    int id;
    printf ("donner id ");
    scanf ("%d",&id);
    salarie s;
   while (!feof(f))

 {fscanf  (f,"%d %s %s %s %d %f\n",&s.id,s.nom,s.prenom,s.adresse,&s.num,&s.salaire);
 if (id==s.id)
 {
     printf ("donner nouveau numer");
     scanf ("%d",&s.num);

 }
  fprintf (f1,"%d %s %s %s %d %f\n",s.id,s.nom,s.prenom,s.adresse,s.num,s.salaire);

}
fclose (f);
fclose (f1);
remove("salarie.txt");
rename ("sala.txt","salarie.txt");
}
void supprimer ()
{
    FILE *f =fopen("salarie.txt","r");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
        FILE *f1 =fopen("sala.txt","w");
    if (f1==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    int id;
    printf ("donner id ");
    scanf ("%d",&id);
    salarie s;
   while (!feof(f))

 {fscanf  (f,"%d %s %s %s %d %f\n",&s.id,s.nom,s.prenom,s.adresse,&s.num,&s.salaire);
 if (id!=s.id)
 {

  fprintf (f1,"%d %s %s %s %d %f\n",s.id,s.nom,s.prenom,s.adresse,s.num,s.salaire);
 }
}
fclose (f);
fclose (f1);
remove("salarie.txt");
rename ("sala.txt","salarie.txt");
}
float salaire()
{
    FILE *f=fopen("salaire.txt","r");
     if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    salarie e;
    int n=0;
    float s=0;
    while(!feof(f)){
        fscanf(f,"%d %s %s %s %d %f\n",&e.id,e.nom,e.prenom,e.adresse,&e.num,&e.salaire);
        n++;
        s=s+e.salaire;
    }
    return(s/n);
}
void tri()
{
    FILE *f=fopen("salarie.txt","r");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    salarie t[100],s;
    int n=0;
    while(!feof(f)){
        fscanf  (f,"%d %s %s %s %d %f\n",&s.id,s.nom,s.prenom,s.adresse,&s.num,&s.salaire);
        t[n]=s;
        n++;
    }
    fclose(f);
    int permut;
    salarie aux;
    do{
        permut=1;
        for(int i=0;i<n-1;i++){
            if(t[i].id>t[i+1].id){
                aux=t[i];
                t[i]=t[i+1];
                t[i+1]=aux;
                permut=0;
            }
        }
    }while(permut);
    ChargerFichier ( t, n);
}

main()
{
salarie t[100];
int n;
puts ("donner nb de salaries");
scanf ("%d",&n);
lire (t,n);
ChargerFichier(t,n);
int choix;
do
{ puts ("1 : Affichage");
 puts ("2: Ajout");
 puts ("3: Modification");
 puts ("4: Suppression");
 puts ("5:salaire moy");
 puts ("6:tri");
  puts ("0: Quitter");
 puts ("donner votre choix");
 scanf ("%d",&choix);
 switch(choix)
 {
     case 1 : affiche();
            break;
    case 2 : ajout();
            break;
    case 3 : modifier();
             break;
    case 4 : supprimer();
             break;
    case 5:salaire();
             break;
    case 6:tri();
             break;
    default : if (choix)
              puts ("choix invalide");

 }

} while (choix!=0);
}
*/
typedef struct
{
    char nom[20],pr[20];
    int tel;

}telephonique;
telephonique saisie()
{ telephonique s;
    puts ("donner nom");
    scanf ("%s",s.nom);
    puts ("donner prenom");
    scanf ("%s",s.pr);
    puts ("donner tel");
    scanf ("%d",&s.tel);
    return s;
}
void ajout_personne ()
{
    FILE *f=fopen("telephone.txt","ab");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    telephonique t=saisie();
    fwrite(&t,sizeof(telephonique),1,f);
    fclose(f);
}
void affiche()
{
    FILE *f=fopen("telephone.txt","rb");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    telephonique t;
    while(fread(&t,sizeof(telephonique),1,f)){
        printf("le nom est %s le prenom est %s le numero est %d",t.nom,t.pr,t.tel);
    }
    fclose(f);
}
void trouver()
{
    FILE *f=fopen("telephone.txt","rb");
    if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    telephonique t;
    char a[20],b[20];
    puts("donner un nom");
    scanf("%s",a);
    puts("donner un prenom");
    scanf("%s",b);
     while(fread(&t,sizeof(telephonique),1,f))
     {
         if(strcmp(a,t.nom)==0&&strcmp(b,t.pr)==0){
            printf("%d",t.tel);
         }
     }
     fclose(f);
}
void changer()
{
    FILE *f=fopen("telephone.txt","rb");
if (f==NULL)
    {
        printf ("erreur");
        exit(-1);
    }
    telephonique t;
    char a[20],b[20];

     puts("donner un nom");
    scanf("%s",a);
    puts("donner un prenom");
    scanf("%s",b);
     while(fread(&t,sizeof(telephonique),1,f))
     {
         if(strcmp(a,t.nom)==0&&strcmp(b,t.pr)==0){
                printf("donner le nouveau numero");
                scanf("%d",&t.tel);
         }
     }

}
int main()
{

int choix;
do
{ puts ("1 :ajout ");
 puts ("2: Affiche");
 puts ("3:trouver ");
 puts ("4: changer");

  puts ("0: Quitter");
 puts ("donner votre choix");
 scanf ("%d",&choix);
 switch(choix)
 {
     case 1 : ajout_personne ();
            break;
    case 2 : ajout_personne ();
            break;
    case 3 : trouver();
             break;
    case 4 : changer();
             break;

    default : if (choix)
              puts ("choix invalide");

 }

} while (choix!=0);
}

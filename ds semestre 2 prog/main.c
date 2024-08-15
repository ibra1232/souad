#include <stdio.h>
#include <stdlib.h>
typedef struct{
char titre [20],auteur [20];
int numpg,etat;
}livre;
livre lire()
{
    livre l;
    puts("donner le titre");
    scanf("%s",l.titre);
    puts("donner l'auteur");
    scanf("%s",l.auteur);
    puts("donner le numpg");
    scanf("%s",&l.numpg);
    puts("donner l'etat");
    scanf("%s",&l.etat);
    return l;
}
void biobliotheque(livre t[], int n)
{
    for ( int i=0 ; i<n;i++)
    {t[i]=lire();}
}
void emprunter(livre t[], int n)
{
    char tit[20];
    puts("donner le titre");
    scanf("%s",tit);
    for ( int i=0 ; i<n;i++){
        if(strcmp(tit,t[i].titre)==0){
            if(t[i].etat==1){
                t[i].etat=0;
            }
            else{
                printf("erreur");

            }
        }
        else{
            printf("erreur");
        }
    }

}
void retourner(livre t[], int n)
{
    char tit[20];
    puts("donner le titre");
    scanf("%s",tit);
    for ( int i=0 ; i<n;i++){
        if(strcmp(tit,t[i].titre)==0){
            if(t[i].etat==1){
                printf("erreur");


            }
            else{
                t[i].etat=1;
                int npgl;
                printf("donner le nombre de page lues");
                scanf("%d",&npgl);
                if(npgl<t[i].numpg){
                    printf("Bravo!");
                }
                else{
                    printf("felecitations");
                }

            }
        }
        else{
            printf("erreur");
        }
    }

}
void trier(livre t[], int n)
{
    int test=1;
    do{
    livre aux;
    for ( int i=0 ; i<n;i++){
        if(strcmp(t[i].titre,t[i+1].titre)>0){
                aux=t[i];
                t[i]=t[i+1];
                t[i+1]=aux;
                test=0;
        }
    }
    }while (test);
}

void afficher(livre t[], int n)
{
    for ( int i=0 ; i<n;i++){
        printf("le livre %s de l'auteur %s son nombre de page est %d et leur etat est %d",t[i].titre,t[i].auteur,t[i].numpg,t[i].etat);
    }
    int m=0;
    float p;
    for ( int i=0 ; i<n;i++){
            if(t[i].etat==0){
                m=m+1;
            }}
    p=(m/n)*100;
    printf("le pourcentage des livres empruntés est %f",p);

}
void supprimer(livre t[], int *n)
{
    char tit[20];
    puts("donner le titre");
    scanf("%s",tit);
    for ( int i=0 ; i<*n;i++){
        if(strcmp(tit,t[i].titre)==0){
            for(int j=i;j<*n-1;j++){
                t[j]=t[j+1];

            }
            *n=*n-1;
        }
    }
}
int main()
{
   int n;
   livre t[100];
   printf("donner n");
   scanf("%d",&n);
   biobliotheque(t,n);
   int choix;
   do
{ puts ("1 : emprunter");
 puts ("2: retourner");
 puts ("3: trier");
 puts ("4: affichage");
 puts ("5:suppresion");
  puts ("0: Quitter");
 puts ("donner votre choix");
 scanf ("%d",&choix);
 switch(choix)
 {
     case 1 : emprunter(t,n);
            break;
    case 2 : retourner(t,n);
            break;
    case 3 : trier(t,n);
             break;
    case 4 : afficher(t,n);
             break;
    case 5:supprimer(t,n);
             break;
    default : if (choix)
              puts ("choix invalide");

 }

} while (choix!=0);


}




/*
#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
    float ab,or;
}point;
void saisie(point*p)
{
    printf("donner ab");
    scanf("%f",&(*p).ab);
    printf("donner or");
    scanf("%f",&(*p).or);
}
void affiche(point p)
{
    printf("%f",p.ab);
    printf("|%f",p.or);
}
void  deplacer(point*p1)
{
    float ds,dy;
    printf("donner ds");
    scanf("%d",&ds);
    printf("donner dy");
    scanf("%f",&dy);
    (*p1).ab=(*p1).ab+ds;
    (*p1).or=(*p1).or+dy;
}
point milieu(point p,point p1)
{
    point M ;
    M.ab=(p.ab+p1.ab)/2;
    M.or=(p.or+p1.or)/2;
    return M ;
}

int main()
{
    point p,M,p1;
    saisie(&p);
    saisie(&p1);
    deplacer(&p1);
    M=milieu(p,p1);
    affiche(M);
}
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct eleveurs
{
    char Nom[20];
    int NB1,NB2,NB3;
}eleveurs;
void saisie(eleveurs*p)
{
    printf("donner Nom");
    scanf("%s",&(*p).Nom);
    printf("donner NB1 ");
    scanf("%d",&(*p).NB1);
    printf("donner NB2 ");
    scanf("%d",&(*p).NB2);
    printf("donner NB3 ");
    scanf("%d",&(*p).NB3);
}
void Saisir_Eleveur(eleveurs T[],int n)
{
    int i;
    for(i=0;i<n;i++)
        saisie(&T[i]);
}


void infoele(eleveurs T[100],int n)
{
    int i,a;
    for(i=0;i<n;i++){

        printf("%s\n",T[i].Nom);
        a=T[i].NB1+T[i].NB2+T[i].NB3;
        printf("%d\n",a);
        printf("%.2f\n",(float)T[i].NB1/a);
    }
}
void Max_troupeau(eleveurs T[100],int n)
{
    int i,max,a;
    max=0;
    for(i=1;i<n;i++){
        a=T[i].NB1+T[i].NB2+T[i].NB3;
        if (a>T[max].NB1+T[max].NB2+T[max].NB3){
            max=i;
        }
    }
    printf("%s\n",T[max].Nom);
    printf("%d\n",T[max].NB1);
    printf("%d\n",T[max].NB2);
    printf("%d\n",T[max].NB3);
}
int main()
{
    eleveurs p,T[100];
    int n;
    printf("donner n");
    scanf("%d",&n);
    Saisir_Eleveur(T, n);
    infoele( T, n);
    Max_troupeau(T, n);


}

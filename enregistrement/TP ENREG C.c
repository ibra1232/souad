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

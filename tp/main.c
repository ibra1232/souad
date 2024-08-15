#include <stdio.h>
#include <stdlib.h>
/*
float max (float x,float y)
{
if (x>y)
    return x;
else
    return y;



}
float min (float x,float y)
{
 if (x<y)
    return x;
else
    return y;

}
int impaire(int x)
{

    if(x%2==0)
        return 0;
    else
        return 1;

}
int absolue(int x)
{
    if(x>0)
        return x;
    else
        return -1*x;
}
int main()
{
    float a,b,c,d,MAX,MIN;
    printf("donner a ");
    scanf("%f",&a);
        printf("donner b");
    scanf("%f",&b);
        printf("donner c");
    scanf("%f",&c);
        printf("donner d");
    scanf("%f",&d);
    MAX=max(max(a,b),max(c,d));
    MIN=min(min(a,b),min(c,d));
    printf("%.2f\n",MAX);
    printf("%.2f\n",MIN);
    if(impaire(6))
        printf("impaire");
    else
        printf("pair");

}
*/
int LONG_CH(char CH[])
{
    int i;
    for(i=0;CH[i];i++);
    return i;

}
int nbapp(char c,char CH[])
{
    int i,n=0;
    for (i=0;CH[i];i++){
        if(CH[i]==c){
            n++;
        }}
        return n;
}
void ajout(char ch1[],char ch2[],char ch[])
{
    int i,j;
    for(i=0;ch1[i];i++)
        ch[i]=ch1[i];
    for(j=0;ch2[j];j++){
        ch[i]=ch2[j];
        i++;
    }
    ch[i]='\0';
}
void permuter(char*ch,char*ch1)
{
    char aux=*ch;
    *ch=*ch1;
    *ch1=aux;
}
void inverser(char ch[])
{
    int i,j;
    for(i=0,j=strlen(ch)-1;i<strlen(ch)/2;i++,j--)
        permuter(&ch[i],&ch[j]);
}
main()
{
    char CH[20],ch1[20],ch2[40];
    puts("donner une chaine");
    gets(CH);
    puts("la chaine est ");
    puts(CH);
    int n=LONG_CH(CH);
    printf("la longueur est %d \n",n);
    char c;
    printf("donner le cara");
    scanf("%c",&c);
    int s=nbapp(c,CH);
    printf("%c apparait %d fois\n",c,s);
    printf("donner une chaine");
    scanf("%s",ch1);
    ajout(CH,ch1,ch2);
    printf("%s",ch2);
    inverser(CH);
    printf("\n%s",CH);
}


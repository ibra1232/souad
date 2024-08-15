#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[20];
    printf("donner s");
    gets(s);
    int x=0,i;
    for(i=0;s[i]!='\0';i++){
            x=x+1;

    }
    printf("le nombre de chaine est %d",x);




}

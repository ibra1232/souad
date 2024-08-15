#include <stdio.h>
#include <stdlib.h>
/*

int main()
{
    int *t,*t1,n,n1,*p,*p1;
    printf("n=");
    scanf("%d",&n);
    printf("n1=");
    scanf("%d",&n1);
    t=(int*)malloc(n*sizeof(int));
    t1=(int*)malloc(n1*sizeof(int));
    for(p=t;p<t+n;p++){
        scanf("%d",p);
    }
    for(p=t1;p<t1+n1;p++){
        scanf("%d",p);
    }
    t=(int*)realloc(t,n+n1*sizeof(int));
    for(p=t+n,p1=t1;p<t+n+n1;p++,p1++){
        *p=*p1;
    }
    for(p=t;p<t+n+n1;p++){
        printf("%d",*p);
    }

}

int main()
{
    int *a,x,n,*p,*i;
    printf("n=");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("x=");
    scanf("%d",&x);
    for(p=a;p<a+n;p++){
        scanf("%d",p);}
    for(p=a;p<a+n;p++){
        if(*p==x){
            for(i=p;i<a+(n-1);i++){
                *i=*(i+1);
            }
            p--;
            n--;
        }
    }
    a=(int*)realloc(a,n*sizeof(int));
    for(i=a;i<a+n;i++)
        printf("%d",*i);
}
*/
int main()
{
    int t[100],i,n,x,*p,y;
    int*TPOS;
    int*TNEG;

    printf("n=");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("t[%d]=",i);
        scanf("%d",&t[i]);
    }
    x=0;
    for(i=0;i<n;i++){
        if(t[i]>0){
            x=x+1;
        }
    }
    TPOS=(int*)malloc(x*sizeof(int));
    for(p=TPOS,i=0;i<n;i++){
        if(t[i]>0){
            *p=t[i];
            p++;

        }
    }
    y=n-x;
    TNEG=(int*)malloc(y*sizeof(int));
    for(p=TNEG,i=0;i<n;i++){
        if(t[i]<0){
            *p=t[i];
            p++;
        }
    }
    printf("TPOS=");
    for(p=TPOS;p<TPOS+x;p++){
        printf("%d |",*p);
    }
    printf("\n");
    printf("TNEG=");
    for(p=TNEG;p<TNEG+y;p++){
        printf("%d |",*p);
    }
}





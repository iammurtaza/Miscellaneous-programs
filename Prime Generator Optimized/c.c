#include <stdio.h>

void z(long n){
    long i,f=1,d=0,no=-1;
    for(i=2;i<=n;i++){
        f=f*i;
    }
    while(d==0){
        no++;
        d=f%10;
        f=f/10;
    }
    printf("%d\n",no);
}

int main()
{
    long i,t,n[100000];
    scanf("%d",t);
    for(i=0;i<t;i++)
        scanf("%d",n[i]);
    for(i=0;i<t;i++)
        z(n[i]);
    return 0;
}

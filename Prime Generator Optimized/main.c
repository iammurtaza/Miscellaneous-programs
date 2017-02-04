#include <stdio.h>

short primechecker(long i){
    long j=2,p=sqrtl(i);
    for(;j<=p;j++){
        if(i%j==0)
            return 0;
    }
    if(i==1)
        return 0;
    else
        return 1;
}

void prime(long m,long n){
    long i;
    for(i=m;i<=n;i++){
        if(primechecker(i))
            printf("%d\n",i);
    }
}

int main(){
    long m[150],n[150];
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%d %d",&m[i],&n[i]);
    for(i=0;i<t;i++)
        prime(m[i],n[i]);
    return 0;
}

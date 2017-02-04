#include <stdio.h>

void swap(long &x,long &y){
    long temp=x;
    x=y;
    y=temp;
}

int partition(long *a,int start,int end){
    int partIndex=start;
    long pivot=a[end];
    for(int i=start;i<end;i++){
        if(a[i]<=pivot){
            swap(a[i],a[partIndex]);
            partIndex++;
        }
    }
    swap(a[partIndex],a[end]);
    return partIndex;
}

void quicksort(long *a,int start,int end){
    if(start<end){
        int partIndex = partition(a,start,end);
        quicksort(a,start,partIndex-1);
        quicksort(a,partIndex+1,end);
    }
}

int main()
{
    int i,k,t;
    long c,b[20000][4];

    scanf("%d",&t);
    for(i=0;i<t;i++)
        for(k=0;k<4;k++)
            scanf("%li",&b[i][k]);

    for(i=0;i<t;i++){
        c=0;
        quicksort(b[i],0,3);
        while((b[i][0]+b[i][1]+b[i][2]+b[i][3]>=4) && b[i][2]!=0){
            while(b[i][0]>=1){
                b[i][0]--;
                b[i][1]--;
                b[i][2]--;
                b[i][3]--;
                c++;
            }

            while(b[i][1]>=1 && b[i][3]>=2){
                b[i][1]--;
                b[i][2]--;
                b[i][3]-=2;
                c++;
            }

            while(b[i][2]>=2){
                b[i][2]-=2;
                b[i][3]-=2;
                c++;
            }
        }

    printf("Case %d: %li\n",i+1,c);
    }
    return 0;
}

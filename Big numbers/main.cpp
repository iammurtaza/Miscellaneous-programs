#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char x[100],y[100];
    int z[101],i,j,k,carry;
    gets(x);
    gets(y);

    cout<<"Adding them: ";
    carry=0;
    for(i=strlen(x)-1,j=strlen(y)-1;i>=0;i--,j--){
        if(j>=0)
            k=(int)(x[i]-'0')+(int)(y[j]-'0')+carry;
        else
            k=(int)(x[i]-'0')+carry;
        z[i+1]=k%10;
        carry=k/10;
    }
    if(carry>0)
        z[i+1]=carry;

    if(carry>0)
        for(i=0;i<=strlen(x);i++)
            cout<<z[i];

    else
        for(i=1;i<=strlen(x);i++)
            cout<<z[i];

    cout<<"\n\nSubtracting them(with a>b): ";
    for(i=strlen(x)-1,j=strlen(y)-1;i>=0;i--,j--){
        if(j>=0){
        if(x[i]>y[j])
            z[i]=x[i]-y[j];
        else
            while(x[i]<=y[j]){
                x[i]+=9;
                i--;
                j--;
                x[i]--;
            }
        }
        else{
            z[i]=x[i]
        }
    }
    for(i=0;i<strlen(x);i++)
            cout<<z[i];
    cout<<"\n\nMultiplying A with a constant\n";
    cout<<"\n\nDividing A with a constant\n";
    return 0;
}

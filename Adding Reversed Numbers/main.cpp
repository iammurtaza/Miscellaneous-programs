#include <iostream>

using namespace std;

int power(int j){
    int num=1;
    while(j!=0){
        num*=10;
        j--;
    }
    return num;
}

int rev(int a){
    int n=0,d[10],i=0,j,k;
    while(a>0){
        d[i]=a%10;
        a/=10;
        i++;
    }
    for(j=i-1,k=0;j>-1;j--,k++){
        n+=d[k]*power(j);
    }
    return n;
}

int main(){
    int a,b,i,n,o[10000];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        o[i]=rev(rev(a)+rev(b));
    }
    for(i=0;i<n;i++){
        cout<<o[i]<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

void sieve(int n){
    int k,i,a[10001][2];
    for(i=2;i<=n;i++){
        a[i][1]=i;
        a[i][2]=0;
    }
    for(k=2;k<n/2;k++){
        for(i=k+1;i<=n;i++){
            if(a[i][2]==0){
                if(a[i][1]%k==0)
                    a[i][2]=1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(a[i][2]==0)
            cout<<a[i][1]<<" ";
    }
}

int main()
{   int i,n[100],t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n[i];
    }
    for(i=0;i<t;i++){
        sieve(n[i]);
        cout<<endl;
    }
    return 0;
}

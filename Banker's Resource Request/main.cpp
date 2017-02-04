#include <iostream>

using namespace std;
int alloc[100][100],mx[100][100],need[100][100],ava[100],marked[100],total[100],used[100],work[100],req[100][100] ;
int n,m ;

bool safety_test() {

    int i,j,flag,cnt ;
    
    for(j=0;j<m;j++)
        ava[j]=work[j] ;

    for(i=0;i<n;i++)
        marked[i]=0;
    
    cnt=0 ;
    a1:
    for(i=0;i<n;i++)
    {   flag=0;
        for(j=0;j<m;j++)
            if(!(need[i][j]<=ava[j] && marked[i]==0))
                flag=1;


        if(!flag)
        {   for(j=0;j<m;j++)
               ava[j] += alloc[i][j];
			
			marked[i]=1 ;
            cnt++ ;
            //cout<<"P "<<i+1<<" executed\n";
            goto a1;
        }
    }

    if (cnt==n)
        return true ;
    else
        return false ;
}

int main() {
    int k,f2,i,j ;
    cin>>n>>m;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>alloc[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++) {
            cin>>mx[i][j];
            need[i][j]=mx[i][j]-alloc[i][j];
        }

    for(j=0;j<m;j++)
        cin>>total[j];

    for(j=0;j<m;j++)
        for(i=0;i<n;i++)
            used[j]+=alloc[i][j];

    for(j=0;j<m;j++)
        work[j]=total[j]-used[j];

    cout<<"Enter process number : " ;
    cin>>k ;
    k-- ;

    cout<<"Enter request : " ;
    for (j=0;j<m;j++)
        cin>>req[k][j] ;

    for (j=0,f2=0;j<m;j++)
        if (req[k][j]>need[k][j]  || req[k][j]>work[j])
        {   f2=1 ;
            break ;
        }

    
    if (f2==0){
        for(j=0;j<m;j++){
            alloc[k][j] += req[k][j];
            work[j] -= req[k][j];
            need[k][j] -= req[k][j];
        }
        if(safety_test())
            cout<<"Safe";
        else
            cout<<"Unsafe";
    }

    else
        cout<<"Invalid Request";
    return 0;
}
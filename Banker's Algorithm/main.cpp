#include <iostream>

using namespace std;
int alloc[100][100],mx[100][100],need[100][100],ava[100],marked[100],total[100],used[100] ;
int main()
{
    int n,m,i,j,flag,cnt;
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
        ava[j]=total[j]-used[j];

    for(i=0;i<n;i++)
        marked[i]=0;
    
    cnt=0 ;
    a1:
    for(i=0;i<n;i++)
    {   
        flag=0;
        for(j=0;j<m;j++)
            if(!(need[i][j]<=ava[j] && marked[i]==0))
                flag=1;


        if(flag==0)
        {   for(j=0;j<m;j++)
               ava[j] += alloc[i][j];
			
            marked[i]=1 ;
            cnt++ ;
            cout<<"P "<<i+1<<" executed\n";
            goto a1;
        }
    }

    if (cnt==n)
        cout<<"Safe state\n" ;
    else
        cout<<"Deadlocked\n";
    return 0;
}
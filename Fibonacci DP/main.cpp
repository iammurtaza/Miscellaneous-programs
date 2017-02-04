#include <iostream>

using namespace std;

long long fib[100];

long long fibDP(int n){
    long long i,mem[500];

    if(n<=1)
        return n;

    mem[0]=0;
    mem[1]=1;

    for(i=2;i<=n;i++){
        mem[i]=mem[i-1]+mem[i-2];
    }
    return mem[n];
}

long long fib_Recursion_With_Memorization(int n){
    if(n<=1)
        return n;

    if(fib[n]!=0)
        return fib[n];

    fib[n]=fib_Recursion_With_Memorization(n-1)+fib_Recursion_With_Memorization(n-2);
    return fib[n];
}

int main()
{
    int n;
    cin>>n;
    fib[1]=1;
    cout<<fib_Recursion_With_Memorization(n);
    return 0;
}

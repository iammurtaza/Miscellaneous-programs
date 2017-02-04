#include <iostream>
#define ll long long int

using namespace std;

ll pow(ll x,ll n){
    if(n==0)
        return 1;
    return x*pow(x,n-1);

}

ll pow_LOGN(ll x,ll n){
    if(n==0)
        return 1;
    if(n%2==0){
        ll y = pow(x,n/2);
        return y*y;
    }
    return x*pow(x,n-1);
}

int main()
{
    ll x,n;
    cin>>x;
    cin>>n;
    cout<<pow_LOGN(x,n);
    return 0;
}

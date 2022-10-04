#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    ll n;
    cin>>n;
    ll x=(-1+sqrt(1.0+(4.0*2.0*n)))/2;
    ll y=((x*x)+x)/2;
    if(n==y) cout<<x<<endl;
    else cout<<n-y<<endl;
    return 0;
}
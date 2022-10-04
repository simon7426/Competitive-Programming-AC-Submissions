#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sq(x) x*x
ll a[100100];
 
vector <int> v;
main()
{
    ll n,i,t;
    cin>>n;
    ll k=1;
    t=2;
    ll x;
    while(k!=n+1)
    {
        x=k*k*k+2*k*k+((k>1)?1:-1);
        cout<<x<<endl;
        t=k*(k+1);
        k++;
    }
    return 0;
}
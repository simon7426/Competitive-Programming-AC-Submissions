#include<iostream>
#include<cmath>
typedef long long int ll;
using namespace std;
ll c=0,t;
ll cnt(ll a,ll b)
{
    if(b==1)
        return a;
    if(a==1)
        return b;
    if(a>b){t=a/b;c+=t;
        return cnt(a-b*t,b);}
    if(a<b){t=b/a;c+=t;
        return cnt(a,b-a*t);}
}
main()
{
    ll a,b;
    cin>>a>>b;
    cout<<cnt(a,b)+c<<endl;
    return 0;
}
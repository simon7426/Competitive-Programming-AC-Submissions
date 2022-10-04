#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
main()
{
    ll n,i,t,cnt=0,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        cnt+=t;
        ma=max(ma,t);
    }
    cnt+=n-2;
    ll x=cnt/(n-1);
    x=max(ma,x);
    cout<<x<<endl;
    return 0;
}
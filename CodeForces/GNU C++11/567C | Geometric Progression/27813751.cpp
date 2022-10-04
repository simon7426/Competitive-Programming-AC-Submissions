#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
map<ll,ll> l,r;
main()
{
    ll n,i,t,k;
    cin>>n>>k;
    ll a[n+1];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        r[a[i]]++;
    }
    ll ans=0LL;
    for(i=0;i<n;i++)
    {
        t=a[i];
        r[t]--;
        if(t%k==0)
        {
            ans+=(l[t/k]*r[t*k]);
        }
        l[t]++;
        //cout<<l[t]<<" "<<r[t]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
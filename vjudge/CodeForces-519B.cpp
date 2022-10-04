#include<iostream>
#include<map>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll n,i,t;
    cin>>n;
    map<ll,pair<ll,ll> >a;
    map<ll,pair<ll,ll> >b;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a[t].first++;
    }
    for(i=0;i<n-1;i++)
    {
        cin>>t;
        a[t].second++;
        b[t].first++;
    }
    for(i=0;i<n-2;i++)
    {
        cin>>t;
        b[t].second++;
    }
    map<ll,pair<ll,ll> >::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        if(it->second.first!=it->second.second)
        {cout<<it->first<<endl;break;}
    }
    for(it=b.begin();it!=b.end();it++)
    {
        if(it->second.first!=it->second.second)
        {cout<<it->first<<endl;break;}
    }
    return 0;
}

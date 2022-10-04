#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
typedef long long int ll;
using namespace std;
struct fri
{
    ll pos;
    ll num;
    ll cnt;
};
bool com(fri a,fri b)
{
    if(a.cnt==b.cnt)
        return a.pos<b.pos;
    return a.cnt>b.cnt;
}
main()
{
    ll n,i,t,j,d;
    cin>>n>>d;
    map<ll,pair<ll,ll> > a;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(a[t].first==0)
        {
            a[t].first=1;
            a[t].second=i;
        }
        else
            a[t].first++;
    }
    vector<fri> v;
    i=0;
    map<ll,pair<ll,ll> >::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        v.push_back(fri());
        v[i].pos=(ll)it->second.second;
       // cout<<it->first<<" "<<it->second<<endl;
        v[i].num=(ll)(it->first);
        v[i].cnt=(ll)(it->second.first);
        i++;
    }
    /*for(i=0;i<v.size();i++)
        cout<<v[i].num<<" "<<endl;*/
    sort(v.begin(),v.end(),com);
    for(i=0;i<v.size();i++)
    {
        for(j=0;j<v[i].cnt;j++){
            cout<<v[i].num<<" ";
        }
    }
}

#include<iostream>
#include<algorithm>
#include<utility>
typedef long long ll;
using namespace std;
main()
{
    ll s,t;
    int n,i;
    cin>>n;
    pair<ll,ll> p[n];
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        p[i]=make_pair(s,t);
    }
    sort(p,p+n);
    s=-1;
    for(i=0;i<n;i++)
    {
        if(p[i].second>=s)
            s=p[i].second;
        else
            s=p[i].first;
    }
    cout<<s<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long int ll;
using namespace std;
void solve()
{
    ll n,i,j,p,q,ma=0;
    cin>>n;
    vector<ll> a,b;
    for(i=0;i<n;i++)
    {
        cin>>p>>q;
        a.push_back(p);
        b.push_back(q);
    }
    sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll o=0;
        vector<ll>::iterator it;
        for(i=0;i<n;i++)
        {
            it=lower_bound(a.begin(),a.end(),b[i]);
            ma=max((ll)(it-a.begin())-o,ma);
            o++;
        }
    cout<<ma<<endl;
}
main()
{
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
        solve();
    return 0;
}

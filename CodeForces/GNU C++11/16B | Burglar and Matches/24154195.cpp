#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
typedef long long int ll;
#define pll pair<ll,ll>
using namespace std;
bool com(const pll &a,const pll &b)
{
    return a.second>b.second;
}
main()
{
    ll n,m,s,t,i,cnt=0,cnt1=0;
    cin>>n>>m;
    vector<pair<ll,ll> > a;
    for(i=0;i<m;i++)
    {
        cin>>s>>t;
        a.push_back(make_pair(s,t));
    }
    sort(a.begin(),a.end(),com);
    i=0;
    while(cnt1+a[i].first<=n&&i<m)
    {
        cnt+=a[i].first*a[i].second;
        cnt1+=a[i].first;
        i++;
        //cout<<cnt<<" "<<cnt1<<" "<<i<<endl;
    }
    if(i<m&&cnt1<n){
    t=n-cnt1;
    //cout<<t<<endl;
    cnt+=t*a[i].second;}
    cout<<cnt<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
typedef long long int ll;
using namespace std;
vector<ll> a(100010,0);
vector<ll> cnt;
/*inline ll fun(ll n)
{
    if(n==0)
        return 0;
    if(n==1)
        return a[1];
    ll t=max(fun(n-1),fun(n-2)+a[n]*n);
    return t;
}*/
main()
{
    ios::sync_with_stdio(0);
    ll n,i,t,s,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        ma=max(ma,t);
        a[t]++;
    }
    cnt.push_back((ll)0);
    cnt.push_back(a[1]);
    for(i=2;i<=ma;i++)
    {
        cnt.push_back(max(cnt[i-1],cnt[i-2]+a[i]*i));
    }
    cout<<cnt[ma]<<endl;
    return 0;
}
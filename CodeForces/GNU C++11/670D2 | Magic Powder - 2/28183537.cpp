#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll n,k,a[100010],b[100010],x[100010],cnt;
 
bool f(ll v)
{
    cnt=0LL;
    for(int i=0;i<n;i++)
    {
        x[i]=max(0LL,(v*a[i])-b[i]);
        cnt+=x[i];
        if(cnt>k) return false;
    }
    return true;
}
 
main()
{
    ll i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    ll l=0LL,h=3000000000,m;
    while(l<h)
    {
        m=(l+h+1)/2;
        //cout<<m<<endl;
        if(f(m)) l=m;
        else h=m-1;
    }
    cout<<l<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll n,k,a[1010],b[1010],x[1010],cnt;
 
bool f(ll v)
{
    cnt=0;
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
    ll l=0,h=100000000,m;
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
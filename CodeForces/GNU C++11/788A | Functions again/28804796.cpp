#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll a[100100],b[100100],c[100100],d[100100];
 
main()
{
    ll n,i,t;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(i=0;i<n-1;i++)
        b[i]=abs(a[i]-a[i+1]);
    c[n]=0;
    d[n]=0;
    ll ans=LLONG_MIN;
    for(i=n-1;i>=0;i--)
    {
        c[i]=b[i]-d[i+1];
        d[i]=b[i]-c[i+1];
        c[i]=max(b[i],c[i]);
        ans=max(ans,c[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
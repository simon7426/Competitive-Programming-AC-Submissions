#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll a[400010];
main()
{
    ll n,i,t,in=0,mi=2e9+5,f=0,ma=0,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
        if(a[i]<=mi)
        {
            mi=a[i];
        }
    }
    for( i=0;i<2*n;i++)
    {
        if(a[i]==mi)
        {
            ma=max(cnt,ma);
            cnt=0;
        }
        cnt++;
    }
    //cout<<in<<" "<<fo<<endl;
    cout<<n*mi+ma-1LL<<endl;
    return 0;
}
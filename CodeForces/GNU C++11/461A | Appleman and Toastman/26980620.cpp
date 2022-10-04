#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
typedef long long ll;
ll a[300500];
main()
{
    optimize();
    ll n,i,t=0;
    cin>>n;
    for(i=0;i<n;i++)
        {cin>>a[i];t+=a[i];}
    if(n<=1) {cout<<t<<endl;return 0;}
    sort(a,a+n);
    ll ans=t*2;
    for(i=0;i<n-2;i++)
        {  ans+=(t-a[i]);
           t-=a[i];
           //cout<<ans<<" ";
        }
        cout<<ans<<endl;
}
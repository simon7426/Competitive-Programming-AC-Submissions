#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[200050],q[200050];
ll b[200050];
main()
{
    optimize();
    memset(q,0,sizeof q);
    int n,m,i,t,l,r;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        q[l-1]++;
        q[r]--;
    }
    b[0]=q[0];
    for(i=1;i<n;i++)
        b[i]=q[i]+b[i-1];
    sort(b,b+n);
    sort(a,a+n);
    ll ans=0;
    for(i=0;i<n;i++)
    {
        ans+=a[i]*b[i];
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    ll i,x1,x2,y1,y2,n,ans=0,a,b,c,x,y;
    cin>>x1>>y1>>x2>>y2>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        x=(x1*a+y1*b+c)<0;
        y=(x2*a+y2*b+c)<0;
        if(x!=y) ans++;
    }
    cout<<ans<<endl;
}
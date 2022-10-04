#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,k,i,t,a,b=1,c,ans=0,f=1;
    cin>>n>>k;
    c=n*(k-1);
    c++;
    a=c;
    for(i=1;i<=n;i++)
    {
        ans+=a;
        a+=(n-k+1);
    }
    cout<<ans<<endl;
    while(f<=n){
    for(i=1;i<k;i++)
    {
        cout<<b<<" ";
        b++;
    }
    for(i=k;i<=n;i++)
    {
        cout<<c<<" ";
        c++;
    }
    cout<<endl;
    f++;
    }
    return 0;
}
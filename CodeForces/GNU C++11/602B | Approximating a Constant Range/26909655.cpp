#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,ans=0;
    cin>>n;
    int a[n+5];
    int i=0,j=0,l=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    int ma=a[0],mi=a[0],f[n+5];
    f[0]=0;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) f[i]=f[i-1];
        else f[i]=i;
        if(a[i]<a[i-1]&&abs(ma-a[i])>1){ l=f[i-1];ma=a[i-1]; }
        else if(a[i]>a[i-1]&&abs(mi-a[i])>1) {l=f[i-1];mi=a[i-1];}
        ma=max(ma,a[i]),mi=min(mi,a[i]);
        ans=max(ans,i-l+1);
        //cout<<f[i]<<" "<<a[i]<<" "<<ma<<" "<<mi<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
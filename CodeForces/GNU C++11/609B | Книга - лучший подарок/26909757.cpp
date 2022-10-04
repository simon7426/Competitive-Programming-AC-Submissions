#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,i,j,t;
    cin>>n>>m;
    int a[m+1];
    memset(a,0,sizeof a);
    for(i=0;i<n;i++)
        {cin>>t;a[t]++;}
    t=0;
    for(i=1;i<=m;i++)
    {
        for(j=i+1;j<=m;j++){
            //cout<<a[i]<<" "<<a[j]<<" "<<t<<endl;
            t+=a[i]*a[j];
        }
    }
    cout<<t<<endl;
    return 0;
}
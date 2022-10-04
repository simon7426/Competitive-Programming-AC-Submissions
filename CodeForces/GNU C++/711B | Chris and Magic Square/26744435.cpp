#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,j,t,x,y;
    cin>>n;
    int a[n][n];
    ll r[n+1],c[n+1],d[2],ma=0;
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    memset(d,0,sizeof d);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
        cin>>a[i][j];
        if(a[i][j]==0)
        {
            x=i,y=j;
        }
        r[i]+=a[i][j];
        c[j]+=a[i][j];
        ma=max(ma,max(r[i],c[j]));
        if(i==j)
            d[0]+=a[i][j];
        ma=max(d[0],ma);
        if(i+j==n-1) d[1]+=a[i][j];
        ma=max(d[1],ma);
        }
    }
    //cout<<d[0]<<" "<<d[1]<<endl;
    if(n==1) {cout<<1<<endl;return 0;}
    ll k=ma-r[x];
    r[x]=ma;
    c[y]+=k;
    if(x==y) d[0]+=k;
    if(x+y==n-1) d[1]+=k;
    for(i=0;i<n;i++)
    {
        if(r[i]!=ma||c[i]!=ma)
            break;
    }
    if(k<=0||i<n||d[0]!=ma||d[1]!=ma)
        cout<<-1<<endl;
    else
        cout<<k<<endl;
    return 0;
}
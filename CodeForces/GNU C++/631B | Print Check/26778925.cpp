#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mem(a,b) memset(a, b, sizeof(a) )
main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ma=max(m,max(n,k));
    int i,j,x,y,z;
    int r[ma+2],rt[ma+2],c[ma+1],ct[ma+1];
    mem(r,0);
    mem(c,0);
    mem(rt,0);
    mem(ct,0);
    for(i=0;i<k;i++)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            rt[y]=i+1;
            r[y]=z;
        }
        else if(x==2)
        {
            ct[y]=i+1;
            c[y]=z;
        }
    }
    /*for(i=0;i<k;i++)
        cout<<rt[i+1]<<" ";
    cout<<endl;
    for(i=0;i<k;i++)
        cout<<ct[i+1]<<" ";
        cout<<endl;
    for(i=0;i<k;i++)
        cout<<r[i+1]<<" ";
    cout<<endl;
    for(i=0;i<k;i++)
        cout<<c[i+1]<<" ";
        cout<<endl;*/
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(rt[i]>ct[j])
                cout<<r[i]<<" ";
            else if(rt[i]<ct[j])
                cout<<c[j]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
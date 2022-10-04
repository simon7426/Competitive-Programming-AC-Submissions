#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,b,i,t;
    cin>>n>>m;
    int x= __gcd(n,m);
    int a[x];
    memset(a,0,sizeof a);
    cin>>b;
    for(i=0;i<b;i++)
    {
        cin>>t;
        a[t%x]=1;
    }
    cin>>b;
    for(i=0;i<b;i++)
    {
        cin>>t;
        a[t%x]=1;
    }
    for(i=0;i<x;i++)
    {
        if(a[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
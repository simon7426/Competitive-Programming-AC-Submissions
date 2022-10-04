#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool com(pair<int,int> p,pair<int,int> q)
{
    if(p.first==q.first)
        return p.second > q.second;
    return p.first<q.first;
}
main()
{
    pair<int,int> a[9];
    int i,n,t,mi=100000010;
    cin>>n;
    for(i=0;i<9;i++)
    {
        cin>>t;
        a[i].first=t;
        a[i].second=i+1;
        mi=min(mi,t);
    }
    int r=n/mi;
    if(r==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(r--)
    for(i=8;i>=0;i--)
    {
        if((n-a[i].first)/mi==r&&n>=a[i].first)
        {
            cout<<i+1;
            n-=a[i].first;
            break;
        }
    }
        return 0;
}
 
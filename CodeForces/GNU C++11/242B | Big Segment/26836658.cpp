#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector< pair<int,int> > a,v;
 
bool com(const pair<int,int> &l,const pair<int,int> &r)
{
    return l.first>r.first;
}
 
main()
{
    int n,i,s,t,mi=1e9+5,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        a.push_back(make_pair(s,t));
        v.push_back(make_pair(t-s,i));
        mi=min(mi,s);
        ma=max(ma,t);
    }
    sort(v.begin(),v.end(),com);
    int x=v[0].second;
    if(a[x].first==mi&&a[x].second==ma)
        cout<<x+1<<endl;
    else
        cout<<-1<<endl;
}
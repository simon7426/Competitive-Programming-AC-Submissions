#include<iostream>
#include<map>
#include<utility>
#define pi pair<int,int>
using namespace std;
main()
{
    pi pp,qq;
    int n,m,i,j;
    cin>>n>>m;
    map< pi , pi > a;
    int p,q,r,s;
    for(i=0;i<n;i++)
    {
        cin>>p>>q>>r>>s;
        pp=make_pair(p,q);
        qq=make_pair(r,s);
        if(a[pp].second<=s)
            a[pp]=qq;
    }
    for(i=0;i<m;i++)
    {
        cin>>p>>q;
        pp=make_pair(p,q);
        cout<<a[pp].first<<endl;
    }
}

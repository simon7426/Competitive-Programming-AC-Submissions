#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
//typedefs
typedef long long int ll;
typedef vector<int> vi;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
main()
{
    optimize();
    int n,m,k,i,x=1,t,a=1,b=1;
    cin>>n>>m>>k;
    bool h[n+1];
    int v[n+1];
    memset(h,0,sizeof h);
    for(i=0;i<m;i++)
    {
        cin>>t;
        h[t]=1;
    }
    for(i=0;i<=n;i++)
        v[i]=i;
    for(i=0;i<k;i++)
    {
        if(v[a]==1&&h[a]==1) {cout<<a<<endl;return 0;}
        else if(v[b]==1&&h[b]==1){cout<<b<<endl;return 0;}
        cin>>a>>b;
        t=v[a];
        v[a]=v[b];
        v[b]=t;
        if(v[a]==1) x=a;
        if(v[b]==1) x=b;
    }
    cout<<x<<endl;
    return 0;
}
 
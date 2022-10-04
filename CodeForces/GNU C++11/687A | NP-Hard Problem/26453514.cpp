#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
vi g[100100];
vi a,b;
int vis[100100],f=0;
void dfs(int i,int x)
{
    vis[i]=x;
    if(vis[i]==1)a.push_back(i);
    if(vis[i]==2)b.push_back(i);
    //cout<<vis[i]<<" "<<i<<endl;
    for(int j=0;j<g[i].size();j++)
    {
        if(vis[i]==vis[g[i][j]])
        {
            f=1;
            return;
        }
        if(!vis[g[i][j]])
            dfs(g[i][j],vis[i]%2+1);
    }
}
main()
{
    int n,m,s,t,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>s>>t;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    memset(vis,0,sizeof vis);
    for(i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i,1);
    }
    if(f==1) {cout<<-1<<endl;return 0;}
    int cnt1=a.size();
    int cnt2=b.size();
    cout<<cnt1<<endl;
    for(i=0;i<cnt1;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<cnt2<<endl;
    for(i=0;i<cnt2;i++)
        cout<<b[i]<<" ";
        cout<<endl;
    return 0;
}
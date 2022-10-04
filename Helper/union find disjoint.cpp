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

vi p,ra,si;
int cnts;
multiset<int> ms[100010];
vector<int> g[100010];
void ufind(int n)
{
    ra.assign(n,0);
    p.assign(n,0);
    si.assign(n,1);
    for(int i=0;i<n;i++)
        p[i]=i;
    cnts=n-1;
}
int findset(int i) {return ((p[i]==i)?i:p[i]=findset(p[i]));}
bool issame(int i,int j) {return findset(i)==findset(j);}
void unionset(int i,int j)
{
    if(!issame(i,j))
    {
        cnts--;
        int x=findset(i);int y=findset(j);
        if(ra[x]>ra[y])
            {
                si[findset(x)]+=si[findset(y)];
                p[y]=x;
            }
        else
        {
            si[findset(y)]+=si[findset(x)];
            p[x]=y;
            if(ra[x]==ra[y]) ra[y]++;
        }
    }
}
int setsize(int n)
{
    return si[findset(n)];
}
int numofsets() {return cnts;}
main()
{
    int n,m,s,t,i,tc=0;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        ufind(n+1);
        for(i=0;i<m;i++)
            {scanf("%d %d",&s,&t);
            unionset(s,t);}
        printf("Case %d: %d\n",++tc,numofsets());
    }
    return 0;
}

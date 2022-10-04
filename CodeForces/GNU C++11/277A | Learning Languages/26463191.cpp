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
int cnts=0;
void ufind(int n)
{
    ra.assign(n,0);
    p.assign(n,0);
    si.assign(n,1);
    for(int i=0;i<n;i++)
        p[i]=i;
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
    int a[110];
    memset(a,0,sizeof a);
    int n,m,k,i,j,cnt=0,s,t;
    cin>>n>>m;
    ufind(m+1);
    for(i=0;i<n;i++)
    {
        cin>>k;
        if(k==0) cnt++;
        else
        {
            cin>>s;
            if(!a[s]) {cnts++;a[s]=1;}
            for(j=1;j<k;j++)
            {
                cin>>t;
                if(!a[t]){cnts++;a[t]=1;}
                unionset(s,t);
            }
        }
    }
    int x=((numofsets()==0)?0:numofsets()-1);
    //cout<<numofsets()<<" "<<cnt<<endl;
    cout<<x+cnt<<endl;
    return 0;
}
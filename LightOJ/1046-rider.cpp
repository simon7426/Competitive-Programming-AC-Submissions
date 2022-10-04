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

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

inline int in() { int x; scanf("%d", &x); return x; }
inline ll inl() { ll x;scanf("%I64d",&x); return x;}
inline double ind() { double x;scanf("%lf",&x);return x;}

int gcd(int a,int b) { return b==0 ? a:gcd(b,a%b);}
int power( int x, int n)
{
    if(n==0)return 1;
    else if(n%2==0)
    {
        int y=power(x,n/2);
        return y*y;
    }
    else
        return x*power(x,n-1);
}
//abcdefghijklmnopqrstuvwxyz//

struct rider
{
    int x,y,k;
    rider(){}
    rider(int a,int b,int c): x(a),y(b),k(c) {}
};

unsigned dis[12][12][11];
unsigned res[12][12];
int s[12][12];
int n,m;

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc,tc,i,j,k,l,x,y,z,a,b,c;
    unsigned d,mx;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        mem(res,0);
        vii v;
        scanf("%d %d",&n,&m);
        getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                s[i][j]=getchar()-'0';
                if(s[i][j]>0&&s[i][j]<10) v.pb(mp(i,j));
            }
            getchar();
        }
        rider p;
        for(i=0;i<v.size();i++)
        {
            memset(dis,-1,sizeof dis);
            queue<rider> q;
            q.push(rider(v[i].ff,v[i].ss,s[v[i].ff][v[i].ss]+1));
            dis[v[i].ff][v[i].ss][s[v[i].ff][v[i].ss]+1]=1;
            while(!q.empty())
            {
                x=q.front().x;
                y=q.front().y;
                k=q.front().k;
                q.pop();
                l=k-1;
                if(l==0) l=s[v[i].ff][v[i].ss];
                for(j=0;j<8;j++)
                {
                    a=x+dx[j];
                    b=y+dy[j];
                    if(a<0||a>=n||b<0||b>=m) continue;
                    d=dis[x][y][k]+(k == 1 ? 1 : 0);
                    if(dis[a][b][l]>d)
                    {
                        dis[a][b][l]=d;
                        q.push(rider(a,b,l));
                    }
                }
            }
            for(int it=0;it<n;it++)
            {
                for(j=0;j<m;j++)
                {
                    if(it!=v[i].ff||j!=v[i].ss)
                    {
                        mx=-1;
                        for(k=1;k<=10;k++)
                        {
                            if(mx>dis[it][j][k]) mx=dis[it][j][k];
                        }
                        if(mx==-1)
                            res[it][j]=-1;
                        else if(res[it][j]!=-1) res[it][j]+=mx;
                    }
                }
            }
        }
        mx=-1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
             //   cout<<res[i][j]<<" ";

                if(res[i][j]<mx) mx=res[i][j];
            }
           // cout<<endl;
        }
            printf("Case %d: %d\n",tc,mx);
    }
}



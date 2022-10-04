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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; ///4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};///8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};///Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; ///Hexagonal Direction

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
int n;
double w;
struct point
{
    int rnk,x,y;
}poi[1005];
struct edge
{
    int x,y,type;
    double len;
    edge (){}
    edge(int xx,int yy,double leng,int tp)
    {
        x=xx;y=yy;len=leng;type=tp;
    }
    bool operator< (const edge& right) const {return len<right.len;}
};
vector<edge> e;
double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int pa[1005];
int findp(int x)
{
    if(pa[x]==x) return x;
    else return pa[x]=findp(pa[x]);
}
void uni(int x,int y)
{
    int u=findp(x);
    int v=findp(y);
    if(u==v) return;
    if(u<v) pa[v]=u;
    if(v<u) pa[u]=v;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        e.clear();
        for(int i=0;i<1005;i++)
        {
            pa[i]=i;
        }
        n=in();
        w=ind();
        int f;
        for(int i=1;i<=n;i++)
        {
            int x=in(),y=in();
            poi[i]={i,x,y};
            for(int j=1;j<i;j++)
            {
                double dist=dis(poi[i].x,poi[i].y,poi[j].x,poi[j].y);
                if(dist<=w) f=1;
                else f=2;
                e.pb(edge(poi[i].rnk,poi[j].rnk,dist,f));
            }
        }
        sort(e.begin(),e.end());
        //for(int i=0;i<e.size();i++)
        //    cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].len<<" "<<e[i].type<<endl;
        double rail=0.0,road=0.0;
        int stacnt=0;
        for(int i=0;i<e.size();i++)
        {
            int u=findp(e[i].x);
            int v=findp(e[i].y);
            if(u==v) continue;
            uni(u,v);
            if(e[i].type==1)
            {
                road+=e[i].len;
            }
            else
            {
                rail+=e[i].len;
                stacnt++;
            }
        }
        printf("Case #%d: %d %d %d\n",tc,stacnt+1,(int)(road+0.5),(int)(rail+0.5));
    }
}


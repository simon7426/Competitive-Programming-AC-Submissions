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

const int maxn=1050;
int n,m;
int qn;
int f[maxn][maxn];

void update(int x,int y,int val)
{
    for(int i=x;i<=n;i=i|(i+1))
        for(int j=y;j<=n;j=j|(j+1))
        f[i][j]+=val;
}

int getsum(int x,int y)
{
    int res=0;
    for(int i=x;i>0;i=(i&(i+1))-1)
        for(int j=y;j>0;j=(j&(j+1))-1)
        res+=f[i][j];
    return res;
}

int getsum(int fx,int fy,int tx,int ty)
{
    return getsum(tx,ty)-getsum(tx,fy-1)-getsum(fx-1,ty)+getsum(fx-1,fy-1);
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        int t;
        scanf("%d",&t);
        update(i+1,j+1,t);
    }
    int q,typ,x,y,t;
    scanf("%d",&q);
    int fx,fy,tx,ty;
    for(i=0;i<q;i++)
    {
        scanf("%d",&typ);
        if(ty==1)
        {
            scanf("%d %d %d",&x,&y,&t);
            update(x,y,t);
        }
        else
        {
            scanf("%d%d%d%d",&fx,&fy,&tx,&ty);
            if(fx>tx) swap(fx,tx);
            if(fy>ty) swap(fy,ty);
            printf("%d\n",getsum(fx,fy,tx,ty));
        }
    }
    return 0;
}


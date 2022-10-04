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
const double infd=1e100,epsd=1e-12;

struct point
{
    double x,y;
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    double r()
    {
        return sqrt(x*x+y*y);
    }
    void print()
    {
        printf("%f %f\n",x,y);
    }
    bool operator<(const point &r)const
    {
        if(x<r.x) return 1;
        if(x>r.x) return 0;
        return y<r.y;
    }
    point operator-(point &r)
    {
        point res= {x-r.x,y-r.y};
        return res;
    }
    double slope()
    {
        if(x==0.0 && y==0.0) return -infd;
        if(x==0.0) return infd;
        return y/x;
    }
    double operator* (const point &r)
    {
        return x*r.y-y*r.x;
    }
    double dist_to(point &r)
    {
        return sqrt(sqr(x-r.x)+sqr(y-r.y));
    }
};

point O;
bool byslope(point l,point r)
{
    double ls=(l-O).slope(),rs=(r-O).slope();
    if(ls<rs)return 1;
    if(ls>rs)return 0;
    return l.dist_to(O)<r.dist_to(O);
}

vector<point> convex_hull(point *p,int n)
{
    if(n<=2) return vector<point>(p,p+n);
    sort(p,p+n);
    O=p[0];
    sort(p+1,p+n,byslope);
    vector<point> hull;
    for(int i=0;i<n;i++)
    {
        if(i<3)hull.pb(p[i]);
        else
        {
            int sz=hull.size();
            while(sz>=2 && (p[i]-hull[sz-2])*(hull[sz-1]-hull[sz-2])>=0)
                {
                    hull.pop_back();
                    sz--;
                }
            hull.pb(p[i]);
        }
    }
    return hull;
}

vector<point> v;
int nn;
point p[100010];

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    nn=in();
    for(int i=0;i<nn;i++)
    {
        p[i].read();
    }

    v=convex_hull(p,nn);
    for(int i=0;i<v.size();i++)
        v[i].print();
}


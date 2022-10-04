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
struct point
{
    int x,y;
    point()
    {}
    point(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    bool operator <(point &right)
    {
        return (abs(x)+abs(y))<=(abs(right.x)+abs(right.y));
    }
};
vector<point> p;
vii ans;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),i,j,u,v;
    char c[4]={'R','L','U','D'};
    for(i=0;i<n;i++)
    {
        u=in(),v=in();
        p.pb(point(u,v));
    }
    sort(p.begin(),p.end());
    /*printf("\n\n");
    for(i=0;i<n;i++)
        printf("%d %d\n",p[i].x,p[i].y);*/
    int x,y;
    for(i=0;i<n;i++)
    {
        x=p[i].x;
        y=p[i].y;
        if(x!=0)
        {
            if(x<0) ans.pb(mp(abs(x),2));
            else ans.pb(mp(abs(x),1));
        }
        if(y!=0)
        {
            if(y<0) ans.pb(mp(abs(y),4));
            else ans.pb(mp(abs(y),3));
        }
        ans.pb(mp(-2,0));
        x*=-1,y*=-1;
        if(y!=0)
        {
            if(y<0) ans.pb(mp(abs(y),4));
            else ans.pb(mp(abs(y),3));
        }
        if(x!=0)
        {
            if(x<0) ans.pb(mp(abs(x),2));
            else ans.pb(mp(abs(x),1));
        }
 
        ans.pb(mp(-3,0));
    }
    int cnt=ans.size();
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++)
    {
        if(ans[i].ff<0)
            printf("%d\n",-ans[i].ff);
        else
        {
            printf("1 %d %c\n",ans[i].ff,c[ans[i].ss-1]);
        }
    }
}
 
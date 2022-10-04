//lightoj 1306
//no of solutions in the given range
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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll xx,yy;
    ll d=exgcd(b,a%b,xx,yy);
    x=yy;
    y=xx-((a/b)*yy);
    return d;
}

void shiftsol(ll &x,ll &y,ll a,ll b,ll cnt)
{
    x+=cnt*b;
    y-=cnt*a;
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tc,tcc;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        ll a,b,c,x,y,g,x1,x2,y1,y2,x0,y0;
        scanf("%lld %lld %lld",&a,&b,&c);
        scanf("%lld %lld %lld %lld",&x1,&x2,&y1,&y2);
        c=-c;
        g=exgcd(a,b,x,y);
        if(g && c%g)
        {
            printf("Case %d: 0\n",tc);
        }
        else if(a==0&&b==0)
        {
            if(c==0)
            {
                printf("Case %d: %lld\n",tc,(x2-x1+1)*(y2-y1+1));
            }
            else
            {
                printf("Case %d: 0\n",tc);
            }
            continue;
        }
        else if(a==0)
        {
            if(c/b>=y1&&c/b<=y2)
                printf("Case %d: %lld\n",tc,x2-x1+1);
            else
                printf("Case %d: 0\n",tc);
            continue;
        }
        else if(b==0)
        {
            if(c/a>=x1&&c/a<=x2)
                printf("Case %d: %lld\n",tc,y2-y1+1);
            else
                printf("Case %d: 0\n",tc);
            continue;
        }
        else
        {
            x*=c/g;
            y*=c/g;
            //printf("%d %d\n",x,y);
            a/=g,b/=g;
            ll signa= a>0? 1:-1;
            ll signb= b>0? 1:-1;
            shiftsol(x,y,a,b,(x1-x)/b);
            if(x<x1)
                shiftsol(x,y,a,b,signb);
            if(x>x2)
            {
                printf("Case %d: 0\n",tc);
                continue;
            }
            ll lx1=x;
            //cout<<x<<" "<<y<<endl;
            shiftsol(x,y,a,b,(x2-x)/b);
            if(x>x2)
                shiftsol(x,y,a,b,-signb);
            ll rx1=x;
            //cout<<x<<" "<<y<<endl;
            shiftsol(x,y,a,b,-(y1-y)/a);
            if(y<y1)
                shiftsol(x,y,a,b,-signa);
            if(y>y2)
            {
                printf("Case %d: 0\n",tc);
                continue;
            }
            ll lx2=x;
            //cout<<x<<" "<<y<<endl;
            shiftsol(x,y,a,b,-(y2-y)/a);
            if(y>y2)
                shiftsol(x,y,a,b,signa);
            ll rx2=x;
            //cout<<x<<" "<<y<<endl;
            if(lx2>rx2)
                swap(lx2,rx2);
            //cout<<lx1<<" "<<lx2<<" "<<rx1<<" "<<rx2<<endl;
            ll lx=max(lx1,lx2);
            ll rx=min(rx1,rx2);
            //cout<<rx<<" "<<lx<<endl;
            ll ans=((rx-lx)/abs(b) )+ 1;
            //cout<<"here"<<endl;
            printf("Case %d: %lld\n",tc,max(0LL,ans));
        }
    }
}


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
char s[1010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=1;tc<=tcc;tc++)
    {
        scanf("%s",s);
        int n=strlen(s);
        int c0=0,c1=0,c2=0;
        int sum=0;
        if(n==1)
        {
            printf("Case %d: S\n",tc);
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')%3==0)c0++;
            else if((s[i]-'0')%3==1) c1++;
            else if((s[i]-'0')%3==2) c2++;
            sum+=(s[i]-'0');
        }
        int w;
        if(sum%3==0)
        {
            if(c0==0)
            {
                w=1;
            }
            else
            {
                if(c0%2==0) w=1;
                else w=0;
            }
        }
        else if(sum%3==1)
        {
            if(c1==0)
            {
                w=1;
            }
            else
            {
                if(c0%2==0) w=0;
                else w=1;
            }
        }
        else if(sum%3==2)
        {
            if(c2==0)
            {
                w=1;
            }
            else
            {
                if(c0%2==0) w=0;
                else w=1;
            }
        }
        printf("Case %d: ",tc);
        if(w==1) printf("T\n");
        else printf("S\n");
    }
}


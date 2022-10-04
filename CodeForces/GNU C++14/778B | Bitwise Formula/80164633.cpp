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
//#define mp make_pair
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
string nam,num[5010];
int op[5010],ln[5010],rn[5010],mi[5010],ma[5010],val[5010];
map<string,int> mp;
int n,m;
int lol(string x)
{
    if(x=="?")
         return n+1;
    return mp[x];
}
int F(int x)
{
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(op[i]==0)
            val[i]=(num[i][x]-'0');
        else if(op[i]==1)
            val[i]=(val[ln[i]]) & (val[rn[i]]);
        else if(op[i]==2)
            val[i]=(val[ln[i]]) | (val[rn[i]]);
        else if(op[i]==3)
            val[i]=(val[ln[i]]) ^ (val[rn[i]]);
        ret+=val[i];
    }
    return ret;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>nam;
        mp[nam]=i;
        cin>>nam>>num[i];
        if(num[i][0]=='0'||num[i][0]=='1')
            continue;
        ln[i]=lol(num[i]);
        cin>>nam>>num[i];
        if(nam[0]=='A') op[i]=1;
        else if (nam[0]=='O') op[i]=2;
        else op[i]=3;
        rn[i]=lol(num[i]);
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        val[n+1]=0;
        x=F(i);
        val[n+1]=1;
        y=F(i);
        //cout<<x<<" "<<y<<endl;
        if(x==y)
        {
            ma[i]=0;
            mi[i]=0;
        }
        else if(x>y)
        {
            ma[i]=0;
            mi[i]=1;
        }
        else if(x<y)
        {
            ma[i]=1;
            mi[i]=0;
        }
    }
    for(int i=0;i<m;i++) cout<<mi[i];
    cout<<endl;
    for(int i=0;i<m;i++) cout<<ma[i];
    cout<<endl;
}
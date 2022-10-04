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
const int mx=1e7+10;
bool pr[mx];
vi prime;
int cnt[mx];
int ans[1000010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    mem(pr,0);
    int i,j,k=1;
    int li=sqrt(mx)+20;
    for(i=2;i<=li;i+=k)
    {
        if(i==3)k=2;
        if(pr[i]==0){
                //printf("%d ",i);
        for(j=i*i;j<=mx;j+=i)
            pr[j]=1;
        }
    }
    for(i=2;i<=mx;i++)
        if(pr[i]==0) prime.pb(i);
    //for(i=0;i<65;i++) printf("%d ",prime[i]);
    mem(cnt,0);
    int n=in(),t;
    for(i=0;i<n;i++)
    {
        t=in();
        cnt[t]++;
    }
    for(i=0;i<prime.size();i++)
    {
        for(j=prime[i]+prime[i];j<mx;j+=prime[i])
            {
                cnt[prime[i]]+=cnt[j];
            }
    }
    //cout<<prime.size()<<endl;
    mem(ans,0);
    ans[0]=cnt[2];
    for(i=1;i<prime.size();i++)
        ans[i]=ans[i-1]+cnt[prime[i]];
    int m=in(),l,r,x,y;
    for(i=0;i<m;i++)
    {
        l=in(),r=in();
        x=lower_bound(prime.begin(),prime.end(),l)-prime.begin();
        y=upper_bound(prime.begin(),prime.end(),r)-prime.begin();
        //printf("%d %d\n",x,y);
        if(x==y)
            printf("0\n");
        else if(x==0)
            printf("%d\n",ans[y-1]);
        else
            printf("%d\n",ans[y-1]-ans[x-1]);
    }
 
}
 
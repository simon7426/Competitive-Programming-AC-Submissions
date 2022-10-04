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
int a[100010];
int nxt[100010],val[100010],last[100010];
int n,q;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();q=in();
    for(int i=1;i<=n;i++)
        a[i]=in();
    int R=sqrt(n),l,r,cur;
    int sz=(n-1)/R+1;
    for(int i=1;i<=sz;i++)
    {
        l=(i-1)*R+1;
        r=min(i*R,n);
        for(int j=l;j<=r;j++)
        {
            cur=j;
            last[j]=cur;
            while(cur<=r)
            {
                cur+=a[cur];
                val[j]++;
                nxt[j]=cur;
                if(cur<=r)last[j]=cur;
            }
        }
    }
    //for(int i=1;i<=n;i++) printf("%d ",nxt[i]); printf("\n");
    int ty,x,y,block;
    for(int i=0;i<q;i++)
    {
        ty=in();x=in();
        if(ty==0)
        {
            y=in();
            a[x]=y;
            block=(x-1)/R+1;
            l=(block-1)*R+1;
            r=min(block*R,n);
            cur=x;
            val[x]=0;
            if(x+a[x]>0)
            {
                nxt[x]=x+a[x];
                val[x]=1;
                last[x]=x;
            }
            else
            {
                nxt[x]=nxt[x+a[x]];
                val[x]=val[x+a[x]]+1;
                last[x]=last[x+a[x]];
            }
            for(int j=x-1;j>=l;j--)
            {
                if(j+a[j]<=r)
                {
                    nxt[j]=nxt[j+a[j]];
                    val[j]=val[j+a[j]]+1;
                    last[j]=last[j+a[j]];
                }
                else
                {
                    nxt[j]=j+a[j];
                    val[j]=1;
                    last[j]=j;
                }
            }
        }
        else
        {
            int ans=0;
            while(nxt[x]<=n)
            {
                //printf("%d\n",x);
                ans+=val[x];
                x=nxt[x];
            }
            ans+=val[x];
            printf("%d %d\n",last[x],ans);
        }
    }
}
/*
8 5
1 1 1 1 1 2 8 2
*/
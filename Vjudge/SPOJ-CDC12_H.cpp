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
#define Si 400100
//Segment tree
#define left(x) x<<1
#define right(x) (x<<1)+1
ll st[Si],lazy[Si];
int n;
void update(int p,int l,int r,int i,int j,ll v)
{
    if(lazy[p]!=0)
    {
        st[p]+=(r-l+1)*lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        lazy[p]=0;
    }

    if(l>r||l>j||r<i) return;

    if(l>=i&&r<=j)
    {
        st[p]+=(r-l+1)*v;
        if(l!=r)
        {
            lazy[left(p)]+=v;
            lazy[right(p)]+=v;
        }
       // printf("%d %d %d %d ",l,r,i,j);
       // printf("%d %d\n",st[p],v);
        return;
    }

    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}
void update(int i,int j,int v)
{
    update(1,0,n-1,i,j,v);
}
ll rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=0)
    {
        st[p]+=(r-l+1)*lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        lazy[p]=0;
    }
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return p1+p2;
}
ll rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}

char c[20];
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,t,i,j,k,l,r,q,v;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        memset(st,0,sizeof st);
        memset(lazy,0,sizeof lazy);
        n=in();
        int m=in();
        printf("Scenario #%d:\n",t);
        for(i=0;i<m;i++)
        {
           scanf("%s %d %d",c,&l,&r);
           --l,--r;
          // printf("%s %d %d\n",c,l,r);
            if(c[0]=='m')
            {
                update(l,r,1);
                printf("OK\n");
            }
            else
            {
                printf("%lld\n",rmq(l,r));
            }
        }
    }
    return 0;
}


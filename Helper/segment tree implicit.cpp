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
struct node
{
    ll sum;
    node *l,*r;
    node() : sum(0),l(NULL),r(NULL) {}
};

void add(node *v,int b,int e,int l,int r,ll val)
{
    if(l>r||r<b||l>e)
        return;
    if(l<=b && e<=r)
    {
        v->sum+=val;
        return;
    }
    int mid=(b+e)>>1;
    if(v->l==NULL)
        v->l=new node();
    if(v->r==NULL)
        v->r=new node();
    add(v->l,b,mid,l,r,val);
    add(v->r,mid+1,e,l,r,val);
}

ll get(node *v,int l,int r,int pos)
{
    if(!v||l>r||pos<l||pos>r)
        return 0;
    if(l==r)
        return v->sum;
    int mid=(l+r)>>1;
    return v->sum+get(v->l,l,mid,pos)+get(v->r,mid+1,r,pos);
}
int n,m,x,y;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    node *root = new node();
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        add(root,0,n-1,i,i,x);
    }
    int qt,l,r;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&qt);
        if(qt==1)
        {
            scanf("%d%d%d",&l,&r,&x);
            add(root,0,n-1,l,r,x);
        }
        else
        {
            scanf("%d",&x);
            printf("%I64d\n",get(root,0,n-1,x));
        }
    }
}


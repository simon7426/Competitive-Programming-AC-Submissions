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
    int y,val;
    int sz,mn;
    bool rev;
    node *l,*r;
    node (int nval,int ny) //nval = new value, ny= new y
    {
        y=ny;
        val=nval;
        sz=1;
        mn=val;
        rev=false;
        l=NULL;
        r=NULL;
    }
};

typedef node *pnode;

int getsize(pnode t)
{
    if(t==NULL)
        return 0;
    return t->sz;
}

int getmin(pnode t)
{
    if(t==NULL)
        return inf;
    return t->mn;
}

void update(pnode t)
{
    if(t==NULL)
        return;
    t->sz=getsize(t->l)+1+getsize(t->r);
    t->mn=min(t->val,min(getmin(t->l),getmin(t->r)));
}

void push(pnode t)
{
    if(t&&t->rev)
    {
        swap(t->l,t->r);
        if(t->l) t->l->rev ^= true;
        if(t->r) t->r->rev ^= true;
        t->rev=false;
    }
}

void merge(pnode &t,pnode l,pnode r)
{
    push(l);
    push(r);
    if(l==NULL)
        t=r;
    else if(r==NULL)
        t=l;
    else if(l->y > r->y)
        {
            merge(l->r,l->r,r);
            t=l;
        }
    else
    {
        merge(r->l,l,r->l);
        t=r;
    }
    update(t);
}

void split(pnode t,pnode &l,pnode &r,int x,int add=0)
{
    push(t);
    if(t==NULL)
    {
        l=r=NULL;
        return;
    }
    int key=getsize(t->l)+1+add;
    if(x<=key)
    {
        split(t->l,l,t->l,x,add);
        r=t;
    }
    else
    {
        split(t->r,t->r,r,x,add+getsize(t->l)+1);
        l=t;
    }
    update(t);
}

void reverse(pnode t,int l,int r)
{
    pnode a,b;
    split(t,t,a,l,0);
    split(a,a,b,r-l+2,0);
    a->rev ^= true;
    merge(t,t,a);
    merge(t,t,b);
}

int getmin(pnode t,int l,int r)
{
    int ans;
    pnode a,b;
    split(t,t,a,l,0);
    split(a,a,b,r-l+2,0);
    ans=getmin(a);
    merge(t,t,a);
    merge(t,t,b);
    return ans;
}

int n,m;
int q,l,r;
pnode root=NULL,add;

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        add = new node(x,rand());
        merge(root,root,add);
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&q,&l,&r);
        if(q==1)
            reverse(root,l,r);
        else
            printf("%d\n",getmin(root,l,r));
    }
    return 0;
}


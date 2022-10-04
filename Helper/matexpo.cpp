//CF 718c
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
const int mx=400010;
#define left(x) x<<1
#define right(x) (x<<1)+1
int a[100010],n,m;

struct mat
{
    int m[2][2];
    mat(int a=0,int b=0,int c=0,int d=0)
    {
        m[0][0]=a;
        m[0][1]=b;
        m[1][0]=c;
        m[1][1]=d;
    }
    mat operator * (const mat &a) const
    {
        mat ret;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                ret.m[i][j]=((ll)m[i][0]*(ll)a.m[0][j]+(ll)m[i][1]*(ll)a.m[1][j])%MOD;
            }
        }
        return ret;
    }
    mat operator + (const mat &a) const
    {
        mat ret;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                ret.m[i][j]=(m[i][j]+a.m[i][j])%MOD;
        }
        return ret;
    }
}S(1,1,1,0),B(1,0,0,1),tmp;



mat qpow(mat a,int b)
{
    mat ret=B;
    for(;b;b>>=1)
    {
        if(b&1) ret=ret*a;
        a=a*a;
    }
    return ret;
}

struct segmenttree
{
    int n;
    mat st[mx];
    mat lazy[mx];
    build()
    {
        mem(st,0);
        mem(lazy,0);
        build(1,0,n-1);
    }
    void build(int p,int l,int r)
    {
        lazy[p]=B;
        if(l==r)
            {
            st[p]=qpow(S,a[l]-1);
            //printf("%d %d %d %d\n",p,l,r,st[p]);
            }
        else
        {
            build(left(p),l,(l+r)/2);
            build(right(p),(l+r)/2+1,r);
            mat p1=st[left(p)],p2=st[right(p)];
            st[p]=p1+p2;
            //printf("%d %d %d %d\n",p,l,r,st[p]);
        }
    }
    void update(int p,int l,int r,int i,int j,int v)
    {
        if(lazy[p].m[0][1]!=0)
        {
            if(l!=r)
            {
                lazy[left(p)]=lazy[left(p)]*lazy[p];
                lazy[right(p)]=lazy[right(p)]*lazy[p];
            st[left(p)]=st[left(p)]*lazy[p];
            st[right(p)]=st[right(p)]*lazy[p];
            lazy[p]=B;
            }
        }
        //printf("%d %d %d %d\n",l,r,i,j);
        if(l>r||l>j||r<i) return;
        if(l>=i&&r<=j)
        {
            st[p]=st[p]*tmp;
            lazy[p]=lazy[p]*tmp;
            return;
        }
        //printf("%d %d\n",st[p],v);
        update(left(p),l,(l+r)/2,i,j,v);
        update(right(p),1+(l+r)/2,r,i,j,v);
        mat p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
    }

    void update(int i,int j,int v)
    {
        update(1,0,n-1,i,j,v);
    }

    int query(int p,int l,int r,int i,int j)
    {
        if(i>r||j<l)
            return -1;
        if(lazy[p].m[0][1]!=0)
        {
            if(l!=r)
            {
                lazy[left(p)]=lazy[left(p)]*lazy[p];
                lazy[right(p)]=lazy[right(p)]*lazy[p];
            st[left(p)]=st[left(p)]*lazy[p];
            st[right(p)]=st[right(p)]*lazy[p];
            }
            lazy[p]=B;
        }
        if(l>=i&&r<=j) return st[p].m[0][0];
        int p1=query(left(p),l,(l+r)/2,i,j);
        int p2=query(right(p),(l+r)/2+1,r,i,j);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        return (p1+p2)%MOD;
    }
    int query(int i,int j)
    {
        return query(1,0,n-1,i,j);
    }
};

segmenttree seg;

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=in();
    m=in();
    for(int i=0;i<n;i++) a[i]=in();
    seg.n=n;
    seg.build(1,0,n-1);
    int t,x,y,z;
    for(int i=0;i<m;i++)
    {
        t=in(),x=in(),y=in();
        x--;
        y--;
        if(t==1)
        {
            z=in();
            tmp=qpow(S,z);
            seg.update(x,y,z);
        }
        else
        {
            printf("%d\n",seg.query(x,y));
        }
    }

}
/*
18 19
2 2 2 2 1 1 1 1 1 2 1 2 2 1 2 1 2 2
2 4 14
2 16 16
2 5 8
1 1 6 2
2 14 14
2 1 3
2 4 5
2 11 13
2 18 18
1 8 15 2
2 17 18
2 14 16
1 3 10 2
2 1 9
1 3 18 1
1 17 18 1
2 17 17
1 15 15 1
1 3 18 2
*/

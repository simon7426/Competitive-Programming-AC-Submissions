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
const int mxn=100010;
char T[mxn];
int n,ra[mxn],tempra[mxn];
int sa[mxn],tempsa[mxn];
int c[mxn];
int phi[mxn],plcp[mxn],lcp[mxn];

void countsort(int k)
{
    int i,sum,maxi=max(n,300);
    memset(c,0,sizeof c);
    for(i=0;i<n;i++)
        c[i + k < n ? ra[i+k] : 0 ]++;
    for(i=sum=0;i<maxi;i++)
        {
            int t=c[i];c[i]=sum;sum+=t;
        }
    for(i=0;i<n;i++)
        tempsa[ c[sa[i]+k<n ? ra[sa[i]+k] : 0 ]++]=sa[i];
    for(i=0;i<n;i++)
        sa[i]=tempsa[i];
}

void consuffixa()
{
    int i,k,r;
    for(i=0;i<n;i++) ra[i]=T[i];
    for(i=0;i<n;i++) sa[i]=i;
    for(k=1;k<n;k<<=1)
    {
        countsort(k);
        countsort(0);
        tempra[sa[0]]=r=0;
        for(i=1;i<n;i++)
            tempra[sa[i]]=(ra[sa[i]]==ra[sa[i-1]]&&ra[sa[i]+k]==ra[sa[i-1]+k])? r : ++r;
        for(i=0;i<n;i++)
            ra[i]=tempra[i];
        if(ra[sa[n-1]]==n-1) break;
    }
}

void complcp()
{
    int i,l;
    phi[sa[0]]=-1;
    for(i=1;i<n;i++)
        phi[sa[i]]=sa[i-1];
    for(i=l=0;i<n;i++)
    {
        if(phi[i]==-1) {plcp[i]=0;continue;}
        while(T[i+l]==T[phi[i]+l]) l++;
        plcp[i]=l;
        l=max(l-1,0);
    }
    for(i=0;i<n;i++)
        lcp[i]=plcp[sa[i]];
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    n=(int)strlen(gets(T));
    T[n++]='$';
    consuffixa();
    complcp();
    for(int i=0;i<n;i++)
        printf("%2d\t%d\t%s\n",sa[i],lcp[i],T+sa[i]);
}


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

const double pi = acos(-1);
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
typedef complex<double> comp;
const int maxn = 505000;
int rev[maxn*2];

void fft(comp p[],int n,bool invert)
{
    int dig=0;
    while((1<<dig)<n)
    {
        dig++;
    }
    for(int i=0;i<n;i++)
    {
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(dig-1));
        if(rev[i]>i)
            swap(p[i],p[rev[i]]);
    }
    for(int len=2;len<=n;len<<=1)
    {
        double angle=2*pi/len;
        if(invert)
            angle*=-1;
        comp wgo(cos(angle),sin(angle));
        for(int i=0;i<n;i+=len)
        {
            comp w(1);
            for(int j=0;j<(len>>1);j++)
            {
                comp a = p[i+j],b=w*p[i+j+(len>>1)];
                p[i+j]=a+b;
                p[i+j+(len>>1)]=a-b;
                w*=wgo;
            }
        }
    }
    if(invert)
    {
        for(int i=0;i<n;i++)
            p[i]/=n;
    }
}

comp a[maxn*2],b[maxn*2];
int ans[maxn*2];
int alen,blen,total;

void readpolynom(comp p[],int &len,bool space)
{
    string s;
    if(space)
        getline(cin,s,' ');
    else
        getline(cin,s);
    len=1;
    while(len<(int)s.length())
        len*=2;
    memset(p,0,sizeof p);
    int pos=0;
    for(int i=(int)s.length()-1;i>=0;i--)
    {
        comp coeff(s[i]-'0');
        p[pos]=coeff;
        pos++;
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    readpolynom(a,alen,true);
    readpolynom(b,blen,false);
    total=max(alen,blen);
    total*=2;
    fft(a,total,false);
    fft(b,total,false);
    for(int i=0;i<total;i++)
        a[i]=a[i]*b[i];
    fft(a,total,true);
    for(int i=0;i<total;i++)
        ans[i]=(int) floor(a[i].real()+0.5);
    int go=0;
    for(int i=0;i<total;i++)
    {
        ans[i]+=go;
        go=ans[i]/10;
        ans[i]%=10;
    }
    int ans_ind=total-1;
    while(ans_ind>0&&ans[ans_ind]==0)
        ans_ind--;
    for(int i=ans_ind;i>=0;i--)
        printf("%d",ans[i]);
    printf("\n");
}


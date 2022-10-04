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
char ss[1010],fs[1010];
vi r2,p2,s2;
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int tc=0;tc<tcc;tc++)
    {
        mem(fs,0);
        r2.clear();
        p2.clear();
        s2.clear();
        int n=in();
        int r,p,s;
        scanf("%d %d %d\n",&r,&p,&s);
        scanf("%s",ss);
        //printf("%s\n",ss);
        int r1,p1,s1;
        r1=p1=s1=0;
        for(int i=0;i<strlen(ss);i++)
        {
            if(ss[i]=='R') {r1++;r2.pb(i);}
            if(ss[i]=='P') {p1++;p2.pb(i);}
            if(ss[i]=='S') {s1++;s2.pb(i);}
        }
        int wincnt=0;
        if(r>=s1)
        {
            wincnt+=s1;
            r-=s1;
            for(int i=0;i<s2.size();i++) fs[s2[i]]='R';
        }
        else
        {
            wincnt=r;
            for(int i=0;i<r;i++) fs[s2[i]]='R';
            r=0;
        }
        if(p>=r1)
        {
            wincnt+=r1;
            p-=r1;
            for(int i=0;i<r2.size();i++) fs[r2[i]]='P';
        }
        else
        {
            wincnt+=p;
 
            for(int i=0;i<p;i++) fs[r2[i]]='P';
            p=0;
        }
        if(s>=p1)
        {
            wincnt+=p1;
            s-=p1;
            for(int i=0;i<p2.size();i++) fs[p2[i]]='S';
 
        }
        else
        {
            wincnt+=s;
            for(int i=0;i<s;i++) fs[p2[i]]='S';
            s=0;
        }
        //printf("%d\n",wincnt);
        int lim=(n+1)/2;
        if(wincnt<lim)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0;i<n;i++)
            {
                //printf("%d ",fs[i]);
                if(fs[i]==0)
                {
                    if(r!=0)
                    {
                        fs[i]='R';
                        r--;
                    }
                    else if(p!=0)
                    {
                        fs[i]='P';
                        p--;
                    }
                    else if(s!=0)
                    {
                        fs[i]='S';
                        s--;
                    }
                }
 
            }
             printf("%s\n",fs);
        }
    }
}
 
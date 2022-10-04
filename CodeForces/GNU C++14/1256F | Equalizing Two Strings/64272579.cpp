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
char s[200010],t[200010];
int sc[30],tc[30];
int tmp1[30],tmp2[30];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc=in();
    for(int lol=1;lol<=tcc;lol++)
    {
        mem(sc,0);
        mem(tc,0);
        int n=in();
        scanf("%s",s);
        scanf("%s",t);
        for(int i=0;i<n;i++)
        {
            sc[s[i]-'a']++;
            tc[t[i]-'a']++;
        }
        int f=0;
        for(int i=0;i<26;i++)
        {
            if(sc[i]!=tc[i])
            {
                printf("NO\n");
                f=1;
                break;
            }
        }
        if(f==1) continue;
        for(int i=0;i<26;i++)
        {
            if(sc[i]>=2)
            {
                f=1;break;
            }
        }
        if(f==1){printf("YES\n");continue;}
        for(int i=0;i<n;i++)
            tmp1[t[i]-'a']=i+1;
        for(int i=0;i<n;i++)
            tmp2[i]=tmp1[s[i]-'a'];
        f=1;
        int cnt=0;
        while(f)
        {
            f=0;
            for(int i=0;i<n-1;i++)
            {
                if(tmp2[i]>tmp2[i+1])
                {
                    swap(tmp2[i],tmp2[i+1]);
                    cnt++;
                    f=1;
                }
            }
        }
        if(cnt&1) printf("NO\n");
        else printf("YES\n");
    }
}
 
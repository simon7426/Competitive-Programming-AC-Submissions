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
char s[3][100010];
int f[3][100010],si[3];
void prekmp(int x)
{
    int i=0,j=-1,m=si[x];
    f[x][0]=-1;
    while(i<m)
    {
        while(j>=0&&s[x][i]!=s[x][j]) j=f[x][j];
        i++,j++;
        f[x][i]=j;
    }
}
int kmp(int x,int y)
{
    int i=0,j=0;
    while(i<si[x]&&j<si[y])
    {
        if(j==-1||s[x][i]==s[y][j])
        {
            i++;
            j++;
        }
        else j=f[y][j];
    }
    return j;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    scanf("%s%s%s",s[0],s[1],s[2]);
    //printf("%s %s %s\n",s[0],s[1],s[2]);
    for(int i=0;i<3;i++)
    {
        si[i]=strlen(s[i]);
        prekmp(i);
    }
    int ans=0,ma,tmp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j) continue;
            for(int k=0;k<3;k++)
            {
                if(i==k||j==k) continue;
                ma=kmp(i,j);
                if(ma==si[j])
                    ma+=kmp(i,k);
                else
                    ma+=kmp(j,k);
                ans=max(ans,ma);
            }
        }
    }
    printf("%d\n",si[0]+si[1]+si[2]-ans);
}
 
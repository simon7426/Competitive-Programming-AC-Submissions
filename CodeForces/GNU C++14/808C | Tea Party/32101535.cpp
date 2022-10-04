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
    int pos,val,cnt;
}a[110];
bool com1(node a,node b)
{
    return a.val>b.val;
}
bool com2(node a,node b)
{
    return a.pos<b.pos;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int n=in(),w=in(),i,j,t;
    for(i=0;i<n;i++)
    {
       a[i].val=in();
       a[i].pos=i;
       a[i].cnt=ceil((double)a[i].val/2.0);
       w-=a[i].cnt;
    }
    if(w<0)
    {
        printf("-1\n");
        return 0;
    }
    sort(a,a+n,com1);
   // for(i=0;i<n;i++)
   //     cout<<a[i].val<<" "<<a[i].cnt<<endl;
    for(i=n-2;i>=0;i--)
    {
        if(a[i].cnt<a[i+1].cnt)
        {
            t=a[i+1].cnt-a[i].cnt;
            a[i].cnt=a[i+1].cnt;
            w-=t;
        }
        if(w<0)
        {
            printf("-1\n");
            return 0;
        }
    }
 
    for(i=0;i<n;i++)
    {
        if(a[i].cnt+w>a[i].val)
        {
            w-=(a[i].val-a[i].cnt);
            a[i].cnt=a[i].val;
        }
        else
        {
            a[i].cnt+=w;
            break;
        }
    }
    sort(a,a+n,com2);
    for(i=0;i<n;i++)
        printf("%d ",a[i].cnt);
    printf("\n");
}
 
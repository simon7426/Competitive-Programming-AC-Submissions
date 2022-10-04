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
char box[5][5];
int xcnt=0,ocnt=0;
bool won(char x)
{
    for(int i=0;i<3;i++)
    {
        if(box[i][0]==x&&box[i][1]==x&&box[i][2]==x) return true;
        if(box[0][i]==x&&box[1][i]==x&&box[2][i]==x) return true;
    }
    if(box[0][0]==x&&box[1][1]==x&&box[2][2]==x) return true;
    if(box[0][2]==x&&box[1][1]==x&&box[2][0]==x) return true;
    return false;
}
bool llegal()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    {
        if(box[i][j]=='X')xcnt++;
        if(box[i][j]=='0')ocnt++;
    }
    //printf("%d %d\n",xcnt,ocnt);
    if(xcnt-ocnt>1) return false;
    if(ocnt-xcnt>0) return false;
    if(xcnt+ocnt>9) return false;
    if(won('X')&&xcnt==ocnt) return false;
    if(won('0')&&xcnt>ocnt) return false;
    return true;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int i;
    for(i=0;i<3;i++)
        scanf("%s",box[i]);
    if(!llegal())
    {
        printf("illegal\n");
    }
    else if(won('X')) printf("the first player won\n");
    else if(won('0')) printf("the second player won\n");
    else if(xcnt+ocnt==9) printf("draw\n");
    else if(xcnt>ocnt) printf("second\n");
    else printf("first\n");
    return 0;
}


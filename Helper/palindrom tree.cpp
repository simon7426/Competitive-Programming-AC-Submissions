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
const int maxn=105000;

struct node
{
    int next[26];
    int len;
    int sufflink;
    int num;
};

int len;
char s[maxn];
node tree[maxn];
int num;
int suff;
ll ans;

bool addletter(int pos)
{
    int cur=suff,curlen=0;
    int let=s[pos]-'a';

    while(true)
    {
        curlen=tree[cur].len;
        if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])
            break;
        cur=tree[cur].sufflink;
    }
    if(tree[cur].next[let])
    {
        suff=tree[cur].next[let];
        return false;
    }

    num++;

    suff=num;
    tree[num].len=tree[cur].len+2;
    tree[cur].next[let]=num;

    if(tree[num].len==1)
    {
        tree[num].sufflink=2;
        tree[num].num=1;
        return true;
    }
    while(true)
    {
        cur=tree[cur].sufflink;
        curlen=tree[cur].len;
        if(pos-1-curlen>=0 && s[pos-1-curlen]==s[pos])
        {
            tree[num].sufflink=tree[cur].next[let];
            break;
        }
    }
    tree[num].num=1+tree[tree[num].sufflink].num;
    return true;
}

void inittree()
{
    num=2;suff=2;
    tree[1].len=-1;
    tree[1].sufflink=1;
    tree[2].len=0;tree[2].sufflink=1;
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    gets(s);
    len=strlen(s);
    inittree();

    for(int i=0;i<len;i++)
    {
        addletter(i);
        ans+=tree[suff].num;
    }
    printf("%lld\n",ans);
}


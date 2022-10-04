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
int n,k;
string s;
struct node
{
    bool fin;
    node *chi[27];
    node()
    {
        fin=false;
        for(int i=0;i<26;i++)
            chi[i]=NULL;
    }
}*root;
 
void insert(string &str,int len)
{
    node *cur=root;
    for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(cur->chi[x]==NULL)
            cur->chi[x]=new node();
        cur=cur->chi[x];
    }
    cur->fin=true;
}
bool win(node *cur)
{
    for(int i=0;i<26;i++)
    {
        if(cur->chi[i]==NULL) continue;
        if(!win(cur->chi[i]))return true;
    }
    return false;
}
bool loss(node *cur)
{
    bool flag=false;
    for(int i=0;i<26;i++)
    {
        if(cur->chi[i]!=NULL)
        {
            flag=true;
            break;
        }
    }
    if(!flag) return true;
    for(int i=0;i<26;i++)
    {
        if(cur->chi[i]==NULL) continue;
        if(!loss(cur->chi[i])) return true;
    }
    return false;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    root=new node();
    cin>>n>>k;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>s;
        int x=s.size();
        insert(s,x);
    }
    int a=win(root),b=loss(root);
    if(!a) cout<<"Second"<<endl;
    else if(b||k&1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
 
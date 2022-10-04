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
    bool fin;
    node *next[4];
    node ()
    {
        fin=false;
        for(int i=0;i<3;i++) next[i]=NULL;
    }
};
node *root;
string s1,s2;
void add(string s)
{
    node *cur=root;
    for(int i=0;i<s.size();i++)
    {
        int x=s[i]-'a';
        if(cur->next[x]==NULL)
        {
            cur->next[x]=new node();
        }
        cur=cur->next[x];
    }
    cur->fin=true;
}
bool query(node *cur,int pos,int flag)
{
    if(pos==s2.size())
    {
        if(cur->fin==true&&flag) return true;
        else return false;
    }
    int x=s2[pos]-'a';
    bool ans=false;
    for(int i=0;i<3;i++)
    {
        if(cur->next[i]==NULL) continue;
        if(i!=x)
        {
            if(!flag) ans|=query(cur->next[i],pos+1,1);
        }
        if(i==x) ans|=query(cur->next[i],pos+1,flag);
    }
    return ans;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    root= new node();
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        cin>>s1;
        add(s1);
    }
    while(m--)
    {
        cin>>s2;
        if(query(root,0,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
 
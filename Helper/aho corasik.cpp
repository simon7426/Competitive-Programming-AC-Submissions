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
    int suff_link,par;
    char c;
    map<char,int> go;
    bool is_word;
    node()
    {
        suff_link=-1,par=-1;
        is_word=false;
    }
};

int n;
char s[maxn];
vector<node> trie;

void TrieInsert(char s[maxn])
{
    int cur_node=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int go=trie[cur_node].go[s[i]];
        if(go==0)
        {
            node add;
            add.par=cur_node;
            add.c=s[i];
            trie.push_back(add);
            go=(int) trie.size()-1;
            trie[cur_node].go[s[i]]=go;
        }
        cur_node=go;
    }
    trie[cur_node].is_word=true;
}

int GetSuffLink(int cur_node);

int go(int cur_node,int c)
{
    if(trie[cur_node].go.count(c)>0)
        return trie[cur_node].go[c];
    if(cur_node==0)
        return trie[cur_node].go[c]=0;
    int suff_link=GetSuffLink(cur_node);
    return trie[cur_node].go[c]=go(suff_link,c);
}

int GetSuffLink(int cur_node)
{
    if(trie[cur_node].suff_link!=-1)
        return trie[cur_node].suff_link;
    if(trie[cur_node].par==0)
        return trie[cur_node].suff_link=0;
    char c=trie[cur_node].c;
    int parent=trie[cur_node].par;
    return trie[cur_node].suff_link=go(trie[parent].suff_link,c);
}



void BuildAhoCorasick()
{
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int cur_node=q.front();
        q.pop();

        for(map<char,int> :: iterator it=trie[cur_node].go.begin();it!= trie[cur_node].go.end();it++)
        {
            q.push(it->second);
        }
        int suff_link=GetSuffLink(cur_node);
        trie[cur_node].suff_link=suff_link;
        if(trie[suff_link].is_word)
            trie[cur_node].is_word=true;
    }
}

main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    node root;
    root.suff_link=0;
    trie.push_back(root);

    scanf("%d",&n);
    gets(s);

    for(int i=1;i<=n;i++)
    {
        gets(s);
        TrieInsert(s);
    }

    BuildAhoCorasick();

    while(gets(s))
    {
        int cur_node=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            cur_node=go(cur_node,s[i]);
            if(trie[cur_node].is_word)
            {
                puts(s);
                break;
            }
        }
    }
    return 0;
}


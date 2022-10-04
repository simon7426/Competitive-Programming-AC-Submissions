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
int tree[21][400100], lazy[21][400100], a[100100];
ll tmp[21];
 
void build(int node, int l, int r, int val) {
        if(l == r) {
                if(a[l]&(1<<val)) tree[val][node] = 1;
                return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, val);
        build(node*2 + 1, mid+1, r, val);
        tree[val][node] = tree[val][node*2] + tree[val][node*2 + 1];
}
 
void update(int node, int l, int r, int b, int e, int val) {
        if(lazy[val][node]) {
                tree[val][node] = (r-l+1)-tree[val][node];
                if(l != r) lazy[val][node*2] ^= 1, lazy[val][node*2 + 1] ^= 1;
                lazy[val][node] = 0;
        }
        if(l > e || r < b) return;
        if(l >= b && r <= e) {
                tree[val][node] = (r-l+1)-tree[val][node];
                if(l != r) lazy[val][node*2] ^= 1, lazy[val][node*2 + 1] ^= 1;
                return;
        }
        int mid = (l+r)/2;
        update(node*2, l, mid, b, e, val);
        update(node*2 + 1, mid+1, r, b, e, val);
        tree[val][node] = tree[val][node*2] + tree[val][node*2 + 1];
}
 
int query(int node, int l, int r, int b, int e, int val) {
        if(lazy[val][node]) {
                tree[val][node] = (r-l+1)-tree[val][node];
                if(l != r) lazy[val][node*2] ^= 1, lazy[val][node*2 + 1] ^= 1;
                lazy[val][node] = 0;
        }
        if(l > e || r < b) return 0;
        if(l >= b && r <= e) return tree[val][node];
        int mid = (l+r)/2;
        return query(node*2, l, mid, b, e, val) + query(node*2 + 1, mid+1, r, b, e, val);
}
 
int main()
{
 
        for(int i = 1, j = 0; j < 21; ++j, i *= 2) tmp[j] = i;
        int n=in();
        for(int i = 0; i < n; ++i) a[i]=in();
        for(int i = 0; i < 21; ++i) build(1, 0, n-1, i);
        int m=in();
        while(m--)
            {
                int t=in();
                if(t == 1) {
                        int l, r;
                        l=in(),r=in();
                        ll ans = 0LL;
                        for(int i = 0; i < 21; ++i) ans += tmp[i] * query(1, 0, n-1, l-1, r-1, i);
                        printf("%lld\n", ans);
                }
                else {
                        int l, r, x;
                        l=in(),r=in(),x=in();
                        for(int i = 0; i < 21; ++i) if(x&(1<<i)) update(1, 0, n-1, l-1, r-1, i);
                }
        }
 
        return 0;
}
 
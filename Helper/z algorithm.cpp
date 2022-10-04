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
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int z[1000010];
int cnt[1000010];
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    string s;
    cin>>s;
    int n=s.size(),i,t;
    mem(z,0);
    z[0]=-1;
    int l=0,r=0;
    for(i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<n&&s[r-l]==s[r]) r++;
            z[i]=r-l;
            r--;
        }
        else
        {
            int k=i-l;
            if(z[k]<r-i+1)
            {
                z[i]=z[k];
            }
            else
            {
                l=i;
                while(r<n && s[r-l]==s[r])r++;
                z[i]=r-l;
                r--;
            }

        }
    }
    for(i=0;i<=n;i++)
        cout<<z[i]<<" ";
}

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

//#define PB push_back
#define pb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define endl '\n'

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

main()
{
    string s;
    vector<char> v;
    while(getline(cin,s)&&s!="DONE")
    {
        v.clear();
        int si=s.size();
        for(int i=0;i<si;i++)
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
                v.push_back(tolower(s[i]));
        si=v.size();
        int f=0;
        for(int i=0;i<si/2;i++)
        {
            if(v[i]!=v[si-i-1])
            {
                f=1;
                break;
            }
        }
        if(f==1) printf("Uh oh..\n");
        else printf("You won't be eaten!\n");
    }
}

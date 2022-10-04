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
string s,qq;
int ok[27],z;
int match1(int st,int fin)
{
    if(st>fin) return 1;
    //cout<<st<<" "<<fin<<" "<<z<<endl;
    for(int i=st;i<=fin;i++)
    {
        //cout<<s[i]<<" "<<qq[i]<<" "<<i<<endl;
        if(s[i]=='?'&&ok[qq[i]-'a']) continue;
        if(s[i]!=qq[i]) return 0;
    }
    return true;
}
int match2(int st,int fin)
{
    if(st>fin) return 1;
    //cout<<st<<" "<<fin<<" "<<z<<endl;
    for(int i=st;i<=fin;i++)
    {
        //cout<<s[i]<<" "<<qq[i+z]<<" "<<i<<endl;
        if(s[i]=='?'&&ok[qq[i+z]-'a']) continue;
        if(s[i]!=qq[i+z]) return 0;
    }
    return true;
}
int match3(int st,int fin)
{
    for(int i=st;i<=fin;i++)
    {
        if(ok[qq[i]-'a'])
            return 0;
    }
    return 1;
}
main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    optimize();
    mem(ok,0);
    cin>>s;
 
    for(int i=0;i<s.size();i++) ok[s[i]-'a']=1;
    cin>>s;
    int n=s.size();
    int val=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            val=i;
            break;
        }
    }
    int q;
    cin>>q;
    int fla1,fla2,fla3;
    for(int i=0;i<q;i++)
    {
        cin>>qq;
        z=qq.size()-n;
        if(z<0)
        {
            if(z==-1&&val!=-1)
            {
                string a=qq.substr(0,val);
                string b=qq.substr(val,qq.size());
                qq=a+'.'+b;
                z=0;
            }
            else{
            cout<<"NO"<<endl;
            continue;
            }
        }
        if(val==-1)
        {
            fla1=match1(0,n-1);
            if(fla1==1&&z==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            continue;
        }
        else
        {
            fla1=match1(0,val-1);
            fla2=match2(val+1,n-1);
            fla3=match3(val,val+z);
            //cout<<fla1<<" "<<fla2<<" "<<fla3<<endl;
            if(fla1&&fla2&&fla3)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            continue;
        }
    }
    return 0;
}
/*
abcdefghrtyu
*jxeqql
1
jxeqql
*/
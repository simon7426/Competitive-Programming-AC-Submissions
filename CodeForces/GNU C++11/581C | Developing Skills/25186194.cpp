#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
#define PB push_back
#define MP make_pair
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
bool com(int a,int b)
{
    if(a!=100&&b!=100)
        return a%10>b%10;
    else
    {
        if(a==100)
            return b>a;
        else
            return a<b;
    }
}
main()
{
    optimize();
    ll n,i,r,t,cnt=0,cn1=0;
    vl a;
    cin>>n>>r;
    for(i=0;i<n;i++)
    {
        cin>>t;
        a.PB(t);
        if(t%10==0)
            cn1+=100-t;
        cnt+=t/10;
    }
    sort(a.begin(),a.end(),com);
    //for(i=0;i<n;i++)
    //cout<<a[i]<<" "<<endl;
    for(i=0;i<n;i++)
    {
        t=a[i]%10;
        t=10-t;
        if(t<=r&&t!=10)
        {
            cnt++;
            r-=t;
            cn1+=100-a[i]-t;
        }
        else
            break;
    }
    cnt+=min(r,cn1)/10;
    cout<<cnt<<endl;
    return 0;
}
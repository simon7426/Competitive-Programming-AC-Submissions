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
bool com(const pii &a,const pii &b)
{
    return a.second<b.second;
}
main()
{
    optimize();
    vii a;
    ll n,i,t,s,r,avg,cnt=0,wr=0;
    cin>>n>>r>>avg;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        cnt+=s;
        a.PB(MP(s,t));
    }
    if(cnt>=n*avg)
    {
        printf("0\n");
        return 0;
    }
    cnt=(n*avg)-cnt;
    sort(a.begin(),a.end(),com);
    for(i=0;i<n;i++)
    {
        s=r-a[i].first;
        if(s<cnt)
        {
           wr+=s*a[i].second;
           cnt-=s;
        }
        else
        {
            wr+=cnt*a[i].second;
            break;
        }
    }
    cout<<wr<<endl;
    return 0;
}
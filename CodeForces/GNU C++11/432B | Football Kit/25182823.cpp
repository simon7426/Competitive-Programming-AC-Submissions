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
//typedefs
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define PB push_back
#define MP make_pair
main()
{
    int n,i,s,t;
    vii a;
    map<int,vi> ho,aw;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>t;
        a.PB(MP(s,t));
        ho[s].PB(i);
        aw[t].PB(i);
    }
    for(i=0;i<n;i++)
    {
        t=ho[a[i].second].size();
        cout<<n-1+t<<" "<<n-1-t<<endl;
    }
    return 0;
}
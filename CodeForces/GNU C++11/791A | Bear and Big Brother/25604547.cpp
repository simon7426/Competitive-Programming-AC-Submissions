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
main()
{
    ll n=0,i,s,t;
    cin>>s>>t;
    while(s<=t)
    {
        n++;
        s*=3;
        t*=2;
    }
    cout<<n;
}
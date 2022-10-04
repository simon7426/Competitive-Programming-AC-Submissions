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
main()
{
    ll n,a,b,c,d,cnt=0,x,y,z;
    cin>>n>>a>>b>>c>>d;
    for(ll i=1;i<=n;i++)
    {
        if(max(i+b-c,max(i+a-d,i+a+b-c-d))<=n&&min(i+b-c,min(i+a-d,i+a+b-c-d))>0)
            cnt++;
    }
    cout<<cnt*n<<endl;
    return 0;
}
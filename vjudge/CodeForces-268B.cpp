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
    ll n,i,t=0;
    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        t+=i*(n-i)+1;
    }
    cout<<t+1<<endl;
    return 0;
}

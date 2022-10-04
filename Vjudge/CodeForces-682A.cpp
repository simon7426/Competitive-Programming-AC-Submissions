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
    ll n,k,i,t=0;
    cin>>n>>k;
    t+=((n/5)*(k/5))*5;
    t+=(n/5)*(k%5);
    t+=(k/5)*(n%5);
    if(n%5!=0&&k%5!=0)
    {
        t+=max(0LL,(n%5)+(k%5)-4);
    }
    cout<<t<<endl;
    return 0;
}

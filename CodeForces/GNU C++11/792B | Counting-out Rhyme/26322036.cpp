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
 
main()
{
    int n,k,i,j=0,t;
    cin>>n>>k;
    vi a;
    for(i=1;i<=n;i++)
    {
        a.push_back(i);
    }
    for(i=0;i<k;i++)
    {
        cin>>t;
        j=(j+t)%n;
        cout<<a[j]<<" ";
        a.erase(a.begin()+j);
        n--;
    }
    return 0;
}
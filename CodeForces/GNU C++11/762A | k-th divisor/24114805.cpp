#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
typedef long long int ll;
using namespace std;
main()
{
    set<ll> s;
    ll n,k,i,t;
    cin>>n>>k;
    t=(ll)sqrt(n);
    for(i=1;i<=t;i++)
    {
        if(n%i==0)
        {
            s.insert(i);
            s.insert(n/i);
        }
    }
    if(s.size()<k)
    {
        cout<<-1<<endl;
        return 0;
    }
    set<ll>::iterator it=s.begin();
    for(i=0;i<k-1;i++)
    {
        ++it;
    }
    cout<<*it<<endl;
    return 0;
}
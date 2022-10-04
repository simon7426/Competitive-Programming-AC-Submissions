#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
typedef long long int ll;
using namespace std;
main()
{
    ll n,d,i,j,t,cnt=0;
    cin>>n;
    map<ll,ll> a;
    map<ll,ll>::iterator p,q;
    for(i=0;i<n;i++)
    {
        cin>>d;
        for(j=0;j<d;j++)
        {
            cin>>t;
            a[t]++;
        }
        p=a.begin();
        q=a.end();
        --q;
        cnt+=(q->first-p->first);
        if(p->second>1)
            p->second--;
        else
            a.erase(p);
        if(q->second>1)
            q->second--;
        else
            a.erase(q);
    }
    cout<<cnt<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }
 
main()
{
    ll t,l,r,i;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        for(i=0;setBit(l,i)<=r;i++) l=setBit(l,i);
        cout<<l<<endl;
    }
}
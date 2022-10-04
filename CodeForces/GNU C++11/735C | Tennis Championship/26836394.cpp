#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
main()
{
    ll n,a=1,b=2,c=0;
    int i=1;
    cin>>n;
    if(n==2)
    {
        cout<<1<<endl;
        return 0;
    }
    while(c<=n)
    {
        //cout<<c<<" "<<i<<endl;
        c=a+b;
        if(c>n) break;
        a=b;
        b=c;
        i++;
    }
    cout<<i<<endl;
}
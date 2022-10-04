#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i;
    cin>>n;
    if(n==1)
    {
        cout<<"a"<<endl;
        return 0;
    }
    for(i=0;i<n/2;i++)
    {
        if(i&1)
            cout<<"aa";
        else
            cout<<"bb";
    }
    if(n%2!=0)
    {
        n/=2;
        if(n&1)
            cout<<"a"<<endl;
        else
            cout<<"b"<<endl;
    }
    return 0;
}
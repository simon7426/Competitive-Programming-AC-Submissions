#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool prime( int n)
{
    if(n%2==0&&n!=2)
        return 0;
    int x=sqrt(n)+1;
    for(int i=3;i<=x;i+=2)
        if(n%i==0)
            return 0;
        return 1;
}
 
main()
{
    int n;
    cin>>n;
    if(prime(n))
        cout<<1<<endl;
    else if(n%2==0)
        cout<<2<<endl;
    else if(n&1 && prime(n-2))
        cout<<2<<endl;
    else cout<<3<<endl;
    return 0;
}
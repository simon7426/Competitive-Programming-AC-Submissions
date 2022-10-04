#include<iostream>
using namespace std;
main()
{
    long long n,m,r=9,s=0;
    cin>>n;
    while(n>0)
    {
        s+=n;
        n-=r;
        r*=10;
    }
    cout<<s<<endl;
    return 0;
}
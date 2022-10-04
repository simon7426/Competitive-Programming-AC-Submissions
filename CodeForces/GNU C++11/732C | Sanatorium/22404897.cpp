#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
main()
{
    ll a[3],c;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[1]==a[2])
        c=a[2]-(a[0]+1);
    else
        c=a[2]-1-a[0]+a[2]-1-a[1];
    if(c<0)
        c=0;
    cout<<c<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
main()
{
    ll a[3],cnt=0,t;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(2*(a[0]+a[1])<a[2])
        cnt=a[0]+a[1];
    else
        cnt=(a[0]+a[1]+a[2])/3;
    //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<endl;
    cout<<cnt<<endl;
    return 0;
    }
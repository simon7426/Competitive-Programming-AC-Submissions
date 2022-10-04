#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int a[3],b,c,d;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    c=a[0];
    d=(a[0]+(a[1]-a[0])/3+(a[2]-a[0])/3);
    b=a[1]/3+a[2]/3;
    a[1]%=3;
    a[2]%=3;
    sort(a,a+3);
    a[2]-=a[0];
    b+=a[0];
    b+=a[2]/3;
 
    cout<<max(b,d)<<endl;
    return 0;
}
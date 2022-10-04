#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int i,int j)
{
    if(i==0)
        return j;
    return gcd(j%i,i);
}
main()
{
    int a[100],i,n,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int t=a[0];
    for(i=1;i<n;i++)
    {
        t=gcd(t,a[i]);
    }
    cout<<t*n<<endl;
}
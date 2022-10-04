#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int l,r,n,x,i,sum=0,k=1;
    cin>>n>>x;
    for(i=0;i<n;i++)
        {
           cin>>l>>r;
           sum+=(l-k)%x+(r-l+1);
           k=r+1;
        }
    cout<<sum<<endl;
    return 0;
}
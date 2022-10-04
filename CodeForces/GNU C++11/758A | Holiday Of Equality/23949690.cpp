#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
main()
{
    int a[105],n,i,t,cnt=0,ma=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ma=max(a[i],ma);
    }
    for(i=0;i<n;i++)
    {
        cnt+=(ma-a[i]);
    }
    cout<<cnt<<endl;
    return 0;
}
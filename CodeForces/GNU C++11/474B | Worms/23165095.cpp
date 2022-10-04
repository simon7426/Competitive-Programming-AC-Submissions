#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n;
    cin>>n;
    int i,t,a[n];
    cin>>a[0];
    for(i=1;i<n;i++)
    {
        cin>>t;
        a[i]=a[i-1]+t;
    }
    int m;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>t;
        cout<<lower_bound(a,a+n,t)-a+1<<endl;
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,i,j,m,t,c,sum;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(i=1;i<n;i++)
    {
        cin>>t;
        a[i]=a[i-1]+t;
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        c=0;sum=0;
        cin>>t;
        cout<<(lower_bound(a,a+n,t)-a)+1<<endl;
    }
    return 0;
}

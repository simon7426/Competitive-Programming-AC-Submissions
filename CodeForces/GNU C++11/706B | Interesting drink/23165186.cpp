#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int m,t;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>t;
        cout<<upper_bound(a,a+n,t)-a<<endl;
    }
    return 0;
}
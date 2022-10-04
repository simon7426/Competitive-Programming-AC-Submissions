#include<iostream>
using namespace std;
main()
{
    int n,m,i;
    cin>>n>>m;
    if(n==m)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<n-m<<" ";
    for(i=1;i<n-m;i++)
        cout<<i<<" ";
    for(i=n-m+1;i<=n;i++)
        cout<<i<<" ";
    return 0;
}
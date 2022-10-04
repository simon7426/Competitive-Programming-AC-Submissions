#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m],i,j,c=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<m;i++)
        cin>>b[i];
    sort(b,b+m);
    for(i=0;i<m;i++)
    {
        if(c==n)
        {
            cout<<0<<endl;
            return 0;
        }
        if(b[i]>=a[c])
            c++;
    }
    cout<<n-c<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int i,m,n,min,a[51],tmp;
    cin>>m>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(m>=n)
    {
        cout<<a[n-1]-a[0]<<endl;
        return 0;
    }
    min=a[m-1]-a[0];
    for(i=0;i<(n-m)+1;i++)
    {
        tmp=a[i+m-1]-a[i];
        if(tmp<min)
            min=tmp;
    }
    cout<<min<<endl;
    return 0;
}
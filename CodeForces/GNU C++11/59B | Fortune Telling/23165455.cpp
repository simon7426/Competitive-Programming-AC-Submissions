#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n];
    int sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2==1)
    {
        cout<<sum<<endl;
        return 0;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]%2==1)
        {
            sum-=a[i];
            cout<<sum<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
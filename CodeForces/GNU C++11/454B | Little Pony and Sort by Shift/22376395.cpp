#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n;
    cin>>n;
    int s=0,i;
    int a[n],b[n],c[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort (b,b+n);
    for(i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                s=i;
                break;
            }
        }
    if(s==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int k=0;
    for(i=s;i<n;i++)
    {
        c[k]=a[i];
        k++;
    }
    for(i=0;i<s;i++)
    {
        c[k]=a[i];
        k++;
    }
    k=1;
    for(i=0;i<n;i++)
        if(c[i]!=b[i])
    {
       k=0;
       break;
    }
    k==0?cout<<-1<<endl:cout<<n-s<<endl;
}
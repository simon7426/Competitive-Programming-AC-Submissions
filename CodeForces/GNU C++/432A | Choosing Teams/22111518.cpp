#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,i,a[5001],c,k;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]>5-k)
        {
            c=i;
            break;
        }
        else
            c=n;
    }
    cout<<c/3<<endl;
    return 0;
}
#include<iostream>
using namespace std;
main()
{
    int i,n,k,a[101],tmp,max=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        tmp=a[i]-a[i+1]-k;
        if(tmp>max)
            max=tmp;
    }
    cout<<max<<endl;
    return 0;
}
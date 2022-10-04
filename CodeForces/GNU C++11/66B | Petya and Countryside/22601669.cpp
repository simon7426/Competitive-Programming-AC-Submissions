#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,i,j,k,count=0,ma=1;
    cin>>n;
    int a[n];
    int c[n];
    for(i=0;i<n;i++)
        c[i]=1;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<=a[j-1])
                c[i]++;
            else
                break;
        }
        for(k=i-1;k>=0;k--)
        {
            if(a[k]<=a[k+1])
                c[i]++;
            else
                break;
        }
    }
    sort(c,c+n);
    reverse(c,c+n);
    cout<<c[0]<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,cnt=0,p;
    cin>>n;
    int a[n],i,j;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                a[j]++;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
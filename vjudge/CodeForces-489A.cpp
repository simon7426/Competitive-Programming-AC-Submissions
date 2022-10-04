#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,i,j,t;
    cin>>n;
    int a[n],b[n];
    int cnt=0,x[n],y[n];
    for(i=0;i<n;i++)
        {cin>>a[i];
        b[i]=a[i];}
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        if(a[i]==b[i])continue;
        for(j=i;j<n;j++)
        {
            if(a[j]==b[i])
            {
                x[cnt]=i;
                y[cnt]=j;
                cnt++;
                break;
            }
        }
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    cout<<cnt<<endl;
    for(i=0;i<cnt;i++)
        cout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}

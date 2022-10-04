#include<iostream>
using namespace std;
main()
{
    bool a,b,c,d;
    int n,i,j,ans=0;
    cin>>n;
    int x[n],y[n];
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(i=0;i<n;i++)
    {
        a=0;b=0;c=0;d=0;
        for(j=0;j<n;j++)
        {
            if(x[i]==x[j]&&y[i]<y[j])
                a=1;
            if(x[i]==x[j]&&y[i]>y[j])
                b=1;
            if(x[i]>x[j]&&y[i]==y[j])
                c=1;
            if(x[i]<x[j]&&y[i]==y[j])
                d=1;
        }
        if(a==1&&b==1&&c==1&&d==1)
                ans++;
    }
    cout<<ans<<endl;
}
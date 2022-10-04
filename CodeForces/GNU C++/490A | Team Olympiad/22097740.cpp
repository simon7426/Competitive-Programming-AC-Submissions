#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int i,n,p,a[5001],b[5001],c[5001],ac,bc,cc,m;
    ac=bc=cc=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p;
        if (p==1)
            {
              a[ac]=i+1;
              ac++;
            }
        else if(p==2)
        {
            b[bc]=i+1;
            bc++;
        }
        else if (p==3)
        {
            c[cc]=i+1;
            cc++;
        }
    }
    if(ac==0||bc==0||cc==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int d[3];
    d[0]=ac;
    d[1]=bc;
    d[2]=cc;
    sort(d,d+3);
    cout<<d[0]<<endl;
    for(i=0;i<d[0];i++)
    {
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }
}
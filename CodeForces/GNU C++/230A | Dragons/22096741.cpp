#include<iostream>
#include<algorithm>
using namespace std;
struct dg
{
    int h;
    int b;
}a[1001],tmp;
main()
{
    int i,j,s,n,c=0;
    cin>>s>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i].h>>a[i].b;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].h>a[j].h)
                {
                    tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
            else if(a[i].h==a[j].h)
                {
                    if(a[i].b<a[j].b)
                    {
                        tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                    }
                }
        }
    }
    for(i=0;i<n;i++)
    {
        if(s>a[i].h)
            s+=a[i].b;
        else
        {
            c=1;
            break;
        }
    }
    c==1?cout<<"NO"<<endl:cout<<"YES"<<endl;
}
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,a[3],i,j,e,k,tmp,m=0,t;
    cin>>n>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    e=n/a[0];
    for(i=0;i<=e;i++)
        for(j=0;j<=e;j++)
        {
            tmp=n-(j*a[1]+i*a[2]);
            if(tmp>=0&&tmp%a[0]==0)
            {
                t=i+j+tmp/a[0];
                m=max(m,t);
            }
        }
        cout<<m<<endl;
        return 0;
}
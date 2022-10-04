#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    int n,i,j,sum,t1,t2,g;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        else
        {
            sum=0;
            int sum=0;
            for(i=1;i<n;i++)
                for(j=i+1;j<=n;j++)
            {
                t1=i;t2=j;
               do
               {
                   g=t1%t2;
                   if(g==0)
                    break;
                   t1=t2;
                   t2=g;
               }
               while(true);
               sum+=t2;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

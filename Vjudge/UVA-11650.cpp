#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    int h,m,n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d:%d",&h,&m);
        h=11-h;
        if(m==0)
            h+=1;
        m=60-m;
        if(h<=0)
            h+=12;
        if(m==60)
            m=0;
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}

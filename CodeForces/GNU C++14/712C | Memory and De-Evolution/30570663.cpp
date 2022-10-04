#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,a[3],t=0;
    scanf("%d %d",&n,&m);
    a[0]=a[1]=a[2]=m;
    while(a[0]<n||a[1]<n||a[2]<n)
    {
        sort(a,a+3);
        a[0]=min(n,a[1]+a[2]-1);
        t++;
    }
    printf("%d\n",t);
    return 0;
}
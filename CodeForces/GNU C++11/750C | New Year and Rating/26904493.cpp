#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t,d,l=-2e9,r=2e8,m=1e7,s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&t,&d);
        if(d==1) l=max(l,1900-s);
        else r=min(r,1899-s);
        s+=t;
    }
    if(l>r) printf("Impossible\n");
    else if(r==2e8) printf("Infinity\n");
    else printf("%d\n",r+s);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[50],p[6];
main()
{
    int n,i,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    p[0]=0;
    for(i=1;i<=5;i++)
        scanf("%d",&p[i]);
    int x,y;
    ll tot=0L,b[6];
 
    memset(b,0L,sizeof b);
    for(i=0;i<n;i++)
    {
        tot+=a[i];
        while(tot>=p[1])
        {
            x=lower_bound(p,p+6,tot)-p;
            if(x<=0) break;
            if(p[x]!=tot)--x;
            b[x]+=(ll)tot/(ll)p[x];
            y= tot % p[x];
            //cout<<tot<<" "<<x<<" "<<p[x]<<" "<<b[x]<<" "<<y<<endl;
            tot=y;
        }
    }
    for(i=1;i<=5;i++)
        printf("%I64d ",b[i]);
    printf("\n%d\n",tot);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,i;
    double ans,t;
    cin>>m>>n;
    ans=m;
    for(i=1;i<m;i++)
    {
        t=pow((i*1.0/(double)m),(double) n);
        ans-=t;
    }
    printf("%.8f\n",ans);
    return 0;
}
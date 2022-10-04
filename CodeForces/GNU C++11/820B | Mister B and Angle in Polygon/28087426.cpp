#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    double n,a,t,mi;
    int i,ans;
    scanf("%lf %lf",&n,&a);
    double x=(180.0*(n-2.0))/n;
    double f=x/(double)(n-2.0);
    mi=abs(f-a);
    //cout<<mi<<endl;
    ans=3;
    for(i=4;i<=n;i++)
    {
        t=f*(i-2);
        if(abs(t-a)<mi)
            {
                ans=i;
                mi=abs(t-a);
            }
    }
    printf("%d 1 2\n",ans);
    return 0;
}
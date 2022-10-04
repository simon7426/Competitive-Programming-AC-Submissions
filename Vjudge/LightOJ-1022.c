#include<stdio.h>
#include<math.h>
main()
{
    int t,i;
    double r,s,pi;
    pi= 2.0 * acos(0.0);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&r);
        s=(4.0*r*r)-(pi*r*r);
        printf("Case %d: %.2lf\n",i,s);
    }
    return 0;
}

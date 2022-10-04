#include<stdio.h>
#include<math.h>
double distance(int x1,int y1,int x2,int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
main()
{
    int a1,a2,n,i,b1,b2,v;
    double tmin,dis,t;
    scanf("%d %d",&a1,&a2);
    scanf("%d",&n);
    scanf("%d %d %d",&b1,&b2,&v);
    dis=distance(a1,a2,b1,b2);
    t=dis/v;
    for (i=1;i<n;i++)
    {
        scanf("%d %d %d",&b1,&b2,&v);
        dis=distance(a1,a2,b1,b2);
        tmin=dis/v;
        if (tmin<t)
            t=tmin;
    }
    printf("%lf",t);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
main()
{
    #ifdef cp
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // cp
    double x1,x2,x3,x4,y1,y2,y3,y4,dis,x,y;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x3,&y3)!=EOF)
    {
        x2=(x1+x3+y3-y1)/2;
        x4=(x1+x3+y1-y3)/2;
        y2=(x1-x3+y1+y3)/2;
        y4=(x3-x1+y3+y1)/2;
        printf("%.9f %.9f %.9f %.9f\n",x2,y2,x4,y4);
    }
    return 0;
}

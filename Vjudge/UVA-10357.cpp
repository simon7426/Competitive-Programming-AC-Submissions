#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point
{
    double x,y,s;
    point() {x=y=0.0;}
    point(double xx,double yy,double zz):x(xx),y(yy),s(zz) {}
};
double dist(point a,point b)
{
    return hypot(a.x-b.x,a.y-b.y);
}

double dp,dn;
point p[105],pp;
int a,b,c,d,e,f,g;
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,i,j,t,fl;
    double dis,ti;
    scanf("PLAYERS=%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        p[i]=point((double)a,(double)b,(double)c);
    }
    while(getchar() != '\n');
    scanf("BALLS=%d",&m);
    for(i=1;i<=m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            scanf("%d %d %d",&e,&f,&g);
            if(a<0) a=-a,b=-b,c=-c;
            t=(int)ceil((-(double)b+sqrt(b*b*1.0-4.0*a*c))/(2.0*a));

            pp=point((double)d*t+e,(double)f*t+g,0.0);
            if(pp.x<0.0||pp.y<0.0)
            {
                printf("Ball %d was foul at (%d,%d)\n",i,(int)pp.x,(int)pp.y);
            }
            else
            {
               // printf("%d\n",t);
                fl=0;
                for(j=0;j<n;j++)
                {
                    dis=dist(p[j],pp);
                    ti=dis/p[j].s;
                    //printf("%f %f %f %d\n",dis,ti,p[j].s,t);

                    if(ti<double(t))
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl==1)
                {
                    printf("Ball %d was caught at (%d,%d)\n",i,(int)pp.x,(int)pp.y);
                }
                else
                    printf("Ball %d was safe at (%d,%d)\n",i,(int)pp.x,(int)pp.y);
            }
        }
}

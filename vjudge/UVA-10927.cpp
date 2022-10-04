#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.14159265
struct point
{
    double gra,x,y,h;

    point()
    {
        x=0.0,y=0.0,gra=0.0,h=0.0;
    }
    point(double xx,double yy,double hh)
    {
        y=yy;
        x=xx;
        if(x==0.0)
        {
            if(y<0.0) gra=270.0;
            else gra=90.0;
        }
        else if(y==0.0)
        {
            if(x<0.0) gra=180.0;
            else gra=0.0;
        }
        else
        {
            gra=atan(y/x)*180.0/PI;
        }
        h=hh;
    }
    bool operator < (point r) const
    {
        if(gra==r.gra)
            {
                if(x==r.x)
                    return fabs(y)>fabs(r.y);
                return fabs(x)>fabs(r.x);
            }
        return gra<r.gra;
    }
};

bool com (point a,point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
point v;
priority_queue<point> pq;
vector<point> vv;
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,t,tcc=1;
    double a,b,c;

    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        vv.clear();
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf %lf",&a,&b,&c);
            v=point(a,b,c);
            pq.push(v);
        }
        point pp=pq.top(),xx;
        pq.pop();
        while(!pq.empty())
        {

            xx=pq.top();
            pq.pop();
           // printf("%.6f %.6f %.6f %.6f\n",pp.gra,pp.x,pp.y,pp.h);
           // printf("%.6f %.6f %.6f %.6f\n\n",xx.gra,xx.x,xx.y,xx.h);
            if(pp.gra==xx.gra)
            {
                if(fabs(pp.h)>=fabs(xx.h))
                {
                    vv.push_back(xx);
                }
                else
                {
                    pp=xx;
                }
            }
            else
            {
                pp=xx;
            }
        }
        printf("Data set %d:\n",tcc++);
        if(vv.empty())
        {
            printf("All the lights are visible.\n");
        }
        else
        {
            sort(vv.begin(),vv.end(),com);
            t=vv.size();
            printf("Some lights are not visible:\n");
        for(i=0;i<t;i++)
        {
            printf("x = %d, y = %d",(int)vv[i].x,(int)vv[i].y);
            if(i==t-1)
                printf(".\n");
            else
                printf(";\n");
        }
        }

    }
}

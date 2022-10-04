#include<bits/stdc++.h>
//uva 10263
using namespace std;

typedef long long ll;

struct point
{
    double x,y;
    point() {x=y=0.0;}
    point(double xx,double yy):x(xx),y(yy) {}
};
double dist(point a,point b)
{
    return hypot(a.x-b.x,a.y-b.y);
}

struct vec
{
    double x,y;
    vec(double xx,double yy): x(xx),y(yy) {}
};
vec tovec(point a,point b)
{
    return vec(b.x-a.x,b.y-a.y);
}
vec scale(vec v,double s)
{
    return vec(v.x*s,v.y*s);
}
point translate(point p,vec v)
{
    return point(p.x+v.x,p.y+v.y);
}
double dot(vec a,vec b)
{
    return (a.x*b.x+a.y*b.y);
}

double norm_sq (vec v)
{
    return v.x*v.x+v.y*v.y;
}

double distoline(point p,point a,point b,point &c)
{
    vec ap=tovec(a,p),ab=tovec(a,b);
    double u=dot(ap,ab)/norm_sq(ab);
    c=translate(a,scale(ab,u));
    return dist(p,c);
}
double distoseg(point p,point a,point b,point &c)
{
    vec ap=tovec(a,p),ab=tovec(a,b);
    double u=dot(ap,ab)/norm_sq(ab);
    if(u<0.0)
    {
        c=point(a.x,a.y);
        return dist(p,a);
    }
    if(u>1.0)
    {
        c=point(b.x,b.y);
        return dist(p,b);
    }
    return distoline(p,a,b,c);
}

main()
{

    #ifdef cp
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // cp
    double x,y;
    point m,v[10010],a,b;
    int n,i;
    while(scanf("%lf %lf",&x,&y)!=EOF)
    {
        m=point(x,y);
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            scanf("%lf %lf",&x,&y);
            v[i]=point(x,y);
        }
        double dis=distoseg(m,v[0],v[1],a);
        double dis2;
        for(i=1;i<n;i++)
        {
            dis2=distoseg(m,v[i],v[i+1],b);
            if(dis2<dis)
            {
                dis=dis2;
                a.x=b.x;
                a.y=b.y;
            }
        }
        printf("%.4f\n",a.x);
        printf("%.4f\n",a.y);
    }
    return 0;
}

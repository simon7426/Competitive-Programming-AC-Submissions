#include<iostream>
#include<cstdio>
using namespace std;
int lb(int *v,int t,int n)
{
    int lo=0,hi=n,mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(v[mid]==t)
        {
            return mid;
            if(v[mid-1]==t) hi=mid-1;

        }
        else if(v[mid]>t) hi=mid-1;
        else lo=mid+1;
     }
     return lo;
}
int ub(int *v,int t,int n)
{
    int lo=0,hi=n,mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(v[mid]==t)
        {
            return mid;
            if(v[mid+1]==t) lo=mid+1;

        }
        else if(v[mid]>t) hi=mid-1;
        else lo=mid+1;
    }
    return hi;
}
int main()
{
    int te;
    int v[100005];
    scanf("%d",&te);
    for(int cas=1; cas<=te; cas++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",v+i);
        printf("Case %d:\n",cas);
        while(q--)
        {
            int lo,hi;
            scanf("%d %d",&lo,&hi);
            int l=lb(v,lo,n-1);
            int h=ub(v,hi,n-1);
            printf("%d\n",(h-l)+1);
            }
    }
    return 0;
}

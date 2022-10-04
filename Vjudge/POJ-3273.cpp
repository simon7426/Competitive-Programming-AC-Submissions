#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    long long int n,m,i,sum=0,ma=0;
    scanf("%lld %lld",&n,&m);
    long long int a[100010];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
        ma=max(a[i],ma);
    }
    long long int lo=ma;
    long long int hi=sum;
    long long int mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        long long int co=1,csum=0;
        for(i=0;i<n;i++)
        {
            if(csum+a[i]<=mid)
                csum+=a[i];
            else
            {
                csum=a[i];
                ++co;
            }
        }
        if(co>m)
            lo=mid+1;
        else
            hi=mid-1;
    }
    printf("%lld\n",lo);
    return 0;
}

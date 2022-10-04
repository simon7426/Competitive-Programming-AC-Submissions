#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt,n,k,a[1010];

bool check(int x)
{
    cnt=0;
    int cut=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>x) return false;
        if(cnt+a[i]>x)
        {
            cnt=a[i];
            cut++;
        }
        else
            cnt+=a[i];
    }
    if(cut>k) return false;
    else return true;
}

main()
{
    #ifdef cp
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // cp
    int tcc,tc,i,j,low,high,mid;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(a,0,sizeof a);
        scanf("%d %d",&n,&k);
        n++;
        cnt=0;
        for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                cnt+=a[i];
            }
        low=0,high=cnt;
        int res=high;
        while(low<=high)
        {
            mid=(low+high)>>1;
            //printf("%d %d %d %d\n",low,high,mid,res);
            if(check(mid))
                {
                    res=min(res,mid);
                    high=mid-1;
                }
            else
                low=mid+1;
        }
        printf("Case %d: %d\n",tc,res);
        cnt=0;
        int stop=0;
        for(i=0;i<n;i++)
        {
            if(a[i]+cnt>res||(n-i)==(k-stop))
            {
                printf("%d\n",cnt);
                stop++;
                cnt=a[i];
            }
            else
                cnt+=a[i];
        }
        printf("%d\n",cnt);
    }
    return 0;
}

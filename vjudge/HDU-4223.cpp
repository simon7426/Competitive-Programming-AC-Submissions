#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1010],s[1010];
int n;
int main()
{
    #ifdef CP
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif // CP
    int tcc,tc;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {

        memset(s,0,sizeof s);
        int i,j,k,x;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                s[i]=s[i-1]+a[i];
            }
            int ans=1e9;

        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                ans=min(ans,abs(s[j]-s[i-1]));
            }
        }
        /*for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }*/
        printf("Case %d: %d\n",tc,ans);
    }

}


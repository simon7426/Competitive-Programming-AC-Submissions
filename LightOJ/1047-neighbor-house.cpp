#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int ans[21][3],n;
main()
{
    int tc,tcc,i,r,g,b;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(ans,0,sizeof ans);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&r,&g,&b);
            ans[i][0]=min(ans[i-1][1],ans[i-1][2])+r;
            ans[i][1]=min(ans[i-1][0],ans[i-1][2])+g;
            ans[i][2]=min(ans[i-1][1],ans[i-1][0])+b;
        }
        /*for(i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }*/
        printf("Case %d: %d\n",tc,min(ans[n][0],min(ans[n][1],ans[n][2])));
    }
    return 0;
}

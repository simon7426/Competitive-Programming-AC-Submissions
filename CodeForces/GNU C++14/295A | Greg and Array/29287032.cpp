#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll a[100010],s[100010],f[100010],v[100010],cnt[100010],cnt2[100010];
#define mem(a) memset(a, 0, sizeof(a) )
main()
{
    mem(cnt);
    mem(cnt2);
    int n,m,k,i,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%I64d %I64d %I64d",&s[i],&f[i],&v[i]);
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&x,&y);
        cnt[x]++;
        cnt[y+1]--;
    }
    for(i=1;i<=m;i++)
    {
        cnt[i]+=cnt[i-1];
        cnt2[s[i]]+=(v[i]*cnt[i]);
        cnt2[f[i]+1]+=(-1*v[i]*cnt[i]);
    }
    for(i=1;i<=n;i++)
    {
        cnt2[i]+=cnt2[i-1];
        printf("%I64d ",a[i]+cnt2[i]);
    }
    printf("\n");
    return 0;
}
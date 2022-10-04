#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


const int x=100100;
int a[x],st[x][17],n;

void sparse()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        st[i][0]=i;
    }
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<j)-1<n;i++)
        {
            if(a[ st[i][j-1]]< a[st[i+(1<<(j-1))][j-1]])
                st[i][j]=st[i][j-1];
            else
                st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
}
int query(int i,int j)
{
    int k = (int)floor(log(((double)j-i+1))/log(2.0));
     return min(a[st[i][k]], a[ st[j-(1<<k)+1][k]]);
}
main()
{
    int tcc,tc,i,j,q,l,r;
    scanf("%d",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(st,0,sizeof st);
        memset(a,0,sizeof a);
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sparse();
        printf("Case %d:\n",tc);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&l,&r);
            printf("%d\n",query(l-1,r-1));
        }
    }
    return 0;
}

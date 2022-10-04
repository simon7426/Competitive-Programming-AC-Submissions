#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int n,m,f=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void dfs(int x,int y,int tu,int cm)
{
    if(f==1||x<0||x>n-1||y<0||y>m-1||tu>2) return;
    if(a[x][y]=='T'){f=1;return;}
    if(a[x][y]=='*')return;
    if(vis[x][y]!=-1&&vis[x][y]<=tu) return;
    vis[x][y]=tu;
    for(int i=0;i<=3;i++)
    {
        if(i!=cm)
            dfs(x+dx[i],y+dy[i],tu+1,i);
        else
            dfs(x+dx[i],y+dy[i],tu,i);
    }
}
main()
{
    int i,j,x,y;
    scanf("%d %d ",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(a[i][j]=='S')
        {
            x=i;
            y=j;
            break;
        }
    }
    for(i=0;i<=3;i++)
    {
        memset(vis,-1,sizeof(vis));
        dfs(x+dx[i],y+dy[i],0,i);
        if(f==1) break;
    }
    if(f==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
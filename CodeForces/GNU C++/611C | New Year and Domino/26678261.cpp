#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[510][510],d[510][510];
char a[510][510];
main()
{
    //optimize();
    int n,m,q,i,j;
    cin>>n>>m;
    for(i=0;i<n+2;i++)
    {
        //getchar();
        for(j=0;j<m+2;j++)
        {
            if(i==0||i==n+1||j==0||j==m+1)
                a[i][j]='#';
            else
                cin>>a[i][j];
        }
    }
/*    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=m+1;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
*/
    memset(dp,0,sizeof dp);
    memset(d,0,sizeof dp);
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<m+1;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
            if(a[i][j]=='.'&&a[i-1][j]=='.') ++dp[i][j];
            if(a[i][j]=='.'&&a[i][j-1]=='.') ++d[i][j];
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;
    }*/
    int r1,r2,c1,c2;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>r1>>c1>>r2>>c2;
        cout<<dp[r2][c2]-dp[r1][c2]-dp[r2][c1-1]+dp[r1][c1-1]+d[r2][c2]-d[r2][c1]-d[r1-1][c2]+d[r1-1][c1]<<endl;
    }
    return 0;
}
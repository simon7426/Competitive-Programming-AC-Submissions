#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,j,m,t;
    char s[12][12];
    cin>>n>>m;
    getchar();
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=m+1;j++)
        {
            if(i==0||i==n+1||j==0||j==m+1)
                s[i][j]='.';
            else
                cin>>s[i][j];
        }
    }
    /*for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=m+1;j++)
            cout<<s[i][j]<<" ";
            cout<<endl;
    }*/
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i][j]=='W')
            {
               if(s[i-1][j]=='P'||s[i+1][j]=='P'||s[i][j-1]=='P'||s[i][j+1]=='P')
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
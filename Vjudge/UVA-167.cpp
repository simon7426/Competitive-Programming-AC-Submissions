#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int brd[8][8];
int p[8],ma;
bool place(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        if(p[i]==c||abs(r-i)==abs(c-p[i])) return false;
    }
    return true;
}
int backtr(int n,int cnt)
{
    if(n==8) return ma=max(ma,cnt);
    for(int i=0;i<8;i++)
    {
        if(place(n,i))
        {
            p[n]=i;
            backtr(n+1,cnt+brd[n][i]);
        }
    }
    return cnt;
}
main()
{
   // freopen("in.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    optimize();
    int t,tc,i,j;
    cin>>tc;
    for(t=0;t<tc;t++)
    {
        memset(brd,0,sizeof brd);
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
                cin>>brd[i][j];
        }
    ma=-1;
    backtr(0,0);
    cout.width(5);
    cout<<right<<ma<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[505][505],ma=0,n,m,ans[505];
void check(int l,int r)
{
    int cnt=0;
    ma=0;
    (a[l][r]==0)?a[l][r]=1:a[l][r]=0;
    for(int i=0;i<m;i++)
    {
        if(a[l][i]==1)cnt++;
        else
        {
            ma=max(ma,cnt);
            cnt=0;
        }
    }
    ma=max(ma,cnt);
    ans[l]=ma;
    for(int i=0;i<n;i++)
    {
        ma=max(ma,ans[i]);
    }
    cout<<ma<<endl;
}
main()
{
    int i,j,t,q,cnt;
    cin>>n>>m>>q;
    for(i=0;i<n;i++)
    {
        cnt=0;
        ma=0;
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)cnt++;
            else {ma=max(ma,cnt);cnt=0;}
        }
        ma=max(ma,cnt);
        ans[i]=ma;
    }
    int l,r;
    //cout<<ma<<endl;
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        check(l-1,r-1);
    }
}
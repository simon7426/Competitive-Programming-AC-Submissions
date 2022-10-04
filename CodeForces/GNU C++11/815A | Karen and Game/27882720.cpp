#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[105][105],r1[105],c1[105],b[105][105],r2[105],c2[105];
main()
{
    int n,m,i,j,t,mi,mi2;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i][0];
        b[i][0]=a[i][0];
        mi=a[i][0];
        for(j=1;j<m;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
            mi=min(mi,a[i][j]);
        }
        r1[i]=mi;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]-=r1[i];
        }
    }
    for(i=0;i<m;i++)
    {
        mi=a[0][i];
        mi2=b[0][i];
        for(j=1;j<n;j++)
        {
            mi=min(a[j][i],mi);
            mi2=min(b[j][i],mi2);
        }
        c1[i]=mi;
        c2[i]=mi2;
        //cout<<c2[i]<<endl;
        for(j=0;j<n;j++)
            {a[j][i]-=c1[i];
            b[j][i]-=c2[i];}
    }
    for(i=0;i<n;i++)
    {
        mi2=b[i][0];
        for(j=1;j<m;j++)
        {
            mi2=min(mi2,b[i][j]);
        }
        r2[i]=mi2;
        //cout<<r2[i]<<endl;
        for(j=0;j<m;j++)
            b[i][j]-=r2[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]!=0)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int ans=0,ans2=0;
    for(i=0;i<n;i++)
    {
        ans+=r1[i];
        ans2+=r2[i];
    }
    for(i=0;i<m;i++)
    {
        ans+=c1[i];
        ans2+=c2[i];
    }
    //cout<<ans<<" "<<ans2<<endl;
    if(ans<=ans2){
    cout<<ans<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<r1[i];j++)
            cout<<"row "<<i+1<<endl;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<c1[i];j++)
            cout<<"col "<<i+1<<endl;
    }
    }
    else
    {
        cout<<ans2<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<r2[i];j++)
            cout<<"row "<<i+1<<endl;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<c2[i];j++)
            cout<<"col "<<i+1<<endl;
    }
    }
    return 0;
}
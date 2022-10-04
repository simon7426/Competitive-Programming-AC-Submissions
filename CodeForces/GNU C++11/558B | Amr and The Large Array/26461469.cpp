#include<bits/stdc++.h>
using namespace std;
#define si 1000100
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
int x[si],cnt[si],y[si];
main()
{
    optimize();
    memset(x,0,sizeof x);
    memset(y,0,sizeof y);
    memset(cnt,0,sizeof cnt);
    int n,i,ma=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        ma=max(ma,cnt[a[i]]);
    }
    int diff=n,l=1,r=n;
    for(i=0;i<n;i++)
    {
        if(cnt[a[i]]==ma&&!x[a[i]])
        {
            x[a[i]]=i+1;
        }
    }
    for(i=n-1;i>=0;i--)
    {
        if(cnt[a[i]]==ma&&!y[a[i]])
        {
            y[a[i]]=i+1;
            //cout<<x[a[i]]<<" "<<y[a[i]]<<endl;
            if(y[a[i]]-x[a[i]]+1<diff)
            {
                l=x[a[i]];
                r=y[a[i]];
                diff=r-l+1;
            }
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}
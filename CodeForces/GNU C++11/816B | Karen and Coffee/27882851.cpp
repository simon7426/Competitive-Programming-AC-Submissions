#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef long long ll;
int a[200010],c[200010];
main()
{
    optimize();
    memset(a,0,sizeof a);
    memset(c,0,sizeof c);
    int n,k,q,i,j,l,r;
    cin>>n>>k>>q;
    for(i=0;i<n;i++)
    {
        cin>>l>>r;
        a[l]++,a[r+1]--;
    }
    for(i=1;i<200010;i++)
    {
        a[i]+=a[i-1];
        if(a[i]>=k)c[i]=1;
        c[i]+=c[i-1];
    }
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        cout<<c[r]-c[l-1]<<endl;
    }
    return 0;
}
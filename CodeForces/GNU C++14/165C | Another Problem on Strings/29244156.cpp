#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
char s[1000010];
int a[1000010],cnt[1000010];
 
main()
{
    ll ans=0;
    memset(a,0,sizeof a);
    int k,x;
    scanf("%d\n",&k);
    int n=strlen(gets(s)),i,t=1;
    for(i=0;i<n;i++)
    {
            a[i+1]=a[i]+(s[i]=='1');
    }
    cnt[0]++;
    for(i=0;i<n;i++)
    {
        x=a[i+1]-k;
        if(x>=0)ans+=cnt[x];
        cnt[a[i+1]]++;
        //for(int j=0;j<n;j++) cout<<cnt[j]<<" ";
        //cout<<endl;
    }
    printf("%I64d\n",ans);
}
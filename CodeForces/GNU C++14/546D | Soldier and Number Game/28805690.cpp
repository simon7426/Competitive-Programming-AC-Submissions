#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
#define mx 5010000
int k=1;
 
bool seive[5010000];
int prime[mx],dp[mx],v[mx];
 
int f(int x)
{
    if(v[x]!=-1) return v[x];
    v[x]=1;
    int sq=sqrt(x);
    for(int i=0;prime[i]<=sq;i++)
        if(x%prime[i]==0)
        {
            v[x]=1+f(x/prime[i]);
            break;
        }
    return v[x];
}
 
void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
            if(!seive[i>>1]) {
                    for(int j = i * i; j < limit; j += i + i) {
                            seive[j>>1] = 1;
                    }
            }
    }
    prime[0]=2;
    for(int i = 3; i < limit; i += 2) {
            if(!seive[i>>1]) prime[k++]=i;
    }
}
main()
{
    int tc,a,b;
    seiveGen(mx);
    memset(v,-1,sizeof v);
    dp[0]=0;dp[1]=0;
    for(int i=2;i<mx;i++)
        {dp[i]=dp[i-1]+f(i);
        //printf("%d %d\n",i,dp[i]);
        }
        
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        //printf("%d %d\n",dp[a],dp[b]);
        printf("%d\n",dp[a]-dp[b]);
    }
    return 0;
 
}
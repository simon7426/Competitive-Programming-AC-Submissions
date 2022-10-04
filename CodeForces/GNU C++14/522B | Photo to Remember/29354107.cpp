#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int w[200010],h[200010];
main()
{
    int n,i,t,ma=0,sma=0,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&w[i],&h[i]);
        cnt+=w[i];
        if(h[i]>h[ma]) ma=i;
    }
    int x=h[ma];
    h[ma]=-1;
    for(i=0;i<n;i++)
        if(h[i]>h[sma]) sma=i;
    h[ma]=x;
 
    for(i=0;i<n;i++)
    {
        if(i==ma) printf("%d ",(cnt-w[i])*h[sma]);
        else printf("%d ",(cnt-w[i])*h[ma]);
    }
    return 0;
}
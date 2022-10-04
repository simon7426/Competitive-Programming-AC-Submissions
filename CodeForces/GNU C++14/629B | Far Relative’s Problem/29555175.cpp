#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int m[368],f[368];
main()
{
    memset(m,0,sizeof m);
    memset(f,0,sizeof f);
    int n,i,t,a,b;
    char c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c>>a>>b;
        if(c=='M')
            m[a]++,m[b+1]--;
        if(c=='F')
            f[a]++,f[b+1]--;
        //printf("%c %d %d\n",c,a,b);
    }
    int ma=0;
    for(i=1;i<368;i++)
    {
        m[i]+=m[i-1];
        f[i]+=f[i-1];
        ma=max(ma,min(m[i],f[i]));
 
    }
    printf("%d\n",ma*2);
    return 0;
}
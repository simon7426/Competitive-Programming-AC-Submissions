#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
map<int,int> m;
int gcd(int x,int y)
    {
        return y==0?x:gcd(y,x%y);
    }
main()
{
    int n,nn,i,t,s;
    scanf("%d",&n);
    nn=n*n;
    for(i=0;i<nn;i++)
    {
        scanf("%d",&t);
        m[t]++;
    }
    int pos=0;
    int ans[n];
    for(auto it=m.rbegin();it!=m.rend();it++)
    {
        t=it->first;
        //cout<<t<<" ";
        while(m[t])
        {
            ans[pos]=t;
            //printf("%d\n",t);
            for(i=0;i<pos;i++)
            {
                s=gcd(ans[i],ans[pos]);
                //cout<<ans[i]<<" "<<ans[pos]<<" "<<s<<endl;
                m[s]-=2;
            }
            pos++;
            m[t]--;
        }
    }
    for(i=0;i<pos;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<int> a[300100];
 
main()
{
    int n,m,t=0,r=0,x=1;
    int i,j=1,u,v;
    scanf("%d %d",&n,&m);
    int fl[m+3];
    memset(fl,0,sizeof fl);
   while(m--)
    {
        scanf("%d %d",&u,&v);
        if(u==1)
        {
            a[v].push_back(x++);
            t++;r++;
        }
        else if(u==2)
        {
            for(i=a[v].size()-1;i>=0;i--)
            {
                if(fl[a[v][i]]) break;
                fl[a[v][i]]=1;
                r--;
            }
        }
        else if(u==3)
        {
            for(;j<=v;j++)
            {
                if(fl[j]==0)
                {
                    fl[j]=1;
                    r--;
                }
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
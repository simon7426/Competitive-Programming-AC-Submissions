#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
set<int> s;
queue< set<int>::iterator > q;
int v[300010];
main()
{
    memset(v,0,sizeof v);
    int n,m,i,t,a,b,x;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) s.insert(i);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&x);
        auto it=s.lower_bound(a);
        //printf("%d %d\n",*it,*it2);
        while(it!=s.end())
        {
            t=*it;
            if(t>b) break;
            if(t!=x)
            {
                v[t]=x;
                q.push(it);
            }
            ++it;
        }
        while(!q.empty())
        {
            s.erase(q.front());
            q.pop();
        }
       // for(auto it=s.begin();it!=s.end();it++) printf("%d ",*it);
        //printf("\n");
    }
    for(i=1;i<=n;i++)
        printf("%d ",v[i]);
    printf("\n");
    return 0;
}
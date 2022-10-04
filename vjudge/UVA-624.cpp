#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back

vi ans,v;
int ma,t,len,tra[21];

void solve(int n,int s)
{
    if(s>ma)
    {
        ans=v;
        ma=s;
    }
    for(int i=n;i<t;i++)
    {
        if(tra[i]+s<=len)
        {
            v.pb(tra[i]);
            solve(i+1,s+tra[i]);
            v.pop_back();
        }
    }
}

main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&len,&t)==2)
    {
       // printf("%d %d",len,t);
        for(int i=0;i<t;i++)
        {
           // printf("%d ",i);
            scanf("%d",&tra[i]);
        }
        ma=-1;
        //for(int i=0;i<t;i++){printf("%d ",tra[i]);}
        v.clear();
        ans.clear();
        solve(0,0);
        for(int i=0;i<ans.size();i++)
            printf("%d ",ans[i]);
        printf("sum:%d\n",ma);
    }
    return 0;
}

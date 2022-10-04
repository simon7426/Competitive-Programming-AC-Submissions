#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<utility>
#include<iterator>
#include<set>
using namespace std;
//typedefs
typedef long long int ll;
int q[8],p[8];
bool place(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        if(p[i]==c||abs(r-i)==abs(c-p[i])) return false;
    }
    return true;
}
int backtr(int n)
{
    if(n==8) return 0;
    int cnt=1e8;
    for(int i=0;i<8;i++)
    {
        if(place(n,i))
        {
            p[n]=i;
            cnt=min(cnt,(i==q[n])? backtr(n+1):1+backtr(n+1));
        }
    }
    return cnt;
}
main()
{
    int tc=0,i;
    while (++tc)
    {
        for(i=0;i<8;i++)
        {
            if(scanf("%d",&q[i])==1){
            q[i]--;
            p[i]=q[i];
        }
        else return 0;
        }
        printf("Case %d: %d\n",tc,backtr(0));
    }
    return 0;
}

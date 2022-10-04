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
typedef vector<int> vi;
#define Si 400100
//Segment tree
#define left(x) x<<1
#define right(x) (x<<1)+1
int st[Si],a[Si];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        st[p]=a[l];
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=(p1<=p2)? p1:p2;
    }
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return (p1<=p2)?p1:p2;
}
int rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}
void SegmentTree()
{
    memset(st,0,sizeof st);
    build(1,0,n-1);
}
main()
{
    int q,i,t,tc,x,l,r;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++)
    {
        memset(a,0,sizeof a);
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        SegmentTree();
        printf("Case %d:\n",tc);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&l,&r);
            printf("%d\n",rmq(l-1,r-1));
        }
    }
    return 0;
}

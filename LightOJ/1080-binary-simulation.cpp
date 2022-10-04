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
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Si 400100
//Segment tree
#define left(x) x<<1
#define right(x) (x<<1)+1
int st[Si],a[Si],lazy[Si];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        st[p]=0;
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        st[p]=p1+p2;
    }
}
void update(int p,int l,int r,int i,int j,int v)
{
    if(lazy[p]!=0)
    {
        st[p]+=lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        lazy[p]=0;
    }
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l>=i&&r<=j)
    {
        st[p]+=v;
        if(l!=r)
        {
            lazy[left(p)]+=v;
            lazy[right(p)]+=v;
        }
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    st[p]=p1+p2;
}
void update(int i,int j,int v)
{
    update(1,0,n-1,i,j,v);
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)
        return -1;
    if(lazy[p]!=0)
    {
        st[p]+=lazy[p];
        if(l!=r)
        {
            lazy[left(p)]+=lazy[p];
            lazy[right(p)]+=lazy[p];
        }
        lazy[p]=0;
    }
    if(l>=i&&r<=j) return st[p];
    int p1=rmq(left(p),l,(l+r)/2,i,j);
    int p2=rmq(right(p),(l+r)/2+1,r,i,j);
    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return p1+p2;
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,t,i,j,k,l,r,q;
    char c;
    char s[Si];
    scanf("%d",&tc);
    for(t=0;t<tc;t++)
    {
        memset(a,0,sizeof a);
        memset(st,0,sizeof st);
        memset(lazy,0,sizeof lazy);
        scanf("%s",s);
        n=strlen(s);
        //printf("n=%d\n",n);
        build(1,0,n-1);
        scanf("%d",&q);
        printf("Case %d:\n",t+1);
        for(i=0;i<q;i++)
        {
            getchar();
            scanf("%c",&c);
            if(c=='I')
            {
                scanf("%d %d",&l,&r);
                update(l-1,r-1,1);
                //for(j=0;j<4*n;j++) printf("%d ",st[j]);
               // printf("\n");
            }
            else
            {
                scanf("%d",&l);
                r=rmq(l-1,l-1);
                //printf("%d ",r);
                if(r%2==0) printf("%c\n",s[l-1]);
                else
                {
                    printf("%d\n",((s[l-1]=='0')?1:0));
                }
            }
        }
    }
    return 0;
}


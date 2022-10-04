#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
typedef vector<int> vi;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Si 400100
#define left(x) x<<1
#define right(x) (x<<1)+1
int st[Si],a[Si],lazy[Si],f[Si];
int n;
void build(int p,int l,int r)
{
    if(l==r)
        {
            st[p]=a[l];
            f[p]=1;
        }
    else
    {
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)],p2=st[right(p)];
        if(f[left(p)]==1)
        {
            st[p]=p1|p2;
            f[p]=0;
        }
        else
        {
            st[p]=p1^p2;
            f[p]=1;
        }
    }
    //printf("%d %d %d %d\n",p,st[p],l,r);
}
void update(int p,int l,int r,int i,int j,int v)
{
 
    //printf("%d %d %d %d\n",l,r,i,j);
    if(l>r||l>j||r<i) return;
    if(l==i&&r==j)
    {
        st[p]=v;
        return;
    }
    //printf("%d %d\n",st[p],v);
    update(left(p),l,(l+r)/2,i,j,v);
    update(right(p),1+(l+r)/2,r,i,j,v);
    int p1=st[left(p)],p2=st[right(p)];
    if(f[left(p)]==1)
        {
            st[p]=p1|p2;
        }
        else
        {
            st[p]=p1^p2;
        }
    //printf("%d %d %d %d\n",p,st[p],l,r);
}
void update(int i,int j,int v)
{
    //printf("here\n");
    update(1,0,n-1,i,j,v);
}
 
 
main()
{
    int m,i,t,v;
    scanf("%d %d",&n,&m);
    n=1<<n;
    //cout<<n<<endl;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(st,0,sizeof st);
    memset(f,0,sizeof f);
    build(1,0,n-1);
    //for(i=0;i<8;i++)
    //{
   //     printf("%d ",f[i]);
    //}
    //cout<<endl;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&t,&v);
        --t;
        //printf("%d %d\n",t,v);
        update(t,t,v);
        printf("%d\n",st[1]);
    }
    return 0;
}
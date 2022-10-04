#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define PB push_back
//#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'

int a[200010],k,ftree[200010],n,m;

void update(int p)
{
    for(;p<=k;p+=(p&(-p)))
        ftree[p]+=-1;
}
int query(int p)
{
    int sum =0;
    for(;p>0;p-=(p&(-p)))
        sum+=ftree[p];
    return sum;
}
main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,tcc,i,x,t;
    scanf("%d ",&tcc);
    for(tc=1;tc<=tcc;tc++)
    {
        memset(ftree,0,sizeof ftree);
        memset(a,0,sizeof a);
        scanf("%d %d ",&n,&m);
        for(k=1;k<=n;k++)
            scanf("%d",&a[k]);
        char c;
        printf("Case %d:\n",tc);
        for(i=0;i<m;i++)
        {
            getchar();
            scanf("%c %d",&c,&t);
            if(c=='c')
            {
                x=t-query(t);
                printf("%d ",x);
                x<k?printf("%d\n",a[x]):printf("none\n");
                update(t);
            }
            else
                a[k++]=t;
        }
    }
}

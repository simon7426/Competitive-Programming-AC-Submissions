#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
//map<int,int> m;
int a[100010],m[100010];
 
main()
{
    int t,n,k,l,i,j,x;
    ll cnt=0;
    memset(m,0,sizeof m);
    scanf("%d %d %d",&n,&l,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]=i+1;
    }
    for(i=0;i<l;i++)
    {
        scanf("%d",&t);
        x=m[t];
        cnt+=(ll)(x/k)+(x%k!=0);
        //cout<<cnt<<endl;
        if(x!=1){
        swap(a[x-1],a[x-2]);
        m[t]=x-1;
        m[a[x-1]]=x;
        }
    }
    printf("%I64d\n",cnt);
    return 0;
}
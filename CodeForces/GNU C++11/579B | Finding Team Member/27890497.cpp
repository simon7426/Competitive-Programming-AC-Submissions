#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
struct team
{
    int v,l,r;
}a[400010];
bool com(team a,team b)
{
    return a.v>=b.v;
}
main()
{
    int n,i,j,v[805],t,k=0;
    cin>>n;
    for(i=2;i<=2*n;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            cin>>t;
            a[k].v=t;
            a[k].l=i;
            a[k].r=j;
            k++;
            //cout<<k<<endl;
        }
    }
    int y,z;
    sort(a,a+k,com);
    memset(v,0,sizeof v);
    for(i=0;i<k;i++)
    {
        y=a[i].l;
        z=a[i].r;
        //cout<<y<<" "<<z<<endl;
        if(v[y]==0&&v[z]==0)
        {
            v[y]=z;
            v[z]=y;
        }
    }
    for(i=1;i<=2*n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
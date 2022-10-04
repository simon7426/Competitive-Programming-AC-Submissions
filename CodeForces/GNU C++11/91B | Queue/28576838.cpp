#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
int a[100010],mi[100010],p[100010];
main()
{
    //map<int,int> m;
    int n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mi[i]=a[i];
    }
    p[n-1]=n-1;
    for(i=n-2;i>=0;i--)
    {
        if(mi[i+1]<=mi[i])
        {
            mi[i]=mi[i+1];
            p[i]=p[i+1];
        }
        else
        {
            p[i]=i;
        }
    }
    //for(i=0;i<n;i++) cout<<mi[i]<<" ";
    //cout<<endl;
    for(i=0;i<n;i++)
    {
        if(a[i]>mi[i])
            printf("%d ",(lower_bound(mi+i,mi+n,a[i])-mi)-i-2);
        else
            printf("%d ",-1);
    }
    return 0;
}
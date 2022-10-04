#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,i,t,gc=0,ma=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        ma=max(ma,t);
        if(gc!=1){
        gc=__gcd(gc,t);
        }
    }
    int x=(ma/gc)-n;
    printf("%s\n",((x&1)?"Alice":"Bob"));
}
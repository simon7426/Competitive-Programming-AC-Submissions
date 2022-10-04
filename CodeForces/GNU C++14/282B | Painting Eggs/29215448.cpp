#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
main()
{
    int n,m,a,b,diff=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(diff+a<=500)
        {
            printf("A");
            diff+=a;
        }
        else
        {
            printf("G");
            diff-=b;
        }
    }
    printf("\n");
    return 0;
}
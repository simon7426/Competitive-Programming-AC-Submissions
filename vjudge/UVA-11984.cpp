#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
main()
{
    float c,f,f1;
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c>>f;
        f1=((5.0/9.0)*f)+c;
        printf("Case %d: %.2f\n",i,f1);
    }
    return 0;

}

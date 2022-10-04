#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
main()
{
    int n,s;
    cin>>n>>s;
    int i;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    double ma=max((double)a[0],(double)s-a[n-1]);
    for(i=1;i<n;i++)
        ma=max((double)ma,(double)(a[i]-a[i-1])/2);
    printf("%.10f\n",ma);
    return 0;
}
//(double)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
main()
{
    int a[200010];
    double n,c,s;
    int i,t;
    cin>>n>>c;
    t=2*n;
    for(i=0;i<t;i++)
    {
        cin>>a[i];
    }
    sort(a,a+t);
    double mi=min((double)a[0],a[(int)n]/2.0);
    if(mi*n*3<=c)
        printf("%.6f\n",mi*n*3.0);
    else
        printf("%.6f\n",c);
}
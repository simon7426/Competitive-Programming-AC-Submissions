#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
main()
{
    double sum;
    int n,n1[2];
    cin>>n>>n1[0]>>n1[1];
    sort(n1,n1+2);
    int i,a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    double s1=0;
    double s2=0;
    for(i=0;i<n1[0];i++)
    {
        s1+=a[i];
    }
    for(i=n1[0];i<n1[1]+n1[0];i++)
    {
        s2+=a[i];
    }
    sum=(s1/(double)n1[0])+(s2/(double)n1[1]);
    cout.precision(9);
    cout<<fixed<<sum<<endl;
    return 0;
}
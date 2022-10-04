#include<iostream>
#include<algorithm>
#define pi 3.14159265358979323846
using namespace std;
double area(int n)
{
    return pi*n*n;
}
main()
{
    int n;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    double sum=0;
    for(i=n-1;i>0;i-=2)
    {
        sum+=area(a[i])-area(a[i-1]);
    }
    if(n%2!=0)
        sum+=area(a[0]);
    cout<<sum<<endl;
    return 0;
}
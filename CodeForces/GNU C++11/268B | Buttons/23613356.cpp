#include<iostream>
#include<cmath>
//#define sq(x) x*x
using namespace std;
main()
{
    long long int n;
    cin>>n;
    cout<<(long long)(n*((n*n)+5)/6)<<endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int n,m,a,b,ca[3];
    cin>>n>>m>>a>>b;
    ca[0]=(n/m)*b+(n%m)*a;
    ca[1]=(n/m)*b+b;
    ca[2]=n*a;
    sort(ca,ca+3);
    cout<<ca[0]<<endl;
    return 0;
}
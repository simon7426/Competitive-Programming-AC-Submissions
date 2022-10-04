#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int n,m,t=0;
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    //cout<<n<<" "<<0<<endl;
    //n--;
    while(n>=0&&t<=m)
    {
        cout<<n<<" "<<t<<endl;
        n--;
        t++;
    }
    return 0;
}
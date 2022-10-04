#include<iostream>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    if(n%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(i=1;i<=n;i+=2)
        cout<<i+1<<" "<<i<<" ";
    return 0;
}
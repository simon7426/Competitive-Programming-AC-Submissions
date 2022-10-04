#include<iostream>
using namespace std;
main()
{
    int n;
    while(cin>>n)
    {
       if(n%2==0)
       {
           cout<<3*(n/2)<<endl;
       }
       else
        cout<<3*(n/2)+1<<endl;
    }
    return 0;
}

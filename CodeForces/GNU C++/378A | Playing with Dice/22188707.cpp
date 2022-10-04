#include<iostream>
#include<algorithm>
using namespace std;
main()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
        cout<<"0 6 0"<<endl;
    else if((a+b)%2==0)
        (a<b)?cout<<(a+b)/2-1<<" "<<1<<" "<<6-(a+b)/2:cout<<6-(a+b)/2<<" "<<1<<" "<<(a+b)/2-1;
    else
        (a<b)?cout<<(a+b)/2<<" "<<0<<" "<<6-(a+b)/2:cout<<6-(a+b)/2<<" "<<0<<" "<<(a+b)/2;
    return 0;
}
#include<iostream>
using namespace std;
main()
{
    int x[3],y[3];
    cin>>x[0]>>y[0];
    cin>>x[1]>>y[1];
    cin>>x[2]>>y[2];
    cout<<3<<endl;
    cout<<x[0]-x[1]+x[2]<<" "<<y[0]-y[1]+y[2]<<endl;
    cout<<x[1]-x[2]+x[0]<<" "<<y[1]-y[2]+y[0]<<endl;
    cout<<x[2]-x[0]+x[1]<<" "<<y[2]-y[0]+y[1]<<endl;
    return 0;
}
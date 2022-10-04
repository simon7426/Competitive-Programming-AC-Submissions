#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int a,b,c;
    int i,j;
    cin>>a>>b>>c;
    for(i=0;a*i<=c;i++){
        for(j=0;b*j<=c;j++)
    {
        //cout<<a*i+b*j<<endl;
        if(a*i+b*j==c)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    }
    cout<<"No"<<endl;
    return 0;
}